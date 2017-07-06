#ifndef TESTNET_H
#define TESTNET_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class testnet;
}

class Testnet : public QMainWindow
{
    Q_OBJECT

private slots:
    void startTcpserver();
    void sendMessage();
    void newConnect();
    void readMessage();
signals:



public:
    explicit Testnet(QWidget *parent = 0);
    ~Testnet();


private:
    Ui::testnet *ui;
    QTcpServer *m_tcpServer;
//    QTcpSocket *m_tcpSocket;
    QList<QTcpSocket*> m_tcpSockets;


};

#endif // TESTNET_H
