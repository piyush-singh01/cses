#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    vector<int> a(n); for(int &i:a) cin>>i;

    int x = accumulate(a.begin(), a.end(), 0);
    vector<bool> dp(x+1);
    dp[0] = true;

    for(int i = 1;i<=n;i++) {
        vector<bool> new_dp(x+1);
        new_dp[0] = true;
        
        for(int j = 1;j<=x  ;j++) {
            if(j - a[i-1] < 0) {
                new_dp[j] = dp[j]; 
            } else {
                new_dp[j] = dp[j] || dp[j - a[i-1]];
            }
        }
        dp = new_dp;
    }

    vector<int> money_sums;
    for(int sum = 1;sum<=x;sum++) {
        if(dp[sum]) {
            money_sums.push_back(sum);
        }
    }

    cout<<(int)money_sums.size()<<endl;
    for(int money:money_sums) {
        cout<<money<<" ";
    }
}