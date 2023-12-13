#include <iostream>
#include <cmath>
#include "List.hpp"
#include "Node.hpp"

/*CITATION:

The base of this code was taken from my project 2 implementation of a linked list. I have modified it to fit the needs of this project.
*/

List::List(int index){

    this -> index = index; // index of the node
    head = nullptr;
    tail = nullptr;
    adj_next = nullptr;
    adj_prev = nullptr;

}

List::~List(){
    Node* temp = head;
    while(temp != nullptr){
        Node *temp2 = temp->getNext();
        delete temp;
        temp = temp2;
    }
}

void List::insertNode (int point, double distance, double speed, double A){
    Node *new_node = new Node(point, distance, speed, A);
        if (head == nullptr){                // if the linked list is empty
            this->head = new_node;
            this->tail = new_node;
        } else{                               // add the new node to the end of the linked list
            tail->setNext(new_node);
            tail = new_node;
        }
}

void List::settingNext(List *adj_next){
    this->adj_next = adj_next;
}

List *List::gettingNext(){
    return adj_next;
}
int List::get_index(){
    return index;
}

void List::setHead(Node *head){
    this->head = head;
}

Node *List::getHead(){
    return this->head;
}