#include<iostream>
using namespace std;

long long gcd(long long a, long long b, long long &x, long long &y) {
    long long t, d;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    d = gcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b*y;
    return d;
}

long long modular(long long a, long long b, long long n) {
    long long d, e, x, y;
    d = gcd(a, n, x, y);
    if (b % d) return -1;
    e = x * (b / d) % n + n;
    return e % (n / d);
}

int main() {
    long long d, a, b, c, k;
    while (cin >> a >> b >> c >> k) {
        if (a == 0 && b == 0 && c == 0 && k == 0) break;
        d = modular(c, b - a, (long long) 1 << k);
        if (d == -1)
            cout << "FOREVER" << endl;
        else
            cout << d << endl;
    }
    return 0;
}

