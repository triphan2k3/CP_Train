/// hhoangcpascal

#include <iostream>
#include <algorithm>
#include <vector>
#define llong long long

using namespace std;

const llong mod = 1e9+7;
llong n, l;

llong Power(llong A, llong N) {
    llong res = 1;

    while (N > 0) {
        if (N & 1) res = res * A % mod;
        A = A * A % mod;
        N >>= 1;
    }

    return res;
}

llong Cal(llong A, llong N) {
    if (N == 0) return 1;

    llong tmp = Cal(A, (N - 1) >> 1);
    tmp = (Power(A, (((N - 1) >> 1) + 1) * 2) * tmp + tmp) % mod;

    if ((N & 1) == 0) tmp = (tmp + Power(A, N * 2)) % mod;
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> l;
    cout << Cal(2, n) * Power(l, 2) % mod;

    return 0;
}