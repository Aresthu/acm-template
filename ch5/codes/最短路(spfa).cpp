// 初始化：先调用 init，然后用addedge来添加所有边。
// 调用：SPFA(start)。start是起点。如果有负环则返回false，否则返回true。
// 注意：① 下标从0开始；② 结果保存在 d[] 中。
const int MAXN=1000, MAXM=100000, INF=0x3F3F3F3F;
 
struct edge
{
    int u,v,w;
    edge *next;
} mem[MAXM], *adj[MAXN];
 
int m=0;
void init() { m=0; memset(adj,0,sizeof(adj)); }
 
void addedge(int u, int v, int w)
{
    edge *p = &mem[m++];
    p->u=u, p->v=v, p->w=w;
    p->next=adj[p->u];
    adj[p->u]=p;
}
 
queue<int> q;
bool inqueue[MAXN];
int cnt[MAXN];     // 结点进队次数。如果超过n说明有负环。
int d[MAXN];
 
bool SPFA(int start)
{
    memset(d,INF,sizeof(d));     // 注意memset的局限性！
    memset(cnt,0,sizeof(cnt));
 
    d[start]=0;
    q=queue<int>();
    q.push(start);      // 源点入队
    cnt[start]++;
    while (!q.empty())
    {
        int x=q.front(); q.pop();
        inqueue[x]=false;
 
        // 对队首点出发的所有边进行松弛操作(即更新最小值)
        for (edge *e=adj[x];e!=NULL;e=e->next)
        {
            int &v=e->v, &w=e->w;
            if (d[v]>d[x]+w)
            {
                d[v] = d[x]+w;
                // 将不在队列中的尾结点入队
                if (!inqueue[v])
                {
                    q.push(v); inqueue[v]=true;
                    // 有负环
                    if (++cnt[v]>n) return false;
                }
            }
        }
    }
    return true;
}
