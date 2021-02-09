#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define IMX INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int fen[200005],n,pos[200005],Q,pp[200005],a,c,b;
priority_queue<pair<int,pair<int,int> > >pq;
vector<pair<int,int> >v;
void up(int idx)
{
    while(idx<200005)
    {
        fen[idx]++;
        idx+=idx&(-idx);
    }
    return;
}
int SS(int idx)
{
    int re=0;
    while(idx>0)
    {
        re+=fen[idx];
        idx-=idx&(-idx);
    }
    return re;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&pos[i]);
        v.push_back({-pos[i],i});
    }
    sort(all(v));
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        scanf("%d %d",&a,&b);
        pq.push({-a,{b,i}});
    }
    for(int i=1;i<=n;i++)
    {
        //printf("---%d\n",v[i-1].S);
        up(v[i-1].S);
        if(!pq.empty())
        {
            while(-pq.top().F==i)
            {
                a=-pq.top().F;
                b=pq.top().S.F;
                c=pq.top().S.S;
                pq.pop();
                int st=1,ed=n,mid,ans=INT_MAX;
                while(st<=ed)
                {
                    mid=(st+ed)/2;
                    if(SS(mid)>=b)
                    {
                        ans=min(mid,ans);
                        ed=mid-1;
                    }
                    else st=mid+1;
                }
                pp[c]=pos[ans];
                if(pq.empty())break;
            }
        }
    }
    for(int i=1;i<=Q;i++)printf("%d\n",pp[i]);
}
