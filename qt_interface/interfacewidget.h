#ifndef QT_FILE_PROCESSING_INTERFACEWIDGET_H
#define QT_FILE_PROCESSING_INTERFACEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <iostream>
#include <set>
#include <memory>
#include <filesystem>
#include "../headers/file_related.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceWidget; }
QT_END_NAMESPACE

class InterfaceWidget : public QWidget {
Q_OBJECT

public:

    explicit InterfaceWidget(QWidget *parent = nullptr, std::set<std::string> const &file_set = {});

    ~InterfaceWidget() override;

    void setStatus(int id, std::string const &status);
private:
    std::unique_ptr<Ui::InterfaceWidget> ui;
    QVBoxLayout *v_layout;
    QLabel **status_lbl;
};

#endif //QT_FILE_PROCESSING_INTERFACEWIDGET_H
