// 注意：需要左闭右开区间！
int c[100002];
int mergeSort(int *a, int l, int r)
{
    int mid, i, j, tmp;
    int cnt = 0;
    if (r>l+1)
    {
        mid = (l+r)/2;
        cnt += mergeSort(l, mid);
        cnt += mergeSort(mid, r);
        tmp = l;
        for (i=l,j=mid; i<mid && j<r; )
        {
            if (a[i]>a[j])
            {
                c[tmp++] = a[j++];
                // 使用排序,就可以方便地数跨“分界”的逆序对个数了
                cnt += mid-i;
            }
            else
            {
                c[tmp++] = a[i++];
            }
        }
        for (; j<r; j++) c[tmp++] = a[j];
        for (; i<mid; i++) c[tmp++] = a[i];
        for (i=l; i<r; i++) a[i]=c[i];
    }
    return cnt;
}