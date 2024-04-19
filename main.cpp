#include "HelloMayaQt.h"
#include <QtWidgets/QApplication>

#include <maya/MFnPlugin.h>
#include <maya/MGlobal.h>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    HelloMayaQt w;
//    w.show();
//    return a.exec();
//}

MStatus initializePlugin(MObject plugin)
{
	MStatus		st;
	MFnPlugin	pluginFn(plugin, "Autodesk, Inc.", "1.0", "Any", &st);

	if (!st) {
		MGlobal::displayError(
			MString("helixQtCmd - could not initialize plugin: ")
			+ st.errorString()
		);
		return st;
	}

	//	Register the command.
	st = pluginFn.registerCommand(HelloMayaQtCmd::commandName, HelloMayaQtCmd::creator);

	if (!st) {
		MGlobal::displayError(
			MString("helixQtCmd - could not register '")
			+ HelloMayaQtCmd::commandName + "' command: "
			+ st.errorString()
		);
		return st;
	}

	return st;
}


MStatus uninitializePlugin(MObject plugin)
{
	MStatus		st;
	MFnPlugin	pluginFn(plugin, "Autodesk, Inc.", "1.0", "Any", &st);

	if (!st) {
		MGlobal::displayError(
			MString("helixQtCmd - could not uninitialize plugin: ")
			+ st.errorString()
		);
		return st;
	}

	//	Make sure that there is no UI left hanging around.
	HelloMayaQtCmd::cleanup();

	//	Deregister the command.
	st = pluginFn.deregisterCommand(HelloMayaQtCmd::commandName);

	if (!st) {
		MGlobal::displayError(
			MString("helixQtCmd - could not deregister '")
			+ HelloMayaQtCmd::commandName + "' command: "
			+ st.errorString()
		);
		return st;
	}

	return st;
}