#include "arbre.h"
#include "Huffman.h"
#include "Entrada.h"
#include "CuaP.h"
#include "iostream"


// Constructores



Huffman::Huffman()
{
}

Huffman::Huffman(arbre<Entrada> A)
{
	H=A;
}

void Huffman::crea_Huffman(CuaP &Q)
{
	//Q.escribe_CuaP();
	if (Q.consulta_size()<2){
	}
	else if (Q.consulta_size()>2){
		Entrada E=Entrada();
		E.modifica_frecuencia(Q.consulta_primero().arrel().consulta_frecuencia()+Q.consulta_segundo().arrel().consulta_frecuencia());
		H=arbre<Entrada>(E,Q.consulta_primero(), Q.consulta_segundo());
		Q.agrega_node(H);
		Q.quita_primer_nodo();
		Q.quita_primer_nodo();
		Q.ordena_CuaP(100000000);
		crea_Huffman(Q);
	}
	else {	
		Entrada E;
		E.modifica_frecuencia(Q.consulta_primero().arrel().consulta_frecuencia()+Q.consulta_segundo().arrel().consulta_frecuencia());
		H=arbre<Entrada>(E,Q.consulta_primero(), Q.consulta_segundo());
		Q.agrega_node(H);
		Q.quita_primer_nodo();
		Q.quita_primer_nodo();
	}
}


void Huffman::actualiza_huffman(string &s, TaulaFreq &T)
{
	bool found=false;
	if (H.fd().es_buit() and H.fe().es_buit()){
		unsigned int j=0;
		while ((j<T.consulta_size()) and not found){
			if (T.consulta_Entrada(j).consulta_simbolo()==H.arrel().consulta_simbolo()){
				T.modifica_Entrada(j,s);
				found=true;
			}
			else{
				j=j+1;
			}
		}
	}
	else{
		string s1,s2;
		s1=s+'0';
		s2=s+'1';
		Huffman(H.fe()).actualiza_huffman(s1,T);
		Huffman(H.fd()).actualiza_huffman(s2,T);
	}
}




// Destructores

Huffman::~Huffman(){}
	/*Post: Borra automaticamente los objetos locales en salir de un ámbito de visivilidad */





// Modificadores


