/*
Problem statement:-
    Given a array of size n, sort it and print it
Solution(Quick Sort Algorithm):-
    Main idea is to use the divide and conquer strategy by  choosing a pivot
    and making all the element smaller than pivot to the left of it and
    remaining to the right of it, this work is done using the partition function()
    this whole thing is then done recursively for the left part and for the right part
    so in the end we get a sorted array
Runime Complexity:-
    best case n*log(n)
    worst case n^2
    average case n*log(n)
Note:-
    It is not a stable sorting technique so incase the order of the equal elements 
    matters then this is not a ideal choice

Benefits of randomized quick sort over traditional one:-
	* Probability of getting worstcase is 1/(1*2*....*(n-1)*n) which is obviously very 
	  less than the traditional one
	* This algorithm works in O(n*log(n)) with the probability of 1/2 because even if
	  we are able to partition the array into 25-75 ratio or better than that then the 
	  complexity will be close to O(n*log(n))
	* It's time complexity is not dependent on the input array as in traditional one if
	  the array is already sorted then it will take O(n^2)
*/
#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

void swap(int &a,int &b)
{
  int r=a;
  a=b;
  b=r;
}

int partition(int l,int r,vector<int> &a)
{
 	int piv=(rand()%(r-l+1)+l); 	//generating a random position from l to r
 	swap(a[l],a[piv]);				//since the pivot has to be the first element
 	
	int i=l+1,j=l+1;        		//creating two partitions where i is defining the boundry between them
	                      			//i is pointing to the first element of the right partition
	                      			//and j is pointing to the first unchecked element
	for(;j<=r;j++)
	{
		if(a[j]<a[l])
		{
		  swap(a[i],a[j]);
		  i++;
		}
	}
	swap(a[i-1],a[l]);
	return i-1;						//last position of the left partition
}
int ans=0;

void quicksort(int l,int r,vector<int> &a)
{
  ans+=max(r-l,0);
  if(l>=r)
    return;
  int pivot=partition(l,r,a);			//partitioning the array
  quicksort(l,pivot-1,a);			  	//calling quicksort for the left partition
  quicksort(pivot+1,r,a);			  	//calling quicksort for the right partition
}

int main()
{  
	srand((time(0)));
	cout<<"\nEnter the number of elements in the array : ";
	int n;
	cin>>n;
	vector<int> a(n);
	cout<<"\nEnter the elements of the array : ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	quicksort(0,a.size()-1,a);
	cout<<"\nSorted array is : ";
	for(auto x:a)
		cout<<x<<" ";
	cout<<"\nNumber of comparisons made : "<<ans;

 return 0;
}
