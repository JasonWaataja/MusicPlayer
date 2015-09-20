#include "songmanager.h"
#include <QDir>

SongManager::SongManager()
{
    //rootDirectory = new QDir();
    //player = new QMediaPlayer();
    //currentPlaylist = new QMediaPlaylist();
    //currentPlaylist = new Playlist();
}

SongManager::SongManager(QString rootDirectory)
{
    this->rootDirectory = new QDir(rootDirectory);
    //player = new QMediaPlayer();
    //currentPlaylist = new QMediaPlaylist();
    //currentPlaylist = new Playlist();
}

SongManager::SongManager(QFileInfo &rootDirectory)
{
    this->rootDirectory = new QDir(rootDirectory.absoluteFilePath());
    //player = new QMediaPlayer();
    //currentPlaylist = new Playlist();
}

SongManager::~SongManager()
{
    delete rootDirectory;
    //elete player;
    delete currentPlaylist;
}

void SongManager::setRootDirectory(QFileInfo &rootDirectory)
{
    delete this->rootDirectory;
    this->rootDirectory = new QDir(rootDirectory.absoluteFilePath());
}

void SongManager::setRootDirectory(QString rootDirectory)
{
    delete this->rootDirectory;
    this->rootDirectory = new QDir(rootDirectory);
}

QSet<Song> SongManager::getSongs() const
{
    return this->songs;
}

QList<Song> SongManager::getSongsAsList() const
{
    return QList<Song>::fromSet(songs);
}

/*QMediaPlayer* SongManager::getPlayer() const
{
    return this->currentPlaylist->getPlayer();
}*/

void SongManager::scan()
{
    if (rootDirectory->exists())
    {
        QFileInfoList fileList = SongManager::getAllSubFiles(rootDirectory);
        QList<Song> songList = SongManager::fileListToSongList(fileList);
        for (Song song : songList)
        {
            songs.insert(song);
        }
    }


}

QFileInfoList SongManager::getAllSubFiles(QDir *directory)
{
    QFileInfoList originalList = directory->entryInfoList();
    QFileInfoList masterList;
    for (int i = 0; i < originalList.size(); i++)
    {
        QFileInfo currentInfo = originalList.at(i);
        if (currentInfo.isFile())
        {
            masterList.append(currentInfo);
        } else if (currentInfo.isDir() && i != 0 && i != 1)
        {
            QDir* subDir = new QDir(currentInfo.absoluteFilePath());
            QFileInfoList subFiles = SongManager::getAllSubFiles(subDir);
            masterList.append(subFiles);
            delete subDir;
        }
    }
    return masterList;
}

QFileInfoList SongManager::getAllSubFiles(QDir &directory)
{
    return getAllSubFiles(&directory);
}

QFileInfoList SongManager::getAllSubFiles(QFileInfo &directory)
{
    QFileInfoList list;
    if (directory.isDir())
    {
        QDir asDir = QDir(directory.absoluteFilePath());
        list = getAllSubFiles(asDir);
    }
    return list;
}

QList<Song> SongManager::fileListToSongList(QFileInfoList& infoList)
{
    QList<Song> songList;
    for (QFileInfo fileInfo : infoList)
    {
        songList.append(Song(fileInfo));
    }
    return songList;
}

QMediaPlaylist* SongManager::createPlayList(QList<Song>& songList)
{
    QMediaPlaylist* playlist = new QMediaPlaylist();
    for (Song song : songList)
    {
        song.addToPlaylist(playlist);
    }
    return playlist;

}

