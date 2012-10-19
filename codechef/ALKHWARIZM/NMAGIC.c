	#include<stdio.h>
	#include<string.h>
	#include<math.h>
	#include<assert.h>
	#include<stdbool.h>

  // Input macros
    #define s(n)                  scanf("%d",&n)
    #define sc(n)                 scanf("%c",&n)
    #define sl(n)                 scanf("%lld",&n)
    #define sf(n)                 scanf("%lf",&n)
    #define ss(n)                 scanf("%s",n)

    // Useful constants
    #define INF                   (int)1e9
    #define EPS                   1e-9

    // Useful hardware instructions
    #define bitcount              __builtin_popcount
    #define gcd                   __gcd


    // Useful container manipulation / traversal macros
    #define forall(i,a,b)         for(int i=a;i<b;i++)
	#define w(a,b) 				  while(a<b)

	// print macros
	#define p(n) 				  printf("%d",n)
	#define pl(n)				  printf("%d\n",n)
	#define ps(n)				  printf("%s",n)
	#define psl(n) 				  printf("%s\n",n)


	void solver()
	{
		int len=0;
		char str[102],out[102];
		scanf("%s",str);
        len = strlen(str);
        int i=len-1;
        bool found4 = false;
        for( ;i>=0;i--){
            if(str[i]=='4'){
                found4 = true;
                 str[i]='7';
                 break;
            }
            else
                str[i]='4';
        }
        if(!found4)
            printf("4");
        printf("%s\n",str);
	}


	int main()
	{
		int tcases=0;
		scanf("%d",&tcases);
		//assert(tcases>0 && tcases<=1000);
		while(tcases--)
			solver();
	return 0;
	}
