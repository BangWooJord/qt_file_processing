#include <QApplication>
#include "qt_interface/interfacewidget.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <Catch2-2.13.4/include/catch.hpp>
#include <toml11-3.6.0/toml.hpp>

enum ERROR{
    ERROR_OPENING_OFILE = 1,
    ERROR_OPENING_IFILE,
};

int binary_write(std::string const &filename, std::string const &path, const char *data){
    char dash = (path.back() == '\\' || path.back() == '/')? '\\' : NULL; // checking if the file path came with / \ on the end !=> assigning one
    std::string full_path = path + dash + filename;
    std::ofstream wf(full_path.c_str(), std::ios::binary | std::ios::out | std::ios::app);
    if(!wf) return ERROR_OPENING_OFILE;
    wf.write(data, sizeof(data));
    wf.close();
    return 0;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    InterfaceWidget mainPage;
    mainPage.show();
    uint32_t x;
    if(binary_write("file1", "example_files", "Lorem ipsum dolor sit amet") > 0){
        std::cerr << "Something is wrong" << std::endl;
    }
    std::thread th([&](){
        std::cin >> x;
    });
    a.exec();
    th.join();

    return 0;
}
