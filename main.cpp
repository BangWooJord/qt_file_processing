#include <QApplication>
#include "qt_interface/interfacewidget.h"
#include <iostream>
#include <thread>
#include <vector>
#include <set>
#include <toml11-3.6.0/toml.hpp>

bool openConfig(std::string const &cfg_path, std::string const &value, std::set<std::string> &unique_path){
    auto cfg_data = toml::parse(cfg_path);
    std::vector<std::string> data;
    try {
        data = toml::find<std::vector<std::string>>(cfg_data, value);
    }catch(const std::out_of_range& e){
        std::cerr << "Couldn't find specified string vector" << std::endl;
        return false;
    }
    for(const auto &file: data){ //rewrite all file names into a set, if file name matches with the name inside of set - don't save it
        if(unique_path.find(file) == unique_path.end()) {
            unique_path.insert(file);
        }
    }
    return true;
}
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
        ++id;
    }
    id = 0;
    std::thread thread_wait([&](){
        for(auto &thread: thread_vec) {
            thread.join();
            mainPage.setCompleteStatus(id);
            ++id;
        }
    });
    a->exec();
    thread_wait.join();
    return 0;
}
