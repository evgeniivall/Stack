QT += core
QT -= gui

CONFIG += c++11

TARGET = Stack
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    stk.cpp

HEADERS += \
    stk.h
