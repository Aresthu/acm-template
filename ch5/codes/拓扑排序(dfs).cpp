// 初始化：G 表示邻接矩阵，n 表示结点个数，下标从 0 开始
//         从 i 到 j 如果连通，则 G[i][j]=false，否则 G[i][j]=true
// 调用：toposort()，如果有环则返回 false。排序结果保存在数组 a 中。
 
const int MAXN=1000;
 
bool G[MAXN][MAXN];    // 邻接矩阵
int n;                 // 结点个数
int a[MAXN], a_n;
 
// 结点访问情况：0、1、2分别代表未访问、正在访问、已访问。
//               如果正在访问的点又被访问一次，说明有环。
int vis[MAXN];
 
bool DFS(int v)
{
    vis[v]=1;
    for (int i=0; i<n; i++)
        if (G[i][v])
        {
            if (vis[i]==1) return false;
            else if (vis[i]==0) if (not DFS(i)) return false;
        }
    vis[v]=2; a[a_n++]=v;
    return true;
}
 
bool toposort()
{
    memset(vis, 0, sizeof(vis));
    a_n=0;
    for (int i=0;i<n;i++)
        if ((not vis[i]) and (not DFS(i))) return false;
    return true;
}
