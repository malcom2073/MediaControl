#ifndef MCMEDIALIBRARY_H
#define MCMEDIALIBRARY_H

#include <QObject>
#include <QMap>
#include <QString>
#include "mediameta.h"

class MCMediaLibrary : public QObject
{
	Q_OBJECT
public:
	explicit MCMediaLibrary(QObject *parent = 0);
	void init();
	QMap<QString,MediaMeta> getMeta() { return m_metaList; }
signals:
	void mediaLoadFinished();
public slots:

private:
	MediaMeta gettags(QString mediafile);
	void updateMeta(QString filename);

	//TODO: Make this a database
	//Currently a Path to Meta map.
	QMap<QString,MediaMeta> m_metaList;

};

#endif // MCMEDIALIBRARY_H
