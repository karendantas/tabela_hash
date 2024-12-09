#include <iostream>
#define TAM 21
using namespace std;


//lista
class Node{
   public:
     int data;
     Node* next;
     Node(int d):data(d){}
};

class LinkedList{
  public:
    Node* head;
    int tam;
};

void initializaLinkedList(LinkedList* l){
  l->head = NULL;
  l->tam = 0;
};

void insertLinkedList(LinkedList* list, int data){
    Node* newNode = new Node(data);

    newNode->next = list->head;
    list->head = newNode;
    list->tam++;

};

int searchLinkedList(LinkedList* list, int value){
  Node* temp = list->head;

  while(temp && temp->data != value ){
    temp = temp->next;
    if (temp) {
      return temp->data;
    }
  }
  return 0;

};

int printLinkedList(LinkedList* list){
  Node* temp = list->head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
};

void initialize_hash(LinkedList t[]){
  for (int i = 0; i < TAM; i++){
    initializaLinkedList(&t[i]);
  }
};

int func_hash(int value){
  return value % TAM;
};

void insert_hash(LinkedList t[], int value){
    int id = func_hash(value);
    insertLinkedList(&t[id], value);

};

int search_hash(LinkedList t[], int value){
  int id = func_hash(value);
  return searchLinkedList(&t[id], value);
};

void print_hash(LinkedList t[]){
  for ( int i = 0; i < TAM; i++){
    cout << i << "=";
    printLinkedList(&t[i]);
    cout << endl;
  }
};
int main() {
   //testando com uma tabela de 10 elementos
   //tamanho = 2 * 10 (primo mais prximo) = 21

   LinkedList tabela[TAM];
   initialize_hash(tabela);
   insert_hash(tabela, 11);
   insert_hash(tabela, 23);
   insert_hash(tabela, 34);
   insert_hash(tabela, 14);
   print_hash(tabela);

  return 0;
};