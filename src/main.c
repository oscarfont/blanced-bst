#include "definicions.h"

void main() {
    int e, resposta_usuari = 0, m, i, Nia1, Nia2, telf;
    struct nodo* arbol = NULL;
    char Nombre[MAXNOM], Nia_bus[MAXNIA], elem2[MAXNIA], elem3[MAXTELF], resp, n;
    
    while(resposta_usuari != 8){
        
        menu_principal();
        scanf("%s", &resp);
        
        // Mensaje de error si el usuario introduce un carácter.
        e = errorMenu(resp);
        while(e == TRUE){
            printf(ERRORNUM);
            scanf("%s", &resp);
            e = errorMenu(resp);
        }
        
        resposta_usuari = atoi(&resp);
        
        // Posibles casos a realizar.
        switch(resposta_usuari){
	        
	        case 1:
	            printf("Introduzca el numero de alumnos que desea insertar: ");
	            scanf("%s", &n);
                    while(verificarDades0(n) == TRUE){
                        printf("ERROR.\nIntroduzca un número válido.\n");
                        scanf("%s", &n);
                    }
                    m = atoi(&n);
	            for(i = 0; i < m; i++){
	                printf("Introduzca el nombre del alumno: ");
	                scanf("%s", &Nombre);
                        //Verificamos que sea un Nombre sin errores y aceptable. 
                        while(verificarDades1(Nombre) == TRUE){
                            printf(ERRORNOM);
                            scanf("%s", &Nombre);
                        }
	                printf("Introduzca el NIA del alumno: ");
	                scanf("%s", &elem2);
                        //Verificamos que sea un NIA con las cifras debidas y sin errores.
                        while(verificarDades2(elem2) == TRUE){
                            printf(ERRORNIA2);
                            scanf("%s", &elem2);
                        }
                        Nia1 = atoi(elem2);
                        printf("Introduzca el teléfono del alumno: ");
	                scanf("%s", &elem3);
                        //Verificamos que sea un numero de telefono con las cifras debidas y sin errores.
                        while(verificarDades3(elem3) == TRUE){
                            printf(ERRORTEL2);
                            printf("\n");
                            scanf("%s", &elem3);
                        }
                        telf = atoi(elem3);
	                arbol = insertar_nodo(arbol, Nia1, telf, Nombre);
                        printf("\n");
	            }
	            printf("\n\n");
		        break;

                case 2:
                    printf("Introduzca el NIA del alumno que desea buscar: ");
                    scanf("%s", &Nia_bus);
                    //Verificamos que sea un NIA con las cifras debidas y sin errores.
                    while(verificarDades2(Nia_bus) == TRUE){
                            printf(ERRORNIA2);
                            scanf("%s", &Nia_bus);
                    }
                    Nia2 = atoi(Nia_bus);
                    struct nodo *nodo_buscado = buscar(Nia2, arbol);
                    if(nodo_buscado == NULL){
                        printf(ERRORALUM);
                    }else{
                        printf("El nombre del alumno con NIA %d es: %s\n", nodo_buscado->NIA, nodo_buscado->nom);
                        printf("El telefono de %s es: %d\n\n", nodo_buscado->nom, nodo_buscado->telefon);
                    }
		        break;
                case 3:
                    //Recorrido Preorden.
                    Preorden(arbol);
                    printf("\n\n");
		        break;
                case 4:
                    //Recorrido Inorden.
                    Inorden(arbol);
                    printf("\n\n");
		        break;
                case 5:
                    //Recorrido Postorden.
                    Postorden(arbol);
                    printf("\n\n");
		        break;
                case 6:
                    printf("Has salido del programa.\n¡Hasta pronto!\n");
                    exit(0);
		        break;
	        default:
                    printf(ERRORNUM);
                    printf("\n");
		        break;
        }
    }
    
    free(arbol);
}