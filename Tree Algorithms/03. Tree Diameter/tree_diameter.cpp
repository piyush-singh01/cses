#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

void dfs(int node, int par, int d, vector<int> &depth, vector<vector<int>> &adj) {
    depth[node] = d;
    for(int child:adj[node]) {
        if(child == par) continue;
        dfs(child, node, d + 1, depth, adj);
    }
}
int32_t main()
{
    int n;cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 0;i<n-1;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> depth(n+1);
    dfs(1, -1, 0, depth, adj);
    int farthest_node = max_element(all(depth)) - depth.begin();

    fill(all(depth), 0);
    dfs(farthest_node, -1, 0, depth, adj);
    cout<<*max_element(all(depth));
}