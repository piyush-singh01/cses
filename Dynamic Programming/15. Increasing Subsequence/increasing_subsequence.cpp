#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    vector<int> a(n); for(int &i:a) cin>>i;

    vector<int> temp;
    for(int i = 0;i<n;i++) {
        if(temp.empty() or temp.back() < a[i]) {
            temp.push_back(a[i]);
        } else {
            int idx = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            temp[idx] = a[i];
        }
    }
    cout<<temp.size();
}