// combination有五个参数，
//    第一个参数是待排列的字符，
//    第二个和第三个参数分别是组合数的n和m，
//    在调用的时候，第四个和第五个参数应该为0
const int N=20;
char result[N];         // 储存结果
 
void combination(char *item, int n, int m,
                 int pos=0, int depth=0)
{
    if (depth==m)
    {
        // 输出结果
        for (int i=0; i<n; i++) cout<<result[i];
    }
    for (int i=pos; i<n-(m-depth); i++)
    {
        result[depth]=item[i];
        combination(item, n, m, i+1, depth+1);
    }
}
