// Simulation
#include <iostream>
using namespace std;
int main()
{
    long long n; cin >> n;
    while (true) {
        cout<<n<<" ";
        if(n == 1)
            break;
        if (n & 1) {
            n *= 3;
            n++;
        } else {
            n /= 2;
        }
    }
}