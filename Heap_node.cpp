#include <iostream>
#include "Heap_node.hpp"

Heap_node::Heap_node(int vertex, int parent, double time)
{
    this->vertex = vertex;
    this->parent = parent;
    this->time = time;  // this is the key
}

Heap_node::Heap_node()
{
}

Heap_node::~Heap_node()
{
}

int Heap_node::get_vertex(){
    return vertex;
}

int Heap_node::get_parent(){
    return parent;
}

void Heap_node::set_parent(int parent){
    this->parent = parent;
}

double Heap_node::get_time(){
    return time;
}

void Heap_node::set_time(double time){
    this->time = time;
}
