#include "mushrooms.h"
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int count_mushrooms(int n)
{
	int k,rr=1,ca=0,X=161,Y=3;
	vector<int>a,b,t;
	if(n<200)Y=n-1,X=n-1;
	a.pb(0);
	for(int i=1;i<n&&i<=Y;i++)
	{
		t.clear();
		t.pb(0);
		t.pb(i);
		k=use_machine(t);
		if(k==1)b.pb(i);
		else a.pb(i);
	}
	if(a.size()>b.size())
	{
		for(int i=Y+1;i<n&&i<=X;i+=2)
		{
			t.clear();
			t.pb(i);
			t.pb(a[0]);
			t.pb(i+1);
			t.pb(a[1]);
			k=use_machine(t);
			if(k%2==1)b.pb(i);
			else a.pb(i);
			if(k>1)b.pb(i+1);
			else a.pb(i+1);
		}
	}
	else
	{
		for(int i=Y+1;i<n&&i<=X;i+=2)
		{
			t.clear();
			t.pb(i);
			t.pb(b[0]);
			t.pb(i+1);
			t.pb(b[1]);
			k=use_machine(t);
			if(k%2==1)a.pb(i);
			else b.pb(i);
			if(k>1)a.pb(i+1);
			else b.pb(i+1);
		}
	}
	for(int i=X+1;i<n;i++,rr++)
	{
		if(a.size()>b.size())
		{
			if(rr==1)t.clear(),t.pb(a[0]);
			t.pb(i);
			t.pb(a[rr]);
			if(i==n-1)
			{
				k=use_machine(t);
				ca+=rr-(k/2);
				rr=0;
			}
			else if(rr+1==a.size())
			{
				i++;
				t.pb(i);
				k=use_machine(t);
				ca+=rr-(k/2);
				rr=0;
				if(k%2==0)a.pb(i);
				else b.pb(i);
			}
		}
		else
		{
			if(rr==1)t.clear(),t.pb(b[0]);
			t.pb(i);
			t.pb(b[rr]);
			if(i==n-1)
			{
				k=use_machine(t);
				rr=0;
				ca+=k/2;
			}
			else if(rr+1==b.size())
			{
				i++;
				t.pb(i);
				k=use_machine(t);
				rr=0;
				ca+=k/2;
				if(k%2==0)b.pb(i);
				else a.pb(i);
			}
		}
	}
	return a.size()+ca;
}
