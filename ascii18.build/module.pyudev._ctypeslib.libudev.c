/* Generated code for Python module 'pyudev._ctypeslib.libudev'
 * created by Nuitka version 1.8.5
 *
 * This code is in part copyright 2023 Kay Hayen.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nuitka/prelude.h"

#include "nuitka/unfreezing.h"

#include "__helpers.h"

/* The "module_pyudev$_ctypeslib$libudev" is a Python object pointer of module type.
 *
 * Note: For full compatibility with CPython, every module variable access
 * needs to go through it except for cases where the module cannot possibly
 * have changed in the mean time.
 */

PyObject *module_pyudev$_ctypeslib$libudev;
PyDictObject *moduledict_pyudev$_ctypeslib$libudev;

/* The declarations of module constants used, if any. */
static PyObject *mod_consts[123];
#ifndef __NUITKA_NO_ASSERT__
static Py_hash_t mod_consts_hash[123];
#endif

static PyObject *module_filename_obj = NULL;

/* Indicator if this modules private constants were created yet. */
static bool constants_created = false;

/* Function to create module private constants. */
static void createModuleConstants(PyThreadState *tstate) {
    if (constants_created == false) {
        loadConstantsBlob(tstate, &mod_consts[0], UNTRANSLATE("pyudev._ctypeslib.libudev"));
        constants_created = true;

#ifndef __NUITKA_NO_ASSERT__
        for (int i = 0; i < 123; i++) {
            mod_consts_hash[i] = DEEP_HASH(tstate, mod_consts[i]);
        }
#endif
    }
}

// We want to be able to initialize the "__main__" constants in any case.
#if 0
void createMainModuleConstants(PyThreadState *tstate) {
    createModuleConstants(tstate);
}
#endif

/* Function to verify module private constants for non-corruption. */
#ifndef __NUITKA_NO_ASSERT__
void checkModuleConstants_pyudev$_ctypeslib$libudev(PyThreadState *tstate) {
    // The module may not have been used at all, then ignore this.
    if (constants_created == false) return;

    for (int i = 0; i < 123; i++) {
        assert(mod_consts_hash[i] == DEEP_HASH(tstate, mod_consts[i]));
        CHECK_OBJECT_DEEP(mod_consts[i]);
    }
}
#endif

// The module code objects.
static PyCodeObject *codeobj_e59f6b39efaed77d0ee6049d7354ed8b;

static void createModuleCodeObjects(void) {
    module_filename_obj = MAKE_RELATIVE_PATH(mod_consts[120]); CHECK_OBJECT(module_filename_obj);
    codeobj_e59f6b39efaed77d0ee6049d7354ed8b = MAKE_CODE_OBJECT(module_filename_obj, 1, 0, mod_consts[121], mod_consts[121], NULL, NULL, 0, 0, 0);
}

// The module function declarations.
NUITKA_CROSS_MODULE PyObject *impl___main__$$$function__1__mro_entries_conversion(PyThreadState *tstate, PyObject **python_pars);


// The module function definitions.


extern void _initCompiledCellType();
extern void _initCompiledGeneratorType();
extern void _initCompiledFunctionType();
extern void _initCompiledMethodType();
extern void _initCompiledFrameType();

extern PyTypeObject Nuitka_Loader_Type;

#ifdef _NUITKA_PLUGIN_DILL_ENABLED
// Provide a way to create find a function via its C code and create it back
// in another process, useful for multiprocessing extensions like dill
extern void registerDillPluginTables(PyThreadState *tstate, char const *module_name, PyMethodDef *reduce_compiled_function, PyMethodDef *create_compiled_function);

function_impl_code functable_pyudev$_ctypeslib$libudev[] = {

    NULL
};

static char const *_reduce_compiled_function_argnames[] = {
    "func",
    NULL
};

static PyObject *_reduce_compiled_function(PyObject *self, PyObject *args, PyObject *kwds) {
    PyObject *func;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:reduce_compiled_function", (char **)_reduce_compiled_function_argnames, &func, NULL)) {
        return NULL;
    }

    if (Nuitka_Function_Check(func) == false) {
        PyThreadState *tstate = PyThreadState_GET();

        SET_CURRENT_EXCEPTION_TYPE0_STR_STATE(tstate, PyExc_TypeError, "not a compiled function");
        return NULL;
    }

    struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)func;

    function_impl_code *current = functable_pyudev$_ctypeslib$libudev;
    int offset = 0;

    while (*current != NULL) {
        if (*current == function->m_c_code) {
            break;
        }

        current += 1;
        offset += 1;
    }

    if (*current == NULL) {
        PyThreadState *tstate = PyThreadState_GET();

        SET_CURRENT_EXCEPTION_TYPE0_STR(tstate, PyExc_TypeError, "Cannot find compiled function in module.");
        return NULL;
    }

    PyObject *code_object_desc = MAKE_TUPLE_EMPTY(6);
    PyTuple_SET_ITEM0(code_object_desc, 0, function->m_code_object->co_filename);
    PyTuple_SET_ITEM0(code_object_desc, 1, function->m_code_object->co_name);
    PyTuple_SET_ITEM(code_object_desc, 2, PyLong_FromLong(function->m_code_object->co_firstlineno));
    PyTuple_SET_ITEM0(code_object_desc, 3, function->m_code_object->co_varnames);
    PyTuple_SET_ITEM(code_object_desc, 4, PyLong_FromLong(function->m_code_object->co_argcount));
    PyTuple_SET_ITEM(code_object_desc, 5, PyLong_FromLong(function->m_code_object->co_flags));

    CHECK_OBJECT_DEEP(code_object_desc);

    PyObject *result = MAKE_TUPLE_EMPTY(4);
    PyTuple_SET_ITEM(result, 0, PyLong_FromLong(offset));
    PyTuple_SET_ITEM(result, 1, code_object_desc);
    PyTuple_SET_ITEM0(result, 2, function->m_defaults);
    PyTuple_SET_ITEM0(result, 3, function->m_doc != NULL ? function->m_doc : Py_None);

    CHECK_OBJECT_DEEP(result);

    return result;
}

static PyMethodDef _method_def_reduce_compiled_function = {"reduce_compiled_function", (PyCFunction)_reduce_compiled_function,
                                                           METH_VARARGS | METH_KEYWORDS, NULL};

static char const *_create_compiled_function_argnames[] = {
    "func",
    "code_object_desc",
    "defaults",
    "doc",
    NULL
};


static PyObject *_create_compiled_function(PyObject *self, PyObject *args, PyObject *kwds) {
    CHECK_OBJECT_DEEP(args);

    PyObject *func;
    PyObject *code_object_desc;
    PyObject *defaults;
    PyObject *doc;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "OOOO:create_compiled_function", (char **)_create_compiled_function_argnames, &func, &code_object_desc, &defaults, &doc, NULL)) {
        return NULL;
    }

    int offset = PyLong_AsLong(func);

    if (offset == -1 && HAS_ERROR_OCCURRED(tstate)) {
        return NULL;
    }

    if (offset > sizeof(functable_pyudev$_ctypeslib$libudev) || offset < 0) {
        SET_CURRENT_EXCEPTION_TYPE0_STR_STATE(tstate, PyExc_TypeError, "Wrong offset for compiled function.");
        return NULL;
    }

    PyObject *filename = PyTuple_GET_ITEM(code_object_desc, 0);
    PyObject *function_name = PyTuple_GET_ITEM(code_object_desc, 1);
    PyObject *line = PyTuple_GET_ITEM(code_object_desc, 2);
    int line_int = PyLong_AsLong(line);
    assert(!HAS_ERROR_OCCURRED(tstate));

    PyObject *argnames = PyTuple_GET_ITEM(code_object_desc, 3);
    PyObject *arg_count = PyTuple_GET_ITEM(code_object_desc, 4);
    int arg_count_int = PyLong_AsLong(arg_count);
    assert(!HAS_ERROR_OCCURRED(tstate));
    PyObject *flags = PyTuple_GET_ITEM(code_object_desc, 5);
    int flags_int = PyLong_AsLong(flags);
    assert(!HAS_ERROR_OCCURRED(tstate));

    PyCodeObject *code_object = MAKE_CODE_OBJECT(
        filename,
        line_int,
        flags_int,
        function_name,
        function_name, // TODO: function_qualname
        argnames,
        NULL, // freevars
        arg_count_int,
        0, // TODO: Missing kw_only_count
        0 // TODO: Missing pos_only_count
    );

    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        functable_pyudev$_ctypeslib$libudev[offset],
        code_object->co_name,
#if PYTHON_VERSION >= 0x300
        NULL, // TODO: Not transferring qualname yet
#endif
        code_object,
        defaults,
#if PYTHON_VERSION >= 0x300
        NULL, // kwdefaults are done on the outside currently
        NULL, // TODO: Not transferring annotations
#endif
        module_pyudev$_ctypeslib$libudev,
        doc,
        NULL,
        0
    );

    return (PyObject *)result;
}

static PyMethodDef _method_def_create_compiled_function = {
    "create_compiled_function",
    (PyCFunction)_create_compiled_function,
    METH_VARARGS | METH_KEYWORDS, NULL
};


#endif

// Internal entry point for module code.
PyObject *modulecode_pyudev$_ctypeslib$libudev(PyThreadState *tstate, PyObject *module, struct Nuitka_MetaPathBasedLoaderEntry const *loader_entry) {
    // Report entry to PGO.
    PGO_onModuleEntered("pyudev._ctypeslib.libudev");

    // Store the module for future use.
    module_pyudev$_ctypeslib$libudev = module;

    // Modules can be loaded again in case of errors, avoid the init being done again.
    static bool init_done = false;

    if (init_done == false) {
#if defined(_NUITKA_MODULE) && 0
        // In case of an extension module loaded into a process, we need to call
        // initialization here because that's the first and potentially only time
        // we are going called.

        // Initialize the constant values used.
        _initBuiltinModule();
        createGlobalConstants(tstate);

        /* Initialize the compiled types of Nuitka. */
        _initCompiledCellType();
        _initCompiledGeneratorType();
        _initCompiledFunctionType();
        _initCompiledMethodType();
        _initCompiledFrameType();

        _initSlotCompare();
#if PYTHON_VERSION >= 0x270
        _initSlotIterNext();
#endif

        patchTypeComparison();

        // Enable meta path based loader if not already done.
#ifdef _NUITKA_TRACE
        PRINT_STRING("pyudev._ctypeslib.libudev: Calling setupMetaPathBasedLoader().\n");
#endif
        setupMetaPathBasedLoader(tstate);

#if PYTHON_VERSION >= 0x300
        patchInspectModule(tstate);
#endif

#endif

        /* The constants only used by this module are created now. */
        NUITKA_PRINT_TRACE("pyudev._ctypeslib.libudev: Calling createModuleConstants().\n");
        createModuleConstants(tstate);

        createModuleCodeObjects();

        init_done = true;
    }

    // PRINT_STRING("in initpyudev$_ctypeslib$libudev\n");

    moduledict_pyudev$_ctypeslib$libudev = MODULE_DICT(module_pyudev$_ctypeslib$libudev);

#ifdef _NUITKA_PLUGIN_DILL_ENABLED
    registerDillPluginTables(tstate, loader_entry->name, &_method_def_reduce_compiled_function, &_method_def_create_compiled_function);
#endif

    // Set "__compiled__" to what version information we have.
    UPDATE_STRING_DICT0(
        moduledict_pyudev$_ctypeslib$libudev,
        (Nuitka_StringObject *)const_str_plain___compiled__,
        Nuitka_dunder_compiled_value
    );

    // Update "__package__" value to what it ought to be.
    {
#if 0
        UPDATE_STRING_DICT0(
            moduledict_pyudev$_ctypeslib$libudev,
            (Nuitka_StringObject *)const_str_plain___package__,
            mod_consts[122]
        );
#elif 0
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)const_str_plain___name__);

        UPDATE_STRING_DICT0(
            moduledict_pyudev$_ctypeslib$libudev,
            (Nuitka_StringObject *)const_str_plain___package__,
            module_name
        );
#else

#if PYTHON_VERSION < 0x300
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)const_str_plain___name__);
        char const *module_name_cstr = PyString_AS_STRING(module_name);

        char const *last_dot = strrchr(module_name_cstr, '.');

        if (last_dot != NULL) {
            UPDATE_STRING_DICT1(
                moduledict_pyudev$_ctypeslib$libudev,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyString_FromStringAndSize(module_name_cstr, last_dot - module_name_cstr)
            );
        }
#else
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)const_str_plain___name__);
        Py_ssize_t dot_index = PyUnicode_Find(module_name, const_str_dot, 0, PyUnicode_GetLength(module_name), -1);

        if (dot_index != -1) {
            UPDATE_STRING_DICT1(
                moduledict_pyudev$_ctypeslib$libudev,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyUnicode_Substring(module_name, 0, dot_index)
            );
        }
#endif
#endif
    }

    CHECK_OBJECT(module_pyudev$_ctypeslib$libudev);

    // For deep importing of a module we need to have "__builtins__", so we set
    // it ourselves in the same way than CPython does. Note: This must be done
    // before the frame object is allocated, or else it may fail.

    if (GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)const_str_plain___builtins__) == NULL) {
        PyObject *value = (PyObject *)builtin_module;

        // Check if main module, not a dict then but the module itself.
#if defined(_NUITKA_MODULE) || !0
        value = PyModule_GetDict(value);
#endif

        UPDATE_STRING_DICT0(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)const_str_plain___builtins__, value);
    }

    UPDATE_STRING_DICT0(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)const_str_plain___loader__, (PyObject *)&Nuitka_Loader_Type);

#if PYTHON_VERSION >= 0x340
// Set the "__spec__" value

#if 0
    // Main modules just get "None" as spec.
    UPDATE_STRING_DICT0(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)const_str_plain___spec__, Py_None);
#else
    // Other modules get a "ModuleSpec" from the standard mechanism.
    {
        PyObject *bootstrap_module = getImportLibBootstrapModule();
        CHECK_OBJECT(bootstrap_module);

        PyObject *_spec_from_module = PyObject_GetAttrString(bootstrap_module, "_spec_from_module");
        CHECK_OBJECT(_spec_from_module);

        PyObject *spec_value = CALL_FUNCTION_WITH_SINGLE_ARG(tstate, _spec_from_module, module_pyudev$_ctypeslib$libudev);
        Py_DECREF(_spec_from_module);

        // We can assume this to never fail, or else we are in trouble anyway.
        // CHECK_OBJECT(spec_value);

        if (spec_value == NULL) {
            PyErr_PrintEx(0);
            abort();
        }

// Mark the execution in the "__spec__" value.
        SET_ATTRIBUTE(tstate, spec_value, const_str_plain__initializing, Py_True);

        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)const_str_plain___spec__, spec_value);
    }
