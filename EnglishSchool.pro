QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deletestudent.cpp \
    deleteteacher.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    newstudent.cpp \
    newteacher.cpp \
    student.cpp \
    studentdb.cpp \
    teacher.cpp \
    teacherdb.cpp \
    updatestudent.cpp \
    updateteacher.cpp

HEADERS += \
    deletestudent.h \
    deleteteacher.h \
    login.h \
    mainwindow.h \
    newstudent.h \
    newteacher.h \
    student.h \
    studentdb.h \
    teacher.h \
    teacherdb.h \
    updatestudent.h \
    updateteacher.h

FORMS += \
    deletestudent.ui \
    deleteteacher.ui \
    login.ui \
    mainwindow.ui \
    newstudent.ui \
    newteacher.ui \
    updatestudent.ui \
    updateteacher.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
