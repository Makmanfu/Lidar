#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include "ui_NetworkSetting.h"
#include "ui_SerialPortSetting.h"

#include <QLabel>
#include <QSerialPort>
#include <QSerialPortInfo>

//debug
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    layout = new QGridLayout(ui->w_loginSetting);
    networkSettingUi = new Ui::NetworkSetting();
    serialPortSettingUi = new Ui::SerialPortSetting();
    networkSettingUi->setupUi(new QWidget);
    serialPortSettingUi->setupUi(new QWidget);

    layout->addWidget(networkSettingUi->widget);


    connect(ui->pb_ok, SIGNAL(clicked()), this, SLOT(OnOk()));
    connect(ui->pb_cancel, SIGNAL(clicked()), this, SLOT(OnCancel()));
    connect(ui->cb_loginType, SIGNAL(currentTextChanged(const QString &)),
            this, SLOT(OnLoginType(const QString &)));
}

LoginDialog::~LoginDialog()
{
    delete networkSettingUi;
    delete serialPortSettingUi;
    delete ui;
}

void LoginDialog::OnOk()
{


    if(ui->cb_loginType->currentText() == tr("单线") ||
            ui->cb_loginType->currentText() == tr("离轴"))
    {

    }
    else
    {

    }


    this->accept();
}

void LoginDialog::OnCancel()
{
    this->close();
}

void LoginDialog::OnLoginType(const QString &text)
{
    initWidget();
}

void LoginDialog::initWidget()
{


    if(ui->cb_loginType->currentText() == tr("单线") ||
            ui->cb_loginType->currentText() == tr("离轴"))
    {
        serialPortSettingUi->widget->setVisible(false);
        networkSettingUi->widget->setVisible(true);
        layout->removeWidget(serialPortSettingUi->widget);
        layout->addWidget(networkSettingUi->widget);
    }
    else
    {
        networkSettingUi->widget->setVisible(false);
        serialPortSettingUi->widget->setVisible(true);
        layout->removeWidget(networkSettingUi->widget);
        layout->addWidget(serialPortSettingUi->widget);

        QList<QSerialPortInfo>  infos = QSerialPortInfo::availablePorts();
        foreach (QSerialPortInfo info, infos) {
            serialPortSettingUi->cb_devices->addItem(info.portName());
        }
    }
}
