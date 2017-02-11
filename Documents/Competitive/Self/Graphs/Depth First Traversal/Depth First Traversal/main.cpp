//
//  main.cpp
//  Depth First Traversal
//
//  Created by soham harnale on 1/23/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list <int> *adj;
public:
    Graph(int v) {
        this -> V = v;
        adj = new list<int>[v];
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void DFSutil(int s, bool visited[]) {
        visited[s] = true;
        cout<<s<<" ";
        list<int>::iterator it;
        for(it = adj[s].begin(); it != adj[s].end(); it++) {
            if(!visited[*it]) {
                DFSutil(*it, visited);
            }
        }
    }
    
    void DFS(int s) {
        bool *visited = new bool[V];
        for(int i=0; i<V;i++) {
            visited[i] = false;
        }
        DFSutil(s, visited);
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
    return 0;
    
}
