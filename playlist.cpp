#include "playlist.h"
#include "songmanager.h"

Playlist::Playlist(QObject *parent) : QObject(parent)
{
    this->playlist = new QMediaPlaylist();
    this->player = new QMediaPlayer();
    player->setPlaylist(playlist);
    connect(this->player, &QMediaPlayer::mediaChanged, this, &Playlist::onSongChange);
}

Playlist::Playlist(const QList<Song> &songList)
{
    this->songList = songList;
    this->playlist = SongManager::createPlayList(this->songList);
    this->player = new QMediaPlayer();
    updateMediaPlaylist();
    player->setPlaylist(this->playlist);
    connect(this->player, &QMediaPlayer::mediaChanged, this, &Playlist::onSongChange);
    if (songList.size() > 0)
    {
        this->currentSong = songList[0];
        player->setVolume(currentSong.getVolume());
    }
}

Playlist::~Playlist()
{
    delete playlist;
    delete player;
}

void Playlist::updateMediaPlaylist()
{
    playlist->clear();
    for (Song song : songList)
    {
        song.addToPlaylist(playlist);
    }
}

void Playlist::setSongList(const QList<Song>& songList)
{
    this->songList = songList;
    updateMediaPlaylist();
}

void Playlist::play()
{
    player->play();
}

void Playlist::pause()
{
    player->pause();
}

void Playlist::shuffle()
{
    playlist->shuffle();
}

void Playlist::setPlaybackMode(QMediaPlaylist::PlaybackMode playbackMode)
{
    playlist->setPlaybackMode(playbackMode);
}

QMediaPlaylist::PlaybackMode Playlist::getPlaybackMode()
{
    return this->playlist->playbackMode();
}

Song Playlist::getCurrentSong()
{
    return this->currentSong;
}

void Playlist::onSongChange()
{
    int currentIndex = playlist->currentIndex();
    this->currentSong = songList[currentIndex];
    player->setVolume(currentSong.getVolume());
    QTextStream out(stdout);
    out << "Hello World" << endl;
    out << currentSong.getTitle() << endl;
    out << currentSong.getVolume() << endl;
}

void Playlist::nextSong()
{
    playlist->next();
}
