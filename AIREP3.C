
#include <stdio.h>
#include <string.h>

#define ZONAS 5

typedef struct {
    char nombre[30];
    float pm25;
    float co2;
    float temperatura;
    float humedad;
    float viento;
    float prediccion;
    char alerta[30];
    char medida[100];
} Zona;

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ingresarDatos(Zona zonas[]) {
    