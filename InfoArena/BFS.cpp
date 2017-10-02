#include <fstream>
#include <vector>
#include <queue>

#define NMAX 100005
#define INF 0x3f3f3f3f

using namespace std;

ifstream fi("bfs.in");
ofstream fo("bfs.out");

queue<int> que;
vector<int> adjacent[NMAX];

int dist[NMAX];
int n,m,s;

void bfs(int d)
{
    int x;
    que.push(d);
    dist[d] = 0;
    while(!que.empty())
    {
        x = que.front();
        que.pop();
        for(auto y=0; y<adjacent[x].size(); ++y)
        {
            if(dist[adjacent[x][y]]> dist[x]+1)
            {
                que.push(adjacent[x][y]);
                dist[adjacent[x][y]] = dist[x]+1;
            }
        }
    }
}


int main()
{
    fi>>n>>m>>s;
    for(int i=1;i<=m;++i)
    {
        int a,b;
        fi>>a>>b;
        adjacent[a].push_back(b);
    }
    for(int i=0; i<=n; ++i)
        dist[i] = INF;

    bfs(s);

    for(int i=1; i<=n; ++i)
    {
        if(dist[i] == INF) fo<<-1<<" ";
        else fo<<dist[i]<<" ";
    }
}
