//
//  main.cpp
//  Ice Cream Parlor
//
//  Created by soham harnale on 2/16/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int testcases, m=0, n=0, u, v, add, count=0;
    int finalu=0, finalv=0;
    int *var, *sortedvar;
    vector <int> in;
    cin>>testcases;
    for(int i=0; i<testcases; i++) {
        cin>>m>>n;
        var = new int[n]; sortedvar = new int[n];
        for(int j=0; j<n;j++) cin>>var[j], sortedvar[j] = var[j];
        sort(sortedvar, sortedvar+n);
        //u = 0; v=1; <- These parameters can be used if we had to find a specific difference
        u=0; v= n-1;
        //Using 2 pointer
        while(u<n) {
            
            
                while(sortedvar[u] + sortedvar[v] > m && v > 0) v--;
                if (sortedvar[u] + sortedvar[v] == m) {
                    finalu = sortedvar[u];
                    finalv = sortedvar[v];
                    break;
                }
                u++;
            }

        
            //Inefficient
        
            /*add = sortedvar[u] + sortedvar[v];
            if(v==n-1) {
                u++; v= u+1;
            }
            if(add == m) {
                finalu = sortedvar[u]; finalv = sortedvar[v];
                cout<<u+1<<" "<<v+1<<endl;
                break;
            }
            else if(add>m)
                u++;
            else if(add < m)
                v++;*/
        
        for(int j=0; j<n; j++) {
            if(var[j]==finalu||var[j]==finalv) {
                in.push_back(j+1);
                count++;
                if(count==2)
                    break;
            }
            sort(in.begin(), in.end());
        }
        for(auto it=in.begin(); it != in.end(); it++) cout<<*it<<" ";
        cout<<endl;
        in.clear();
    }
    return 0;
}