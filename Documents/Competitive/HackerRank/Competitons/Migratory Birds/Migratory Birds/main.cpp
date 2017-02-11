//
//  main.cpp
//  Migratory Birds
//
//  Created by soham harnale on 2/11/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int birds, temp;
    cin>>birds;
    int types[birds], array[5];
    for(int i=0; i<5;i++)
        array[i] = 0;
    for(int i=0; i<birds; i++) {
        cin>>types[i];
    }
    for(int j=0; j<birds; j++) {
        temp = types[j];
        array[temp-1] = array[temp-1] + 1;
    }
    int index, minv;
    index = minv = 1;
    for(int i=0; i<5; i++) {
        if(array[i]>minv && array[i] != 0) {
            minv = array[i];
            index = i;
        }
        else
            continue;
    }
    cout<<index+1;
    
}