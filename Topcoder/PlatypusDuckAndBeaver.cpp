    //Data Structure includes
    #include<vector>
    #include<stack>
    #include<set>
    #include<map>
    #include<queue>
    #include<deque>
    #include<string>

    //Other Includes
    #include<iostream>
    #include<algorithm>
    #include<cstring>
    #include<cassert>
    #include<cstdlib>
    #include<cstdio>
    #include<cmath>
    using namespace std;

 class PlatypusDuckAndBeaver {
	public:
	int minimumAnimals(int w, int d, int b) {

		int res=d+b;
		int wf = 2*d + 4*b;
		if( w == wf ) 
			return res;
		else{
			res -= (wf-w)/2;
			return res;		
		}	
	}
};
