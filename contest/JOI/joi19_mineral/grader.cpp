//#include "minerals.cpp"
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#include "minerals.h"
#include<bits/stdc++.h>
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
int ls,tp;
vector<int>a,b;

void find_ans(vector<int>A,vector<int>B)
{
    int si=A.size(),ch,re;
    vector<int>na1,nb1,na2,nb2;
    if(A.size()==1)
    {
        Answer(A[0],B[0]);
    }
    for(int i=1;i<=si/2;i++)
    {
        ch=Query(B[i]);
        nb1.pb(B[i]);
    }
    for(int i=(si/2)+1;i<=si;i++)
    {
        nb2.pb(B[i]);
    }
    for(int i=1;i<=si;i++)
    {
        re=Query(A[i]);
        if(ch!=re)
        {
            na2.pb(A[i]);
        }
        else
        {
            na1.pb(A[i]);
        }
        Query(A[i]);
    }
    for(int i=1;i<=si/2;i++)
    {
        ch=Query(B[i]);
    }
    find_ans(na1,nb1);
    find_ans(na2,nb2);
    return;
}

void Solve(int N)
{
    for(int i=1;i<=2*N;i++)
    {
        tp=Query(i);
        if(tp!=ls)
        {
            a.pb(i);
        }
        else
        {
            b.pb(i);
        }
        ls=tp;
    }
    for(int i=1;i<=2*N;i++)Query(i);
    find_ans(a,b);
    return;
}

constexpr int MAX_N = 43000;
constexpr int MAX_CALLS = 1000000;

namespace {

void WrongAnswer(int code) {
  printf("Wrong Answer [%d]\n", code);
  exit(0);
}

int N;
int counterpart[2 * MAX_N + 1];

int num_queries;
int num_kinds;
int on[2 * MAX_N + 1];
int count[2 * MAX_N + 1];

int num_answers;
int answer[2 * MAX_N + 1];

}  // namespace

int Query(int x) {
  if (!(1 <= x && x <= 2 * N)) {
    WrongAnswer(1);
  }
  if (++num_queries > MAX_CALLS) {
    WrongAnswer(2);
  }
  const int type = std::min(x, counterpart[x]);
  if (on[x]) {
    --on[x];
    --count[type];
    if (count[type] == 0) {
      --num_kinds;
    }
  } else {
    ++on[x];
    ++count[type];
    if (count[type] == 1) {
      ++num_kinds;
    }
  }
  return num_kinds;
}

void Answer(int a, int b) {
  if (++num_answers > N) {
    WrongAnswer(6);
  }
  if (!(1 <= a && a <= 2 * N && 1 <= b && b <= 2 * N)) {
    WrongAnswer(3);
  }
  if (answer[a] != 0) {
    WrongAnswer(4);
  }
  answer[a] = b;
  if (answer[b] != 0) {
    WrongAnswer(4);
  }
  answer[b] = a;
  if (!(counterpart[a] == b && counterpart[b] == a)) {
    WrongAnswer(5);
  }
}

int main() {
  if (scanf("%d", &N) != 1) {
    fprintf(stderr, "Error while reading input\n");
    exit(1);
  }
  for (int i = 1; i <= N; ++i) {
    int x, y;
    if (scanf("%d%d", &x, &y) != 2) {
      fprintf(stderr, "Error while reading input\n");
      exit(1);
    }
    counterpart[x] = y;
    counterpart[y] = x;
  }
  Solve(N);
  if (num_answers != N) {
    WrongAnswer(6);
  }
  printf("Accepted: %d\n", num_queries);
  return 0;
}
