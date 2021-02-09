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
int t,n,ll,k,x,y;
char c[4000005];
vector<int>v[2][2];
bool a,b;
priority_queue<int>p;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        v[0][0].clear();
        v[0][1].clear();
        v[1][0].clear();
        v[1][1].clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",c+1);
            ll=strlen(c+1);
            //printf("--%d %d\n",c[1]-'0',c[ll]-'0');
            v[c[1]-'0'][c[ll]-'0'].push_back(i);
        }
        x=v[1][0].size();
        y=v[0][1].size();
        if(v[0][0].size()!=0)a=true;
        if(v[1][1].size()!=0)b=true;
        if(a&&b)
        {
            if(x==0&&y==0)
            {
                printf("-1\n");
            }
            else
            {
                while(abs(x-y)>1)
                {
                    if(x>y)
                    {
                        p.push(-v[1][0][x-1]);
                        x--;
                        y++;
                    }
                    else
                    {
                        p.push(-v[0][1][y-1]);
                        y--;
                        x++;
                    }
                }
                printf("%d\n",p.size());
                while(!p.empty())
                {
                    printf("%d ",-p.top());
                    p.pop();
                }
                printf("\n");
            }
        }
        else
        {
            while(abs(x-y)>1)
            {
                if(x>y)
                {
                    p.push(-v[1][0][x-1]);
                    x--;
                    y++;
                }
                else
                {
                    p.push(-v[0][1][y-1]);
                    y--;
                    x++;
                }
            }
            printf("%d\n",p.size());
            while(!p.empty())
            {
                printf("%d ",-p.top());
                p.pop();
            }
            printf("\n");
        }
    }
}
