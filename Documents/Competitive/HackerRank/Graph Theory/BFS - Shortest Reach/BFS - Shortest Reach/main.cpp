//
//  main.cpp
//  BFS - Shortest Reach
//
//  Created by soham harnale on 2/8/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
public:
    int V, E;
    list<int> *adj;
    
    Graph(int v, int e) {
        this -> V = v;
        this -> E = e;
        adj = new list<int> [v];
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void BFS(int s) {
        bool *visited = new bool[V];
        int temp = s;
        for(int i=0; i<V; i++) {
            visited[i] = false;
        }
        //vector <int> level(V, 0);
        int level[V];
        for(int l=0; l<V; l++)
            level[l] = 0;
        list <int> queue;
        list <int> ::iterator it;
        visited[s] = true;
        queue.push_back(s);
        while(!queue.empty()) {
            s = queue.front();
            //queue.pop_front();
            for(it = adj[s].begin(); it != adj[s].end(); it++) {
                if(!visited[*it]) {
                    level[*it] = level[s] + 1;
                    queue.push_back(*it);
                    visited[*it] = true;
                }
            }
            queue.pop_front();
        }
        
        for(int i=0; i<V; i++) {
            if(level[i]==0) {
                level[i] = -1;
                continue;
            }
            else
                level[i] = level[i] * 6;
        }
        
        
        for(int i=0; i<V; i++) {
            if(i==temp)
                continue;
            cout<<level[i]<<" ";
        }
        cout<<endl;
      
    }
};


int main() {
    int testcases, vertices, edges, u, v, s;
    cin>>testcases;
    for(int i=0; i<testcases; i++) {
        cin>>vertices>>edges;
        Graph g(vertices, edges);
        for(int j=0; j<edges; j++) {
            cin>>u>>v;
            g.addEdge(u-1, v-1);
        }
        cin>>s;
        g.BFS(s-1);
    }
    return 0;
}