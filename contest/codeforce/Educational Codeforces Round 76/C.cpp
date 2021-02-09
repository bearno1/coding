#include<bits/stdc++.h>
#define F first
#define S second
const long long MOD = (long long)(1e9+7);
using namespace std;
int t,n,x,ans;
vector<int>v[200005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=INT_MAX;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            v[x].push_back(i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<v[i].size();j++)
            {
                ans=min(ans,v[i][j]-v[i][j-1]+1);
            }
        }
        if(ans==INT_MAX)printf("-1\n");
        else printf("%d\n",ans);
    }
}
