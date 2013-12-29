#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QMainWindow>
#include <QtNetWork>
#include <QTimer>
namespace Ui {
    class SerialPort;
}

class SerialPort : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialPort(QWidget *parent = 0);
    ~SerialPort();
private slots:
    void on_pushButton_receive_clicked();
    void acceptConnection();
    void readClient();
    void TimerEvent();
private:
    int kind;
    Ui::SerialPort *ui;
    QTcpServer *server;
    QTcpSocket *clientConnection;

};

#endif // SERIALPORT_H
