//
//  main.cpp
//  Union Find Algorithm - Cycle Detection
//
//  Created by soham harnale on 1/24/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
using namespace std;

class Edge {
public:
    int src, des, weight;
};

//Here, structure is used instead of class
class Graph {
    int V, E;
public:
    Edge *edge;
    
    Graph* createGraph(int v, int e) {
        Graph *graph = new Graph;
        graph -> V =v;
        graph -> E = E;
        graph -> edge = new Edge[e];
        return graph;
    }
    
    int Find(int parent[], int i) {
        if(parent[i] == -1)
            return i;
        return Find(parent, parent[i]);
    }
    
    void Union(int parent[], int x, int y) {
        int xtemp = Find(parent, x);
        int ytemp = Find(parent, y);
        parent[xtemp] = ytemp;
    }
    
    int isCycle(Graph *graph) {
        int *parent = new int[graph ->E];
        for(int i=0; i<graph ->E; i++) {
            parent[i] = -1;
        }
        for(int i=0; i<graph ->E; i++) {
            int x = Find(parent, graph ->edge[i].src);
            int y = Find(parent, graph ->edge[i].des);
            if(x==y)
                return 1;
            Union(parent,x,y);
        }
        return 0;
    }
    
};

int main() {
    
}