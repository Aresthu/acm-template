const int MAX=1000;
 
struct node
{
    int value;
    node *parent;           // 根据实际需要来添加
    node *left, *right;
};
 
int n=0;
node tree[MAX], *head=NULL;
 
inline node *createNode()
{
    node *t=&tree[++n];
    t->value=0; t->parent=NULL; t->left=t->right=NULL;
    return t;
}
 
void preOrder(node *p)      // 前序遍历
{
    if (p==NULL) return;
    cout<<p->value<<' '; preOrder(p->leftchild); preOrder(p->rightchild);
}
void inOrder(node *p)       // 中序遍历
{
    if (p==NULL) return;
    inOrder(p->leftchild); cout<<p->value<<' '; inOrder(p->rightchild);
}
void postOrder(node *p)     // 后序遍历
{
    if (p==NULL) return;
    postOrder(p->leftchild); postOrder(p->rightchild); cout<<p->value<<' ';
}
