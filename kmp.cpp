/*
Problem Statement:-
	Given two strings a text(t) and a pattern(p) you need to find the number of 
	occurrences of the string in the text
Solution(KMP(Knuth–Morris–Pratt) algorithm):-
	The main idea is to use the prefix function array denoted by pi
	in the kmp algorithm on the string p+'#'+t
Runtime Complexity:-
	O(n+m) where n is the length of the pattern and m is the length of the text
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	cout<<"\nEnter a text : ";
	string t;
	getline(cin,t);
	cout<<"\nEnter a pattern : ";
	string p;
	getline(cin,p);
	string buff=p+'#'+t;
	int n=buff.size();

	vector<int> pi(n);
	for(int i=1;i<n;i++)				//calculating the prefix function array
	{
		int j=pi[i-1];
		while(j>0&&buff[j]!=buff[i])
			j=pi[j-1];
		if(buff[j]==buff[i])			//else the j will be zero
			j++;
		pi[i]=j;
	}

	vector<int> ans;
	for(int i=p.size();i<n;i++)
		if(pi[i]==p.size())
			ans.push_back(i);
	
	cout<<"\nNumber of occurrences of the string in the text are : "<<ans.size()<<endl;
	
	if(ans.size())
	{
		cout<<"\nString found at the positions : ";
		for(auto x:ans)
			cout<<x-2*p.size()<<" ";
	}
	cout<<endl;

return 0;
}
