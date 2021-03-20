#include "interfacewidget.h"
#include "ui_InterfaceWidget.h"

InterfaceWidget::InterfaceWidget(QWidget *parent, const std::set<std::string>& file_set) :
        QWidget(parent), ui(new Ui::InterfaceWidget) {
    ui->setupUi(this);
    this->setStyleSheet(""
                        );

    v_layout = new QVBoxLayout(this);
    const int file_amount = file_set.size();
    h_layout = new QHBoxLayout*[file_amount];

    text_lbl = new QLabel*[file_amount];
    size_lbl = new QLabel*[file_amount];
    int i = 0;
    for(const auto &set_iterator: file_set){
        text_lbl[i] = new QLabel(this);
            std::string file = set_iterator;
            if(!remove_path(file)) std::cerr << "Couldn't remove path" << std::endl;
            text_lbl[i]->setText("File " + QString::fromStdString(file));
        size_lbl[i] = new QLabel(this);
            size_lbl[i]->setText("Length: " + QString::number(file_length(set_iterator)) + " ch");
        h_layout[i] = new QHBoxLayout(this);
            h_layout[i]->addWidget(text_lbl[i], 0, Qt::AlignCenter);
            h_layout[i]->addWidget(size_lbl[i], 0, Qt::AlignCenter);
        v_layout->addLayout(h_layout[i]);
        ++i;
    }
    this->setLayout(v_layout);
}

InterfaceWidget::~InterfaceWidget(){
    delete text_lbl;
}

void InterfaceWidget::setCompleteStatus(int id) {
    this->text_lbl[id]->setText(this->text_lbl[id]->text() + " processing complete");
}