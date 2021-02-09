#include "highway.h"
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
vector<int>v[90005];
vector<int>hi[90005];
int h[90005];

void dfs(int nn,int hn)
{
    h[nn]=hn;
    for(int i=0;i<v[nn].size();i++)
    {
        if(h[v[nn][i]]==0)
        {
            dfs(v[nn][i],hn+1);
        }
    }
    return;
}

void find_pair(int n,vector<int>a,vector<int>b,int c1,int c2)
{
    int m=a.size(),re1,re2,st=1,ed=90000,mid,hh=90000;
    LL dis,tp;
    vector<int>co(m);
    for(int i=0;i<m;i++)
    {
        v[a[i]].pb(b[i]);
        v[b[i]].pb(a[i]);
    }
    dfs(0,1);
    for(int i=0;i<m;i++)
    {
        hi[max(h[a[i]],h[b[i]])].pb(i);
    }
    for(int i=0;i<m;i++)co[i]=0;
    dis=ask(co);
    while(st<=ed)
    {
        mid=(st+ed)/2;
        for(int i=0;i<m;i++)co[i]=0;
        for(int i=mid+1;i<=90000;i++)
        {
            for(int j=0;j<hi[i].size();j++)
            {
                co[hi[i][j]]=1;
            }
        }
        tp=ask(co);
        if(tp==dis)
        {
            hh=min(hh,mid);
            ed=mid-1;
        }
        else
        {
            st=mid+1;
        }
    }
    st=0,ed=hi[hh].size()-1,re1=hi[hh].size()-1;
    while(st<=ed)
    {
        mid=(st+ed)/2;
        for(int i=0;i<m;i++)co[i]=0;
        for(int i=st;i<=mid;i++)
        {
            co[hi[hh][i]]=1;
        }
        tp=ask(co);
        if(tp==dis)
        {
            st=mid+1;
        }
        else
        {
            re1=min(re1,mid);
            ed=mid-1;
        }
    }
    re1=hi[hh][re1];
    if(h[a[re1]]>h[b[re1]])re1=a[re1];
    else re1=b[re1];
    for(int i=0;i<90005;i++)h[i]=0;
    dfs(re1,1);
    for(int i=0;i<90005;i++)hi[i].clear();
    hh=(dis/c1)+1;
    for(int i=0;i<m;i++)
    {
        hi[max(h[a[i]],h[b[i]])].pb(i);
        //printf("%d %d %d\n",i,h[a[i]],h[b[i]]);
    }
    st=0,ed=hi[hh].size()-1,re2=hi[hh].size()-1;
    while(st<=ed)
    {
        mid=(st+ed)/2;
        for(int i=0;i<m;i++)co[i]=0;
        for(int i=st;i<=mid;i++)
        {
            co[hi[hh][i]]=1;
        }
        tp=ask(co);
        if(tp==dis)
        {
            st=mid+1;
        }
        else
        {
            re2=min(re2,mid);
            ed=mid-1;
        }
    }
    re2=hi[hh][re2];
    if(h[a[re2]]>h[b[re2]])re2=a[re2];
    else re2=b[re2];
    //printf("%d %d",re1,re2);
    answer(re1,re2);
    return;
}
