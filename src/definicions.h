// ----------- LIBRERÍAS ------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ---------- DEFINICIONES ----------

#define TRUE         1      // Cert per variables booleanes
#define FALSE        0      // Fals per variables booleanes

#define MAXNOM       100    //Máxima longitud del nombre del alumno
#define MAXNIA       5      //Máxima longitud del NIA del alumno
#define MAXTELF      10      //Máxima longitud del telefono del alumno      

#define ERRORNUM "ERROR.\nPor favor, introduzca un número dentro del rango.\n"
#define ERRORNOM "ERROR.\nPor favor, introduzca un nombre sin numeros ni caracteres especiales.\n"
#define ERRORNIA "ERROR.\nEl identificador del alumno debe ser de entre 3 y 4 cifras.\n"
#define ERRORNIA2 "ERROR.\nEl NIA no debe contner ni letras ni caracteres especiales.\n"
#define ERRORTEL "ERROR.\nEl número de teléfono del alumno debe ser un número de 9 cifras.\n"
#define ERRORTEL2 "ERROR.\nEl número de teléfono no debe contener ni caracteres especiales ni letras.\n"
#define ERRORARB "ERROR.\nEl árbol está vacío.\n"
#define ERRORREP "ERROR.\nEl NIA introducido ya existe, introduzca otro NIA por favor.\n"
#define ERRORALUM "ERROR.\nEl Alumno solicitado no se encuentra en la base de datos.\n"


// ---------- ESTRUCTURAS ----------

struct nodo{ // Definimos cada nodo del árbol como un struct con los campos nia, nombre y telefono
	int NIA;
	char nom[MAXNOM];
	int telefon;
	int altura;
	struct nodo *hijo_izq;
	struct nodo *hijo_der;
};


// ---------- DECLARACIONES ----------

void menu_principal();
int errorMenu(char resp);
struct nodo* buscar(int NIA, struct nodo* arbol);
int es_vacio(struct nodo* arbol);
int getAltura(struct nodo *arbol);
int max(int num1, int num2);
struct nodo* nuevoNodo(int Nia, int telf, char Nomb[]);
struct nodo* rotacion_simple_derecha(struct nodo* n2);
struct nodo* rotacion_simple_izquierda(struct nodo* n2);
struct nodo* rotacion_doble_DerIzq(struct nodo* n2);
struct nodo* rotacion_doble_IzqDer(struct nodo* n2);
int dif_altura(struct nodo* arbol);
struct nodo* insertar_nodo(struct nodo* nodo, int NIA, int telf, char Nomb[]);
void Preorden(struct nodo *arbol);
void Inorden(struct nodo* arbol);
void Postorden(struct nodo *arbol);
int verificarDades0(char k);
int verificarDades1(char *Nom);
int verificarDades2(char NIA[]);
int verificarDades3(char telf[]);