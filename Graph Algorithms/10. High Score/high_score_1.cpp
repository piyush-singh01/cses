#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const ll INF = 1e18;
typedef array<ll, 3> arr;
// if possible to reach final node after going through marked nodes
bool dfs(int node, vector<bool> &mark, vector<bool> &visited, vector<vector<int>> &adj) {
    if(mark[node]) return true;
    visited[node] = true;
    for(int child:adj[node]) {
        if(visited[child]) continue;
        if(dfs(child, mark, visited, adj) == true) {
            return true;
        } 
    }
    return false;
}
// bellman with marking abnormal edges
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<arr> edges;
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        ll w;cin>>w;
        edges.push_back({a,b,w});
    }

    vector<ll> dist(n+1, -INF);
    dist[1] = 0;
    for(int i = 0;i<n-1;i++) {
        for(int j = 0;j<m;j++) {
            int fr = edges[j][0];
            int to = edges[j][1];
            ll wt = edges[j][2];
            if(dist[fr] == -INF) continue;
            if(dist[to] < dist[fr] + wt) {
                dist[to] = dist[fr] + wt;
            }
        }
    }

    // mark those whose distance is changing in the n'th iteration
    vector<bool> mark(n+1, false);
    for(int j = 0;j<m;j++) {
        int fr = edges[j][0];
        int to = edges[j][1];
        ll wt = edges[j][2];
        if(dist[fr] == -INF) continue;
        if(dist[to] < dist[fr] + wt) {
            mark[to] = true;
            dist[to] = dist[fr] + wt;
        }
    }

    vector<bool> visited(n+1, false);
    vector<vector<int>> adj(n+1);
    for(int j = 0;j<m;j++) {
        int fr = edges[j][0];
        int to = edges[j][1];
        adj[to].push_back(fr);  //pushing edges in opposite to traverse from last node
    }

    if(dfs(n, mark, visited, adj)) {
        cout<<-1;
        return 0;
    }
    cout<<dist[n];
}