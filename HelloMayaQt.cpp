#include "HelloMayaQt.h"

HelloMayaQt::HelloMayaQt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

HelloMayaQt::~HelloMayaQt()
{}

void HelloMayaQtCmd::cleanup()
{
    if (ptr != nullptr)
    {
        delete ptr;
    }
}

MStatus HelloMayaQtCmd::doIt(const MArgList &args)
{
	//	Create a window containing a HelixButton, if one does not already
	//	exist. Otherwise just make sure that the existing window is visible.
	if (ptr == nullptr) 
	{
		ptr = new HelloMayaQt();
		//ptr->connect(ptr, SIGNAL(clicked(bool)), ptr, SLOT(createHelix(bool)));
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
