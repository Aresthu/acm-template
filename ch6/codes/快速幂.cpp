// 相信大家很容易就能把此代码改成求 a^b mod c
typedef long long ll;
ll quickpow(ll a, ll b)
{
    if (a==1 or b==0) return 1;
 
    ll r=1, t=a;
    while (b)
    {
        if (b%2) r*=t;
        b>>=1;
        t*=t;
    }
    return r;
}
