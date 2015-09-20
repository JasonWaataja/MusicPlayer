#include "audioplayer.h"
#include "song.h"
#include "songmanager.h"
#include "playlist.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTime>
#include <QMediaPlayer>

#include <iostream>


using namespace std;

void delaySeconds(int seconds)
{
    QTime endTime = QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < endTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AudioPlayer w;
    w.show();
    QTextStream out(stdout);

    SongManager manager("C:/Users/jason/Music/Play Music");
    manager.scan();
    QList<Song> songList = QList<Song>::fromSet(manager.getSongs());
    Playlist playlist(songList);
    playlist.play();

    while (true)
    {
        delaySeconds(5);
        playlist.nextSong();
    }


    return a.exec();
}
