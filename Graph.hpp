#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <fstream>

#include "List.hpp"
#include "Node.hpp"
#include "Heap.hpp"
#include "Heap_node.hpp"

class Graph
{
private:
    List *adj_head; // points to the head of the adjacency list/ the first linkedlist
    List *adj_tail; // points to the tail of the adjacency list/ the last linkedlist
    int num;
public:
    Graph();
    ~Graph();

    void load(std::fstream &fin);
    void insert(int a, int b, double d, double s);
    bool print(int a);
    bool delete_node(int a);
    bool dijkstra(int a, int b, bool type);
    bool traffic(int a, int b, double A);
    bool update(std::fstream &fin);

};

#endif