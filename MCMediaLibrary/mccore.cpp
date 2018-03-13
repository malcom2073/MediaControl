#include "mccore.h"
#include <QDebug>
#include <QFile>
#include <QDir>
#include "mcmedialibrary.h"
//#include "httplistener.h"


MCCore::MCCore(QObject *parent) : QObject(parent)
{
//	QMediaPlayer *player = new QMediaPlayer(this);
//	player->setMedia(QUrl::fromLocalFile("E:\\Backup\\Users\\Michael\\Desktop\\Mikes Playlist rock&metal\\05 Forgiven.mp3"));
//	connect(player,SIGNAL(metaDataAvailableChanged(bool)),this,SLOT(playerMetaAvailableChanged(bool)));
	//qDebug() << player->metaData("Author");
	m_mediaLibrary = new MCMediaLibrary(this);
	connect(m_mediaLibrary,SIGNAL(mediaLoadFinished()),this,SLOT(mediaLoadFinished()));
/*	QSettings* settings=new QSettings("test.ini", QSettings::IniFormat);
	settings->beginGroup("listener");
	settings->setValue("host","127.0.0.1");
	settings->setValue("port",8080);
	settings->setValue("minThreads",4);
	settings->setValue("maxThreads",100);
	settings->setValue("cleanupInterval",60000);
	settings->setValue("readTimeout",60000);
	settings->setValue("maxRequestSize",16000);
	settings->setValue("maxMultiPartSize",1000000);
	m_webProvider = new WebProvider(this);
//	provider->passMeta(core.m_metaList);
	new stefanfrings::HttpListener(settings,m_webProvider, this);*/

	m_mediaLibrary->init();
	m_ipc = new MCIPC(this);
	QJsonObject readyobj;
	readyobj.insert("sender","MCMediaLibrary");
	readyobj.insert("status","ready");
	m_ipc->sendJson(readyobj,12345,QHostAddress("127.0.0.1"));

}
void MCCore::playerMetaAvailableChanged(bool available)
{
	QMediaPlayer *player = qobject_cast<QMediaPlayer*>(sender());
	qDebug() << "Available:" << player->metaData("Title");
}
void MCCore::mediaLoadFinished()
{
//	m_webProvider->passMeta(m_mediaLibrary->getMeta());
}
