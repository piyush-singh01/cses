#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i = 1;i<=m;i++) {
        int a,b;cin>>a>>b;a--;b--;
        adj[a].push_back(b);
    }

    int dp[1<<n][n] = {};
    dp[1][0] = 1;
    for(int i = 0;i<(1<<n);i++) {
        if(!(i&1)) continue;    // if city 1 not in mask
        if((i&(1<<(n-1))) and (i != (1<<(n-1)))) continue;  // if city n in mask and not full set
        for(int j = 0;j<n;j++) {
            if(!((1<<j)&i)) continue;   // if j not in mask
            for(int k:adj[j]) {
                if(!dp[i][j] or ((1<<k)&i)) continue;   // if j not reachable or k already visited.
                dp[i | (1<<k)][k] += dp[i][j];
                dp[i | (1<<k)][k] %= MOD;
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1];
}
