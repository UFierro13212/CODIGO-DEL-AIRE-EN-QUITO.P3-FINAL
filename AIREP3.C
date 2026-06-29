
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
    int i;

    for (i = 0; i < ZONAS; i++) {
        printf("\n--- Zona %d ---\n", i + 1);

        printf("Nombre de la zona: ");
        fgets(zonas[i].nombre, 30, stdin);
        zonas[i].nombre[strcspn(zonas[i].nombre, "\n")] = '\0';

        printf("PM2.5: ");
        scanf("%f", &zonas[i].pm25);

        printf("CO2: ");
        scanf("%f", &zonas[i].co2);

        printf("Temperatura: ");
        scanf("%f", &zonas[i].temperatura);

        printf("Humedad: ");
        scanf("%f", &zonas[i].humedad);

        printf("Velocidad del viento: ");
        scanf("%f", &zonas[i].viento);

        limpiarBuffer();
    }
}

void calcularPrediccion(Zona zonas[]) {
    int i;

    for (i = 0; i < ZONAS; i++) {
        zonas[i].prediccion =
            (zonas[i].pm25 * 0.45) +
            (zonas[i].co2 * 0.25) +
            (zonas[i].humedad * 0.10) +
            (zonas[i].temperatura * 0.10) -
            (zonas[i].viento * 0.10);
    }
}

void generarAlertas(Zona zonas[]) {
    int i;

    for (i = 0; i < ZONAS; i++) {
        if (zonas[i].prediccion < 50) {
            strcpy(zonas[i].alerta, "BAJA");
            strcpy(zonas[i].medida, "Calidad del aire aceptable.");
        } else if (zonas[i].prediccion < 100) {
            strcpy(zonas[i].alerta, "MEDIA");
            strcpy(zonas[i].medida, "Evitar actividad fisica intensa al aire libre.");
        } else {
            strcpy(zonas[i].alerta, "ALTA");
            strcpy(zonas[i].medida, "Reducir trafico y evitar exposicion prolongada.");
        }
    }
}

void mostrarResultados(Zona zonas[]) {
    int i;

    printf("\n========== REPORTE QUITOAIRE ==========\n");

    for (i = 0; i < ZONAS; i++) {
        printf("\nZona: %s\n", zonas[i].nombre);
        printf("Prediccion 24h: %.2f\n", zonas[i].prediccion);
        printf("Alerta: %s\n", zonas[i].alerta);
        printf("Medida: %s\n", zonas[i].medida);
    }
}

