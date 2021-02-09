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
typedef pair<LL,int>PQ;
int n,x,fen[300005];
LL ans,a,rr,b,ls=-1;
priority_queue<PQ,vector<PQ>,greater<PQ> >pq;
queue<int>q;
void up(int idx)
{
    while(idx<=300004)
    {
        fen[idx]++;
        idx+=idx&(-idx);
    }
    return;
}
int ss(int idx)
{
    LL re=0;
    while(idx>0)
    {
        re+=fen[idx];
        idx-=idx&(-idx);
    }
    return re;
}
int main()
{
    pq.push({1e18+1,-1});
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        pq.push({x,i});
    }
    while(pq.top().S!=-1)
    {
        if(pq.top().F!=ls)
        {
            while(!q.empty())up(q.front()),q.pop(),rr++;
        }
        ls=pq.top().F;
        q.push(pq.top().S);
        a=ss(pq.top().S);
        pq.pop();
        ans+=(a*(rr-a));
    }
    printf("%lld",ans);
}
