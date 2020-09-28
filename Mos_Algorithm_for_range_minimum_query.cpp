//Problem Statement:-
//Given an array A of size N, there are two types of queries on this array.
//(1) q l r in this query you need to print the minimum in the sub-array A[l:r]
//(2) u x y in this query you need to update A[x]=y

//Solution(Mo's Algorithm):-
//The main idea of the algorithm is to divide the array into blocks(ideally of length sqrt(N))
//and precompute the minimum for the blocks and store it in a different array
//and when query of type 1 is asked then traversing the block if required to reduce the runtime
//complexity from O(N) to O(sqrt(N))
//and when query of type 2 is asked then updating the array and recalculate the minimum for the
//block in which it lies thus increasing the time complexity from O(1) to O(sqrt(N))
//Overall the run time complexity of the algorithm is 
//O(N) for preprocessing 
//O(sqrt(N)) for answering the query and updating
//so overall the complexity will be O(Q*sqrt(N)) where Q is the number of query

#include<bits/stdc++.h>
using namespace std;

#define xlr8 ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nl '\n'

signed main()
{
    xlr8;
  
	int n,q;                     				      //Array lenght and number of query
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];

	int bl=ceil(sqrt(n));       				      //BLock length
	vector<int> s(n/bl+1);      				      //Array containing minimum value for the blocks

	for(int i=0;i<n;i++)
	{ 
		if(i%bl==0)               				      //Initialising
		    s[i/bl]=a[i];
		else                                    //Calculating the minimum and assigning back to the specific block
		    s[i/bl]=min(s[i/bl],a[i]);
	}
	
	while(q--)
	{
		char c;
		cin>>c;
		int l,r;
		cin>>l>>r;
		if(c=='q')                              //Query for printing the minimum in the given range
		{
		    l--,r--;
		    int ll=l/bl;						            //left side block number
		    int rr=r/bl;						            //right side block number
		    int ans=INT_MAX;
		    if(ll!=rr)							            //when range lies in multiple blocks
		    {
		        while(l<(ll+1)*bl)				      //traversing the first block
		            ans=min(ans,a[l++]);
		        for(int i=ll+1;i<rr;i++)		    //going upto the last block
		            ans=min(ans,s[i]);
		        for(int i=rr*bl;i<=r;i++)		    //traversing the last block
		            ans=min(ans,a[i]);
		    }
		    else
		        for(;l<=r;l++)					        //when range lies in the same block
		            ans=min(ans,a[l]);
		    cout<<ans<<nl;
		}
		else                                    //Query for updating the value
		{
		    l--;
		    a[l]=r;                             //Updating the array
		    int ll=l/bl;
		    s[ll]=INT_MAX;
		    for(int i=ll*bl;i<(ll+1)*bl;i++)    //Updating process for the block
		        s[ll]=min(s[ll],a[i]);
		}
	}

    return 0;
}
