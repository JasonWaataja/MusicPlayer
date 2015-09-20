#ifndef SONG_H
#define SONG_H

#include <QFile>
#include <QString>
#include <QMediaPlayer>
#include <QFileInfo>
#include <QMediaPlaylist>


class Song
{
    QFileInfo songFile;
    QString title;
    int volume;

public:
    Song();
    Song(QString songFile, QString title);
    Song(QString songFile);
    Song(QFileInfo songFileInfo);
    Song(QFileInfo songFileInfo, QString title);
    ~Song();

    void setMediaForPlayer(QMediaPlayer* player);
    void addToPlaylist(QMediaPlaylist* playlist);

    int getVolume() const;
    void setVolume(int volume);
    QFileInfo getSongFile() const;
    void setSongFile(QString songFile);
    void setSongFile(QFileInfo songFile);
    QString getTitle() const;
    void setTitle(QString title);

    QString getSongPath() const;

};

inline bool operator==(const Song& song1, const Song& song2)
{
    return (song1.getTitle() == song2.getTitle()) && (song1.getSongFile() == song2.getSongFile());
}

inline uint qHash(const Song& key)
{
    return /*qHash(key.getTitle()) ^ */qHash(key.getSongPath());
}

#endif // SONG_H
