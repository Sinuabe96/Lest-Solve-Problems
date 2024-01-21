#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node* prev;
};

struct LinkedList {
  private:
      Node* head;
      Node* tail;
  LinkedList(){
    head = nullptr;
    tail = nullptr;

  }
  void insertFront(int data){
    Node* newNode = Node();
    newNode->data = data;

    if(head == nullptr){
      head = newNode;
      tail = newNode;
    }
    else {
      head = newNode;
      tail = head->next;
    }
    
  }
};





int main(){






  return 0;
}