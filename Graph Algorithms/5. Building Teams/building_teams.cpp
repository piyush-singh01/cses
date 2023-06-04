#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
// graph 2 coloring
bool dfs(int node, int c, vector<int> &color, vector<vector<int>> &adj) {
    color[node] = c;
    for(int child:adj[node]) {
        if(color[child] == -1) {
            if(dfs(child, c^1, color, adj) == false) {
                return false;
            }
        } else {
            if(color[child] == color[node]) {
                return false;
            }
        }
    }
    return true;
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

    vector<bool> visited(n+1, false);
    vector<int> color(n+1, -1);

    for(int i = 1;i<=n;i++) {
        if(color[i] == -1) {
            if(dfs(i, 0, color, adj) == false) {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i = 1;i<=n;i++) {
        cout<<color[i] + 1<<" ";
    }
}