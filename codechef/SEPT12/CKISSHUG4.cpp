    #include<iostream>
    #include<cstdlib>
    #include<cstdio>
    #include<cmath>
    using namespace std;
	#define MOD 	1000000007

    /*Main code begins now */
    unsigned long long  power(int x, unsigned int y)
    {
    	unsigned long long  temp,res;
    	if( y == 0)	return 1;
	      temp = power(x, y/2);
	      temp = temp%MOD;
	      res = (temp*temp)%MOD;
	    if (y%2 == 0)	return res;
	    else	return (x*res)%MOD;
	}
    void solve(){
    	unsigned int N;
		scanf("%d",&N);
		N--;
		unsigned long long   res = 0,tmp=0;
		tmp = power(2,N/2);
		res = ((tmp-1)*4+2)%MOD;
		if(N%2){
			tmp = power(2,(N+1)/2);
			res = (res+tmp)%MOD;
		}
		printf("%lld\n",res); 
	} 
    int main()
    {
    	int tcase;
		scanf("%d",&tcase);
		while(tcase--)
            solve();
        
    return 0;
    }
