#ifndef CUAP_H
#define CUAP_H
#include "arbre.h"
#include "Entrada.h"
#include "TaulaFreq.h"
#include <queue>

class CuaP {
// Represents una CuaP de arboles con la prioridad según la frecuencia.

private:

	struct node_CuaP{
		arbre<Entrada> T;
		node_CuaP *p_siguiente;
		node_CuaP *p_anterior;		
	};
	unsigned int size;
	node_CuaP *p_primero;
	node_CuaP *p_ultimo;
	double precision;

public:




// Constructores




CuaP();
/*Pre: cierto*/
/*Post: devuelve una cola vacia.*/

void CuaP_desde_TaulaFreq(TaulaFreq Taula);
/*Pre: una Tabla de frecuencias con al menos un elemento.*/
/*Post: devuelve una cola a partir de los datos de la tabla.*/




//Modificadores


arbre<Entrada> modifica_arbol (const string &cual);
/*Pre: una CuaP no vacia*/
/*Post: Devuelve el puntero al árbol.*/

void ordena_CuaP(const double &precision);
/*Pre: una CuaP de arbre<Entradas>, y precision que representa el número de digitos despues de la coma de la frecuencia.*/
/*Post: la CuaP ordenado de menor a mayor frecuencia*/

void agrega_node(const arbre<Entrada> &New_Tree);
/*Pre:cierto*/
/*Post: devuelve la queue del parametro implicito con el elemento agregado*/

void quita_primer_nodo();
/*Pre: una CuaP*/
/*Post: elimina el primero nodo.*/




//Consultores




unsigned int consulta_size ();
/*Pre: cierto*/
/*Post: devuelve el tamaño de un arbol*/

arbre<Entrada> consulta_primero ();
/*Pre: una CuaP no vacia*/
/*Post: el árbol del primero elemento.*/

arbre<Entrada> consulta_segundo ();
/*Pre: una CuaP no vacia*/
/*Post: el árbol del primero elemento.*/

void escribe_CuaP();
/*Pre: cierto*/
/*Post: escribe por la pantalla los datos de la CuaP*/




//Operadores




};

#endif
