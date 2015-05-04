// full_permutation有三个参数，
//    第一个参数是待排列的字符，
//    第二个参数是字符个数，
//    在调用的时候，第三个参数应该为0
 
const int N=20;
char result[N];         // 储存结果
bool used[N];           // 表示是否已经被使用
 
void full_permutation(char *item, int n, int depth=0)
{
    if (depth==n)
    {
        // 输出结果
        for (int i=0; i<n; i++) cout<<result[i];
        return;
    }
 
    for (int i=0; i<n; i++)
        if (not used[i])
        {
            used[i]=true;
            result[depth]=item[i];
            full_permutation(item,n,depth+1);
            used[i]=false;
        }
}
