//Given an input string and a dictionary of words,
//segment the input string into a space-separated
//sequence of dictionary words if possible. For
//example, if the input string is "applepie" and
//dictionary contains a standard set of English words,
//then we would return the string "apple pie" as output.
vector<string>  result;
bool segmentString(string Input, Dictionary dict)
{
    if(dict.contains(Input)){
            result.push_back(Input);
            return true;
    }
    int len = Input.length();
    for(int i=1;i<len;i++)
    {
        string prefix = Input.substr(0,i);
        if(dict.contains(prefix)){
                string remaining = Input.substr(i+1,len);
                if(segmentString(remaining))
                {
                    result.push_back(prefix);
                    return true;
                }
        }
    }
    return false;
}
