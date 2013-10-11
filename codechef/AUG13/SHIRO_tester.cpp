#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define IN(A, B, C) assert( B <= A && A <= C)

//typedef int LL;
//typedef __int64 LL;

int a[101], p[101];
double prob[2][20004];

int main()
{
	int T, i, j;
	int n;
	int maxL, nmaxL;
	int OFFSET;
	double pp, ans;
	int u, v;

	scanf("%d", &T);
	IN(T, 1, 100);

	while(T--)
	{
		scanf("%d", &n);
		IN(n, 1, 100);

		FORAB(i, 1, n)
		{
			scanf("%d", &a[i]);
			IN(a[i], 1, 100);
		}

		FORAB(i, 1, n)
		{
			scanf("%d", &p[i]);
			IN(p[i], 0, 100);
		}

		OFFSET = 10000;
		prob[0][OFFSET] = 1;

		u = 0;
		v = 1;

		//Easy DP. probability(i, j) = p*probability(i - 1, j - a[i]) + (1 - p)*probability(i - 1, j + a[i])
		maxL = 0;
		FORAB(i, 1, n)
		{
			nmaxL = maxL + a[i];
			pp = p[i]/100.;

			FORAB(j, -nmaxL, nmaxL)
			{
				prob[v][j + OFFSET] = 0;

				if(-maxL <= j + a[i] && j + a[i] <= maxL) 
					prob[v][j + OFFSET] += (1. - pp)*prob[u][j + a[i] + OFFSET];

				if(-maxL <= j - a[i] && j - a[i] <= maxL) 
					prob[v][j + OFFSET] += pp*prob[u][j - a[i] + OFFSET];
			}

			maxL = nmaxL;
			u = 1 ^ u;
			v = 1 ^ v;
		}

		ans = 0;
		FORAB(i, 0, maxL)
			ans += prob[u][i + OFFSET];

		printf("%.10lf\n", ans);
	}

	return 0;
}
