#include "split.h"
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
vector<int>v[100005],cn[100005];
vector<pii>gr;
bitset<100005>vis;
int ch[100005],mn,pos,rr,re[100005];

void dfs(int N)
{
	if(re[N]!=0)return;
	vis[N]=true;
	ch[N]=1;
	for(int i=0;i<v[N].size();i++)
	{
		if((!vis[v[N][i]])&&re[v[N][i]]==0)
		{
			dfs(v[N][i]);
			ch[N]+=ch[v[N][i]];
			cn[N].pb(v[N][i]);
		}
	}
	//printf("[%d %d]\n",N,ch[N]);
	return;
}

void grdiv(int N,int ty)
{
	if(rr>=gr[ty].F||re[N]!=0)return;
	ch[N]=0;
	rr++,re[N]=gr[ty].S;
	for(int i=0;i<cn[N].size();i++)
	{
		grdiv(cn[N][i],ty);
	}
	return;
}

vector<int>find_split(int n,int a,int b,int c,vector<int>p,vector<int>q)
{
	vector<int>ans(n);
	gr.pb({a,1});
	gr.pb({b,2});
	gr.pb({c,3});
	sort(all(gr));
	for(int i=0;i<p.size();i++)
	{
		v[p[i]].pb(q[i]);
		v[q[i]].pb(p[i]);
	}
	dfs(0);
	mn=imx,rr=1;
	for(int i=0;i<n;i++)
	{
		if(ch[i]>=gr[0].F&&ch[i]<mn)
		{
			mn=ch[i];
			pos=i;
		}
	}
	re[pos]=gr[0].S,ch[pos]=0;
	for(int i=0;i<cn[pos].size();i++)grdiv(cn[pos][i],0);
	for(int i=0;i<n;i++)vis[i]=false;
	dfs(0);
	mn=imx,rr=1;
	for(int i=0;i<n;i++)
	{
		if(ch[i]>=gr[1].F&&ch[i]<mn)
		{
			mn=ch[i];
			pos=i;
		}
	}
	if(mn!=imx)
	{
		re[pos]=gr[1].S,ch[pos]=0;
		for(int i=0;i<cn[pos].size();i++)grdiv(cn[pos][i],1);
		for(int i=0;i<n;i++)
		{
			//printf("%d ",re[i]);
			if(re[i]==0)ans[i]=gr[2].S;
			else ans[i]=re[i];
		}
		//printf("\n");
	}
	return ans;
}
