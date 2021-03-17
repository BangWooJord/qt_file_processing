#include "interfacewidget.h"
#include "ui_InterfaceWidget.h"

InterfaceWidget::InterfaceWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::InterfaceWidget) {
    ui->setupUi(this);
    this->setStyleSheet(""
                        );
    text_lbl = new QLabel(this);
    text_lbl->setGeometry(100,150, 200, 100);
    text_lbl->setText("Text");
}

InterfaceWidget::~InterfaceWidget(){
    delete text_lbl;
}

