#include <QApplication>
#include "qt_interface/interfacewidget.h"
#include <iostream>
#include <thread>
#include <vector>
#include <toml11-3.6.0/toml.hpp>
#include "headers/file_related.h"

int openConfig(std::string cfg_path, std::string value, std::vector<std::string> &data){
    auto cfg_data = toml::parse(cfg_path);
    try {
        data = toml::find<std::vector<std::string>>(cfg_data, value);
    }catch(const std::out_of_range& e){
        std::cerr << "Couldn't find specified string vector" << std::endl;
        return 0;
    }
}
//TODO: юнит тесты -> название файла в GUI
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    std::vector<std::string> file_path;
    if(openConfig("../toml_cfg/cfg.toml", "paths", file_path) == 0) return 0;

    InterfaceWidget mainPage(nullptr, file_path.size());
    mainPage.show();

    std::vector<std::thread> thread_vec;
    thread_vec.reserve(file_path.size());
    int id = 0;
    for(auto &file : file_path){
        uint32_t file_size = file_length(file);
        mainPage.setSize(id, file_size);
        thread_vec.emplace_back(std::thread([&](){
            long double data;
            try {
                throw binary_read(file, data, file_size);
            }catch(int err){
                if(err < 0) std::cerr << "Error: " << err << std::endl;
            }
        }));
        ++id;
    }
    a.exec();
    for(auto &thread: thread_vec) thread.join();

    return 0;
}
