#include<iostream>
#include "cLinhas.h"
#include "cNoSimpEnc.h"

// ******************************************************
// ***
// ******************************************************
cLinhas::cLinhas()  { 
  inicio  = NULL;
  fim = NULL; 
  numElem = 0;
}

// ******************************************************
// ***
// ******************************************************
cLinhas::~cLinhas() { 

}

// ******************************************************
// ***
// ******************************************************
bool cLinhas::push(int dado)  { 

  cNoSimpEnc* novoNo = new cNoSimpEnc(dado); 
     
  if(novoNo == NULL)
      return false; 

  if (inicio == NULL){
    inicio = novoNo;
    fim = novoNo;
    numElem++;
    return true;
  }

  fim->setProx(novoNo);
  fim = novoNo;  
  numElem++;
  return true;
}

// ******************************************************
// ***
// ******************************************************

// ******************************************************
// ***
// ******************************************************
bool cLinhas::pop()  {  
  

  if (inicio != NULL){
    cNoSimpEnc* apagar = inicio;
    inicio = inicio->getProx();
    
    if(inicio == NULL)
      fim = NULL;

    delete apagar;
    numElem--;
    return true;

  }else 
    return false;
  
    
  return false;
}
// ******************************************************
// ***
// ******************************************************

int cLinhas::back(){
  return fim->getDado();
}

int cLinhas::front(){

  return inicio->getDado();
}
// ******************************************************
// ***
// ******************************************************
int cLinhas::tamanho() {
  
  return (numElem);
}

bool cLinhas::empty() {
  if(numElem == 0)
    return true;
  else
    return false; 
}
