#define PY_SSIZE_T_CLEAN
#include <Python.h>

PyMODINIT_FUNC PyInit_spam(void);

int main(int argc, const char *argv[])
{
	wchar_t *program = Py_DecodeLocale(argv[0], NULL);
	if (program == NULL) {
		fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
		exit(1);
	}

	if (PyImport_AppendInittab("spam", PyInit_spam) == -1) {
		fprintf(stderr, "Error: could not extend in-built modules table\n");
		exit(1);
	}

	Py_SetProgramName(program);
	Py_Initialize();
	PyObject *pmodule = PyImport_ImportModule("spam");
    if (!pmodule) {
        PyErr_Print();
        fprintf(stderr, "Error: could not import module 'spam'\n");
    }

    PyRun_SimpleString("import spam");
    PyRun_SimpleString("spam.system('ls -l')");

    PyMem_RawFree(program);
    return 0;
}

