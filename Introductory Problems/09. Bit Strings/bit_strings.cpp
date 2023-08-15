#include <iostream>
const int MOD = 1e9 + 7;
typedef long long int ll;

ll power(ll a, ll b, int mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a)%mod;
        }
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int n; std::cin>>n;
    std::cout<<power(2, n);
}