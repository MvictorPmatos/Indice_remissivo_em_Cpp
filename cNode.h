#pragma once
#include <iostream>
#include <string>
#include <list>
#include "cLinhas.h"

class cNode	{ 	

private:
	std::string data;
	std::string color;
	cNode* parent;
  	cNode* left;
  	cNode* right;
 	cLinhas* lista;

public:

	cNode();
	cNode(std::string d, int l);
	cNode(const cNode& n);
	cNode(std::string d);

	void 	setLeftChild(cNode* node);
	cNode* 	getLeftChild();
	cNode**	getRefLeftChild();

	void 	setParent(cNode* node);
	cNode* 	getParent();
	cNode**	getRefParent();

	void 	setRightChild(cNode* node);
	cNode* 	getRightChild();
	cNode**	 getRefRightChild();

	void 	setData(std::string d);
	std::string getData();

  
    cLinhas* linhas();
	
	void	setColor(std::string c);
	std::string getColor();


	friend std::ostream &operator<<( std::ostream &output, const cNode &n);


};