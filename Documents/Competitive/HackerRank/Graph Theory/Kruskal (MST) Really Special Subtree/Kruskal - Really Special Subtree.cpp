//
//  main.cpp
//  Kruskal's Algorithm
//
//  Created by soham harnale on 1/27/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
///Users/Soham/Documents/Competitive/Self/Graphs/Kruskal's Algorithm/Kruskal's Algorithm/main.cpp

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
public:
    int V, E;
    vector<pair<int, pair<int, int> > > edges;

    Graph(int v, int e) {
        this -> V= v;
        this -> E = e;
        //edges = new vector<pair<int, pair<int, int> > > [v];
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();
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

int Graph :: kruskalMST() {
    int FinalW = 0;
    sort(edges.begin(), edges.end());
    DisjointSet ds;
    for(int i=0; i<V; i++) {
        ds.MakeSet(i);
    }
    vector<pair<int, pair<int, int> > > :: iterator it;
    for(it = edges.begin(); it != edges.end(); it++) {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.findSet(u);
        int set_v = ds.findSet(v);

        if(set_u != set_v) {
            //cout<<u<<" - "<<v<<endl;
            FinalW += it ->first;
            ds.Union(u, v);
        }

    }
    return FinalW;

}

int main() {
    int vertices, edges, u, v, w;
    cin>>vertices>>edges;
    Graph g(vertices, edges);
    for(int i=0; i<edges; i++) {
        cin>>u>>v>>w;
        g.addEdge(u-1, v-1, w);
    }
    int wt = g.kruskalMST();
    cout<<wt;
    return 0;
    /*int V = 4, E = 6;
    Graph g(V, E);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(3, 0, 6);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 5);

    cout << "Edges of MST are \n";
    int mst_wt = g.kruskalMST();

    cout << "\nWeight of MST is " << mst_wt;

    return 0;
     */

}


