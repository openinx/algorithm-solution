#include <cstdio>
//ax + by = gcd(a, b)
long long extended_gcd(long long a, long long b, long long &x, long long &y)
{
    long long ret, tmp;
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ret = extended_gcd(b, a % b, x, y);
    tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ret;
}
//ax = b mod n
long long modular_linear_equation(long long a, long long b, long long n)
{
    long long x, y, e;
    long long d = extended_gcd(a, n, x, y);
    if (b % d)  return -1;
    e = b / d * x % n + n;
    return e % (n / d);
}
int main()
{
    long long a, b, c, ans;
    int k;

    while (scanf("%lld %lld %lld %d", &a, &b, &c, &k) == 4)
    {
        if (a == 0 && b == 0 && c == 0 && k == 0)
            break;
        ans = modular_linear_equation(c, b - a, 1LL << k);
        if (ans == -1)
            puts("FOREVER");
        else
            printf("%lld\n", ans);
    }

    return 0;
}
