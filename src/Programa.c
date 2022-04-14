/*
 * Programa.c
 *
 *  Created on: 9 abr. 2022
 *      Author: W10-PC
 */

#include "Programa.h"
#define TAM 9

int IngresarKilometros(char mensaje[])
{
	int kilometros;

	printf("%s", mensaje);
	scanf("%d", &kilometros);

	return kilometros;
}

float IngresarPrecios(char mensaje[])
{
	float precio;

	printf("%s", mensaje);
	scanf("%f", &precio);

	return precio;
}

int ValidarKilometros(int kilometros)
{
	while(kilometros < 0)
	{
		kilometros = IngresarKilometros("Error, ingrese kilometros mayor a 0km: ");
	}

	return kilometros;
}

float ValidarPrecios(float precio)
{
	while(precio < 0)
	{
		precio = IngresarPrecios("Error, ingrese un precio mayor a $0 : ");
	}

	return precio;
}

void CalcularCostos(float precioLatam, float precioAerolineas, int kilometros, float costos[])
{
	int i;
	int j;
	int k;
	int bandera = 0;
	int precio;


	for(i = 0; i < 2 ; i++)
	{
		precio = precioLatam;

		for(j = 0, k = 0 ; j < 4 ; j++, k++)
		{
			if(bandera == 0 && i == 1)
			{
				precio = precioAerolineas;
				k = 4;
				bandera = 1;
			}

			switch(j)
			{
			case 0: //j = 0 , k = 4
				costos[k] = TarjetaDebito(precio);
				break;
			case 1: // j = 1 , k = 5
				costos[k] = TarjetaCredito(precio);
				break;
			case 2: // j = 2 , k = 6
				costos[k] = Bitcoin(precio);
				break;
			case 3: // j = 3, k = 7
				costos[k] = PrecioUnitario(precio, kilometros);
				break;

			}
		}

	}

	// k = 8
	costos[k] = DiferenciaPrecio(precioLatam, precioAerolineas);

}

float TarjetaDebito(float precio)
{
	float precioDescuento;
	float descuento;

	descuento = (precio * 10) / 100;

	precioDescuento = precio - descuento;

	return precioDescuento;
}

float TarjetaCredito(float precio)
{
	float precioInteres;
	float interes;

	interes = (precio * 25) / 100;

	precioInteres = precio + interes;

	return precioInteres;
}

float Bitcoin(float precio)
{
	float bitcoin;

	bitcoin = 4606954.55 / precio;

	return bitcoin;
}

float PrecioUnitario(float precio, int kilometros)
{
	float precioUnitario;

	precioUnitario = precio / kilometros;

	return precioUnitario;
}

void InformarResultados(float costos[])
{
	int i;

	for(i = 0; i < TAM ; i++ )
	{
		switch(i)
		{
		case 0:
			printf("Latam: \n");
			printf("Precio con tarjeta de debito : $ %.2f\n", costos[i]);
			break;
		case 1:
			printf("Precio con tarjeta de credito : $ %.2f\n", costos[i]);
			break;
		case 2:
			printf("Precio pagando con bitcoin :  %.2f BTC\n", costos[i]);
			break;
		case 3:
			printf("Precio unitario : $ %.2f\n", costos[i]);
			break;
		case 4:
			printf("Aerolineas: \n");
			printf("Precio con tarjeta de debito : $ %.2f\n", costos[i]);
			break;
		case 5:
			printf("Precio con tarjeta de credito : $ %.2f\n", costos[i]);
			break;
		case 6:
			printf("Precio pagando con bitcoin : %.2f BTC\n", costos[i]);
			break;
		case 7:
			printf("Precio unitario : $ %.2f\n", costos[i]);
			break;
		case 8:
			printf("La diferencia de precio es : $ %.2f\n", costos[i]);
			break;
		}
	}

}

float DiferenciaPrecio(float precioLatam, float precioAerolineas)
{
	float diferencia;

	diferencia = precioLatam - precioAerolineas;

	return diferencia;
}

void CargaForzada(float cargaForzada[])
{

	CalcularCostos(159339, 162965, 7090, cargaForzada);

}
