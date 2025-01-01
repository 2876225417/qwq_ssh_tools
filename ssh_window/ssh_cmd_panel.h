
#ifndef SSH_CMD_PANEL_H_
#define SSH_CMD_PANEL_H_

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>

class SSHCMDPanel: public QWidget {
    Q_OBJECT
public:
    explicit SSHCMDPanel(QWidget* parent = nullptr);
    ~SSHCMDPanel();

private slots:
    void onCmdEntered();
private:
    QLineEdit* cmd_edit;
    QTextEdit* otp_edit;
    QVBoxLayout* layout;    
};

#endif