#endif
#endif

    // Temp variables if any
    PyObject *outline_0_var___class__ = NULL;
    PyObject *outline_1_var___class__ = NULL;
    PyObject *outline_2_var___class__ = NULL;
    PyObject *outline_3_var___class__ = NULL;
    PyObject *outline_4_var___class__ = NULL;
    PyObject *outline_5_var___class__ = NULL;
    PyObject *tmp_class_creation_1__bases = NULL;
    PyObject *tmp_class_creation_1__bases_orig = NULL;
    PyObject *tmp_class_creation_1__class_decl_dict = NULL;
    PyObject *tmp_class_creation_1__metaclass = NULL;
    PyObject *tmp_class_creation_1__prepared = NULL;
    PyObject *tmp_class_creation_2__bases = NULL;
    PyObject *tmp_class_creation_2__bases_orig = NULL;
    PyObject *tmp_class_creation_2__class_decl_dict = NULL;
    PyObject *tmp_class_creation_2__metaclass = NULL;
    PyObject *tmp_class_creation_2__prepared = NULL;
    PyObject *tmp_class_creation_3__bases = NULL;
    PyObject *tmp_class_creation_3__bases_orig = NULL;
    PyObject *tmp_class_creation_3__class_decl_dict = NULL;
    PyObject *tmp_class_creation_3__metaclass = NULL;
    PyObject *tmp_class_creation_3__prepared = NULL;
    PyObject *tmp_class_creation_4__bases = NULL;
    PyObject *tmp_class_creation_4__bases_orig = NULL;
    PyObject *tmp_class_creation_4__class_decl_dict = NULL;
    PyObject *tmp_class_creation_4__metaclass = NULL;
    PyObject *tmp_class_creation_4__prepared = NULL;
    PyObject *tmp_class_creation_5__bases = NULL;
    PyObject *tmp_class_creation_5__bases_orig = NULL;
    PyObject *tmp_class_creation_5__class_decl_dict = NULL;
    PyObject *tmp_class_creation_5__metaclass = NULL;
    PyObject *tmp_class_creation_5__prepared = NULL;
    PyObject *tmp_class_creation_6__bases = NULL;
    PyObject *tmp_class_creation_6__bases_orig = NULL;
    PyObject *tmp_class_creation_6__class_decl_dict = NULL;
    PyObject *tmp_class_creation_6__metaclass = NULL;
    PyObject *tmp_class_creation_6__prepared = NULL;
    PyObject *tmp_import_from_1__module = NULL;
    PyObject *tmp_import_from_2__module = NULL;
    struct Nuitka_FrameObject *frame_e59f6b39efaed77d0ee6049d7354ed8b;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    bool tmp_result;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;
    PyObject *exception_keeper_type_2;
    PyObject *exception_keeper_value_2;
    PyTracebackObject *exception_keeper_tb_2;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_2;
    int tmp_res;
    PyObject *locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37 = NULL;
    PyObject *tmp_dictset_value;
    PyObject *exception_keeper_type_3;
    PyObject *exception_keeper_value_3;
    PyTracebackObject *exception_keeper_tb_3;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_3;
    PyObject *exception_keeper_type_4;
    PyObject *exception_keeper_value_4;
    PyTracebackObject *exception_keeper_tb_4;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_4;
    PyObject *exception_keeper_type_5;
    PyObject *exception_keeper_value_5;
    PyTracebackObject *exception_keeper_tb_5;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_5;
    PyObject *locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49 = NULL;
    PyObject *exception_keeper_type_6;
    PyObject *exception_keeper_value_6;
    PyTracebackObject *exception_keeper_tb_6;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_6;
    PyObject *exception_keeper_type_7;
    PyObject *exception_keeper_value_7;
    PyTracebackObject *exception_keeper_tb_7;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_7;
    PyObject *exception_keeper_type_8;
    PyObject *exception_keeper_value_8;
    PyTracebackObject *exception_keeper_tb_8;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_8;
    PyObject *locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61 = NULL;
    PyObject *exception_keeper_type_9;
    PyObject *exception_keeper_value_9;
    PyTracebackObject *exception_keeper_tb_9;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_9;
    PyObject *exception_keeper_type_10;
    PyObject *exception_keeper_value_10;
    PyTracebackObject *exception_keeper_tb_10;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_10;
    PyObject *exception_keeper_type_11;
    PyObject *exception_keeper_value_11;
    PyTracebackObject *exception_keeper_tb_11;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_11;
    PyObject *locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73 = NULL;
    PyObject *exception_keeper_type_12;
    PyObject *exception_keeper_value_12;
    PyTracebackObject *exception_keeper_tb_12;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_12;
    PyObject *exception_keeper_type_13;
    PyObject *exception_keeper_value_13;
    PyTracebackObject *exception_keeper_tb_13;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_13;
    PyObject *exception_keeper_type_14;
    PyObject *exception_keeper_value_14;
    PyTracebackObject *exception_keeper_tb_14;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_14;
    PyObject *locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85 = NULL;
    PyObject *exception_keeper_type_15;
    PyObject *exception_keeper_value_15;
    PyTracebackObject *exception_keeper_tb_15;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_15;
    PyObject *exception_keeper_type_16;
    PyObject *exception_keeper_value_16;
    PyTracebackObject *exception_keeper_tb_16;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_16;
    PyObject *exception_keeper_type_17;
    PyObject *exception_keeper_value_17;
    PyTracebackObject *exception_keeper_tb_17;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_17;
    PyObject *locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97 = NULL;
    PyObject *exception_keeper_type_18;
    PyObject *exception_keeper_value_18;
    PyTracebackObject *exception_keeper_tb_18;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_18;
    PyObject *exception_keeper_type_19;
    PyObject *exception_keeper_value_19;
    PyTracebackObject *exception_keeper_tb_19;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_19;
    PyObject *exception_keeper_type_20;
    PyObject *exception_keeper_value_20;
    PyTracebackObject *exception_keeper_tb_20;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_20;

    // Module code.
    {
        PyObject *tmp_assign_source_1;
        tmp_assign_source_1 = mod_consts[0];
        UPDATE_STRING_DICT0(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[1], tmp_assign_source_1);
    }
    {
        PyObject *tmp_assign_source_2;
        tmp_assign_source_2 = module_filename_obj;
        UPDATE_STRING_DICT0(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[2], tmp_assign_source_2);
    }
    frame_e59f6b39efaed77d0ee6049d7354ed8b = MAKE_MODULE_FRAME(codeobj_e59f6b39efaed77d0ee6049d7354ed8b, module_pyudev$_ctypeslib$libudev);

    // Push the new frame as the currently active one, and we should be exclusively
    // owning it.
    pushFrameStackCompiledFrame(tstate, frame_e59f6b39efaed77d0ee6049d7354ed8b);
    assert(Py_REFCNT(frame_e59f6b39efaed77d0ee6049d7354ed8b) == 2);

    // Framed code:
    {
        PyObject *tmp_assattr_value_1;
        PyObject *tmp_assattr_target_1;
        tmp_assattr_value_1 = module_filename_obj;
        tmp_assattr_target_1 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[3]);

        if (unlikely(tmp_assattr_target_1 == NULL)) {
            tmp_assattr_target_1 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[3]);
        }

        assert(!(tmp_assattr_target_1 == NULL));
        tmp_result = SET_ATTRIBUTE(tstate, tmp_assattr_target_1, mod_consts[4], tmp_assattr_value_1);
        if (tmp_result == false) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_assattr_value_2;
        PyObject *tmp_assattr_target_2;
        tmp_assattr_value_2 = Py_True;
        tmp_assattr_target_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[3]);

        if (unlikely(tmp_assattr_target_2 == NULL)) {
            tmp_assattr_target_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[3]);
        }

        assert(!(tmp_assattr_target_2 == NULL));
        tmp_result = SET_ATTRIBUTE(tstate, tmp_assattr_target_2, mod_consts[5], tmp_assattr_value_2);
        if (tmp_result == false) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_assign_source_3;
        tmp_assign_source_3 = Py_None;
        UPDATE_STRING_DICT0(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[6], tmp_assign_source_3);
    }
    {
        PyObject *tmp_assign_source_4;
        tmp_assign_source_4 = IMPORT_HARD_CTYPES();
        assert(!(tmp_assign_source_4 == NULL));
        assert(tmp_import_from_1__module == NULL);
        Py_INCREF(tmp_assign_source_4);
        tmp_import_from_1__module = tmp_assign_source_4;
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_5;
        PyObject *tmp_import_name_from_1;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_1 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_1)) {
            tmp_assign_source_5 = IMPORT_NAME_OR_MODULE(
                tstate,
                tmp_import_name_from_1,
                (PyObject *)moduledict_pyudev$_ctypeslib$libudev,
                mod_consts[7],
                mod_consts[8]
            );
        } else {
            tmp_assign_source_5 = IMPORT_NAME_FROM_MODULE(tstate, tmp_import_name_from_1, mod_consts[7]);
        }

        if (tmp_assign_source_5 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 28;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[7], tmp_assign_source_5);
    }
    {
        PyObject *tmp_assign_source_6;
        PyObject *tmp_import_name_from_2;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_2 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_2)) {
            tmp_assign_source_6 = IMPORT_NAME_OR_MODULE(
                tstate,
                tmp_import_name_from_2,
                (PyObject *)moduledict_pyudev$_ctypeslib$libudev,
                mod_consts[9],
                mod_consts[8]
            );
        } else {
            tmp_assign_source_6 = IMPORT_NAME_FROM_MODULE(tstate, tmp_import_name_from_2, mod_consts[9]);
        }

        if (tmp_assign_source_6 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 28;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[9], tmp_assign_source_6);
    }
    {
        PyObject *tmp_assign_source_7;
        PyObject *tmp_import_name_from_3;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_3 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_3)) {
            tmp_assign_source_7 = IMPORT_NAME_OR_MODULE(
                tstate,
                tmp_import_name_from_3,
                (PyObject *)moduledict_pyudev$_ctypeslib$libudev,
                mod_consts[10],
                mod_consts[8]
            );
        } else {
            tmp_assign_source_7 = IMPORT_NAME_FROM_MODULE(tstate, tmp_import_name_from_3, mod_consts[10]);
        }

        if (tmp_assign_source_7 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 28;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[10], tmp_assign_source_7);
    }
    {
        PyObject *tmp_assign_source_8;
        PyObject *tmp_import_name_from_4;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_4 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_4)) {
            tmp_assign_source_8 = IMPORT_NAME_OR_MODULE(
                tstate,
                tmp_import_name_from_4,
                (PyObject *)moduledict_pyudev$_ctypeslib$libudev,
                mod_consts[11],
                mod_consts[8]
            );
        } else {
            tmp_assign_source_8 = IMPORT_NAME_FROM_MODULE(tstate, tmp_import_name_from_4, mod_consts[11]);
        }

        if (tmp_assign_source_8 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 28;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11], tmp_assign_source_8);
    }
    {
        PyObject *tmp_assign_source_9;
        PyObject *tmp_import_name_from_5;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_5 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_5)) {
            tmp_assign_source_9 = IMPORT_NAME_OR_MODULE(
                tstate,
                tmp_import_name_from_5,
                (PyObject *)moduledict_pyudev$_ctypeslib$libudev,
                mod_consts[12],
                mod_consts[8]
            );
        } else {
            tmp_assign_source_9 = IMPORT_NAME_FROM_MODULE(tstate, tmp_import_name_from_5, mod_consts[12]);
        }

        if (tmp_assign_source_9 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 28;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12], tmp_assign_source_9);
    }
    {
        PyObject *tmp_assign_source_10;
        PyObject *tmp_import_name_from_6;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_6 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_6)) {
            tmp_assign_source_10 = IMPORT_NAME_OR_MODULE(
                tstate,
                tmp_import_name_from_6,
                (PyObject *)moduledict_pyudev$_ctypeslib$libudev,
                mod_consts[13],
                mod_consts[8]
            );
        } else {
            tmp_assign_source_10 = IMPORT_NAME_FROM_MODULE(tstate, tmp_import_name_from_6, mod_consts[13]);
        }

        if (tmp_assign_source_10 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 28;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[13], tmp_assign_source_10);
    }
    {
        PyObject *tmp_assign_source_11;
        PyObject *tmp_import_name_from_7;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_7 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_7)) {
            tmp_assign_source_11 = IMPORT_NAME_OR_MODULE(
                tstate,
                tmp_import_name_from_7,
                (PyObject *)moduledict_pyudev$_ctypeslib$libudev,
                mod_consts[14],
                mod_consts[8]
            );
        } else {
            tmp_assign_source_11 = IMPORT_NAME_FROM_MODULE(tstate, tmp_import_name_from_7, mod_consts[14]);
        }

        if (tmp_assign_source_11 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 28;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[14], tmp_assign_source_11);
    }
    goto try_end_1;
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    CHECK_OBJECT(tmp_import_from_1__module);
    Py_DECREF(tmp_import_from_1__module);
    tmp_import_from_1__module = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto frame_exception_exit_1;
    // End of try:
    try_end_1:;
    CHECK_OBJECT(tmp_import_from_1__module);
    Py_DECREF(tmp_import_from_1__module);
    tmp_import_from_1__module = NULL;
    {
        PyObject *tmp_assign_source_12;
        PyObject *tmp_name_value_1;
        PyObject *tmp_globals_arg_value_1;
        PyObject *tmp_locals_arg_value_1;
        PyObject *tmp_fromlist_value_1;
        PyObject *tmp_level_value_1;
        tmp_name_value_1 = mod_consts[15];
        tmp_globals_arg_value_1 = (PyObject *)moduledict_pyudev$_ctypeslib$libudev;
        tmp_locals_arg_value_1 = Py_None;
        tmp_fromlist_value_1 = mod_consts[16];
        tmp_level_value_1 = mod_consts[17];
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 30;
        tmp_assign_source_12 = IMPORT_MODULE5(tstate, tmp_name_value_1, tmp_globals_arg_value_1, tmp_locals_arg_value_1, tmp_fromlist_value_1, tmp_level_value_1);
        if (tmp_assign_source_12 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 30;

            goto frame_exception_exit_1;
        }
        assert(tmp_import_from_2__module == NULL);
        tmp_import_from_2__module = tmp_assign_source_12;
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_13;
        PyObject *tmp_import_name_from_8;
        CHECK_OBJECT(tmp_import_from_2__module);
        tmp_import_name_from_8 = tmp_import_from_2__module;
        if (PyModule_Check(tmp_import_name_from_8)) {
            tmp_assign_source_13 = IMPORT_NAME_OR_MODULE(
                tstate,
                tmp_import_name_from_8,
                (PyObject *)moduledict_pyudev$_ctypeslib$libudev,
                mod_consts[18],
                mod_consts[8]
            );
        } else {
            tmp_assign_source_13 = IMPORT_NAME_FROM_MODULE(tstate, tmp_import_name_from_8, mod_consts[18]);
        }

        if (tmp_assign_source_13 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 30;

            goto try_except_handler_2;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[18], tmp_assign_source_13);
    }
    {
        PyObject *tmp_assign_source_14;
        PyObject *tmp_import_name_from_9;
        CHECK_OBJECT(tmp_import_from_2__module);
        tmp_import_name_from_9 = tmp_import_from_2__module;
        if (PyModule_Check(tmp_import_name_from_9)) {
            tmp_assign_source_14 = IMPORT_NAME_OR_MODULE(
                tstate,
                tmp_import_name_from_9,
                (PyObject *)moduledict_pyudev$_ctypeslib$libudev,
                mod_consts[19],
                mod_consts[8]
            );
        } else {
            tmp_assign_source_14 = IMPORT_NAME_FROM_MODULE(tstate, tmp_import_name_from_9, mod_consts[19]);
        }

        if (tmp_assign_source_14 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 30;

            goto try_except_handler_2;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[19], tmp_assign_source_14);
    }
    {
        PyObject *tmp_assign_source_15;
        PyObject *tmp_import_name_from_10;
        CHECK_OBJECT(tmp_import_from_2__module);
        tmp_import_name_from_10 = tmp_import_from_2__module;
        if (PyModule_Check(tmp_import_name_from_10)) {
            tmp_assign_source_15 = IMPORT_NAME_OR_MODULE(
                tstate,
                tmp_import_name_from_10,
                (PyObject *)moduledict_pyudev$_ctypeslib$libudev,
                mod_consts[20],
                mod_consts[8]
            );
        } else {
            tmp_assign_source_15 = IMPORT_NAME_FROM_MODULE(tstate, tmp_import_name_from_10, mod_consts[20]);
        }

        if (tmp_assign_source_15 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 30;

            goto try_except_handler_2;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20], tmp_assign_source_15);
    }
    goto try_end_2;
    // Exception handler code:
    try_except_handler_2:;
    exception_keeper_type_2 = exception_type;
    exception_keeper_value_2 = exception_value;
    exception_keeper_tb_2 = exception_tb;
    exception_keeper_lineno_2 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    CHECK_OBJECT(tmp_import_from_2__module);
    Py_DECREF(tmp_import_from_2__module);
    tmp_import_from_2__module = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_2;
    exception_value = exception_keeper_value_2;
    exception_tb = exception_keeper_tb_2;
    exception_lineno = exception_keeper_lineno_2;

    goto frame_exception_exit_1;
    // End of try:
    try_end_2:;
    CHECK_OBJECT(tmp_import_from_2__module);
    Py_DECREF(tmp_import_from_2__module);
    tmp_import_from_2__module = NULL;
    // Tried code:
    {
        PyObject *tmp_assign_source_16;
        PyObject *tmp_tuple_element_1;
        tmp_tuple_element_1 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[9]);

        if (unlikely(tmp_tuple_element_1 == NULL)) {
            tmp_tuple_element_1 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[9]);
        }

        if (tmp_tuple_element_1 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        tmp_assign_source_16 = MAKE_TUPLE_EMPTY(1);
        PyTuple_SET_ITEM0(tmp_assign_source_16, 0, tmp_tuple_element_1);
        assert(tmp_class_creation_1__bases_orig == NULL);
        tmp_class_creation_1__bases_orig = tmp_assign_source_16;
    }
    {
        PyObject *tmp_assign_source_17;
        PyObject *tmp_dircall_arg1_1;
        CHECK_OBJECT(tmp_class_creation_1__bases_orig);
        tmp_dircall_arg1_1 = tmp_class_creation_1__bases_orig;
        Py_INCREF(tmp_dircall_arg1_1);

        {
            PyObject *dir_call_args[] = {tmp_dircall_arg1_1};
            tmp_assign_source_17 = impl___main__$$$function__1__mro_entries_conversion(tstate, dir_call_args);
        }
        if (tmp_assign_source_17 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        assert(tmp_class_creation_1__bases == NULL);
        tmp_class_creation_1__bases = tmp_assign_source_17;
    }
    {
        PyObject *tmp_assign_source_18;
        tmp_assign_source_18 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_1__class_decl_dict == NULL);
        tmp_class_creation_1__class_decl_dict = tmp_assign_source_18;
    }
    {
        PyObject *tmp_assign_source_19;
        PyObject *tmp_metaclass_value_1;
        nuitka_bool tmp_condition_result_1;
        int tmp_truth_name_1;
        PyObject *tmp_type_arg_1;
        PyObject *tmp_expression_value_1;
        PyObject *tmp_subscript_value_1;
        PyObject *tmp_bases_value_1;
        CHECK_OBJECT(tmp_class_creation_1__bases);
        tmp_truth_name_1 = CHECK_IF_TRUE(tmp_class_creation_1__bases);
        if (tmp_truth_name_1 == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        tmp_condition_result_1 = tmp_truth_name_1 == 0 ? NUITKA_BOOL_FALSE : NUITKA_BOOL_TRUE;
        if (tmp_condition_result_1 == NUITKA_BOOL_TRUE) {
            goto condexpr_true_1;
        } else {
            goto condexpr_false_1;
        }
        condexpr_true_1:;
        CHECK_OBJECT(tmp_class_creation_1__bases);
        tmp_expression_value_1 = tmp_class_creation_1__bases;
        tmp_subscript_value_1 = mod_consts[8];
        tmp_type_arg_1 = LOOKUP_SUBSCRIPT_CONST(tstate, tmp_expression_value_1, tmp_subscript_value_1, 0);
        if (tmp_type_arg_1 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        tmp_metaclass_value_1 = BUILTIN_TYPE1(tmp_type_arg_1);
        Py_DECREF(tmp_type_arg_1);
        if (tmp_metaclass_value_1 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        goto condexpr_end_1;
        condexpr_false_1:;
        tmp_metaclass_value_1 = (PyObject *)&PyType_Type;
        Py_INCREF(tmp_metaclass_value_1);
        condexpr_end_1:;
        CHECK_OBJECT(tmp_class_creation_1__bases);
        tmp_bases_value_1 = tmp_class_creation_1__bases;
        tmp_assign_source_19 = SELECT_METACLASS(tstate, tmp_metaclass_value_1, tmp_bases_value_1);
        Py_DECREF(tmp_metaclass_value_1);
        if (tmp_assign_source_19 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        assert(tmp_class_creation_1__metaclass == NULL);
        tmp_class_creation_1__metaclass = tmp_assign_source_19;
    }
    {
        bool tmp_condition_result_2;
        PyObject *tmp_expression_value_2;
        CHECK_OBJECT(tmp_class_creation_1__metaclass);
        tmp_expression_value_2 = tmp_class_creation_1__metaclass;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_2, mod_consts[21]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        tmp_condition_result_2 = (tmp_res != 0) ? true : false;
        if (tmp_condition_result_2 != false) {
            goto branch_yes_1;
        } else {
            goto branch_no_1;
        }
    }
    branch_yes_1:;
    {
        PyObject *tmp_assign_source_20;
        PyObject *tmp_called_value_1;
        PyObject *tmp_expression_value_3;
        PyObject *tmp_args_value_1;
        PyObject *tmp_tuple_element_2;
        PyObject *tmp_kwargs_value_1;
        CHECK_OBJECT(tmp_class_creation_1__metaclass);
        tmp_expression_value_3 = tmp_class_creation_1__metaclass;
        tmp_called_value_1 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_3, mod_consts[21]);
        if (tmp_called_value_1 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        tmp_tuple_element_2 = mod_consts[22];
        tmp_args_value_1 = MAKE_TUPLE_EMPTY(2);
        PyTuple_SET_ITEM0(tmp_args_value_1, 0, tmp_tuple_element_2);
        CHECK_OBJECT(tmp_class_creation_1__bases);
        tmp_tuple_element_2 = tmp_class_creation_1__bases;
        PyTuple_SET_ITEM0(tmp_args_value_1, 1, tmp_tuple_element_2);
        CHECK_OBJECT(tmp_class_creation_1__class_decl_dict);
        tmp_kwargs_value_1 = tmp_class_creation_1__class_decl_dict;
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 37;
        tmp_assign_source_20 = CALL_FUNCTION(tstate, tmp_called_value_1, tmp_args_value_1, tmp_kwargs_value_1);
        Py_DECREF(tmp_called_value_1);
        Py_DECREF(tmp_args_value_1);
        if (tmp_assign_source_20 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        assert(tmp_class_creation_1__prepared == NULL);
        tmp_class_creation_1__prepared = tmp_assign_source_20;
    }
    {
        bool tmp_condition_result_3;
        PyObject *tmp_operand_value_1;
        PyObject *tmp_expression_value_4;
        CHECK_OBJECT(tmp_class_creation_1__prepared);
        tmp_expression_value_4 = tmp_class_creation_1__prepared;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_4, mod_consts[23]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        tmp_operand_value_1 = (tmp_res != 0) ? Py_True : Py_False;
        tmp_res = CHECK_IF_TRUE(tmp_operand_value_1);
        assert(!(tmp_res == -1));
        tmp_condition_result_3 = (tmp_res == 0) ? true : false;
        if (tmp_condition_result_3 != false) {
            goto branch_yes_2;
        } else {
            goto branch_no_2;
        }
    }
    branch_yes_2:;
    {
        PyObject *tmp_raise_type_1;
        PyObject *tmp_raise_value_1;
        PyObject *tmp_mod_expr_left_1;
        PyObject *tmp_mod_expr_right_1;
        PyObject *tmp_tuple_element_3;
        PyObject *tmp_expression_value_5;
        PyObject *tmp_name_value_2;
        PyObject *tmp_default_value_1;
        tmp_raise_type_1 = PyExc_TypeError;
        tmp_mod_expr_left_1 = mod_consts[24];
        CHECK_OBJECT(tmp_class_creation_1__metaclass);
        tmp_expression_value_5 = tmp_class_creation_1__metaclass;
        tmp_name_value_2 = mod_consts[25];
        tmp_default_value_1 = mod_consts[26];
        tmp_tuple_element_3 = BUILTIN_GETATTR(tstate, tmp_expression_value_5, tmp_name_value_2, tmp_default_value_1);
        if (tmp_tuple_element_3 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        tmp_mod_expr_right_1 = MAKE_TUPLE_EMPTY(2);
        {
            PyObject *tmp_expression_value_6;
            PyObject *tmp_type_arg_2;
            PyTuple_SET_ITEM(tmp_mod_expr_right_1, 0, tmp_tuple_element_3);
            CHECK_OBJECT(tmp_class_creation_1__prepared);
            tmp_type_arg_2 = tmp_class_creation_1__prepared;
            tmp_expression_value_6 = BUILTIN_TYPE1(tmp_type_arg_2);
            assert(!(tmp_expression_value_6 == NULL));
            tmp_tuple_element_3 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_6, mod_consts[25]);
            Py_DECREF(tmp_expression_value_6);
            if (tmp_tuple_element_3 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 37;

                goto tuple_build_exception_1;
            }
            PyTuple_SET_ITEM(tmp_mod_expr_right_1, 1, tmp_tuple_element_3);
        }
        goto tuple_build_noexception_1;
        // Exception handling pass through code for tuple_build:
        tuple_build_exception_1:;
        Py_DECREF(tmp_mod_expr_right_1);
        goto try_except_handler_3;
        // Finished with no exception for tuple_build:
        tuple_build_noexception_1:;
        tmp_raise_value_1 = BINARY_OPERATION_MOD_OBJECT_UNICODE_TUPLE(tmp_mod_expr_left_1, tmp_mod_expr_right_1);
        Py_DECREF(tmp_mod_expr_right_1);
        if (tmp_raise_value_1 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_3;
        }
        exception_type = tmp_raise_type_1;
        Py_INCREF(tmp_raise_type_1);
        exception_value = tmp_raise_value_1;
        exception_lineno = 37;
        RAISE_EXCEPTION_IMPLICIT(tstate, &exception_type, &exception_value, &exception_tb);

        goto try_except_handler_3;
    }
    branch_no_2:;
    goto branch_end_1;
    branch_no_1:;
    {
        PyObject *tmp_assign_source_21;
        tmp_assign_source_21 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_1__prepared == NULL);
        tmp_class_creation_1__prepared = tmp_assign_source_21;
    }
    branch_end_1:;
    {
        PyObject *tmp_assign_source_22;
        {
            PyObject *tmp_set_locals_1;
            CHECK_OBJECT(tmp_class_creation_1__prepared);
            tmp_set_locals_1 = tmp_class_creation_1__prepared;
            locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37 = tmp_set_locals_1;
            Py_INCREF(tmp_set_locals_1);
        }
        // Tried code:
        // Tried code:
        tmp_dictset_value = mod_consts[27];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37, mod_consts[28], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_5;
        }
        tmp_dictset_value = mod_consts[29];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37, mod_consts[1], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_5;
        }
        tmp_dictset_value = mod_consts[22];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37, mod_consts[30], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_5;
        }
        {
            nuitka_bool tmp_condition_result_4;
            PyObject *tmp_cmp_expr_left_1;
            PyObject *tmp_cmp_expr_right_1;
            CHECK_OBJECT(tmp_class_creation_1__bases);
            tmp_cmp_expr_left_1 = tmp_class_creation_1__bases;
            CHECK_OBJECT(tmp_class_creation_1__bases_orig);
            tmp_cmp_expr_right_1 = tmp_class_creation_1__bases_orig;
            tmp_condition_result_4 = RICH_COMPARE_NE_NBOOL_OBJECT_TUPLE(tmp_cmp_expr_left_1, tmp_cmp_expr_right_1);
            if (tmp_condition_result_4 == NUITKA_BOOL_EXCEPTION) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 37;

                goto try_except_handler_5;
            }
            if (tmp_condition_result_4 == NUITKA_BOOL_TRUE) {
                goto branch_yes_3;
            } else {
                goto branch_no_3;
            }
        }
        branch_yes_3:;
        CHECK_OBJECT(tmp_class_creation_1__bases_orig);
        tmp_dictset_value = tmp_class_creation_1__bases_orig;
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37, mod_consts[31], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_5;
        }
        branch_no_3:;
        {
            PyObject *tmp_assign_source_23;
            PyObject *tmp_called_value_2;
            PyObject *tmp_args_value_2;
            PyObject *tmp_tuple_element_4;
            PyObject *tmp_kwargs_value_2;
            CHECK_OBJECT(tmp_class_creation_1__metaclass);
            tmp_called_value_2 = tmp_class_creation_1__metaclass;
            tmp_tuple_element_4 = mod_consts[22];
            tmp_args_value_2 = MAKE_TUPLE_EMPTY(3);
            PyTuple_SET_ITEM0(tmp_args_value_2, 0, tmp_tuple_element_4);
            CHECK_OBJECT(tmp_class_creation_1__bases);
            tmp_tuple_element_4 = tmp_class_creation_1__bases;
            PyTuple_SET_ITEM0(tmp_args_value_2, 1, tmp_tuple_element_4);
            tmp_tuple_element_4 = locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37;
            PyTuple_SET_ITEM0(tmp_args_value_2, 2, tmp_tuple_element_4);
            CHECK_OBJECT(tmp_class_creation_1__class_decl_dict);
            tmp_kwargs_value_2 = tmp_class_creation_1__class_decl_dict;
            frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 37;
            tmp_assign_source_23 = CALL_FUNCTION(tstate, tmp_called_value_2, tmp_args_value_2, tmp_kwargs_value_2);
            Py_DECREF(tmp_args_value_2);
            if (tmp_assign_source_23 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 37;

                goto try_except_handler_5;
            }
            assert(outline_0_var___class__ == NULL);
            outline_0_var___class__ = tmp_assign_source_23;
        }
        CHECK_OBJECT(outline_0_var___class__);
        tmp_assign_source_22 = outline_0_var___class__;
        Py_INCREF(tmp_assign_source_22);
        goto try_return_handler_5;
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_5:;
        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37);
        locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37 = NULL;
        goto try_return_handler_4;
        // Exception handler code:
        try_except_handler_5:;
        exception_keeper_type_3 = exception_type;
        exception_keeper_value_3 = exception_value;
        exception_keeper_tb_3 = exception_tb;
        exception_keeper_lineno_3 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37);
        locals_pyudev$_ctypeslib$libudev$$$class__1_udev_37 = NULL;
        // Re-raise.
        exception_type = exception_keeper_type_3;
        exception_value = exception_keeper_value_3;
        exception_tb = exception_keeper_tb_3;
        exception_lineno = exception_keeper_lineno_3;

        goto try_except_handler_4;
        // End of try:
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_4:;
        CHECK_OBJECT(outline_0_var___class__);
        Py_DECREF(outline_0_var___class__);
        outline_0_var___class__ = NULL;
        goto outline_result_1;
        // Exception handler code:
        try_except_handler_4:;
        exception_keeper_type_4 = exception_type;
        exception_keeper_value_4 = exception_value;
        exception_keeper_tb_4 = exception_tb;
        exception_keeper_lineno_4 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        // Re-raise.
        exception_type = exception_keeper_type_4;
        exception_value = exception_keeper_value_4;
        exception_tb = exception_keeper_tb_4;
        exception_lineno = exception_keeper_lineno_4;

        goto outline_exception_1;
        // End of try:
        NUITKA_CANNOT_GET_HERE("Return statement must have exited already.");
        return NULL;
        outline_exception_1:;
        exception_lineno = 37;
        goto try_except_handler_3;
        outline_result_1:;
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[22], tmp_assign_source_22);
    }
    goto try_end_3;
    // Exception handler code:
    try_except_handler_3:;
    exception_keeper_type_5 = exception_type;
    exception_keeper_value_5 = exception_value;
    exception_keeper_tb_5 = exception_tb;
    exception_keeper_lineno_5 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    Py_XDECREF(tmp_class_creation_1__bases_orig);
    tmp_class_creation_1__bases_orig = NULL;
    Py_XDECREF(tmp_class_creation_1__bases);
    tmp_class_creation_1__bases = NULL;
    Py_XDECREF(tmp_class_creation_1__class_decl_dict);
    tmp_class_creation_1__class_decl_dict = NULL;
    Py_XDECREF(tmp_class_creation_1__metaclass);
    tmp_class_creation_1__metaclass = NULL;
    Py_XDECREF(tmp_class_creation_1__prepared);
    tmp_class_creation_1__prepared = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_5;
    exception_value = exception_keeper_value_5;
    exception_tb = exception_keeper_tb_5;
    exception_lineno = exception_keeper_lineno_5;

    goto frame_exception_exit_1;
    // End of try:
    try_end_3:;
    CHECK_OBJECT(tmp_class_creation_1__bases_orig);
    Py_DECREF(tmp_class_creation_1__bases_orig);
    tmp_class_creation_1__bases_orig = NULL;
    CHECK_OBJECT(tmp_class_creation_1__bases);
    Py_DECREF(tmp_class_creation_1__bases);
    tmp_class_creation_1__bases = NULL;
    CHECK_OBJECT(tmp_class_creation_1__class_decl_dict);
    Py_DECREF(tmp_class_creation_1__class_decl_dict);
    tmp_class_creation_1__class_decl_dict = NULL;
    CHECK_OBJECT(tmp_class_creation_1__metaclass);
    Py_DECREF(tmp_class_creation_1__metaclass);
    tmp_class_creation_1__metaclass = NULL;
    CHECK_OBJECT(tmp_class_creation_1__prepared);
    Py_DECREF(tmp_class_creation_1__prepared);
    tmp_class_creation_1__prepared = NULL;
    {
        PyObject *tmp_assign_source_24;
        PyObject *tmp_called_value_3;
        PyObject *tmp_args_element_value_1;
        tmp_called_value_3 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[7]);

        if (unlikely(tmp_called_value_3 == NULL)) {
            tmp_called_value_3 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[7]);
        }

        if (tmp_called_value_3 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 46;

            goto frame_exception_exit_1;
        }
        tmp_args_element_value_1 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[22]);

        if (unlikely(tmp_args_element_value_1 == NULL)) {
            tmp_args_element_value_1 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[22]);
        }

        if (tmp_args_element_value_1 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 46;

            goto frame_exception_exit_1;
        }
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 46;
        tmp_assign_source_24 = CALL_FUNCTION_WITH_SINGLE_ARG(tstate, tmp_called_value_3, tmp_args_element_value_1);
        if (tmp_assign_source_24 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 46;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32], tmp_assign_source_24);
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_25;
        PyObject *tmp_tuple_element_5;
        tmp_tuple_element_5 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[9]);

        if (unlikely(tmp_tuple_element_5 == NULL)) {
            tmp_tuple_element_5 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[9]);
        }

        if (tmp_tuple_element_5 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        tmp_assign_source_25 = MAKE_TUPLE_EMPTY(1);
        PyTuple_SET_ITEM0(tmp_assign_source_25, 0, tmp_tuple_element_5);
        assert(tmp_class_creation_2__bases_orig == NULL);
        tmp_class_creation_2__bases_orig = tmp_assign_source_25;
    }
    {
        PyObject *tmp_assign_source_26;
        PyObject *tmp_dircall_arg1_2;
        CHECK_OBJECT(tmp_class_creation_2__bases_orig);
        tmp_dircall_arg1_2 = tmp_class_creation_2__bases_orig;
        Py_INCREF(tmp_dircall_arg1_2);

        {
            PyObject *dir_call_args[] = {tmp_dircall_arg1_2};
            tmp_assign_source_26 = impl___main__$$$function__1__mro_entries_conversion(tstate, dir_call_args);
        }
        if (tmp_assign_source_26 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        assert(tmp_class_creation_2__bases == NULL);
        tmp_class_creation_2__bases = tmp_assign_source_26;
    }
    {
        PyObject *tmp_assign_source_27;
        tmp_assign_source_27 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_2__class_decl_dict == NULL);
        tmp_class_creation_2__class_decl_dict = tmp_assign_source_27;
    }
    {
        PyObject *tmp_assign_source_28;
        PyObject *tmp_metaclass_value_2;
        nuitka_bool tmp_condition_result_5;
        int tmp_truth_name_2;
        PyObject *tmp_type_arg_3;
        PyObject *tmp_expression_value_7;
        PyObject *tmp_subscript_value_2;
        PyObject *tmp_bases_value_2;
        CHECK_OBJECT(tmp_class_creation_2__bases);
        tmp_truth_name_2 = CHECK_IF_TRUE(tmp_class_creation_2__bases);
        if (tmp_truth_name_2 == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        tmp_condition_result_5 = tmp_truth_name_2 == 0 ? NUITKA_BOOL_FALSE : NUITKA_BOOL_TRUE;
        if (tmp_condition_result_5 == NUITKA_BOOL_TRUE) {
            goto condexpr_true_2;
        } else {
            goto condexpr_false_2;
        }
        condexpr_true_2:;
        CHECK_OBJECT(tmp_class_creation_2__bases);
        tmp_expression_value_7 = tmp_class_creation_2__bases;
        tmp_subscript_value_2 = mod_consts[8];
        tmp_type_arg_3 = LOOKUP_SUBSCRIPT_CONST(tstate, tmp_expression_value_7, tmp_subscript_value_2, 0);
        if (tmp_type_arg_3 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        tmp_metaclass_value_2 = BUILTIN_TYPE1(tmp_type_arg_3);
        Py_DECREF(tmp_type_arg_3);
        if (tmp_metaclass_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        goto condexpr_end_2;
        condexpr_false_2:;
        tmp_metaclass_value_2 = (PyObject *)&PyType_Type;
        Py_INCREF(tmp_metaclass_value_2);
        condexpr_end_2:;
        CHECK_OBJECT(tmp_class_creation_2__bases);
        tmp_bases_value_2 = tmp_class_creation_2__bases;
        tmp_assign_source_28 = SELECT_METACLASS(tstate, tmp_metaclass_value_2, tmp_bases_value_2);
        Py_DECREF(tmp_metaclass_value_2);
        if (tmp_assign_source_28 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        assert(tmp_class_creation_2__metaclass == NULL);
        tmp_class_creation_2__metaclass = tmp_assign_source_28;
    }
    {
        bool tmp_condition_result_6;
        PyObject *tmp_expression_value_8;
        CHECK_OBJECT(tmp_class_creation_2__metaclass);
        tmp_expression_value_8 = tmp_class_creation_2__metaclass;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_8, mod_consts[21]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        tmp_condition_result_6 = (tmp_res != 0) ? true : false;
        if (tmp_condition_result_6 != false) {
            goto branch_yes_4;
        } else {
            goto branch_no_4;
        }
    }
    branch_yes_4:;
    {
        PyObject *tmp_assign_source_29;
        PyObject *tmp_called_value_4;
        PyObject *tmp_expression_value_9;
        PyObject *tmp_args_value_3;
        PyObject *tmp_tuple_element_6;
        PyObject *tmp_kwargs_value_3;
        CHECK_OBJECT(tmp_class_creation_2__metaclass);
        tmp_expression_value_9 = tmp_class_creation_2__metaclass;
        tmp_called_value_4 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_9, mod_consts[21]);
        if (tmp_called_value_4 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        tmp_tuple_element_6 = mod_consts[33];
        tmp_args_value_3 = MAKE_TUPLE_EMPTY(2);
        PyTuple_SET_ITEM0(tmp_args_value_3, 0, tmp_tuple_element_6);
        CHECK_OBJECT(tmp_class_creation_2__bases);
        tmp_tuple_element_6 = tmp_class_creation_2__bases;
        PyTuple_SET_ITEM0(tmp_args_value_3, 1, tmp_tuple_element_6);
        CHECK_OBJECT(tmp_class_creation_2__class_decl_dict);
        tmp_kwargs_value_3 = tmp_class_creation_2__class_decl_dict;
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 49;
        tmp_assign_source_29 = CALL_FUNCTION(tstate, tmp_called_value_4, tmp_args_value_3, tmp_kwargs_value_3);
        Py_DECREF(tmp_called_value_4);
        Py_DECREF(tmp_args_value_3);
        if (tmp_assign_source_29 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        assert(tmp_class_creation_2__prepared == NULL);
        tmp_class_creation_2__prepared = tmp_assign_source_29;
    }
    {
        bool tmp_condition_result_7;
        PyObject *tmp_operand_value_2;
        PyObject *tmp_expression_value_10;
        CHECK_OBJECT(tmp_class_creation_2__prepared);
        tmp_expression_value_10 = tmp_class_creation_2__prepared;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_10, mod_consts[23]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        tmp_operand_value_2 = (tmp_res != 0) ? Py_True : Py_False;
        tmp_res = CHECK_IF_TRUE(tmp_operand_value_2);
        assert(!(tmp_res == -1));
        tmp_condition_result_7 = (tmp_res == 0) ? true : false;
        if (tmp_condition_result_7 != false) {
            goto branch_yes_5;
        } else {
            goto branch_no_5;
        }
    }
    branch_yes_5:;
    {
        PyObject *tmp_raise_type_2;
        PyObject *tmp_raise_value_2;
        PyObject *tmp_mod_expr_left_2;
        PyObject *tmp_mod_expr_right_2;
        PyObject *tmp_tuple_element_7;
        PyObject *tmp_expression_value_11;
        PyObject *tmp_name_value_3;
        PyObject *tmp_default_value_2;
        tmp_raise_type_2 = PyExc_TypeError;
        tmp_mod_expr_left_2 = mod_consts[24];
        CHECK_OBJECT(tmp_class_creation_2__metaclass);
        tmp_expression_value_11 = tmp_class_creation_2__metaclass;
        tmp_name_value_3 = mod_consts[25];
        tmp_default_value_2 = mod_consts[26];
        tmp_tuple_element_7 = BUILTIN_GETATTR(tstate, tmp_expression_value_11, tmp_name_value_3, tmp_default_value_2);
        if (tmp_tuple_element_7 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        tmp_mod_expr_right_2 = MAKE_TUPLE_EMPTY(2);
        {
            PyObject *tmp_expression_value_12;
            PyObject *tmp_type_arg_4;
            PyTuple_SET_ITEM(tmp_mod_expr_right_2, 0, tmp_tuple_element_7);
            CHECK_OBJECT(tmp_class_creation_2__prepared);
            tmp_type_arg_4 = tmp_class_creation_2__prepared;
            tmp_expression_value_12 = BUILTIN_TYPE1(tmp_type_arg_4);
            assert(!(tmp_expression_value_12 == NULL));
            tmp_tuple_element_7 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_12, mod_consts[25]);
            Py_DECREF(tmp_expression_value_12);
            if (tmp_tuple_element_7 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 49;

                goto tuple_build_exception_2;
            }
            PyTuple_SET_ITEM(tmp_mod_expr_right_2, 1, tmp_tuple_element_7);
        }
        goto tuple_build_noexception_2;
        // Exception handling pass through code for tuple_build:
        tuple_build_exception_2:;
        Py_DECREF(tmp_mod_expr_right_2);
        goto try_except_handler_6;
        // Finished with no exception for tuple_build:
        tuple_build_noexception_2:;
        tmp_raise_value_2 = BINARY_OPERATION_MOD_OBJECT_UNICODE_TUPLE(tmp_mod_expr_left_2, tmp_mod_expr_right_2);
        Py_DECREF(tmp_mod_expr_right_2);
        if (tmp_raise_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_6;
        }
        exception_type = tmp_raise_type_2;
        Py_INCREF(tmp_raise_type_2);
        exception_value = tmp_raise_value_2;
        exception_lineno = 49;
        RAISE_EXCEPTION_IMPLICIT(tstate, &exception_type, &exception_value, &exception_tb);

        goto try_except_handler_6;
    }
    branch_no_5:;
    goto branch_end_4;
    branch_no_4:;
    {
        PyObject *tmp_assign_source_30;
        tmp_assign_source_30 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_2__prepared == NULL);
        tmp_class_creation_2__prepared = tmp_assign_source_30;
    }
    branch_end_4:;
    {
        PyObject *tmp_assign_source_31;
        {
            PyObject *tmp_set_locals_2;
            CHECK_OBJECT(tmp_class_creation_2__prepared);
            tmp_set_locals_2 = tmp_class_creation_2__prepared;
            locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49 = tmp_set_locals_2;
            Py_INCREF(tmp_set_locals_2);
        }
        // Tried code:
        // Tried code:
        tmp_dictset_value = mod_consts[27];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49, mod_consts[28], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_8;
        }
        tmp_dictset_value = mod_consts[34];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49, mod_consts[1], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_8;
        }
        tmp_dictset_value = mod_consts[33];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49, mod_consts[30], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_8;
        }
        {
            nuitka_bool tmp_condition_result_8;
            PyObject *tmp_cmp_expr_left_2;
            PyObject *tmp_cmp_expr_right_2;
            CHECK_OBJECT(tmp_class_creation_2__bases);
            tmp_cmp_expr_left_2 = tmp_class_creation_2__bases;
            CHECK_OBJECT(tmp_class_creation_2__bases_orig);
            tmp_cmp_expr_right_2 = tmp_class_creation_2__bases_orig;
            tmp_condition_result_8 = RICH_COMPARE_NE_NBOOL_OBJECT_TUPLE(tmp_cmp_expr_left_2, tmp_cmp_expr_right_2);
            if (tmp_condition_result_8 == NUITKA_BOOL_EXCEPTION) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 49;

                goto try_except_handler_8;
            }
            if (tmp_condition_result_8 == NUITKA_BOOL_TRUE) {
                goto branch_yes_6;
            } else {
                goto branch_no_6;
            }
        }
        branch_yes_6:;
        CHECK_OBJECT(tmp_class_creation_2__bases_orig);
        tmp_dictset_value = tmp_class_creation_2__bases_orig;
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49, mod_consts[31], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 49;

            goto try_except_handler_8;
        }
        branch_no_6:;
        {
            PyObject *tmp_assign_source_32;
            PyObject *tmp_called_value_5;
            PyObject *tmp_args_value_4;
            PyObject *tmp_tuple_element_8;
            PyObject *tmp_kwargs_value_4;
            CHECK_OBJECT(tmp_class_creation_2__metaclass);
            tmp_called_value_5 = tmp_class_creation_2__metaclass;
            tmp_tuple_element_8 = mod_consts[33];
            tmp_args_value_4 = MAKE_TUPLE_EMPTY(3);
            PyTuple_SET_ITEM0(tmp_args_value_4, 0, tmp_tuple_element_8);
            CHECK_OBJECT(tmp_class_creation_2__bases);
            tmp_tuple_element_8 = tmp_class_creation_2__bases;
            PyTuple_SET_ITEM0(tmp_args_value_4, 1, tmp_tuple_element_8);
            tmp_tuple_element_8 = locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49;
            PyTuple_SET_ITEM0(tmp_args_value_4, 2, tmp_tuple_element_8);
            CHECK_OBJECT(tmp_class_creation_2__class_decl_dict);
            tmp_kwargs_value_4 = tmp_class_creation_2__class_decl_dict;
            frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 49;
            tmp_assign_source_32 = CALL_FUNCTION(tstate, tmp_called_value_5, tmp_args_value_4, tmp_kwargs_value_4);
            Py_DECREF(tmp_args_value_4);
            if (tmp_assign_source_32 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 49;

                goto try_except_handler_8;
            }
            assert(outline_1_var___class__ == NULL);
            outline_1_var___class__ = tmp_assign_source_32;
        }
        CHECK_OBJECT(outline_1_var___class__);
        tmp_assign_source_31 = outline_1_var___class__;
        Py_INCREF(tmp_assign_source_31);
        goto try_return_handler_8;
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_8:;
        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49);
        locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49 = NULL;
        goto try_return_handler_7;
        // Exception handler code:
        try_except_handler_8:;
        exception_keeper_type_6 = exception_type;
        exception_keeper_value_6 = exception_value;
        exception_keeper_tb_6 = exception_tb;
        exception_keeper_lineno_6 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49);
        locals_pyudev$_ctypeslib$libudev$$$class__2_udev_enumerate_49 = NULL;
        // Re-raise.
        exception_type = exception_keeper_type_6;
        exception_value = exception_keeper_value_6;
        exception_tb = exception_keeper_tb_6;
        exception_lineno = exception_keeper_lineno_6;

        goto try_except_handler_7;
        // End of try:
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_7:;
        CHECK_OBJECT(outline_1_var___class__);
        Py_DECREF(outline_1_var___class__);
        outline_1_var___class__ = NULL;
        goto outline_result_2;
        // Exception handler code:
        try_except_handler_7:;
        exception_keeper_type_7 = exception_type;
        exception_keeper_value_7 = exception_value;
        exception_keeper_tb_7 = exception_tb;
        exception_keeper_lineno_7 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        // Re-raise.
        exception_type = exception_keeper_type_7;
        exception_value = exception_keeper_value_7;
        exception_tb = exception_keeper_tb_7;
        exception_lineno = exception_keeper_lineno_7;

        goto outline_exception_2;
        // End of try:
        NUITKA_CANNOT_GET_HERE("Return statement must have exited already.");
        return NULL;
        outline_exception_2:;
        exception_lineno = 49;
        goto try_except_handler_6;
        outline_result_2:;
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[33], tmp_assign_source_31);
    }
    goto try_end_4;
    // Exception handler code:
    try_except_handler_6:;
    exception_keeper_type_8 = exception_type;
    exception_keeper_value_8 = exception_value;
    exception_keeper_tb_8 = exception_tb;
    exception_keeper_lineno_8 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    Py_XDECREF(tmp_class_creation_2__bases_orig);
    tmp_class_creation_2__bases_orig = NULL;
    Py_XDECREF(tmp_class_creation_2__bases);
    tmp_class_creation_2__bases = NULL;
    Py_XDECREF(tmp_class_creation_2__class_decl_dict);
    tmp_class_creation_2__class_decl_dict = NULL;
    Py_XDECREF(tmp_class_creation_2__metaclass);
    tmp_class_creation_2__metaclass = NULL;
    Py_XDECREF(tmp_class_creation_2__prepared);
    tmp_class_creation_2__prepared = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_8;
    exception_value = exception_keeper_value_8;
    exception_tb = exception_keeper_tb_8;
    exception_lineno = exception_keeper_lineno_8;

    goto frame_exception_exit_1;
    // End of try:
    try_end_4:;
    CHECK_OBJECT(tmp_class_creation_2__bases_orig);
    Py_DECREF(tmp_class_creation_2__bases_orig);
    tmp_class_creation_2__bases_orig = NULL;
    CHECK_OBJECT(tmp_class_creation_2__bases);
    Py_DECREF(tmp_class_creation_2__bases);
    tmp_class_creation_2__bases = NULL;
    CHECK_OBJECT(tmp_class_creation_2__class_decl_dict);
    Py_DECREF(tmp_class_creation_2__class_decl_dict);
    tmp_class_creation_2__class_decl_dict = NULL;
    CHECK_OBJECT(tmp_class_creation_2__metaclass);
    Py_DECREF(tmp_class_creation_2__metaclass);
    tmp_class_creation_2__metaclass = NULL;
    CHECK_OBJECT(tmp_class_creation_2__prepared);
    Py_DECREF(tmp_class_creation_2__prepared);
    tmp_class_creation_2__prepared = NULL;
    {
        PyObject *tmp_assign_source_33;
        PyObject *tmp_called_value_6;
        PyObject *tmp_args_element_value_2;
        tmp_called_value_6 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[7]);

        if (unlikely(tmp_called_value_6 == NULL)) {
            tmp_called_value_6 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[7]);
        }

        if (tmp_called_value_6 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 58;

            goto frame_exception_exit_1;
        }
        tmp_args_element_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[33]);

        if (unlikely(tmp_args_element_value_2 == NULL)) {
            tmp_args_element_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[33]);
        }

        if (tmp_args_element_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 58;

            goto frame_exception_exit_1;
        }
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 58;
        tmp_assign_source_33 = CALL_FUNCTION_WITH_SINGLE_ARG(tstate, tmp_called_value_6, tmp_args_element_value_2);
        if (tmp_assign_source_33 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 58;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35], tmp_assign_source_33);
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_34;
        PyObject *tmp_tuple_element_9;
        tmp_tuple_element_9 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[9]);

        if (unlikely(tmp_tuple_element_9 == NULL)) {
            tmp_tuple_element_9 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[9]);
        }

        if (tmp_tuple_element_9 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        tmp_assign_source_34 = MAKE_TUPLE_EMPTY(1);
        PyTuple_SET_ITEM0(tmp_assign_source_34, 0, tmp_tuple_element_9);
        assert(tmp_class_creation_3__bases_orig == NULL);
        tmp_class_creation_3__bases_orig = tmp_assign_source_34;
    }
    {
        PyObject *tmp_assign_source_35;
        PyObject *tmp_dircall_arg1_3;
        CHECK_OBJECT(tmp_class_creation_3__bases_orig);
        tmp_dircall_arg1_3 = tmp_class_creation_3__bases_orig;
        Py_INCREF(tmp_dircall_arg1_3);

        {
            PyObject *dir_call_args[] = {tmp_dircall_arg1_3};
            tmp_assign_source_35 = impl___main__$$$function__1__mro_entries_conversion(tstate, dir_call_args);
        }
        if (tmp_assign_source_35 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        assert(tmp_class_creation_3__bases == NULL);
        tmp_class_creation_3__bases = tmp_assign_source_35;
    }
    {
        PyObject *tmp_assign_source_36;
        tmp_assign_source_36 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_3__class_decl_dict == NULL);
        tmp_class_creation_3__class_decl_dict = tmp_assign_source_36;
    }
    {
        PyObject *tmp_assign_source_37;
        PyObject *tmp_metaclass_value_3;
        nuitka_bool tmp_condition_result_9;
        int tmp_truth_name_3;
        PyObject *tmp_type_arg_5;
        PyObject *tmp_expression_value_13;
        PyObject *tmp_subscript_value_3;
        PyObject *tmp_bases_value_3;
        CHECK_OBJECT(tmp_class_creation_3__bases);
        tmp_truth_name_3 = CHECK_IF_TRUE(tmp_class_creation_3__bases);
        if (tmp_truth_name_3 == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        tmp_condition_result_9 = tmp_truth_name_3 == 0 ? NUITKA_BOOL_FALSE : NUITKA_BOOL_TRUE;
        if (tmp_condition_result_9 == NUITKA_BOOL_TRUE) {
            goto condexpr_true_3;
        } else {
            goto condexpr_false_3;
        }
        condexpr_true_3:;
        CHECK_OBJECT(tmp_class_creation_3__bases);
        tmp_expression_value_13 = tmp_class_creation_3__bases;
        tmp_subscript_value_3 = mod_consts[8];
        tmp_type_arg_5 = LOOKUP_SUBSCRIPT_CONST(tstate, tmp_expression_value_13, tmp_subscript_value_3, 0);
        if (tmp_type_arg_5 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        tmp_metaclass_value_3 = BUILTIN_TYPE1(tmp_type_arg_5);
        Py_DECREF(tmp_type_arg_5);
        if (tmp_metaclass_value_3 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        goto condexpr_end_3;
        condexpr_false_3:;
        tmp_metaclass_value_3 = (PyObject *)&PyType_Type;
        Py_INCREF(tmp_metaclass_value_3);
        condexpr_end_3:;
        CHECK_OBJECT(tmp_class_creation_3__bases);
        tmp_bases_value_3 = tmp_class_creation_3__bases;
        tmp_assign_source_37 = SELECT_METACLASS(tstate, tmp_metaclass_value_3, tmp_bases_value_3);
        Py_DECREF(tmp_metaclass_value_3);
        if (tmp_assign_source_37 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        assert(tmp_class_creation_3__metaclass == NULL);
        tmp_class_creation_3__metaclass = tmp_assign_source_37;
    }
    {
        bool tmp_condition_result_10;
        PyObject *tmp_expression_value_14;
        CHECK_OBJECT(tmp_class_creation_3__metaclass);
        tmp_expression_value_14 = tmp_class_creation_3__metaclass;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_14, mod_consts[21]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        tmp_condition_result_10 = (tmp_res != 0) ? true : false;
        if (tmp_condition_result_10 != false) {
            goto branch_yes_7;
        } else {
            goto branch_no_7;
        }
    }
    branch_yes_7:;
    {
        PyObject *tmp_assign_source_38;
        PyObject *tmp_called_value_7;
        PyObject *tmp_expression_value_15;
        PyObject *tmp_args_value_5;
        PyObject *tmp_tuple_element_10;
        PyObject *tmp_kwargs_value_5;
        CHECK_OBJECT(tmp_class_creation_3__metaclass);
        tmp_expression_value_15 = tmp_class_creation_3__metaclass;
        tmp_called_value_7 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_15, mod_consts[21]);
        if (tmp_called_value_7 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        tmp_tuple_element_10 = mod_consts[36];
        tmp_args_value_5 = MAKE_TUPLE_EMPTY(2);
        PyTuple_SET_ITEM0(tmp_args_value_5, 0, tmp_tuple_element_10);
        CHECK_OBJECT(tmp_class_creation_3__bases);
        tmp_tuple_element_10 = tmp_class_creation_3__bases;
        PyTuple_SET_ITEM0(tmp_args_value_5, 1, tmp_tuple_element_10);
        CHECK_OBJECT(tmp_class_creation_3__class_decl_dict);
        tmp_kwargs_value_5 = tmp_class_creation_3__class_decl_dict;
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 61;
        tmp_assign_source_38 = CALL_FUNCTION(tstate, tmp_called_value_7, tmp_args_value_5, tmp_kwargs_value_5);
        Py_DECREF(tmp_called_value_7);
        Py_DECREF(tmp_args_value_5);
        if (tmp_assign_source_38 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        assert(tmp_class_creation_3__prepared == NULL);
        tmp_class_creation_3__prepared = tmp_assign_source_38;
    }
    {
        bool tmp_condition_result_11;
        PyObject *tmp_operand_value_3;
        PyObject *tmp_expression_value_16;
        CHECK_OBJECT(tmp_class_creation_3__prepared);
        tmp_expression_value_16 = tmp_class_creation_3__prepared;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_16, mod_consts[23]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        tmp_operand_value_3 = (tmp_res != 0) ? Py_True : Py_False;
        tmp_res = CHECK_IF_TRUE(tmp_operand_value_3);
        assert(!(tmp_res == -1));
        tmp_condition_result_11 = (tmp_res == 0) ? true : false;
        if (tmp_condition_result_11 != false) {
            goto branch_yes_8;
        } else {
            goto branch_no_8;
        }
    }
    branch_yes_8:;
    {
        PyObject *tmp_raise_type_3;
        PyObject *tmp_raise_value_3;
        PyObject *tmp_mod_expr_left_3;
        PyObject *tmp_mod_expr_right_3;
        PyObject *tmp_tuple_element_11;
        PyObject *tmp_expression_value_17;
        PyObject *tmp_name_value_4;
        PyObject *tmp_default_value_3;
        tmp_raise_type_3 = PyExc_TypeError;
        tmp_mod_expr_left_3 = mod_consts[24];
        CHECK_OBJECT(tmp_class_creation_3__metaclass);
        tmp_expression_value_17 = tmp_class_creation_3__metaclass;
        tmp_name_value_4 = mod_consts[25];
        tmp_default_value_3 = mod_consts[26];
        tmp_tuple_element_11 = BUILTIN_GETATTR(tstate, tmp_expression_value_17, tmp_name_value_4, tmp_default_value_3);
        if (tmp_tuple_element_11 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        tmp_mod_expr_right_3 = MAKE_TUPLE_EMPTY(2);
        {
            PyObject *tmp_expression_value_18;
            PyObject *tmp_type_arg_6;
            PyTuple_SET_ITEM(tmp_mod_expr_right_3, 0, tmp_tuple_element_11);
            CHECK_OBJECT(tmp_class_creation_3__prepared);
            tmp_type_arg_6 = tmp_class_creation_3__prepared;
            tmp_expression_value_18 = BUILTIN_TYPE1(tmp_type_arg_6);
            assert(!(tmp_expression_value_18 == NULL));
            tmp_tuple_element_11 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_18, mod_consts[25]);
            Py_DECREF(tmp_expression_value_18);
            if (tmp_tuple_element_11 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 61;

                goto tuple_build_exception_3;
            }
            PyTuple_SET_ITEM(tmp_mod_expr_right_3, 1, tmp_tuple_element_11);
        }
        goto tuple_build_noexception_3;
        // Exception handling pass through code for tuple_build:
        tuple_build_exception_3:;
        Py_DECREF(tmp_mod_expr_right_3);
        goto try_except_handler_9;
        // Finished with no exception for tuple_build:
        tuple_build_noexception_3:;
        tmp_raise_value_3 = BINARY_OPERATION_MOD_OBJECT_UNICODE_TUPLE(tmp_mod_expr_left_3, tmp_mod_expr_right_3);
        Py_DECREF(tmp_mod_expr_right_3);
        if (tmp_raise_value_3 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_9;
        }
        exception_type = tmp_raise_type_3;
        Py_INCREF(tmp_raise_type_3);
        exception_value = tmp_raise_value_3;
        exception_lineno = 61;
        RAISE_EXCEPTION_IMPLICIT(tstate, &exception_type, &exception_value, &exception_tb);

        goto try_except_handler_9;
    }
    branch_no_8:;
    goto branch_end_7;
    branch_no_7:;
    {
        PyObject *tmp_assign_source_39;
        tmp_assign_source_39 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_3__prepared == NULL);
        tmp_class_creation_3__prepared = tmp_assign_source_39;
    }
    branch_end_7:;
    {
        PyObject *tmp_assign_source_40;
        {
            PyObject *tmp_set_locals_3;
            CHECK_OBJECT(tmp_class_creation_3__prepared);
            tmp_set_locals_3 = tmp_class_creation_3__prepared;
            locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61 = tmp_set_locals_3;
            Py_INCREF(tmp_set_locals_3);
        }
        // Tried code:
        // Tried code:
        tmp_dictset_value = mod_consts[27];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61, mod_consts[28], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_11;
        }
        tmp_dictset_value = mod_consts[37];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61, mod_consts[1], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_11;
        }
        tmp_dictset_value = mod_consts[36];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61, mod_consts[30], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_11;
        }
        {
            nuitka_bool tmp_condition_result_12;
            PyObject *tmp_cmp_expr_left_3;
            PyObject *tmp_cmp_expr_right_3;
            CHECK_OBJECT(tmp_class_creation_3__bases);
            tmp_cmp_expr_left_3 = tmp_class_creation_3__bases;
            CHECK_OBJECT(tmp_class_creation_3__bases_orig);
            tmp_cmp_expr_right_3 = tmp_class_creation_3__bases_orig;
            tmp_condition_result_12 = RICH_COMPARE_NE_NBOOL_OBJECT_TUPLE(tmp_cmp_expr_left_3, tmp_cmp_expr_right_3);
            if (tmp_condition_result_12 == NUITKA_BOOL_EXCEPTION) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 61;

                goto try_except_handler_11;
            }
            if (tmp_condition_result_12 == NUITKA_BOOL_TRUE) {
                goto branch_yes_9;
            } else {
                goto branch_no_9;
            }
        }
        branch_yes_9:;
        CHECK_OBJECT(tmp_class_creation_3__bases_orig);
        tmp_dictset_value = tmp_class_creation_3__bases_orig;
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61, mod_consts[31], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto try_except_handler_11;
        }
        branch_no_9:;
        {
            PyObject *tmp_assign_source_41;
            PyObject *tmp_called_value_8;
            PyObject *tmp_args_value_6;
            PyObject *tmp_tuple_element_12;
            PyObject *tmp_kwargs_value_6;
            CHECK_OBJECT(tmp_class_creation_3__metaclass);
            tmp_called_value_8 = tmp_class_creation_3__metaclass;
            tmp_tuple_element_12 = mod_consts[36];
            tmp_args_value_6 = MAKE_TUPLE_EMPTY(3);
            PyTuple_SET_ITEM0(tmp_args_value_6, 0, tmp_tuple_element_12);
            CHECK_OBJECT(tmp_class_creation_3__bases);
            tmp_tuple_element_12 = tmp_class_creation_3__bases;
            PyTuple_SET_ITEM0(tmp_args_value_6, 1, tmp_tuple_element_12);
            tmp_tuple_element_12 = locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61;
            PyTuple_SET_ITEM0(tmp_args_value_6, 2, tmp_tuple_element_12);
            CHECK_OBJECT(tmp_class_creation_3__class_decl_dict);
            tmp_kwargs_value_6 = tmp_class_creation_3__class_decl_dict;
            frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 61;
            tmp_assign_source_41 = CALL_FUNCTION(tstate, tmp_called_value_8, tmp_args_value_6, tmp_kwargs_value_6);
            Py_DECREF(tmp_args_value_6);
            if (tmp_assign_source_41 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 61;

                goto try_except_handler_11;
            }
            assert(outline_2_var___class__ == NULL);
            outline_2_var___class__ = tmp_assign_source_41;
        }
        CHECK_OBJECT(outline_2_var___class__);
        tmp_assign_source_40 = outline_2_var___class__;
        Py_INCREF(tmp_assign_source_40);
        goto try_return_handler_11;
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_11:;
        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61);
        locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61 = NULL;
        goto try_return_handler_10;
        // Exception handler code:
        try_except_handler_11:;
        exception_keeper_type_9 = exception_type;
        exception_keeper_value_9 = exception_value;
        exception_keeper_tb_9 = exception_tb;
        exception_keeper_lineno_9 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61);
        locals_pyudev$_ctypeslib$libudev$$$class__3_udev_list_entry_61 = NULL;
        // Re-raise.
        exception_type = exception_keeper_type_9;
        exception_value = exception_keeper_value_9;
        exception_tb = exception_keeper_tb_9;
        exception_lineno = exception_keeper_lineno_9;

        goto try_except_handler_10;
        // End of try:
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_10:;
        CHECK_OBJECT(outline_2_var___class__);
        Py_DECREF(outline_2_var___class__);
        outline_2_var___class__ = NULL;
        goto outline_result_3;
        // Exception handler code:
        try_except_handler_10:;
        exception_keeper_type_10 = exception_type;
        exception_keeper_value_10 = exception_value;
        exception_keeper_tb_10 = exception_tb;
        exception_keeper_lineno_10 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        // Re-raise.
        exception_type = exception_keeper_type_10;
        exception_value = exception_keeper_value_10;
        exception_tb = exception_keeper_tb_10;
        exception_lineno = exception_keeper_lineno_10;

        goto outline_exception_3;
        // End of try:
        NUITKA_CANNOT_GET_HERE("Return statement must have exited already.");
        return NULL;
        outline_exception_3:;
        exception_lineno = 61;
        goto try_except_handler_9;
        outline_result_3:;
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[36], tmp_assign_source_40);
    }
    goto try_end_5;
    // Exception handler code:
    try_except_handler_9:;
    exception_keeper_type_11 = exception_type;
    exception_keeper_value_11 = exception_value;
    exception_keeper_tb_11 = exception_tb;
    exception_keeper_lineno_11 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    Py_XDECREF(tmp_class_creation_3__bases_orig);
    tmp_class_creation_3__bases_orig = NULL;
    Py_XDECREF(tmp_class_creation_3__bases);
    tmp_class_creation_3__bases = NULL;
    Py_XDECREF(tmp_class_creation_3__class_decl_dict);
    tmp_class_creation_3__class_decl_dict = NULL;
    Py_XDECREF(tmp_class_creation_3__metaclass);
    tmp_class_creation_3__metaclass = NULL;
    Py_XDECREF(tmp_class_creation_3__prepared);
    tmp_class_creation_3__prepared = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_11;
    exception_value = exception_keeper_value_11;
    exception_tb = exception_keeper_tb_11;
    exception_lineno = exception_keeper_lineno_11;

    goto frame_exception_exit_1;
    // End of try:
    try_end_5:;
    CHECK_OBJECT(tmp_class_creation_3__bases_orig);
    Py_DECREF(tmp_class_creation_3__bases_orig);
    tmp_class_creation_3__bases_orig = NULL;
    CHECK_OBJECT(tmp_class_creation_3__bases);
    Py_DECREF(tmp_class_creation_3__bases);
    tmp_class_creation_3__bases = NULL;
    CHECK_OBJECT(tmp_class_creation_3__class_decl_dict);
    Py_DECREF(tmp_class_creation_3__class_decl_dict);
    tmp_class_creation_3__class_decl_dict = NULL;
    CHECK_OBJECT(tmp_class_creation_3__metaclass);
    Py_DECREF(tmp_class_creation_3__metaclass);
    tmp_class_creation_3__metaclass = NULL;
    CHECK_OBJECT(tmp_class_creation_3__prepared);
    Py_DECREF(tmp_class_creation_3__prepared);
    tmp_class_creation_3__prepared = NULL;
    {
        PyObject *tmp_assign_source_42;
        PyObject *tmp_called_value_9;
        PyObject *tmp_args_element_value_3;
        tmp_called_value_9 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[7]);

        if (unlikely(tmp_called_value_9 == NULL)) {
            tmp_called_value_9 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[7]);
        }

        if (tmp_called_value_9 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 70;

            goto frame_exception_exit_1;
        }
        tmp_args_element_value_3 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[36]);

        if (unlikely(tmp_args_element_value_3 == NULL)) {
            tmp_args_element_value_3 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[36]);
        }

        if (tmp_args_element_value_3 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 70;

            goto frame_exception_exit_1;
        }
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 70;
        tmp_assign_source_42 = CALL_FUNCTION_WITH_SINGLE_ARG(tstate, tmp_called_value_9, tmp_args_element_value_3);
        if (tmp_assign_source_42 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 70;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38], tmp_assign_source_42);
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_43;
        PyObject *tmp_tuple_element_13;
        tmp_tuple_element_13 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[9]);

        if (unlikely(tmp_tuple_element_13 == NULL)) {
            tmp_tuple_element_13 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[9]);
        }

        if (tmp_tuple_element_13 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        tmp_assign_source_43 = MAKE_TUPLE_EMPTY(1);
        PyTuple_SET_ITEM0(tmp_assign_source_43, 0, tmp_tuple_element_13);
        assert(tmp_class_creation_4__bases_orig == NULL);
        tmp_class_creation_4__bases_orig = tmp_assign_source_43;
    }
    {
        PyObject *tmp_assign_source_44;
        PyObject *tmp_dircall_arg1_4;
        CHECK_OBJECT(tmp_class_creation_4__bases_orig);
        tmp_dircall_arg1_4 = tmp_class_creation_4__bases_orig;
        Py_INCREF(tmp_dircall_arg1_4);

        {
            PyObject *dir_call_args[] = {tmp_dircall_arg1_4};
            tmp_assign_source_44 = impl___main__$$$function__1__mro_entries_conversion(tstate, dir_call_args);
        }
        if (tmp_assign_source_44 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        assert(tmp_class_creation_4__bases == NULL);
        tmp_class_creation_4__bases = tmp_assign_source_44;
    }
    {
        PyObject *tmp_assign_source_45;
        tmp_assign_source_45 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_4__class_decl_dict == NULL);
        tmp_class_creation_4__class_decl_dict = tmp_assign_source_45;
    }
    {
        PyObject *tmp_assign_source_46;
        PyObject *tmp_metaclass_value_4;
        nuitka_bool tmp_condition_result_13;
        int tmp_truth_name_4;
        PyObject *tmp_type_arg_7;
        PyObject *tmp_expression_value_19;
        PyObject *tmp_subscript_value_4;
        PyObject *tmp_bases_value_4;
        CHECK_OBJECT(tmp_class_creation_4__bases);
        tmp_truth_name_4 = CHECK_IF_TRUE(tmp_class_creation_4__bases);
        if (tmp_truth_name_4 == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        tmp_condition_result_13 = tmp_truth_name_4 == 0 ? NUITKA_BOOL_FALSE : NUITKA_BOOL_TRUE;
        if (tmp_condition_result_13 == NUITKA_BOOL_TRUE) {
            goto condexpr_true_4;
        } else {
            goto condexpr_false_4;
        }
        condexpr_true_4:;
        CHECK_OBJECT(tmp_class_creation_4__bases);
        tmp_expression_value_19 = tmp_class_creation_4__bases;
        tmp_subscript_value_4 = mod_consts[8];
        tmp_type_arg_7 = LOOKUP_SUBSCRIPT_CONST(tstate, tmp_expression_value_19, tmp_subscript_value_4, 0);
        if (tmp_type_arg_7 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        tmp_metaclass_value_4 = BUILTIN_TYPE1(tmp_type_arg_7);
        Py_DECREF(tmp_type_arg_7);
        if (tmp_metaclass_value_4 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        goto condexpr_end_4;
        condexpr_false_4:;
        tmp_metaclass_value_4 = (PyObject *)&PyType_Type;
        Py_INCREF(tmp_metaclass_value_4);
        condexpr_end_4:;
        CHECK_OBJECT(tmp_class_creation_4__bases);
        tmp_bases_value_4 = tmp_class_creation_4__bases;
        tmp_assign_source_46 = SELECT_METACLASS(tstate, tmp_metaclass_value_4, tmp_bases_value_4);
        Py_DECREF(tmp_metaclass_value_4);
        if (tmp_assign_source_46 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        assert(tmp_class_creation_4__metaclass == NULL);
        tmp_class_creation_4__metaclass = tmp_assign_source_46;
    }
    {
        bool tmp_condition_result_14;
        PyObject *tmp_expression_value_20;
        CHECK_OBJECT(tmp_class_creation_4__metaclass);
        tmp_expression_value_20 = tmp_class_creation_4__metaclass;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_20, mod_consts[21]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        tmp_condition_result_14 = (tmp_res != 0) ? true : false;
        if (tmp_condition_result_14 != false) {
            goto branch_yes_10;
        } else {
            goto branch_no_10;
        }
    }
    branch_yes_10:;
    {
        PyObject *tmp_assign_source_47;
        PyObject *tmp_called_value_10;
        PyObject *tmp_expression_value_21;
        PyObject *tmp_args_value_7;
        PyObject *tmp_tuple_element_14;
        PyObject *tmp_kwargs_value_7;
        CHECK_OBJECT(tmp_class_creation_4__metaclass);
        tmp_expression_value_21 = tmp_class_creation_4__metaclass;
        tmp_called_value_10 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_21, mod_consts[21]);
        if (tmp_called_value_10 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        tmp_tuple_element_14 = mod_consts[39];
        tmp_args_value_7 = MAKE_TUPLE_EMPTY(2);
        PyTuple_SET_ITEM0(tmp_args_value_7, 0, tmp_tuple_element_14);
        CHECK_OBJECT(tmp_class_creation_4__bases);
        tmp_tuple_element_14 = tmp_class_creation_4__bases;
        PyTuple_SET_ITEM0(tmp_args_value_7, 1, tmp_tuple_element_14);
        CHECK_OBJECT(tmp_class_creation_4__class_decl_dict);
        tmp_kwargs_value_7 = tmp_class_creation_4__class_decl_dict;
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 73;
        tmp_assign_source_47 = CALL_FUNCTION(tstate, tmp_called_value_10, tmp_args_value_7, tmp_kwargs_value_7);
        Py_DECREF(tmp_called_value_10);
        Py_DECREF(tmp_args_value_7);
        if (tmp_assign_source_47 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        assert(tmp_class_creation_4__prepared == NULL);
        tmp_class_creation_4__prepared = tmp_assign_source_47;
    }
    {
        bool tmp_condition_result_15;
        PyObject *tmp_operand_value_4;
        PyObject *tmp_expression_value_22;
        CHECK_OBJECT(tmp_class_creation_4__prepared);
        tmp_expression_value_22 = tmp_class_creation_4__prepared;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_22, mod_consts[23]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        tmp_operand_value_4 = (tmp_res != 0) ? Py_True : Py_False;
        tmp_res = CHECK_IF_TRUE(tmp_operand_value_4);
        assert(!(tmp_res == -1));
        tmp_condition_result_15 = (tmp_res == 0) ? true : false;
        if (tmp_condition_result_15 != false) {
            goto branch_yes_11;
        } else {
            goto branch_no_11;
        }
    }
    branch_yes_11:;
    {
        PyObject *tmp_raise_type_4;
        PyObject *tmp_raise_value_4;
        PyObject *tmp_mod_expr_left_4;
        PyObject *tmp_mod_expr_right_4;
        PyObject *tmp_tuple_element_15;
        PyObject *tmp_expression_value_23;
        PyObject *tmp_name_value_5;
        PyObject *tmp_default_value_4;
        tmp_raise_type_4 = PyExc_TypeError;
        tmp_mod_expr_left_4 = mod_consts[24];
        CHECK_OBJECT(tmp_class_creation_4__metaclass);
        tmp_expression_value_23 = tmp_class_creation_4__metaclass;
        tmp_name_value_5 = mod_consts[25];
        tmp_default_value_4 = mod_consts[26];
        tmp_tuple_element_15 = BUILTIN_GETATTR(tstate, tmp_expression_value_23, tmp_name_value_5, tmp_default_value_4);
        if (tmp_tuple_element_15 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        tmp_mod_expr_right_4 = MAKE_TUPLE_EMPTY(2);
        {
            PyObject *tmp_expression_value_24;
            PyObject *tmp_type_arg_8;
            PyTuple_SET_ITEM(tmp_mod_expr_right_4, 0, tmp_tuple_element_15);
            CHECK_OBJECT(tmp_class_creation_4__prepared);
            tmp_type_arg_8 = tmp_class_creation_4__prepared;
            tmp_expression_value_24 = BUILTIN_TYPE1(tmp_type_arg_8);
            assert(!(tmp_expression_value_24 == NULL));
            tmp_tuple_element_15 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_24, mod_consts[25]);
            Py_DECREF(tmp_expression_value_24);
            if (tmp_tuple_element_15 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 73;

                goto tuple_build_exception_4;
            }
            PyTuple_SET_ITEM(tmp_mod_expr_right_4, 1, tmp_tuple_element_15);
        }
        goto tuple_build_noexception_4;
        // Exception handling pass through code for tuple_build:
        tuple_build_exception_4:;
        Py_DECREF(tmp_mod_expr_right_4);
        goto try_except_handler_12;
        // Finished with no exception for tuple_build:
        tuple_build_noexception_4:;
        tmp_raise_value_4 = BINARY_OPERATION_MOD_OBJECT_UNICODE_TUPLE(tmp_mod_expr_left_4, tmp_mod_expr_right_4);
        Py_DECREF(tmp_mod_expr_right_4);
        if (tmp_raise_value_4 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_12;
        }
        exception_type = tmp_raise_type_4;
        Py_INCREF(tmp_raise_type_4);
        exception_value = tmp_raise_value_4;
        exception_lineno = 73;
        RAISE_EXCEPTION_IMPLICIT(tstate, &exception_type, &exception_value, &exception_tb);

        goto try_except_handler_12;
    }
    branch_no_11:;
    goto branch_end_10;
    branch_no_10:;
    {
        PyObject *tmp_assign_source_48;
        tmp_assign_source_48 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_4__prepared == NULL);
        tmp_class_creation_4__prepared = tmp_assign_source_48;
    }
    branch_end_10:;
    {
        PyObject *tmp_assign_source_49;
        {
            PyObject *tmp_set_locals_4;
            CHECK_OBJECT(tmp_class_creation_4__prepared);
            tmp_set_locals_4 = tmp_class_creation_4__prepared;
            locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73 = tmp_set_locals_4;
            Py_INCREF(tmp_set_locals_4);
        }
        // Tried code:
        // Tried code:
        tmp_dictset_value = mod_consts[27];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73, mod_consts[28], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_14;
        }
        tmp_dictset_value = mod_consts[40];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73, mod_consts[1], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_14;
        }
        tmp_dictset_value = mod_consts[39];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73, mod_consts[30], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_14;
        }
        {
            nuitka_bool tmp_condition_result_16;
            PyObject *tmp_cmp_expr_left_4;
            PyObject *tmp_cmp_expr_right_4;
            CHECK_OBJECT(tmp_class_creation_4__bases);
            tmp_cmp_expr_left_4 = tmp_class_creation_4__bases;
            CHECK_OBJECT(tmp_class_creation_4__bases_orig);
            tmp_cmp_expr_right_4 = tmp_class_creation_4__bases_orig;
            tmp_condition_result_16 = RICH_COMPARE_NE_NBOOL_OBJECT_TUPLE(tmp_cmp_expr_left_4, tmp_cmp_expr_right_4);
            if (tmp_condition_result_16 == NUITKA_BOOL_EXCEPTION) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 73;

                goto try_except_handler_14;
            }
            if (tmp_condition_result_16 == NUITKA_BOOL_TRUE) {
                goto branch_yes_12;
            } else {
                goto branch_no_12;
            }
        }
        branch_yes_12:;
        CHECK_OBJECT(tmp_class_creation_4__bases_orig);
        tmp_dictset_value = tmp_class_creation_4__bases_orig;
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73, mod_consts[31], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto try_except_handler_14;
        }
        branch_no_12:;
        {
            PyObject *tmp_assign_source_50;
            PyObject *tmp_called_value_11;
            PyObject *tmp_args_value_8;
            PyObject *tmp_tuple_element_16;
            PyObject *tmp_kwargs_value_8;
            CHECK_OBJECT(tmp_class_creation_4__metaclass);
            tmp_called_value_11 = tmp_class_creation_4__metaclass;
            tmp_tuple_element_16 = mod_consts[39];
            tmp_args_value_8 = MAKE_TUPLE_EMPTY(3);
            PyTuple_SET_ITEM0(tmp_args_value_8, 0, tmp_tuple_element_16);
            CHECK_OBJECT(tmp_class_creation_4__bases);
            tmp_tuple_element_16 = tmp_class_creation_4__bases;
            PyTuple_SET_ITEM0(tmp_args_value_8, 1, tmp_tuple_element_16);
            tmp_tuple_element_16 = locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73;
            PyTuple_SET_ITEM0(tmp_args_value_8, 2, tmp_tuple_element_16);
            CHECK_OBJECT(tmp_class_creation_4__class_decl_dict);
            tmp_kwargs_value_8 = tmp_class_creation_4__class_decl_dict;
            frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 73;
            tmp_assign_source_50 = CALL_FUNCTION(tstate, tmp_called_value_11, tmp_args_value_8, tmp_kwargs_value_8);
            Py_DECREF(tmp_args_value_8);
            if (tmp_assign_source_50 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 73;

                goto try_except_handler_14;
            }
            assert(outline_3_var___class__ == NULL);
            outline_3_var___class__ = tmp_assign_source_50;
        }
        CHECK_OBJECT(outline_3_var___class__);
        tmp_assign_source_49 = outline_3_var___class__;
        Py_INCREF(tmp_assign_source_49);
        goto try_return_handler_14;
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_14:;
        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73);
        locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73 = NULL;
        goto try_return_handler_13;
        // Exception handler code:
        try_except_handler_14:;
        exception_keeper_type_12 = exception_type;
        exception_keeper_value_12 = exception_value;
        exception_keeper_tb_12 = exception_tb;
        exception_keeper_lineno_12 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73);
        locals_pyudev$_ctypeslib$libudev$$$class__4_udev_device_73 = NULL;
        // Re-raise.
        exception_type = exception_keeper_type_12;
        exception_value = exception_keeper_value_12;
        exception_tb = exception_keeper_tb_12;
        exception_lineno = exception_keeper_lineno_12;

        goto try_except_handler_13;
        // End of try:
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_13:;
        CHECK_OBJECT(outline_3_var___class__);
        Py_DECREF(outline_3_var___class__);
        outline_3_var___class__ = NULL;
        goto outline_result_4;
        // Exception handler code:
        try_except_handler_13:;
        exception_keeper_type_13 = exception_type;
        exception_keeper_value_13 = exception_value;
        exception_keeper_tb_13 = exception_tb;
        exception_keeper_lineno_13 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        // Re-raise.
        exception_type = exception_keeper_type_13;
        exception_value = exception_keeper_value_13;
        exception_tb = exception_keeper_tb_13;
        exception_lineno = exception_keeper_lineno_13;

        goto outline_exception_4;
        // End of try:
        NUITKA_CANNOT_GET_HERE("Return statement must have exited already.");
        return NULL;
        outline_exception_4:;
        exception_lineno = 73;
        goto try_except_handler_12;
        outline_result_4:;
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[39], tmp_assign_source_49);
    }
    goto try_end_6;
    // Exception handler code:
    try_except_handler_12:;
    exception_keeper_type_14 = exception_type;
    exception_keeper_value_14 = exception_value;
    exception_keeper_tb_14 = exception_tb;
    exception_keeper_lineno_14 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    Py_XDECREF(tmp_class_creation_4__bases_orig);
    tmp_class_creation_4__bases_orig = NULL;
    Py_XDECREF(tmp_class_creation_4__bases);
    tmp_class_creation_4__bases = NULL;
    Py_XDECREF(tmp_class_creation_4__class_decl_dict);
    tmp_class_creation_4__class_decl_dict = NULL;
    Py_XDECREF(tmp_class_creation_4__metaclass);
    tmp_class_creation_4__metaclass = NULL;
    Py_XDECREF(tmp_class_creation_4__prepared);
    tmp_class_creation_4__prepared = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_14;
    exception_value = exception_keeper_value_14;
    exception_tb = exception_keeper_tb_14;
    exception_lineno = exception_keeper_lineno_14;

    goto frame_exception_exit_1;
    // End of try:
    try_end_6:;
    CHECK_OBJECT(tmp_class_creation_4__bases_orig);
    Py_DECREF(tmp_class_creation_4__bases_orig);
    tmp_class_creation_4__bases_orig = NULL;
    CHECK_OBJECT(tmp_class_creation_4__bases);
    Py_DECREF(tmp_class_creation_4__bases);
    tmp_class_creation_4__bases = NULL;
    CHECK_OBJECT(tmp_class_creation_4__class_decl_dict);
    Py_DECREF(tmp_class_creation_4__class_decl_dict);
    tmp_class_creation_4__class_decl_dict = NULL;
    CHECK_OBJECT(tmp_class_creation_4__metaclass);
    Py_DECREF(tmp_class_creation_4__metaclass);
    tmp_class_creation_4__metaclass = NULL;
    CHECK_OBJECT(tmp_class_creation_4__prepared);
    Py_DECREF(tmp_class_creation_4__prepared);
    tmp_class_creation_4__prepared = NULL;
    {
        PyObject *tmp_assign_source_51;
        PyObject *tmp_called_value_12;
        PyObject *tmp_args_element_value_4;
        tmp_called_value_12 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[7]);

        if (unlikely(tmp_called_value_12 == NULL)) {
            tmp_called_value_12 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[7]);
        }

        if (tmp_called_value_12 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
        tmp_args_element_value_4 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[39]);

        if (unlikely(tmp_args_element_value_4 == NULL)) {
            tmp_args_element_value_4 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[39]);
        }

        if (tmp_args_element_value_4 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 82;
        tmp_assign_source_51 = CALL_FUNCTION_WITH_SINGLE_ARG(tstate, tmp_called_value_12, tmp_args_element_value_4);
        if (tmp_assign_source_51 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41], tmp_assign_source_51);
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_52;
        PyObject *tmp_tuple_element_17;
        tmp_tuple_element_17 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[9]);

        if (unlikely(tmp_tuple_element_17 == NULL)) {
            tmp_tuple_element_17 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[9]);
        }

        if (tmp_tuple_element_17 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        tmp_assign_source_52 = MAKE_TUPLE_EMPTY(1);
        PyTuple_SET_ITEM0(tmp_assign_source_52, 0, tmp_tuple_element_17);
        assert(tmp_class_creation_5__bases_orig == NULL);
        tmp_class_creation_5__bases_orig = tmp_assign_source_52;
    }
    {
        PyObject *tmp_assign_source_53;
        PyObject *tmp_dircall_arg1_5;
        CHECK_OBJECT(tmp_class_creation_5__bases_orig);
        tmp_dircall_arg1_5 = tmp_class_creation_5__bases_orig;
        Py_INCREF(tmp_dircall_arg1_5);

        {
            PyObject *dir_call_args[] = {tmp_dircall_arg1_5};
            tmp_assign_source_53 = impl___main__$$$function__1__mro_entries_conversion(tstate, dir_call_args);
        }
        if (tmp_assign_source_53 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        assert(tmp_class_creation_5__bases == NULL);
        tmp_class_creation_5__bases = tmp_assign_source_53;
    }
    {
        PyObject *tmp_assign_source_54;
        tmp_assign_source_54 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_5__class_decl_dict == NULL);
        tmp_class_creation_5__class_decl_dict = tmp_assign_source_54;
    }
    {
        PyObject *tmp_assign_source_55;
        PyObject *tmp_metaclass_value_5;
        nuitka_bool tmp_condition_result_17;
        int tmp_truth_name_5;
        PyObject *tmp_type_arg_9;
        PyObject *tmp_expression_value_25;
        PyObject *tmp_subscript_value_5;
        PyObject *tmp_bases_value_5;
        CHECK_OBJECT(tmp_class_creation_5__bases);
        tmp_truth_name_5 = CHECK_IF_TRUE(tmp_class_creation_5__bases);
        if (tmp_truth_name_5 == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        tmp_condition_result_17 = tmp_truth_name_5 == 0 ? NUITKA_BOOL_FALSE : NUITKA_BOOL_TRUE;
        if (tmp_condition_result_17 == NUITKA_BOOL_TRUE) {
            goto condexpr_true_5;
        } else {
            goto condexpr_false_5;
        }
        condexpr_true_5:;
        CHECK_OBJECT(tmp_class_creation_5__bases);
        tmp_expression_value_25 = tmp_class_creation_5__bases;
        tmp_subscript_value_5 = mod_consts[8];
        tmp_type_arg_9 = LOOKUP_SUBSCRIPT_CONST(tstate, tmp_expression_value_25, tmp_subscript_value_5, 0);
        if (tmp_type_arg_9 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        tmp_metaclass_value_5 = BUILTIN_TYPE1(tmp_type_arg_9);
        Py_DECREF(tmp_type_arg_9);
        if (tmp_metaclass_value_5 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        goto condexpr_end_5;
        condexpr_false_5:;
        tmp_metaclass_value_5 = (PyObject *)&PyType_Type;
        Py_INCREF(tmp_metaclass_value_5);
        condexpr_end_5:;
        CHECK_OBJECT(tmp_class_creation_5__bases);
        tmp_bases_value_5 = tmp_class_creation_5__bases;
        tmp_assign_source_55 = SELECT_METACLASS(tstate, tmp_metaclass_value_5, tmp_bases_value_5);
        Py_DECREF(tmp_metaclass_value_5);
        if (tmp_assign_source_55 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        assert(tmp_class_creation_5__metaclass == NULL);
        tmp_class_creation_5__metaclass = tmp_assign_source_55;
    }
    {
        bool tmp_condition_result_18;
        PyObject *tmp_expression_value_26;
        CHECK_OBJECT(tmp_class_creation_5__metaclass);
        tmp_expression_value_26 = tmp_class_creation_5__metaclass;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_26, mod_consts[21]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        tmp_condition_result_18 = (tmp_res != 0) ? true : false;
        if (tmp_condition_result_18 != false) {
            goto branch_yes_13;
        } else {
            goto branch_no_13;
        }
    }
    branch_yes_13:;
    {
        PyObject *tmp_assign_source_56;
        PyObject *tmp_called_value_13;
        PyObject *tmp_expression_value_27;
        PyObject *tmp_args_value_9;
        PyObject *tmp_tuple_element_18;
        PyObject *tmp_kwargs_value_9;
        CHECK_OBJECT(tmp_class_creation_5__metaclass);
        tmp_expression_value_27 = tmp_class_creation_5__metaclass;
        tmp_called_value_13 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_27, mod_consts[21]);
        if (tmp_called_value_13 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        tmp_tuple_element_18 = mod_consts[42];
        tmp_args_value_9 = MAKE_TUPLE_EMPTY(2);
        PyTuple_SET_ITEM0(tmp_args_value_9, 0, tmp_tuple_element_18);
        CHECK_OBJECT(tmp_class_creation_5__bases);
        tmp_tuple_element_18 = tmp_class_creation_5__bases;
        PyTuple_SET_ITEM0(tmp_args_value_9, 1, tmp_tuple_element_18);
        CHECK_OBJECT(tmp_class_creation_5__class_decl_dict);
        tmp_kwargs_value_9 = tmp_class_creation_5__class_decl_dict;
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 85;
        tmp_assign_source_56 = CALL_FUNCTION(tstate, tmp_called_value_13, tmp_args_value_9, tmp_kwargs_value_9);
        Py_DECREF(tmp_called_value_13);
        Py_DECREF(tmp_args_value_9);
        if (tmp_assign_source_56 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        assert(tmp_class_creation_5__prepared == NULL);
        tmp_class_creation_5__prepared = tmp_assign_source_56;
    }
    {
        bool tmp_condition_result_19;
        PyObject *tmp_operand_value_5;
        PyObject *tmp_expression_value_28;
        CHECK_OBJECT(tmp_class_creation_5__prepared);
        tmp_expression_value_28 = tmp_class_creation_5__prepared;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_28, mod_consts[23]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        tmp_operand_value_5 = (tmp_res != 0) ? Py_True : Py_False;
        tmp_res = CHECK_IF_TRUE(tmp_operand_value_5);
        assert(!(tmp_res == -1));
        tmp_condition_result_19 = (tmp_res == 0) ? true : false;
        if (tmp_condition_result_19 != false) {
            goto branch_yes_14;
        } else {
            goto branch_no_14;
        }
    }
    branch_yes_14:;
    {
        PyObject *tmp_raise_type_5;
        PyObject *tmp_raise_value_5;
        PyObject *tmp_mod_expr_left_5;
        PyObject *tmp_mod_expr_right_5;
        PyObject *tmp_tuple_element_19;
        PyObject *tmp_expression_value_29;
        PyObject *tmp_name_value_6;
        PyObject *tmp_default_value_5;
        tmp_raise_type_5 = PyExc_TypeError;
        tmp_mod_expr_left_5 = mod_consts[24];
        CHECK_OBJECT(tmp_class_creation_5__metaclass);
        tmp_expression_value_29 = tmp_class_creation_5__metaclass;
        tmp_name_value_6 = mod_consts[25];
        tmp_default_value_5 = mod_consts[26];
        tmp_tuple_element_19 = BUILTIN_GETATTR(tstate, tmp_expression_value_29, tmp_name_value_6, tmp_default_value_5);
        if (tmp_tuple_element_19 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        tmp_mod_expr_right_5 = MAKE_TUPLE_EMPTY(2);
        {
            PyObject *tmp_expression_value_30;
            PyObject *tmp_type_arg_10;
            PyTuple_SET_ITEM(tmp_mod_expr_right_5, 0, tmp_tuple_element_19);
            CHECK_OBJECT(tmp_class_creation_5__prepared);
            tmp_type_arg_10 = tmp_class_creation_5__prepared;
            tmp_expression_value_30 = BUILTIN_TYPE1(tmp_type_arg_10);
            assert(!(tmp_expression_value_30 == NULL));
            tmp_tuple_element_19 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_30, mod_consts[25]);
            Py_DECREF(tmp_expression_value_30);
            if (tmp_tuple_element_19 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 85;

                goto tuple_build_exception_5;
            }
            PyTuple_SET_ITEM(tmp_mod_expr_right_5, 1, tmp_tuple_element_19);
        }
        goto tuple_build_noexception_5;
        // Exception handling pass through code for tuple_build:
        tuple_build_exception_5:;
        Py_DECREF(tmp_mod_expr_right_5);
        goto try_except_handler_15;
        // Finished with no exception for tuple_build:
        tuple_build_noexception_5:;
        tmp_raise_value_5 = BINARY_OPERATION_MOD_OBJECT_UNICODE_TUPLE(tmp_mod_expr_left_5, tmp_mod_expr_right_5);
        Py_DECREF(tmp_mod_expr_right_5);
        if (tmp_raise_value_5 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_15;
        }
        exception_type = tmp_raise_type_5;
        Py_INCREF(tmp_raise_type_5);
        exception_value = tmp_raise_value_5;
        exception_lineno = 85;
        RAISE_EXCEPTION_IMPLICIT(tstate, &exception_type, &exception_value, &exception_tb);

        goto try_except_handler_15;
    }
    branch_no_14:;
    goto branch_end_13;
    branch_no_13:;
    {
        PyObject *tmp_assign_source_57;
        tmp_assign_source_57 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_5__prepared == NULL);
        tmp_class_creation_5__prepared = tmp_assign_source_57;
    }
    branch_end_13:;
    {
        PyObject *tmp_assign_source_58;
        {
            PyObject *tmp_set_locals_5;
            CHECK_OBJECT(tmp_class_creation_5__prepared);
            tmp_set_locals_5 = tmp_class_creation_5__prepared;
            locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85 = tmp_set_locals_5;
            Py_INCREF(tmp_set_locals_5);
        }
        // Tried code:
        // Tried code:
        tmp_dictset_value = mod_consts[27];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85, mod_consts[28], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_17;
        }
        tmp_dictset_value = mod_consts[40];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85, mod_consts[1], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_17;
        }
        tmp_dictset_value = mod_consts[42];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85, mod_consts[30], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_17;
        }
        {
            nuitka_bool tmp_condition_result_20;
            PyObject *tmp_cmp_expr_left_5;
            PyObject *tmp_cmp_expr_right_5;
            CHECK_OBJECT(tmp_class_creation_5__bases);
            tmp_cmp_expr_left_5 = tmp_class_creation_5__bases;
            CHECK_OBJECT(tmp_class_creation_5__bases_orig);
            tmp_cmp_expr_right_5 = tmp_class_creation_5__bases_orig;
            tmp_condition_result_20 = RICH_COMPARE_NE_NBOOL_OBJECT_TUPLE(tmp_cmp_expr_left_5, tmp_cmp_expr_right_5);
            if (tmp_condition_result_20 == NUITKA_BOOL_EXCEPTION) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 85;

                goto try_except_handler_17;
            }
            if (tmp_condition_result_20 == NUITKA_BOOL_TRUE) {
                goto branch_yes_15;
            } else {
                goto branch_no_15;
            }
        }
        branch_yes_15:;
        CHECK_OBJECT(tmp_class_creation_5__bases_orig);
        tmp_dictset_value = tmp_class_creation_5__bases_orig;
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85, mod_consts[31], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 85;

            goto try_except_handler_17;
        }
        branch_no_15:;
        {
            PyObject *tmp_assign_source_59;
            PyObject *tmp_called_value_14;
            PyObject *tmp_args_value_10;
            PyObject *tmp_tuple_element_20;
            PyObject *tmp_kwargs_value_10;
            CHECK_OBJECT(tmp_class_creation_5__metaclass);
            tmp_called_value_14 = tmp_class_creation_5__metaclass;
            tmp_tuple_element_20 = mod_consts[42];
            tmp_args_value_10 = MAKE_TUPLE_EMPTY(3);
            PyTuple_SET_ITEM0(tmp_args_value_10, 0, tmp_tuple_element_20);
            CHECK_OBJECT(tmp_class_creation_5__bases);
            tmp_tuple_element_20 = tmp_class_creation_5__bases;
            PyTuple_SET_ITEM0(tmp_args_value_10, 1, tmp_tuple_element_20);
            tmp_tuple_element_20 = locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85;
            PyTuple_SET_ITEM0(tmp_args_value_10, 2, tmp_tuple_element_20);
            CHECK_OBJECT(tmp_class_creation_5__class_decl_dict);
            tmp_kwargs_value_10 = tmp_class_creation_5__class_decl_dict;
            frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 85;
            tmp_assign_source_59 = CALL_FUNCTION(tstate, tmp_called_value_14, tmp_args_value_10, tmp_kwargs_value_10);
            Py_DECREF(tmp_args_value_10);
            if (tmp_assign_source_59 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 85;

                goto try_except_handler_17;
            }
            assert(outline_4_var___class__ == NULL);
            outline_4_var___class__ = tmp_assign_source_59;
        }
        CHECK_OBJECT(outline_4_var___class__);
        tmp_assign_source_58 = outline_4_var___class__;
        Py_INCREF(tmp_assign_source_58);
        goto try_return_handler_17;
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_17:;
        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85);
        locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85 = NULL;
        goto try_return_handler_16;
        // Exception handler code:
        try_except_handler_17:;
        exception_keeper_type_15 = exception_type;
        exception_keeper_value_15 = exception_value;
        exception_keeper_tb_15 = exception_tb;
        exception_keeper_lineno_15 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85);
        locals_pyudev$_ctypeslib$libudev$$$class__5_udev_monitor_85 = NULL;
        // Re-raise.
        exception_type = exception_keeper_type_15;
        exception_value = exception_keeper_value_15;
        exception_tb = exception_keeper_tb_15;
        exception_lineno = exception_keeper_lineno_15;

        goto try_except_handler_16;
        // End of try:
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_16:;
        CHECK_OBJECT(outline_4_var___class__);
        Py_DECREF(outline_4_var___class__);
        outline_4_var___class__ = NULL;
        goto outline_result_5;
        // Exception handler code:
        try_except_handler_16:;
        exception_keeper_type_16 = exception_type;
        exception_keeper_value_16 = exception_value;
        exception_keeper_tb_16 = exception_tb;
        exception_keeper_lineno_16 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        // Re-raise.
        exception_type = exception_keeper_type_16;
        exception_value = exception_keeper_value_16;
        exception_tb = exception_keeper_tb_16;
        exception_lineno = exception_keeper_lineno_16;

        goto outline_exception_5;
        // End of try:
        NUITKA_CANNOT_GET_HERE("Return statement must have exited already.");
        return NULL;
        outline_exception_5:;
        exception_lineno = 85;
        goto try_except_handler_15;
        outline_result_5:;
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[42], tmp_assign_source_58);
    }
    goto try_end_7;
    // Exception handler code:
    try_except_handler_15:;
    exception_keeper_type_17 = exception_type;
    exception_keeper_value_17 = exception_value;
    exception_keeper_tb_17 = exception_tb;
    exception_keeper_lineno_17 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    Py_XDECREF(tmp_class_creation_5__bases_orig);
    tmp_class_creation_5__bases_orig = NULL;
    Py_XDECREF(tmp_class_creation_5__bases);
    tmp_class_creation_5__bases = NULL;
    Py_XDECREF(tmp_class_creation_5__class_decl_dict);
    tmp_class_creation_5__class_decl_dict = NULL;
    Py_XDECREF(tmp_class_creation_5__metaclass);
    tmp_class_creation_5__metaclass = NULL;
    Py_XDECREF(tmp_class_creation_5__prepared);
    tmp_class_creation_5__prepared = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_17;
    exception_value = exception_keeper_value_17;
    exception_tb = exception_keeper_tb_17;
    exception_lineno = exception_keeper_lineno_17;

    goto frame_exception_exit_1;
    // End of try:
    try_end_7:;
    CHECK_OBJECT(tmp_class_creation_5__bases_orig);
    Py_DECREF(tmp_class_creation_5__bases_orig);
    tmp_class_creation_5__bases_orig = NULL;
    CHECK_OBJECT(tmp_class_creation_5__bases);
    Py_DECREF(tmp_class_creation_5__bases);
    tmp_class_creation_5__bases = NULL;
    CHECK_OBJECT(tmp_class_creation_5__class_decl_dict);
    Py_DECREF(tmp_class_creation_5__class_decl_dict);
    tmp_class_creation_5__class_decl_dict = NULL;
    CHECK_OBJECT(tmp_class_creation_5__metaclass);
    Py_DECREF(tmp_class_creation_5__metaclass);
    tmp_class_creation_5__metaclass = NULL;
    CHECK_OBJECT(tmp_class_creation_5__prepared);
    Py_DECREF(tmp_class_creation_5__prepared);
    tmp_class_creation_5__prepared = NULL;
    {
        PyObject *tmp_assign_source_60;
        PyObject *tmp_called_value_15;
        PyObject *tmp_args_element_value_5;
        tmp_called_value_15 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[7]);

        if (unlikely(tmp_called_value_15 == NULL)) {
            tmp_called_value_15 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[7]);
        }

        if (tmp_called_value_15 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 94;

            goto frame_exception_exit_1;
        }
        tmp_args_element_value_5 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[42]);

        if (unlikely(tmp_args_element_value_5 == NULL)) {
            tmp_args_element_value_5 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[42]);
        }

        if (tmp_args_element_value_5 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 94;

            goto frame_exception_exit_1;
        }
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 94;
        tmp_assign_source_60 = CALL_FUNCTION_WITH_SINGLE_ARG(tstate, tmp_called_value_15, tmp_args_element_value_5);
        if (tmp_assign_source_60 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 94;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43], tmp_assign_source_60);
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_61;
        PyObject *tmp_tuple_element_21;
        tmp_tuple_element_21 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[9]);

        if (unlikely(tmp_tuple_element_21 == NULL)) {
            tmp_tuple_element_21 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[9]);
        }

        if (tmp_tuple_element_21 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        tmp_assign_source_61 = MAKE_TUPLE_EMPTY(1);
        PyTuple_SET_ITEM0(tmp_assign_source_61, 0, tmp_tuple_element_21);
        assert(tmp_class_creation_6__bases_orig == NULL);
        tmp_class_creation_6__bases_orig = tmp_assign_source_61;
    }
    {
        PyObject *tmp_assign_source_62;
        PyObject *tmp_dircall_arg1_6;
        CHECK_OBJECT(tmp_class_creation_6__bases_orig);
        tmp_dircall_arg1_6 = tmp_class_creation_6__bases_orig;
        Py_INCREF(tmp_dircall_arg1_6);

        {
            PyObject *dir_call_args[] = {tmp_dircall_arg1_6};
            tmp_assign_source_62 = impl___main__$$$function__1__mro_entries_conversion(tstate, dir_call_args);
        }
        if (tmp_assign_source_62 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        assert(tmp_class_creation_6__bases == NULL);
        tmp_class_creation_6__bases = tmp_assign_source_62;
    }
    {
        PyObject *tmp_assign_source_63;
        tmp_assign_source_63 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_6__class_decl_dict == NULL);
        tmp_class_creation_6__class_decl_dict = tmp_assign_source_63;
    }
    {
        PyObject *tmp_assign_source_64;
        PyObject *tmp_metaclass_value_6;
        nuitka_bool tmp_condition_result_21;
        int tmp_truth_name_6;
        PyObject *tmp_type_arg_11;
        PyObject *tmp_expression_value_31;
        PyObject *tmp_subscript_value_6;
        PyObject *tmp_bases_value_6;
        CHECK_OBJECT(tmp_class_creation_6__bases);
        tmp_truth_name_6 = CHECK_IF_TRUE(tmp_class_creation_6__bases);
        if (tmp_truth_name_6 == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        tmp_condition_result_21 = tmp_truth_name_6 == 0 ? NUITKA_BOOL_FALSE : NUITKA_BOOL_TRUE;
        if (tmp_condition_result_21 == NUITKA_BOOL_TRUE) {
            goto condexpr_true_6;
        } else {
            goto condexpr_false_6;
        }
        condexpr_true_6:;
        CHECK_OBJECT(tmp_class_creation_6__bases);
        tmp_expression_value_31 = tmp_class_creation_6__bases;
        tmp_subscript_value_6 = mod_consts[8];
        tmp_type_arg_11 = LOOKUP_SUBSCRIPT_CONST(tstate, tmp_expression_value_31, tmp_subscript_value_6, 0);
        if (tmp_type_arg_11 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        tmp_metaclass_value_6 = BUILTIN_TYPE1(tmp_type_arg_11);
        Py_DECREF(tmp_type_arg_11);
        if (tmp_metaclass_value_6 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        goto condexpr_end_6;
        condexpr_false_6:;
        tmp_metaclass_value_6 = (PyObject *)&PyType_Type;
        Py_INCREF(tmp_metaclass_value_6);
        condexpr_end_6:;
        CHECK_OBJECT(tmp_class_creation_6__bases);
        tmp_bases_value_6 = tmp_class_creation_6__bases;
        tmp_assign_source_64 = SELECT_METACLASS(tstate, tmp_metaclass_value_6, tmp_bases_value_6);
        Py_DECREF(tmp_metaclass_value_6);
        if (tmp_assign_source_64 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        assert(tmp_class_creation_6__metaclass == NULL);
        tmp_class_creation_6__metaclass = tmp_assign_source_64;
    }
    {
        bool tmp_condition_result_22;
        PyObject *tmp_expression_value_32;
        CHECK_OBJECT(tmp_class_creation_6__metaclass);
        tmp_expression_value_32 = tmp_class_creation_6__metaclass;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_32, mod_consts[21]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        tmp_condition_result_22 = (tmp_res != 0) ? true : false;
        if (tmp_condition_result_22 != false) {
            goto branch_yes_16;
        } else {
            goto branch_no_16;
        }
    }
    branch_yes_16:;
    {
        PyObject *tmp_assign_source_65;
        PyObject *tmp_called_value_16;
        PyObject *tmp_expression_value_33;
        PyObject *tmp_args_value_11;
        PyObject *tmp_tuple_element_22;
        PyObject *tmp_kwargs_value_11;
        CHECK_OBJECT(tmp_class_creation_6__metaclass);
        tmp_expression_value_33 = tmp_class_creation_6__metaclass;
        tmp_called_value_16 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_33, mod_consts[21]);
        if (tmp_called_value_16 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        tmp_tuple_element_22 = mod_consts[44];
        tmp_args_value_11 = MAKE_TUPLE_EMPTY(2);
        PyTuple_SET_ITEM0(tmp_args_value_11, 0, tmp_tuple_element_22);
        CHECK_OBJECT(tmp_class_creation_6__bases);
        tmp_tuple_element_22 = tmp_class_creation_6__bases;
        PyTuple_SET_ITEM0(tmp_args_value_11, 1, tmp_tuple_element_22);
        CHECK_OBJECT(tmp_class_creation_6__class_decl_dict);
        tmp_kwargs_value_11 = tmp_class_creation_6__class_decl_dict;
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 97;
        tmp_assign_source_65 = CALL_FUNCTION(tstate, tmp_called_value_16, tmp_args_value_11, tmp_kwargs_value_11);
        Py_DECREF(tmp_called_value_16);
        Py_DECREF(tmp_args_value_11);
        if (tmp_assign_source_65 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        assert(tmp_class_creation_6__prepared == NULL);
        tmp_class_creation_6__prepared = tmp_assign_source_65;
    }
    {
        bool tmp_condition_result_23;
        PyObject *tmp_operand_value_6;
        PyObject *tmp_expression_value_34;
        CHECK_OBJECT(tmp_class_creation_6__prepared);
        tmp_expression_value_34 = tmp_class_creation_6__prepared;
        tmp_res = HAS_ATTR_BOOL2(tstate, tmp_expression_value_34, mod_consts[23]);
        if (tmp_res == -1) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        tmp_operand_value_6 = (tmp_res != 0) ? Py_True : Py_False;
        tmp_res = CHECK_IF_TRUE(tmp_operand_value_6);
        assert(!(tmp_res == -1));
        tmp_condition_result_23 = (tmp_res == 0) ? true : false;
        if (tmp_condition_result_23 != false) {
            goto branch_yes_17;
        } else {
            goto branch_no_17;
        }
    }
    branch_yes_17:;
    {
        PyObject *tmp_raise_type_6;
        PyObject *tmp_raise_value_6;
        PyObject *tmp_mod_expr_left_6;
        PyObject *tmp_mod_expr_right_6;
        PyObject *tmp_tuple_element_23;
        PyObject *tmp_expression_value_35;
        PyObject *tmp_name_value_7;
        PyObject *tmp_default_value_6;
        tmp_raise_type_6 = PyExc_TypeError;
        tmp_mod_expr_left_6 = mod_consts[24];
        CHECK_OBJECT(tmp_class_creation_6__metaclass);
        tmp_expression_value_35 = tmp_class_creation_6__metaclass;
        tmp_name_value_7 = mod_consts[25];
        tmp_default_value_6 = mod_consts[26];
        tmp_tuple_element_23 = BUILTIN_GETATTR(tstate, tmp_expression_value_35, tmp_name_value_7, tmp_default_value_6);
        if (tmp_tuple_element_23 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        tmp_mod_expr_right_6 = MAKE_TUPLE_EMPTY(2);
        {
            PyObject *tmp_expression_value_36;
            PyObject *tmp_type_arg_12;
            PyTuple_SET_ITEM(tmp_mod_expr_right_6, 0, tmp_tuple_element_23);
            CHECK_OBJECT(tmp_class_creation_6__prepared);
            tmp_type_arg_12 = tmp_class_creation_6__prepared;
            tmp_expression_value_36 = BUILTIN_TYPE1(tmp_type_arg_12);
            assert(!(tmp_expression_value_36 == NULL));
            tmp_tuple_element_23 = LOOKUP_ATTRIBUTE(tstate, tmp_expression_value_36, mod_consts[25]);
            Py_DECREF(tmp_expression_value_36);
            if (tmp_tuple_element_23 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 97;

                goto tuple_build_exception_6;
            }
            PyTuple_SET_ITEM(tmp_mod_expr_right_6, 1, tmp_tuple_element_23);
        }
        goto tuple_build_noexception_6;
        // Exception handling pass through code for tuple_build:
        tuple_build_exception_6:;
        Py_DECREF(tmp_mod_expr_right_6);
        goto try_except_handler_18;
        // Finished with no exception for tuple_build:
        tuple_build_noexception_6:;
        tmp_raise_value_6 = BINARY_OPERATION_MOD_OBJECT_UNICODE_TUPLE(tmp_mod_expr_left_6, tmp_mod_expr_right_6);
        Py_DECREF(tmp_mod_expr_right_6);
        if (tmp_raise_value_6 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_18;
        }
        exception_type = tmp_raise_type_6;
        Py_INCREF(tmp_raise_type_6);
        exception_value = tmp_raise_value_6;
        exception_lineno = 97;
        RAISE_EXCEPTION_IMPLICIT(tstate, &exception_type, &exception_value, &exception_tb);

        goto try_except_handler_18;
    }
    branch_no_17:;
    goto branch_end_16;
    branch_no_16:;
    {
        PyObject *tmp_assign_source_66;
        tmp_assign_source_66 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_6__prepared == NULL);
        tmp_class_creation_6__prepared = tmp_assign_source_66;
    }
    branch_end_16:;
    {
        PyObject *tmp_assign_source_67;
        {
            PyObject *tmp_set_locals_6;
            CHECK_OBJECT(tmp_class_creation_6__prepared);
            tmp_set_locals_6 = tmp_class_creation_6__prepared;
            locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97 = tmp_set_locals_6;
            Py_INCREF(tmp_set_locals_6);
        }
        // Tried code:
        // Tried code:
        tmp_dictset_value = mod_consts[27];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97, mod_consts[28], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_20;
        }
        tmp_dictset_value = mod_consts[45];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97, mod_consts[1], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_20;
        }
        tmp_dictset_value = mod_consts[44];
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97, mod_consts[30], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_20;
        }
        {
            nuitka_bool tmp_condition_result_24;
            PyObject *tmp_cmp_expr_left_6;
            PyObject *tmp_cmp_expr_right_6;
            CHECK_OBJECT(tmp_class_creation_6__bases);
            tmp_cmp_expr_left_6 = tmp_class_creation_6__bases;
            CHECK_OBJECT(tmp_class_creation_6__bases_orig);
            tmp_cmp_expr_right_6 = tmp_class_creation_6__bases_orig;
            tmp_condition_result_24 = RICH_COMPARE_NE_NBOOL_OBJECT_TUPLE(tmp_cmp_expr_left_6, tmp_cmp_expr_right_6);
            if (tmp_condition_result_24 == NUITKA_BOOL_EXCEPTION) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 97;

                goto try_except_handler_20;
            }
            if (tmp_condition_result_24 == NUITKA_BOOL_TRUE) {
                goto branch_yes_18;
            } else {
                goto branch_no_18;
            }
        }
        branch_yes_18:;
        CHECK_OBJECT(tmp_class_creation_6__bases_orig);
        tmp_dictset_value = tmp_class_creation_6__bases_orig;
        tmp_res = PyObject_SetItem(locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97, mod_consts[31], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 97;

            goto try_except_handler_20;
        }
        branch_no_18:;
        {
            PyObject *tmp_assign_source_68;
            PyObject *tmp_called_value_17;
            PyObject *tmp_args_value_12;
            PyObject *tmp_tuple_element_24;
            PyObject *tmp_kwargs_value_12;
            CHECK_OBJECT(tmp_class_creation_6__metaclass);
            tmp_called_value_17 = tmp_class_creation_6__metaclass;
            tmp_tuple_element_24 = mod_consts[44];
            tmp_args_value_12 = MAKE_TUPLE_EMPTY(3);
            PyTuple_SET_ITEM0(tmp_args_value_12, 0, tmp_tuple_element_24);
            CHECK_OBJECT(tmp_class_creation_6__bases);
            tmp_tuple_element_24 = tmp_class_creation_6__bases;
            PyTuple_SET_ITEM0(tmp_args_value_12, 1, tmp_tuple_element_24);
            tmp_tuple_element_24 = locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97;
            PyTuple_SET_ITEM0(tmp_args_value_12, 2, tmp_tuple_element_24);
            CHECK_OBJECT(tmp_class_creation_6__class_decl_dict);
            tmp_kwargs_value_12 = tmp_class_creation_6__class_decl_dict;
            frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 97;
            tmp_assign_source_68 = CALL_FUNCTION(tstate, tmp_called_value_17, tmp_args_value_12, tmp_kwargs_value_12);
            Py_DECREF(tmp_args_value_12);
            if (tmp_assign_source_68 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 97;

                goto try_except_handler_20;
            }
            assert(outline_5_var___class__ == NULL);
            outline_5_var___class__ = tmp_assign_source_68;
        }
        CHECK_OBJECT(outline_5_var___class__);
        tmp_assign_source_67 = outline_5_var___class__;
        Py_INCREF(tmp_assign_source_67);
        goto try_return_handler_20;
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_20:;
        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97);
        locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97 = NULL;
        goto try_return_handler_19;
        // Exception handler code:
        try_except_handler_20:;
        exception_keeper_type_18 = exception_type;
        exception_keeper_value_18 = exception_value;
        exception_keeper_tb_18 = exception_tb;
        exception_keeper_lineno_18 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        Py_DECREF(locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97);
        locals_pyudev$_ctypeslib$libudev$$$class__6_udev_hwdb_97 = NULL;
        // Re-raise.
        exception_type = exception_keeper_type_18;
        exception_value = exception_keeper_value_18;
        exception_tb = exception_keeper_tb_18;
        exception_lineno = exception_keeper_lineno_18;

        goto try_except_handler_19;
        // End of try:
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_19:;
        CHECK_OBJECT(outline_5_var___class__);
        Py_DECREF(outline_5_var___class__);
        outline_5_var___class__ = NULL;
        goto outline_result_6;
        // Exception handler code:
        try_except_handler_19:;
        exception_keeper_type_19 = exception_type;
        exception_keeper_value_19 = exception_value;
        exception_keeper_tb_19 = exception_tb;
        exception_keeper_lineno_19 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        // Re-raise.
        exception_type = exception_keeper_type_19;
        exception_value = exception_keeper_value_19;
        exception_tb = exception_keeper_tb_19;
        exception_lineno = exception_keeper_lineno_19;

        goto outline_exception_6;
        // End of try:
        NUITKA_CANNOT_GET_HERE("Return statement must have exited already.");
        return NULL;
        outline_exception_6:;
        exception_lineno = 97;
        goto try_except_handler_18;
        outline_result_6:;
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[44], tmp_assign_source_67);
    }
    goto try_end_8;
    // Exception handler code:
    try_except_handler_18:;
    exception_keeper_type_20 = exception_type;
    exception_keeper_value_20 = exception_value;
    exception_keeper_tb_20 = exception_tb;
    exception_keeper_lineno_20 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    Py_XDECREF(tmp_class_creation_6__bases_orig);
    tmp_class_creation_6__bases_orig = NULL;
    Py_XDECREF(tmp_class_creation_6__bases);
    tmp_class_creation_6__bases = NULL;
    Py_XDECREF(tmp_class_creation_6__class_decl_dict);
    tmp_class_creation_6__class_decl_dict = NULL;
    Py_XDECREF(tmp_class_creation_6__metaclass);
    tmp_class_creation_6__metaclass = NULL;
    Py_XDECREF(tmp_class_creation_6__prepared);
    tmp_class_creation_6__prepared = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_20;
    exception_value = exception_keeper_value_20;
    exception_tb = exception_keeper_tb_20;
    exception_lineno = exception_keeper_lineno_20;

    goto frame_exception_exit_1;
    // End of try:
    try_end_8:;
    CHECK_OBJECT(tmp_class_creation_6__bases_orig);
    Py_DECREF(tmp_class_creation_6__bases_orig);
    tmp_class_creation_6__bases_orig = NULL;
    CHECK_OBJECT(tmp_class_creation_6__bases);
    Py_DECREF(tmp_class_creation_6__bases);
    tmp_class_creation_6__bases = NULL;
    CHECK_OBJECT(tmp_class_creation_6__class_decl_dict);
    Py_DECREF(tmp_class_creation_6__class_decl_dict);
    tmp_class_creation_6__class_decl_dict = NULL;
    CHECK_OBJECT(tmp_class_creation_6__metaclass);
    Py_DECREF(tmp_class_creation_6__metaclass);
    tmp_class_creation_6__metaclass = NULL;
    CHECK_OBJECT(tmp_class_creation_6__prepared);
    Py_DECREF(tmp_class_creation_6__prepared);
    tmp_class_creation_6__prepared = NULL;
    {
        PyObject *tmp_assign_source_69;
        PyObject *tmp_called_value_18;
        PyObject *tmp_args_element_value_6;
        tmp_called_value_18 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[7]);

        if (unlikely(tmp_called_value_18 == NULL)) {
            tmp_called_value_18 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[7]);
        }

        if (tmp_called_value_18 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 106;

            goto frame_exception_exit_1;
        }
        tmp_args_element_value_6 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[44]);

        if (unlikely(tmp_args_element_value_6 == NULL)) {
            tmp_args_element_value_6 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[44]);
        }

        if (tmp_args_element_value_6 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 106;

            goto frame_exception_exit_1;
        }
        frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame.f_lineno = 106;
        tmp_assign_source_69 = CALL_FUNCTION_WITH_SINGLE_ARG(tstate, tmp_called_value_18, tmp_args_element_value_6);
        if (tmp_assign_source_69 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 106;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[46], tmp_assign_source_69);
    }
    {
        PyObject *tmp_assign_source_70;
        tmp_assign_source_70 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[14]);

        if (unlikely(tmp_assign_source_70 == NULL)) {
            tmp_assign_source_70 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[14]);
        }

        if (tmp_assign_source_70 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 108;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT0(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[47], tmp_assign_source_70);
    }
    {
        PyObject *tmp_assign_source_71;
        PyObject *tmp_dict_key_1;
        PyObject *tmp_dict_value_1;
        PyObject *tmp_tuple_element_25;
        tmp_dict_key_1 = mod_consts[48];
        tmp_tuple_element_25 = MAKE_LIST_EMPTY(0);
        tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
        PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_25);
        tmp_tuple_element_25 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

        if (unlikely(tmp_tuple_element_25 == NULL)) {
            tmp_tuple_element_25 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
        }

        if (tmp_tuple_element_25 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 112;

            goto tuple_build_exception_7;
        }
        PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_25);
        goto tuple_build_noexception_7;
        // Exception handling pass through code for tuple_build:
        tuple_build_exception_7:;
        Py_DECREF(tmp_dict_value_1);
        goto frame_exception_exit_1;
        // Finished with no exception for tuple_build:
        tuple_build_noexception_7:;
        tmp_assign_source_71 = _PyDict_NewPresized( 70 );
        {
            PyObject *tmp_tuple_element_26;
            PyObject *tmp_list_element_1;
            PyObject *tmp_tuple_element_27;
            PyObject *tmp_list_element_2;
            PyObject *tmp_tuple_element_28;
            PyObject *tmp_list_element_3;
            PyObject *tmp_tuple_element_29;
            PyObject *tmp_list_element_4;
            PyObject *tmp_tuple_element_30;
            PyObject *tmp_list_element_5;
            PyObject *tmp_tuple_element_31;
            PyObject *tmp_list_element_6;
            PyObject *tmp_tuple_element_32;
            PyObject *tmp_list_element_7;
            PyObject *tmp_tuple_element_33;
            PyObject *tmp_list_element_8;
            PyObject *tmp_tuple_element_34;
            PyObject *tmp_list_element_9;
            PyObject *tmp_tuple_element_35;
            PyObject *tmp_list_element_10;
            PyObject *tmp_tuple_element_36;
            PyObject *tmp_list_element_11;
            PyObject *tmp_tuple_element_37;
            PyObject *tmp_list_element_12;
            PyObject *tmp_tuple_element_38;
            PyObject *tmp_list_element_13;
            PyObject *tmp_tuple_element_39;
            PyObject *tmp_list_element_14;
            PyObject *tmp_tuple_element_40;
            PyObject *tmp_list_element_15;
            PyObject *tmp_tuple_element_41;
            PyObject *tmp_list_element_16;
            PyObject *tmp_tuple_element_42;
            PyObject *tmp_list_element_17;
            PyObject *tmp_tuple_element_43;
            PyObject *tmp_list_element_18;
            PyObject *tmp_tuple_element_44;
            PyObject *tmp_list_element_19;
            PyObject *tmp_tuple_element_45;
            PyObject *tmp_list_element_20;
            PyObject *tmp_tuple_element_46;
            PyObject *tmp_list_element_21;
            PyObject *tmp_tuple_element_47;
            PyObject *tmp_list_element_22;
            PyObject *tmp_tuple_element_48;
            PyObject *tmp_list_element_23;
            PyObject *tmp_tuple_element_49;
            PyObject *tmp_list_element_24;
            PyObject *tmp_tuple_element_50;
            PyObject *tmp_list_element_25;
            PyObject *tmp_tuple_element_51;
            PyObject *tmp_list_element_26;
            PyObject *tmp_tuple_element_52;
            PyObject *tmp_list_element_27;
            PyObject *tmp_tuple_element_53;
            PyObject *tmp_list_element_28;
            PyObject *tmp_tuple_element_54;
            PyObject *tmp_list_element_29;
            PyObject *tmp_tuple_element_55;
            PyObject *tmp_list_element_30;
            PyObject *tmp_tuple_element_56;
            PyObject *tmp_list_element_31;
            PyObject *tmp_tuple_element_57;
            PyObject *tmp_list_element_32;
            PyObject *tmp_tuple_element_58;
            PyObject *tmp_list_element_33;
            PyObject *tmp_tuple_element_59;
            PyObject *tmp_list_element_34;
            PyObject *tmp_tuple_element_60;
            PyObject *tmp_list_element_35;
            PyObject *tmp_tuple_element_61;
            PyObject *tmp_list_element_36;
            PyObject *tmp_tuple_element_62;
            PyObject *tmp_list_element_37;
            PyObject *tmp_tuple_element_63;
            PyObject *tmp_list_element_38;
            PyObject *tmp_tuple_element_64;
            PyObject *tmp_list_element_39;
            PyObject *tmp_tuple_element_65;
            PyObject *tmp_list_element_40;
            PyObject *tmp_tuple_element_66;
            PyObject *tmp_list_element_41;
            PyObject *tmp_tuple_element_67;
            PyObject *tmp_list_element_42;
            PyObject *tmp_tuple_element_68;
            PyObject *tmp_list_element_43;
            PyObject *tmp_tuple_element_69;
            PyObject *tmp_list_element_44;
            PyObject *tmp_tuple_element_70;
            PyObject *tmp_list_element_45;
            PyObject *tmp_tuple_element_71;
            PyObject *tmp_list_element_46;
            PyObject *tmp_tuple_element_72;
            PyObject *tmp_list_element_47;
            PyObject *tmp_tuple_element_73;
            PyObject *tmp_list_element_48;
            PyObject *tmp_tuple_element_74;
            PyObject *tmp_list_element_49;
            PyObject *tmp_tuple_element_75;
            PyObject *tmp_list_element_50;
            PyObject *tmp_tuple_element_76;
            PyObject *tmp_list_element_51;
            PyObject *tmp_tuple_element_77;
            PyObject *tmp_list_element_52;
            PyObject *tmp_tuple_element_78;
            PyObject *tmp_list_element_53;
            PyObject *tmp_tuple_element_79;
            PyObject *tmp_list_element_54;
            PyObject *tmp_tuple_element_80;
            PyObject *tmp_list_element_55;
            PyObject *tmp_tuple_element_81;
            PyObject *tmp_list_element_56;
            PyObject *tmp_tuple_element_82;
            PyObject *tmp_list_element_57;
            PyObject *tmp_tuple_element_83;
            PyObject *tmp_list_element_58;
            PyObject *tmp_tuple_element_84;
            PyObject *tmp_list_element_59;
            PyObject *tmp_tuple_element_85;
            PyObject *tmp_list_element_60;
            PyObject *tmp_tuple_element_86;
            PyObject *tmp_list_element_61;
            PyObject *tmp_tuple_element_87;
            PyObject *tmp_list_element_62;
            PyObject *tmp_tuple_element_88;
            PyObject *tmp_list_element_63;
            PyObject *tmp_tuple_element_89;
            PyObject *tmp_list_element_64;
            PyObject *tmp_tuple_element_90;
            PyObject *tmp_list_element_65;
            PyObject *tmp_tuple_element_91;
            PyObject *tmp_list_element_66;
            PyObject *tmp_tuple_element_92;
            PyObject *tmp_list_element_67;
            PyObject *tmp_tuple_element_93;
            PyObject *tmp_list_element_68;
            PyObject *tmp_tuple_element_94;
            PyObject *tmp_list_element_69;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[49];
            tmp_list_element_1 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_1 == NULL)) {
                tmp_list_element_1 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_1 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 113;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_26 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_26, 0, tmp_list_element_1);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_26);
            tmp_tuple_element_26 = Py_None;
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_26);
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[50];
            tmp_list_element_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_2 == NULL)) {
                tmp_list_element_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_2 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 114;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_27 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_27, 0, tmp_list_element_2);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_27);
            tmp_tuple_element_27 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_tuple_element_27 == NULL)) {
                tmp_tuple_element_27 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_tuple_element_27 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 114;

                goto tuple_build_exception_8;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_27);
            goto tuple_build_noexception_8;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_8:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_8:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[51];
            tmp_list_element_3 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_3 == NULL)) {
                tmp_list_element_3 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_3 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 115;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_28 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_28, 0, tmp_list_element_3);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_28);
            tmp_tuple_element_28 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_28 == NULL)) {
                tmp_tuple_element_28 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_28 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 115;

                goto tuple_build_exception_9;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_28);
            goto tuple_build_noexception_9;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_9:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_9:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[52];
            tmp_list_element_4 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_4 == NULL)) {
                tmp_list_element_4 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_4 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 116;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_29 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_29, 0, tmp_list_element_4);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_29);
            tmp_tuple_element_29 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_29 == NULL)) {
                tmp_tuple_element_29 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_29 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 116;

                goto tuple_build_exception_10;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_29);
            goto tuple_build_noexception_10;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_10:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_10:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[53];
            tmp_list_element_5 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_5 == NULL)) {
                tmp_list_element_5 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_5 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 117;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_30 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_30, 0, tmp_list_element_5);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_30);
            tmp_tuple_element_30 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_30 == NULL)) {
                tmp_tuple_element_30 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_30 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 117;

                goto tuple_build_exception_11;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_30);
            goto tuple_build_noexception_11;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_11:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_11:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[54];
            tmp_list_element_6 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_6 == NULL)) {
                tmp_list_element_6 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_6 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 118;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_31 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_31, 0, tmp_list_element_6);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_31);
            tmp_tuple_element_31 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_31 == NULL)) {
                tmp_tuple_element_31 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_31 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 118;

                goto tuple_build_exception_12;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_31);
            goto tuple_build_noexception_12;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_12:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_12:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[55];
            tmp_list_element_7 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_7 == NULL)) {
                tmp_list_element_7 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_7 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 119;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_32 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_32, 0, tmp_list_element_7);
            tmp_list_element_7 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_list_element_7 == NULL)) {
                tmp_list_element_7 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_list_element_7 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 119;

                goto list_build_exception_1;
            }
            PyList_SET_ITEM0(tmp_tuple_element_32, 1, tmp_list_element_7);
            goto list_build_noexception_1;
            // Exception handling pass through code for list_build:
            list_build_exception_1:;
            Py_DECREF(tmp_tuple_element_32);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_1:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_32);
            tmp_tuple_element_32 = Py_None;
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_32);
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[56];
            tmp_list_element_8 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_8 == NULL)) {
                tmp_list_element_8 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_8 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 120;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_33 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_33, 0, tmp_list_element_8);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_33);
            tmp_tuple_element_33 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_tuple_element_33 == NULL)) {
                tmp_tuple_element_33 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_tuple_element_33 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 120;

                goto tuple_build_exception_13;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_33);
            goto tuple_build_noexception_13;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_13:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_13:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[57];
            tmp_list_element_9 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_9 == NULL)) {
                tmp_list_element_9 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_9 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 121;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_34 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_34, 0, tmp_list_element_9);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_34);
            tmp_tuple_element_34 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_tuple_element_34 == NULL)) {
                tmp_tuple_element_34 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_tuple_element_34 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 121;

                goto tuple_build_exception_14;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_34);
            goto tuple_build_noexception_14;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_14:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_14:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[58];
            tmp_list_element_10 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_10 == NULL)) {
                tmp_list_element_10 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_10 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 122;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_35 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_35, 0, tmp_list_element_10);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_35);
            tmp_tuple_element_35 = Py_None;
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_35);
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[59];
            tmp_list_element_11 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_11 == NULL)) {
                tmp_list_element_11 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_11 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 123;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_36 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_36, 0, tmp_list_element_11);
            tmp_list_element_11 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_11 == NULL)) {
                tmp_list_element_11 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_11 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 123;

                goto list_build_exception_2;
            }
            PyList_SET_ITEM0(tmp_tuple_element_36, 1, tmp_list_element_11);
            goto list_build_noexception_2;
            // Exception handling pass through code for list_build:
            list_build_exception_2:;
            Py_DECREF(tmp_tuple_element_36);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_2:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_36);
            tmp_tuple_element_36 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_36 == NULL)) {
                tmp_tuple_element_36 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_36 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 123;

                goto tuple_build_exception_15;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_36);
            goto tuple_build_noexception_15;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_15:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_15:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[60];
            tmp_list_element_12 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_12 == NULL)) {
                tmp_list_element_12 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_12 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 124;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_37 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_37, 0, tmp_list_element_12);
            tmp_list_element_12 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_12 == NULL)) {
                tmp_list_element_12 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_12 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 124;

                goto list_build_exception_3;
            }
            PyList_SET_ITEM0(tmp_tuple_element_37, 1, tmp_list_element_12);
            goto list_build_noexception_3;
            // Exception handling pass through code for list_build:
            list_build_exception_3:;
            Py_DECREF(tmp_tuple_element_37);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_3:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_37);
            tmp_tuple_element_37 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_37 == NULL)) {
                tmp_tuple_element_37 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_37 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 124;

                goto tuple_build_exception_16;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_37);
            goto tuple_build_noexception_16;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_16:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_16:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[61];
            tmp_list_element_13 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_13 == NULL)) {
                tmp_list_element_13 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_13 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 125;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_38 = MAKE_LIST_EMPTY(3);
            PyList_SET_ITEM0(tmp_tuple_element_38, 0, tmp_list_element_13);
            tmp_list_element_13 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_13 == NULL)) {
                tmp_list_element_13 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_13 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 125;

                goto list_build_exception_4;
            }
            PyList_SET_ITEM0(tmp_tuple_element_38, 1, tmp_list_element_13);
            tmp_list_element_13 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_13 == NULL)) {
                tmp_list_element_13 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_13 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 125;

                goto list_build_exception_4;
            }
            PyList_SET_ITEM0(tmp_tuple_element_38, 2, tmp_list_element_13);
            goto list_build_noexception_4;
            // Exception handling pass through code for list_build:
            list_build_exception_4:;
            Py_DECREF(tmp_tuple_element_38);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_4:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_38);
            tmp_tuple_element_38 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_38 == NULL)) {
                tmp_tuple_element_38 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_38 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 125;

                goto tuple_build_exception_17;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_38);
            goto tuple_build_noexception_17;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_17:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_17:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[62];
            tmp_list_element_14 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_14 == NULL)) {
                tmp_list_element_14 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_14 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 126;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_39 = MAKE_LIST_EMPTY(3);
            PyList_SET_ITEM0(tmp_tuple_element_39, 0, tmp_list_element_14);
            tmp_list_element_14 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_14 == NULL)) {
                tmp_list_element_14 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_14 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 126;

                goto list_build_exception_5;
            }
            PyList_SET_ITEM0(tmp_tuple_element_39, 1, tmp_list_element_14);
            tmp_list_element_14 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_14 == NULL)) {
                tmp_list_element_14 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_14 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 126;

                goto list_build_exception_5;
            }
            PyList_SET_ITEM0(tmp_tuple_element_39, 2, tmp_list_element_14);
            goto list_build_noexception_5;
            // Exception handling pass through code for list_build:
            list_build_exception_5:;
            Py_DECREF(tmp_tuple_element_39);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_5:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_39);
            tmp_tuple_element_39 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_39 == NULL)) {
                tmp_tuple_element_39 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_39 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 126;

                goto tuple_build_exception_18;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_39);
            goto tuple_build_noexception_18;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_18:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_18:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[63];
            tmp_list_element_15 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_15 == NULL)) {
                tmp_list_element_15 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_15 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 127;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_40 = MAKE_LIST_EMPTY(3);
            PyList_SET_ITEM0(tmp_tuple_element_40, 0, tmp_list_element_15);
            tmp_list_element_15 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_15 == NULL)) {
                tmp_list_element_15 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_15 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 127;

                goto list_build_exception_6;
            }
            PyList_SET_ITEM0(tmp_tuple_element_40, 1, tmp_list_element_15);
            tmp_list_element_15 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_15 == NULL)) {
                tmp_list_element_15 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_15 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 127;

                goto list_build_exception_6;
            }
            PyList_SET_ITEM0(tmp_tuple_element_40, 2, tmp_list_element_15);
            goto list_build_noexception_6;
            // Exception handling pass through code for list_build:
            list_build_exception_6:;
            Py_DECREF(tmp_tuple_element_40);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_6:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_40);
            tmp_tuple_element_40 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_40 == NULL)) {
                tmp_tuple_element_40 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_40 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 127;

                goto tuple_build_exception_19;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_40);
            goto tuple_build_noexception_19;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_19:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_19:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[64];
            tmp_list_element_16 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_16 == NULL)) {
                tmp_list_element_16 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_16 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 128;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_41 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_41, 0, tmp_list_element_16);
            tmp_list_element_16 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_16 == NULL)) {
                tmp_list_element_16 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_16 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 128;

                goto list_build_exception_7;
            }
            PyList_SET_ITEM0(tmp_tuple_element_41, 1, tmp_list_element_16);
            goto list_build_noexception_7;
            // Exception handling pass through code for list_build:
            list_build_exception_7:;
            Py_DECREF(tmp_tuple_element_41);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_7:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_41);
            tmp_tuple_element_41 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_41 == NULL)) {
                tmp_tuple_element_41 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_41 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 128;

                goto tuple_build_exception_20;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_41);
            goto tuple_build_noexception_20;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_20:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_20:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[65];
            tmp_list_element_17 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_17 == NULL)) {
                tmp_list_element_17 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_17 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 129;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_42 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_42, 0, tmp_list_element_17);
            tmp_list_element_17 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_17 == NULL)) {
                tmp_list_element_17 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_17 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 129;

                goto list_build_exception_8;
            }
            PyList_SET_ITEM0(tmp_tuple_element_42, 1, tmp_list_element_17);
            goto list_build_noexception_8;
            // Exception handling pass through code for list_build:
            list_build_exception_8:;
            Py_DECREF(tmp_tuple_element_42);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_8:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_42);
            tmp_tuple_element_42 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_42 == NULL)) {
                tmp_tuple_element_42 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_42 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 129;

                goto tuple_build_exception_21;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_42);
            goto tuple_build_noexception_21;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_21:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_21:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[66];
            tmp_list_element_18 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_18 == NULL)) {
                tmp_list_element_18 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_18 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 130;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_43 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_43, 0, tmp_list_element_18);
            tmp_list_element_18 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_18 == NULL)) {
                tmp_list_element_18 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_18 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 130;

                goto list_build_exception_9;
            }
            PyList_SET_ITEM0(tmp_tuple_element_43, 1, tmp_list_element_18);
            goto list_build_noexception_9;
            // Exception handling pass through code for list_build:
            list_build_exception_9:;
            Py_DECREF(tmp_tuple_element_43);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_9:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_43);
            tmp_tuple_element_43 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_43 == NULL)) {
                tmp_tuple_element_43 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_43 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 130;

                goto tuple_build_exception_22;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_43);
            goto tuple_build_noexception_22;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_22:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_22:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[67];
            tmp_list_element_19 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_19 == NULL)) {
                tmp_list_element_19 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_19 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 131;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_44 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_44, 0, tmp_list_element_19);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_44);
            tmp_tuple_element_44 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_44 == NULL)) {
                tmp_tuple_element_44 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_44 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 131;

                goto tuple_build_exception_23;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_44);
            goto tuple_build_noexception_23;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_23:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_23:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[68];
            tmp_list_element_20 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_20 == NULL)) {
                tmp_list_element_20 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_20 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 132;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_45 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_45, 0, tmp_list_element_20);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_45);
            tmp_tuple_element_45 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_45 == NULL)) {
                tmp_tuple_element_45 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_45 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 132;

                goto tuple_build_exception_24;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_45);
            goto tuple_build_noexception_24;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_24:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_24:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[69];
            tmp_list_element_21 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[35]);

            if (unlikely(tmp_list_element_21 == NULL)) {
                tmp_list_element_21 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[35]);
            }

            if (tmp_list_element_21 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 133;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_46 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_46, 0, tmp_list_element_21);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_46);
            tmp_tuple_element_46 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38]);

            if (unlikely(tmp_tuple_element_46 == NULL)) {
                tmp_tuple_element_46 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[38]);
            }

            if (tmp_tuple_element_46 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 133;

                goto tuple_build_exception_25;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_46);
            goto tuple_build_noexception_25;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_25:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_25:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[70];
            tmp_list_element_22 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38]);

            if (unlikely(tmp_list_element_22 == NULL)) {
                tmp_list_element_22 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[38]);
            }

            if (tmp_list_element_22 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 135;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_47 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_47, 0, tmp_list_element_22);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_47);
            tmp_tuple_element_47 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38]);

            if (unlikely(tmp_tuple_element_47 == NULL)) {
                tmp_tuple_element_47 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[38]);
            }

            if (tmp_tuple_element_47 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 135;

                goto tuple_build_exception_26;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_47);
            goto tuple_build_noexception_26;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_26:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_26:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[71];
            tmp_list_element_23 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38]);

            if (unlikely(tmp_list_element_23 == NULL)) {
                tmp_list_element_23 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[38]);
            }

            if (tmp_list_element_23 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 136;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_48 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_48, 0, tmp_list_element_23);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_48);
            tmp_tuple_element_48 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_48 == NULL)) {
                tmp_tuple_element_48 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_48 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 136;

                goto tuple_build_exception_27;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_48);
            goto tuple_build_noexception_27;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_27:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_27:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[72];
            tmp_list_element_24 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38]);

            if (unlikely(tmp_list_element_24 == NULL)) {
                tmp_list_element_24 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[38]);
            }

            if (tmp_list_element_24 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 137;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_49 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_49, 0, tmp_list_element_24);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_49);
            tmp_tuple_element_49 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_49 == NULL)) {
                tmp_tuple_element_49 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_49 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 137;

                goto tuple_build_exception_28;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_49);
            goto tuple_build_noexception_28;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_28:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_28:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[73];
            tmp_list_element_25 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_25 == NULL)) {
                tmp_list_element_25 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_25 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 139;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_50 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_50, 0, tmp_list_element_25);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_50);
            tmp_tuple_element_50 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_tuple_element_50 == NULL)) {
                tmp_tuple_element_50 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_tuple_element_50 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 139;

                goto tuple_build_exception_29;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_50);
            goto tuple_build_noexception_29;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_29:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_29:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[74];
            tmp_list_element_26 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_26 == NULL)) {
                tmp_list_element_26 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_26 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 140;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_51 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_51, 0, tmp_list_element_26);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_51);
            tmp_tuple_element_51 = Py_None;
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_51);
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[75];
            tmp_list_element_27 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_27 == NULL)) {
                tmp_list_element_27 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_27 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 141;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_52 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_52, 0, tmp_list_element_27);
            tmp_list_element_27 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_27 == NULL)) {
                tmp_list_element_27 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_27 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 141;

                goto list_build_exception_10;
            }
            PyList_SET_ITEM0(tmp_tuple_element_52, 1, tmp_list_element_27);
            goto list_build_noexception_10;
            // Exception handling pass through code for list_build:
            list_build_exception_10:;
            Py_DECREF(tmp_tuple_element_52);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_10:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_52);
            tmp_tuple_element_52 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_tuple_element_52 == NULL)) {
                tmp_tuple_element_52 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_tuple_element_52 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 141;

                goto tuple_build_exception_30;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_52);
            goto tuple_build_noexception_30;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_30:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_30:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[76];
            tmp_list_element_28 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_28 == NULL)) {
                tmp_list_element_28 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_28 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 143;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_53 = MAKE_LIST_EMPTY(3);
            PyList_SET_ITEM0(tmp_tuple_element_53, 0, tmp_list_element_28);
            tmp_list_element_28 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_28 == NULL)) {
                tmp_list_element_28 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_28 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 143;

                goto list_build_exception_11;
            }
            PyList_SET_ITEM0(tmp_tuple_element_53, 1, tmp_list_element_28);
            tmp_list_element_28 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_28 == NULL)) {
                tmp_list_element_28 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_28 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 143;

                goto list_build_exception_11;
            }
            PyList_SET_ITEM0(tmp_tuple_element_53, 2, tmp_list_element_28);
            goto list_build_noexception_11;
            // Exception handling pass through code for list_build:
            list_build_exception_11:;
            Py_DECREF(tmp_tuple_element_53);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_11:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_53);
            tmp_tuple_element_53 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_tuple_element_53 == NULL)) {
                tmp_tuple_element_53 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_tuple_element_53 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 144;

                goto tuple_build_exception_31;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_53);
            goto tuple_build_noexception_31;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_31:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_31:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[77];
            tmp_list_element_29 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_29 == NULL)) {
                tmp_list_element_29 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_29 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 146;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_54 = MAKE_LIST_EMPTY(3);
            PyList_SET_ITEM0(tmp_tuple_element_54, 0, tmp_list_element_29);
            tmp_list_element_29 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[10]);

            if (unlikely(tmp_list_element_29 == NULL)) {
                tmp_list_element_29 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[10]);
            }

            if (tmp_list_element_29 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 146;

                goto list_build_exception_12;
            }
            PyList_SET_ITEM0(tmp_tuple_element_54, 1, tmp_list_element_29);
            tmp_list_element_29 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[47]);

            if (unlikely(tmp_list_element_29 == NULL)) {
                tmp_list_element_29 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[47]);
            }

            assert(!(tmp_list_element_29 == NULL));
            PyList_SET_ITEM0(tmp_tuple_element_54, 2, tmp_list_element_29);
            goto list_build_noexception_12;
            // Exception handling pass through code for list_build:
            list_build_exception_12:;
            Py_DECREF(tmp_tuple_element_54);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_12:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_54);
            tmp_tuple_element_54 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_tuple_element_54 == NULL)) {
                tmp_tuple_element_54 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_tuple_element_54 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 146;

                goto tuple_build_exception_32;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_54);
            goto tuple_build_noexception_32;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_32:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_32:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[78];
            tmp_list_element_30 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_30 == NULL)) {
                tmp_list_element_30 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_30 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 147;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_55 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_55, 0, tmp_list_element_30);
            tmp_list_element_30 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_30 == NULL)) {
                tmp_list_element_30 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_30 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 147;

                goto list_build_exception_13;
            }
            PyList_SET_ITEM0(tmp_tuple_element_55, 1, tmp_list_element_30);
            goto list_build_noexception_13;
            // Exception handling pass through code for list_build:
            list_build_exception_13:;
            Py_DECREF(tmp_tuple_element_55);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_13:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_55);
            tmp_tuple_element_55 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_tuple_element_55 == NULL)) {
                tmp_tuple_element_55 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_tuple_element_55 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 147;

                goto tuple_build_exception_33;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_55);
            goto tuple_build_noexception_33;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_33:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_33:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[79];
            tmp_list_element_31 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_31 == NULL)) {
                tmp_list_element_31 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_31 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 148;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_56 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_56, 0, tmp_list_element_31);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_56);
            tmp_tuple_element_56 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_tuple_element_56 == NULL)) {
                tmp_tuple_element_56 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_tuple_element_56 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 148;

                goto tuple_build_exception_34;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_56);
            goto tuple_build_noexception_34;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_34:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_34:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[80];
            tmp_list_element_32 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_32 == NULL)) {
                tmp_list_element_32 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_32 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 149;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_57 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_57, 0, tmp_list_element_32);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_57);
            tmp_tuple_element_57 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_tuple_element_57 == NULL)) {
                tmp_tuple_element_57 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_tuple_element_57 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 149;

                goto tuple_build_exception_35;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_57);
            goto tuple_build_noexception_35;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_35:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_35:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[81];
            tmp_list_element_33 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_33 == NULL)) {
                tmp_list_element_33 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_33 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 151;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_58 = MAKE_LIST_EMPTY(3);
            PyList_SET_ITEM0(tmp_tuple_element_58, 0, tmp_list_element_33);
            tmp_list_element_33 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_33 == NULL)) {
                tmp_list_element_33 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_33 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 151;

                goto list_build_exception_14;
            }
            PyList_SET_ITEM0(tmp_tuple_element_58, 1, tmp_list_element_33);
            tmp_list_element_33 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_33 == NULL)) {
                tmp_list_element_33 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_33 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 151;

                goto list_build_exception_14;
            }
            PyList_SET_ITEM0(tmp_tuple_element_58, 2, tmp_list_element_33);
            goto list_build_noexception_14;
            // Exception handling pass through code for list_build:
            list_build_exception_14:;
            Py_DECREF(tmp_tuple_element_58);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_14:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_58);
            tmp_tuple_element_58 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_tuple_element_58 == NULL)) {
                tmp_tuple_element_58 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_tuple_element_58 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 152;

                goto tuple_build_exception_36;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_58);
            goto tuple_build_noexception_36;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_36:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_36:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[82];
            tmp_list_element_34 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_34 == NULL)) {
                tmp_list_element_34 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_34 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 154;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_59 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_59, 0, tmp_list_element_34);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_59);
            tmp_tuple_element_59 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_59 == NULL)) {
                tmp_tuple_element_59 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_59 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 154;

                goto tuple_build_exception_37;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_59);
            goto tuple_build_noexception_37;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_37:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_37:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[83];
            tmp_list_element_35 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_35 == NULL)) {
                tmp_list_element_35 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_35 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 155;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_60 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_60, 0, tmp_list_element_35);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_60);
            tmp_tuple_element_60 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_60 == NULL)) {
                tmp_tuple_element_60 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_60 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 155;

                goto tuple_build_exception_38;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_60);
            goto tuple_build_noexception_38;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_38:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_38:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[84];
            tmp_list_element_36 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_36 == NULL)) {
                tmp_list_element_36 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_36 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 156;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_61 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_61, 0, tmp_list_element_36);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_61);
            tmp_tuple_element_61 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_61 == NULL)) {
                tmp_tuple_element_61 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_61 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 156;

                goto tuple_build_exception_39;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_61);
            goto tuple_build_noexception_39;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_39:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_39:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[85];
            tmp_list_element_37 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_37 == NULL)) {
                tmp_list_element_37 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_37 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 157;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_62 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_62, 0, tmp_list_element_37);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_62);
            tmp_tuple_element_62 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_62 == NULL)) {
                tmp_tuple_element_62 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_62 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 157;

                goto tuple_build_exception_40;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_62);
            goto tuple_build_noexception_40;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_40:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_40:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[86];
            tmp_list_element_38 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_38 == NULL)) {
                tmp_list_element_38 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_38 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 158;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_63 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_63, 0, tmp_list_element_38);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_63);
            tmp_tuple_element_63 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_63 == NULL)) {
                tmp_tuple_element_63 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_63 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 158;

                goto tuple_build_exception_41;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_63);
            goto tuple_build_noexception_41;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_41:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_41:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[87];
            tmp_list_element_39 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_39 == NULL)) {
                tmp_list_element_39 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_39 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 159;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_64 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_64, 0, tmp_list_element_39);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_64);
            tmp_tuple_element_64 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_64 == NULL)) {
                tmp_tuple_element_64 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_64 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 159;

                goto tuple_build_exception_42;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_64);
            goto tuple_build_noexception_42;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_42:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_42:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[88];
            tmp_list_element_40 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_40 == NULL)) {
                tmp_list_element_40 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_40 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 160;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_65 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_65, 0, tmp_list_element_40);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_65);
            tmp_tuple_element_65 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_65 == NULL)) {
                tmp_tuple_element_65 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_65 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 160;

                goto tuple_build_exception_43;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_65);
            goto tuple_build_noexception_43;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_43:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_43:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[89];
            tmp_list_element_41 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_41 == NULL)) {
                tmp_list_element_41 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_41 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 161;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_66 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_66, 0, tmp_list_element_41);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_66);
            tmp_tuple_element_66 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_66 == NULL)) {
                tmp_tuple_element_66 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_66 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 161;

                goto tuple_build_exception_44;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_66);
            goto tuple_build_noexception_44;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_44:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_44:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[90];
            tmp_list_element_42 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_42 == NULL)) {
                tmp_list_element_42 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_42 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 162;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_67 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_67, 0, tmp_list_element_42);
            tmp_list_element_42 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_42 == NULL)) {
                tmp_list_element_42 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_42 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 162;

                goto list_build_exception_15;
            }
            PyList_SET_ITEM0(tmp_tuple_element_67, 1, tmp_list_element_42);
            goto list_build_noexception_15;
            // Exception handling pass through code for list_build:
            list_build_exception_15:;
            Py_DECREF(tmp_tuple_element_67);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_15:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_67);
            tmp_tuple_element_67 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_67 == NULL)) {
                tmp_tuple_element_67 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_67 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 162;

                goto tuple_build_exception_45;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_67);
            goto tuple_build_noexception_45;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_45:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_45:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[91];
            tmp_list_element_43 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_43 == NULL)) {
                tmp_list_element_43 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_43 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 163;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_68 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_68, 0, tmp_list_element_43);
            tmp_list_element_43 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_43 == NULL)) {
                tmp_list_element_43 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_43 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 163;

                goto list_build_exception_16;
            }
            PyList_SET_ITEM0(tmp_tuple_element_68, 1, tmp_list_element_43);
            goto list_build_noexception_16;
            // Exception handling pass through code for list_build:
            list_build_exception_16:;
            Py_DECREF(tmp_tuple_element_68);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_16:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_68);
            tmp_tuple_element_68 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_68 == NULL)) {
                tmp_tuple_element_68 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_68 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 163;

                goto tuple_build_exception_46;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_68);
            goto tuple_build_noexception_46;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_46:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_46:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[92];
            tmp_list_element_44 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_44 == NULL)) {
                tmp_list_element_44 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_44 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 164;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_69 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_69, 0, tmp_list_element_44);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_69);
            tmp_tuple_element_69 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[47]);

            if (unlikely(tmp_tuple_element_69 == NULL)) {
                tmp_tuple_element_69 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[47]);
            }

            assert(!(tmp_tuple_element_69 == NULL));
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_69);
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[93];
            tmp_list_element_45 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_45 == NULL)) {
                tmp_list_element_45 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_45 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 165;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_70 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_70, 0, tmp_list_element_45);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_70);
            tmp_tuple_element_70 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_tuple_element_70 == NULL)) {
                tmp_tuple_element_70 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_tuple_element_70 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 165;

                goto tuple_build_exception_47;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_70);
            goto tuple_build_noexception_47;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_47:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_47:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[94];
            tmp_list_element_46 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_46 == NULL)) {
                tmp_list_element_46 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_46 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 166;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_71 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_71, 0, tmp_list_element_46);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_71);
            tmp_tuple_element_71 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[14]);

            if (unlikely(tmp_tuple_element_71 == NULL)) {
                tmp_tuple_element_71 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[14]);
            }

            if (tmp_tuple_element_71 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 166;

                goto tuple_build_exception_48;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_71);
            goto tuple_build_noexception_48;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_48:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_48:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[95];
            tmp_list_element_47 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_47 == NULL)) {
                tmp_list_element_47 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_47 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 167;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_72 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_72, 0, tmp_list_element_47);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_72);
            tmp_tuple_element_72 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_72 == NULL)) {
                tmp_tuple_element_72 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_72 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 167;

                goto tuple_build_exception_49;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_72);
            goto tuple_build_noexception_49;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_49:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_49:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[96];
            tmp_list_element_48 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_48 == NULL)) {
                tmp_list_element_48 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_48 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 168;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_73 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_73, 0, tmp_list_element_48);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_73);
            tmp_tuple_element_73 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[14]);

            if (unlikely(tmp_tuple_element_73 == NULL)) {
                tmp_tuple_element_73 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[14]);
            }

            if (tmp_tuple_element_73 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 168;

                goto tuple_build_exception_50;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_73);
            goto tuple_build_noexception_50;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_50:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_50:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[97];
            tmp_list_element_49 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_49 == NULL)) {
                tmp_list_element_49 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_49 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 169;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_74 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_74, 0, tmp_list_element_49);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_74);
            tmp_tuple_element_74 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38]);

            if (unlikely(tmp_tuple_element_74 == NULL)) {
                tmp_tuple_element_74 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[38]);
            }

            if (tmp_tuple_element_74 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 169;

                goto tuple_build_exception_51;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_74);
            goto tuple_build_noexception_51;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_51:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_51:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[98];
            tmp_list_element_50 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_50 == NULL)) {
                tmp_list_element_50 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_50 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 170;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_75 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_75, 0, tmp_list_element_50);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_75);
            tmp_tuple_element_75 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38]);

            if (unlikely(tmp_tuple_element_75 == NULL)) {
                tmp_tuple_element_75 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[38]);
            }

            if (tmp_tuple_element_75 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 170;

                goto tuple_build_exception_52;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_75);
            goto tuple_build_noexception_52;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_52:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_52:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[99];
            tmp_list_element_51 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_51 == NULL)) {
                tmp_list_element_51 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_51 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 171;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_76 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_76, 0, tmp_list_element_51);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_76);
            tmp_tuple_element_76 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38]);

            if (unlikely(tmp_tuple_element_76 == NULL)) {
                tmp_tuple_element_76 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[38]);
            }

            if (tmp_tuple_element_76 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 171;

                goto tuple_build_exception_53;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_76);
            goto tuple_build_noexception_53;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_53:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_53:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[100];
            tmp_list_element_52 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_52 == NULL)) {
                tmp_list_element_52 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_52 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 172;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_77 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_77, 0, tmp_list_element_52);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_77);
            tmp_tuple_element_77 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38]);

            if (unlikely(tmp_tuple_element_77 == NULL)) {
                tmp_tuple_element_77 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[38]);
            }

            if (tmp_tuple_element_77 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 172;

                goto tuple_build_exception_54;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_77);
            goto tuple_build_noexception_54;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_54:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_54:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[101];
            tmp_list_element_53 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_53 == NULL)) {
                tmp_list_element_53 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_53 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 173;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_78 = MAKE_LIST_EMPTY(3);
            PyList_SET_ITEM0(tmp_tuple_element_78, 0, tmp_list_element_53);
            tmp_list_element_53 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_53 == NULL)) {
                tmp_list_element_53 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_53 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 173;

                goto list_build_exception_17;
            }
            PyList_SET_ITEM0(tmp_tuple_element_78, 1, tmp_list_element_53);
            tmp_list_element_53 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_53 == NULL)) {
                tmp_list_element_53 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_53 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 173;

                goto list_build_exception_17;
            }
            PyList_SET_ITEM0(tmp_tuple_element_78, 2, tmp_list_element_53);
            goto list_build_noexception_17;
            // Exception handling pass through code for list_build:
            list_build_exception_17:;
            Py_DECREF(tmp_tuple_element_78);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_17:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_78);
            tmp_tuple_element_78 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_78 == NULL)) {
                tmp_tuple_element_78 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_78 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 173;

                goto tuple_build_exception_55;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_78);
            goto tuple_build_noexception_55;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_55:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_55:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[102];
            tmp_list_element_54 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_list_element_54 == NULL)) {
                tmp_list_element_54 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_list_element_54 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 174;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_79 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_79, 0, tmp_list_element_54);
            tmp_list_element_54 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_54 == NULL)) {
                tmp_list_element_54 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_54 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 174;

                goto list_build_exception_18;
            }
            PyList_SET_ITEM0(tmp_tuple_element_79, 1, tmp_list_element_54);
            goto list_build_noexception_18;
            // Exception handling pass through code for list_build:
            list_build_exception_18:;
            Py_DECREF(tmp_tuple_element_79);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_18:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_79);
            tmp_tuple_element_79 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_79 == NULL)) {
                tmp_tuple_element_79 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_79 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 174;

                goto tuple_build_exception_56;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_79);
            goto tuple_build_noexception_56;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_56:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_56:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[103];
            tmp_list_element_55 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_list_element_55 == NULL)) {
                tmp_list_element_55 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_list_element_55 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 176;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_80 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_80, 0, tmp_list_element_55);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_80);
            tmp_tuple_element_80 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_tuple_element_80 == NULL)) {
                tmp_tuple_element_80 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_tuple_element_80 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 176;

                goto tuple_build_exception_57;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_80);
            goto tuple_build_noexception_57;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_57:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_57:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[104];
            tmp_list_element_56 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_list_element_56 == NULL)) {
                tmp_list_element_56 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_list_element_56 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 177;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_81 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_81, 0, tmp_list_element_56);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_81);
            tmp_tuple_element_81 = Py_None;
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_81);
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[105];
            tmp_list_element_57 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_57 == NULL)) {
                tmp_list_element_57 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_57 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 178;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_82 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_82, 0, tmp_list_element_57);
            tmp_list_element_57 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_57 == NULL)) {
                tmp_list_element_57 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_57 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 178;

                goto list_build_exception_19;
            }
            PyList_SET_ITEM0(tmp_tuple_element_82, 1, tmp_list_element_57);
            goto list_build_noexception_19;
            // Exception handling pass through code for list_build:
            list_build_exception_19:;
            Py_DECREF(tmp_tuple_element_82);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_19:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_82);
            tmp_tuple_element_82 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_tuple_element_82 == NULL)) {
                tmp_tuple_element_82 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_tuple_element_82 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 178;

                goto tuple_build_exception_58;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_82);
            goto tuple_build_noexception_58;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_58:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_58:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[106];
            tmp_list_element_58 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_list_element_58 == NULL)) {
                tmp_list_element_58 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_list_element_58 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 179;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_83 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_83, 0, tmp_list_element_58);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_83);
            tmp_tuple_element_83 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_83 == NULL)) {
                tmp_tuple_element_83 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_83 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 179;

                goto tuple_build_exception_59;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_83);
            goto tuple_build_noexception_59;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_59:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_59:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[107];
            tmp_list_element_59 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_list_element_59 == NULL)) {
                tmp_list_element_59 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_list_element_59 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 180;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_84 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_84, 0, tmp_list_element_59);
            tmp_list_element_59 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_list_element_59 == NULL)) {
                tmp_list_element_59 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_list_element_59 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 180;

                goto list_build_exception_20;
            }
            PyList_SET_ITEM0(tmp_tuple_element_84, 1, tmp_list_element_59);
            goto list_build_noexception_20;
            // Exception handling pass through code for list_build:
            list_build_exception_20:;
            Py_DECREF(tmp_tuple_element_84);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_20:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_84);
            tmp_tuple_element_84 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_84 == NULL)) {
                tmp_tuple_element_84 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_84 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 180;

                goto tuple_build_exception_60;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_84);
            goto tuple_build_noexception_60;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_60:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_60:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[108];
            tmp_list_element_60 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_list_element_60 == NULL)) {
                tmp_list_element_60 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_list_element_60 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 181;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_85 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_85, 0, tmp_list_element_60);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_85);
            tmp_tuple_element_85 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_85 == NULL)) {
                tmp_tuple_element_85 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_85 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 181;

                goto tuple_build_exception_61;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_85);
            goto tuple_build_noexception_61;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_61:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_61:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[109];
            tmp_list_element_61 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_list_element_61 == NULL)) {
                tmp_list_element_61 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_list_element_61 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 182;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_86 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_86, 0, tmp_list_element_61);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_86);
            tmp_tuple_element_86 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[41]);

            if (unlikely(tmp_tuple_element_86 == NULL)) {
                tmp_tuple_element_86 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[41]);
            }

            if (tmp_tuple_element_86 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 182;

                goto tuple_build_exception_62;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_86);
            goto tuple_build_noexception_62;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_62:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_62:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[110];
            tmp_list_element_62 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_list_element_62 == NULL)) {
                tmp_list_element_62 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_list_element_62 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 184;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_87 = MAKE_LIST_EMPTY(3);
            PyList_SET_ITEM0(tmp_tuple_element_87, 0, tmp_list_element_62);
            tmp_list_element_62 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_62 == NULL)) {
                tmp_list_element_62 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_62 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 184;

                goto list_build_exception_21;
            }
            PyList_SET_ITEM0(tmp_tuple_element_87, 1, tmp_list_element_62);
            tmp_list_element_62 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_62 == NULL)) {
                tmp_list_element_62 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_62 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 184;

                goto list_build_exception_21;
            }
            PyList_SET_ITEM0(tmp_tuple_element_87, 2, tmp_list_element_62);
            goto list_build_noexception_21;
            // Exception handling pass through code for list_build:
            list_build_exception_21:;
            Py_DECREF(tmp_tuple_element_87);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_21:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_87);
            tmp_tuple_element_87 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_87 == NULL)) {
                tmp_tuple_element_87 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_87 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 185;

                goto tuple_build_exception_63;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_87);
            goto tuple_build_noexception_63;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_63:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_63:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[111];
            tmp_list_element_63 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_list_element_63 == NULL)) {
                tmp_list_element_63 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_list_element_63 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 187;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_88 = MAKE_LIST_EMPTY(2);
            PyList_SET_ITEM0(tmp_tuple_element_88, 0, tmp_list_element_63);
            tmp_list_element_63 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_63 == NULL)) {
                tmp_list_element_63 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_63 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 187;

                goto list_build_exception_22;
            }
            PyList_SET_ITEM0(tmp_tuple_element_88, 1, tmp_list_element_63);
            goto list_build_noexception_22;
            // Exception handling pass through code for list_build:
            list_build_exception_22:;
            Py_DECREF(tmp_tuple_element_88);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_22:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_88);
            tmp_tuple_element_88 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_88 == NULL)) {
                tmp_tuple_element_88 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_88 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 187;

                goto tuple_build_exception_64;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_88);
            goto tuple_build_noexception_64;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_64:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_64:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[112];
            tmp_list_element_64 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_list_element_64 == NULL)) {
                tmp_list_element_64 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_list_element_64 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 188;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_89 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_89, 0, tmp_list_element_64);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_89);
            tmp_tuple_element_89 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_89 == NULL)) {
                tmp_tuple_element_89 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_89 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 188;

                goto tuple_build_exception_65;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_89);
            goto tuple_build_noexception_65;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_65:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_65:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[113];
            tmp_list_element_65 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[43]);

            if (unlikely(tmp_list_element_65 == NULL)) {
                tmp_list_element_65 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[43]);
            }

            if (tmp_list_element_65 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 189;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_90 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_90, 0, tmp_list_element_65);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_90);
            tmp_tuple_element_90 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[12]);

            if (unlikely(tmp_tuple_element_90 == NULL)) {
                tmp_tuple_element_90 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[12]);
            }

            if (tmp_tuple_element_90 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 189;

                goto tuple_build_exception_66;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_90);
            goto tuple_build_noexception_66;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_66:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_66:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[114];
            tmp_list_element_66 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[46]);

            if (unlikely(tmp_list_element_66 == NULL)) {
                tmp_list_element_66 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[46]);
            }

            assert(!(tmp_list_element_66 == NULL));
            tmp_tuple_element_91 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_91, 0, tmp_list_element_66);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_91);
            tmp_tuple_element_91 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[46]);

            if (unlikely(tmp_tuple_element_91 == NULL)) {
                tmp_tuple_element_91 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[46]);
            }

            assert(!(tmp_tuple_element_91 == NULL));
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_91);
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[115];
            tmp_list_element_67 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[46]);

            if (unlikely(tmp_list_element_67 == NULL)) {
                tmp_list_element_67 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[46]);
            }

            assert(!(tmp_list_element_67 == NULL));
            tmp_tuple_element_92 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_92, 0, tmp_list_element_67);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_92);
            tmp_tuple_element_92 = Py_None;
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_92);
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[116];
            tmp_list_element_68 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[32]);

            if (unlikely(tmp_list_element_68 == NULL)) {
                tmp_list_element_68 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[32]);
            }

            if (tmp_list_element_68 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 193;

                goto dict_build_exception_1;
            }
            tmp_tuple_element_93 = MAKE_LIST_EMPTY(1);
            PyList_SET_ITEM0(tmp_tuple_element_93, 0, tmp_list_element_68);
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_93);
            tmp_tuple_element_93 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[46]);

            if (unlikely(tmp_tuple_element_93 == NULL)) {
                tmp_tuple_element_93 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[46]);
            }

            assert(!(tmp_tuple_element_93 == NULL));
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_93);
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
            tmp_dict_key_1 = mod_consts[117];
            tmp_list_element_69 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[46]);

            if (unlikely(tmp_list_element_69 == NULL)) {
                tmp_list_element_69 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[46]);
            }

            assert(!(tmp_list_element_69 == NULL));
            tmp_tuple_element_94 = MAKE_LIST_EMPTY(3);
            PyList_SET_ITEM0(tmp_tuple_element_94, 0, tmp_list_element_69);
            tmp_list_element_69 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[11]);

            if (unlikely(tmp_list_element_69 == NULL)) {
                tmp_list_element_69 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[11]);
            }

            if (tmp_list_element_69 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 195;

                goto list_build_exception_23;
            }
            PyList_SET_ITEM0(tmp_tuple_element_94, 1, tmp_list_element_69);
            tmp_list_element_69 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[13]);

            if (unlikely(tmp_list_element_69 == NULL)) {
                tmp_list_element_69 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[13]);
            }

            if (tmp_list_element_69 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 195;

                goto list_build_exception_23;
            }
            PyList_SET_ITEM0(tmp_tuple_element_94, 2, tmp_list_element_69);
            goto list_build_noexception_23;
            // Exception handling pass through code for list_build:
            list_build_exception_23:;
            Py_DECREF(tmp_tuple_element_94);
            goto dict_build_exception_1;
            // Finished with no exception for list_build:
            list_build_noexception_23:;
            tmp_dict_value_1 = MAKE_TUPLE_EMPTY(2);
            PyTuple_SET_ITEM(tmp_dict_value_1, 0, tmp_tuple_element_94);
            tmp_tuple_element_94 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[38]);

            if (unlikely(tmp_tuple_element_94 == NULL)) {
                tmp_tuple_element_94 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[38]);
            }

            if (tmp_tuple_element_94 == NULL) {
                assert(HAS_ERROR_OCCURRED(tstate));

                FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


                exception_lineno = 196;

                goto tuple_build_exception_67;
            }
            PyTuple_SET_ITEM0(tmp_dict_value_1, 1, tmp_tuple_element_94);
            goto tuple_build_noexception_67;
            // Exception handling pass through code for tuple_build:
            tuple_build_exception_67:;
            Py_DECREF(tmp_dict_value_1);
            goto dict_build_exception_1;
            // Finished with no exception for tuple_build:
            tuple_build_noexception_67:;
            tmp_res = PyDict_SetItem(tmp_assign_source_71, tmp_dict_key_1, tmp_dict_value_1);
            Py_DECREF(tmp_dict_value_1);
            assert(!(tmp_res != 0));
        }
        goto dict_build_noexception_1;
        // Exception handling pass through code for dict_build:
        dict_build_exception_1:;
        Py_DECREF(tmp_assign_source_71);
        goto frame_exception_exit_1;
        // Finished with no exception for dict_build:
        dict_build_noexception_1:;
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[118], tmp_assign_source_71);
    }
    {
        PyObject *tmp_assign_source_72;
        PyObject *tmp_dict_key_2;
        PyObject *tmp_dict_value_2;
        tmp_dict_key_2 = mod_consts[93];
        tmp_dict_value_2 = Py_None;
        tmp_assign_source_72 = _PyDict_NewPresized( 70 );
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[97];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[89];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[92];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[82];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[88];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[87];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[95];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[80];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[81];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[99];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[90];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[94];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[83];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[100];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[91];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[86];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[85];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[84];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[98];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[96];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[102];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[78];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[77];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[79];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[76];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[75];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[73];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[74];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[101];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 230;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[66];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 231;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[59];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 232;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[60];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 233;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[61];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 234;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[62];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 235;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[63];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 236;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[64];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 237;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[65];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 238;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[67];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 239;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[69];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[56];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[57];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[68];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[58];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[52];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[54];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[53];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[51];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[117];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[116];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[114];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[115];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[71];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[70];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[72];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[107];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[18]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[18]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 256;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[106];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[18]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[18]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 259;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[109];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[19]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[19]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 260;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[103];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[110];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 262;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[111];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[20]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[20]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 263;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[112];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[18]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[18]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 264;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[113];
        tmp_dict_value_2 = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[18]);

        if (unlikely(tmp_dict_value_2 == NULL)) {
            tmp_dict_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(tstate, mod_consts[18]);
        }

        if (tmp_dict_value_2 == NULL) {
            assert(HAS_ERROR_OCCURRED(tstate));

            FETCH_ERROR_OCCURRED(tstate, &exception_type, &exception_value, &exception_tb);


            exception_lineno = 265;

            goto dict_build_exception_2;
        }
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[108];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[105];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[104];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[48];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[50];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[55];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        tmp_dict_key_2 = mod_consts[49];
        tmp_dict_value_2 = Py_None;
        tmp_res = PyDict_SetItem(tmp_assign_source_72, tmp_dict_key_2, tmp_dict_value_2);
        assert(!(tmp_res != 0));
        goto dict_build_noexception_2;
        // Exception handling pass through code for dict_build:
        dict_build_exception_2:;
        Py_DECREF(tmp_assign_source_72);
        goto frame_exception_exit_1;
        // Finished with no exception for dict_build:
        dict_build_noexception_2:;
        UPDATE_STRING_DICT1(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)mod_consts[119], tmp_assign_source_72);
    }


    // Put the previous frame back on top.
    popFrameStack(tstate);

    goto frame_no_exception_1;
    frame_exception_exit_1:


    if (exception_tb == NULL) {
        exception_tb = MAKE_TRACEBACK(frame_e59f6b39efaed77d0ee6049d7354ed8b, exception_lineno);
    } else if (exception_tb->tb_frame != &frame_e59f6b39efaed77d0ee6049d7354ed8b->m_frame) {
        exception_tb = ADD_TRACEBACK(exception_tb, frame_e59f6b39efaed77d0ee6049d7354ed8b, exception_lineno);
    }



    assertFrameObject(frame_e59f6b39efaed77d0ee6049d7354ed8b);

    // Put the previous frame back on top.
    popFrameStack(tstate);

    // Return the error.
    goto module_exception_exit;
    frame_no_exception_1:;

    // Report to PGO about leaving the module without error.
    PGO_onModuleExit("pyudev._ctypeslib.libudev", false);

    Py_INCREF(module_pyudev$_ctypeslib$libudev);
    return module_pyudev$_ctypeslib$libudev;
    module_exception_exit:

#if defined(_NUITKA_MODULE) && 0
    {
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_pyudev$_ctypeslib$libudev, (Nuitka_StringObject *)const_str_plain___name__);

        if (module_name != NULL) {
            Nuitka_DelModule(tstate, module_name);
        }
    }
#endif
    PGO_onModuleExit("pyudev$_ctypeslib$libudev", false);

    RESTORE_ERROR_OCCURRED(tstate, exception_type, exception_value, exception_tb);
    return NULL;
}
