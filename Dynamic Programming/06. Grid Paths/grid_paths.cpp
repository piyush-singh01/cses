#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int INF = 2e9;

int32_t main()
{
    int n;cin>>n;
    vector<string> grid(n);
    for(int i = 0;i<n;i++) {
        cin>>grid[i];
    }

    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = 0;i<n;i++) {
        if(grid[i][0] == '*') {
            break;
        }
        dp[i][0] = 1;
    }

    for(int j = 0;j<n;j++) {
        if(grid[0][j] == '*') {
            break;
        }
        dp[0][j] = 1;
    }
    
    for(int i = 1;i<n;i++) {
        for(int j = 1;j<n;j++) {
            if(grid[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            }
        }
    }
    cout<<dp[n-1][n-1];
}