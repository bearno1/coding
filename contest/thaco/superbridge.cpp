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
int n,m,k,u,v,w,bs[100005],cc,nn,co;
LL cost;
priority_queue<pair<pii,pii> >pq;
vector<int>B;
vector<pii>BR;
set<int>s;
set<int>::iterator it;
int F(int X)
{
    if(bs[X]==X)return X;
    else return bs[X]=F(bs[X]);
}
void un(int X,int Y)
{
    bs[F(X)]=F(Y);
    return;
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)bs[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        pq.push({{-w,i},{u,v}});
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d %d",&u,&w);
        pq.push({{-w,i},{0,u}});
    }
    cc=n-1;
    while(cc)
    {
        w=-pq.top().F.F;
        nn=pq.top().F.S;
        u=pq.top().S.S;
        v=pq.top().S.F;
        pq.pop();
        if(v==0)
        {
            //printf("=%d %d %d\n",u,w,nn);
            cost+=w;
            cc--;
            BR.pb({nn,u});
        }
        else
        {
            if(F(u)!=F(v))
            {
                //printf("=%d %d %d\n",u,v,w);
                cost+=w;
                un(u,v);
                cc--;
                B.pb(nn);
            }
        }
    }
    for(int i=1;i<=n;i++)s.insert(F(bs[i]));
    for(int i=0;i<BR.size();i++)
    {
        it=s.begin();
        if(*it==F(BR[i].S))
        {
            it++;
            co=*it;
            s.erase(F(BR[i].S));
            un(BR[i].S,co);
            BR[i].S=co;
        }
        else
        {
            co=*it;
            s.erase(F(BR[i].S));
            un(BR[i].S,co);
            BR[i].S=co;
        }
    }
    printf("%lld\n",cost);
    printf("%d\n",B.size());
    for(int i=0;i<B.size();i++)printf("%d\n",B[i]);
    printf("%d\n",BR.size());
    for(int i=0;i<BR.size();i++)printf("%d %d\n",BR[i].F,BR[i].S);
}
