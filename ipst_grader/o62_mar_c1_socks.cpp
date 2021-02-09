#include<bits/stdc++.h>
#include "sockslib.h"
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
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
int n,m,nn,st,ed,pr[2005][2005];
vector<int>v;
bitset<2005>ch;
queue<pair<int,int> >q;
void calc(int a,int b)
{
    int mid=(a+b)/2;
    vector<int>cc;
    if(a==b)return;
    for(int i=a;i<=b;i++)
    {
        cc.pb(i);
    }
    pr[a][b]=ask(cc);
    calc(a,mid);
    calc(mid+1,b);
    return;
}
int main()
{
    n=num();
    nn=n*2;
    calc(1,nn);
    // match(1,5);
    // match(2,6);
    // match(3,4);
    for(int i=1;i<=nn;i++)pr[i][i]=1;
    for(int i=1;i<=nn;i++)
    {
        if(ch[i])continue;
        st=1,ed=nn;
        while(st<ed)
        {
            bool p=false;
            int mid=(st+ed)/2;
            v.clear();
            for(int j=st;j<=mid;j++)
            {
                if(i==j)
                {
                    p=true;
                    continue;
                }
                v.pb(j);
            }
            if(!p)v.pb(i);
            if(ask(v)==pr[st][mid])ed=mid;
            else st=mid+1;
        }
        q.push({i,st});
        ch[i]=true;
        ch[st]=true;
    }
    while(!q.empty())
    {
        match(q.front().F,q.front().S);
        q.pop();
    }
}
