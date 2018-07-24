#ifndef ENTRADA_H
#define ENTRADA_H


#include <iostream>
using namespace std;

class Entrada {
// Representa los datos de frecuencia, código binario y código huffman del símbolo de Entrada.  También guarda el valor de repeticiones que indica cuantas veces se ha repetido una entrada.
    
private:

	char simbolo;
	double frecuencia;
	string huffman;
	unsigned int repeticion;
    
public:
        
	//Constructors 
	Entrada();
	/*Pre: cierto*/
	/*Post: El resultado es una Entrada nueva.  La frecuencia es 1, código huffman CHF y repeticion es 1.*/

	Entrada(char a);
	/*Pre: cierto*/
	/*Post: El resultado es una Entrada nueva con el simbolo del parametro directo y con frecuencia 1, codigo huffman CHF y repeticion 1.*/

	//Destructor por defecto
	~Entrada();
	/*Post: Borra automaticamente los objetos locales en salir de un ámbito de visivilidad */

//Modificadores

	void cambia_frecuencia (const double &cont_simbol, const double &total_simbol);
	/*Pre: cierto*/
	/*Post: remplaza la frecuencia con el cociente del número de apariciones de un símbolo del parametro implicito divido por el número total de símbolos.*/

	void modifica_frecuencia(const double &nueva_frecuencia);
	/*Pre: cierto*/
/*Post: remplaza la frecuencia con la del parametro directo.*/

	void cambia_repeticion();
	/*Pre: cierto*/
	/*Post: agrega una unidad a las repeticiones*/

	void cambia_huffman (const string &nuevo_huffman);
	/*Pre: cierto*/
	/*Post: remplaza el código huffman del paramentro implicito.*/




	//Consultores




	double consulta_frecuencia() const;
	/*Pre: cierto*/
	/*Post: Devuelve el valor de la frecuencia del símbolo del parametro implícito*/

	unsigned int consulta_repeticion() const;
	/*Pre: cierto*/
	/*Post: Devuelve el valor de las repeticiones del simbolo del parametro implícito*/

	char consulta_simbolo() const;
	/*Pre: cierto*/
	/*Post: Devuelve el valdor del simbolo del parametro implicito.*/
	
	string consulta_huffman() const;
	/*Pre: cierto*/
	/*Post: Devuelve es el valor del código huffman del símbolo del parametro implícito*/





	//Entrada y Salida




	friend ostream& operator<<(ostream &os, Entrada &e);
	/* Pre: cierto */
	/* Post: Escribe los detalles de la Entrada en el formato adecuado */
	/* Ejemplo de formato:Simbol:a, Frequencia: 0.666667, Codificacio: 
 */

};

#endif
