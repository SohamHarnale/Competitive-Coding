//
//  main.cpp
//  Game of Two Stacks
//
//  Created by soham harnale on 2/18/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long int INF = 0x3f3f3f3f;

int main() {
    long int testcases, sizeA, sizeB, x, temp, count,sum, backA, backB;
    vector <long int> A; vector <long int> B;
    cin>>testcases;
    for(int i=0; i<testcases; i++) {
        count=0; sum=0;
        A.clear(); B.clear();
        cin>>sizeA>>sizeB>>x;
        for(int j=0; j<sizeA; j++) cin>>temp, A.push_back(temp);
        for(int j=0; j<sizeB; j++) cin>>temp, B.push_back(temp);
        reverse(A.begin(), A.end()); reverse(B.begin(), B.end());
        //cout<<A.back()<<" "<<B.back();
        while(sum<=x) {
            if(!A.empty()) backA = A.back();
            else backA = INF;
            if(!B.empty()) backB = B.back();
            else backB = INF;
            if(A.empty() && B.empty()) {
                break;
            }
            else if(backA < backB) {
                sum += A.back();
                A.pop_back();
                if(sum>x) break;
                count++;
                continue;
            }
            else if(backA > backB) {
                sum += B.back();
                B.pop_back();
                if(sum>x) break;
                count++;
                continue;
            }
            else if(backA == backB){
                sum += A.back();
                A.pop_back();
                if(sum>x) break;
                count++;
                continue;
            }
            
        }
        cout<<count<<endl;
        
    }
}
