#-------------------------------------------------
#
# Project created by QtCreator 2014-11-07T17:37:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RiskOfRain-Server
TEMPLATE = app

#
# Windows binary information.
#
VERSION = 0.0.0.0
QMAKE_TARGET_COMPANY        = "???"
QMAKE_TARGET_DESCRIPTION    = "Risk of Rain custom server."
QMAKE_TARGET_COPYRIGHT      = "\251 all rights reserved."
#

#
# Compilation option.
#
CONFIG   += c++11
#

#
# Configure release & debug build directories.
#
BUILDDIRWIN32DBG = build/RiskOfRainServer-Win32-Debug
BUILDDIRWIN32REL = build/RiskOfRainServer-Win32-Release
BUILDDIRUNIXDBG  = build/RiskOfRainServer-Unix-Debug
BUILDDIRUNIXREL  = build/RiskOfRainServer-Unix-Release
CONFIG(debug, debug|release) { # Debug build dirs
    win32:  DESTDIR     = $${BUILDDIRWIN32DBG}/
    win32:  OBJECTS_DIR = $${BUILDDIRWIN32DBG}/obj
    win32:  MOC_DIR     = $${BUILDDIRWIN32DBG}/moc
    win32:  RCC_DIR     = $${BUILDDIRWIN32DBG}/rsc
    win32:  UI_DIR      = $${BUILDDIRWIN32DBG}/ui
    unix:   DESTDIR     = $${BUILDDIRUNIXDBG}/obj
    unix:   OBJECTS_DIR = $${BUILDDIRUNIXDBG}/obj
    unix:   MOC_DIR     = $${BUILDDIRUNIXDBG}/moc
    unix:   RCC_DIR     = $${BUILDDIRUNIXDBG}/rsc
    unix:   UI_DIR      = $${BUILDDIRUNIXDBG}/ui
} else { # Release build dirs
    win32:  DESTDIR     = $${BUILDDIRWIN32REL}/
    win32:  OBJECTS_DIR = $${BUILDDIRWIN32REL}/obj
    win32:  MOC_DIR     = $${BUILDDIRWIN32REL}/moc
    win32:  RCC_DIR     = $${BUILDDIRWIN32REL}/rsc
    win32:  UI_DIR      = $${BUILDDIRWIN32REL}/ui
    unix:   DESTDIR     = $${BUILDDIRUNIXREL}/
    unix:   OBJECTS_DIR = $${BUILDDIRUNIXREL}/obj
    unix:   MOC_DIR     = $${BUILDDIRUNIXREL}/moc
    unix:   RCC_DIR     = $${BUILDDIRUNIXREL}/rsc
    unix:   UI_DIR      = $${BUILDDIRUNIXREL}/ui
}
#

#
# include path
#
INCLUDEPATH += \
    src/

DEPENDPATH += \
    src/
#

#
# SFML library
#   ref: https://github.com/LaurentGomila/SFML/wiki/Tutorial:-Link-SFML-with-Qt-Creator
#
INCLUDEPATH += extlib/headers/
DEPENDPATH += extlib/headers/
LIBS += -L"extlib/libs-mingw/x86"
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
#

#
# source files
#
SOURCES += \
    src/main.cpp \
    src/gui/ServerGuiMainWindow.cpp \
    src/server/Server.cpp

HEADERS  += \
    src/gui/ServerGuiMainWindow.hpp \
    src/server/Server.hpp

FORMS    += \
    src/gui/ServerGuiMainWindow.ui
