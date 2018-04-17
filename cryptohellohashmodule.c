// Copyright (c) 2017 The Sumokoin Projects
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <Python.h>
#include "cryptohello_hash.h"

#include <stdint.h>

static PyObject *cryptohello_hash(PyObject *self, PyObject *args)
{
	char *output;
	PyObject *value;
#if PY_MAJOR_VERSION >= 3
	PyBytesObject *input;
#else
	PyStringObject *input;
#endif
	int inputlen;
	
	if (!PyArg_ParseTuple(args, "Si", &input, &inputlen))
		return NULL;
	Py_INCREF(input);
	output = (char*)PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
	cryptonight_hash(output, (char *) PyBytes_AsString((PyObject*) input), inputlen);
#else
	cryptonight_hash(output, (char *) PyString_AsString((PyObject*) input), inputlen);
#endif
	Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
	value = Py_BuildValue("y#", output, 32);
#else
	value = Py_BuildValue("s#", output, 32);
#endif
	PyMem_Free(output);
	return value;
}


static PyMethodDef CryptohelloMethods[] = {
	{ "cryptohello_hash", cryptohello_hash, METH_VARARGS, "Hash with cryptonight algorithm" },
	{ NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef CryptohelloModule = {
	PyModuleDef_HEAD_INIT,
	"cryptohello_hash",
	"...",
	-1,
	CryptohelloMethods
};

PyMODINIT_FUNC PyInit_cryptohello_hash(void) {
	return PyModule_Create(&CryptohelloModule);
}

#else

PyMODINIT_FUNC initcryptohello_hash(void) {
	(void)Py_InitModule("cryptohello_hash", CryptohelloMethods);
}
#endif

