#include "src/definicions.h"

// Imprime el menú principal del programa.
void menu_principal(){
        printf("◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡\n\n");
	    printf("Bienvenido al simulador TAD Árbol Binario de Búsqueda Equilibrado (AVL).\n");
	    printf("A continuación se muestran por pantalla las opciones de las cuales dispone.\n\n");
	    printf("\t 1.- Insertar alumnos.\n");
	    printf("\t 2.- Buscar un alumno por su Nia.\n");
	    printf("\t 3.- Mostrar los Nias de alumnos en recorrido Preorden.\n");
	    printf("\t 4.- Mostrar los Nias de alumnos en recorrido Inorden.\n");
	    printf("\t 5.- Mostrar los Nias de alumnos en recorrido Postorden.\n");
	    printf("\t 6.- Salir del programa.\n\n");
	    printf("Introduzca el número correspondiente a la acción que desea realizar.\n\n");
	    printf("◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡◠◡\n\n");
}

// Detecta errores en el menú.
int errorMenu(char resp){
    
    if((48 <= resp)&&(resp < 58)){
        return FALSE;
    }else{
        return TRUE;
    }
}

//Función que devuelve TRUE o FALSE en función si el arbol esta vacío o no.
int es_vacio(struct nodo* arbol){
  if(arbol != NULL){//comprovación de si el árbol está vacío
        return FALSE;
    }else{//Si está vacío, da un mensaje de error
        return TRUE;
    }
}

// Función que devuelve la altura de un arbol o subarbol.
int getAltura(struct nodo *arbol){
    if (es_vacio(arbol)){
        return 0;
    }else{
        return(arbol->altura);
    }
}

// Búsqueda de nodo.
struct nodo* buscar(int NIA, struct nodo* arbol){
    if(es_vacio(arbol)){
        return NULL;
    } if(NIA < arbol -> NIA) {
        return buscar(NIA, arbol -> hijo_izq);
    } else if(NIA > arbol -> NIA) {
        return buscar(NIA, arbol -> hijo_der);
    } else{
        return arbol;
    }
}

//Función que devuelve el número máximo de dos números dados.
int max(int num1, int num2){
   int result;
   if (num1 > num2)
      result = num1;
   else
      result = num2;
   return result;
}

//Función que reserva memoria y crea un nuevo nodo.
struct nodo* nuevoNodo(int Nia, int telf, char Nomb[]){
    struct nodo* nodo = (struct nodo*)malloc(sizeof(struct nodo));
    if(nodo == NULL){
        printf("ERROR.\n No se pudo crear un nuevo nodo.");
    }else{
        strcpy(nodo->nom, Nomb);
        nodo->NIA  = Nia;
        nodo->telefon = telf;
        nodo->hijo_izq = NULL;
        nodo->hijo_der = NULL;
        nodo->altura = 1; 
        return(nodo);
    }
}

//Función que realiza una rotación simple hacia la derecha.
struct nodo* rotacion_simple_derecha(struct nodo* n2){
    struct nodo* n1 = NULL;
    n1 = n2 -> hijo_izq;
    n2 -> hijo_izq = n1 -> hijo_der;
    n1 -> hijo_der = n2;
    n2 -> altura = max(getAltura(n2 -> hijo_izq), getAltura(n2 -> hijo_der)) + 1;
    n1 -> altura = max(getAltura(n1 -> hijo_der), getAltura(n1 -> hijo_izq)) + 1;
    return(n1);
}

//Función que realiza una rotación simple hacia la izquierda.
struct nodo* rotacion_simple_izquierda(struct nodo* n2){
    struct nodo* n1 = NULL;
    n1 = n2 -> hijo_der;
    n2 -> hijo_der = n1 -> hijo_izq;
    n1 -> hijo_izq = n2;
    n2 -> altura = max(getAltura(n2 -> hijo_izq), getAltura(n2 -> hijo_der)) + 1;
    n1 -> altura = max(getAltura(n1 -> hijo_der), getAltura(n1 -> hijo_izq)) + 1;
    return(n1);
}

/*Función que realiza una rotación doble. Primero hacia la derecha y luego 
hacia la izquierda.*/
struct nodo* rotacion_doble_DerIzq(struct nodo* n2){
    n2->hijo_der = rotacion_simple_derecha(n2 -> hijo_der);
    n2 = rotacion_simple_izquierda(n2);
    return(n2);
}

/*Función que realiza una rotación doble. Primero hacia la izquierda y luego 
hacia la derecha.*/
struct nodo* rotacion_doble_IzqDer(struct nodo* n2){
    n2->hijo_izq = rotacion_simple_izquierda(n2 -> hijo_izq);
    n2 = rotacion_simple_derecha(n2);
    return(n2);
}

