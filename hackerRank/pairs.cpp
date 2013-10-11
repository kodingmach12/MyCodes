#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

void solver(){
    LL N,K,e,res = 0;
    scanf("%lld%lld",&N,&K);
    vector< LL > v;
    for(LL i=0; i < N; i++){
      scanf("%lld",&e);
      v.push_back(e);
    }
    sort(v.begin(),v.end());
    LL j=0;
    for(LL i=1; i < N; i++){
      if(v[i] - v[j] == K) { j++; res++; }
    }
    printf("%lld\n",res);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    solver();
    return 0;
}
