#include<bits/stdc++.h>
using namespace std;
typedef array<int, 2> ar;

// dp[node][0] == if the edge between node and parent is not taken.
// dp[node][1] == if the edge between node and parent is taken.

// dp[node][1] == sum over all children, with no edge. Sum(dp[child][0]);
// dp[node][0] == can take at most one child with edge. Max(sum - dp[child][0] + dp[child][1] + 1)

void dfs(int node, int par, vector<ar> &dp, vector<vector<int>> &adj) {
    for(int child:adj[node]) {
        if(child == par) continue;
        dfs(child, node, dp, adj);
        dp[node][1] += dp[child][0];
    }
    int sum = dp[node][1];
    dp[node][0] = sum;  // if not taking any child.
    for(int child:adj[node]) {
        if(child == par) continue;
        dp[node][0] = max(dp[node][0], sum - dp[child][0] + dp[child][1] + 1);
    }
}
int32_t main() {
    int n;cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 0;i<n-1;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int root = 1;
    vector<ar> dp(n+1);
    dfs(root, -1, dp, adj);
    cout<<max(dp[root][0], dp[root][1]);
}