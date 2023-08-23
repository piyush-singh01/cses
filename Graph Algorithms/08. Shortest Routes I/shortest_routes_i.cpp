#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const ll INF = 1e18;
typedef array<ll, 2> ar;

template<class T>
using pqmin = priority_queue<T, vector<T>, greater<T>>;
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<vector<ar>> adj(n+1);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        ll w;cin>>w;
        adj[a].push_back({b, w});
    }

    const int S = 1;
    pqmin<ar> pq;
    vector<ll> dist(n + 1, -1);

    pq.push({0, S});
    while(!pq.empty()) {
        ar curr = pq.top();
        pq.pop();

        int fr = curr[1];
        ll dis = curr[0];

        if(dist[fr] != -1) continue;
        dist[fr] = dis;
        
        for(ar child:adj[fr]) {
            int to = child[0];
            ll wt = child[1];
            pq.push({dis + wt, to});
        }
    }
    
    for(int i = 1;i<=n;i++) {
        cout<<dist[i]<<" ";
    }
}