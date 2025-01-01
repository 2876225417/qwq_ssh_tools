


#include "mainwindow.h"
#include "ssh_cmd_panel.h"
#include <qnamespace.h>
#include <qsplitter.h>
#include <qwindowdefs.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ssh_config_panel(new SSHConfigPanel(this))
    , ssh_cmd_panel(new SSHCMDPanel(this))
    {
    QSplitter* splitter = new QSplitter(Qt::Horizontal, this);
    
    splitter->addWidget(ssh_config_panel);
    splitter->addWidget(ssh_cmd_panel);

    setCentralWidget(splitter);
    
}

MainWindow::~MainWindow(){} 