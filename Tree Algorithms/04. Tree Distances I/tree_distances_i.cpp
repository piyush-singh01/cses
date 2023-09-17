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

    vector<int> f(n+1);
    dfs(1, -1, 0, f, adj);
    int one_end = max_element(all(f)) - f.begin();

    fill(all(f), 0);
    dfs(one_end, -1, 0, f, adj);
    int other_end = max_element(all(f)) - f.begin();
    
    vector<int> g(n+1);
    dfs(other_end, -1, 0, g, adj);

    for(int node = 1;node<=n;node++) {
        cout<<max(f[node], g[node])<<" ";
    }
}