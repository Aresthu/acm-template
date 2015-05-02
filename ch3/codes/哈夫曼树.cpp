const int INF=9999999, M=100;
 
struct node
{
    int w;
    node *parent, *leftchild, *rightchild;
} h[M];
 
// weight[i]表示结点i的权值。返回值是Huffman的树根。
node *makeHuffman(int *weight, int n)        
{
    node *p1, *p2;
 
    memset(h,0,sizeof(h));
    for (int i=0; i<n; i++) h[i].w=weight[i];
    int m=2*n-1;
 
    for (node *np=h+n; np<h+m; np++)
    {
        int min1=INF, min2=INF;
        for (node *op=h; op<np; op++)
        {
            if (op->parent==0)        // 处理未处理节点
            {
                if (op->w < min1)    // 选择权值最小的两个点
                    min2=min1, min1=op->w, p2=p1, p1=op;
                else if (op->w < min2)
                    min2=op->w, p2=op;
            }
        }
        p1->parent = p2->parent = np;
        np->leftchild = p1;
        np->rightchild = p2;
        np->w = p1->w + p2->w;
    }
    return &h[2*n-2];
}
