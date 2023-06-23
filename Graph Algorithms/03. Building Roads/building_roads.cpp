#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj) {
    if(visited[node]) return;
    visited[node] = true;

    for(int child:adj[node]) {
        dfs(child, visited, adj);
    }
}
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n+1);
    int components = 0;
    vector<int> cities;
    for(int i = 1;i<=n;i++) {
        if(!visited[i]) {
            components++;
            cities.push_back(i);
            dfs(i, visited, adj);
        }
    }

    cout<<components - 1<<endl;
    for(int i = 1;i<(int)cities.size();i++) {
        cout<<cities[i-1]<<" "<<cities[i]<<"\n";
    }
}