/*
Problem Statement:-
	You are give a number n and you will be asked q queries, in each
	query you will be given a number x(x<=n), you have to print whether
	the number is prime or not
Solution(Sieve of eratosthenes):-
	The main idea is to Sieve of eratosthenes and store whether the number
	is prime or not in an array and when query is asked just check in the array
	for the answer
Runtime Complextiy:-
	O(n*log(log(n))) for preprocessing
	O(q) for query answering
Space Complexity:-
	O(n)
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cout<<"\nEnter a upper bound for number : ";
	cin>>n;
	vector<bool> prime(n+1, true);
	prime[0]=prime[1]=false;

	for(int i=2;i*i<=n;i++) 						//calculating the sieve
	    if(prime[i])
	        for(int j=i*i;j<=n;j+=i)				//if the number is prime marking it's multiples not prime
	            prime[j]=false;

	int q;
	cout<<"\nEnter the number of query : ";
	cin>>q;
	while(q--)
	{
		int x;
		cout<<"\nEnter a number : ";
		cin>>x;	
		if(x>n||x<0)
			return cout<<"\nInvalid number",0;

		if(prime[x])
			cout<<"\n"<<x<<" is a prime number\n";
		else
			cout<<"\n"<<x<<" is not a prime number\n";
	}
	
return 0;
}
