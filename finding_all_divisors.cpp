/*
Problem Statement:-
	Given a number n, find and print all its divisors in the increasing order
Solution:-
	Using mathematics
Runtime Complexity:-
	O(sqrt(n)*log(cbrt(n)))
Space Complexity:-
	O(cbrt(n)) as the upper bound for the number of divisors is n^(1/3)
*/
#include<iostream>
#include<set>

using namespace std;

int main()
{
	cout<<"\nEnter a number : ";
	int n;
	cin>>n;
	if(n<=0)
	{
		cout<<"\nCan't find the divisors";
		continue;
	}
	set<int> s;
	s.insert(1);
	s.insert(n);
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
		{
			s.insert(i);
			s.insert(n/i);
		}
	cout<<"\nDivisors of the number are : ";
	for(auto x:s)
		cout<<x<<" ";

	return 0;
}