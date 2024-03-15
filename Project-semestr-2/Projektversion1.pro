QT       += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cbaza.cpp \
    cbazadostawa.cpp \
    cbazafaktury.cpp \
    cbazanadanie.cpp \
    cbluza.cpp \
    cdostawa.cpp \
    cfaktura.cpp \
    chdd.cpp \
    ckolanka.cpp \
    ckoszulka.cpp \
    cnadanie.cpp \
    cprodukt.cpp \
    crecznik.cpp \
    csluchawki.cpp \
    cssd.cpp \
    ctasmy.cpp \
    cwezel.cpp \
    cwezeldostawa.cpp \
    cwezelfaktury.cpp \
    cwezelnadanie.cpp \
    dodacdostawe.cpp \
    dodacnadanie.cpp \
    dodanienowegoproduktu.cpp \
    dostepne_amazon.cpp \
    dostepne_produkty.cpp \
    listadostaw.cpp \
    listafaktur.cpp \
    listanadan.cpp \
    main.cpp \
    mainwindow.cpp \
    pokazfaktury.cpp \
    produktinfo.cpp \
    przedsiebiorca.cpp \
    wszystkieprodukty.cpp \
    zapelnicfakture.cpp \
    zmianailosci.cpp \
    zmieniciloscamazon.cpp \
    znalezcfakture.cpp \
    znalezcprodukt.cpp

HEADERS += \
    cbaza.h \
    cbazadostawa.h \
    cbazafaktury.h \
    cbazanadanie.h \
    cbluza.h \
    cdostawa.h \
    cfaktura.h \
    chdd.h \
    ckolanka.h \
    ckoszulka.h \
    cnadanie.h \
    cprodukt.h \
    crecznik.h \
    csluchawki.h \
    cssd.h \
    ctasmy.h \
    cwezel.h \
    cwezeldostawa.h \
    cwezelfaktury.h \
    cwezelnadanie.h \
    dodacdostawe.h \
    dodacnadanie.h \
    dodanienowegoproduktu.h \
    dostepne_amazon.h \
    dostepne_produkty.h \
    listadostaw.h \
    listafaktur.h \
    listanadan.h \
    mainwindow.h \
    pokazfaktury.h \
    produktinfo.h \
    przedsiebiorca.h \
    wszystkieprodukty.h \
    zapelnicfakture.h \
    zmianailosci.h \
    zmieniciloscamazon.h \
    znalezcfakture.h \
    znalezcprodukt.h

FORMS += \
    dodacdostawe.ui \
    dodacnadanie.ui \
    dodanienowegoproduktu.ui \
    dostepne_amazon.ui \
    dostepne_produkty.ui \
    listadostaw.ui \
    listafaktur.ui \
    listanadan.ui \
    mainwindow.ui \
    pokazfaktury.ui \
    produktinfo.ui \
    wszystkieprodukty.ui \
    zapelnicfakture.ui \
    zmianailosci.ui \
    zmieniciloscamazon.ui \
    znalezcfakture.ui \
    znalezcprodukt.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
