#include <bits/stdc++.h>
#define NMAX 50005
using namespace std;

ifstream fi("sortaret.in"); void Input();
ofstream fo("sortaret.out"); void Output();
int N, M;
vector<int> graph[NMAX];
bool visited[NMAX];
vector<int> topo;

void DFS(int node)
{
    visited[node] = true;
    for(auto y:graph[node])
    {
        if(visited[y] == false)
            DFS(y);
    }
    topo.push_back(node);
}


int main()
{
    Input();
    for(int i = 1; i <= N; ++i)
    {
        if(visited[i] == false)
        {
            DFS(i);
        }
    }
    Output();
}

void Input()
{
    fi>>N>>M;
    int x, y;
    for(int i = 1; i <= M; ++i)
    {
        fi>>x>>y;
        graph[x].push_back(y);
    }
}

void Output()
{
    for(auto i = N-1; i >= 0; --i)
    {
        fo<<topo[i]<<' ';
    }
}#include <bits/stdc++.h>
#define NMAX 50005
using namespace std;

ifstream fi("sortaret.in"); void Input();
ofstream fo("sortaret.out"); void Output();
int N, M;
vector<int> graph[NMAX];
bool visited[NMAX];
vector<int> topo;

void DFS(int node)
{
    visited[node] = true;
    for(auto y:graph[node])
    {
        if(visited[y] == false)
            DFS(y);
    }
    topo.push_back(node);
}


int main()
{
    Input();
    for(int i = 1; i <= N; ++i)
    {
        if(visited[i] == false)
        {
            DFS(i);
        }
    }
    Output();
}

void Input()
{
    fi>>N>>M;
    int x, y;
    for(int i = 1; i <= M; ++i)
    {
        fi>>x>>y;
        graph[x].push_back(y);
    }
}

void Output()
{
    for(auto i = N-1; i >= 0; --i)
    {
        fo<<topo[i]<<' ';
    }
}
