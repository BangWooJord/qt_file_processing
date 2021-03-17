#ifndef QT_FILE_PROCESSING_INTERFACEWIDGET_H
#define QT_FILE_PROCESSING_INTERFACEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <iostream>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceWidget; }
QT_END_NAMESPACE

class InterfaceWidget : public QWidget {
Q_OBJECT

public:
    explicit InterfaceWidget(QWidget *parent = nullptr);

    ~InterfaceWidget() override;

private:
    std::unique_ptr<Ui::InterfaceWidget> ui;
    QLabel *text_lbl;
};

#endif //QT_FILE_PROCESSING_INTERFACEWIDGET_H
