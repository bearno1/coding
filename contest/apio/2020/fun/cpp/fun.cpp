#include "fun.h"
#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define all(x) (x).begin(),(x).end()
#define MEM(x,a) memset((x),a,sizeof((x)))
#define F first
#define S second
#define imx INT_MAX
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
typedef pair<int,int> pii;
int cen,di[505],k,gr,ls=-1,mx,dd,bs[100005],se;
priority_queue<pii>pq[3];
bitset<100005>del;
vector<int>l,r;
int F(int X)
{
    if(X==bs[X])return X;
    else return F(bs[X]);
}
std::vector<int> createFunTour(int N, int Q)
{
    vector<int>re;
        int mr=2,rr=1;
        l.push_back(0);
        se=-1;
        for(int i=1;i<N;i++)
        {
            if(rr<mr/2)
            {
                l.push_back(-i);
            }
            else
            {
                r.push_back(-i);
            }
            if(rr==mr)mr*=2,rr=1;
        }
        sort(all(l));
        sort(all(r));
        for(int i=l.size()-1;i>0;i--)
        {
            l[i]=-l[i];
            r.push_back(l[i]);
        }
        int ra=0,rb=0;
        for(int i=0;i<N;i++)
        {
            if(se=-1)
            {
                while(del[l[ra]])ra++;
                re.push_back(l[ra]);
                del[l[ra]]=true;
                se=1;
            }
            else
            {
                while(del[r[rb]])rb++;
                re.push_back(r[rb]);
                del[r[ra]]=true;
                se=-1;
            }
        }
        return re;
    for(int i=0;i<N;i++)
    {
        bool cc=true;
        for(int j=0;j<N;j++)
        {
            if(attractionsBehind(i,j)>N/2&&i!=j)cc=false;
            di[j]=hoursRequired(i,j);
        }
        if(cc)
        {
            //printf("{%d}",i);
            cen=i;
            break;
        }
    }
    del[cen]=true;
    //printf("[%d]",cen);
    //for(int i=0;i<N;i++)printf("%d ",di[i]);
    //printf("\n");
    while(1)
    {
        bool cc=true;
        for(int i=0;i<N;i++)
        {
            if(!del[i])cc=false,k=i;
        }
        if(cc)break;
        pq[gr].push({di[k],k});
        del[k]=true;
        //printf("\n{%d}",k);
        for(int i=0;i<N;i++)
        {
            if(del[i])continue;
            if(hoursRequired(k,i)<di[k]+di[i])
            {
                pq[gr].push({di[i],i}),del[i]=true;
                //printf("{%d}",i);
            }
        }
        gr++;
    }
    for(int i=1;i<N;i++)
    {
        mx=0,dd=ls;
        for(int j=0;j<3;j++)
        {
            if(ls==j)continue;
            if(pq[j].size()==0)continue;
            if(mx<pq[j].top().F)mx=pq[j].top().F,dd=j;
            if(mx==pq[j].top().F)
            {
                if(pq[j].size()>pq[dd].size())dd=j;
            }
        }
        re.push_back(pq[dd].top().S);
        //printf("%d %d",dd,pq[dd].size());
        //printf("[%d %d]\n",pq[dd].top().S,dd);
        pq[dd].pop();
        ls=dd;
    }
    re.push_back(cen);
//    for(int i=0;i<N;i++)printf("%d ",re[i]);
    return re;
}
