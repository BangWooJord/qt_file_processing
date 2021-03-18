#include "interfacewidget.h"
#include "ui_InterfaceWidget.h"

InterfaceWidget::InterfaceWidget(QWidget *parent, int file_amount) :
        QWidget(parent), ui(new Ui::InterfaceWidget) {
    ui->setupUi(this);
    this->setStyleSheet(""
                        );

    v_layout = new QVBoxLayout(this);
    h_layout = new QHBoxLayout*[file_amount];

    text_lbl = new QLabel*[file_amount];
    size_lbl = new QLabel*[file_amount];
    for(int i = 0; i < file_amount; ++i){
        text_lbl[i] = new QLabel(this);
            text_lbl[i]->setText("Length of file number " + QString::number(i+1));
        size_lbl[i] = new QLabel(this);
        h_layout[i] = new QHBoxLayout(this);
            h_layout[i]->addWidget(text_lbl[i], 0, Qt::AlignCenter);
            h_layout[i]->addWidget(size_lbl[i], 0, Qt::AlignCenter);
        v_layout->addLayout(h_layout[i]);
    }
    this->setLayout(v_layout);
}

InterfaceWidget::~InterfaceWidget(){
    delete text_lbl;
}

void InterfaceWidget::setSize(int id, double size) {
    this->size_lbl[id]->setText(QString::number(size, 'g', 12) + " characters");
}