#include "arbre.h"
#include "TaulaFreq.h"
#include "CuaP.h"
#include <queue>




// Constructores




CuaP::CuaP()
/*Pre: cierto*/
/*Post: devuelve una cola vacia.*/
{
	p_primero=NULL;
	p_ultimo=NULL;
	size=0;
}


void CuaP::CuaP_desde_TaulaFreq(TaulaFreq Taula){
/*Pre: una Tabla de frecuencias con al menos un elemento.*/
/*Post: devuelve una cola a partir de los datos de la tabla.*/
	node_CuaP *n, *prev;
	size = Taula.consulta_size();
	n = new node_CuaP;
	n->T = arbre<Entrada> (Taula.consulta_Entrada(0), arbre<Entrada> (),arbre<Entrada> ());
	n->p_anterior = NULL;
	p_primero = n;
	p_ultimo = n;
	prev =n;

	unsigned int j=1;

	//Invariant: los elementos de la tabla desde indice 0 hasta elemento j han sido agregados a la CuaP.
	//Función de fita: El ultimo elemento de la Tabla de frecuencia -j.

	while (j<size){
		n= new node_CuaP;
		n->T = arbre<Entrada>(Taula.consulta_Entrada(j),arbre<Entrada> (),arbre<Entrada> ());
		n->p_anterior = prev;
		prev->p_siguiente = n;
		prev = n;
		j=j+1;
	}

	p_ultimo = n;
	n->p_siguiente = NULL;
}


//Modificadores

arbre<Entrada> CuaP::modifica_arbol (const string &cual)
/*Pre: una CuaP no vacia*/
/*Post: Devuelve el puntero al árbol.*/
{
	node_CuaP *n;
	n=p_primero;
	if (cual=="primero"){
		n=p_primero;
	}
	if (cual=="segundo"){
		n=n->p_siguiente;
	}

	return n->T;
}




void CuaP::ordena_CuaP(const double &precision)
{
	arbre<Entrada> E;
	
	if (precision!=1){

		vector<queue <arbre <Entrada> > > buckets(10);
		node_CuaP *p_actual;
		p_actual=p_primero;

		while (p_actual!=NULL){
			//Declaraciones:
			node_CuaP *E;
			E=new node_CuaP ; 
			E->T=p_actual->T;
			double position=E->T.arrel().consulta_frecuencia();
			position=position*precision;
			int position1=(unsigned int)position%10/1;
			buckets[position1].push(E->T);
			p_actual=p_actual->p_siguiente;
			p_primero=p_actual;
		}
		
		unsigned int l=0;

		bool first=true;
		node_CuaP *n, *previo; 
		n= new node_CuaP;
		while (l<10){
			if (buckets[l].size()>0){
				if ((first) and (not buckets[l].empty())){
					n= new node_CuaP;
					n->T=buckets[l].front();
					n->p_anterior=NULL;
					p_primero=n;
					p_ultimo=n;
					previo=n;
					first=false;
					buckets[l].pop();
				}
				while (not buckets[l].empty()){
					n=new node_CuaP;
					n->T=buckets[l].front();
					n->p_anterior=previo;
					previo->p_siguiente=n;
					p_ultimo=n;
					previo=n;
					n->p_siguiente=NULL;
					buckets[l].pop();
				}
			}
			l=l+1;
		}

		ordena_CuaP(precision/10);
	}
}


void CuaP::agrega_node(const arbre<Entrada> &New_Tree)
{
	node_CuaP *n=new node_CuaP;
	n->T=New_Tree;
	size=size+1;

	if (p_primero==NULL){
		p_primero=n;
		p_ultimo=n;
	}
	else {
		n->p_anterior=p_ultimo;
		p_ultimo->p_siguiente=n;
		n->p_siguiente=NULL;		
	}
}

void CuaP::quita_primer_nodo()
/*Pre: una CuaP*/
/*Post: elimina el primero nodo.*/
{
	
	if (size>0){
		node_CuaP *n;
		n=new node_CuaP;
		n=p_primero;
		p_primero=n->p_siguiente;
		n->p_siguiente->p_anterior=NULL;
		size=size-1;
		delete n;
	}
}




//Consultores



unsigned int CuaP::consulta_size ()
/*Pre: cierto*/
/*Post: devuelve el tamaño de un arbol*/
{
	return size;
}

arbre<Entrada> CuaP::consulta_primero ()
/*Pre: una CuaP no vacia*/
/*Post: el árbol del primero elemento.*/
{
	node_CuaP *n;
	n=p_primero;
	return n->T;
}

arbre<Entrada> CuaP::consulta_segundo ()
/*Pre: una CuaP no vacia*/
/*Post: el árbol del primero elemento.*/
{
	node_CuaP *n;
	n=p_primero->p_siguiente;
	return n->T;
}

void CuaP::escribe_CuaP()
/*Pre: cierto*/
/*Post: escribe por la pantalla los datos de la CuaP*/
{
	//Invariant: los elementos de la queue del parametro implicito han sido escritos por la pantalla.
	//función de fita: pq.empty()

	node_CuaP *aux;
	aux=p_primero;
	while (aux!=NULL){
		Entrada T_actual = aux->T.arrel();
		cout<<"Simbol:"<<T_actual.consulta_simbolo()<<", Frequencia: "<<T_actual.consulta_frecuencia()<<", Codificacio: "<<endl;
		aux=aux->p_siguiente;
	}
	cout<<endl;
}


//Operadores


