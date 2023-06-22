#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    string s;cin>>s;
    string t;cin>>t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i = 1;i<=n;i++) {
        dp[i][0] = i;
    }
    for(int j = 1;j<=m;j++) {
        dp[0][j] = j;
    }

    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (s[i-1] != t[j-1])});
        }
    }
    cout<<dp[n][m];
}