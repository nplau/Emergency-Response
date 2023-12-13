#include <iostream>
#include <cmath>
#include "Heap.hpp"
#include "Heap_node.hpp"

/*CITATION:

For the heap functions, I learnt how to do it from Github copilot and Geeksforgeeks.org website on binary heaps and youtube*/

Heap::Heap(int capacity)
{
    size = 0;
    heap = new Heap_node[capacity];

    for (int i = 0; i < capacity; i++){
        heap[i] = Heap_node(0, 0, INFINITY);
    }
}

Heap::~Heap()
{
    delete [] heap;
}

// insert function as shown in class slides
void Heap::insert_heap(int start, int parent, double time){
    heap[size] = Heap_node(start, parent, time);
    size += 1;

    // place the new node in the correct position in the heap
    if (size > 0){
        int i = size;
        int parent = (i-1)/2;
        while (i > 0 && heap[i].get_time() < heap[parent].get_time()){
            Heap_node temp = heap[i];
            heap[i] = heap[parent];
            heap[parent] = temp;
            i = parent;
        }
    }
}

//extract and heapify functions as shown in class slides
Heap_node* Heap::extract(){

    Heap_node* min = new Heap_node(heap[0].get_vertex(), heap[0].get_parent(), heap[0].get_time());
    heap[0] = heap[size-1];
    size -= 1;
    int i = 0;

    heapify(i);
    return min;
}

void Heap::heapify(int i){
    int left = 2 * i +1;
    int right = 2 * i +2;
    int smallest = i;

    if (left < size && heap[left].get_time() < heap[smallest].get_time())
        smallest = left;

    if (right < size && heap[right].get_time() < heap[smallest].get_time())
        smallest = right;

    if (smallest != i) {

        // Swap heap[i] and heap[smallest]
        Heap_node temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        heapify(smallest);
    }
}

int Heap::get_size(){
    return size;
}

Heap_node* Heap::get_heap(){
    return heap;
}