#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int N,M,T;
int surface[1005][1005];
bool visited[1005][1005];
int flooded;
queue< pair<int,int> > que;

bool Check(int i,int j)  {return (i>0 && i<=N && j>0 && j<=M); }

int diri[] ={-1, 0, 1, 0};
int dirj[] ={ 0, 1, 0,-1};
int ii,jj,id,jd,d;
void input();
void output();
void phil(int i,int j);

int main()
{
    input();

    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=M;++j)
        {
            if(surface[i][j]==0 && visited[i][j]==0)
            {
                visited[i][j]=1;
                phil(i,j);
            }
        }
    }


    output();

}
void phil(int i,int j)
{
    que.push({i,j});

    while(!que.empty())
    {
        ii =que.front().first;
        jj = que.front().second;
        que.pop();
        for(d=0;d<4;++d)
        {
            id = ii+diri[d];
            jd = jj+dirj[d];
            if(Check(id,jd))
            {
                if(visited[id][jd]==0 && surface[id][jd]<T && surface[id][jd] != 0)
                {
                    flooded++;
                    visited[id][jd] = 1;
                    que.push({id,jd});
                }
            }

        }
    }
}


void input()
{
    ifstream fi("tsunami.in");
    fi>>N>>M>>T;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            fi>>surface[i][j];
        }
    }
    fi.close();
}
void output()
{
    ofstream fo("tsunami.out");
    fo<<flooded;
    fo.close();
}



