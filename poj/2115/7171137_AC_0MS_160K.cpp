#include <stdio.h>
typedef long long llg;
llg extgcd(llg a, llg b, llg &x, llg &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	llg d = extgcd(b, a % b, x, y);
	llg t = x;
	x = y;
	y = t - a / b * y;
	return d;
}
llg mod_linear_solver(llg a, llg b, llg n)
{
	llg x, y;
	llg d = extgcd(a, n, x, y);
	if(b % d == 0)
	{
		llg t = n / d;
		x = (x * (b / d)) % n;
		return (x + n) % t;
	}
	return -1;
}
int main(void)
{
	llg a, b, c, k;
	while(scanf("%lld%lld%lld%lld", &a, &b, &c, &k) != EOF)
	{
		if(a == 0 && b == 0 && c == 0 && k == 0)
			break;
		llg m = 1LL << k;
		if(b >= m)
		{
			printf("FOREVER\n");
			continue;
		}
		if(a-b == 0)
		{
			printf("0\n");
			continue;
		}
		llg t = b - a;
		if(t < 0)
			t += m;
		llg n = mod_linear_solver(c, t, m);
		if(n < 0)
			printf("FOREVER\n");
		else
			printf("%lld\n", n);
	}
	return 0;
}
