#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<string>
using namespace std;

void reverse_1(string &str)
{
    string:: iterator it1,it2;
    it1=str.begin();
    it2=str.end()-1;
    while(it1!=it2)
    {
        swap(*it1,*it2);
        it1++;
        it2--;
    }
}

void reverse_2(string &str,string::iterator start, string::iterator end)
{
    while(start<=end){
        swap( *start, *end );
        start++;
        end--;
    }
}

void reverse_words(string &s)
{
    string::iterator start,end,temp;
    start=s.begin();
    end=s.end();
    reverse_2(s, start, end-1);
    temp=start;



}

int main()
{
    string s;
    int len;
    string::iterator start,end;
    cin>>s;
    len=s.size();
    start=s.begin();
    end=s.end();

    cout<<" Input: "<<s<<endl;

    reverse_1(s);
    cout<<" Output: "<<s<<endl;

    reverse_2(s,start,end-1);
    cout<<" Output: "<<s<<endl;

return 0;
}

