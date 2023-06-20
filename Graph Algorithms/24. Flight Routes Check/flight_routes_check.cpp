#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Lemma: Sufficient and neccesory condition is that any one node can both reach and reachable by all others.
// Then every vertex can reach every other.
void dfs_forward(int node, vector<int> &visited, vector<vector<int>> &adj) {
    if(visited[node]) return;
    visited[node] = true;
    for(int child:adj[node]) {
        dfs_forward(child, visited, adj);
    }
}
void dfs_reverse(int node, vector<int> &visited, vector<vector<int>> &rev) {
    if(visited[node]) return;
    visited[node] = true;
    for(int child:rev[node]) {
        dfs_reverse(child, visited, rev);
    }
} 
int32_t main()
{
    int n;cin>>n;
    int m;cin>>m;

    vector<int> visited(n+1);
    vector<vector<int>> adj(n+1);
    vector<vector<int>> rev(n+1);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    dfs_forward(1, visited, adj);
    for(int i = 1;i<=n;i++) {
        if(!visited[i]) {
            cout<<"NO\n";
            cout<<1<<" "<<i;
            return 0;
        }
    }

    fill(visited.begin(), visited.end(), 0);

    dfs_reverse(1, visited, rev);
    for(int i = 1;i<=n;i++) {
        if(!visited[i]) {
            cout<<"NO\n";
            cout<<i<<" "<<1;
            return 0;
        }
    }
    cout<<"YES\n";

}
