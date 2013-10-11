
    //Other Includes
    #include<iostream>
    #include<algorithm>
    #include<cstring>
    #include<cassert>
    #include<cstdlib>
    #include<cstdio>
    #include<cmath>
    using namespace std;

    #define   MOD                 100000007
    typedef long long LL;

	unsigned int v[100000001];
	unsigned int index = 4;
    unsigned int fib(LL  num)
	{
	    if(num<=3)
            return num;
        if(num<index)
            return v[num];
        else if( num <= 100000000)
        {
            for( ; index<=num; index++){
                v[index]= v[index-1]+v[index-2];
                v[index] %= MOD;
            }
            return v[num];
        }
        else
        {
            unsigned int t1=v[99999999],t2=v[100000000],res=0,ind=100000001;
            for( ; ind<=num; ind++  ){
                res = ( t1 + t2 )%MOD;
                t1 = t2;
                t2 = res;
            }
            return res;
        }
	}
    void solve(){
		LL N=0;
		LL res = 0;
		scanf("%d",&N);
        for(LL i=1L; i<N; i++ ){
            res += fib(i)*(fib(N+1-i)+fib(N+2-i));
            if(res>MOD)  res = res%MOD;
        }
        printf("%lld\n",res);
	}
    int main()
    {
    	int tcase;
		scanf("%d",&tcase);
		v[0]=1;
		v[1]=1;
		v[2]=2;
		v[3]=3;
		while(tcase--)
            solve();

    return 0;
    }
