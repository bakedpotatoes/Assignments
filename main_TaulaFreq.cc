#include <iostream>
#include "Entrada.h"
#include "TaulaFreq.h"
#include "CuaP.h"

using namespace std;

int main(){
	//Declarations
	string line;
	
	getline(cin,line);
	
	if (line.size()>0){
		TaulaFreq tb=TaulaFreq(line[0]);
		unsigned int j=1;
		while (j<line.size()){
			Entrada c=Entrada(line[j]);
			tb.agrega_Entrada(c);
			j=j+1; 
		}
		cout<<"Tabla Completo"<<endl;
		tb.actualiza_frecuencia();
		tb.escribir_taula();
	}
}
