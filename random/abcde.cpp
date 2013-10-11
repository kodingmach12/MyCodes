#include<iostream>
#include<string>

using namespace std;

int main(){
int n,cnt=0;
cin>>n;
unsigned long long int j = 10000,i,res = 0;
for( ; j < 100000; j++ ){
i = j;
int e = i%10;
	i/=10;
int d = i%10;
	i/=10;
int c = i%10;
	i/=10;
int b = i%10;
	i/=10;
int a = i%10;
	i/=10;

if( a<b && b<c && c>d && d>e  ){
	if(n == c){
		cout <<j<<endl;
		cnt++;
	}
	res++;
}

}
cout << res << endl;
cout << cnt << endl;
return 0;
}

