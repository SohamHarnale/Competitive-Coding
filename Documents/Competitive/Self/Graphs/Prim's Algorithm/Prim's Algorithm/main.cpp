//
//  main.cpp
//  Prim's Algorithm
//
//  Created by soham harnale on 2/6/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V, E;
    vector<int, pair<int , int>> edges;
    
    Graph(int v, int e) {
        this -> V = v;
        this -> E = e;
    }
    
    void addEdge(int u, int v, int w) {
        edges.push_back({u, {v, w}});
    }
};

int main() {
    
}