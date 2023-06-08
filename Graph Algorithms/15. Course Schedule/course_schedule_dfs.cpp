#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

// store all ordered independent chains in any order.
// store while tracing back
void dfs(int node, vector<int> &topo, vector<bool> &visited, vector<vector<int>> &adj) {
    if(visited[node]) return;
    visited[node] = true;

    for(int child:adj[node]) {
        dfs(child, topo, visited, adj);
    }
    topo.push_back(node);
}
int32_t main() {
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
    }
    
    /**/
    vector<bool> visited(n+1);
    vector<int> topo;
    for(int i = 1;i<=n;i++) {
        if(!visited[i]) {
            dfs(i, topo, visited, adj);
        }
    }
    reverse(topo.begin(), topo.end());
    /**/

    // check if impossible
    vector<int> idx(n+1);
    for(int i = 0;i<n;i++) {
        idx[topo[i]] = i;
    }

    for(int node = 1;node<=n;node++) {  //o(n+m)
        for(int child:adj[node]) {
            if(idx[child] <= idx[node]) {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i = 0;i<n;i++) {
        cout<<topo[i]<<" ";
    }

}