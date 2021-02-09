#include "party.h"
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
int findUnusualGuest(int N, int M, int Q) {
  vector<int>ak;
  int re=N+M-1;
  for(int i=0;i<N+M;i++)ak.pb(i);
  vector<int> A = ask(ak);
  sort(all(A));
  for(int i=0;i<A.size();i++)if(A[i]!=i)re=min(re,A[i]);
  return 0;
}
