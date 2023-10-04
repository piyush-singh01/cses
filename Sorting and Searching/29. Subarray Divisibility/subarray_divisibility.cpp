#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

ll nc2(ll n) {
    return ((n) * (n - 1))/2;
}
int32_t main()
{
    int n;cin>>n;
    vector<int> a(n); for(int &i:a) cin>>i;

    ll pf = 0;
    vector<int> pfmod(n);
    for(int i = 0;i<n;i++) {
        pf += a[i];
        pfmod[i] = ((pf % n) + n) % n;
    }


    map<int, int> freq;
    for(int i = 0;i<n;i++) {
        freq[pfmod[i]]++;
    }

    ll res = 0;
    for(auto it:freq) {
        res += nc2(it.second);
        if(it.first == 0) {
            res += it.second; // array with one element containing self.
        }
    }
    cout<<res;
}