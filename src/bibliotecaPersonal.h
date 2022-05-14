#define TRUE 1
#define FALSE 0

#ifndef BIBLIOTECAPERSONAL_H_
#define BIBLIOTECAPERSONAL_H_

int pedirInt(int* numero, char*mensaje, char* msjError, int rangoMinimo, int rangoMaximo);
int pedirFloat(float* flotante, char*mensaje, char* msjError, float rangoMinimo, float rangoMaximo);
int pedirChar(char* letra, char*mensaje, char* msjError, char rangoMinimo, char rangoMaximo);

void mostrar(sPassenger, sStatus);
sPassenger cargar(sStatus[], int);
int buscarLibre(sPassenger[], int);
int cargarEnLista(sPassenger[], int, sStatus[], int);
void mostrarTodos(sPassenger[], int);
int modificarlos(sPassenger[], int);
int confirmar();
int recibirEntero(char[]);
void mostrarID(sPassenger list[], int size);
int baja(sPassenger[], int);
int CalcularTotalPrecio(sPassenger[], int);
int calcularPromedio(int, int);
int calcularPasajerosMasDelPromedio(sPassenger[], int,sStatus[]);






#endif
