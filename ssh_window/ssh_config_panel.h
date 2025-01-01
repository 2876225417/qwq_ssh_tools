#ifndef SSH_CONFIG_PANEL_H_
#define SSH_CONFIG_PANEL_H_

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFormLayout>
#include <QSplitter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>
#include "ssh_conn.h"

class SSHConfigPanel: public QWidget {
    Q_OBJECT
public:
    explicit SSHConfigPanel(QWidget* parent = nullptr);
    ~SSHConfigPanel();

private slots:
    void onSubmitButtonClicked(); 
private:
    QLabel*         config_title;
    QLineEdit*      host_edit;
    QLineEdit*      port_edit;
    QLineEdit*      user_edit;
    QPushButton*    submit_btn;
};

#endif  // SSH_CONFIG_PANEL_H