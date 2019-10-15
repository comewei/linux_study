int max(int *a,int n)
{
	int m=a[0];
	int i=0;
	for(i;i<n;i++)
	{
	if(a[i]>m)
	m=a[i];
	}
	return m;
}

int sum(int *a,int n)
{
	int i=0;
	int s=0;
	for(i;i<n;i++)
	{
	s+=a[i];	
	}
	return s;
}
