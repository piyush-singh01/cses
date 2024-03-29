#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

// In order of out time.
void dfs(int node, vector<int> &order, vector<bool> &visited, vector<vector<int>> &adj) {
    if(visited[node]) return;
    visited[node] = true;
    for(int child:adj[node]) {
        dfs(child, order, visited, adj);
    }
    order.push_back(node);
}

// Call on reverse graph, in reverse order of out time.
void _dfs(int node, int count, vector<int> &kingdom, vector<bool> &visited, vector<vector<int>> &rev) {
    if(visited[node]) return;
    visited[node] = true;

    kingdom[node] = count;
    for(int child:rev[node]) {
        _dfs(child, count, kingdom, visited, rev);
    }
}
int32_t main()
{
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> rev(n+1);
    for(int i = 1;i<=m;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<bool> visited(n+1);
    vector<int> order;

    for(int node = 1;node<=n;node++) {
        if(!visited[node]) {
            dfs(node, order, visited, adj);
        }
    }

    for(int node = 1;node<=n;node++) {
        visited[node] = false;
    }

    reverse(order.begin(), order.end());
    vector<int> kingdom(n+1);
    int count = 0;
    
    for(int node:order) {
        if(!visited[node]) {
            count++;
            _dfs(node, count, kingdom, visited, rev);
        }
    }
    cout<<count<<"\n";
    for(int node = 1;node<=n;node++) {
        cout<<kingdom[node]<<" ";
    }
}
