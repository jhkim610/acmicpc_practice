#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//N: 0, S: 1

vector<int> wheel[4];
int K;
void rotate(int num, int dir);
void rotate_together(int num, int dir);

int main()
{
    for(int i=0;i<4;i++)
    {
	string temp;
	cin>>temp;
	for(int j=0;j<8;j++)
	{
	    wheel[i].push_back(int(temp[j]-'0'));
	}
    }
    /*
    for(int i=0;i<4;i++)
    {
	for(int j=0;j<8;j++)
	    cout<<wheel[i][j]<<' ';
	cout<<endl;
    }
    */

    cin>>K;
    int num[K];
    int dir[K];
    for(int i=0;i<K;i++)
    {
	//num: wheel number, dir: 1 if clockwise, -1 if counterclockwise
	cin>>num[i]>>dir[i];
    }
    
    for(int i=0;i<K;i++)
	rotate_together(num[i]-1, dir[i]);

    int val=0;
    int exp=1;
    for(int i=0;i<4;i++)
    {
	val += wheel[i][0]*exp;
	exp = exp*2;
    }
    cout<<val<<endl;
    return 0;
}

void rotate(int num, int dir)
{
    if(dir==1)
    {
	int temp = wheel[num][7];
	for(int i=0;i<8;i++)
	{
	    int temp2 = wheel[num][i];
	    wheel[num][i] = temp;
	    temp = temp2;
	}
    }
    else if(dir==-1)
    {
	int temp = wheel[num][0];
	for(int i=7;i>=0;i--)
	{
	    int temp2 = wheel[num][i];
	    wheel[num][i] = temp;
	    temp = temp2;
	}
    }
}

void rotate_together(int num, int dir)
{
    int dirs_mask[3]; // -1 or 0
    int dirs[4];
    if(wheel[0][2]==wheel[1][6])
        dirs_mask[0] = 0;
    else
        dirs_mask[0] = -1;
    
    if(wheel[1][2]==wheel[2][6])
	dirs_mask[1] = 0;
    else
	dirs_mask[1] = -1;

    if(wheel[2][2]==wheel[3][6])
	dirs_mask[2] = 0;
    else
	dirs_mask[2] = -1;

    dirs[num] = dir;

    int left, right;
    left = num-1;
    right = num+1;
    while(true)
    {
	if(left<0)
	    break;
	dirs[left] = dirs[left+1]*dirs_mask[left];  
	left--;
    }

    while(true)
    {
	if(right>3)
	    break;
	dirs[right] = dirs[right-1]*dirs_mask[right-1];
	right++;
    }

    for(int i=0;i<4;i++)
    {
	rotate(i, dirs[i]);
	//cout<<"wheel: "<<i+1<<", dir: "<<dirs[i]<<endl;
    }
}   
