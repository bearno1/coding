#include<bits/stdc++.h>
//#pragma GCC optimize("O3")
//#pragma GCC target ("sse4")
using namespace std;
#define PB push_back
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
int n,l,r,ch[100005];
bool p;
char c[100005];
int main()
{
    scanf("%d",&n);
    scanf("%s",c+1);
    for(ch[1]=0;ch[1]<2;ch[1]++)
    {
        for(ch[2]=0;ch[2]<2;ch[2]++)
        {
            for(int i=3;i<=n;i++)
            {
                if(ch[i-1]==1)
                {
                    if(c[i-1]=='x')
                    {
                        ch[i]=1-ch[i-2];
                    }
                    else
                    {
                        ch[i]=ch[i-2];
                    }
                }
                else
                {
                    if(c[i-1]=='x')
                    {
                        ch[i]=ch[i-2];
                    }
                    else
                    {
                        ch[i]=1-ch[i-2];
                    }
                }
            }
            if(ch[n]==1)
            {
                if(c[n]=='x')
                {
                    if(ch[1]+ch[n-1]==1)p=true;
                    else p=false;
                }
                else
                {
                    if(ch[1]==ch[n-1])p=true;
                    else p=false;
                }
            }
            else
            {
                if(c[n]=='x')
                {
                    if(ch[1]==ch[n-1])p=true;
                    else p=false;
                }
                else
                {
                    if(ch[1]+ch[n-1]==1)p=true;
                    else p=false;
                }
            }
            if(!p)continue;
            if(ch[1]==1)
            {
                if(c[1]=='x')
                {
                    if(ch[n]+ch[2]==1)p=true;
                    else p=false;
                }
                else
                {
                    if(ch[n]==ch[2])p=true;
                    else p=false;
                }
            }
            else
            {
                if(c[1]=='x')
                {
                    if(ch[n]==ch[2])p=true;
                    else p=false;
                }
                else
                {
                    if(ch[n]+ch[2]==1)p=true;
                    else p=false;
                }
            }
            if(!p)continue;
            for(int i=1;i<=n;i++)
            {
                if(ch[i]==1)printf("S");
                else printf("W");
            }
            return 0;
        }
    }
    printf("-1");
}
