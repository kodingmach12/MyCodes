    #include<string>
    #include<iostream>
    #include<cstring>
    #include<cstdlib>
    #include<cstdio>
    using namespace std;

    // Input macros
    #define MOD                   10000009
    void solve(){
        string a;
        cin>>a;
        int size = a.size();
        unsigned long long res = 1;
        for(int i=0;i<=(size-1)/2; i++)
        {
            if(a[i]==a[size-1-i] && a[i]=='?'){
                res*=26;
            if(res>MOD)
                res%=MOD;
            continue;
            }
            if(a[i]!=a[size-1-i] && a[i]!='?' && a[size-1-i]!='?'){
                res=0;
                break;
            }
        }
		printf("%lld\n",res);
	}
    int main(){
    	int tcase;
		scanf("%d",&tcase);
		while(tcase--)
            solve();
    return 0;
    }
