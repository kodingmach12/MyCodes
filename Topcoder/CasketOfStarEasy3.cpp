struct CasketOfStar 
{ 
    vector<int> weight; 
    int mem[50][50]; 
     
    int rec(int a, int b) 
    { 
        int & res = mem[a][b]; 
        if (res == -1) { 
            res = 0; 
            // Pick c - the element we will remove last: 
            for (int c=a+1; c<b; c++) { 
                // if we remove c last, we can find the score of the sub-vector a..c 
                // and c..b to know the best strategy for the previous elements. 
                res = std::max(res, weight[a]*weight[b] + rec(a,c) + rec(c,b) ); 
            } 
        } 
        return res; 
    } 
     
    int maxEnergy(vector <int> weight) 
    { 
         this->weight = weight; 
         memset(mem,-1,sizeof(mem)); 
         return rec(0, weight.size() - 1); 
    } 
}; 
