#include "stations.h"
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int nn,co[1005];
bitset<1005>go;
vector<int>v[1005];

void dfs(int N,int h)
{
	go[N]=true;
	if(h%2==0)
	{
		co[N]=nn;
		nn++;
	}
	for(int i=0;i<v[N].size();i++)
	{
		if(!go[v[N][i]])
		{
			dfs(v[N][i],h+1);
		}
	}
	if(h%2==1)
	{
		co[N]=nn;
		nn++;
	}
	return;
}

vector<int>label(int n,int k,vector<int>a,vector<int>b)
{
	vector<int>labels(n);
	nn=0;
	for(int i=0;i<1005;i++)v[i].clear(),go[i]=false;
	for(int i=0;i<a.size();i++)
	{
		v[a[i]].pb(b[i]);
		v[b[i]].pb(a[i]);
	}
	dfs(0,0);
	for(int i=0;i<n;i++)labels[i]=co[i];
	return labels;
}

int find_next_station(int s,int t,vector<int>c)
{
	int st,ed,rech,repr,mxpr=0,mnch=imx;
	bool ch=false;
	for(int i=0;i<c.size();i++)
	{
		st=s,ed=c[i];
		if(ed<st)swap(st,ed);
		if(st<=t&&ed>=t)
		{
			if(mnch>ed-st)
			{
				ch=true;
				mnch=ed-st;
				rech=c[i];
			}
		}
		else
		{
			if(mxpr<ed-st)
			{
				mxpr=ed-st;
				repr=c[i];
			}
		}
	}
	if(ch)return rech;
	else return repr;
}
