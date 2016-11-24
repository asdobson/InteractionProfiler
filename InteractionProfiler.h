#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_InteractionProfiler.h"

class InteractionProfiler : public QMainWindow
{
    Q_OBJECT

public:
    InteractionProfiler(QWidget *parent = Q_NULLPTR);

private:
    Ui::InteractionProfilerClass ui;
};
