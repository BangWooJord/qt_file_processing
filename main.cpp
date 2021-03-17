#include <QApplication>
#include "qt_interface/interfacewidget.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <toml11-3.6.0/toml.hpp>

int binary_encoder(){}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    InterfaceWidget mainPage;
    mainPage.show();
    uint32_t x;
    std::thread th([&](){
        std::cin >> x;
    });
    a.exec();
    th.join();

    return 0;
}
