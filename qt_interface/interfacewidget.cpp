#include "interfacewidget.h"
#include "ui_InterfaceWidget.h"


fileObject::fileObject(const QString &_file_name, const QString &_status, const QString &_length) {
    file_name = new QLabel();
    file_name->setText(_file_name);
    status = new QLabel();
    status->setText(_status);
    length = new QLabel();
    length->setText(_length);

    this->addWidget(file_name, 0, Qt::AlignCenter);
    this->addWidget(status, 0, Qt::AlignCenter);
    this->addWidget(length, 0, Qt::AlignCenter);
}
fileObject::~fileObject(){
    delete file_name;
    delete status;
    delete length;
}
void fileObject::setStatus(const std::string &_status) {
    this->status->setText(QString::fromStdString(_status));
}


InterfaceWidget::InterfaceWidget(QWidget *parent, const std::set<std::string>& file_set) :
        QWidget(parent), ui(new Ui::InterfaceWidget) {
    ui->setupUi(this);
    this->setStyleSheet(""
                        );
    const int file_amount = file_set.size();

    v_layout = new QVBoxLayout(this);
    files = new fileObject*[file_amount];

    int i = 0;
    for(const auto &file_iterator: file_set){
        std::string file = file_iterator;
            if(!remove_path(file)) std::cerr << "Couldn't remove path" << std::endl;
        files[i] = new fileObject(QString::fromStdString(file), "",
                                  QString::number(file_length(file_iterator)));
        v_layout->addLayout(files[i]);
        ++i;
    }
    this->setLayout(v_layout);
}

InterfaceWidget::~InterfaceWidget(){
    delete files;
    delete v_layout;
}

void InterfaceWidget::setStatus(int id, std::string const &status) {
    this->files[id]->setStatus(status);
}