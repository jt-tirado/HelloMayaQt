#include "HelloMayaQt.h"

#include <QVBoxLayout>
#include <QPushButton>

#include <maya/MQtUtil.h>
#include <maya/MGlobal.h>

HelloMayaQt::HelloMayaQt(QWidget *parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

	setObjectName("HelloMayaQtWindowUI");
	setWindowTitle("HelloMayaQt");

	QPushButton *button = new QPushButton("HelloWorld");
	setCentralWidget(button);

	connect(button, &QPushButton::clicked, this, &HelloMayaQt::onButtonPress);
}

HelloMayaQt::~HelloMayaQt()
{}

void HelloMayaQt::onButtonPress(bool value)
{
	MGlobal::displayInfo("HelloWorld!");
}

void HelloMayaQtCmd::cleanup()
{
    if (ptr != nullptr)
    {
        delete ptr;
    }
}

MStatus HelloMayaQtCmd::doIt(const MArgList &args)
{
	//	Create a window, if one does not already
	//	exist. Otherwise just make sure that the existing window is visible.
	if (ptr == nullptr) 
	{
		ptr = new HelloMayaQt(MQtUtil::mainWindow());
		ptr->show();
	}
	else {
		ptr->showNormal();
		ptr->raise();
	}


	return MS::kSuccess;
}

HelloMayaQt* HelloMayaQtCmd::ptr = nullptr;
const MString HelloMayaQtCmd::commandName ="HelloMayaQtCmd";
