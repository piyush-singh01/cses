#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int32_t main()
{
    int n;cin>>n;
    vector<pair<int, int>> movie;

    for(int i = 0;i<n;i++) {
        int a,b;cin>>a>>b;
        movie.push_back({a,b});
    }

    auto cmp = [&](const pair<int,int> &x, const pair<int, int> &y) -> bool {
        return x.second < y.second;
    };

    sort(movie.begin(), movie.end(), cmp);
    int cnt = 0;
    int currEnd = -1;
    for(int i = 0;i<n;i++) {
        if(movie[i].first >= currEnd){
            cnt++;
            currEnd = movie[i].second;
        }
    }
    cout<<cnt;
}