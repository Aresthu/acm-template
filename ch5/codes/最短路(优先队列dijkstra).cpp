// 初始化：先调用init，然后用addedge来添加所有边。
// 调用：Dijkstra(start)，其中start是起点。结果保存在d[]中。
// 注意：① 不能有负边！
//        ② 调用函数之后可以追踪prev以获得具体的路径
//        ③ #include <queue>、<vector>、<utility>
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
 
typedef pair<int, int> pii;
priority_queue < pii, vector<pii>, greater<pii> > q;
int d[MAXN], prev[MAXN];
 
void Dijkstra(int start)
{
    memset(d,INF,sizeof(d));     // 注意memset的局限性！
    d[start]=0;
    q.push(make_pair(d[start], start));
 
    while (!q.empty())
    {
        // 在所有未标号的结点中,选择一个d值最小的点x。
        pii u=q.top(); q.pop();
        int x=u.second;
        // 已经计算完
        if (u.first!=d[x]) continue;
 
        for (edge *e=adj[x]; e!=NULL; e=e->next)
        {
            int &v=e->v, &w=e->w;
            if (d[v] > d[x]+ w)
            {
                // 松弛
                d[v] = d[x]+ w;
                prev[v]=x;
                q.push(make_pair(d[v], v));
            }
        }
    }
}
