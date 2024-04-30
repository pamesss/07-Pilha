#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
  int valor;
  NO* prox;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
//--------------------------


int main()
{
  menu();
}

void menu()
{
  int op = 0;
  while (op != 4) {
    cout << "Menu Pilha";
    cout << endl << endl;
    cout << "1 - Inicializar Pilha \n";
    cout << "2 - Inserir elemento (Push) \n";
    cout << "3 - Remover elementos (Pop) \n";
    cout << "4 - Sair \n";


    cout << "Opcao: ";
    cin >> op;

    switch (op)
    {
    case 1: inicializar();
      break;
    case 2:push();
      break;
    case 3: pop();
      break;
    case 4:
      return;
    default:
      break;
    }
  }
}

void inicializar()
{

  // se a lista já possuir elementos
  // libera a memoria ocupada
  NO* aux = topo;
  while (aux != NULL) {
    NO* paraExcluir = aux;
    aux = aux->prox;
    free(paraExcluir);
  }

  topo = NULL;
  cout << "Pilha inicializada \n";

}


void push()
{
  // aloca memoria dinamicamente para o novo elemento
  NO* novo = (NO*)malloc(sizeof(NO));
  if (novo == NULL)
  {
    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;
    return;
  }
  else {
    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = topo; 
    topo = novo; 

    return;
  } 
}



void pop()
{
  {
  if (topo != NULL) {
    NO* paraExcluir = topo;
    topo = topo->prox;
    cout << "Elemento removido: " << paraExcluir->valor << endl;
    free(paraExcluir);
  }
  else {
    cout << "Pilha Vazia" << endl;
  }
}
}
