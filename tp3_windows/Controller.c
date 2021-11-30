#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"

static int saveId(char* PATH, int auxId);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno =-1;

	FILE* pFile;
		if(path!=NULL && pArrayListEmployee!=NULL)
		    {
		       pFile = fopen (path, "r");
		       if(pFile!=NULL && pArrayListEmployee != NULL)
		            {
		     	   	   parser_EmployeeFromText(pFile,pArrayListEmployee);
		    	   	   retorno =0;
		            }
		        fclose(pFile);
		    }

	    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)

{

	int retorno = -1;

	FILE*pFile = fopen(path, "rb");

	if (pFile != NULL)
	{

		retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	}

	return retorno;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno =-1;
	int idAsignar;

	if(ll_add(pArrayListEmployee,CrearNuevoEmpleado(&idAsignar))==0)
	{
		saveId("ArchivoId.txt", idAsignar);
		retorno = 0;
	}

	return retorno;
}





/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

		int retorno = -1;

		int id;
		int idAEditar;
		char nombre[50];
		int horasTrabajadas;
		int sueldo;
		int tamLista;
		char idMax[10];
		int idIntMax;
		if(UltimoId("ArchivoId.txt", idMax)!=-1)
			{
			 idIntMax=atoi(idMax);
			}

		Employee*empleadoAux = employee_new();

		if (pArrayListEmployee != NULL)
		{
			tamLista = ll_len(pArrayListEmployee);

			idAEditar = PedirUnEnteroRango("Ingrese id a editar", 0, idIntMax);


		for (int i = 0; i < tamLista; i++)
			{
				empleadoAux = (Employee*) ll_get(pArrayListEmployee, i);

				retorno = employee_getId(empleadoAux, &id);

				if (retorno != -1)
				{
					if (id == idAEditar)
					{
						imprimirUnEmpleado(empleadoAux);
						int menu;
		do
			{
				menu = PedirUnEnteroRango("\nQue Dato Desea Modificar?\n"
										  "1. Nombre\n"
										  "2. Horas trabajadas\n"
										  "3. Sueldo\n"
										  "0. Salir\n", 0, 3);

			switch (menu)
				{

				case 1:

						PedirCadena(nombre, "Ingrese el nombre", "Error");
						if(employee_setNombre(empleadoAux, nombre)!=-1)
							{
								printf("Nombre modificado correctamente \n");
							}
						break;
				case 2:
						horasTrabajadas = PedirUnEnteroRango("Ingrese horas trabajadas", 0, 1000);
						if(employee_setHorasTrabajadas(empleadoAux, horasTrabajadas)!=-1)
							{
								printf("Horas trabajadas modificadas correctamente \n");
							}

						break;

				case 3:
						sueldo = PedirUnEnteroRango("Ingrese el sueldo", 1, 800000);
						if(employee_setSueldo(empleadoAux, sueldo)!=-1)
							{
								printf("Sueldo modificado Exitosamente \n");
							}

						break;
				}



				}while(menu!=0);

					retorno = ll_set(pArrayListEmployee, i, empleadoAux);
						break;
					}
				}
				else
				{
					free(empleadoAux);
				}
			}
		}
		else
		{
			printf("No hay Datos\n\n");
		}

		return retorno;
	}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
		int retorno = -1;

		char seguir;
		int id = 0;
		int tamLista;
		int idABorrar;

		char idMax[10];
		int idIntMax;

		if(UltimoId("ArchivoId.txt", idMax)!=-1)
		{
			idIntMax=atoi(idMax);
		}



		if (pArrayListEmployee != NULL)
		{
			Employee* auxEmpleado;
			tamLista = ll_len(pArrayListEmployee);

			idABorrar = PedirUnEnteroRango("Ingrese la id a eliminar", 0, idIntMax);

			for (int i = 0; i < tamLista; i++)
			{

			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);//Trae un empleado

		    employee_getId(auxEmpleado, &id);

			if (id == idABorrar)
				{
					imprimirUnEmpleado(auxEmpleado);


					fflush(stdin);
					PedirCadena(&seguir," Confimar borrado s/n:","Error");

					if (seguir == 'n')
					{
						printf("Baja cancelada \n");
					}
					else
					{
					if(seguir == 's')
					{
						ll_remove(pArrayListEmployee, i);
						employee_delete(auxEmpleado);
						retorno = 0;
					}
					}
					break;

				}
			}
		}

		return retorno;
}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int len;
	Employee* empAux;

	retorno =-1;
	printf("\nID\t\tNOMBRE\t\tHORAS TRABAJADAS\tSUELDO\n");

	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL)
	{
	    for(int i=0;i<len;i++)
			{
	    	empAux =(Employee*)ll_get(pArrayListEmployee, i);
			imprimirUnEmpleado(empAux);
			retorno =0;
			}
	}
	printf("\nID\t\tNOMBRE\t\tHORAS TRABAJADAS\tSUELDO\n");

    return retorno;
}




