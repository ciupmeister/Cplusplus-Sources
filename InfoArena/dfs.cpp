#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fi("dfs.in");
ofstream fo("dfs.out");
int n,m;
int finalResult;

vector<int> adjacentList[100005];
bool visited[100005];

void input()
{
    int a,b;
    fi>>n>>m;
    for(int i=1; i<=m; ++i)
    {
        fi>>a>>b;
        adjacentList[a].push_back(b);
        adjacentList[b].push_back(a);
    }
}
void output()
{
    fo<<finalResult;
}
void callDFS(int x)
{
    visited[x] = true;
    for(auto j=0; j<adjacentList[x].size(); ++j)
    {
        if(!visited[adjacentList[x][j]])
            callDFS(adjacentList[x][j]);
        cout<<j;
    }
}

int main()
{
    input();
    for(int i=1; i<=n; ++i)
    {
        if(!visited[i])
        {
            ++finalResult;
            callDFS(i);
        }
    }
    output();
}
