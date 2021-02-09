#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define all(x) ((x)).begin(),((x)).end()
#define F first
#define S second
#define pb push_back
#define L (idx*2)
#define R ((idx*2)+1)
typedef long long LL;
typedef pair<int,int> pii;
int n,m,sp[100005],ans,a,b,c,d,e,ti,k;
vector<pair<int,pair<pii,pii> > >v;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&sp[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        v.pb({b,{{a,c+1},{d+1,e}}});
    }
    sort(all(v));
        for(int i=1;i<=n;i++)
        {
            ans=0,ti=1,k=1e9;
            for(int j=0;j<m;j++)
            {
                if(i>=v[j].S.F.S&&i<=v[j].S.S.F)
                {
                    //printf("{%d %d}",i,j);
                    ans+=(v[j].F-ti)*sp[i];
                    ti=v[j].F;
                    //printf("-%d-",v[j].S.F.F);
                    if(v[j].S.F.F==1)
                    {
                        if(ans<=v[j].S.S.S)k=min(k,v[j].S.S.S);
                        //printf("[%d %d]",ans,v[j].S.S.S);
                    }
                    else
                    {
                        sp[i]=min(sp[i],v[j].S.S.S);
                        //printf("(%d %d %d)",sp[i],v[j].S.S.S,ans);
                    }
                }
            }
            ans+=(((int)1e8)-ti+1)*sp[i];
            printf("%d\n",min(ans,k));
    }
}
