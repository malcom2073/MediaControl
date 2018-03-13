#ifndef MCIPC_H
#define MCIPC_H
#include <QObject>
#include <QUdpSocket>
#include <QJsonObject>

class MCIPC : public QObject
{
	Q_OBJECT
public:
	MCIPC(QObject *parent=0);
private:
	QUdpSocket *m_socket;
public slots:
	void sendJson(QJsonObject object, int port=0,QHostAddress target=QHostAddress::Any);
private slots:
	void socketReadyRead();
signals:
	void incomingJson(QJsonObject object);
};

#endif // MCIPC_H
