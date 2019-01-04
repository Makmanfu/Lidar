#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QString>
#include <QLayout>

namespace Ui {
class LoginDialog;
class NetworkSetting;
class SerialPortSetting;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void OnOk();

    void OnCancel();

    void OnLoginType(const QString& text);

private:
    void initWidget();

private:
    Ui::LoginDialog *ui;

    QGridLayout * layout;
    Ui::NetworkSetting * networkSettingUi;
    Ui::SerialPortSetting * serialPortSettingUi;
};

#endif // LOGINDIALOG_H
