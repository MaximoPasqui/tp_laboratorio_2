#include <stdio.h>
#include <string.h>
#include "arrayPassenger.h"
#include "bibliotecaPersonal.h"
#define TRUE 1
#define FALSE 0
#define UP 2
#define DOWN 3

int initPassengers(sPassenger list[], int size)
{
	for(int i=0;i<size;i++)
	{
		list[i].isEmpty = FALSE;
	}

return 0;
}

int addPassenger(sPassenger list[], sStatus listS[], int sizeS, int size, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[], int idS, char description[])
{
	int result;
	result =-1;

	for(int i=0;i<size;i++)
	{
		if(i == 0 || list[i].isEmpty == FALSE)
		{
			list[i].id = id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].flyCode, flyCode);
			listS[i].idStatus = idS;
			strcpy(listS[i].description, description);
			for(int j=0;j<size;j++)
			{
				printf("ID \tNAME \t\tLAST NAME\tPRICE\t\tTP\tFC\tID STATUS\tDESCRIPTION\n%d \t%s \t%s\t\t%2.f\t\t%d\t%s\t%d\t%s",list[i].id, list[i].name, list[i].lastName,list[i].price, list[i].typePassenger, list[i].flyCode, listS[i].idStatus, listS[i].description);
				result =1;
			}
			list[i].isEmpty = TRUE;
			break;
		}
	}
return result;
}

int findPassengerById(sPassenger list[],int size, int id)
{
	int result;
	result =-1;

	for(int i=0;i<size;i++)
	{
		if(list[i].isEmpty == TRUE && list[i].id == id)
		{
			result =1;
			break;
		}
	}

	return result;
}

int removePassenger(sPassenger list[], int size, int id)
{
	int result;
	char confirm;
	result =0;
	confirm = 'n';

	for(int i=0;i<size;i++)
	{
		if(list[i].isEmpty == TRUE && list[i].id == id)
		{
			printf("ID Encontrado. Seguro quieres eliminarlo?\n");
			fflush(stdin);
			scanf("%c",&confirm);
			while(confirm != 's' && confirm != 'n')
			{
				printf("s o n..");
				scanf("%c",&confirm);
			}
			if(confirm == 's')
			{
				list[i].isEmpty = FALSE;
				result = 1;
			}
		}
	}

	return result;
}

int sortPassengers(sPassenger list[], int size, int order)
{
	sPassenger aux;
	int result;
	result =0;

	switch(order)
	{
	case UP:
	for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(list[i].lastName > list[j].lastName && list[i].typePassenger > list[j].typePassenger)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;

				printf("The array has been susessfully sorted from lower to upper by last name and type of passenger.\n");
			}
		}
	}
	result =1;
	break;
	case DOWN:
	for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(list[i].lastName < list[j].lastName && list[i].typePassenger < list[j].typePassenger)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;

				printf("The array has been susessfully sorted from upper to lower by last name and type of passenger.\n");
			}
		}
	}
	result =1;
	break;
	default:
		printf("ERROR.. Parameter not recognized, type 2(sort from lower to upper) or 3(sort from upper to lower).");
	break;

	}


	return result;
}

int printPassenger(sPassenger list[], int size, sStatus listS[], int sizeS)
{
	int retorno;
	retorno =0;

	printf("ID \tNAME \tLAST NAME\tPRICE\t\tTP\tFC\tSF\n");
	for(int i=0;i<size;i++)
	{
		if(list[i].isEmpty == TRUE)
		{
			printf("%d \t%s \t %s\t\t%2.f\t\t%d\t%s\t%s\n",list[i].id, list[i].name, list[i].lastName,list[i].price, list[i].typePassenger, list[i].flyCode, listS[i].description);

		}
	}



	return retorno;
}

int sortPassengersByCode(sPassenger list[], int size, int order)
{
	int result;
	result =0;
	sPassenger aux;
	switch(order)
	{
	case UP:
	for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(list[i].flyCode > list[j].flyCode && list[i].statusFlight > list[j].statusFlight)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;

				printf("The array has been susessfully sorted from lower to upper by flycode and status flight.\n");
			}
		}
	}
	result =1;
	break;
	case DOWN:
	for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(list[i].flyCode < list[j].flyCode && list[i].statusFlight < list[j].statusFlight)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;

				printf("The array has been susessfully sorted from upper to lower by flycode and status flight.\n");
			}
		}
	}
	result =1;
	break;
	default:
		printf("ERROR.. Parameter not recognized, type 2(sort from lower to upper) or 3(sort from upper to lower).");
	break;
	}

	return result;
}

