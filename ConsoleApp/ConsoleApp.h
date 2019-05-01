#pragma once

int main(int argc, char * argv[]) {

	PyObject* myModuleString = PyString_FromString("mytest");
	//PyObject* myModule = PyImport_Import("");

	Py_Initialize();

	PyRun_SimpleString("import multiply");
	PyRun_SimpleString("print(multiply.multiply(5))");
	Py_Finalize();

	return 0;
}
