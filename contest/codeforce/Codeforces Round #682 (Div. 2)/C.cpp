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
int n,m,cal[105][105],t;
bitset<105>ch[105];
int main()
{
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        for(int i=1;i<105;i++)
        {
            for(int j=1;j<105;j++)
            {
                ch[i][j]=false,cal[i][j]=0;
            }
        }
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&cal[i][j]);
            }
        }
        bool p=false,aa=false;
        int k=100;
        while(!p)
        {
            if(k==0)aa=true;
            p=true,k=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(ch[i][j])continue;
                    if(cal[i][j]==cal[i+1][j]||cal[i][j]==cal[i][j+1]||cal[i][j]==cal[i-1][j]||cal[i][j]==cal[i][j-1])
                    {
                        p=false;
                        if(!(cal[i][j]+1==cal[i+1][j]||cal[i][j]+1==cal[i][j+1]||cal[i][j]+1==cal[i-1][j]||cal[i][j]+1==cal[i][j-1]))
                        {
                            k++;
                            cal[i][j]++;
                            ch[i][j]=true;
                        }
                        if(aa)
                        {
                            k++;
                            cal[i][j]++;
                            ch[i][j]=true;
                            aa=false;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                printf("%d ",cal[i][j]);
            }
            printf("\n");
        }
    }
}
