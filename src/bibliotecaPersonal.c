#include <stdio.h>
#include <string.h>
#include "arrayPassenger.h"
#define TRUE 1
#define FALSE 0
#define UP 2
#define DOWN 3
#define DENEGAR 4

int pedirEntero(int* numero, char*mensaje, char* msjError, int rangoMinimo, int rangoMaximo)
{
	int retorno;
	int bufferInt;
	retorno = -1;
	if(numero != NULL && mensaje != NULL && msjError != NULL && rangoMinimo <= rangoMaximo)
	{
		printf("%s",mensaje);
		scanf("%d",&bufferInt);
		if(bufferInt >= rangoMinimo && bufferInt <= rangoMaximo){
			*numero = bufferInt;
			retorno = 0;
		}else{
			printf("%s",msjError);
		}
	}
	return retorno;
}

float pedirFloat(float* flotante, char*mensaje, char* msjError, float rangoMinimo, float rangoMaximo)
{
	int retorno;
	int bufferFloat;
	retorno = -1;
	if(flotante != NULL && mensaje != NULL && msjError != NULL && rangoMinimo <= rangoMaximo)
	{
		printf("%s",mensaje);
		scanf("%d",&bufferFloat);
		if(bufferFloat >= rangoMinimo && bufferFloat <= rangoMaximo){
			*flotante = bufferFloat;
			retorno = 0;
		}else{
			printf("%s",msjError);
		}
	}
	return retorno;
}

int pedirChar(char* letra, char*mensaje, char* msjError, char rangoMinimo, char rangoMaximo)
{
	int retorno;
	int bufferChar;
	retorno = -1;
	if(letra != NULL && mensaje != NULL && msjError != NULL && rangoMinimo <= rangoMaximo)
	{
		printf("%s",mensaje);
		scanf("%d",&bufferChar);
		retorno = 0;
		}else{
			printf("%s",msjError);
		}
	return retorno;
}

void mostrar(sPassenger passenger, sStatus status){
	printf("\n%d %s %s %.2f %s %d %d %s\n",  	passenger.id,
												passenger.name,
												passenger.lastName,
												passenger.price,
												passenger.flyCode,
												passenger.typePassenger,
												status.idStatus,
												status.description);
}

sPassenger cargar(sStatus listS[], int sizeS){
	int IDs;
	int validar;
	IDs =0;
	sPassenger passenger;
	printf("Ingrese nombre\n");
	gets(passenger.name);
	validar = strlen(passenger.name);
	while(validar > 51)
	{
		printf("Error,cadena muy grande");
		gets(passenger.name);
	}
	scanf("%s",passenger.name);
	fflush(stdin);
	printf("Ingrese Apellido:\n");
	fflush(stdin);
	scanf("%s",passenger.lastName);
	printf("Ingrese precio:\n");
	scanf("%f",&passenger.price);
	printf("Ingrese codigo de vuelo:\n");
	fflush(stdin);
	scanf("%s",passenger.flyCode);
	printf("Ingrese tipo de pasajero: \n");
	scanf("%d",&passenger.typePassenger);
	for(int i=0;i<sizeS;i++)
	{
		printf("%d %s\n",listS[i].idStatus,listS[i].description);
	}
	printf("\nIngrese ID de estado de vuelo: \n");
	scanf("%d",&IDs);
	passenger.isEmpty = TRUE;
	passenger.id ++;

	return passenger;
}

int buscarLibre(sPassenger list[], int size){
	int resultado;
	resultado =-1;
	for(int i=0;i<size;i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			resultado =i;
			break;
		}
	}
	return resultado;
}

int cargarEnLista(sPassenger list[], int size, sStatus listS[], int sizeS){
	int resultado;
	resultado = buscarLibre(list, size);
	if(resultado!=-1)
	{
		list[resultado] = cargar(listS, sizeS);
	}
	//resultado = confirmar();

	return resultado;
}

