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
int t,n,go[30][30],le;
bool p;
char a[1005],b[1005],c[1005];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        p=true;
        memset(go,-1,sizeof(go));
        scanf("%s",a+1);
        scanf("%s",b+1);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",c+1);
            go[c[1]-'a'+1][c[4]-'a'+1]=1;
        }
        if(strlen(a+1)!=strlen(b+1))p=false;
        le=min(strlen(a+1),strlen(b+1));
        for(int i=1;i<30;i++)go[i][i]=1;
        for(int k=1;k<30;k++)
        {
            for(int i=1;i<30;i++)
            {
                for(int j=1;j<30;j++)
                {
                    if(go[i][k]==1&&go[k][j]==1)go[i][j]=1;
                }
            }
        }
        for(int i=1;i<=le;i++)
        {
            if(go[a[i]-'a'+1][b[i]-'a'+1]==-1)p=false;
        }
        if(p)printf("YES\n");
        else printf("NO\n");
    }
}
