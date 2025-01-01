

#include "ssh_cmd_panel.h"
#include <qboxlayout.h>


SSHCMDPanel::SSHCMDPanel(QWidget* parent)
    : QWidget(parent)
    , cmd_edit(new QLineEdit(this))
    , otp_edit(new QTextEdit(this))
    , layout(new QVBoxLayout(this)) {

    otp_edit->setReadOnly(true);

    layout->addWidget(otp_edit);
    layout->addWidget(cmd_edit);
    setLayout(layout);

}

SSHCMDPanel::~SSHCMDPanel(){}

void SSHCMDPanel::onCmdEntered() {} 