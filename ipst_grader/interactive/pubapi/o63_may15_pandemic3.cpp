#include<bits/stdc++.h>
#include "pandelib.h"
//#include "pandelib.cpp"
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define F first
#define S second
#define imx ((int)1e9)
#define pb push_back
#define all(x) ((x).begin(),((x).end())
typedef long long LL;
int n,k,l,n1,r2,r1,cc,m,n4,cc1,cc2,x,y,mmd;
bool results[100000];
vector<int>a[5][100000];
int main()
{
    pandemic_init(n,k,l);
    n4=(n+3)/4;
    if(true)
    {
        // for(int j=0;j<4;j++)
        // {
        //     for(int i=0;i<n4;i++)
        //     {
        //         if(i+(j*n4)>=n4)continue;
        //         a[j][i].pb(i+(j*n4));
        //     }
        // }
        for(int i=0;i<n;i++)a[0][i].pb(i);
        for(int i=0;i<4;i++)pandemic_assign(a[i],results);
        for(int i=5;i<=30;i++)pandemic_assign(a[4],results);
        for(int i=31;i<=36;i++)
        {
            pandemic_assign(a[4],results);
            for(int j=0;j<n4;j++)
            {
                if(results[j])pandemic_answer(a[i-31][j][0]);
            }
        }
        pandemic_answer(0);
    }
}
