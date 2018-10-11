#include <iostream>
#include <stack>

using namespace std;



bool grid[101][101];

void mark(int &x, int &y, int d);
void make_curve(int x, int y, int g, int c, stack<int> &stack);
void count_quad();

int main()
{
    int N;
    int x, y, d, g;
    cin>>N;
    for(int i=0;i<N;i++)
    {
	cin>>x>>y>>d>>g;
	stack<int> s;
	s.push(d);
	grid[x][y] =true;
	mark(x,y,d);
	make_curve(x,y,g,1,s);
    }

    count_quad();
    return 0;


}

void mark(int &x, int &y, int d)
{
    if(d==0)
    {
	x = x+1;
    }
    else if(d==1)
    {
	y = y-1;
    }
    else if(d==2)
    {
	x = x-1;
    }
    else if(d==3)
    {

	y = y+1;
    }

    grid[x][y]=true;
}

void make_curve(int x, int y, int g, int c, stack<int> & s)
{
    if(c>g)
	return;

    stack<int> s_next;
    s_next = s;
    int s_size;
    s_size = s.size();


    for(int i=0;i<s_size;i++)
    {
	int d = s.top();
	s.pop();
	d = (d+1)%4;
	s_next.push(d);
	mark(x,y,d);
    }
    
    make_curve(x, y, g, c+1, s_next);
}


void count_quad()
{

    int cnt=0;
    for(int i=0;i<100;i++)
    {
	for(int j=0;j<100;j++)
	{
	    if(grid[i][j] && grid[i][j+1] && grid[i+1][j] && grid[i+1][j+1])
		    cnt++;
	}

    }
    cout<<cnt<<endl;

}
