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
int n,x,ps,nw,k,kk;
LL ans[100005],nn[200005][2],bs[200005],ss[200005][2],mx;
priority_queue<pii>pq;
bitset<200005>uu;
int F(int X)
{
    if(X==bs[X])return X;
    else return bs[X]=F(bs[X]);
}
void un(int X,int Y)
{
    if(nn[X][0]==nn[X][1])
    {
        nn[X][0]+=nn[Y][0];
        nn[X][1]+=nn[Y][1];
        ss[X][0]+=ss[Y][0];
        ss[X][1]+=ss[Y][1];
    }
    else
    {
        nn[X][0]+=nn[Y][1];
        nn[X][1]+=nn[Y][0];
        ss[X][0]+=ss[Y][1];
        ss[X][1]+=ss[Y][0];
    }
    bs[Y]=X;
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        bs[i]=i;
        scanf("%d",&x);
        pq.push({x,i});
    }
    while(!pq.empty())
    {
        x=pq.top().F;
        ps=pq.top().S;
        pq.pop();
        uu[ps]=true;
        nn[ps][0]=1;
        ss[ps][0]=x;
        mx+=x;
        nw++;
        if(uu[ps-1])
        {
            k=F(ps-1);
            kk=F(ps);
            if(nn[k][0]==nn[k][1])mx-=max(ss[k][0],ss[k][1]);
            else mx-=ss[k][0];
            if(nn[kk][0]==nn[kk][1])mx-=max(ss[kk][0],ss[kk][1]);
            else mx-=ss[kk][0];
            nw-=nn[k][0];
            nw-=nn[kk][0];
            un(k,kk);
            if(nn[k][0]==nn[k][1])mx+=max(ss[k][0],ss[k][1]);
            else mx+=ss[k][0];
            nw+=nn[k][0];
        }
        if(uu[ps+1])
        {
            k=F(ps);
            kk=F(ps+1);
            if(nn[k][0]==nn[k][1])mx-=max(ss[k][0],ss[k][1]);
            else mx-=ss[k][0];
            if(nn[kk][0]==nn[kk][1])mx-=max(ss[kk][0],ss[kk][1]);
            else mx-=ss[kk][0];
            nw-=nn[k][0];
            nw-=nn[kk][0];
            un(k,kk);
            if(nn[k][0]==nn[k][1])mx+=max(ss[k][0],ss[k][1]);
            else mx+=ss[k][0];
            nw+=nn[k][0];
        }
        // printf("==== %d %d %d\n",x,ps,nw);
        // for(int i=1;i<=n;i++)
        // {
        //     printf("[%d] %lld %lld %lld %lld\n",i,ss[i][0],ss[i][1],nn[i][0],nn[i][1]);
        // }
        ans[nw]=max(ans[nw],mx);
    }
    for(int i=1;i<=(n+1)/2;i++)
    {
        printf("%lld\n",ans[i]);
    }
}
