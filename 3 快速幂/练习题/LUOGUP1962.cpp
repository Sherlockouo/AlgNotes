#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

const int mod = 1e9+7;
typedef long long ll;
struct matrix
{
    ll a1, a2, b1, b2;
    matrix(ll a1, ll a2, ll b1, ll b2) : a1(a1), a2(a2), b1(b1), b2(b2) {}
    matrix operator*(const matrix &y)
    {
        matrix ans((a1 * y.a1 + a2 * y.b1) % mod,
                   (a1 * y.a2 + a2 * y.b2) % mod,
                   (b1 * y.a1 + b2 * y.b1) % mod,
                   (b1 * y.a2 + b2 * y.b2) % mod);
        return ans;
    }
};

matrix qpow(matrix a, ll n)
{
    matrix ans(1, 0, 0, 1); //单位矩阵
    while (n)
    {
        if (n & 1)
            ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

int main()
{
    ll x;
    matrix M(0, 1, 1, 1);
    scanf("%lld", &x);
    matrix ans = qpow(M, x - 1);
    printf("%lld\n", (ans.a1 + ans.a2) % mod);
    return 0;
}