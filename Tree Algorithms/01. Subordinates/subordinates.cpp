#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &dp, vector<vector<int>> &adj) {
    dp[node] = 1;
    for(int child:adj[node]) {
        if(child == parent) continue;

        dfs(child, node, dp, adj);
        dp[node] += dp[child];
    }
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 2;i<=n;i++) {
        int x;cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    vector<int> dp(n+1);
    dfs(1, -1, dp, adj);

    for(int i = 1;i<=n;i++) {
        cout<<dp[i] - 1<<" ";
    }
}