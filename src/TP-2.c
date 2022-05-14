/*
Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener más de 2000 pasajeros.
Datos:

El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
 */

#include <stdio.h>
#include <stdlib.h>
#include"arrayPassenger.h"
#include "bibliotecaPersonal.h"
#define TRUE 1
#define FALSE 0
#define UP 2
#define DOWN 3
#define T 2000

int main(){
	setbuf(stdout,NULL);
	sStatus listS[3] = {{1,"Cancelado"},{2,"Demorado"},{3,"Activo"}};
	sPassenger list[T];
	int option;
	char carryOn;
	int retorno;

	carryOn = 's';

	initPassengers(list, T);
	//addPassenger(list, listS, 3, T, 5, "Jhonathan", "Rivero", 1250.00, 3, "estry", 2, "Demorado");

	do
	{
		printf("\n1) ALTA\n");
		printf("2) MODIFICAR\n");
		printf("3) BAJA\n");
		printf("4) MOSTRAR\n");
		printf("Por favor, elija una opcion:\n");
		scanf("%d",&option);

		switch(option)
		{
		case 1:
			retorno = cargarEnLista(list, T, listS, 3);
			switch(retorno)
			{
			case -1:
			printf("\nNo hay espacio...\n");
			break;

			case 2:
				printf("\nCarga cancelada\n");
			break;
			default:
				printf("\n carga completada\n");
			break;
			}
		break;
		case 2:
			retorno = modificarlos(list, T);
		if(retorno == 0)
		{
			printf("\nno hubo cambios..");
		}else
		{
			printf("Cambio realizado.\n");
		}
		break;
		case 3:
			retorno = removePassenger(list, T, 1);
			if(retorno == 0)
			{
				printf("\neliminacion cancelada.");
			}else
			{
				printf("eliminacion realizada.\n");
			}
		break;
		case 4:
			retorno = printPassenger(list, T, listS, 3);
			retorno = sortPassengers(list, T, UP);
			switch(retorno)
			{
			case 1:
				printf("Se han ordenado los datos\n");
			break;
			default:
				printf("Error..Intentelo de nuevo\n");
			break;
			}

			retorno = CalcularTotalPrecio(list, T);
			printf("El promedio es: %d",retorno);

			retorno = calcularPasajerosMasDelPromedio(list, T, listS);
			if(retorno ==1)
			{
				printf("Las personas con precio mas alto que el promedio son: \n");
			}

			retorno = sortPassengersByCode(list, T, UP);

		break;
		default:
			printf("ERROR, ingrese una opcion existente..");
			scanf("%d",&option);
		break;
		}

	}while(carryOn == 's');

	return 0;
}