//Función que calcula la diferencia de alturas entre dos subarboles.
int dif_altura(struct nodo* arbol){
    if(es_vacio(arbol)){
        return 0;
    }else{
        return((getAltura(arbol->hijo_izq)) - (getAltura(arbol->hijo_der)));
    }
}

//Función que inserta un nodo en el arbol.
struct nodo* insertar_nodo(struct nodo* nodo, int NIA, int telf, char Nomb[]){
    int difer_alturas;
    
    //Insertamos nodo mirando si es mayor o menor que la raíz
    if(es_vacio(nodo)){
        return(nuevoNodo(NIA, telf, Nomb));
    }else if(NIA > nodo->NIA){
        nodo->hijo_der = insertar_nodo(nodo->hijo_der, NIA, telf, Nomb);
    }else if(NIA < nodo->NIA){
        nodo->hijo_izq = insertar_nodo(nodo->hijo_izq, NIA, telf, Nomb);
    }else{
        return(nodo);
    }
    
    nodo->altura = 1 + max(getAltura(nodo->hijo_der), getAltura(nodo->hijo_izq));
    
    difer_alturas = dif_altura(nodo);
    
    //Caso en que se necesita rotación simple a la derecha.
    if((difer_alturas > 1)&&(NIA < nodo->hijo_izq->NIA)){
        return(rotacion_simple_derecha(nodo));
    }
    //Caso en que se necesita rotación doble izquierda-derecha.
    if((difer_alturas > 1)&&(NIA > nodo->hijo_izq->NIA)){
        return(rotacion_doble_IzqDer(nodo));
    }
    //Caso en que se necesita rotación simple a la izquierda.
    if((difer_alturas < -1)&&(NIA > nodo->hijo_der->NIA)){
        return(rotacion_simple_izquierda(nodo));
    }
    //Caso en que se necesita rotación doble derecha-izquierda.
    if((difer_alturas < -1)&&(NIA < nodo->hijo_der->NIA)){
        return(rotacion_doble_DerIzq(nodo));
    }
    
    return(nodo);
}

//Función que recorre el arbol en recorrido Inorden de un arbol.
void Inorden(struct nodo *arbol){
    if(!(es_vacio(arbol))){
       Inorden(arbol->hijo_izq);
       printf("%d ", arbol->NIA);
       Inorden(arbol->hijo_der);
    }
}

//Función que realiza el recorrido Preorden de un arbol.
void Preorden(struct nodo *arbol){
    if(!(es_vacio(arbol))){
        printf("%d ", arbol->NIA);
        Preorden(arbol->hijo_izq);
        Preorden(arbol->hijo_der);
    }
}

//Función que realiza el recorrido Postorden de un arbol.
void Postorden(struct nodo *arbol){
    if(!(es_vacio(arbol))){
        Preorden(arbol->hijo_izq);
        Preorden(arbol->hijo_der);
        printf("%d ", arbol->NIA);
    }
}

//Función que verifica que un Nombre no contenga ni números ni caracteres especiales.
int verificarDades1(char *Nom){
    int i = 0, error;
    while(Nom[i] != '\0'){
        if(((65 <= Nom[i])&&(Nom[i] < 91))||((97 <= Nom[i])&&(Nom[i] < 123))){
            error = FALSE;
        }else{
            error = TRUE;
            break;
        }
        i++;
    }
    return error;
}

/*Función que verifica que un NIA sea de entre 3 y 4 cifras y que no
contenga ni letras ni caracteres especiales.*/
int verificarDades2(char NIA[]){
    int i = 0, error, cont = 0;
    while(NIA[i] != '\0'){
        if((48 <= NIA[i])&&(NIA[i] < 58)){
            error = FALSE;
            cont++;
        }else{
            error = TRUE;
            break;
        }
        i++;
    }
    
    if((cont > 4)||(cont < 3)){
        error = TRUE;
        printf(ERRORNIA);
    }
    
    return error;
}

/*Función que verifica que un numero de telefono sea de 9 cifras y que no
contenga ni letras ni caracteres especiales.*/
int verificarDades3(char telf[]){
    int i = 0, error, cont = 0;
    while(telf[i] != '\0'){
        if((48 <= telf[i])&&(telf[i] < 58)){
            error = FALSE;
            cont++;
        }else{
            error = TRUE;
            break;
        }
        i++;
    }
    
    if((cont > 9)||(cont < 9)){
        error = TRUE;
        printf(ERRORTEL);
    }
    
    return error;
}

/*Función que verifica que el numero de alumnos que queremos introducir no sea
ni una letra ni un caracter especial.*/
int verificarDades0(char k){
    int error;
    if((48 <= k)&&(k < 58)){
        error = FALSE;
    }else{
        error = TRUE;
    }
    return error;
}