#-------------------------------------------------
#
# Project created by QtCreator 2015-08-11T23:16:14
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AudioPlayer
TEMPLATE = app


SOURCES += main.cpp\
        audioplayer.cpp \
    song.cpp \
    songmanager.cpp \
    playlist.cpp

HEADERS  += audioplayer.h \
    song.h \
    songmanager.h \
    playlist.h

FORMS    += audioplayer.ui

CONFIG += c++11
