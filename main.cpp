#include <iostream>
#include <fstream>
#include "illegal_exception.hpp"
#include "Graph.hpp"
#include "List.hpp"
#include "Node.hpp"
#include "Heap.hpp"
#include "Heap_node.hpp"

/*CITATION: 

debugged with help from chatGPT and copilot*/
Graph *graph = new Graph();
std::string input;
std::string filename;
int a;
int b;
double s;
double d;
double A;

int main()
{
    while (std::cin >> input){

        if (input == "LOAD"){
            std::cin >> filename;
            std::fstream fin(filename.c_str());
            graph -> load (fin);
            std::cout << "success" << std::endl;

        } else if (input == "INSERT"){
            std::cin >> a >> b >> d >> s;

            try {
                if (a <= 0 || a > 500000 || b <= 0 || b > 500000 || d <= 0 || s <= 0 ){
                    throw illegal_exception();
                } else {
                    graph -> insert(a, b, d, s);
                    std::cout << "success" << std::endl;
                }

            } catch (illegal_exception& e){
                std::cout << e.what() << std::endl;
            }

        } else if (input == "PRINT"){
            std::cin >> a;

            try {
                if (a <= 0 || a > 500000){
                    throw illegal_exception();
                } else if (graph -> print(a)){
                    std::cout << std::endl;
                } else {
                    std::cout << "failure" << std::endl;
                }

            } catch (illegal_exception& e){
                std::cout << e.what() << std::endl;
            }

        } else if (input == "DELETE"){
            std::cin >> a;

            try {
                if (a <= 0 || a > 500000){
                    throw illegal_exception();
                } else if (graph -> delete_node(a)){
                    std::cout << "success" << std::endl;
                } else {
                    std::cout << "failure" << std::endl;
                }

            } catch (illegal_exception& e){
                std::cout << e.what() << std::endl;
            }

        } else if (input == "PATH"){
            std::cin >> a >> b;

            try {
                if (a <= 0 || a > 500000 || b <= 0 || b > 500000 ){
                    throw illegal_exception();
                } else {
                    if (!graph -> dijkstra(a, b, true)){
                        std::cout << "failure" << std::endl;
                    }
                }

            } catch (illegal_exception& e){
                std::cout << e.what() << std::endl;
            }

        } else if (input == "TRAFFIC"){
            std::cin >> a >> b >> A;

            try {
                if (a <= 0 || a > 500000 || b <= 0 || b > 500000 ){
                    throw illegal_exception();
                } else {
                    if (graph -> traffic(a, b, A)){
                        std::cout << "success" << std::endl;
                    } else {
                        std::cout << "failure" << std::endl;
                    }
                }

            } catch (illegal_exception& e){
                std::cout << e.what() << std::endl;
            }

        } else if (input == "UPDATE"){
            std::cin >> filename;
            std::fstream fin(filename.c_str());
            if (graph -> update(fin)){
                std::cout << "success" << std::endl;
            } else {
                std::cout << "failure" << std::endl;
            }

        } else if (input == "LOWEST"){
            std::cin >> a >> b;

            try {
                if (a <= 0 || a > 500000){
                    throw illegal_exception();
                } else {
                    if (!graph -> dijkstra(a, b, false)){
                        std::cout << "failure" << std::endl;
                    } 
                }

            } catch (illegal_exception& e){
                std::cout << e.what() << std::endl;
            }

        } else if (input == "END"){
            delete graph;
            return 0;
        } 
    }
}