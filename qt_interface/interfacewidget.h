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

class InterfaceWidget : public QWidget {
Q_OBJECT

public:
    explicit InterfaceWidget(QWidget *parent = nullptr, const std::set<std::string>& file_set = {});
    ~InterfaceWidget() override;
    void setCompleteStatus(int id);
private:
    std::unique_ptr<Ui::InterfaceWidget> ui;
    QLabel **text_lbl;
    QLabel **size_lbl;
    QVBoxLayout *v_layout;
    QHBoxLayout **h_layout;
};

#endif //QT_FILE_PROCESSING_INTERFACEWIDGET_H
