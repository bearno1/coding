#include<bits/stdc++.h>
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
typedef pair<int,int> pii;
int n,m,botn[200005],botm[200005],fen[400005],con[200005],rr,co;
vector<int>seq;
vector<pii>v;
LL ans,k;
int ss(int x)
{
    LL re=0;
    while(x>0)
    {
        re+=fen[x];
        x-=x&(-x);
    }
    return re;
}
void up(int x)
{
    while(x<400005)
    {
        fen[x]++;
        x+=x&(-x);
    }
    return;
}
int main()
{
    scanf("%d %d",&n,&m);
    rr=1,co=0;
    for(int i=1;i<=n;i++)scanf("%d",&botn[i]),v.pb({botn[i],i});
    for(int i=1;i<=m;i++)scanf("%d",&botm[i]),v.pb({botm[i],-1});
    sort(all(v));
    for(int i=0;i<v.size();i++)
    {
        if(v[i].S!=-1)
        {
            co++;
            botn[v[i].S]=i+1;
        }
        else
        {
            con[rr]=co;
            rr++;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i].S==-1)
        {
            seq.pb(i+1);
        }
    }
    for(int i=1;i<=n;i++)seq.pb(botn[i]);
    for(int i=0;i<seq.size();i++)
    {
        k+=ss(seq[i]);
        up(seq[i]);
        //printf("%d ",seq[i]);
    }
    //printf("\n");
    ans=k;
    for(int i=1;i<=m;i++)
    {
        k+=(con[m-i+1]+con[m-i+1]-n);
        ans=max(ans,k);
        //printf("%d\n",k);
    }
    printf("%lld",ans);
}
