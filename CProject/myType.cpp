#include <Python.h>
#include "structmember.h"

typedef struct {
	PyObject_HEAD
	int x;
	int y;
} Player;

static void Player_dealloc(Player* self) {
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject * Player_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	Player *self;

	self = (Player *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->x = 0;
		self->y = 0;
	}

	return (PyObject *)self;
}

static int Player_init(Player *self, PyObject *args, PyObject *kwds)
{
	if (!PyArg_ParseTuple(args, "ii", &self->x, &self->y))
		return -1;
	return 0;
}

static PyMemberDef Player_members[] = {
	{"x", T_INT, offsetof(Player, x), 0, "x koordinate"},
	{"y", T_INT, offsetof(Player, y), 0, "y koordinate"},
	{NULL}  /* Sentinel */
};

static void Player_move_right(Player* self)
{
	self->x + 1;
}

static void Player_move_left(Player* self)
{
	self->x - 1;
}

static void Player_move_up(Player* self)
{
	self->y + 1;
}

static void Player_move_down(Player* self)
{
	self->y - 1;
}

static PyMethodDef Player_methods[] = {
	{"move_right", (PyCFunction)Player_move_right, METH_O, "Moves player to the right"},
	{"move_left", (PyCFunction)Player_move_left, METH_O, "Moves player to the left"},
	{"move_up", (PyCFunction)Player_move_up, METH_O, "Moves player up"},
	{"move_down", (PyCFunction)Player_move_down, METH_O, "Moves player down"},
	{NULL}  /* Sentinel */
};

static PyObject* Player_str(Player* self) {
	return PyUnicode_FromFormat("(%i %i)", self->x, self->y);
}


static PyTypeObject noddy_PlayerType = {
  PyVarObject_HEAD_INIT(NULL, 0)
  "noddy.Player", /*tp_name*/
  sizeof(Player), /*tp_basicsize*/
  0, /*tp_itemsize*/
  (destructor)Player_dealloc, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_reserved*/
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash */
  0, /*tp_call*/
  (reprfunc)Player_str, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
  "Cia yra þaidëjas", /* tp_doc */
  0,
  0,
  0,
  0,
  0,
  0,
  Player_methods, //cia bus metodai
  Player_members,
  0,
  0,
  0,
  0,
  0,
  0,
  (initproc)Player_init,
  0,
  Player_new,
};