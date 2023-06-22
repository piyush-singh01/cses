
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 2e9;
int32_t main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
 
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            if(i == j) {
                dp[i][j] = 0;
            } else {
                for(int k = 1;k<i;k++) {
                    dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
                }
                for(int k = 1;k<j;k++) {
                    dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
                }
            }
        }
    }
    cout<<dp[n][m];
}
