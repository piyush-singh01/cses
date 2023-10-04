#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

/**/
template<class T>
std::istream& operator>>(std::istream &in, std::vector<T> &list) {for(T &x:list) {in>>x;} return in;} 
template<class T>
std::ostream& operator<<(std::ostream &out, std::vector<T> const &list) { for(const T &x:list) {out<<x<<" ";} return out;} 
/**/
int32_t main() {
    int n;cin>>n;
    vector<int> a(n); cin>>a;
    sort(a.begin(), a.end());

    ll pf = 0;
    for(int i = 0;i<n and a[i] <= (pf + 1);i++) {
        pf += a[i];
    }
    cout<<pf + 1;
}