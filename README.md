[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=424594&assignment_repo_type=GroupAssignmentRepo)
# Problema 2

## Indexando um texto
Indexando um texto é uma aplicação que permite ler um arquivo no formato ASCII, e, a partir deste, criar outro arquivo de saída que contenha o índice remissivo das palavras relevantes identificadas, bem como as linhas ou páginas que estão localizadas. As estruturas de dados escolhidas para implementar a aplicação foi um árvore balanceada rubro-negra e uma fila com o endereço do primeiro e o último elemento.
 
# Classes Utilizadas e métodos:
 
## cRedBlackTree
Responsável por armazenar as palavras chaves identificadas. Sendo uma árvore balanceada, os nós são inseridos de modo a garantir que todos os caminhos até a folha sejam equilibrados. A cada inserção, utilizando o método *insertNode*, as letras da palavra são transformadas em minúsculas, verificado se é uma palavra válida, e se satisfaz as propriedades da árvore rubro-negra através do *fixUp*, caso alguma propriedade seja violada os métodos *leftRotate*, *rightRotate*, ou *colorflip* são aplicados dependendo do caso. Para armazenar apenas as linhas é utilizado *insertLine*.
 
Para gerar o índice remissivo em um arquivo externo, foi criado o método *serialise*, que percorre a árvore em ordem alfabética e retorna as palavras associadas às linhas/páginas do texto.
 
O método *palavraValida* define se a palavra pode ou não ser inserida na árvore através de algumas propriedades definidas. Por fim, o método *searchValue* busca as palavras chaves dentro do texto.
 
## cNode
Classe responsável pela criação de um único nó. Para a aplicação foi definido que o nó precisa conter a palavra (data), a cor (color), o endereço do nó pai (parent), o filho esquerdo (left), o filho direito (right) e as linhas ou páginas (linhas). Para acessar essas informações utilizamos o método *get* e para defini-las *set*.
 
## cLinhas
A classe armazena os dados associados a cada página ou linha do texto. Tem comportamento de uma fila. Para inserir uma nova linha/página no final da fila tem-se o método *push*, já o *pop* remove os elementos do topo da fila. *Front* e *back* dão acesso ao primeiro e último elemento, respectivamente. O método *empty* verifica se a lista é vazia, do contrário retorna falso, e o *tamanho* retorna a quantidade de elementos inseridos. Cada valor inserido é criado um novo nó, que pertence à classe *cNoSimpEnc*.
 
## Main.cpp
Arquivo principal do programa, onde é definido o número de palavras máximas para uma linha, o número de linhas que definem uma página e o máximo de palavras para um texto pequeno ou médio. É criado uma função para eliminar os caracteres indesejados associados à palavra. Depois inicializa as variáveis e objetos importantes para o funcionamento da aplicação. Para intermediar a leitura e criação de arquivos foi utilizado a biblioteca *fstream*. Caso não ocorram erros, o arquivo é aberto e as palavras identificadas são inseridas na árvore rubro-negra e no final é gerado um arquivo com o índice remissivo.