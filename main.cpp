#include <QApplication>
#include "qt_interface/interfacewidget.h"
#include "headers/toml_related.h"
#include <iostream>
#include <thread>
#include <vector>
#include <set>

//TODO: юнит тесты, сделать заново проект под Visual Studio


int main(int argc, char *argv[]) {
    auto *a = new QApplication(argc, argv);
    std::set<std::string> unique_path;
    if(!openConfig("../toml_cfg/cfg.toml", "paths", unique_path)) return 0;

    InterfaceWidget mainPage(nullptr, unique_path);
        mainPage.show();

    std::vector<std::thread> thread_vec;
        thread_vec.reserve(unique_path.size());
    auto MAX_THREAD = std::thread::hardware_concurrency();
    MAX_THREAD = 2;

    std::atomic<int> thread_counter = 0;
    std::atomic<int> id = 0;
    std::thread work_th([&]() {
        std::thread create_th([&](){
            for (const auto &file : unique_path) {
                while(thread_counter == MAX_THREAD); //если кол-во работающих потоков = максимально разрешенному - не создаем новые
                thread_vec.emplace_back(std::thread([&]() {
                    long double data;
                    try {
                        throw binary_read(file, data);
                    } catch (int err) {
                        if (err < 0) std::cerr << "Error: " << err << std::endl;
                    }
                }));
                mainPage.setStatus(id, "processing");
                ++thread_counter;
                ++id;
            }
        });

        std::thread join_th([&]() {
            for (int i = 0; i < thread_vec.size(); ++i) {
                while(i > id); // "усыпляем" до момента когда не будет создан новый поток в векторе потоков - таким образом
                                //этот поток, который отвечает за закрытие каждого потока в векторе потоков не "пройдет" прежде чем все потоки были открыты
                thread_vec[i].join();
                thread_counter--; //один поток закончился - кол-во работающих потоков стало меньше на 1
                mainPage.setStatus(i, "processing complete");
            }
        });
        create_th.detach();
        join_th.join();
    });
    a->exec();
    work_th.join();
    return 0;
}
