#include <iostream>
#include <fstream>
#include <cmath>
#include "Graph.hpp"
#include "List.hpp"
#include "Node.hpp"
#include "Heap.hpp"
#include "Heap_node.hpp"


Graph::Graph()
{
    adj_head = nullptr;
    adj_tail = nullptr;
    num = 0;
}

Graph::~Graph()
{
    List* temp = adj_head;
    while (temp != nullptr) {
        List* temp2 = (temp)->gettingNext();
        delete temp;
        temp = temp2;
    }
}

void Graph::load (std::fstream& fin){
    int a;
    int b;
    double d;
    double s;

    while (fin >> a >> b >> d >> s){ 
        insert(a, b, d, s);  // insert the vertices into the adjacency list
    }
}

void Graph::insert(int a, int b, double d, double s){
    bool foundA = false;
    bool foundB = false;

    // check if a or b exists
    List* temp = adj_head;
    List* tempA = nullptr;
    List* tempB = nullptr;
    while (temp != nullptr) {
        if (a == (temp)->get_index()) {
            foundA = true;
            tempA = temp;
        }
        if (b == (temp)->get_index()) {
            foundB = true;
            tempB = temp;
        }
        temp = ((temp)->gettingNext());
    }

    // insert the new vertices into the adjacency list 
    if (foundA){
        tempA->insertNode(b, d, s, 1);
    } else if (!foundA) { // if a does not exist
        List* new_A = new List(a);
        if (adj_head == nullptr) { // if the linked list is empty
            adj_head = new_A;
            adj_tail = new_A;
            temp = adj_head;
        }
        else { // add the new node to the end of the linked list
            (adj_tail)->settingNext(new_A);
            adj_tail = new_A;
            temp = adj_tail;
        }
        (temp)->insertNode(b, d, s, 1); // insert b into the linkedlist of a
    }

    if (foundB){
        tempB->insertNode(a, d, s, 1);
    } else if (!foundB) { // if b does not exist
        List* new_B = new List(b);
        if (adj_head == nullptr) { // if the linked list is empty
            this->adj_head = new_B;
            this->adj_tail = new_B;
            temp = adj_head;
        } else { // add the new node to the end of the linked list
            (adj_tail)->settingNext(new_B);
            adj_tail = new_B;
            temp = adj_tail;
        }
        (temp)->insertNode(a, d, s, 1); // insert a into the linkedlist of b
    }

    // if a and b exists, update the distance and speed for both linkedlists
    if (foundA && foundB){
        temp = adj_head;
        while (temp != nullptr){
            if (a == (temp)->get_index()){
                Node* temp2 = (temp)->getHead();
                while (temp2 != nullptr){
                    if (b == temp2->getPoint()){
                        temp2->setDistance(d);
                        temp2->setSpeed(s);
                    }
                    temp2 = temp2->getNext();
                }
            }
            if (b == (temp)->get_index()){
                Node* temp2 = (temp)->getHead();
                while (temp2 != nullptr){
                    if (a == temp2->getPoint()){
                        temp2->setDistance(d);
                        temp2->setSpeed(s);
                    }
                    temp2 = temp2->getNext();
                }
            }
            temp = ((temp)->gettingNext());
        }
    } 

    num += 1;
    return;
}

bool Graph::print(int a){
    bool valid = false;
      
    List* temp = adj_head;
    while (temp != nullptr) {
        if (a == (temp)->get_index()) {
            Node* temp2 = (temp)->getHead();
            while (temp2 != nullptr) {
                std::cout << temp2->getPoint() << " ";
                valid = true;
                temp2 = temp2->getNext();
            }
        }
        temp = ((temp)->gettingNext());
    }
    return valid;
}

bool Graph::delete_node(int a){
    bool deleted = false;
    List* temp = adj_head;
    List* prevTemp = nullptr;

    // iterate through the outer linked list
    while (temp != nullptr) { 
        if (a == temp->get_index()) {
            // reassigning prev and next pointers
            if (prevTemp != nullptr) {
                prevTemp->settingNext(temp->gettingNext());
            } else {
                adj_head = temp->gettingNext();
            }
            List* nextTemp = temp->gettingNext();
            delete temp;
            temp = nextTemp;
            deleted = true;
            num -= 1;
            // Skip the inner loop if the node is deleted in the outer loop
            continue;
        } else {
            // iterate through the inner linked list
            Node* temp2 = temp->getHead();
            Node* prevTemp2 = nullptr;
            while (temp2 != nullptr) {
                if (a == temp2->getPoint()) {
                    // reassigning prev and next pointers
                    if (prevTemp2 != nullptr) {
                        prevTemp2->setNext(temp2->getNext());
                    } else {
                        temp->setHead(temp2->getNext());
                    }
                    Node* nextTemp2 = temp2->getNext();
                    delete temp2;
                    temp2 = nextTemp2;
                    deleted = true;
                    num -= 1;
                    break;
                }
                prevTemp2 = temp2;
                temp2 = temp2->getNext();
            }
        } 
        prevTemp = temp;
        temp = temp->gettingNext();
    }   
    return deleted;
}

