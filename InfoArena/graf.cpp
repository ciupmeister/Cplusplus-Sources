#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>


#define INF 0x3f3f3f3f
#define NMAX 7505
using namespace std;
ifstream fi("graf.in"); void input();
ofstream fo("graf.out"); void output();

int N,M,X,Y;
int dist[NMAX];
int viz[NMAX];
int reviz[NMAX];
queue<int> q;
vector<int> solutions;
vector<int> graph[NMAX];
vector<int> distances[NMAX];



int main()
{
    input();
    dist[X] = 1;
    q.push(X);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto y:graph[x])
        {
            if(!viz[y] && dist[y]>dist[x]+1)
            {
                viz[y] = 1;
                dist[y] = dist[x]+1;
                q.push(y);
            }
        }
    }
    solutions.push_back(Y);

    q.push(Y);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto y:graph[x])
        {
            if(dist[y] == dist[x]-1 && !reviz[y])
            {
                reviz[y] = 1;
                distances[dist[y]].push_back(y);
                q.push(y);
            }
        }
    }
    for(int i=1; i<=dist[Y]; ++i)
    {
        if(distances[i].size() == 1)
            solutions.push_back(distances[i][0]);
    }
    output();
}

void input()
{
    fi>>N>>M>>X>>Y;
    int a,b;
    for(int i=1; i<=M; ++i)
    {
        fi>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=N; ++i)
    {
        dist[i] = INF;
    }
}

void output()
{
    fo<<solutions.size()<<'\n';
    sort(solutions.begin(),solutions.end());
    for(auto y:solutions)
        fo<<y<<' ';
}
