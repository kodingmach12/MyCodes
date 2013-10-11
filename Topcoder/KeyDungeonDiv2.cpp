#line 5 "KeyDungeonDiv2.cpp"
#include <string>
#include <vector>
class KeyDungeonDiv2 {
	public:
	int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) {
		int r = keys[0];
    int g = keys[1];
    int w= keys[2];
    int n = doorR.size(),
      count = 0;

    for(int i=0;i < n; i++){
      int temp = 0;
       temp = doorR[i] - r + doorG - g;
       if(w >= temp){
        count++;
       }
    }
    return count;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
