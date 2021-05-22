/*
快速幂（Exponentiation by squaring，平方求幂）是一种简单而有效的小算法，它可以以[公式]的时间复杂度计算乘方。快速幂不仅本身非常常见，而且后续很多算法也都会用到快速幂。
*/

//递归
const int mod = 1e9+7;
typedef long long ll;

 ll qpow(ll a,ll b){
    int ans = 1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}