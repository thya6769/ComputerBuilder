#-------------------------------------------------
#
# Project created by QtCreator 2015-02-11T16:44:59
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ComputerBuilder
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Ram.cpp \
    GraphicsCard.cpp \
    SolidStateDrive.cpp \
    HardDiscDrive.cpp \
    CPU.cpp \
    Motherboard.cpp \
    PowerSupply.cpp \
    Case.cpp \
    DVDDrive.cpp \
    BluRayDrive.cpp \
    CoolingFan.cpp \
    WaterCooling.cpp \
    Computer.cpp \
    RamSet.cpp \
    HardDriveSet.cpp \
    GraphicsCardSet.cpp \
    PartAllocator.cpp

HEADERS += \
    Computer.h \
    ComputerPlan.h \
    Ram.h \
    HardDrive.h \
    GraphicsCard.h \
    Part.h \
    SolidStateDrive.h \
    HardDiscDrive.h \
    CPU.h \
    Motherboard.h \
    PowerSupply.h \
    Case.h \
    DiscDrive.h \
    DVDDrive.h \
    BluRayDrive.h \
    CoolingFan.h \
    WaterCooling.h \
    PartAllocator.h \
    RamSet.h \
    HardDriveSet.h \
    GraphicsCardSet.h \
    ComputerParts.h
