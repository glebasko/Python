#include <Windows.h>
#include <cmath>
#include <Python.h>
#include <myType.cpp>

PyObject* isNumberPrime(PyObject *, PyObject* args) {
	int num = 0;
	try {
		num = PyLong_AsLong(args);
	}
	catch (...)
	{
		PyErr_SetString(PyExc_RuntimeError, "Parametras turi bûti int tipo skaièius");
		return NULL;
	}
	int count = 0;
	if (num == 0)
	{
		return Py_False;
	}
	else {
		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				count++;
			}
		}
	}

	if (count > 1)
	{
		return Py_False;
	}

	return Py_True;
}


// structure that defines how the C++ function is presented to Python:
static PyMethodDef myModule_methods[] = {
	{ "isNumberPrime", (PyCFunction)isNumberPrime, METH_O, nullptr },

	// Terminate the array with an object containing nulls.
	{ nullptr, nullptr, 0, nullptr }
};

// structure that defines the module
static PyModuleDef myModule_module = {
	PyModuleDef_HEAD_INIT,
	"MyModule",						// Module name to use with Python import statements
	"MyModule description",			// Module description
	0,
	myModule_methods				// Structure that defines the methods of the module
};

// method that Python calls when it loads the module
PyMODINIT_FUNC PyInit_MyModule() {
	PyObject *m;

	if (PyType_Ready(&noddy_PlayerType) < 0)
		return NULL;

	m = PyModule_Create(&myModule_module);
	if (m == NULL)
		return NULL;

	Py_INCREF(&noddy_PlayerType);
	PyModule_AddObject(m, "Player", (PyObject*)&noddy_PlayerType);

	return m;
}