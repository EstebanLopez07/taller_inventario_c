#include <stdio.h>

int main() {

    char nombres[10][50];
    float precios[10];
    int cantidad = 0;
    int opcion;
    float total = 0.0;
    int caro = 0;
    int barato = 0;
    float suma = 0.0;
    float promedio;
    char busqueda[50];

    do {
        printf("Cuantos productos desea ingresar(maximo 10): \n");
        scanf("%d", &cantidad);

        if (cantidad < 1 || cantidad > 10) {
            printf("[error]: Ingrese un numero entre 1 y 10\n");
        }
    } while (cantidad < 1 || cantidad > 10);

    for (int i = 0; i < cantidad; i++) {
        printf("Producto %d\n", i + 1);
        printf("Nombre: ");
        scanf("%s", nombres[i]);
        printf("Precio: ");
        scanf("%f", &precios[i]);
    }
    
    do {
        printf("\n1. Calcular precio total del inventario\n");
        printf("2. Mostrar producto mas caro y mas barato\n");
        printf("3. Calcular precio promedio\n");
        printf("4. Buscar producto por nombre\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion del 1-5\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                total = 0.0; // Reinicio para evitar acumular si se ejecuta varias veces
                for (int i = 0; i < cantidad; i++) {
                    total += precios[i];
                }
                
                printf("El precio total del inventario es: $%.2f\n", total);
                break;

            case 2:
                caro = 0;   // Reinicio para evaluar desde el primer producto
                barato = 0;
                
                for (int i = 1; i < cantidad; i++) {
                    if (precios[i] > precios[caro]) {
                        caro = i;
                    }
                }
                
                for (int i = 1; i < cantidad; i++) {
                    if (precios[i] < precios[barato]) {
                        barato = i;
                    }
                }
                
                printf("El producto mas caro es %s - $%.2f\n", nombres[caro], precios[caro]);
                printf("El producto mas barato es %s - $%.2f\n", nombres[barato], precios[barato]);
                break;

            case 3:
                suma = 0.0; // Reinicio para evitar acumular si se ejecuta varias veces
                for (int i = 0; i < cantidad; i++) {
                    suma += precios[i];
                }
                
                promedio = suma / cantidad;
                printf("El promedio de precios es de $%.2f\n", promedio);
                break;

            case 4: {
                char buscado[30];
                int encontrado = 0;

                printf("\nIngrese el nombre del producto a buscar: ");
                scanf("%s", buscado);

                for (int i = 0; i < cantidad; i++) {
                    int sonIguales = 1;
                    int j = 0;

                    while (nombres[i][j] != '\0' || buscado[j] != '\0') {
                        if (nombres[i][j] != buscado[j]) {
                            sonIguales = 0;
                            break;
                        }
                        j++;
                    }

                    if (sonIguales == 1) {
                        printf("-> ¡Producto encontrado! %s cuesta: $%.2f\n", nombres[i], precios[i]);
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("-> El producto '%s' no existe en el inventario.\n", buscado);
                }
                break;
            }

            case 5:
                printf("\nSaliendo del sistema de inventario. ¡Hasta luego!\n");
                break;

            default:
                printf("\nOpcion no valida. Por favor, ingrese un numero del 1 al 5.\n");
                break;
        }

    } while (opcion != 5);

    return 0;
}