int modificarlos(sPassenger list[], int size){
	int ID;
	int opcion;
	int bandera;
	char guardar;
	char* cambioNombre;
	char* cambioApellido;
	float cambioPrecio;
	int cambioTipo;
	char* cambioCodigo;

	guardar = 'n';
	bandera =0;

	printf("Ingrese ID a modificar: \n");
	scanf("%d",&ID);
	for(int i=0;i<size;i++)
	{
		if(list[i].isEmpty == TRUE && list[i].id == ID)
		{
			printf("Elija opcion a modificar: \n");
			printf("\n1) Nombre");
			printf("\n2) Apellido");
			printf("\n3) Precio");
			printf("\n4) Tipo de pasajero\n");
			printf("\n5) Codigo de pasajero");
			scanf("%d",&opcion);
			switch(opcion)
			{
			case 1:
				printf("Ingrese el nuevo nombre: \n");
				fflush(stdin);
				scanf("%s",cambioNombre);
				printf("Desea guardar el cambio? s/n \n");
				fflush(stdin);
				scanf("%c",&guardar);
				if(guardar == 's')
				{
					cambioNombre = list[i].name;
					printf("Cambio realizado. \n");
				}else
				{
					printf("Cambio no realizado. \n");
				}
			break;
			case 2:
				printf("Ingrese el nuevo apellido: \n");
				fflush(stdin);
				scanf("%s",cambioApellido);
				printf("Desea guardar el cambio? s/n \n");
				fflush(stdin);
				scanf("%c",&guardar);
				if(guardar == 's')
				{
					cambioApellido = list[i].lastName;
					printf("Cambio realizado. \n");
				}else
				{
					printf("Cambio no realizado. \n");
				}
			break;
			case 3:
				printf("Ingrese el nuevo precio: \n");
				scanf("%f",&cambioPrecio);
				printf("Desea guardar el cambio? s/n \n");
				fflush(stdin);
				scanf("%c",&guardar);
				if(guardar == 's')
				{
					cambioPrecio = list[i].price;
					printf("Cambio realizado. \n");
				}else
				{
					printf("Cambio no realizado. \n");
				}
			break;
			case 4:
				printf("Ingrese el nuevo tipo de pasajero: \n");
				scanf("%d",&cambioTipo);
				printf("Desea guardar el cambio? s/n \n");
				fflush(stdin);
				scanf("%c",&guardar);
				if(guardar == 's')
				{
					cambioTipo = list[i].typePassenger;
					printf("Cambio realizado. \n");
				}else
				{
					printf("Cambio no realizado. \n");
				}
			break;
			case 5:
				printf("Ingrese el nuevo codigo de pasajero: \n");
				fflush(stdin);
				scanf("%s",cambioCodigo);
				printf("Desea guardar el cambio? s/n \n");
				fflush(stdin);
				scanf("%c",&guardar);
				if(guardar == 's')
				{
					cambioCodigo = list[i].flyCode;
					printf("Cambio realizado. \n");
				}else
				{
					printf("Cambio no realizado. \n");
				}
			break;
			default:
				printf("Error, ingrese opcion valida...\n");
				scanf("%d",&opcion);
			break;
			}
			bandera =1;
		}
	}

	return bandera;
}

int confirmar(){
	int resultado;
	char confirmar;
	confirmar = 's';
	printf("Esta seguro que quiere continuar?");
	fflush(stdin);
	scanf("%c",&confirmar);

	if(confirmar == 'n')
	{
		resultado = DENEGAR;
	}
	return resultado;
}

void mostrarID(sPassenger list[], int size){
	for(int i=0;i<size;i++)
	{
		if(list[i].isEmpty == TRUE)
		{
			printf("%d",list[i].id);
		}
	}
}

int CalcularTotalPrecio(sPassenger list[], int size)
{
	int promedio;
	int contadorPrecio;
	int acumulador;
	acumulador =0;
	contadorPrecio =0;
	for(int i=0;i<size;i++)
	{
		if(list[i].isEmpty == TRUE)
		{
			contadorPrecio ++;
			acumulador += list[i].price;
		}
	}
	promedio = acumulador / contadorPrecio;
	return promedio;
}

int calcularPasajerosMasDelPromedio(sPassenger list[], int size,sStatus listS[])
{
	int retorno;
	int promedio;
	retorno = 0;
	promedio = CalcularTotalPrecio(list, size);
	for(int i=0;i<size;i++)
	{
		if(list[i].isEmpty == TRUE && list[i].price > promedio)
		{
			retorno = 1;
			mostrar(list[i], listS[i]);
		}
	}
	return retorno;
}

