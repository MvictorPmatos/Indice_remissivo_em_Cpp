/* Classe Lista Simplesmente Encadeada */ 

#pragma once

#include<iostream>
#include "cNoSimpEnc.h"


class cLinhas	{ 

	private:
		cNoSimpEnc* inicio;    	// indica a primeira posicao da lista 
    cNoSimpEnc* fim;
  	int  numElem;   		// Total de posicoes alocadas

	public:	
		cLinhas();

		~cLinhas();

		bool push(int dado);

		bool pop();

    int front();

    int back();
    
    int tamanho();

    bool empty();

};
