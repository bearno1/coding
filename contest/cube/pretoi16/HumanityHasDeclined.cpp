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
int n,m,k,sq,l,r,ch,cc[200005],cur1=0,cur2=1,sw[200005],q;
vector<pair<pair<int,int>,int> >v[600];
bitset<200005>ans;
int main()
{
    scanf("%d %d %d",&n,&m,&q);
    sq=sqrt(n);
    for(int i=1;i<=n;i++)scanf("%d",&sw[i]);
    for(int i=1;i<=q;i++)
    {
        scanf("%d %d",&l,&r);
        v[l/sq].pb({{r,l},i});
    }
    ch=m;
    for(int i=0;i<600;i++)
    {
        sort(all(v[i]));
        for(int j=0;j<v[i].size();j++)
        {
            l=v[i][j].F.S;
            r=v[i][j].F.F;
            k=v[i][j].S;
            if(cur1<l-1)
            {
               for(int i=cur1+1;i<l;i++)
               {
                  cc[sw[i]]--;
                  if(sw[i]<=m&&cc[sw[i]]==0)
                  {
                      ch++;
                  }
               }
            }
            if(cur1>l-1)
            {
               for(int i=cur1;i>l-1;i--)
               {
                  cc[sw[i]]++;
                  if(sw[i]<=m&&cc[sw[i]]==1)
                  {
                      ch--;
                  }
               }
            }
            cur1=l-1;
            if(cur2<r+1)
            {
               for(int i=cur2;i<r+1;i++)
               {
                  cc[sw[i]]++;
                  if(sw[i]<=m&&cc[sw[i]]==1)
                  {
                      ch--;
                  }
               }
            }
            if(cur2>r+1)
            {
               for(int i=cur2-1;i>r;i--)
               {
                   cc[sw[i]]--;
                   if(sw[i]<=m&&cc[sw[i]]==0)
                   {
                       ch++;
                   }
               }
            }
            cur2=r+1;
            if(ch==0)ans[k]=true;
            else ans[k]=false;
        }
    }
    for(int i=1;i<=q;i++)
    {
        if(ans[i])printf("YES\n");
        else printf("NO\n");
    }
}
