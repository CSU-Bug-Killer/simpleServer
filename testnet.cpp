#include "testnet.h"
#include "ui_testnet.h"
//#include <QtGui>
#include <QByteArray>
#include <QDebug>
#include <QTcpSocket>

Testnet::Testnet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testnet)
{
    ui->setupUi(this);
    this->connect(ui->pushButton_start,SIGNAL(clicked()),this,SLOT(startTcpserver()));
//    this->connect(ui->pushButton_send,SIGNAL(clicked()),this,SLOT(sendMessage()));
    this->connect(ui->pushButton_send,SIGNAL(clicked()),this,SLOT(sendMessage()));
}
Testnet::~Testnet()
{
    delete ui;
}
void Testnet::startTcpserver()
{
    qDebug() << "Start Server.";
    m_tcpServer = new QTcpServer(this);
    m_tcpServer->listen(QHostAddress::Any,9527); //监听任何连上19999端口的ip
    connect(m_tcpServer,SIGNAL(newConnection()),this,SLOT(newConnect())); //新连接信号触发，调用newConnect()槽函数，这个跟信号函数一样，其实你可以随便取。
}
void Testnet::newConnect()
{
    qDebug() << "new connect";
    QTcpSocket *m_tcpSocket = m_tcpServer->nextPendingConnection(); //得到每个连进来的socket
    m_tcpSockets.append(m_tcpSocket);
    connect(m_tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage())); //有可读的信息，触发读函数槽
}
void Testnet::readMessage() //读取信息
{
    QByteArray  message;
    for(int i = 0;i < m_tcpSockets.length();i ++)
        {

            qDebug() << "QDataStream " ;
//            QDataStream in(m_tcpSockets.at(i));
//            in.setVersion (QDataStream::Qt_5_7);
//            in >> message;
            message = m_tcpSockets.at(i)->readAll();
            if(!(message.isEmpty()))
            {
                qDebug() << "break " ;
                break;
            }
        }

    // ui->textEdit_rec->te
//    QByteArray qba= m_tcpSocket->readAll(); //读取
    qDebug()<<message;
    QString ss=QVariant(message).toString();
    ui->textEdit_rec->setText(ss);
}
void Testnet::sendMessage() //发送信息
{
    qDebug() << "send message";
    QString strMesg= ui->lineEdit_sendmessage->text();
    qDebug()<<strMesg;
    for (int i = 0; i < m_tcpSockets.size(); ++i) {
//         if (list.at(i) == "Jane")
//             cout << "Found Jane at position " << i << endl;
        m_tcpSockets.at(i)->write(strMesg.toStdString().c_str(),strlen(strMesg.toStdString().c_str())); //发送

     }


}
