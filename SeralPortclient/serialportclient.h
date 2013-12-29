#ifndef SERIALPORTCLIENT_H
#define SERIALPORTCLIENT_H

#include <QMainWindow>
#include <QtNetwork>
namespace Ui {
    class SerialPortclient;
}

class SerialPortclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialPortclient(QWidget *parent = 0);
    ~SerialPortclient();

private slots:
    void on_pushButton_stop_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_forward_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::SerialPortclient *ui;
    QTcpSocket *client;
};

#endif // SERIALPORTCLIENT_H
