//
//  main.cpp
//  Comrades II
//
//  Created by soham harnale on 1/8/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>

using namespace std;


struct node {
    int data;
    int color;
    node *left;
    node *right;
};

node *root = NULL;

void Create(node *root, int v, int c) {
    int vertices[v-1];
    root -> data = 1;
    root -> left = root -> right = NULL;
    for(int i = 2; i<=v; i++) {
        cin>>vertices[i];
    }
    for(int i=2; i<=v; i++) {
        cout<<vertices[i]<<"-> "<<i<<endl;
    }
}

int main() {
    Create(root, 5, 4);
    return 0;
}