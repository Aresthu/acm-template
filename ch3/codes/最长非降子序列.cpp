// 注意：
// ① 本段代码为最长非降子序列
// ② 所有数组的下标都是从 1 开始的
// ③ 序列会被记录到 ans[] 里，如果不需要，可以把代码 (*) 处删除
// ④ 如果希望数字不重复，请修改代码中的 (1) 处
//    如果希望寻找下降或非升序列，请修改代码中的 (1)、(2)、(3) 处
const int N=1000;
const int INIT=0x3F3F3F3F;
 
int C[N], f[N];
int f_max, f_last;
int C_prev[N], C_id[N], ans[N];     // (*) 记录序列
 
int b_search(int *a, int left, int right, int val)
{
    while (left<right)
    {
        int mid=(left+right)/2;
        if (a[mid]<=val) left=mid+1; else right=mid;
        // (1) 最长上升序列：把 <= 改成 <
        //     下降序列改成 > ，非升序列改成 >=
    }
    return left;   // (2) 下降和非升序列：改成 right
}
 
int LIS(int *a, int n)
{
    memset(C, INIT, sizeof(C));   // (3) 下降和非升序列：把 INIT 改成 0
    C[0]=a[0]; f_max=f_last=0;
 
    for (int i=0; i<n; i++)
    {
        int pos=b_search(C, 0, i, a[i]);
        f[i]=pos+1; C[pos]=a[i];
        if (f[i]>f_max) f_max=f[i], f_last=i;
 
        // (*) 记录序列
        C_id[pos]=i;
        if (pos==0) C_prev[i]=-1; else C_prev[i]=C_id[pos-1];        
    }
 
    // (*) 记录序列
    for (int p=f_last, i=f_max; i>0; p=C_prev[p], i--) ans[i]=a[p];
 
    return f_max;
}