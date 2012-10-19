#include<iostream>
#define pair< int,int > point
void closest_Pair(vector< point> P,int& p1,int& p2)
{
    int N=P.size(),minDist=INT_MAX;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            if(i!=j){
                int xd=P[i].first-P[j].first;
                int yd=P[i].second-P[j].second;
                int dist=sqrt(xd*xd + yd*yd);
                if(dist<minDist){
                    minDist=dist;
                    p1=i;
                    p2=j;
                }
            }
        }
}
bool Compare(const pair<int,int> p1, const pair<int,int> p2)
{
    if(p1.first < p2.first)     return true;
    if(p1.first == p2.first && p1.second < p2.second) return true;
    return false;
}
// Line sweep Algorithm Implementation
void LineSweep(vector<point> P, int& p1, int& p2)
{
    sort(P.begin(),P.end(),Compare);
/* Algo
1- sort all points a/t their x-coordinates
2- suppose n-1 points have been processed and minimum distance found till now is h
   Now we need to consider only those point whose x-cordinate lies in this range
   maintain a set of active points ordered a/t their y-cordinates
   consider only those points whose y-cordinate lies in the range yn+h & yn-h.
*/
}
