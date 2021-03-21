#ifndef QT_FILE_PROCESSING_INTERFACEWIDGET_H
#define QT_FILE_PROCESSING_INTERFACEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <iostream>
#include <set>
#include <memory>
#include "../headers/file_related.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceWidget; }
QT_END_NAMESPACE

class fileObject : public QHBoxLayout{
private:
    QLabel *file_name;
    QLabel *status;
    QLabel *length;
public:
    //constructor
    fileObject(QString const &_file_name, QString const &_status, QString const &_length);
    //destructor
    ~fileObject() override;

    //methods
    void setStatus(std::string const &_status);
};

class InterfaceWidget : public QWidget {
Q_OBJECT

public:
    //constructor
    explicit InterfaceWidget(QWidget *parent = nullptr, const std::set<std::string>& file_set = {});
    //destructor
    ~InterfaceWidget() override;

    //methods
    void setStatus(int id, std::string const &status);
private:
    std::unique_ptr<Ui::InterfaceWidget> ui;
    QVBoxLayout *v_layout;
    fileObject **files;
};

#endif //QT_FILE_PROCESSING_INTERFACEWIDGET_H
