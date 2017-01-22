//
//  main.cpp
//  Breadth First Traversal
//
//  Created by soham harnale on 1/23/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

/*  Here, A list is preferred over Vector and Queue containers. This is because we later implement functions such as "pop_front" which are not available in Vectors. We have also made use of an iterator, which cannot be used with a stack/queue. Hence, list is the preferred option.
*/

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int v) {
        this -> V = v;
        adj = new list<int> [v];
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void BFS(int s) {
        bool *visited = new bool[V];
        for(int i=0; i<V; i++) {
            visited[i] = false;
        }
        list<int> queue;
        list<int>::iterator it;
        visited[s] = true;
        queue.push_back(s);
        
        while(!queue.empty()) {
            s = queue.front();
            cout<<s<<" ";
            queue.pop_front();
            for(it = adj[s].begin(); it != adj[s].end(); it++) {
                if(!visited[*it]) {
                    queue.push_back(*it);
                    visited[*it] = true;
                }
            }
        }
        
    }
};

//Driver
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(3);
    return 0;
}








