
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

#include "Input.h"

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void imprimirUnEmpleado(Employee* this);
Employee* CrearNuevoEmpleado(int* idAsignar);
int UltimoId(char* PATH, char* cadena);

int empleado_CompararPorSueldo(void* valor1, void* valor2);
int empleado_CompararPorHorasTrabajadas(void* valor1, void* valor2);
int empleado_CompararPorId(void* valor1, void* valor2);
int empleado_CompararPorNombre(void* valor1, void* valor2);

#endif // employee_H_INCLUDED
