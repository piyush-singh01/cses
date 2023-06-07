#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

typedef array<ll, 2> ar;
template<typename T>
using pqmin = priority_queue<T, vector<T>, greater<T>>;

int32_t main()
{
    int n,m,k;cin>>n>>m>>k;
    vector<vector<ar>> adj(n+1);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        ll w;cin>>w;
        adj[a].push_back({b,w});
    }

    vector<vector<ll>> dist(n+1);
    int src = 1;

    pqmin<ar> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        ar curr = pq.top();
        pq.pop();

        int fr = curr[1];
        ll dis = curr[0];

        // if already visited k times, continue.
        if((int)dist[fr].size() >= k) continue; 
        dist[fr].push_back(dis);

        for(ar child:adj[fr]) {
            int to = child[0];
            ll wt = child[1];
            pq.push({dis + wt, to});
        }
    }

    for(ll dis:dist[n]) {
        cout<<dis<<" ";
    }
}