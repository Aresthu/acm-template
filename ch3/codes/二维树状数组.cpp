const int N=1000;
 
struct BIT
{
    int sum[N][N], m, n;    // m 行 n 列
 
    BIT(int row, int col): m(row), n(len) { memset(sum,0,sizeof(sum)); }
 
    int lowbit(int x) { return x & -x; }
 
    void add(int i, int j, int value)
    {
        for (; i<=row; i+=lowbit(i))
            for (int tj=j; tj<=col; tj+=lowbit(tj))
                sum[i][tj]+=value;
    }
    int query(int i, int j)
    {
        int r=0;
        for (; i>0; i-=lowbit(i))
            for (int tj=j; tj>0; tj-=lowbit(tj))
                r+=sum[i][tj];
        return r;
    }
};