/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		int menu;

		if (pArrayListEmployee != NULL)
		{

			menu = MostrarMenuB();
			switch (menu)
			{
			case 1:

				ll_sort(pArrayListEmployee, empleado_CompararPorId, 1);
				controller_ListEmployee(pArrayListEmployee);
				break;
			case 2:
				ll_sort(pArrayListEmployee, empleado_CompararPorId, 0);
				controller_ListEmployee(pArrayListEmployee);

				break;
			case 3:
				ll_sort(pArrayListEmployee, empleado_CompararPorNombre, 1);
				controller_ListEmployee(pArrayListEmployee);

				break;
			case 4:
				ll_sort(pArrayListEmployee, empleado_CompararPorNombre, 0);
				controller_ListEmployee(pArrayListEmployee);

				break;
			case 5:
				ll_sort(pArrayListEmployee, empleado_CompararPorHorasTrabajadas, 1);
				controller_ListEmployee(pArrayListEmployee);
				break;
			case 6:
				ll_sort(pArrayListEmployee, empleado_CompararPorHorasTrabajadas, 0);
				controller_ListEmployee(pArrayListEmployee);
				break;
			case 7:
				ll_sort(pArrayListEmployee, empleado_CompararPorSueldo, 1);
				controller_ListEmployee(pArrayListEmployee);
				break;
			case 8:
				ll_sort(pArrayListEmployee, empleado_CompararPorSueldo, 0);
				controller_ListEmployee(pArrayListEmployee);
				break;
			}
		}
		else
		{
			printf("No se ingresan datos \n");
		}

		return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int tamLista;
	int id;
	char nombre[20];
	int horasTrabajadas;
	int sueldo;

	  if (path != NULL && pArrayListEmployee != NULL)
	    {

	        tamLista = ll_len(pArrayListEmployee);

	        FILE *pFile = fopen(path, "w");

	        if (pFile != NULL)
	        {

	            Employee* pEmployee = employee_new();


	            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
	            for (int i = 0; i < tamLista; i++)
	            {
	                pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
	                if(employee_getId(pEmployee, &id)!=-1
	                &&employee_getNombre(pEmployee, nombre) !=-1
	                &&employee_getHorasTrabajadas(pEmployee, &horasTrabajadas) !=-1
	                &&employee_getSueldo(pEmployee, &sueldo) !=-1)
	                {
	                	fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,
	                    horasTrabajadas, sueldo);
	                }

	            }
	            retorno = 0;
	            fclose(pFile);
	        }

	    }

	    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

	int retorno = -1;

	FILE* pFile;

	pFile = fopen(path, "wb"); // escribe en binario

	Employee* empleado;

	int tamLista = ll_len(pArrayListEmployee);

	if (pArrayListEmployee != NULL)
	{
		for (int i = 0; i < tamLista; i++)
		{
			empleado = (Employee*) ll_get(pArrayListEmployee, i);

			fwrite(empleado, sizeof(Employee), 1, pFile);
		}

		fclose(pFile);

		retorno = 0;

	}
	else
	{
		printf("No hay Datos\n");
	}

	return retorno;
}



static int saveId(char* PATH, int auxId)
{
	int retorno;
	retorno =-1;
	FILE* pFile;

	if(PATH != NULL)
	{

		pFile= fopen(PATH,"w");
		if (pFile!=NULL)
		{
			fprintf(pFile,"%d",auxId);
			retorno = 0;
			fclose(pFile);
		}

	}

	return retorno;
}



