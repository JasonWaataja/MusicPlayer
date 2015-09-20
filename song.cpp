#include "song.h"
#include <QHash>


Song::Song()
{
    songFile = QFileInfo();
    volume = 100;
}

Song::Song(QString songFile, QString title)
{
    this->songFile = QFileInfo(songFile);
    this->title = title;
    volume = 100;
}

Song::Song(QFileInfo songFileInfo, QString title)
{
    this->songFile = songFileInfo;
    this->title = title;
    volume = 100;
}

Song::Song(QString songFile)
{
    this->songFile = QFileInfo(songFile);
    this->title = songFile;
    volume = 100;
}

Song::Song(QFileInfo songFileInfo)
{
    this->songFile = songFileInfo;
    this->title = songFileInfo.absoluteFilePath();
    volume = 100;
}

Song::~Song()
{
    //delete songFile;
}

int Song::getVolume() const
{
    return this->volume;
}

void Song::setVolume(int volume)
{
    this->volume = volume;
    if (this->volume < 0) {
        this->volume = 0;
    } else if (this->volume > 500) {
        this->volume = 500;
    }
}

QFileInfo Song::getSongFile() const
{
    return this->songFile;
}

void Song::setSongFile(QString songFile)
{
    this->songFile = QFileInfo(songFile);
}

void Song::setSongFile(QFileInfo songFile)
{
    this->songFile = songFile;
}

QString Song::getTitle() const
{
    return this->title;
}

void Song::setTitle(QString title)
{
    this->title = title;
}

QString Song::getSongPath() const
{

    return this->songFile.absoluteFilePath();
}

void Song::setMediaForPlayer(QMediaPlayer *player)
{
    player->setMedia(QUrl::fromLocalFile(getSongPath()));
    player->setVolume(this->volume);
}

void Song::addToPlaylist(QMediaPlaylist *playlist)
{
    playlist->addMedia(QUrl::fromLocalFile(getSongPath()));
}
