/*
 * Programa.h
 *
 *  Created on: 9 abr. 2022
 *      Author: W10-PC
 */

#ifndef PROGRAMA_H_
#define PROGRAMA_H_
#include <stdio.h>

//-------------------------------------------------------------------

/** \brief Pide al usuario que ingrese kilometros y los registre
 *
 * \param char[] Es el mensaje de pedido de ingreso de kilometros
 * \return int devuelve los kilometros
 *
 */


int IngresarKilometros(char[]);

//-------------------------------------------------------------------

/** \brief Pide al usuario que ingrese un precio
 *
 * \param char[] Es el mensaje de pedido de un precio 'precio latam y precio aerolineas'
 * \return float Devuelve el precio
 *
 */

float IngresarPrecios(char[]);

//-------------------------------------------------------------------


/** \brief Valida los kilometros si es menor a 0
 *
 * \param int Los kilometros ingresados
 * \return int Devuelve los kilometros validados
 *
 */
int ValidarKilometros(int);

//-------------------------------------------------------------------

/** \brief Valida los precios si es menor a 0
 *
 * \param float Recibe el precio ingresado
 * \return float Devuelve el precio validado
 *
 */
float ValidarPrecios(float);

//-------------------------------------------------------------------

/** \brief Calcula todos los costos por medio de valores que recibe como parametro y
 * llama a las funciones TarjetaDebito(); TarjetaCredito(); Bitcoin(); PrecioUnitario();
  y DiferenciaPrecio();
 *
 * \param float Es el precio Latam
 * \param float Es el precio Aerolineas
 * \param int Son los kilometros
 * \param float[] Es el vector de costos, donde registrara todos los costos
 * \return void
 *
 */

void CalcularCostos(float, float, int, float[]);

//-------------------------------------------------------------------

/** \brief Calcula el precio usando Tarjeta de Debito
 *
 * \param float Recibe un precio
 * \return float Devuelve el precio con descuento
 *
 */

float TarjetaDebito(float);

//-------------------------------------------------------------------

/** \brief Calcula el precio usando Tarjeta de Credito
 *
 * \param float Recibe un precio
 * \return float Devuelve el precio con interes
 *
 */

float TarjetaCredito(float);

//-------------------------------------------------------------------

/** \brief Calcula precio pagando con Bitcoin
 *
 * \param float Recibe un precio
 * \return float Devuelve el precio pagando con Bitcoin
 *
 */

float Bitcoin(float);

//-------------------------------------------------------------------

/** \brief Calcula precio por km
 *
 * \param float Recibe un precio
 * \param int Recibe los kilometros
 * \return float Devuelve el precio por km
 *
 */

float PrecioUnitario(float, int);

//-------------------------------------------------------------------

/** \brief Muestra diferencia de precio
 *
 * \param float Es el precio Latam
 * \param float Es el precio Aerolineas
 * \return float Devuelve la diferencia entre los 2 precios
 *
 */

float DiferenciaPrecio(float, float);

//-------------------------------------------------------------------

/** \brief Carga forzadamente los datos. Llama la funcion CalcularCostos
pasando como parametro Valores hardcodeados y el Vector de Costos
 *
 * \param float[] Es el vector de costos, donde registrara todos los costos de los valores
 * hardcodeados
 * \return void
 *
 */

void CargaForzada(float[]);

//-------------------------------------------------------------------

/** \brief Informa Resultados, recibiendo  como parametro un Vector
 *
 * \param float[] El registro de todos los costos 'Latam y Aerolineas'
 * \return void
 *
 */

void InformarResultados(float[]);

//-------------------------------------------------------------------

#endif /* PROGRAMA_H_ */
