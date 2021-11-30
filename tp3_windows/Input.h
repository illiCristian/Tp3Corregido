/*
 * Input.h
 *
 *  Created on: 12 oct 2021
 *      Author: Cris
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef INPUT_H_
#define INPUT_H_

int MostrarMenu();
//float PedirFlotante(char mensaje[]);
/// @fn int myGets(char[], int)
/// @brief Es una mejora del scanf que evita desbordamientos de cadenas
/// @param cadena
/// @param longitud
/// @return El valor de verdad
int myGets (char cadena [], int longitud);
/// @fn int ValidarEntero(char[])
/// @brief Lee una cadena y valida un numero entero
/// @param numero
/// @return Un valor de verdad
int ValidarEntero (char numero[]);
/// @fn int getString(char*, int)
/// @brief Pido una cadena
/// @param cadena
/// @param longitud
/// @return Un valor de verdad
int getString(char* cadena, int longitud);
/// @fn int PedirNumeroFlotante(float*, char*, char*, float, float, int)
/// @brief Pide un numero flotante
/// @param pResultado
/// @param mensaje ingresado por el usuario
/// @param mensajeError
/// @param minimo parametro minimo
/// @param maximo parametro minimo
/// @param reintentos
/// @return Un valor de verdad
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int reintentos);
/// @fn int getFloat(float*)
/// @brief Obtiene un flotante de una cadena
/// @param pResultado
/// @return Un valor de verdad
int getFloat(float* pResultado);
/// @fn int esFlotante(char*)
/// @brief Valida si un numero es flotante
/// @param cadena
/// @return Un valor de verdad
int esFlotante(char* cadena);
/// @fn void PedirCadena(char[], char[], char[])
/// @brief Pide una cadena que sean solo letras
/// @param array
/// @param message
/// @param messageError
void PedirCadena(char array[],char message[],char messageError[]);
/// @fn int validateStringOfLetters(char[])
/// @brief Valida una cadena que sea solo letras
/// @param cadena
/// @return Un valor de verdad
int validateStringOfLetters(char cadena[]);
/// @fn int PedirUnEntero(char[])
/// @brief Pide un numero entero
/// @param mensaje Es el parametro que se pasa por cadena
/// @return Retorna un numero entero
int PedirUnEntero(char mensaje[]);

//int VerificarRangoEntero (char numeroAverificar[], int *numeroAretornar,int minimo, int maximo);
/// @fn void PedirCadenaB(char[], char[])
/// @brief Pide una cadana
/// @param array
/// @param message
void PedirCadenaB(char array[],char message[]);

int PedirUnEnteroRango(char mensaje[],int minimo, int maximo);
/// @fn int VerificarRangoInt(char[], int*, int, int)
/// @brief Verifica que un numero entero este dentro de los rangos ingresados
/// @param numeroAverificar
/// @param numeroAretornar
/// @param minimo
/// @param maximo
/// @return Un valor de verdad
int VerificarRangoInt (char numeroAverificar[], int *numeroAretornar, int minimo ,int maximo);

int GenerarId(int id);

int MostrarMenuB();
int validarCadenaConEspacios(char nombre[]);
int validarCadenaNumerica(char nombre[]);
int ValidarCharNumerofloat(char numero[]);




#endif /* INPUT_H_ */
