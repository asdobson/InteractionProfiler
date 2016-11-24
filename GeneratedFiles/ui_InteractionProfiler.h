/********************************************************************************
** Form generated from reading UI file 'InteractionProfiler.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERACTIONPROFILER_H
#define UI_INTERACTIONPROFILER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InteractionProfilerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InteractionProfilerClass)
    {
        if (InteractionProfilerClass->objectName().isEmpty())
            InteractionProfilerClass->setObjectName(QStringLiteral("InteractionProfilerClass"));
        InteractionProfilerClass->resize(600, 400);
        menuBar = new QMenuBar(InteractionProfilerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        InteractionProfilerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InteractionProfilerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        InteractionProfilerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(InteractionProfilerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        InteractionProfilerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(InteractionProfilerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        InteractionProfilerClass->setStatusBar(statusBar);

        retranslateUi(InteractionProfilerClass);

        QMetaObject::connectSlotsByName(InteractionProfilerClass);
    } // setupUi

    void retranslateUi(QMainWindow *InteractionProfilerClass)
    {
        InteractionProfilerClass->setWindowTitle(QApplication::translate("InteractionProfilerClass", "InteractionProfiler", 0));
    } // retranslateUi

};

namespace Ui {
    class InteractionProfilerClass: public Ui_InteractionProfilerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERACTIONPROFILER_H
