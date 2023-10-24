#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    int w;cin>>w;
    vector<int> cost(n+1);
    vector<int> pages(n+1);

    for(int i = 1;i<=n;i++) {
        cin>>cost[i];
    }
    for(int i = 1;i<=n;i++) {
        cin>>pages[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(w+1));

    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=w;j++) {
            if(j - cost[i] < 0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], pages[i] + dp[i-1][j - cost[i]]);
            }
        }
    }
    cout<<dp[n][w];
}