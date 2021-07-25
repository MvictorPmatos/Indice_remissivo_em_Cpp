/* Classe No de uma Lista Simplesmente Encadeada */ 

#pragma once

#include<iostream>
#include "cNoSimpEnc.h"

class cNoSimpEnc {
  private: 
    int dado;
    cNoSimpEnc* prox;

  public:
  	cNoSimpEnc();
    cNoSimpEnc(int dado);
  	~cNoSimpEnc();
    
  	void setDado(int d);
  	void setProx(cNoSimpEnc* p);
  	int  getDado();
  	cNoSimpEnc* getProx();

	friend std::ostream &operator<<( std::ostream &output, const cNoSimpEnc &n);

};
