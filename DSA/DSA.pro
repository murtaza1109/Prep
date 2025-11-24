TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
    LinkedList \
    Stack_Queue
