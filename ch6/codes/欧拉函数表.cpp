void phi_table(int *a, int n)
{
    memset(a,0,sizeof(int)*(n+1));
    a[1]=1;
    for (int i=2; i<=n; i++)
        if (!a[i])
            for (int j=1; j<=n; j+=i)
            {
                if (!a[j]) a[j]=j;
                a[j]=a[j]/i*(i-1)
            }
}
