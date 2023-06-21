#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    int x;cin>>x;
    
    vector<int> coin(n);
    for(int &i:coin) {
        cin>>i;
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1));
    for(int i = 0;i<=n;i++) {
        dp[i][0] = 1;
    }

    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=x;j++) {
            if(j - coin[i-1] < 0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-coin[i-1]])%MOD;
            }
        }
    }
    cout<<dp[n][x];
}