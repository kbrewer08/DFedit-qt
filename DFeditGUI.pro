#-------------------------------------------------
#
# Project created by QtCreator 2014-06-18T01:47:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DFeditGUI

TEMPLATE = app

SOURCES += \
    interface/main.cpp \
    interface/CastlesTab.cpp \
    interface/DivisionsTab.cpp \
    interface/GeneralsTab.cpp \
    interface/KingdomsTab.cpp \
    interface/MassEditTab.cpp \
    interface/DFeditGUI.cpp \
    interface/ItemsTab.cpp \
    interface/MainContentHolder.cpp \
    implementation/Castle.cpp \
    implementation/Division.cpp \
    implementation/DragonForce.cpp \
    implementation/FileReader.cpp \
    implementation/FileWriter.cpp \
    implementation/General.cpp

HEADERS  += \
    interface/CastlesTab.h \
    interface/DivisionsTab.h \
    interface/GeneralsTab.h \
    interface/KingdomsTab.h \
    interface/MassEditTab.h \
    interface/DFeditGUI.h \
    interface/ItemsTab.h \
    interface/MainContentHolder.h \
    implementation/Castle.h \
    implementation/Division.h \
    implementation/DragonForce.h \
    implementation/FileReader.h \
    implementation/FileWriter.h \
    implementation/General.h
