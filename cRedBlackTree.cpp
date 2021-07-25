#include <cctype>
#include <algorithm>
#include "cNode.h"
#include <vector>
#include <fstream>
#include "cRedBlackTree.h"
#include <string>
#include <iostream>

cRedBlackTree::cRedBlackTree(){
    root = NULL;
}

void cRedBlackTree::setRoot(cNode* r) {

	root = r;

}

cNode* cRedBlackTree::getRoot() {

	return root;

}

int cRedBlackTree::serialise(std::ofstream& outfile){

  serialise(outfile, root);
  return 0;
}

int cRedBlackTree::serialise(std::ofstream& fp, cNode* r){
    if(r == NULL){
      fp << "." << std::endl;
      return -1;
    }

    serialise(fp, r->getLeftChild());
    
    fp << "["<< r->getData() << "] = { ";
    
    while( !(r->linhas()->empty()) ){ 
         
      fp <<r->linhas()->front(); 
      r->linhas()->pop(); //retira o elemento da lista
      
      if(!(r->linhas()->empty())) //verifica se tem um próximo, para acrescentar a virgula
        fp <<", ";
    }
      
      fp <<" }\n";      
      
    serialise(fp, r->getRightChild());
    return 0;
}

bool cRedBlackTree::insertNode(std::string d, int linha) {

	return insertNode(&root, d, linha);

}

bool cRedBlackTree::insertNode(cNode** r, std::string d, int linha) {

  if(!palavraValida(d))
    return false;

   cNode* novono = new cNode (d);

   if(novono == NULL)
    return false;

  if(root ==  NULL)
    root = novono;
  
  else{
    cNode *node = root;

    cNode *parent;

    while(node){
      parent = node;
            
      if(node->getData() > d)
        node = node->getLeftChild();

      else if(node->getData() < d)
        node = node->getRightChild();

      else{

      if(node->linhas()->empty()){
        node->linhas()->push(linha);
        return true;
      }

      else if( (node->linhas()->back() != linha) ){
          node->linhas()->push(linha); 
          return true;  
      }
       return true;
      }
    }

    std::string val = parent->getData();

        if(val > d)
            parent->setLeftChild(novono);
    
        else
            parent->setRightChild(novono);

        novono->setParent(parent);
    }

    novono->setColor("RED");
    novono->linhas()->push(linha);
 
    fixUp(novono);

    return true;
}

bool cRedBlackTree::colorFlip(cNode *p, cNode* gr){
    if(p == NULL || gr == NULL)
        return false;

    std::string aux = p->getColor();

    p->setColor(gr->getColor());
    gr->setColor(aux);

    return true;
}

void cRedBlackTree::fixUp(cNode *r){

  cNode *parent = r->getParent();

  cNode *grand_p = nullptr;
    
  while( r != root && parent->getColor() == "RED" && r->getColor() == "RED"){

    grand_p = parent->getParent();

      if(parent == grand_p->getLeftChild()){ 

           cNode *tio = grand_p->getRightChild();    
           //-------------------------------------------------------/
          /*	Caso 1		*/
          if(tio !=NULL && tio->getColor() == "RED"){
              tio->setColor("BLACK");
              grand_p->setColor("RED");
              parent->setColor("BLACK");  
              r = grand_p;  
            }
          //-------------------------------------------------------//
          /*	Caso 2		*/
          else {
              if (r == parent->getRightChild()){
                LeftRotate(parent);
                r = parent;
                parent = r->getParent();
              }
          /* 	Caso 3 */
           
          RightRotate(grand_p);
          colorFlip(parent, grand_p);
          r = parent;  
          }
            
        }

          //-----------------------------------------------------------//
        else{
          	cNode *tio = grand_p->getLeftChild();

          /*     Caso 1      */
          //---------------------------------------------------------//
          	if(tio !=NULL && tio->getColor() == "RED"){
              tio->setColor("BLACK");
              grand_p->setColor("RED");
              parent->setColor("BLACK");  
              r = grand_p;  

          	}
          /* Caso 2*/
          //---------------------------------------------------------//
            else{
                if(r == parent->getLeftChild()){
                    RightRotate(parent);
                    r = parent;
                    parent = r->getParent();
                }
            
                /*      Caso 3      */
            
                LeftRotate(grand_p);
                colorFlip(parent, grand_p);
                r = parent;
            }
        }
    }
    root->setColor("BLACK");
}

