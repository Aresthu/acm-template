// 初始化：G表示邻接矩阵，n表示结点个数，下标从0开始
//         如果边(i,j)不存在，则G[i][j] = INF
// 调用：Floyd()。结果保存在f[][]中。
// 注意：调用函数之后可以追踪prev以获得具体的路径
const int MAXN=300, INF=0x3F3F3F3F;
int G[MAXN][MAXN], n;
 
int f[MAXN][MAXN], prev[MAXN][MAXN];
 
void Floyd()
{
    memcpy(f,G,sizeof(G));
    memset(prev, -1, sizeof(prev));
 
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (f[i][k] + f[k][j] < f[i][j])
                {
                    f[i][j] = f[i][k] + f[k][j];
                    prev[i][j] = k;
                }
}
