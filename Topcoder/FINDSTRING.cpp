#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
#include <cmath>
#include <list>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class WordFindPuzzle {
 public:
  int solveWordFindPuzzle(vector <string> words, vector <string> board)
  {
   int ans = 0;
   for (int i = 0; i < words.size(); i++)
    ans += perfect(words[i], board);
   return ans;
  }


  bool perfect(string word, vector <string> &board)
  {
   bool hor = false, ver = false;
   for (int i = 0; i < board.size(); i++)
   {
    string s = board[i];
    if (s.find(word) != -1)
    {
     hor = true;
     break;
    }
    reverse(s.begin(), s.end());
    if (s.find(word) != -1)
    {
     hor = true;
     break;
    }
   }
   for (int i = 0; i < board[0].size(); i++)
   {
    string s = "";
    for (int j = 0; j < board.size(); j++)
     s += board[j][i];
    if (s.find(word) != -1)
    {
     ver = true;
     break;
    }
    reverse(s.begin(), s.end());
    if (s.find(word) != -1)
    {
     ver = true;
     break;
    }
   }
   return hor && ver;
  }
};
int main()
{
  WordFindPuzzle A;
  vector<string> words,board;
  string w,b;
  int size;
  cin>>size;
  int i=0;
    for(i=0;i<size;i++)
    {  cin>>w;
      words.push_back(w);
    }

   for(i=0;i<size;i++)
    {  cin>>b;
      board.push_back(w);
    }

  if( A.solveWordFindPuzzle(words,board)==true)
    cout<<"Found"<<endl;
  return 0;
}
