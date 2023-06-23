#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
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
    vector<int> parent(n+1);

    int src = 1;
    int dest = n;

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int child:adj[curr]) {
            if(!visited[child]) {
                visited[child] = true;
                parent[child] = curr;
                q.push(child);
            }
        }
    }

    if(!visited[dest]) {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    
    vector<int> p;
    int curr = dest;
    while(curr != src) {
        p.push_back(curr);
        curr = parent[curr];
    }
    p.push_back(src);

    reverse(p.begin(), p.end());

    cout<<(int)p.size()<<"\n";
    for(int i:p) {
        cout<<i<<" ";
    }
}