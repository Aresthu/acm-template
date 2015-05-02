// 本代码维护的是区间和
// 注意：① 请根据实际需要修改 modify、update、mergevalue 和 query 四个函数！
// ② N 的取值应该为区间最大值的 3~4 倍。
const int N=1000;
 
struct segment_tree
{
    struct node
    {
        node *lch, *rch;
        int st, en;
        int value;
        int delta;           // 懒惰修改标记
        void modify(int d)   // 懒惰修改
        { 
            value+=d*(en-st);
            delta+=d; 
        }
        void update()
        {
            if (lch and rch) 
            {
                lch->delta+=delta;
                lch->value+=delta*(lch->en - lch->st);
                rch->delta+=delta;
                rch->value+=delta*(rch->en - rch->st);
            }
            delta=0;
        }
        void mergevalue()
        {
            value = lch->value + rch->value;
        }
    } ST[N];
    int node_top;
 
    node *head() { return ST; }    
 
    void build(node *root, int st, int en)
    {
        root->st=st, root->en=en;
        root->value=root->delta=0;
        if (en-st>1)
        {
            int mid=(st+en)>>1;
            root->lch=&ST[++node_top]; root->rch=&ST[++node_top];
            build(root->lch, st, mid);
            build(root->rch, mid, en);
        }
    }
 
    segment_tree(int st, int en) { node_top=0; build(ST, st, en); }
 
    void modify(node *root, int st, int en, int delta)
    {
        if (st <= root->st and root->en <= en)
        {
            root->modify(delta);
        }
        else
        {
            if (root->delta != 0) root->update();
 
            int mid = (root->st + root->en)>>1;
            if (st<mid) modify(root->lch, st, en, delta);
            if (mid<en) modify(root->rch, st, en, delta);
 
            root->mergevalue();
        }
    }
 
    int query(node *root, int st, int en)
    {
        if (st <= root->st and root->en <= en)
            return root->value;
        else
        {
            if (root->delta != 0) root->update();
 
            int value=0;
            int mid = (root->st + root->en)/2;
            if (st<mid) value+=query(root->lch, st, en);
            if (mid<en) value+=query(root->rch, st, en);
            return value;
        }
    }
};
