//
//  main.cpp
//  Pairs
//
//  Created by soham harnale on 2/16/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

//Using 2 pointer method

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, *array,count=0, diff=0;
    cin>>n>>k;
    array = new int[n];
    for(int i=0; i<n; i++) cin>>array[i];
    sort(array, array+n);
    int i=0; int j=1;
    while(j<n) {
        diff = array[j]-array[i];
        if(diff == k) {
            count++;
            i++;
        }
        else if(diff>k)
            i++;
        else if(diff<k)
            j++;
    }
    cout<<count;
    
}