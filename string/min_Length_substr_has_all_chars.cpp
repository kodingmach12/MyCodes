#include<iostream>
#include<cstring>
using namespace std;

// Return Values are : -
// 1 - success
// 0 - Not found
int  minLengthSubStr(char *s,int len,int tlen, int hash[],int& substart,int& subend)
{
    if(len==0)  return 0;
    int count=0,i=0,j=0;
    for(i=0;i<256;i++)
    {
        count+= hash[i];
    }
    if( count > len )    return 0;
    int foundcnt=0,start=0,end=len-1,foundtable[256]={0},current_char=0,currentLength=0,minLength=len;
    bool foundonce=false;

    for(i=0;i<len;i++)
    {
        int current_char=s[i];
        if(!foundonce)
        {
            if( foundtable[current_char] < hash[current_char])
            {
                foundtable[current_char]++;
                foundcnt++;
                end=i;
            }
        }
        else
        {
            if( hash[s[start]] == 0 )
                start++;
            if(hash[s[start]] > 0)
            {
                foundtable[s[start]]--;
                foundcnt--;
                start++;
            }
            if(  foundtable[current_char] < hash[current_char])
            {
                foundtable[current_char]++;
                foundcnt++;
                end=i;
            }
        }
        if( foundcnt == count )
        {
            cout<<"found"<<endl;
            if(!foundonce)      foundonce = true;

            currentLength=end-start+1;
            if(currentLength < minLength )
            {
                substart=start;
                subend=end;
                minLength=currentLength;
            }
        }
    cout<<"start: "<<start<<" end: "<<end<<" current pos : "<<i<<" foundval: "<<foundonce<<endl;
    }
    while( start+count < len )
    {
        current_char=s[start];
        if( hash[current_char] )
        {
            foundtable[current_char]--;
            foundcnt--;
        }
        start++;
        if( foundcnt == count )
        {
            currentLength=end-start+1;
            if(currentLength < minLength )
            {
                substart=start;
                subend=end;
                minLength=currentLength;
            }
        }
        cout<<"start: "<<start<<" end: "<<end<<" current pos : "<<i<<" foundval: "<<foundonce<<endl;
    }
    cout<<" Min Length found is "<<minLength<<endl;
if(foundonce)
    return 1;
return 0;
}
int minLengthWindow(char *s,int slen,int shouldfind[],int tlen, int& substart,int& subfinish)
{
    int hasfound[256]={0}, i=0, j=0, cnt=0, start=0, finish=0, minWindow = slen, current_char=0;
    start  = 0;
    finish = slen;
    for( i=0; i<slen; i++)
    {   current_char = s[i];
        if(!shouldfind[current_char])
            continue;
        hasfound[current_char] += 1;
        if( hasfound[current_char] <= shouldfind[current_char])
            cnt++;
        if(cnt== tlen )
        {
            while( shouldfind[s[j]]==0 || (hasfound[s[j]] > shouldfind[s[j]]) )
            {
                if( hasfound[s[j]] > shouldfind[s[j]] )
                    hasfound[s[j]]--;
                    j++;
            }
            if( minWindow > (i-j+1) )
            {
                minWindow = i-j+1;
                start=j;
                finish=i;
            }
        }
        cout<<" i: "<<i<<" j: "<<j<<"cnt "<<cnt<<" start: "<<start<<" finish "<<finish<<endl;
    }
    substart=start;
    subfinish=finish;
return 1;
}

int main()
{
    char s[100],t[100];
    int shouldfind[256]={0},i,j,slen,tlen;
    int start,end;

    cin>>s;
    cin>>t;

    tlen=strlen(t);
    slen=strlen(s);

    for(i=0;i<tlen;i++)
        shouldfind[ t[i] ] ++;

    int retval;
    //retval=minLengthSubStr(s,slen,tlen,hash,start,end);
    retval=minLengthWindow(s,slen,shouldfind,tlen,start,end);
    cout<<" retval is "<<retval<<endl;
    if(retval)
    {
        cout<<endl<<" substring is : -> ";
        for(i=start;i<=end;i++)
            cout<<s[i];
        cout<<endl;
    }
    else
        cout<<" Not Found "<<endl;

return 0;
}

/*
// Returns false if no valid window is found. Else returns
// true and updates minWindowBegin and minWindowEnd with the
// starting and ending position of the minimum window.
bool minWindow(const char* S, const char *T,
               int &minWindowBegin, int &minWindowEnd) {
  int sLen = strlen(S);
  int tLen = strlen(T);
  int needToFind[256] = {0};

  for (int i = 0; i < tLen; i++)
    needToFind[T[i]]++;

  int hasFound[256] = {0};
  int minWindowLen = INT_MAX;
  int count = 0;
  for (int begin = 0, end = 0; end < sLen; end++) {
    // skip characters not in T
    if (needToFind[S[end]] == 0) continue;
    hasFound[S[end]]++;
    if (hasFound[S[end]] <= needToFind[S[end]])
      count++;

    // if window constraint is satisfied
    if (count == tLen) {
      // advance begin index as far right as possible,
      // stop when advancing breaks window constraint.
      while (needToFind[S[begin]] == 0 ||
            hasFound[S[begin]] > needToFind[S[begin]]) {
        if (hasFound[S[begin]] > needToFind[S[begin]])
          hasFound[S[begin]]--;
        begin++;
      }

      // update minWindow if a minimum length is met
      int windowLen = end - begin + 1;
      if (windowLen < minWindowLen) {
        minWindowBegin = begin;
        minWindowEnd = end;
        minWindowLen = windowLen;
      } // end if
    } // end if
  } // end for

  return (count == tLen) ? true : false;
}
*/
