#include <QApplication>
#include "qt_interface/interfacewidget.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <Catch2-2.13.4/include/catch.hpp>
#include <toml11-3.6.0/toml.hpp>

enum ERROR{
    ERROR_OPENING_OFILE = -1,
    ERROR_OPENING_IFILE = -2,
};

int binary_write(std::string const &filename, std::string const &path, const char *data){
    char dash = (path.back() != '\\' && path.back() != '/')? '/' : NULL; // checking if the file path came with / \ on the end !=> assigning one
    std::string full_path = path + dash + filename + ".bin";
    std::ofstream file_write(full_path.c_str(), std::ios::binary | std::ios::app);
    if(!file_write) return ERROR_OPENING_OFILE;
    size_t data_size = strlen(data);
    //wf.write((char*)&data_size, sizeof(data_size));
    int i = 0;
    while (i < 60077770){
        long double wr = rand()%77777*i;
        file_write.write((char*)&wr, sizeof(wr));
        ++i;
    }
   // wf.write(data, data_size);
    file_write.close();
    return 0;
}

int binary_read(std::string const &path){
    std::ifstream file_read(path.c_str(), std::ios::binary);
    if(!file_read) return ERROR_OPENING_IFILE;
    double data;
    std::cout << "data do be reading doe" << std::endl;
    while(file_read.read((char*)&data, sizeof(data))){
        //std::cout << data << "  ";
    }
    file_read.close();
    return 0;
}

//TODO: Считывание из томл -> вектор потоков -> одновременное считывание из нескольких файлов ->
//TODO: -> юнит тесты -> GUI -> название файла в GUI -> индикатор выполнения для каждого файла
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    InterfaceWidget mainPage;
    mainPage.show();
    auto cfg_data = toml::parse("../toml_cfg/cfg.toml");
    std::vector<std::string> file_path;
    try {
        file_path = toml::find<std::vector<std::string>>(cfg_data, "paths");
    }catch(const std::out_of_range& e){
        std::cerr << "Couldn't find specified string vector" << std::endl;
        return 0;
    }
    std::vector<std::thread> thread_vec;
    thread_vec.resize(file_path.size());
    for(int i = 0; i < thread_vec.size(); ++i){
        thread_vec[i] = std::thread([&](){
            try {
                throw binary_read(file_path[i]);
            }catch(int err){
                if(err < 0) std::cerr << "Error: " << err << std::endl;
            }
        });
    }
    a.exec();
    for(auto &thread: thread_vec) thread.join();

    return 0;
}
