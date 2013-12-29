#include "serialportclient.h"
#include "ui_serialportclient.h"

SerialPortclient::SerialPortclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialPortclient)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("ÖÇÄÜ³µÔ¶³ÌÒ£¿Ø"));
}

SerialPortclient::~SerialPortclient()
{
    delete ui;
}


void SerialPortclient::on_pushButton_stop_clicked()
{
    char *data="s";
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("10.1.151.217"), 6666);
    client->write(data);
}

void SerialPortclient::on_pushButton_right_clicked()
{
    char *data="r";
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("10.1.151.217"), 6666);
    client->write(data);

}

void SerialPortclient::on_pushButton_left_clicked()
{
    char *data="l";
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("10.1.151.217"), 6666);
    client->write(data);
}

void SerialPortclient::on_pushButton_forward_clicked()
{
    char *data="f";
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("10.1.151.217"), 6666);
    client->write(data);
}

void SerialPortclient::on_pushButton_back_clicked()
{
    char *data="b";
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress("10.1.151.217"), 6666);
    client->write(data);

}
