#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>

class Edge {
public:
    int start; //start vertex's label
    int end; //end vertex's label
    
    Edge();
    Edge(int start, int end);

};

#endif /* Edge_hpp */
