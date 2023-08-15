#include<bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main()
{
    string s;cin>>s;
    int n = s.size();

    int i = 1;
    int cnt = 1;
    int maxCnt = 1;
    while(i<n) {
        if(s[i] == s[i-1]) {
            while(s[i] == s[i-1]) {
                i++;
                cnt++;
            }
        } else {
            maxCnt = max(maxCnt, cnt);
            cnt = 1;
            i++;
        }
    }
    maxCnt = max(maxCnt, cnt);

    cout<<maxCnt;
}