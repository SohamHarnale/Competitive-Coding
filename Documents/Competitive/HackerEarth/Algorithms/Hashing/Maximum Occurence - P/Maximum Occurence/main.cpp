//
//  main.cpp
//  Maximum Occurence
//
//  Created by soham harnale on 1/18/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//char str[100] = "0123456789!\"#$%&'()*+,-./ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int Hash(char *c) {
    char letter  = *c;
    int h = int(letter);
    if(h >= 32 && h<=47)
        return h-32;
    else if(h>=48 && h<=57)
        return h-32;
    else if(h>=65 && h<=90)
        return h-39;
    else
        return h-45;
}


int Store(char *p, int count[1000], int maxC) {
    int index, ansindex;
    for(char *i = p; *i; i++) {
        index = Hash(i);
        //cout<<index<<endl;
        count[index]++;
        if(count[index]>maxC) {
            maxC = count[index];
            
        }
    }
    return maxC;
}

int findCounts(int count[1000], int max) {
    int found;
    for(int i=0; i<1000; i++) {
        if(count[i] == max) {
            found = i;
            break;
        }
    }
    return found;
    
}



int main() {
    string str = " !\"#$%&'()*+,-./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char input[1000], *p;
    int count[1000], max, final;
    memset(count, 0, 1000);
    cin.getline(input, sizeof(input));
    p = strtok(input, " ");
    while(p != NULL) {
        max = Store(p, count, max);
        p = strtok(NULL, " ");
    }
    final = findCounts(count, max);
    //cout<<max<<endl;
    //cout<<final<<endl;
    cout<<str[final]<<" "<<max;
    return 0;
}