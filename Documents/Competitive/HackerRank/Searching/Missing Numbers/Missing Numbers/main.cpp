//
//  main.cpp
//  Missing Numbers
//
//  Created by soham harnale on 2/15/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> finalE;

void Hash(int *b, int *hashT, int blen, int minV) {
    int index=0;
    for(int i=0; i<blen; i++) {
        index = b[i] - minV;
        hashT[index]++;
    }
}

int main() {
    int *a, *b, *hashTb, *hashTa;
    int alen, blen, minS, minV, element;
    cin>>alen;
    a = new int[alen];
    for(int i=0; i<alen; i++) cin>>a[i];
    //cout<<a[alen-1];
    sort(a, a+alen);
    cin>>blen;
    b = new int[blen];
    for(int i=0; i<blen; i++) cin>>b[i];
    sort(b, b + blen);
    
    //Finding min value for hashT
    minS = b[blen-1] - b[0];
    minV = b[0];
    
    //cout<<minS<<" "<<minV;
    
    
    hashTb = new int[minS]; hashTa = new int[minS];
    for(int i=0; i<minS; i++) hashTb[i] = 0;
    for(int i=0; i<minS; i++) hashTa[i] = 0;
    //Count of each element stored in HashT
    Hash(b, hashTb, blen, minV);
    Hash(a, hashTa, alen, minV);
    
    //Traversing b and finding elements with count>1 and comparing with counts in a
    for(int i=0; i<minS; i++) {
        if(hashTb[i] > 1) {
            if(hashTa[i] == hashTb[i]) {
                continue;
            }
            else {
                element = i + minV;
                finalE.push_back(element);
                continue;
            }
        }
        else
            continue;
    }
    vector<int>::iterator it;
    sort(finalE.begin(), finalE.end());
    for(it = finalE.begin(); it != finalE.end(); it++)
        cout<<*it<<" ";
    
    
    
    return 0;
    
}