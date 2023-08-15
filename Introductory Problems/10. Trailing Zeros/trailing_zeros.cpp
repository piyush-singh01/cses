#include<iostream>

int main() {
    int n; std::cin>>n;
    int curr = 5;
    int trailingZeroes = 0;
    while (n >= curr) {
        trailingZeroes += n / curr;
        curr *= 5;
    }
    std::cout<<trailingZeroes;
}