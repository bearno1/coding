#include "average.h"
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
vector<double>v;
void init()
{
    v.pb(0);
    return;
}

void addMonth(int K)
{
    v.pb(K+v[v.size()-1]);
    return;
}

double maximumAverage(int L, int R)
{
    int k=v.size();
    return (v[k-1]-v[L])/(k-L-1);
}
