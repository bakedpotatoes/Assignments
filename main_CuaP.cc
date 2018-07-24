#include "CuaP.h"
#include "TaulaFreq.h"
#include "Entrada.h"
#include <iostream>

using namespace std;

int main(){

	//Declarations
	CuaP E;
	string line;
	

	//Invariant: los strings leidos por el canal de entrada.
	//Función de fita: la ultima línea leido por el canal.
	while (getline(cin, line)){
		if (line.size()>0){

			TaulaFreq tb=TaulaFreq(line[0]);
			unsigned int j=1;

			//Invariant: los elementos de 0<j han sido agregados a la tabla.
			//Función de fita: el último indice.

			while (j<line.size()){
				Entrada c=Entrada(line[j]);
				tb.agrega_Entrada(c);
				j=j+1; 
			}
			tb.actualiza_frecuencia();

			CuaP E;
			E.CuaP_desde_TaulaFreq(tb);
			E.ordena_CuaP(100000000000);
			E.escribe_CuaP();
		}
	}
}
