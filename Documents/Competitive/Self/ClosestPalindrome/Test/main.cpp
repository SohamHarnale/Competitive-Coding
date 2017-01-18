//
//  main.cpp
//  Test
//
//  Created by soham harnale on 12/11/15.
//  Copyright © 2015 soham harnale. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{   int n[10], length, rounder, ans;
    int k=0, p=0, p2=0;                                                      //k = The original input of the user, p = palindrome
    cout<<"length of the number";
    cin>>length;
    for(int i = 0; i<length; i++)
    {
        cout<<"enter the"<<" "<<i+1<<" "<< "digit";
        cin>>n[i];
        k = 10 * k + n[i];
    }
    if(length%2==0)                                                         //Rounder is used to split number into two parts
        rounder = length/2;
    else
        rounder = length/2 + 1;
    
    
    for(int i = 0; i<rounder ; i++)                                         //Interchanging parts of the number to produce the palindrome
    {
        n[length-1-i] = n[i];
        
    }
    for(int i=0; i<length; i++)
    {
        p = 10 * p + n[i];
    }
    if(k<p && length%2==0)                                                  //following if() tree to up/down scale the palindrome based on if its
    {                                                                       //greater or lesser than the palindrome
        n[length/2]--;
        n[(length-1)/2+1]--;
    }
    else if(k<p && length%2!=0)
        n[(length-1)/2]--;
    else if(k>p && length%2==0)
    {
        n[(length-1)/2]++;
        n[(length-1)/2 + 1]++;
    }
    else
        n[(length-1)/2]++;
    
    for(int i = 0; i<length ; i++)                                          //Converting the modified array into new palindrome
    {
        p2 = 10 * p2 + n[i];
    }
    
    
    if( (k-p) > (k-p2) )
        ans = p2;
    else
        ans = p;
    
    cout<<"The closest Palindrome is "<<ans<<std::endl;
    
    
    
    
    
    return 0;
    
    
    
    
    
    
    
    
    
    
    
}

