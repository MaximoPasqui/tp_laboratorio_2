
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define TRUE 1
#define FALSE 0
#define UP 2
#define DOWN 3

typedef struct
{
	int idStatus;
	char description[21];

}sStatus;

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
	int idStatus;

}sPassenger;

int initPassengers(sPassenger[], int);
int addPassenger(sPassenger[], sStatus[], int, int, int, char[], char[], float, int, char[], int, char[]);
int findPassengerById(sPassenger[],int, int);
int removePassenger(sPassenger[], int, int);
int sortPassengers(sPassenger[], int, int);
int printPassenger(sPassenger[], int, sStatus[], int);
int sortPassengersByCode(sPassenger[], int, int);

#endif
