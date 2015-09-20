#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QList>
#include <QMediaPlaylist>
#include "song.h"

#include <QObject>

class Playlist : public QObject
{
    Q_OBJECT
public:
    explicit Playlist(QObject *parent = 0);
    Playlist(const QList<Song>& songList);
    ~Playlist();

    void setSongList(const QList<Song>& songList);

    void play();
    void pause();
    void shuffle();
    void setPlaybackMode(QMediaPlaylist::PlaybackMode playbackMode);
    QMediaPlaylist::PlaybackMode getPlaybackMode();
    Song getCurrentSong();
    void nextSong();

private:
    QList<Song> songList;
    QMediaPlaylist* playlist;
    QMediaPlayer* player;
    Song currentSong;
    void updateMediaPlaylist();

signals:

public slots:
    void onSongChange();
};

#endif // PLAYLIST_H
