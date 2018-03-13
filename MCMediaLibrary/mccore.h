#ifndef MCCORE_H
#define MCCORE_H

#include <QObject>
#include <QMediaPlayer>
//#include "webprovider.h"
#include "mcipc.h"

class MCMediaLibrary;

class MCCore : public QObject
{
	Q_OBJECT
public:
	explicit MCCore(QObject *parent = 0);
signals:

public slots:
	void playerMetaAvailableChanged(bool available);
	void mediaLoadFinished();
private:
	MCMediaLibrary *m_mediaLibrary;
	MCIPC *m_ipc;
//	WebProvider *m_webProvider;
};

#endif // MCCORE_H
