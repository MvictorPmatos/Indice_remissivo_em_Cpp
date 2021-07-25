/* Tipos Abstratos e Registros */ 

#include<iostream>
#include "cNoSimpEnc.h"


// ******************************************************
// ***
// ******************************************************
cNoSimpEnc::cNoSimpEnc() { 
	dado = 0;
	prox = NULL;
}


// ******************************************************
// ***
// ******************************************************
cNoSimpEnc::cNoSimpEnc(int dado) {
	this->dado = dado;
	this->prox = NULL;
}



// ******************************************************
// ***
// ******************************************************
cNoSimpEnc::~cNoSimpEnc() {

}

// ******************************************************
// ***
// ******************************************************
void cNoSimpEnc::setDado(int d) {

	dado = d;
}

// ******************************************************
// ***
// ******************************************************
void cNoSimpEnc::setProx(cNoSimpEnc* p) {

	prox = p;

}

// ******************************************************
// ***
// ******************************************************
int  cNoSimpEnc::getDado(){

	return dado;

}

// ******************************************************
// ***
// ******************************************************
cNoSimpEnc*  cNoSimpEnc::getProx() {

	return prox;

}

// ******************************************************
// ***
// ******************************************************
std::ostream &operator<<( std::ostream &output, const cNoSimpEnc &n ) { 

	output << "=====+=====" << std::endl;
	output << "|  " << n.dado << " |  " << n.prox << " | " << std::endl;
	output << "=====+=====" << std::endl;

	return output;            
}
				