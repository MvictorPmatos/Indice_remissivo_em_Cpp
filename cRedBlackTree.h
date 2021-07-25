#include "cNode.h"
#include <vector>
#include <fstream>  



class cRedBlackTree{

    private:
        cNode* root;
        void LeftRotate(cNode *r);
        void RightRotate(cNode *r);
        void fixUp(cNode *r);
        bool colorFlip(cNode *p, cNode* gr);
        int  serialise(std::ofstream& fp, cNode *r);
        bool insertNode(cNode** r, std::string d, int linha);
		bool searchValueRec(cNode* r, std::string d);
		bool palavraValida(std::string d);
        void insertLineRec(cNode** r, std::string d ,int linha);
		bool insertNode(cNode** r, std::string d);
		
		

    public:
        cRedBlackTree();
        bool 	  insertNode(std::string d, int linha);
		bool 	  searchValue(std::string d);
        int 	  serialise(std::ofstream& outfile);
		void      insertLine(std::string d ,int linha);
		bool      insertNode(std::string d);
        void 	  setRoot(cNode* r);
		cNode* 	  getRoot();
		
};
