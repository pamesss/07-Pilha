#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
  int valor;
  NO *prox;
};

NO *topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
//--------------------------

int main() { menu(); }

void menu() {
  int op = 0;
  while (op != 4) {
    cout << "\n\nMenu Pilha";
    cout << endl << endl;
    cout << "1 - Inicializar Pilha \n";
    cout << "2 - Inserir elemento (Push) \n";
    cout << "3 - Remover elementos (Pop) \n";
    cout << "4 - Sair \n";

    cout << "Opcao: ";
    cin >> op;

    switch (op) {
    case 1:
      inicializar();
      break;
    case 2:
      push();
      break;
    case 3:
      pop();
      break;
    case 4:
      return;
    default:
      break;
    }
  }
}

void inicializar() {

  // se a lista já possuir elementos
  // libera a memoria ocupada
  NO *aux = topo;
  while (aux != NULL) {
    NO *paraExcluir = aux;
    aux = aux->prox;
    free(paraExcluir);
  }

  topo = NULL;
  cout << "Pilha inicializada \n";
}

void push() {
  // aloca memoria dinamicamente para o novo elemento
  NO *novo = (NO *)malloc(sizeof(NO));
  if (novo == NULL) {
    return;
  }

  cout << "Digite o elemento: ";
  cin >> novo->valor;
  novo->prox = NULL;
}

void pop() {
  // puxa o primeiro elemento da pilha
  NO *aux = topo;

  // se estiver vazio, imprime lista vazia
  while (topo != NULL) {
    // remove o elemento
    topo = topo->prox;
    // libera a memoria
    free(aux);
    cout << "Elemento removido" << endl;
  }
  cout << "Pilha vazia." << endl;
  return;
}
