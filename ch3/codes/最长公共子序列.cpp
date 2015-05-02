// 注意：下标从 1 开始，m、n 分别表示 a[]、b[] 元素个数。
int f[1001][1001];
int LCS(int *a, int m, int *b, int n)
{
    memset(f,0,sizeof(f));
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        {
            if (a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
            f[i][j] = max(f[i][j], max(f[i-1][j], f[i][j-1]));
        }
    return f[m][n];
}