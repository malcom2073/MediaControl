#include "mcmedialibrary.h"

#include <QMap>
#include <QString>
#include <QDir>
#include <QFile>


#include <taglib/fileref.h>
#include <taglib/tag.h>

MCMediaLibrary::MCMediaLibrary(QObject *parent) : QObject(parent)
{

}
void MCMediaLibrary::init()
{
	QString basedir = "E:\\Backup\\Users\\Michael\\Desktop\\Mikes Playlist rock&metal\\";
	QString filename = basedir + "07 Awake and Alive.mp3";
	//qDebug() << "Tag:" << gettags(filename);
	QDir base(basedir);
	foreach (QString filename,base.entryList(QDir::Files | QDir::NoDotAndDotDot))
	{
		updateMeta(base.absoluteFilePath(filename));
//		m_metaList.append(gettags(base.absoluteFilePath(filename)));
	}
	emit mediaLoadFinished();
}

void MCMediaLibrary::updateMeta(QString filename)
{
	if (m_metaList.contains(filename))
	{
		m_metaList.remove(filename);
	}
	m_metaList.insert(filename,gettags(filename));
}

MediaMeta MCMediaLibrary::gettags(QString mediafile)
{
	MediaMeta retval;
	TagLib::FileRef file(TagLib::FileName(mediafile.toStdString().c_str()));
	TagLib::String artist_string = file.tag()->artist();
	TagLib::String title_string = file.tag()->title();
	TagLib::String album_string = file.tag()->album();
	QString artist = QString::fromLatin1(artist_string.toCString());
	QString title = QString::fromStdString(title_string.toCString());
	QString album = QString::fromStdString(album_string.toCString());
	retval.artist = artist;
	retval.title = title;
	retval.album = album;
	return retval;
}
