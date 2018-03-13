#include <QCoreApplication>
#include "mccore.h"
#include <QSettings>
#include "mediameta.h"
#include <QTcpSocket>
#include <QTcpServer>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	/*QTcpServer *server = new QTcpServer();
	QTcpServer *server80 = new QTcpServer();
	server80->listen(QHostAddress("127.0.0.1"),80);

	server->listen(QHostAddress("127.0.0.1"),3000);

	server->waitForNewConnection(60000);
	QTcpSocket *socket = server->nextPendingConnection();
	qDebug() << QString(socket->readAll());


	server80->waitForNewConnection(60000);
	QTcpSocket *socket80 = server80->nextPendingConnection();
	qDebug() << QString(socket80->readAll());
	return a.exec();*/
	MCCore core;
	//QZeroConf zeroConf;
	//zeroConf.addServiceTxtRecord("asdf");
	//zeroConf.startServicePublish("_Volumio", "_Volumio._tcp", "local", 3000);
	//zeroConf.startServicePublish("Test", "_test._tcp", "local", 12345);



	return a.exec();
}
