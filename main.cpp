#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include "cNode.h"
#include "cRedBlackTree.h"


#define LINHAS 15
#define PAGINAS 50
#define TEXTO 12000

using namespace std;

std::string f(std::string w){

    char v[] = {'.', ',', '"', '?', '!', ':', '"'};

    for(int i=0; i<7; i++){
        w.erase(std::remove(w.begin(), w.end(), v[i]), w.end());
    }
    transform(w.begin(), w.end(), w.begin(), ::tolower);

    return w;

}
int main(int argv, char** argc) {

  std::string arquivo =  "pequeno.txt";

  std::string chave = "chave-pequeno0.txt";

  std::ifstream ifs(arquivo);
  std::ifstream arq(chave);
  std::string p;
  int c;
  std::string palavraC;
  std::string w;
  int count = 0;
  std::string word;


 cRedBlackTree arv;
    if (!arq) {
	    std::cout << "Não foi possível abrir o arquivo de chaves. Rodaremos o algoritmo padrão do programa! " <<std::endl;
        if (!ifs) {
	        std::cout << "Não é possível abrir o arquivo do texto" <<std::endl;
	        exit(EXIT_FAILURE);
	    }

   

        while (ifs >> w)
	        count++;
           

        ifs.close();

        /*Se o arquivo é pequeno ou médio armazena apenas as linhas */
        ifs.open(arquivo);

        if ( !ifs )
            return 0;

        int linha = 1;  int pagina =1;
        if(count < TEXTO){
            count = 0;
            while ( ifs >> word ){
                arv.insertNode(f(word),linha);
                count++;
                if(count == LINHAS){
                    linha++;
                    count = 0;
                }
            }
        }
        /* Se o arquivo é grande armazena apenas páginas*/
        else{
            linha =1; count = 0;
            while(ifs >> word){
                arv.insertNode(f(word), pagina);

                count++;
                if(count == LINHAS){
                    linha++;
                    count = 0;
            
                    if(linha == PAGINAS){
                        pagina++;
                        linha = 0;
                    }
                }
            }
        }   

        /* Gera o arquivo de saída */
        std::ofstream indice("indice.txt");
        arv.serialise(indice);
        indice.close();

        return 0;
    } else{
              
        while (arq >> p)
	        c++;

        arq.close();

        arq.open(chave);

        if ( !arq )
            return 0;
        while ( arq >> palavraC ){
            arv.insertNode(palavraC);
        }

        if (!ifs) {
	        std::cout << "Não é possível abrir o arquivo do texto" <<std::endl;
	        exit(EXIT_FAILURE);
	    }
	
        while (ifs >> w)
	        count++;

        ifs.close();

        /*Se o arquivo é pequeno ou médio armazena apenas as linhas */
        ifs.open(arquivo);

        if ( !ifs )
            return 0;

        int tam = count;

        int linha = 1;  int pagina =1;
        if(count < TEXTO){
            count = 0;
            while ( ifs >> word ){
                if(arv.searchValue(f(word))){
                    //Método que guarda linha
                    arv.insertLine(f(word), linha);
                }
                count++;
                if(count == LINHAS){
                    linha++;
                    count = 0;
                }
            }
        }
        /* Se o arquivo é grande armazena apenas páginas*/
        else{
            linha =1; count = 0;
            while(ifs >> word){
                if(arv.searchValue(f(word))){
                    arv.insertLine(f(word), pagina);
                }

                count++;
                if(count == LINHAS){
                    linha++;
                    count = 0;
            
                    if(linha == PAGINAS){
                        pagina++;
                        linha = 0;
                    }
                }
            }
        }   

        /* Gera o arquivo de saída */
        std::ofstream indice("indice.txt");
        arv.serialise(indice);
        indice.close();

        return 0;
    }

  return 0;
}
