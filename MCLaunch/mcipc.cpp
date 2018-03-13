#include "mcipc.h"
#include <QJsonDocument>
#include <QJsonObject>

MCIPC::MCIPC(QObject *parent) : QObject(parent)
{
	m_socket = new QUdpSocket(this);
	connect(m_socket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));
	m_socket->bind(12345);
}
void MCIPC::socketReadyRead()
{
	char datagrambuffer[4096];
	while (m_socket->hasPendingDatagrams())
	{
		int len = m_socket->readDatagram(datagrambuffer,4096);
		QByteArray buf(datagrambuffer,len);
		emit incomingJson(QJsonDocument::fromBinaryData(buf).object());
	}
}
void MCIPC::sendJson(QJsonObject object, int port,QHostAddress target)
{
	//If target == QHostAddress::Any, we should multicast it out maybe?
	QByteArray jsondata = QJsonDocument(object).toBinaryData();
	m_socket->writeDatagram(jsondata,target,port);

}
