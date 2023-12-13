#ifndef NODE_HPP
#define NODE_HPP

/*CITATION:

The base of this code was taken from my project 2 implementation of a linked list. I have modified it to fit the needs of this project.
*/

class Node
{
private:
    int point;
    double distance;
    double speed;
    double A;

    // for the linked list
    Node *next;
    Node *prev;
public:
    Node(int point, double distance, double speed, double A);
    ~Node();

    void setNext(Node *next);
    Node *getNext();
    void setPoint(int point);
    int getPoint();
    void setDistance(double distance);
    double getDistance();
    void setSpeed(double speed);
    double getSpeed();
    void setA(double A);
    double getA();
};

#endif