#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
#define pb push_back
#define all(x) ((x).begin(),(x).end())
typedef long long LL;
int m,n,k,a,b,mr,di,t;
LL ans;
bool p1=true,p2=false;
vector<pair<LL,LL> >v[100005];
priority_queue<pair<LL,LL> >pq;
int main()
{
    scanf("%d %d %d",&m,&n,&k);
    mr=m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        for(int j=1;j<=t;j++)
        {
            scanf("%d %d",&a,&b);
            if(b==0)continue;
            pq.push({b,a});
        }
    }
    while(!pq.empty())
    {
        di=min((LL)mr,pq.top().S);
        mr-=di;
        ans+=(pq.top().F*(LL)di);
        pq.pop();
    }
    printf("%.7lf",(double)ans/(double)k);
}
