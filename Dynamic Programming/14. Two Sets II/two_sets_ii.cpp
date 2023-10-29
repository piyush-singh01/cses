#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int32_t main() {

    int n;cin>>n;
    int sum = (n * (n + 1))/2;
    if(sum&1) {
        cout<<0;
        return 0;
    }

    sum /= 2;
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    // loop only till `n - 1`, include the last element in one set, two avoid dp[sum]/2
    for(int i = 0;i<n-1;i++) {
        for(int j = sum;j>=(i+1);j--) {
            (dp[j] += dp[j - i - 1]) %= MOD;
        }
    }
    cout<<dp[sum];
}