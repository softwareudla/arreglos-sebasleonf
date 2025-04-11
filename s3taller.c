#include <stdio.h>

int main() {
    int i, j;
    float notas[5][3];
    float suma, promedio;
    float mayor, menor;
    int aprobados1 = 0, aprobados2 = 0, aprobados3 = 0;

    for(i = 0; i < 5; i++) {
        printf("\nEstudiante #%d:\n", i + 1);
        for(j = 0; j < 3; j++) {
            do {
                printf("Ingrese la nota de la asignatura #%d: ", j + 1);
                scanf("%f", &notas[i][j]);
                if(notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("La nota debe estar entre 0 y 10. Intente nuevamente.\n");
                }
            } while(notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    for(i = 0; i < 5; i++) {
        suma = 0;
        mayor = notas[i][0];
        menor = notas[i][0];

        for(j = 0; j < 3; j++) {
            suma = suma + notas[i][j];

            if(notas[i][j] > mayor) {
                mayor = notas[i][j];
            }
            if(notas[i][j] < menor) {
                menor = notas[i][j];
            }
        }

        promedio = suma / 3;
        printf("\nEstudiante #%d - Promedio: %.2f | Mayor nota: %.2f | Menor nota: %.2f\n", i + 1, promedio, mayor, menor);
    }

    for(j = 0; j < 3; j++) {
        suma = 0;
        mayor = notas[0][j];
        menor = notas[0][j];
        int aprobados = 0;

        for(i = 0; i < 5; i++) {
            suma = suma + notas[i][j];

            if(notas[i][j] > mayor) {
                mayor = notas[i][j];
            }
            if(notas[i][j] < menor) {
                menor = notas[i][j];
            }

            if(notas[i][j] >= 6) {
                aprobados = aprobados + 1;
            }
        }

        promedio = suma / 5;
        printf("\nAsignatura #%d - Promedio: %.2f | Mayor nota: %.2f | Menor nota: %.2f | Aprobados: %d | Reprobados: %d\n", j + 1, promedio, mayor, menor, aprobados, 5 - aprobados);
    }

    return 0;
}
