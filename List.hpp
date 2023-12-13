#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"

/*CITATION:

The base of this code was taken from my project 2 implementation of a linked list. I have modified it to fit the needs of this project.
*/

class List{
private:
    int index;
    Node *head;
    Node *tail;
    List *adj_next;
    List *adj_prev;

public:
    List(int index);
    ~List();
    void insertNode (int point, double distance, double speed, double A);
    void settingNext(List *adj_next);
    List *gettingNext();
    int get_index();
    void setHead(Node *head);
    Node *getHead();
};


#endif