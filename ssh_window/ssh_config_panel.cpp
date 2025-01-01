


#include "ssh_config_panel.h"
#include "ssh_conn.h"

SSHConfigPanel::SSHConfigPanel(QWidget* parent)
    : QWidget(parent)
    {

    QVBoxLayout* layout = new QVBoxLayout(this);

    QWidget* wrapper = new QWidget(this);
    QFormLayout* config_form = new QFormLayout(wrapper);

    config_title = new QLabel("SSH Configuration", wrapper);
    host_edit = new QLineEdit(wrapper);
    port_edit = new QLineEdit(wrapper);
    user_edit = new QLineEdit(wrapper);
    submit_btn = new QPushButton("Enter",wrapper);

    host_edit->setStyleSheet("background: white");
    port_edit->setStyleSheet("background: white;");
    user_edit->setStyleSheet("background: white;");
    submit_btn->setStyleSheet("background: black; width: 50%;");

    config_form->addRow(config_title);
    config_form->addRow(new QLabel("host: "), host_edit);
    config_form->addRow(new QLabel("port: "), port_edit);
    config_form->addRow(new QLabel("user: "), user_edit);
    config_form->addRow(submit_btn);
    
    wrapper->setStyleSheet("background: #444; border-radius: 10px");
    layout->addWidget(wrapper);
    
    setLayout(layout);

    connect(submit_btn, &QPushButton::clicked, this, &SSHConfigPanel::onSubmitButtonClicked);
}


SSHConfigPanel::~SSHConfigPanel() {
}


void SSHConfigPanel::onSubmitButtonClicked() {
    const char* host = (host_edit->text()).toUtf8().constData();
    int port = (port_edit->text()).toInt();
    const char* user = (user_edit->text()).toUtf8().constData();

    qDebug() << "host: " << host << '\n';
    qDebug() << "port: " << port << '\n';
    qDebug() << "user: " << user << '\n';

    ssh_utils::ssh_conn* ssh_connector = new ssh_utils::ssh_conn();

    ssh_connector->set_ssh_options(host, port, user);
    if (ssh_connector->check_conn()) qDebug() << 'c';
    else ssh_connector->ssh_utils::ssh_conn::~ssh_conn();
    
    qDebug() << "Clicked\n";
}