#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

class LinkedList {
  private: Node* head;
  public:
  LinkedList(): head(nullptr){}


  void insertAtEnd(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if(head ==  nullptr){
      head = newNode;
      cout << "Node added Successfully" << endl;
      return;
    }

    Node* current = head;
    while(current->next != nullptr){
      current = current->next;
    }
    current->next = newNode;
    cout << value <<  " Node added Successfully" << endl;
  }
  void insertAtPosition(int value, int position){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    Node* current = head;
    Node* prev = nullptr;

    for(int i = 0; i < position && current != nullptr; i++){
        prev = current;
        current = current->next;
    }       

    if(current == nullptr){
      prev->next = newNode;
    }

    prev->next = newNode;
    newNode->next = current;

    cout << "Element Inserted Successfully" << endl;
  }
  void display(){
    Node* current = head;

    while( current != nullptr){
      cout << current->data << endl;
      current = current->next;
    }
  }
  void removeAtEnd(){
    if(head == nullptr){
      cout << "List is empty" << endl;
      return;
    }
    Node* current = head;
    while(current->next!= nullptr){
      current = current->next;
    }
    delete current;
    
  }
  void reverseList(){
  Node* prev = nullptr;
  Node* current = head;
  Node* next = nullptr;

  while( current != nullptr){
      next = current->next;
      current->next = prev;


      prev = current;
      current = next;
  }
  head = prev;
 }
  int  searchNode(int value){
    if(head ==  NULL){
      
      return -1;
    }
    Node* current = head;
    int i = 1;
    while(current != NULL){
      if(current->data == value){
       return i;
       break;
      }
      current = current->next;
      i++;
    }
    return -1;
  }
int countNodes() {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

  void sortingNode(){
    Node* current = head;
    Node* rot = nullptr;
    int count = countNodes();

    while( current != nullptr){
        rot = current->next;
        while(rot != nullptr){
          if(current->data > rot->data){
            int temp = current->data;
            current->data = rot->data;
            rot->data = temp;
          }
          rot = rot->next;
        }
        current = current->next;
    }
  }


};

struct DoubleNode {
  int data;
  Node* prev;
  Node* next;
};






int main(){

  LinkedList list;
  list.insertAtEnd(0);
  list.insertAtEnd(1);
  list.insertAtEnd(2);
  list.insertAtEnd(3);
  list.insertAtEnd(4);
  list.insertAtEnd(5);
  cout << endl;

  list.display();

  list.reverseList();
  cout << endl;
  list.display();

  int index = list.searchNode(5);

  if(index == -1){
    cout << "No value is found in the list " ;
  }
  else {
  cout << "The value is found at index " <<  index;
  }

  list.sortingNode();
  cout << endl;
  list.display();






  return 0;
}