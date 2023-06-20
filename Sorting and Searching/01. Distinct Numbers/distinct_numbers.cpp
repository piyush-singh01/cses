#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    set<int> s;
    for(int i = 0;i<n;i++){
        int a;cin>>a;
        s.insert(a);
    }
    cout<<(int)s.size();
}