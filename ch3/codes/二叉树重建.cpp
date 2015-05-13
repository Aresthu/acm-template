// 中序 + 后序 -> 前序
void preorder(int n, char *pre, char *in, char *post)
{
	if (n<=0) return;
	int p=strchr(in, post[n-1])-in;
	pre[0]=post[n-1];
	preorder(p, pre+1, in, post);
	preorder(n-p-1, pre+p+1, in+p+1, post+p);
}

// 前序 + 中序 -> 后序
void postorder(int n, char *pre, char *in, char *post)
{
	if (n<=0) return;
	int p=strchr(in, pre[0])-in;
	postorder(p, pre+1, in, post);
	postorder(n-p-1, pre+p+1, in+p+1, post+p);
	post[n-1]=pre[0];
}


// 前序 + 后序 -> 中序
// 判断 pre、post 是否属于同一棵二叉树
bool check(int n, char *pre, char *post)		
{
	bool b;

	for (int i=0; i<n; i++)
	{
		b=false;
		for (int j=0; j<n; j++)
			if (pre[i]==post[j])
			{
				b=true;
				break;
			}
		if (!b) return false;
	}
	return true;
}

void inorder(int n, char *pre, char *in, char *post)
{
	if (n<=0) return;
	int p=1;
	while (check(p, pre+1, post)==false && p<n)
		p++;

    // 此时，如果再往 inorder 里传 p，pre 已经不含有效字符了。
	if (p>=n) p=n-1;				
	inorder(p, pre+1, in, post);
	in[p]=pre[0];
	inorder(n-p-1, pre+p+1, in+p+1, post+p);
}
