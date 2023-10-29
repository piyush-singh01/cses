#include<bits/stdc++.h>
using namespace std;
int32_t main() {
    
    int n;cin>>n;
    vector<int> a(n);
    for(int &e:a)
        cin>>e;

    int sum = accumulate(a.begin(), a.end(), 0LL);

    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for(int i = 0;i<n;i++) {
        for(int j = sum;j>=a[i];j--) {
            dp[j] = dp[j] || dp[j - a[i]];
        }
    }
    vector<int> money_sums;
    for(int i = 1;i<=sum;i++) {
        if(dp[i]) {
            money_sums.push_back(i);
        }
    }
    
    cout<<money_sums.size()<<'\n';
    for(int money:money_sums) {
        cout<<money<<" ";
    }
}