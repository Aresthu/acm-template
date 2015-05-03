// 初始化：G表示邻接矩阵，n表示结点个数，下标从0开始
//         如果边(i,j)不存在，则G[i][j] = INF
// 调用：Dijkstra(start)，其中start是起点。结果保存在d[]中。
// 注意：① 不能有负边！
//        ② 调用函数之后可以追踪prev以获得具体的路径
const int MAXN=2000, INF=0x3F3F3F3F;
int G[MAXN][MAXN], n;
 
bool visited[MAXN];   // 是否被标号
int d[MAXN];          // 从起点到某点的最短路径长度
int prev[MAXN];
 
void Dijkstra(int start)
{
    memset(visited, 0, sizeof(visited));
    memset(d,INF,sizeof(d));     // 注意memset的局限性！
    d[start]=0;
 
    for (int i=0; i<n; i++)
    {
        int x, min=INF;
        // 在所有未标号的结点中,选择一个d值最小的点x。
        for (int a=0; a<n; a++) if (!visited[a] && d[a]<min) min=d[x=a];
 
        // 标记这个点x。
        visited[x]=true;
        // 对于从x出发的所有边(x,y),更新一下d[y]。
        for (int y=0; y<n; y++)
            if (d[y] > d[x]+G[x][y])
            {
                // y这个最短路径是从x走到y。
                d[y] = d[x]+G[x][y];
                prev[y] = x;
            }
    }
}
