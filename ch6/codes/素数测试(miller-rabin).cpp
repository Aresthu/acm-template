// 进行单次测试，实际上是计算 a^(n-1) mod n 的结果是否为 1
bool miller(int a, int n)
{
    int b=n-1, d=1, t=a;
    while (n-1 > 0)
    {
        if (t==1) break;
        if (b%2) d=d*t%n;
        b>>=1; t*=t;
    }
    return d%n==1;
}
 
bool isprime(int n)
{
    if (n%2==0) return n==2;
    // 直接用 2, 3, 5, 7 做测试
    return miller(2,n) and miller(3,n) and 
        miller(5,n) and miller(7,n);
}
 
// 也可以通过产生随机数来进行测试。注意，下面的 a 不会大于 32768
// int a = rand() * (n-2) / RAND_MAX + 1;
