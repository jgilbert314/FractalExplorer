QT += core gui
#QT += gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


### Compiler Flags
CONFIG += c++11
QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS += -fopenmp
LIBS += -fopenmp
### Force O3 Optimization for release
QMAKE_CXXFLAGS_RELEASE -= -O
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE *= -O3


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    imageviewer.cpp \
    setfam/juliaset.cpp \
    setfam/mandelbrotset.cpp \
    setimage.cpp \
    widgets/inputpanel.cpp \
    widgets/lcdpanel.cpp \
    widgets/lineeditnumber.cpp

HEADERS += \
    imageviewer.h \
    setfam/juliaset.h \
    setfam/mandelbrotset.h \
    setimage.h \
    widgets/inputpanel.h \
    widgets/lcdpanel.h \
    widgets/lineeditnumber.h

FORMS += \
    imageviewer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    widgets/widgets.pri
