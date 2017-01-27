//
//  main.cpp
//  Kruskal's Algorithm
//
//  Created by soham harnale on 1/27/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Graph {
public:
    int V, E;
    vector<pair<int, int> > *adj;
    
    Graph(int v, int e) {
        this -> V= v;
        this -> E = e;
        adj = new vector<pair<int, int> >[V];
    }
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
    }
    
};

class Node {
public:
    int data;
    int rank;
    Node *parent;
};

class DisjointSet {
public:
    map <int, Node*> Map;
    
    void MakeSet(int data) {
        Node *node = new Node;
        node -> data = data;
        node -> parent = node;
        node -> rank =0;
        Map.insert(pair<int, Node*>(data, node));
    }
    
    void Union(int data1, int data2) {
        map <int, Node*> :: iterator it1, it2;
        it1 = Map.find(data1);
        Node *temp1 = it1 -> second;
        it2 = Map.find(data2);
        Node *temp2 = it2 -> second;
        
        
        Node *parent1 = findSet(temp1);
        Node *parent2 = findSet(temp2);
        
        if(parent1 -> rank >= parent2 ->rank) {
            if(parent1 -> rank == parent2 -> rank)
                parent1 -> rank = parent1 -> rank +1;
            else
                parent1 -> rank = parent1 -> rank;
            parent2 -> parent = parent1;
        }
        else
            parent1 -> parent = parent2;
    }
    
    int findSet(int data) {
        map <int, Node*> :: iterator it;
        it = Map.find(data);
        Node *temp = it -> second;
        return (findSet(temp)) -> data;
    }
    
    Node *findSet(Node *node) {
        Node *parent = node -> parent;
        if(parent == node)
            return parent;
        node -> parent = findSet(node -> parent);
        return node -> parent;
    }
};

int main() {
    DisjointSet ds;
    Graph G(4,4);
    //Initialising disjoint sets
    for(int i=0; i<4; i++) {
        ds.MakeSet(i);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    /*DisjointSet ds;
    ds.MakeSet(1);
    ds.MakeSet(2);
    ds.MakeSet(3);
    ds.MakeSet(4);
    ds.MakeSet(5);
    ds.MakeSet(6);
    ds.MakeSet(7);
    
    ds.Union(1, 2);
    ds.Union(2, 3);
    ds.Union(4, 5);
    ds.Union(6, 7);
    ds.Union(5, 6);
    ds.Union(3, 7);
    
    
    cout<<ds.findSet(1);
    cout<<ds.findSet(2);
    cout<<ds.findSet(3);
    cout<<ds.findSet(4);
    cout<<ds.findSet(5);
    cout<<ds.findSet(6);
    cout<<ds.findSet(7);
    */
    
    return 0;
    
}
