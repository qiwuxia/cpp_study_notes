#include "C:\Users\24018\AppData\Local\Programs\Python\Python311\include\Python.h"
#include <conio.h>
#include <stdio.h>
//#include <Python.h>

int main()

{


    Py_Initialize();

    PyRun_SimpleString("print('Hello World from Embedded Python!!!')");

    Py_Finalize();



    return 0;
}