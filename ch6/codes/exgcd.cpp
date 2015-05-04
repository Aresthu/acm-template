// 返回值为 a 和 b 的最大公约数
int exgcd(int a, int b, int &x, int &y)
{
    if (b)    // 1
    {
        int r=exgcd(b,a%b,x,y);
        int t=x; x=y; y=t-a/b*y;
        return r;
    }
    else
    {
        x=1,y=0;
        return a;
    }
}
