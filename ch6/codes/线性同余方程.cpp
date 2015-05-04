// 如果有解则输出解并返回 true，否则返回 false
bool mod_equation(int a, int b, int n)
{
    int x,y;
    int d=exgcd(a,n,x,y);
 
    if (b%d != 0) 
        return false;
    else
    {
        int e = x*(b/d) % n;
        for (int i=0; i<d; i++)
            cout<< (e + i*(n/d)) % n <<endl;
        return true;
    }
}
