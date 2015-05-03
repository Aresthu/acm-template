// G[][] 表示树的邻接矩阵（可改写成邻接表），结果保存在 LCA[][] 中
// 注意：求 LCA 之前先调用 memset(parent,-1,sizeof(parent));
const int N=1000;
int G[N][N], n, LCA[N][N];
int parent[N];
 
int find(int p) { return parent[p]==p ? p : find(parent[p]); }
void unin(int i, int j) { parent[find(i)] = find(j); }
 
void LCA(int u)
{
    parent[u]=u;
 
    for (int i=0; i<n; i++)
        if (G[u][i] and parent[i]==-1) { LCA(i); unin(i,u); }
 
    for (int i=0; i<n; i++)
        if (parent[i]!=-1) LCA[u][i]=LCA[i][u]=find(i);
}
