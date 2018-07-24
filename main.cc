#include "Huffman.h"
#include <iostream>

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
		tb.actualiza_frecuencia();
		cout<<"----------->> CONSTRUINT TAULA... "<<endl;
		tb.escribir_taula();
		CuaP E;
		E.CuaP_desde_TaulaFreq(tb);
		E.ordena_CuaP(100000000000);
		cout<<"----------->> CREANT CUA INICIAL... \n\n----------->> ... Resultat cua inicial."<<endl;
		E.escribe_CuaP();
		Huffman H;
		cout<<"----------->> CREANT ARBRE HUFFMAN"<<endl;
		H.crea_Huffman(E);
		string s="";
		H.actualiza_huffman(s,tb);
		tb.escribir_taula();

	}	
}

