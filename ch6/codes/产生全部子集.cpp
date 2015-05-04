// full_combination有四个参数，
//    第一个参数是待排列的字符，
//    第二个参数是字符个数，
//    在调用的时候，第三个和第四个参数应该为0
const int N=20;
char result[N];         // 储存结果
 
void full_combination(char *item, int n,
                 int pos=0, int depth=0)
{
    for (int i=0; i<depth; i++) cout<<result[i];
    cout<<endl;
 
    for (int i=pos; i<n; i++)
    {
        result[depth]=item[i];
        full_combination(item, n, i, depth+1);
    }
}
