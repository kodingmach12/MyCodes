string wordBreak(string input){
    unsigned long long inLen = input.length();
    assert( 0 != inLen);

    if(dict.contains(input)){
        return input;
    }
    for(int i=1;i < inLen; i++){
        string prefix = input.substr(0,i);
        if(dict.contains(prefix)){
            string brokenSuffix = wordBreak(input.substr(i+1,inLen-i-1));
            if( 0 !=  brokenSuffix.length()){
                return prefix + " " + brokenSuffix;
            }
        }
    }
    return "";
}

     i  l  i  k  e  s  a  m  s  u  n  g
i
l
i
k
e
s
a
m
s
u
n
g

