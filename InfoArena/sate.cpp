#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f
using namespace std;
ifstream fi("sate.in");
ofstream fo("sate.out");
queue<int> q;
vector<pair<int,int> > ways[30005];
int dist[30005];
int n,m,X,Y;

void lee(int d)
{
    q.push(d);
    dist[d] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto y:ways[x])
        {
            if(dist[y.first] == INF)
            {
                int k = dist[x] - y.second;
                int mk = dist[x] + y.second;
                if(x>y.first) dist[y.first] = k;
                else if(x<y.first) dist[y.first] = mk;
                q.push(y.first);
                if(y.first == Y)
                {
                    return;
                }
            }

        }
    }
}

int main()
{
    int a,b,c;
    fi>>n>>m>>X>>Y;
    for(int i=1;i<=m;++i)
    {
        fi>>a>>b>>c;
        ways[a].push_back({b,c});
        ways[b].push_back({a,c});
    }
    for(int i=1;i<=n;++i)
        dist[i] = INF;
    lee(X);
    fo<<dist[Y];




}
