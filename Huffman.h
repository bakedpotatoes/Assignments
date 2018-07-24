#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "arbre.h"
#include "CuaP.h"
#include "Entrada.h"

class Huffman {
// Representa un arbol Huffman.
    
private:
    
	arbre <Entrada> H;

public:
        
	Huffman();
	/*Post: un Huffman vacio*/
	Huffman(arbre<Entrada> A);


	void crea_Huffman(CuaP &Q);
	/*Pre: una CuaP*/
	/*Post: un Huffman basado en la CuaP*/

	void actualiza_huffman(string &s, TaulaFreq &T);

// Destructores

	~Huffman();
	/*Post: Borra automaticamente los objetos locales en salir de un ámbito de visivilidad */

// Modificadores

	
};


#endif
