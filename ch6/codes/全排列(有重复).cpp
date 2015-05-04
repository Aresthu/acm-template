// 调用：unrepeat_permutation
//    第一个参数是待排列的字符，
//    第二个参数是字符个数
const int N=20;
 
void search(char *newitem, int new_n, int *count,
            int depth, int n, char *result)
{
    if (depth==n)
    {
        for (i=0; i<n; i++) cout<<result[i];
        return;
    }
    for (int i=0; i<new_n; i++)
        if (count[i] > 0)
        {
            used[i]--;
            result[depth] = newitem[i];
            search(newitem, new_n, cnt, depth+1, n, result);
            used[i]++;
        }
}
 
void unrepeat_permutation(char *item, int n)
{
    // 预处理，统计本质不同的数的个数
    char uniqueitem[N];
    int count[N]={0};
    int m=0;
 
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            if (item[i]==uniqueitem[j]) { count[j]++; break; }
 
        if (j==m)
        {
            uniqueitem[m]=val, count[m]=1;
            m++;
        }
    }
 
    // 开始搜索
    char result[N];
    search(uniqueitem, m, count, 0, n, result);
}
