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
int t,n,cur1,cur2;
char a[100005],b[100005],xr;
vector<int>ans;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        xr=0;
        ans.clear();
        scanf("%d",&n);
        cur1=1;
        cur2=n;
        scanf("%s",a+1);
        scanf("%s",b+1);
        for(int i=n;i>0;i--)
        {
            if(xr%2==0)
            {
                if(a[cur1]==b[i])ans.pb(1);
                ans.pb(i);
                xr++;
                cur1++;
            }
            else
            {
                if(a[cur2]!=b[i])ans.pb(1);
                ans.pb(i);
                xr++;
                cur2--;
            }
            //printf("[%d %d]\n",cur1,cur2);
        }
        printf("%d ",ans.size());
        for(int j=0;j<ans.size();j++)printf("%d ",ans[j]);
        printf("\n");
    }
}
