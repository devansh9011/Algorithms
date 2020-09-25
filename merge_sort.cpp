#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &a,int l,int m,int r)
{
	int nl=m-l+1,nr=r-m;
	vector<int> g(nl),h(nr);
	for(int i=l;i<=m;i++)
		g[i-l]=a[i];
	for(int i=m+1;i<=r;i++)
		h[i-m-1]=a[i];
	int i=0,j=0,k=l;
	while(i<nl&&j<nr)
	{
		if(g[i]<=h[j])
			a[k++]=g[i++];
		else
			a[k++]=h[j++];
	}
	while(i<nl)
		a[k++]=g[i++];
	while(j<nr)
		a[k++]=h[j++];
}

void mergesort(vector<int> &a,int l,int r)
{
	if(l<r)
	{
		int mid=(r+l)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}

}

int main()
{
	cout<<"\nEnter the number of elements in the array : ";
	int n;
	cin>>n;
	cout<<"\nEnter the elements of the array : ";
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,0,n-1);
	cout<<"\nSorted array is : ";
	for(auto x:a)
		cout<<x<<" ";

	return 0;
}