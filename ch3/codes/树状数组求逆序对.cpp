// ****************************
//  备注：代码是抄袭的，需要消化和整理
// ****************************

#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN=100000;
using namespace std;
 
struct node
{
    long long v;
    int id;
    bool operator< (const node &p) const {return v<p.v;}
};
 
node a[MAXN+10];
long long c[MAXN+10];
long long b[MAXN+10];
int n;
 
inline int lowbit(int x) { return x bitand -x; }
long long Query(int x) 
{
    long long ans=0;
    while (x)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void Change(int x)
{
    while (x<=n)
    {
        c[x]++;
        x+=lowbit(x);
    }
}
 
int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    cin>>n;
    for (int i=1; i<=n; i++) { cin>>a[i].v; a[i].id=i; }
    sort(a+1, a+1+n);
 
    int pre=-1;
    int prevalue=0;
    for (int i=1; i<=n; i++)
    {
        if (pre!=a[i].v)
        {
            pre=a[i].v;
            a[i].v=++prevalue;
        }
        else
            a[i].v=prevalue;
    }
 
    for (int i=1; i<=n; i++)
        b[a[i].id]=a[i].v;
 
    long long s=0;
    for (int i=n; i>=1; i--)
    {
        Change(b[i]);
        s+=Query(b[i]-1);
    }
    cout<<s<<endl;
    return 0;
}