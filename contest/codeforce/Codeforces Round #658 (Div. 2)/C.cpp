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
int t,n;
char a[100005],b[100005],tp[100005];
vector<int>ans;
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        ans.clear();
        scanf("%d",&n);
        scanf("%s",a+1);
        scanf("%s",b+1);
        for(int i=n;i>0;i--)
        {
            if(a[1]==b[i])ans.pb(1);
            ans.pb(i);
            for(int j=1;j<=i;j++)tp[j]=a[j];
            for(int j=1;j<=i;j++)
            {
                if(tp[j]=='0')a[i-j+1]='1';
                else a[i-j+1]='0';
            }
        }
        printf("%d ",ans.size());
        for(int j=0;j<ans.size();j++)printf("%d ",ans[j]);
        printf("\n");
    }
}
