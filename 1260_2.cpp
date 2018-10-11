#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> G[10001];
int C[10001];
int D[10001];

void dfs(int x);
void bfs(int V);

int main()
{
    cin>>N>>M>>V;

    int a, b;
    for(int i=0;i<M;i++)
    {
	cin>>a>>b;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    dfs(V);
    cout<<endl;
    bfs(V);
}

void dfs(int x)
{   
    if(C[x])
	return;
    cout<<x<<' ';
    C[x] = true;
    for(int i=0;i<G[x].size();i++)
    {
	int y;
	y=G[x][i];
	if(!C[y])
	    dfs(y);
    }
}

void bfs(int V)
{
    queue<int> Q;
    Q.push(V);
    cout<<V<<' ';
    D[V] = true;

    while(!Q.empty())
    {
	int x;
	x = Q.front();
	Q.pop();

	for(int i=0;i<G[x].size();i++)
	{
	    int y = G[x][i];
	    if(!D[y])
	    {
		Q.push(y);
		cout<<y<<' ';
		D[y] =true;
	    }
	}
    }
}
