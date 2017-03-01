// C++ program to print print all primes smaller than
// n using segmented sieve
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

vector<int> final;
vector<int> prime;

// This functions finds all primes smaller than 'limit'
// using simple sieve of eratosthenes. It also stores
// found primes in vector prime[]
void simpleSieve(int limit, vector<int> &prime)
{
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    
    //bool mark[limit+1];
    //memset(mark, true, sizeof(mark));
    
    bool *mark = new bool[limit+1];
    for(int i=0; i<limit+1; i++) mark[i] = true;
    
    for (int p=2; p*p<limit; p++)
    {
        // If p is not changed, then it is a prime
        if (mark[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }
    
    // Print all prime numbers and store them in prime
    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            //cout << p << "  ";
        }
    }
}

// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n, int n1)
{
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    //vector<int> prime;
    simpleSieve(limit, prime);
    
    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low  = limit;
    int high = 2*limit;
    
    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        
        //bool mark[limit+1];
        //memset(mark, true, sizeof(mark));
        
        bool *mark = new bool[limit+1];
        for(int i=0; i<limit+1; i++) mark[i] = true;
        
        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < prime.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            
            /*  Mark multiples of prime[i] in [low..high]:
             We are marking j - low for j, i.e. each number
             in range [low, high] is mapped to [0, high-low]
             so if range is [50, 100]  marking 50 corresponds
             to marking 0, marking 51 corresponds to 1 and
             so on. In this way we need to allocate space only
             for range  */
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
        
        // Numbers which are not marked as false are prime
        for (int i = low; i<high; i++) {
            bool flag = false;
            int split =1; int temp=0;
            if (mark[i - low] == true) {
                //final.push_back(i);
                //cout<<i<<" ";
                while(i/split !=0) {
                    temp = i/split % 10;
                    flag = false;
                    
                    if(temp == 2|| temp == 3|| temp == 5|| temp == 7) {
                        flag = false;
                        split *= 10;
                        continue;
                    }
                    else {
                        flag = true;
                        break;
                    }
                    
                }
                if(flag == false && i>=n1 && i<=n) final.push_back(i);
                //else final.push_back(i);
            }
            
        }
        // Update low and high for next segment
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
}

// Driver program to test above function
int main()
{
    int n, n1, count=0;
    //int n = 100;
    //cout << "Primes smaller than " << n << ":\n";
    cin>>n1>>n;
    segmentedSieve(n, n1);
    //for(auto it= prime.begin(); it != prime.end(); it++) cout<<*it<<endl;
    //for(auto it= final.begin(); it != final.end(); it++) cout<<*it<<" ";
    /*for(auto it = prime.begin(); it != prime.end(); it++) {
        if(*it > n1) count++;
    }
    for(auto it = final.begin(); it != final.end(); it++) {
        
        if(*it >= n1 && *it <= n) count++;
        if(*it > n) break;
    }
    cout<<count;*/
    if(n1<10)
        cout<<final.size()+4;
    else
        cout<<final.size();
    return 0;
}