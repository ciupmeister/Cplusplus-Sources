#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f
#define NMAX 50005
using namespace std;

ifstream fi("dijkstra.in");
void input();
ofstream fo("dijkstra.out");

struct nodeData
{
    int node, cost;
    bool operator <(nodeData const &other) const {return cost>other.cost;}

    nodeData(int aNode, int aCost)
    {
        node = aNode;
        cost = aCost;
    }
};


int dist[NMAX];
vector<nodeData> graph[NMAX];

priority_queue<nodeData> q;
int N, M;

void Dijkstra(int beg)
{
    dist[beg] = 0;
    q.push(nodeData(beg,0));

    while(!q.empty())
    {
        int cost = q.top().cost;
        int x = q.top().node;
        q.pop();
        if(cost != dist[x]) continue;
        for(auto y:graph[x])
        {
            if(cost + y.cost < dist[y.node])
            {
                dist[y.node] = cost + y.cost;
                q.push(nodeData(y.node, dist[y.node]));
            }
        }
    }
}

int main()
{
    input();
    Dijkstra(1);

    for(int i=2; i<=N; ++i)
    {
        if(dist[i] != INF)
            fo<<dist[i]<<' ';
        else fo<<0<<' ';
    }
}


void input()
{
    fi>>N>>M;
    int a,b,c;
    for(; M; --M)
    {
        fi>>a>>b>>c;
        graph[a].push_back(nodeData(b,c));
    }
    for(int i = 1; i<=N; ++i) dist[i] = INF;
}
