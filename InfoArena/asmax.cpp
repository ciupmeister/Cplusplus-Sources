#include <bits/stdc++.h>

#define NMAX 16005
#define INF 0x3f3f3f3f

using namespace std;
ifstream fi("asmax.in"); void Input();
ofstream fo("asmax.out"); void Output();

int N, MAX = -INF;
vector<int> graph[NMAX];
vector<int> dp;
bool visited[NMAX];
int val[NMAX];


void Phil(int x)
{
    visited[x] = true;
    dp[x] = val[x];
    for(auto y : graph[x])
    {
        if(!visited[y])
        {
            Phil(y);
            dp[x] = max(dp[x], dp[y] + dp[x]);
        }
    }
    MAX = max(MAX, dp[x]);
}

int main()
{
    Input();
    dp = vector<int> (N + 1, -INF);
    Phil(1);
    Output();
}

void Input()
{
    fi>>N;
    for(int i = 1; i <= N; ++i)
        fi>>val[i];
    for(int i = 1, x, y; i <= N; ++i) 
    {
        fi >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}
void Output()
{
    fo<<MAX;
}
