// 结点编号从1开始，共n个结点。
struct node
{
	int v;
	node *parent, *leftchild, *rightchild;
} a[1001], *p;
int maxd;
bool T[1003];
#define t(x) T[((x)==NULL)?0:((x)-a+1)]
node *p;
void DFS(node * x, int l)
{
	if (l>maxd) maxd=l, p=x;
	if (x==NULL) return;
	t(x)=false;
	if (t(x->parent)) DFS(x->parent, l+1);
	if (t(x->leftchild)) DFS(x->leftchild, l+1);
	if (t(x->rightchild)) DFS(x->rightchild, l+1);
}

int distance(node *tree)			// tree已经事先读好
{
	maxd=0;
	memset(T, 0, sizeof(T));
	for (int i=1; i<=n; i++)
		T[i]=true;
	DFS(tree,0);

	maxd=0;
	memset(T, 0, sizeof(T));
	for (int i=1; i<=n; i++) T[i]=true;
	DFS(p,0);

	return maxd;
}

