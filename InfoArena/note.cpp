#include <bits/stdc++.h>
#define NMAX 1030
using namespace std;
ifstream fi("note.in");
ofstream fo("note.out");

int n,m,v;
int tabs[NMAX][105];
int solf[NMAX];
int dp[NMAX][NMAX];

int LevenstheinDistance()
{
    for(int i = 1; i <= n; ++i)
        dp[i][0] = i;
    for(int j = 1; j <= m; ++j)
        dp[0][j] = j;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            dp[i][j] = min(min(dp[i][j-1] + 1, dp[i-1][j] + 1), dp[i-1][j-1] + !tabs[i][solf[j]]);
    return dp[n][m];
}

int main()
{
    fi>>v>>n;
    for(int i = 1; i <= v; ++i)
        for(int j = 1; j <= n; ++j)
        {
            int a;
            fi>>a;
            tabs[j][a] = 1;
        }
    fi>>m;
    for(int i = 1; i <= m; ++i)
        fi>>solf[i];
    fo<<LevenstheinDistance();
}
