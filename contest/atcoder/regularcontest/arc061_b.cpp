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
int n,x,y,a,b;
LL h,w,col[15];
map<pair<int,int>,int>tri;
map<pair<int,int>,bool>mm;
queue<pair<int,int>>q;
int main()
{
    scanf("%d %d %d",&h,&w,&n);
    col[0]=(h-2)*(w-2);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        mm[{x,y}]=true;
        if(!tri[{x,y}])
        {
            tri[{x,y}]=true;
            q.push({x,y});
        }
        if(!tri[{x-1,y}])
        {
            tri[{x-1,y}]=true;
            q.push({x-1,y});
        }
        if(!tri[{x-2,y}])
        {
            tri[{x-2,y}]=true;
            q.push({x-2,y});
        }
        if(!tri[{x,y-1}])
        {
            tri[{x,y-1}]=true;
            q.push({x,y-1});
        }
        if(!tri[{x-1,y-1}])
        {
            tri[{x-1,y-1}]=true;
            q.push({x-1,y-1});
        }
        if(!tri[{x-2,y-1}])
        {
            tri[{x-2,y-1}]=true;
            q.push({x-2,y-1});
        }
        if(!tri[{x,y-2}])
        {
            tri[{x,y-2}]=true;
            q.push({x,y-2});
        }
        if(!tri[{x-1,y-2}])
        {
            tri[{x-1,y-2}]=true;
            q.push({x-1,y-2});
        }
        if(!tri[{x-2,y-2}])
        {
            tri[{x-2,y-2}]=true;
            q.push({x-2,y-2});
        }
    }
    while(!q.empty())
    {
        a=q.front().F;
        b=q.front().S;
        q.pop();
        if(a<1||b<1||a>h-2||b>w-2)continue;
        //printf("--%d %d\n",a,b);
        col[0]--;
        int cc=0;
        if(mm[{a,b}])cc++;
        if(mm[{a+1,b}])cc++;
        if(mm[{a+2,b}])cc++;
        if(mm[{a,b+1}])cc++;
        if(mm[{a+1,b+1}])cc++;
        if(mm[{a+2,b+1}])cc++;
        if(mm[{a,b+2}])cc++;
        if(mm[{a+1,b+2}])cc++;
        if(mm[{a+2,b+2}])cc++;
        col[cc]++;
    }
    for(int i=0;i<=9;i++)printf("%lld\n",col[i]);
}
