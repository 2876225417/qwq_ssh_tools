


#include "mainwindow.h"
#include <qboxlayout.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qwidget.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    central_widget = new QWidget(this);
    setCentralWidget(central_widget);
    

    layout = new QVBoxLayout(central_widget);
    label = new QLabel("Hello Qt6!", this);
    layout->addWidget(label);

    button = new QPushButton("Click", this);
    layout->addWidget(button);
    connect(button, &QPushButton::clicked, [this]() {
        label->setText("Clicked!");
    });

    setWindowTitle("SSH Tools");
    resize(800, 600);
}

MainWindow::~MainWindow(){} 