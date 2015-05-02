const int N=1000;

struct BIT
{
    int sum[N], n;
 
    BIT(int len): n(len) { memset(sum,0,sizeof(sum)); }
 
    BIT(int *a, int len): n(len) 
    {
        int *pre = new int[len+1]; pre[0]=0;
        for (int i=1; i<=len; i++) pre[i]=pre[i-1]+a[i];
        for (int i=1; i<=len; i++) sum[i]=pre[i]-pre[i-lowbit(i)];
        delete [] pre;
    }
 
    int lowbit(int x) { return x & -x; }
 
    void add(int i, int value) { for (; i<n; i+=lowbit(i)) sum[i]+=value; }
    int query(int i)
    {
        int r=0;
        for (; i>0; i-=lowbit(i)) r+=sum[i];
        return r;
    }
    int query(int x, int y) { return query(y)-query(x-1); }
};