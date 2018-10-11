#include <iostream>
#include <vector>

using namespace std;

int N, M;

int arr[8][8];

int max_num=0;

void build_wall(int x, int y, int num);
void cnt_0();
void disease(int x, int y, int arr2[][8]);

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
	for(int j=0;j<M;j++)
	{
	    int k;
	    cin>>k;
	    arr[i][j] = k;
	}
    }

    build_wall(0,0,3);
    cout<<max_num;

    return 0;
}


void build_wall(int x, int y, int num)
{

    if(num==0)
    {
	cnt_0();
	return;
    }
    for(int i=y;i<N;i++)
    {
	if(i!=y)
	    x=0;
	for(int j=x;j<M;j++)
	{
	    if(arr[i][j]==0)
	    {
		//if(i==0 and j==5 and num==3)
		//    cout<<"v"<<endl;
		arr[i][j]=1;
		build_wall(j,i, num-1);
		arr[i][j]=0;
	    }
	}
    }
}

void cnt_0()
{
    int cnt=0;

    int arr2[8][8];
    for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	    arr2[i][j] = arr[i][j];

    for(int i=0;i<N;i++)
    {
	for(int j=0;j<M;j++)
	{
	    disease(j,i,arr2);
	}
    }
    for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	    if(arr2[i][j]==0)
		cnt = cnt+1;
    /*
    if(cnt==3)
    {
	cout<<N<<' '<<M<<endl;
	for(int i=0;i<N;i++)
	{
	    for(int j=0;j<M;j++)
	    {
		cout<<arr2[i][j]<<' ';
	    }
	    cout<<endl;
	}
    }*/

    if(cnt>max_num)
	max_num=cnt;
}

void disease(int x, int y, int arr2[][8])
{
    if(arr2[y][x]==2)
    {
	int up, down, left, right;
	up = y-1;
	down = y+1;
	left = x -1;
	right = x+1;
	if(up>=0)
	{
	    if(arr2[up][x] == 0)
	    {
		arr2[up][x] = 2;
		disease(x, up, arr2);
	    }
	}
	if(down<N)
	{
	    if(arr2[down][x] ==0)
	    {
		arr2[down][x] =2;
		disease(x, down, arr2);
	    }

	}

	if(left>=0)
	{
	    if(arr2[y][left]==0)
	    {
		arr2[y][left]=2;
		disease(left,y, arr2);
	    }
	}

	if(right<M)
	{
	    if(arr2[y][right]==0)
	    {
		arr2[y][right]=2;
		disease(right,y, arr2);
	    }

	}
    }
}
