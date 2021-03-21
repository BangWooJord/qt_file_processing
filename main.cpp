#include <QApplication>
#include "qt_interface/interfacewidget.h"
#include "headers/toml_related.h"
#include <iostream>
#include <thread>
#include <vector>
#include <set>

//TODO: юнит тесты

int main(int argc, char *argv[]) {
    auto *a = new QApplication(argc, argv);
    std::set<std::string> unique_path;
    if(!openConfig("../toml_cfg/cfg.toml", "paths", unique_path)) return 0;

    InterfaceWidget mainPage(nullptr, unique_path);
    mainPage.show();

    std::vector<std::thread> thread_vec;
    thread_vec.reserve(unique_path.size());
    int id = 0;
    for(const auto &file : unique_path){
        uint32_t file_size = file_length(file);
        thread_vec.emplace_back(std::thread([&]() {
            long double data;
            try {
                throw binary_read(file, data, file_size);
            } catch (int err) {
                if (err < 0) std::cerr << "Error: " << err << std::endl;
            }
        }));
        mainPage.setStatus(id, "processing");
        ++id;
    }
    id = 0;
    std::thread thread_wait([&](){
        for(auto &thread: thread_vec) {
            thread.join();
            mainPage.setStatus(id, "processing complete");
            ++id;
        }
    });
    a->exec();
    thread_wait.join();
    return 0;
}
