#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

/**/
int n;
void dfs1(int node, int par, int d, vll &dp, vll&ans, vvll &adj) {
    ans[1] += d;
    dp[node] = 1; 
    for(int child:adj[node]) {
        if(child == par) continue;
        dfs1(child, node, d+1, dp, ans, adj);
        dp[node] += dp[child];
    }
}
/**/
void dfs2(int node, int par, vll &ans, vll &dp, vvll &adj) {
    if(par != -1)
        // `n - num` nodes increase by 1 and `num` nodes decrease by 1.
        ans[node] = ans[par] + (n - dp[node]) - dp[node];

    for(int child:adj[node]) {
        if(child == par) continue;
        dfs2(child, node, ans, dp, adj);
    }
}
/**/
int32_t main()
{
    cin>>n;
    vvll adj(n+1);
    for(int i = 0;i<n-1;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<long long> dp(n+1);
    vector<long long> ans(n+1);

    dfs1(1, -1, 0, dp, ans, adj);
    dfs2(1, -1, ans, dp, adj);

    for(int node = 1;node<=n;node++) {
        cout<<ans[node]<<" ";
    }
}