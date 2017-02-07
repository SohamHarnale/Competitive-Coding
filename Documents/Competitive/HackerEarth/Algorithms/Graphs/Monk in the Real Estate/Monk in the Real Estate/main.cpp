//
//  main.cpp
//  Monk in the Real Estate
//
//  Created by soham harnale on 2/7/17.
//  Copyright © 2017 Soham Harnale. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool *vis;

int main() {
    int testcases, edges, u, v, count;
    cin>>testcases;
    for(int i=0; i<testcases; i++) {
        cin>>edges;
        count = 0;
        vis = new bool[100000];
        for(int s=0; s<edges; s++) {
            vis[edges] = false;
        }
        for(int j=0; j<edges; j++) {
            
            cin>>u>>v;
            if(vis[u] == false && vis[v] == false) {
                if(u == v)
                    count += 1;
                else
                count = count + 2;
                vis[u] = vis[v] = true;
                continue;
            }
            else if(vis[u] == true && vis[v] == true)
                continue;
            else {
                count += 1;
                vis[u] = true;
                vis[v] = true;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}


/*int main() {
    int testcases, edges, u, v;
    cin>>testcases;
    set <int> s;
    vector <int> v1;
    for(int i=0; i<testcases; i++) {
        cin>>edges;
        v1.clear(); s.clear();
        set <int> ::iterator it;
        for(int j=0; j<edges; j++) {
            cin>>u>>v;
            s.insert(u);
            s.insert(v);
            for(it = s.begin(); it != s.end(); it++) {
                v1.push_back(*it);
            }
        }
        cout<<v1.size();
        
    }
    return 0;
}
 */








