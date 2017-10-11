#include <fstream>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f
#define NMAX 36005


std::ifstream fi("catun.in");
std::ofstream fo("catun.out");
void input();
void output();

struct edge
{
    long long node, cost;
    bool operator <(const edge other) const {return cost>other.cost;}
    edge(long long aNode,long long aCost)
    {
        node = aNode;
        cost = aCost;
    }
};

long long N, M, K;
long long dist[NMAX], parent[NMAX],forts[NMAX];
std::queue<long long> q;
std::vector<edge> graph[NMAX];

void doADijkstraFlip()
{
    while(!q.empty())
    {
        long long x = q.front();
        q.pop();
        for(auto y:graph[x])
        {
            if(dist[y.node]> dist[x] + y.cost)
            {
                dist[y.node] = dist[x] + y.cost;
                parent[y.node] = parent[x];
                q.push(y.node);
            }
            else if(dist[y.node] == dist[x] + y.cost)
            {
                parent[y.node] = std::min(parent[y.node], parent[x]);
                if(parent[y.node] == parent[x]) q.push(y.node);
            }
        }
    }
}




int main()
{
    input();
    doADijkstraFlip();
    output();
}
void output()
{
    for(int i=1; i<=N; ++i)
    {
        if(dist[i] == 0 || dist[i] == INF)
            fo<<0<<" ";
        else
            fo<<parent[i]<<" ";
    }
}
void input()
{
    long long a,b,c;
    fi>>N>>M>>K;
    for(int i=1; i<=N; ++i)
    {
        dist[i] = INF;
    }
    for(int i=1; i<=K; ++i)
    {
        fi>>a;
        dist[a] = 0;
        parent[a] = a;
        q.push(a);
    }
    for(int i=1; i<=M; ++i)
    {
        fi>>a>>b>>c;
        graph[a].push_back(edge(b,c));
        graph[b].push_back(edge(a,c));
    }

}
