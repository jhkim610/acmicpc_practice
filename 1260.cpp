#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N,M,V;

vector<int> c[1001];
int d[1001];
int e[1001];

void dfs(int num);
void bfs(int V);

int main()
{
    cin>>N>>M>>V;

    for(int i=0;i<M;i++)
    {
	int a,b;
	cin>>a>>b;
	c[a].push_back(b);
	c[b].push_back(a);
    }

    for(int i=0;i<1001;i++)
    {
	sort(c[i].begin(),c[i].end());
    }

    dfs(V);
    cout<<endl;
    bfs(V);
    return 0;

}

void dfs(int num)
{
    if(d[num])
	return;

    cout<<num<<' ';
    d[num] = true;

    for(int i=0;i<c[num].size();i++)
    {
	dfs(c[num][i]);
    }

}

void bfs(int V)
{
    queue<int> q;
    q.push(V);
    e[V] = true;

    while(!q.empty())
    {
	int x = q.front();
	q.pop();
	cout<<x<<' ';
	for(int i=0;i<c[x].size();i++)
	{
	    int y = c[x][i];
	    if(!e[y])
	    {
		q.push(y);
		e[y] = true;
	    }	
	}
    }
}
