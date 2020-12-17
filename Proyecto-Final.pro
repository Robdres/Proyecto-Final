QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Course.cpp \
    CourseManager.cpp \
    Faculty.cpp \
    FacultyManager.cpp \
    Grade.cpp \
    GraduateStudent.cpp \
    Proxy.cpp \
    Student.cpp \
    StudentManager.cpp \
    UnderGraduateStudent.cpp \
    User.cpp \
    UserManager.cpp \
    adminscreen.cpp \
    estudiante.cpp \
    main.cpp \
    mainwindow.cpp \
    segundapantalla.cpp

HEADERS += \
    ArrayList.hpp \
    Course.hpp \
    CourseManager.hpp \
    Exceptions.hpp \
    Faculty.hpp \
    FacultyManager.hpp \
    Grade.hpp \
    GraduateStudent.hpp \
    Proxy.hpp \
    Student.hpp \
    StudentManager.hpp \
    UnderGraduateStudent.hpp \
    User.hpp \
    UserManager.hpp \
    adminscreen.h \
    estudiante.h \
    mainwindow.h \
    segundapantalla.h

FORMS += \
    adminscreen.ui \
    mainwindow.ui \
    segundapantalla.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc
