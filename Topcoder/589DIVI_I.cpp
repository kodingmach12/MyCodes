// The solution to the division 2 problem:
int division2(string S)
{
    // note how this is a shorter c++ version than that in the div2 explanation
    int n = S.length(), m = 0;
    for (char ch : S) {
        m = std::max<int>(m, count(S.begin(), S.end(), ch) );
    }
    return n - m;
}
 
 
bool visited[50];
string compo; //all the letters found in positions in the current component
 
int n;
string S;
// A Depth-first search finds all the positions in the connected component
// Saves all their relevant letters in the compo string.
void dfs(int i)
{
    if (! visited[i]) {
        visited[i] = true;
        compo.push_back(S[i]);
        for (int j=0; j<n; j++) {
            if (S[i] == S[j] || j == n -i - 1) {
                dfs(j);
            }
        }
    }
}
 
 
int getmin(string S)
{
    // prepare the DFS:
    n = S.length();
    this->S = S;
    fill(visited, visited+n, false);
     
    int res = 0;
    for (int i=0; i<S.length(); i++) {
        if (! visited[i]) {
            // Get the letters for i's connected component:
            compo = "";
            dfs(i);
            // Solve the sub-problem (Which we solved in division 2)
            res += division2( compo );
        }
    }
    return res;
}