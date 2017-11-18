#include <bits/stdc++.h>
#define NMAX 1030
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int x[NMAX], y[NMAX];
int c[NMAX][NMAX];
int n, m;

void TraceBack(int i, int j)
{
    if(i == 0 || j == 0)
        return;
    else if(x[i] == y[j])
    {
        TraceBack(i-1, j-1);
        fo<<x[i]<<" ";
    }
    else if(c[i][j-1] > c[i-1][j])
        TraceBack(i, j-1);
    else
        TraceBack(i-1, j);
}

int LCS()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(x[i] == y[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i][j-1], c[i-1][j]);
        }
    }
    return c[n][m];
}

int main()
{
    fi>>n>>m;
    for(int i = 1; i <= n; ++i)
        fi>>x[i];
    for(int i = 1; i <= m; ++i)
        fi>>y[i];

    fo<<LCS()<<"\n";
    TraceBack(n,m);
}
