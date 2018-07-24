#ifndef TAULAFREQ_H
#define TAULAFREQ_H
#include "Entrada.h"
#include <vector>

class TaulaFreq {
// Representa los datos de Entrada en una tabla y guarda el valor de precision.
    
private:
    
	vector<Entrada> tb;
	double precision;	
    
public:




// Constructores




TaulaFreq(Entrada a);
/*Pre: cierto*/
/*Post: El resultado es una tabla nueva con la primera Entrada del parametro directo.*/




//Destructor




~TaulaFreq();
/*Post: borra automaticamente los objetos locales en salir de un ámbito de visibilidad.*/




//Modificadores


void modifica_Entrada(const unsigned int &j, const string huffman);


void agrega_Entrada(Entrada a);
/*Pre: cierto*/
/*Post: el resultado es cociente del número de apariciones de un símbolo del parametro implicito divido por el número total de símbolos.*/

void actualiza_frecuencia();
/*Pre: cierto*/
/*Post: actualiza todas las frecuencias de la tabla*/




//Consultores




double consulta_precision() const;
/*Pre:cierto*/
/*Post: Devuelve la precision dinámica para el radix sort*/



Entrada consulta_Entrada(const unsigned int &j) const;
/*Pre: 0 < j <= número de elementos en la tabla de frecuencias.*/
/*Post: el resultado es la Entrada en la posición [j] del parametro implicito*/

unsigned int consulta_size() const;
/*Pre: cierto*/
/*Post: devuelve el número de elementos en la tabla.*/




//Entrada y Salida




void escribir_taula();
/*Pre: cierto*/
/*Post: escribe el contenido de la table del parametro implicito en la pantalla*/

/*
Ejemplo de plantilla:

 Bolcat taula frequencies ---->

 Mida: 3 simbols 
Entrada 0. Simbol:a, Frequencia: 0.666667, Codificacio: 
Entrada 1. Simbol:b, Frequencia: 0.166667, Codificacio: 
Entrada 2. Simbol:c, Frequencia: 0.166667, Codificacio: 
----> Fi bolcat taula
*/

};

#endif
