//
//  main.cpp
//  Minimum Absolute Difference in an Array
//
//  Created by soham harnale on 2/10/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//






#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void closestMinPair(vector<int> &arr) {
    int min2;
    vector<int> diff(arr.size());
    sort(arr.begin(), arr.end());
    int min = INT_MAX;
    for(int i=1; i < arr.size(); i++) {
        diff[i] = arr[i]- arr[i-1];
        if(min > diff[i]) min = diff[i];
    }
    min2 = INT_MAX;
    for(int i=1; i < arr.size(); i++) {
        if(diff[i] == min) {
            
            if(abs(arr[i-1] - arr[i]) < min2) {
                min2 = abs(arr[i-1] - arr[i]);
            }
        }
            
    }
    cout<<min2;
}

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }
    closestMinPair(arr);
    return 0;
}
