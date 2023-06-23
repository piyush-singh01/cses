#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
// cycle print
bool dfs(int node,int par, vector<int> &path, vector<bool> &visited, vector<vector<int>> &adj) {
    visited[node] = true;
    path.push_back(node);
    for(int child:adj[node]) {
        if(!visited[child]) {
            if(dfs(child, node, path, visited, adj) == true) {
                return true;
            }
        } else {
            if(child != par) {
                path.push_back(child);
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}
void convertToCycle(vector<int> &path) {
    reverse(path.begin(), path.end());

    int n = path.size();
    int idx = 0;
    for(int i = 1;i<n;i++) {
        if(path[0] == path[i]) {
            idx = i;
            break;
        }
    }
    path.resize(idx + 1);
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
    vector<int> path;
    for(int i = 1;i<=n;i++) {
        if(!visited[i]) {
            if(dfs(i, -1, path, visited, adj)) {
                convertToCycle(path);
                
                cout<<(int)path.size()<<"\n";
                for(int i = 0;i<(int)path.size();i++) {
                    cout<<path[i]<<" ";
                }
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE";
}