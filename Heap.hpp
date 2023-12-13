#ifndef HEAP_HPP
#define HEAP_HPP
#include "Heap_node.hpp"

class Heap
{
private:
    int size; // size of the heap
    Heap_node *heap; // the heap is an array of heap nodes
public:
    Heap(int capacity);
    ~Heap();

    void insert_heap(int start, int parent, double timere); // to insert a new node into the heap
    Heap_node* extract(); // to extract the node with the smallest distance
    void heapify(int index); // to heapify the heap
    int get_size(); // to get the size of the heap
    Heap_node* get_heap(); // to get the heap


};

#endif
