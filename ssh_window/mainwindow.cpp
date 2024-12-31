// mainwindow.cpp
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Setup UI components (buttons, labels, etc.)
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    layout = new QVBoxLayout(centralWidget);
    label = new QLabel("Hello, Qt6!", this);
    layout->addWidget(label);
    
    button = new QPushButton("Click me", this);
    layout->addWidget(button);
    
    // Add button click event
    connect(button, &QPushButton::clicked, [this]() {
        label->setText("You clicked the button!");
    });

    setWindowTitle("SSH Tools Main Window");
    resize(400, 300);
}

MainWindow::~MainWindow()
{
    // Destructor code (optional for cleanup)
}
