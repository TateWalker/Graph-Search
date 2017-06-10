#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include "Edge.hpp"
using namespace std;

class Graph {
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    vector<list<Edge> > adj_list; // adjacency list
    Edge connection;  
    Graph(); // default constructor
    Graph(vector<list<Edge> > adjl); // constructor from adjl = adjacency list (optional)
    vector<list<Edge> > buildGraph(ifstream& in);  // build a graph from the adjacency list
    void displayGraph(vector<list<Edge> > adj);  // display the graph
    bool partitionable(vector<list<Edge> > adj); //check if graph is partitionable
	void bfs(vector<list<Edge> > adj, int source, int destination); //bfs
    
};

#endif /* Graph_hpp */
