#include <iostream>
#include <cmath>
#include "Node.hpp"

/*CITATION:

The base of this code was taken from my project 2 implementation of a linked list. I have modified it to fit the needs of this project.
*/

Node::Node(int point, double distance, double speed, double A)
{
    this->point = point;     // destination node
    this->distance = distance;
    this->speed = speed;
    this->A = A;
    next = nullptr;
    prev = nullptr;
}

Node::~Node(){
}

void Node::setNext(Node *next){
    this -> next = next;
}

Node *Node::getNext(){
    return next;
}

void Node::setPoint(int point){
    this->point = point;
}

int Node::getPoint(){
    return point;
}

void Node::setDistance(double distance){
    this->distance = distance;
}

double Node::getDistance(){
    return distance;
}

void Node::setSpeed(double speed){
    this->speed = speed;
}

double Node::getSpeed(){
    return speed;
}

void Node::setA(double A){
    this->A = A;
}

double Node::getA(){
    return A;
}

