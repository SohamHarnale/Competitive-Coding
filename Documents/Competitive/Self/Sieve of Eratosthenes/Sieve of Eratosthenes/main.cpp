//
//  main.cpp
//  Sieve of Eratosthenes
//
//  Created by soham harnale on 12/14/15.
//  Copyright © 2015 Soham Harnale. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int testcases, n;
    void SieveOfEratosthenes(int);
    cin>>testcases;
    for(int i=0; i<testcases; i++)
    {
        cin>>n;
        SieveOfEratosthenes(n);
        
    }
    return 0;
}

void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    int p;
    memset(prime, true, sizeof(prime));
    for(p=2; p*p<=n; p++)
    {
        if(prime[p]==true)
        {
            for(int i=p*2; i<=n; i=i+p)
                prime[i]=false;
        }
    }
    for(int p=2; p<=n; p++)
    {
        if(prime[p])
            cout<<p<<" ";
    }
    
}
