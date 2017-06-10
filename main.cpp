#include <iostream>
#include <fstream>
#include <string>
#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    try{
        vector<list<Edge> > adjList(20);
        if (argc != 2) throw invalid_argument("Usage: ./main <file name>");
        ifstream in(argv[1]);
        if (!in) throw invalid_argument("Invalid file name or unable to open file.");
        Graph g;
        adjList = g.buildGraph(in);
        cout<<"Graph of "<<argv[1]<<": \n\n";
        g.displayGraph(adjList);
        if(g.partitionable(adjList) == true){ 
            cout<<"Graph of "<<argv[1]<<" is partitionable\n"<<endl;
            std::cout<<"What two cities do you wish to find the shortest path between (separated by spaces)? \n";
            int source;
            int destination;
            std::cin>>source>>destination;
            g.bfs(adjList,source,destination);
        }
        else cout<<"\nGraph of "<<argv[1]<<" is not partitionable\n"<<endl;
        return 0;
    }
    catch (exception& error){
        cerr << "Error: " << error.what() << endl;
    }
}

