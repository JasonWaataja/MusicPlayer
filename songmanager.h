#ifndef SONGMANAGER_H
#define SONGMANAGER_H

#include "song.h"
#include "playlist.h"

#include <QFile>
#include <QDir>
#include <QString>
#include <QVector>
#include <QFileInfo>
#include <QMediaPlayer>
#include <QSet>


class SongManager
{
    QDir* rootDirectory;
    QSet<Song> songs;
    bool playing;
    Playlist* currentPlaylist;

public:
    SongManager();
    SongManager(QString rootDirectory);
    SongManager(QFileInfo& rootDirectory);
    ~SongManager();

    QDir* getRootDirectory();
    void setRootDirectory(QString rootDirectory);
    void setRootDirectory(QFileInfo& rootDirectory);
    QSet<Song> getSongs() const;
    QList<Song> getSongsAsList() const;
//    QMediaPlayer* getPlayer() const;

    void play();
    void pause();
    void setCurrentPlaylist(QList<Song>& songList);

    void scan();

    static QFileInfoList getAllSubFiles(QDir* directory);
    static QFileInfoList getAllSubFiles(QDir& directory);
    static QFileInfoList getAllSubFiles(QFileInfo& directory);
    static QMediaPlaylist* createPlayList(QList<Song>& songList);

    static QList<Song> fileListToSongList(QFileInfoList& infoList);

};

#endif // SONGMANAGER_H
