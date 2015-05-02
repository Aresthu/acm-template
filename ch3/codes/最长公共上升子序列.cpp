// 注意：
// ① 本段代码为上升序列。如果希望逆序，修改 (1); 如果希望有重复项，修改 (2)
// ② 所有数组的下标都是从 1 开始的
// ③ 序列会被记录到 ans[] 里，如果不需要，可以把代码 (*) 处删除
 
const int N=1000;
 
int f[N];
int prev[N], ans[N];     // (*) 记录序列
 
int LCIS(int *a, int na, int *b, int nb)
{
    memset(f,0,sizeof(f));
    memset(prev,0,sizeof(prev));     // (*) 记录序列
 
    for (int i=1;i<=na;i++)
    {
        for (int j=1,k=0;j<=nb;j++)
        {
            if (b[j]<a[i] and f[j]>f[k]) k=j;  // (1) 逆序：b[j]>a[i]
            if (b[j]==a[i])
            {
                f[j]=(k>0)?(f[k]+1):1;
                prev[j]=k;
                // (2) 重复项：此处加入 k=j;
            }
        }
    }
 
    int pos=0;
    for (int i=1; i<=nb; i++) if (f[i]>f[pos]) pos=i;
 
    // (*) 记录序列
    for (int q=pos, i=f[pos]; i>0; q=prev[q], i--) ans[i]=b[q];
 
    return f[pos];
}