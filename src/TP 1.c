/*
 ============================================================================
 Name        : TP.c
 Author      : Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 9
#include "Programa.h"


int main(void) {

	int opcion;
	int kilometros = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	float costos[TAM];

	int banderaKilometros = 0;
	int banderaPrecios = 0;
	int banderaCalcular = 0;





	setbuf(stdout, NULL);

	do
	{
		printf("1. Ingresar Kilometros: (km = %d)\n", kilometros );
		printf("2. Ingresar Precio de Vuelos: (Aerolineas = $%.2f, Latam = $%.2f )\n", precioAerolineas, precioLatam);
		printf("3. Calcular todos los costos \n");
		printf("4. Informar Resultados \n");
		printf("5. Carga forzada de datos \n");
		printf("6. Salir \n");

		printf("Ingrese una opcion : ");
		scanf("%d", &opcion);


		switch(opcion)
		{
			case 1:
				banderaKilometros = 1;
				kilometros = ValidarKilometros(IngresarKilometros("Ingrese Kilometros : "));
				break;
			case 2:
				banderaPrecios = 1;
				precioAerolineas = ValidarPrecios(IngresarPrecios("Precio vuelo Aerolineas : "));
				precioLatam = ValidarPrecios(IngresarPrecios("Precio vuelo Latam : "));
				break;
			case 3:
				if(banderaPrecios == 1 && banderaKilometros == 1)
				{
					CalcularCostos(precioLatam, precioAerolineas, kilometros, costos);
					banderaCalcular = 1;
					printf("SE CALCULARON TODOS LOS COSTOS \n");
				}
				else
				{
					printf("No se puede calcular porque : \n");
					if(banderaPrecios == 0)
					{
						printf("-No se ingresaron los precios\n");
					}
					if(banderaKilometros == 0)
					{
						printf("-No se ingresaron los kilometros\n");
					}
				}
				break;
			case 4:
				if(banderaCalcular == 1)
				{
					InformarResultados(costos);
				}
				else
				{
					printf("Antes se tiene que Calcular todos los costos \n");
				}

				break;
			case 5:
				CargaForzada(costos);
				InformarResultados(costos);
				break;
			case 6:
				printf("Gracias por usar mi programa \n");
				break;
			default:
				printf("Opcion no valida \n");
				break;
		}

		system("pause");


	}while(opcion != 6);


}














