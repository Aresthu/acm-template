// 中国剩余定理，下标从 0 开始，a 表示余数，m 表示模且 m[0..n-1]两两互素。
int sunzi(int *a, int *m, int n)
{
	int M=1;
	for (int i=0; i<n; i++) M*=m[i];

	int ans=0;
	for (int i=0; i<n; i++)
	{
		// 由于 M 是 m[0..n-1]（两两互素）的乘积，
		// 所以 Mi 可以被除 m[i] 以外的任何整数整除
		int Mi=M/m[i];

		// 使 x*Mi 除以 m[i] 余 1，也就是解 Mi*k=1 (mod m[i])
		int x,y;
		exgcd(Mi,m[i],x,y);

		// 由于 Mi 除以其他 m 都能整除，而 x*Mi 除以 m[i] 余 1，
		// 所以再乘 a[i]，就可以满足第 i 条等式
		// 将 n 条等式加在一起，则可以满足所有等式
		ans=(ans+a[i]*x*Mi)%M;
	}

	while (ans<0) ans+=M;
	return ans;
}
