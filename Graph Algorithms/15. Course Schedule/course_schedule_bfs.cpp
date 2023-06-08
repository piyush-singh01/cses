#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for(int i = 1;i<=n;i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);
        for(int child:adj[node]) {
            indegree[child]--;
            if(indegree[child] == 0) {
                q.push(child);
            }
        }
    }

    if(ans.size() != n) {
        cout<<"IMPOSSIBLE";
        return 0;
    }

    for(int node:ans) {
        cout<<node<<" ";
    }
}