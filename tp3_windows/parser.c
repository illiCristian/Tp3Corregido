#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"
#include "input.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno =-1;
	char id[128];
	char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];
	Employee* pEmployee;
	int contadorLineas;

	 fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

	 while(!feof(pFile))
		    {
		 	 contadorLineas = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,horasTrabajadas,sueldo);
		 	 	if (contadorLineas == 4 && validarCadenaNumerica(id)
 	 			&& validateStringOfLetters(nombre)
				&& validarCadenaNumerica(horasTrabajadas)
				&& validarCadenaNumerica(sueldo))
		 	 	{
		        pEmployee = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
		 	 	}
		 	 	if (pEmployee!=NULL)
		 	 	{
		        ll_add(pArrayListEmployee,pEmployee);//Los cargo en memoria
		 	 	}

		        retorno =0;
		    }

		    return retorno;
}




/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)


{
	int retorno = -1;

	  if (pFile != NULL && pArrayListEmployee != NULL)
	    {
	        while (!feof(pFile))
	        {

	            {
	                Employee*empleado = employee_new();

	                retorno = fread(empleado, sizeof(Employee), 1, pFile);

	                if (retorno == 1)
	                {
	                    ll_add(pArrayListEmployee, empleado);
	                }

	            }
	        }

	        retorno = 0;
	    }

	    fclose(pFile);

	    return retorno;
}


