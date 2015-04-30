int part(int *a, int start, int end)
{
    int low=start, high=end;
    int temp, check=a[start];
    do
    {
        while (a[high]>=check && low<high) high--;
        if (a[high]<check) temp=a[high], a[high]=a[low], a[low]=temp;
        while (a[low]<=check && low<high) low++;
        if (a[low]>check) temp=a[high], a[high]=a[low], a[low]=temp;
    }
    while (low!=high);
    a[low]=check;
    return low;
}

int find(int *a, int start, int end, int k)
{
    if (start==end) return a[start];
    // 计算p位置的“排名”
    int p = part(a, start, end);
    // 只对包含第k小元素的部分进行查找和排序。
    int q = p-start+1;
    if (k <= q)
        return find(a, start, p, k);
    else
        return find(a, p+1, end, k-q);
}
