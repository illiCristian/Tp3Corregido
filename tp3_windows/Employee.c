#include "Employee.h"


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmpleado;

	pEmpleado = employee_new();

	if (pEmpleado != NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
		{
			if (
				employee_setId(pEmpleado,atoi(idStr))!= 0 ||
		        employee_setNombre(pEmpleado,nombreStr) != 0 ||
		        employee_setHorasTrabajadas(pEmpleado,atoi(horasTrabajadasStr))!=0||
		        employee_setSueldo(pEmpleado,atoi(sueldoStr))!=0 )
			{
				employee_delete(pEmpleado);

			}
		}


	return pEmpleado;
}

int employee_setId(Employee* this,int id)
{
	int retorno;
	retorno = -1;

	if(this !=NULL && id > 0)
	{
		this->id =id;
		retorno = 0;
	}


	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno;
	retorno = -1;
	if(this!=NULL && id !=NULL)
	{
		*id = this->id;
		retorno=0;
	}

	return retorno;
}


int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno =-1;

	    if(this!=NULL && nombre!=NULL)
	    {
	        strcpy(this->nombre,nombre);
	        retorno = 0;;
	    }

	    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno =-1;
	if(this!=NULL && nombre!=NULL)
	    {
	        strcpy(nombre,this->nombre);
	        retorno = 0;
	    }

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;
	retorno =-1;

	if(this!=NULL)
	{
	     this->horasTrabajadas = horasTrabajadas;
	     retorno = 0;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;
	retorno =-1;

	if (this!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}


	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;
	retorno =-1;
	if (this!=NULL)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno =-1;
	if (this!=NULL)
	{
		*sueldo= this->sueldo;
		retorno = 0;
	}
	return retorno;
}

Employee* employee_new()
{
	Employee* pEmployee;

	pEmployee = (Employee*) calloc(sizeof(Employee),1);

	return pEmployee;
}

void employee_delete(Employee* this)
{
	if(this!=NULL)
	    {
	        free(this);
	        this=NULL;
	    }
}

void imprimirUnEmpleado(Employee* this)
{
	int id;
	char nombre[20];
	int horasTrabajadas;
	int sueldo;
	if (this != NULL)
	{
	   if(employee_getId(this, &id)!=-1
		  &&employee_getNombre(this, nombre) !=-1
		  &&employee_getHorasTrabajadas(this, &horasTrabajadas) !=-1
		  &&employee_getSueldo(this, &sueldo) !=-1)
		{

		    printf("%d\t%15s\t\t\t%d\t\t%d\n",id,nombre,horasTrabajadas,sueldo);
		}
	}
}
//--------------------------------------------------------------------------
Employee* CrearNuevoEmpleado(int* idAsignar)
{
	Employee* pEmployee;
	char nombre[51];
	char horasTrabajadas[10];
	char sueldo[10];
	char nuevaId[10];
	int  auxId;

	pEmployee = NULL;

	PedirCadena(nombre, "Ingrese el nombre","Error");
	PedirCadenaB(sueldo, "Ingrese el sueldo");
	PedirCadenaB(horasTrabajadas, "Ingrese las horas trabajadas");

	UltimoId("ArchivoId.txt",nuevaId);
	auxId = atoi(nuevaId)+1;

	itoa(auxId,nuevaId,10);

	printf("%d",auxId);

	pEmployee = employee_newParametros(nuevaId,nombre,horasTrabajadas,sueldo);
	if(pEmployee != NULL)
	{
		*idAsignar = auxId;
	}

	return pEmployee;
}



int UltimoId(char* PATH, char* cadena)
{
	int retorno;
	retorno =-1;
	FILE* pFile;

	if(PATH != NULL)
	{
		pFile = fopen(PATH,"r");
		fgets(cadena,10,pFile);
		fclose(pFile);
		retorno = 0;
	}


	return retorno;
}
//-----------------------------------------------------------------------------------------------------
int empleado_CompararPorNombre(void* valor1, void* valor2)
{
	int rtn;

	Employee*e1;
	Employee*e2;

	e1 = (Employee*) valor1;
	e2 = (Employee*) valor2;

	rtn = strcmp(e1->nombre, e2->nombre);

	return rtn;
}
int empleado_CompararPorId(void* valor1, void* valor2)
{
	int retorno = 0;
	Employee*e1;
	Employee*e2;

	e1 = (Employee*) valor1;
	e2 = (Employee*) valor2;

	if (e1->id > e2->id)
	{
		retorno = 1;
	}
	else
	{
		if (e1->id < e2->id)
		{
			retorno = -1;
		}

	}
	return retorno;
}
int empleado_CompararPorSueldo(void* valor1, void* valor2)
{
	int retorno = 0;
	Employee*e1;
	Employee*e2;

	e1 = (Employee*) valor1;
	e2 = (Employee*) valor2;

	if (e1->sueldo > e2->sueldo)
	{
		retorno = 1;
	}
	else
	{
		if (e1->sueldo < e2->sueldo)
		{
			retorno = -1;
		}

	}
	return retorno;
}
int empleado_CompararPorHorasTrabajadas(void* valor1, void* valor2)
{
	int retorno = 0;
	Employee*e1;
	Employee*e2;

	e1 = (Employee*) valor1;
	e2 = (Employee*) valor2;

	if (e1->horasTrabajadas > e2->horasTrabajadas)
	{
		retorno = 1;
	}
	else
	{
		if (e1->horasTrabajadas < e2->horasTrabajadas)
		{
			retorno = -1;
		}

	}
	return retorno;
}