bool Graph::dijkstra(int a, int b, bool type){
    bool found = false;

    if (num == 0){
        return false;
    }
    bool visited[500001] ;
    double shortest[500001];
    int parents[500001];

    for (int i = 0; i < 500001; i++){
        shortest[i] = INFINITY;
        visited[i] = false;
        parents[i] = 0;
    }

    Heap* min_heap = new Heap(500000);

    // setting the source time to 0
    shortest[a] = 0;
    visited[a] = true;

    // min-heap priority queue
    int parent = a;

    // traverse through all adjacent vertices of a and insert it into the heap
    List* temp = adj_head;
    while (temp != nullptr){
        if (parent == (temp)->get_index()){
            Node* temp2 = (temp)->getHead();
            while (temp2 != nullptr){
                int source = temp2->getPoint();
                double A = temp2->getA();
                double d = temp2->getDistance();
                double s = temp2->getSpeed();
                double time = d / (s * A);
                min_heap->insert_heap(source, parent, time);
                temp2 = temp2->getNext();
            }
        }
        temp = ((temp)->gettingNext());
    }
    // while the heap is not empty
    // extract the minimum node from the heap
    // traverse through all adjacent vertices of the extracted node and insert it into the heap
    // if that vertex is already in the heap, update the distance if the new distance is smaller also update the parent 
    // update the shortest distance array for the extracted node if it is smaller than what is already in the array
    // repeat until the heap is empty

    while (min_heap->get_size() > 0){
    Heap_node* min = min_heap->extract();
    int source = min->get_vertex();
    int parent = min->get_parent();
    double time = min->get_time();

    // Only mark the node as visited and update the parent when it's extracted from the heap
    if (!visited[source]) {
        visited[source] = true;

        // update the shortest distance array for the extracted node
        if (time < shortest[source]){
            shortest[source] = time;
            parents[source] = parent;
        }

        delete min;
        temp = adj_head;
        // for the adjacent vertices of the extracted node
        while (temp != nullptr){
            if (source == (temp)->get_index()){
                Node* temp2 = (temp)->getHead();
                while (temp2 != nullptr){
                    int current = temp2->getPoint();
                    double A = temp2->getA();
                    double d = temp2->getDistance();
                    double s = temp2->getSpeed();
                    double new_time = time + d / (s * A);
                    if (!visited[current]){
                        bool inHeap = false;
                        for (int i = 0; i < min_heap->get_size(); i++){
                            if (current == min_heap->get_heap()[i].get_vertex()){
                                if (new_time < min_heap->get_heap()[i].get_time()){
                                    min_heap->get_heap()[i].set_time(new_time);
                                    min_heap->get_heap()[i].set_parent(source);
                                }
                                inHeap = true;
                            }
                        }
                        // if the vertex is not in the heap, insert it into the heap
                        if (!inHeap){
                            min_heap->insert_heap(current, source, new_time);
                        }
                    } 
                    temp2 = temp2->getNext();
                }
            }
            temp = ((temp)->gettingNext());
        }
    }
}

    int point = b;
    while (point != a){
        if (parents[point] == 0){
            return false;
        }
        point = parents[point];
    }

    found = true;

    if (type && found){
        // print the shortest path from a to b
        int point = b;
        while (point != a){
            std::cout << point << " ";
            point = parents[point];
        }
        std::cout << a << std::endl;
    } else if (!type && found){
        std::cout << "lowest is " << shortest[b] << std::endl;
    }

    delete min_heap;    
    return found;
}

bool Graph::traffic(int a, int b, double A){
    bool valid = false;
    bool foundA = false;
    bool foundB = false;

    // check if A is a valid value
    if (A < 0 || A > 1){
        return valid;
    }

    // check if a or b exists
    List* temp = adj_head;
    List* tempA = nullptr;
    List* tempB = nullptr;
    while (temp != nullptr) {
        if (a == (temp)->get_index()) {
            foundA = true;
            tempA = temp;
        }
        if (b == (temp)->get_index()) {
            foundB = true;
            tempB = temp;
        }
        temp = ((temp)->gettingNext());
    }

    if (foundA && foundB){
        temp = adj_head;
        while (temp != nullptr){
            if (a == (temp)->get_index()){
                Node* temp2 = (temp)->getHead();
                while (temp2 != nullptr){
                    if (b == temp2->getPoint()){
                        temp2->setA(A);
                        valid = true;
                    }
                    temp2 = temp2->getNext();
                }
            }
            if (b == (temp)->get_index()){
                Node* temp2 = (temp)->getHead();
                while (temp2 != nullptr){
                    if (a == temp2->getPoint()){
                        temp2->setA(A);
                        valid = true;
                    }
                    temp2 = temp2->getNext();
                }
            }
            temp = ((temp)->gettingNext());
        }
    }
    return valid;
}

bool Graph::update(std::fstream& fin){
    bool updated = false;
    int a;
    int b;
    double A;

    while (fin >> a >> b >> A){ 
        bool valid = traffic(a, b, A);  // insert the vertices into the adjacency list
        if (valid){
            updated = true;
        }
    }

    return updated;
}



