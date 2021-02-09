#include<bits/stdc++.h>
#define F first
#define S second
const long long MOD = (long long)(1e9+7);
using namespace std;
int t,k,n,m,ans;
vector<pair<int,int> >v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        scanf("%d %d",&n,&m);
        v.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&k);
            ans+=k*2;
            v.push_back({k,i});
        }
        sort(v.begin(),v.end());
        if(m<n||n==2)printf("-1\n");
        else
        {
            m-=n;
            ans+=(v[0].F+v[1].F)*m;
            printf("%d\n",ans);
            for(int i=1;i<n;i++)
            {
                printf("%d %d\n",i,i+1);
            }
            printf("%d %d\n",1,n);
            while(m--)
            {
                printf("%d %d\n",v[0].S,v[1].S);
            }
        }
    }
}
