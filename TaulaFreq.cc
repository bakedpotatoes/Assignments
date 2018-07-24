#include "TaulaFreq.h"
#include "Entrada.h"
#include <vector>
#include <iostream>

using namespace std;




// Constructores




TaulaFreq::TaulaFreq(Entrada a)
/*Pre: Cert*/
/*Post: El resultado es una tabla nueva con la primera Entrada del parametro directo.*/
{

	tb.push_back(a);
}




//Destructor




TaulaFreq::~TaulaFreq(){}
/*Post: borra automaticamente los objetos locales en salir de un ámbito de visibilidad.*/




//Modificadores

void TaulaFreq::modifica_Entrada(const unsigned int &j, const string huffman)
/*Pre: cert*/
/*Post: el resultado es la Entrada en la posición [j] del parametro implicito*/
{
	tb[j].cambia_huffman(huffman);
}




void TaulaFreq::agrega_Entrada(Entrada a)
/*Pre: cierto*/
/*Post: Agrega un elemento a la Tabla de Frecuencias.  Si el elemento ya existe, modifica el número de repeticiones en la tabla.*/
{
	unsigned int j=0;
	unsigned int end=tb.size();
	unsigned int position=0;
	bool found=false;

	//Invariant: los elementos desde el primero de la tabla hasta el indice j, han sido visitados.
	//Funcion de fita: El elemento ha sido encontrado con el bool found, j=end, el último elemento en la tabla.
	while ((j<end) and (not found)){
		if (tb[j].consulta_simbolo()==a.consulta_simbolo()){
			position=j;
			found=true;
		}
		j=j+1;
	}
	if (not found){
		tb.push_back(a);
	}
	else{
		tb[position].cambia_repeticion();

	}
}

void TaulaFreq::actualiza_frecuencia()
/*Pre: cert*/
/*Post: actualiza todas las frecuencias de la table*/
{
	unsigned int j=0;
	double b=0;
	//Invariant: las repeticiones han sido acumuladas hasta el indice j.
	//Funcio de fita: el último elemento de la tabla.	
	while (j<tb.size()){
		b=b+tb[j].consulta_repeticion();
		j=j+1;
	}
	j=0;
	//Invariant: las frecuencias han sido actualizados con el cociente hasta indice j.
	//Función de fita: el último elemento de la tabla.
	while (j<tb.size()){
		tb[j].cambia_frecuencia(tb[j].consulta_repeticion(),b);
		j=j+1;
	}
}




//Consultores




double TaulaFreq::consulta_precision() const
/*Pre:cierto*/
/*Post: Devuelve la precision dinámica para el radix sort*/
{
	return precision;
}


Entrada TaulaFreq::consulta_Entrada(const unsigned int &j) const
/*Pre: cert*/
/*Post: el resultado es la Entrada en la posición [j] del parametro implicito*/
{
return tb[j];
}

unsigned int TaulaFreq::consulta_size() const
/*Pre: cert*/
/*Post: retorna el número de elementos en la tabla.*/
{
	unsigned int answer=tb.size();
	return answer;
}




//Entrada y Salida




void TaulaFreq::escribir_taula()
/*Pre: cert*/
/*Post: escribe el contenido de la table del parametro implicito en la pantalla*/

/*

 Bolcat taula frequencies ---->

 Mida: 3 simbols 
Entrada 0. Simbol:a, Frequencia: 0.666667, Codificacio: 
Entrada 1. Simbol:b, Frequencia: 0.166667, Codificacio: 
Entrada 2. Simbol:c, Frequencia: 0.166667, Codificacio: 
----> Fi bolcat taula

*/
{
	cout<<endl;
	cout<<" Bolcat taula frequencies ---->"<<endl;
	cout<<endl;
	actualiza_frecuencia();
	cout<<" Mida: "<<tb.size()<<" simbols "<<endl; 
	unsigned int j=0;
	while (j<tb.size()){
		cout<<"Entrada "<<j<<". "<<tb[j]<<endl;
		j=j+1;
	}
	cout<<"----> Fi bolcat taula"<<endl;
	cout<<endl;
}

