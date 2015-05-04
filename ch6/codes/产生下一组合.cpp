// 注意：只接受从1开始的*连续*数字
//      如果想使用其他元素，可以考虑索引。
bool next_combination(int *index, int n, int m)
{
    int j=m-1;
    while (j>=0 and index[j]==n-(m-1-j)) j--;
    if (j>=0)
    {
        index[j]++;
        for (int k=j+1; k<m; k++) index[k]=index[k-1]+1;
    }
    return j>=0;
}
