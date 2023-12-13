#ifndef HEAP_NODE_HPP
#define HEAP_NODE_HPP

class Heap_node
{
private:
    int vertex;
    int parent;
    double time;
public:
    Heap_node(int vertex, int parent, double time);
    Heap_node();
    ~Heap_node();
    int get_vertex();
    int get_parent();
    void set_parent(int parent);
    double get_time();
    void set_time(double time);
};

#endif
