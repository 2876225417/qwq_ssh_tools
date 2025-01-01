#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

#include "ssh_config_panel.h"
#include "ssh_cmd_panel.h"

class MainWindow: public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent=nullptr);
    ~MainWindow();
private:
    SSHConfigPanel* ssh_config_panel;
    SSHCMDPanel* ssh_cmd_panel;

};
#endif  // MAINWINDOW_H_