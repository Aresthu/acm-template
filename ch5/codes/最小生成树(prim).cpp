// 初始化：G表示邻接矩阵，n表示结点个数，下标从0开始
//         如果边(i,j)不存在，则G[i][j] = INF
// 调用：Prim(start)，其中start是图上某个点的编号，可以任取。
// 注意：① start的出度不能为0！
//        ② 无向图！
//        ③ 调用函数之后可以追踪cloest以获得生成树的具体连接情况
const int MAXN=1000, INF=0x3F3F3F3F;
int G[MAXN][MAXN], n;
 
int minEdge[MAXN];      // 与点N连接的最小边
int cloest[MAXN];       // 追踪
 
int Prim(int start=0)
{
    int ans=0, k=0;
    // 加入第一个点
    for (int i=0;i<n;i++)
    {
        minEdge[i]=G[start][i];
        cloest[i]=start;
    }
    minEdge[start]=0;
    for (int i=0;i<n-1;i++)
    {
        int min=INF;
        // 寻找离生成树最近的未加入顶点k
        for (int j=0;j<n;j++)
            if (minEdge[j]!=0 and minEdge[j]<min) min=minEdge[k=j];
        // 把找到的边加入到MST中
        ans+=minEdge[k];
 
        minEdge[k]=0;
        // 加入完毕。以后不用再处理这个点。
        // 重新计算最短边
        for (int j=0;j<n;j++)
            if (G[k][j]<minEdge[j])
            {
                minEdge[j]=G[k][j];
                cloest[j]=k;
            }
    }
    return ans;
}
