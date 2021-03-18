#ifndef QT_FILE_PROCESSING_INTERFACEWIDGET_H
#define QT_FILE_PROCESSING_INTERFACEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <iostream>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceWidget; }
QT_END_NAMESPACE

class InterfaceWidget : public QWidget {
Q_OBJECT

public:
    explicit InterfaceWidget(QWidget *parent = nullptr, int file_amount = 1);
    ~InterfaceWidget() override;
    void setSize(int id, double size);
private:
    std::unique_ptr<Ui::InterfaceWidget> ui;
    QLabel **text_lbl;
    QLabel **size_lbl;
    QVBoxLayout *v_layout;
    QHBoxLayout **h_layout;
};

#endif //QT_FILE_PROCESSING_INTERFACEWIDGET_H
