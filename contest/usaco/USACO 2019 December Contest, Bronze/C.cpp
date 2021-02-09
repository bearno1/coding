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

vector<string> ans;
string x[10],y[10],tmp;
int N;
int main()
{
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    ans.push_back("Bessie");
    ans.push_back("Buttercup");
    ans.push_back("Belinda");
    ans.push_back("Beatrice");
    ans.push_back("Bella");
    ans.push_back("Blue");
    ans.push_back("Betsy");
    ans.push_back("Sue");
    sort(ans.begin(),ans.end());

    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> x[i];
        cin >> tmp;
        cin >> tmp;
        cin >> tmp;
        cin >> tmp;
        cin >> y[i];
    }

    do {
        /* code */
        bool ok=true,ok2;
        for(int i=0;i<N;i++)
        {
            ok2=false;
            for(int j=0;j<8;j++)
            {
                if(x[i]==ans[j])
                {
                    if((j>0 && ans[j-1]==y[i]) || (j<7 && ans[j+1]==y[i]))
                    {
                        ok2=true;
                    }
                }
            }
            if(ok2==false)
                ok=false;
        }
        if(ok)
        {
            for(int i=0;i<8;i++)
                cout << ans[i] << '\n';
            return 0;
        }
    } while(next_permutation(ans.begin(),ans.end()));
}
