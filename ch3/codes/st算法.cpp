// 初始化：数据在data[]中。首先调用initRMQ()进行预处理，然后就可以用queryRMQ来进行查询。
// 注意：① 下标从0开始；② 下面代码求的是最大值；③ 头文件：algorithm、cmath
int data[N];
int f[N][20];
const int pow2[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,
                    16384,32768,65536,131072,262144,524288};
 
void initRMQ(int n)
{
    for (int i=0; i<n; i++) f[i][0]=data[i];
 
    int k = int(log(n)/log(2));
    for (int level=1; level<=k; level++)
        for (int i=0; i<n; i++)
            if (i + pow2[level-1]-1 < n)
                f[i][level] = max(f[i][level-1], f[i+pow2[level-1]][level-1]);
            else
                break;
}
 
int queryRMQ(int left, int right)
{
    int k = int(log(right-left+1)/log(2));
    return max(f[left][k], f[right-pow2[k]+1][k]);
}
