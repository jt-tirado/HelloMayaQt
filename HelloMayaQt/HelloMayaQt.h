#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HelloMayaQt.h"

#include <maya/MPxCommand.h>
#include <maya/MString.h>
#include <maya/MStatus.h>

class HelloMayaQt : public QMainWindow
{
    Q_OBJECT

public:
    HelloMayaQt(QWidget *parent = nullptr);
    ~HelloMayaQt();

private:
    Ui::HelloMayaQtClass ui;
};

class HelloMayaQtCmd : public MPxCommand
{
public:
	static void	cleanup();
	static void *creator() { return new HelloMayaQtCmd(); }

	MStatus	doIt(const MArgList &args);

	static HelloMayaQt*	ptr;
	static const MString commandName;
};
