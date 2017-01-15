//
//  main.cpp
//  BinTreeBasics
//
//  Created by soham harnale on 1/7/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    node *right;
    node *left;
    int data;
};

node *root = NULL;

node* getNewNode(int data) {
    node *newnode = new node;
    newnode -> data = data;
    newnode -> left = newnode -> right = NULL;
    return newnode;
}

//Insert produces a Binary Search Tree
node* Insert(node* root, int data) {
    if(root == NULL) {
        root = getNewNode(data);
    }
    else if(data<=root -> data) {
        root -> left =  Insert(root -> left, data);
    }
    else {
        root -> right =  Insert(root -> right, data);
    }
    return root;
}


int GetCount(node *root) {
    int count = 1;
    if(root -> left != NULL)
        count += GetCount(root -> left);
    else if(root -> right != NULL)
        count += GetCount(root -> right);
    return count;
    
}

//SInsert produces a simple Binary Tree (Data inserted in simple levels)
node *LInsert(node *root, int data) {
    if(root == NULL) {
        root = getNewNode(data);
    }
    else if(root ->left != NULL) {
        root -> left = LInsert(root ->left, data);
    }
    else {
        root -> right = LInsert(root -> right, data);
    }
    return root;
}


void Preorder(node *root) {
    if(root == NULL) {
        return;
    }
    cout<<root -> data<< " ";
    Preorder(root -> left);
    Preorder(root -> right);
}



void LevelOrder(node *root) {
    if(root == NULL) {
        return;
    }
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()) {
        node *current = Q.front();
        cout<<current -> data<<" ";
        if(current -> left != NULL) {
            Q.push(current -> left);
        }
        if(current -> right != NULL) {
            Q.push(current -> right);
        }
        Q.pop();
    }
}





int main() {
    int count, pairs;
    root = LInsert(root, 20);
    root = LInsert(root, 15);
    root = LInsert(root, 30);
    root = LInsert(root, 10);
    root = LInsert(root, 60);
    root = LInsert(root, 5);
    root = LInsert(root, 2);
    LevelOrder(root);
    count = GetCount(root);
    cout<<"count is "<<count;
    pairs = Pairs(root);
    cout<<"Number of pairs "<<pairs;
    cout<<endl;
    
    return 0;
}