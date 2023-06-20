#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    int x;cin>>x;
    vector<int> a(n); for(int &i:a) cin>>i;
 
    sort(a.begin(), a.end());
    int i = 0;
    int j = n - 1;
    int cnt = 0;
    while(i <= j) {
        if(a[i] + a[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
        cnt++;
    }
    cout<<cnt;
}
