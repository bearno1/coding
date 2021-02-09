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
#define inI(x) scanf("%d",&x)
#define inI2(x,y) scanf("%d %d",&x,&y)
#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)
const long long MOD = (long long)(1e9+7);
const long long MMX = (long long)(1e18);
typedef long long LL;
int n,m,p[105],o=1,pos,opo=0;
bool uu[105];
char c[105][55];
vector<int>v;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",c[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(uu[i])continue;
        for(int j=i+1;j<=n;j++)
        {
            if(uu[j])continue;
            bool cc=true;
            for(int k=0;k<m;k++)
            {
                if(c[i][k]!=c[j][m-k-1])cc=false;
            }
            if(cc)
            {
                //printf("%d %d\n",i,j);
                p[i]=o;
                p[j]=o+1;
                uu[i]=true;
                uu[j]=true;
                v.push_back(o);
                o+=2;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(uu[i])continue;
        bool cc=true;
        for(int k=0;k<m;k++)
        {
            if(c[i][k]!=c[i][m-k-1])cc=false;
        }
        if(cc)
        {
            opo=1;
            pos=i;
            break;
        }
    }
    printf("%d\n",(((o-1)/2)*m*2)+(opo*m));
    for(int i=0;i<v.size();i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(p[j]==v[i])for(int k=0;k<m;k++)printf("%c",c[j][k]);
        }
    }
    if(pos!=0)for(int k=0;k<m;k++)printf("%c",c[pos][k]);
    for(int i=v.size()-1;i>-1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(p[j]==v[i]+1)for(int k=0;k<m;k++)printf("%c",c[j][k]);
        }
    }
}
