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
        int a,b,w;cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }

    vector<ll> dist(n+1, INF);
    vector<bool> visited(n+1, false);
    pqmin<ar> pq;

    int src = 1;
    dist[src] = 0;
    pq.push({dist[src], src});
    while(!pq.empty()) {
        ar curr = pq.top();
        pq.pop();

        ll dis = curr[0];
        int fr = curr[1];
        if(visited[fr]) continue;
        visited[fr] = true;
        for(ar child:adj[fr]) {
            int to = child[0];
            ll wt = child[1];
            if(dist[to] > dis + wt) {
                dist[to] = dist[fr] + wt;
                pq.push({dist[to], to});
            }
        }
    }

    for(int i = 1;i<=n;i++) {
        cout<<dist[i]<<" ";
    }
}