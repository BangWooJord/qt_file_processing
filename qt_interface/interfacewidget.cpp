#include "interfacewidget.h"
#include "ui_InterfaceWidget.h"
namespace fs = std::filesystem;

InterfaceWidget::InterfaceWidget(QWidget *parent, std::set<std::string> const &file_set) :
        QWidget(parent), ui(new Ui::InterfaceWidget) {
    ui->setupUi(this);
    this->setStyleSheet(""
                        );
    const int file_amount = file_set.size();

    v_layout = new QVBoxLayout(this);
    status_lbl = new QLabel*[file_amount];

    int i = 0;
    for(const auto &file_iterator: file_set){
        status_lbl[i] = new QLabel(this);
            status_lbl[i]->setText("status: \n");
            status_lbl[i]->setAlignment(Qt::AlignBottom);
        auto *h_layout = new QHBoxLayout(this);
            auto *lbl = new QLabel(this);
                auto size = std::filesystem::file_size(file_iterator);
                QString file_name_string = QString::fromStdString(fs::path(file_iterator).filename().u8string());
                lbl->setText(file_name_string + " \nsize: " + QString::number(size) + " bytes");
            h_layout->addWidget(lbl);
            h_layout->addWidget(status_lbl[i]);
            h_layout->setAlignment(Qt::AlignCenter);
        v_layout->addLayout(h_layout);
        ++i;
    }
    this->setLayout(v_layout);
}

InterfaceWidget::~InterfaceWidget(){
    delete v_layout;
    delete status_lbl;
}

//methods
void InterfaceWidget::setStatus(int id, std::string const &status) {
    this->status_lbl[id]->setText("Status: \n" + QString::fromStdString(status));
}