#include "serialport.h"
#include "ui_serialport.h"
#include <QMessageBox>
SerialPort::SerialPort(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialPort)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("智能车远程遥控"));
    kind = 0;
    ui->pushButton_back->hide();
    ui->pushButton_left->hide();
    ui->pushButton_right->hide();
    ui->pushButton_stop->hide();
    ui->pushButton_forward->hide();
    ui->pushButton_right->setFlat(true);
    ui->pushButton_forward->setFlat(true);
    ui->pushButton_left->setFlat(true);
    ui->pushButton_stop->setFlat(true);
    ui->pushButton_back->setFlat(true);
    ui->label->setAttribute(Qt::WA_TranslucentBackground, false);
}

SerialPort::~SerialPort()
{
    delete ui;
}


void SerialPort::on_pushButton_receive_clicked()
{
    server = new QTcpServer();
    server->listen(QHostAddress::Any, 6666);
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerEvent()));
    timer->start(500);

}
void SerialPort::acceptConnection()
{
    clientConnection = server->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void SerialPort::readClient()
{
    //QString str = clientConnection->readAll();
    char buf[1];
    clientConnection->read(buf,1);

    switch(buf[0])
    {
    case 'f':
        ui->label->setText(QString::fromLocal8Bit("前进"));
        kind = 1;
        ui->pushButton_back->hide();
        ui->pushButton_left->hide();
        ui->pushButton_right->hide();
        ui->pushButton_stop->hide();
        break;
    case 'b':
        ui->label->setText(QString::fromLocal8Bit("后退"));
        kind = 2;
        ui->pushButton_left->hide();
        ui->pushButton_right->hide();
        ui->pushButton_stop->hide();
        ui->pushButton_forward->hide();
        break;
    case 'l':
        ui->label->setText(QString::fromLocal8Bit("左转"));
        kind = 3;
        ui->pushButton_back->hide();
        ui->pushButton_right->hide();
        ui->pushButton_stop->hide();
        ui->pushButton_forward->hide();
        break;
    case 'r':
        ui->label->setText(QString::fromLocal8Bit("右转"));
        kind = 4;
        ui->pushButton_back->hide();
        ui->pushButton_left->hide();
        ui->pushButton_stop->hide();
        ui->pushButton_forward->hide();
        break;
    case 's':
        ui->label->setText(QString::fromLocal8Bit("停止"));
        kind = 5;
        ui->pushButton_back->hide();
        ui->pushButton_left->hide();
        ui->pushButton_right->hide();
        ui->pushButton_forward->hide();
        break;
    default:
        break;
    }
}
void SerialPort::TimerEvent()
{
    switch(kind)
    {
    case 1:
        if(ui->pushButton_forward->isHidden())
        {
            ui->pushButton_forward->show();
        }
        else
        {
            ui->pushButton_forward->hide();
        }
        break;
    case 2:
        if(ui->pushButton_back->isHidden())
        {
            ui->pushButton_back->show();
        }
        else
        {
            ui->pushButton_back->hide();
        }
        break;
    case 3:
        if(ui->pushButton_left->isHidden())
        {
            ui->pushButton_left->show();
        }
        else
        {
            ui->pushButton_left->hide();
        }
        break;
    case 4:
        if(ui->pushButton_right->isHidden())
        {
            ui->pushButton_right->show();
        }
        else
        {
            ui->pushButton_right->hide();
        }
        break;
    case 5:
        if(ui->pushButton_stop->isHidden())
        {
            ui->pushButton_stop->show();
        }
        else
        {
            ui->pushButton_stop->hide();
        }
        break;
    default:
        break;
    }
}
