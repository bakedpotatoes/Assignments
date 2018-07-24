#include "Entrada.h"

// Constructores

Entrada::Entrada()
/*Pre: cierto*/
/*Post: El resultado es una Entrada nueva.  La frecuencia es 1, código huffman CHF y repeticion es 1.*/
{
	frecuencia=1;
	huffman="";
	repeticion=1;
}

Entrada::Entrada(char a)
/*Pre: cierto*/
/*Post: El resultado es una Entrada nueva con el simbolo del parametro directo y con frecuencia 1, codigo huffman CHF y repeticion 1.*/
{
	simbolo=a;
	frecuencia=1;
	huffman="";
	repeticion=1;
}

//Destructor

Entrada::~Entrada(){}
/*Post: borra automaticamente los objetos locales en salir de un ámbito de visibilidad.*/

//Modificadores

void Entrada::cambia_frecuencia(const double &cont_simbol,const double &total_simbol)
/*Pre: cierto*/
/*Post: remplaza la frecuencia con el cociente del número de apariciones de un símbolo del parametro implicito divido por el número total de símbolos.*/
{
	double answer=cont_simbol/total_simbol;
	frecuencia=answer;
}

void Entrada::modifica_frecuencia(const double &nueva_frecuencia)
/*Pre: cierto*/
/*Post: remplaza la frecuencia con la del parametro directo.*/
{
	frecuencia=nueva_frecuencia;
}

void Entrada::cambia_repeticion()
/*Pre: cierto*/
/*Post: agrega una unidad a las repeticiones*/
{
	repeticion=repeticion+1;
}

void Entrada::cambia_huffman(const string &nuevo_huffman)
/*Pre: cierto*/
/*Post: remplaza el código huffman del paramentro implicito.*/
{
	huffman=nuevo_huffman;
}


//Consultores

double Entrada::consulta_frecuencia() const
/*Pre: cierto*/
/*Post: Devuelve el valor de la frecuencia del símbolo del parametro implícito*/
{
return frecuencia;
}

unsigned int Entrada::consulta_repeticion() const
/*Pre: cierto*/
/*Post: Devuelve el valor de las repeticiones del simbolo del parametro implícito*/
{
	return repeticion;
}

char Entrada::consulta_simbolo() const
/*Pre: cierto*/
/*Post: Devuelve el valdor del simbolo del parametro implicito.*/
{
	return simbolo;
}

string Entrada::consulta_huffman() const
/*Pre: cierto*/
/*Post: Devuelve el valor del código huffman del símbolo del parametro implícito*/
{
	return huffman;
}

ostream& operator<<(ostream &os, Entrada &e)
/* Pre: cierto */
/* Post: Escribe los detalles de la Entrada en el formato adecuado */
/* Ejemplo de formato: Entrada 0. Simbol:a, Frequencia: 0.666667, Codificacio: */
{
	os<<"Simbol:"<<e.consulta_simbolo()<<", Frequencia: "<<e.consulta_frecuencia()<<", Codificacio: "<<e.consulta_huffman();

 	return os;
}
