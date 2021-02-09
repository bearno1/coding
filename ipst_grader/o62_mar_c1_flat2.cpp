#include<bits/stdc++.h>
#define F first
#define S second
const long long MOD = (long long)(1e9+7);
using namespace std;
int n,m,boss[100005],si[100005],hi[100005],a,b,ans[100005],l[100005],r[100005];
priority_queue<pair<int,int> >pq;
int F(int x)
{
    if(boss[x]==x)return x;
    else return boss[x]=F(boss[x]);
}
void un(int x,int y)
{
    si[F(x)]+=si[F(y)];
    l[F(x)]=min(l[F(x)],l[F(y)]);
    r[F(x)]=max(r[F(x)],r[F(x)]);
    boss[F(y)]=F(x);
    return;
}
int main()
{
    scanf("%d %d",&n,&m);
    hi[0]=-10;
    hi[n+1]=-10;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&hi[i]);
        pq.push({hi[i],i});
        ans[i]=-1;
        boss[i]=i;
        si[i]=1;
        l[i]=i;
        r[i]=i;
    }
    while(!pq.empty())
    {
        a=pq.top().F;
        b=pq.top().S;
        pq.pop();
        if(hi[b]<=hi[b+1])
        {
            if(F(b)!=F(b+1))
            {
                un(b,b+1);
            }
        }
        if(hi[b]<=hi[b-1])
        {
            if(F(b)!=F(b-1))
            {
                un(b,b-1);
            }
        }
        if(hi[l[F(b)]-1]!=a&&hi[r[F(b)+1]]!=a)
        {
            //printf("---%d %d\n",si[F(b)]-1,a);
            ans[si[F(b)]-1]=max(ans[si[F(b)]-1],a);
        }
    }
    if(m==-10)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d ",ans[i]);
        }
    }
    else
    {
        printf("%d",ans[m]);
    }
}
