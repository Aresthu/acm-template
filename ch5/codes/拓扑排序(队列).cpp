// 初始化： G 表示邻接矩阵，n 表示结点个数，下标从 0 开始
//         从 i 到 j 如果连通，则 G[i][j]=false ，否则 G[i][j]=true
// 调用： toposort()，如果有环则返回 false 。排序结果保存在数组 a 中。
 
const int MAXN=1000;
 
bool G[MAXN][MAXN];     // 邻接矩阵
int n;                  // 结点个数
int cnt[MAXN];          // cnt[i] 表示结点 i 的入度
int a[MAXN], a_n;       // 结果保存在数组 a 中
queue<int> q;
 
bool toposort()
{
    memset(cnt,0,sizeof(cnt));
    a_n=0; q=queue<int>();
 
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (G[i][j]) cnt[j]++;
 
    for (int i=0;i<n;i++) if (cnt[i]==0) q.push(i);
 
    while (not q.empty())
    {
        int i=q.front(); q.pop();
        a[a_n++]=i;
        for (int j=0;j<n;j++)
        {
            if (G[i][j])
            {
                cnt[j]--;
                if (cnt[j]==0) q.push(j);
            }
        }
    }
 
    for (int i=0;i<n;i++) if (cnt[i]!=0) return false;
    return true;
}
