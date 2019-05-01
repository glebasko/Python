#include "pch.h"
#include <Python.h>

int main(int argc, char * argv[]) {
	Py_Initialize();

	PyObject * myModule = PyImport_ImportModule("multiply");
	PyErr_Print();
	if (myModule == NULL) {
		PyErr_Print();
		return -1;
	}

	PyObject* moduleFunction = PyObject_GetAttrString(myModule, (char*)"multiply");
	PyErr_Print();

	PyObject* arg = PyLong_FromLong(5);
	PyErr_Print();

	PyObject* pArgs = PyTuple_New(1);
	PyTuple_SetItem(pArgs, 0, arg);
	PyErr_Print();

	PyObject* myResult = PyObject_CallObject(moduleFunction, pArgs);
	PyErr_Print();

	int result = PyLong_AsLong(myResult);
	printf("Call result: %ld", result);

	Py_Finalize();

	return 0;
}
