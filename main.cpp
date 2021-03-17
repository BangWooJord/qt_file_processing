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
    char dash = (path.back() != '\\' && path.back() != '/')? '/' : NULL; // checking if the file path came with / \ on the end !=> assigning one
    std::string full_path = path + dash + filename + ".bin";
    std::ofstream wf(full_path.c_str(), std::ios::binary | std::ios::out | std::ios::app);
    if(!wf) return ERROR_OPENING_OFILE;
    size_t data_size = strlen(data);
    //wf.write((char*)&data_size, sizeof(data_size));
    int i = 0;
    while (i < 60077770){
        long double wr = rand()%77777*i;
        wf.write((char*)&wr, sizeof(wr));
        ++i;
    }
   // wf.write(data, data_size);
    wf.close();
    return 0;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    InterfaceWidget mainPage;
    mainPage.show();
    uint32_t x;
    try{
        throw binary_write("file1", "C:/Users/NMaslovskaya/CLionProjects/qt_file_processing/example_files", "");
    }catch(int err){
        if(err > 0) std::cerr << "Error: " << err << std::endl;
    }
    std::thread th([&](){
        std::cin >> x;
    });
    a.exec();
    th.join();

    return 0;
}
