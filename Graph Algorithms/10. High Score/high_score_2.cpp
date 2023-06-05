#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef array<ll, 3> arr;
const ll INF = 1e18;
const ll NINF = -INF;
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<arr> edges;
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        ll w;cin>>w;
        edges.push_back({a,b,w});
    }

    vector<ll> dist(n+1, NINF);
    dist[1] = 0;
    //relax in n-1 iterations
    for(int i = 0;i<n-1;i++) {
        for(int j = 0;j<m;j++) {
            int fr = edges[j][0];
            int to = edges[j][1];
            ll wt = edges[j][2];
            if(dist[fr] == NINF) continue;
            if(dist[to] < dist[fr] + wt) {
                dist[to] = dist[fr] + wt;
            }
        }
    }

    // in other n-1 iterations, all edges can be resolved
    for(int i = 0;i<n-1;i++) {
        for(int j = 0;j<m;j++) {
            int fr = edges[j][0];
            int to = edges[j][1];
            ll wt = edges[j][2];
            if(dist[fr] == NINF) continue;
            if(dist[to] < dist[fr] + wt) {
                dist[to] = INF;
            }
        }
    }

    if(dist[n] == INF) {
        cout<<-1;
        return 0;
    }
    cout<<dist[n];
}