void cRedBlackTree::LeftRotate(cNode* r){


        cNode *right = r->getRightChild();

        r->setRightChild(right->getLeftChild());

        if(r->getLeftChild() != NULL)
            (r->getLeftChild())->setParent(right);
        
        right->setParent(r->getParent());

        if(r->getParent() == NULL)
            root = right;

        else if(r == (r->getParent())->getLeftChild())  
            (r->getParent())->setLeftChild(right);

        else
            (r->getParent())->setRightChild(right);

        r->setParent(right);
        right->setLeftChild(r);
}

void cRedBlackTree::RightRotate(cNode *r){

    cNode *left = r->getLeftChild();

        r->setLeftChild(left->getRightChild());

        if(r->getLeftChild())
            (r->getLeftChild())->setParent(left);
        
        left->setParent(r->getParent());

        if(r->getParent() == NULL)
            root = left;

        else if(r == (r->getParent())->getLeftChild())  
            (r->getParent())->setLeftChild(left);

        else
            (r->getParent())->setRightChild(left);

        left->setRightChild(r);
        r->setParent(left);
}

bool cRedBlackTree::palavraValida(std::string d){
	
std::vector <std::string> palavraIn = { "contra",
	"de", "desde", "quando" , "em", "entre", "para","sem", "por", "perante", "sobre", "debaixo", "apesar",
  "lugar", "frente", "defronte", "junto", "perto", "graças", "diante", "entre", "eles", "elas", "ela", "aos"};
  
  char find = 1;

  while (find < 127){
    if (d.find(find) != std::string::npos){
      if(find < 97 || find > 122)
        return false;
    }
    find++;
  }

	for(int i=0; i<palavraIn.size(); i++){
		if(d == palavraIn[i] || d.size() <=4)
			return false;
	}

	return true;
}

bool 	cRedBlackTree::searchValue(std::string d){
  return searchValueRec(root, d);
}

bool cRedBlackTree::searchValueRec(cNode* r, std::string d) {

  if (r == NULL) 
    return false;

  if( r->getData() == d )
    return true;
  
  
  if (d < r->getData())
    return searchValueRec(r->getLeftChild(), d);
  else
    return searchValueRec(r->getRightChild(), d);

}


void cRedBlackTree::insertLineRec(cNode** r, std::string d, int line){
  if ((*r) -> getData() == d){ // Nao precisa
    
    if((*r)->linhas()->empty()){
      (*r)->linhas()->push(line);
      return;
    }
    else
      if( ((*r)->linhas()->back() != line) ){
          (*r)->linhas()->push(line); 
      }
    return;
  }

    if ((*r) -> getData()>d)
      return insertLineRec((*r)->getRefLeftChild(), d, line);
    else
      return insertLineRec((*r)->getRefRightChild(), d, line);
}

void cRedBlackTree::insertLine(std::string d, int line){
  insertLineRec(&root, d, line);
}

bool cRedBlackTree::insertNode(cNode** r, std::string d){
  
    if(!palavraValida(d))
        return false;

    transform(d.begin(), d.end(), d.begin(), ::tolower);

    cNode* novono = new cNode (d);

    if(novono == NULL)
        return false;

    if((*r) ==  NULL)
        (*r) = novono;
  
    else{
        cNode *node = root;

        cNode *parent;

    while(node){
      parent = node;
            
      if(node->getData() > d)
        node = node->getLeftChild();

      else if(node->getData() < d)
        node = node->getRightChild();

    } 
    std::string val = parent->getData();

        if(val > d)
            parent->setLeftChild(novono);
    
        else
            parent->setRightChild(novono);

        novono->setParent(parent);
    }

    novono->setColor("RED");
    
 
    fixUp(novono);

    return true;
}

bool cRedBlackTree::insertNode(std::string d){
  return insertNode(&root,d);
}