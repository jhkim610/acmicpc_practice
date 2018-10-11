#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int k=0;
vector<int> arr;

void prev_perm(vector<int> &arr);

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
	int n;
	cin>>n;
	arr.push_back(n);
    }

	prev_perm(arr);

}

void prev_perm(vector<int> &arr)
{
    int front = arr.size() -1;

    while(true)
    {
	if(arr[front-1]>arr[front])
	{
	    front--;
	    break;
	}
	
	front--;
	if(front<=0)
	{
	    cout<<"-1"<<endl;
	    k = -1;
	    return;
	}
    }

    int rear = front+1;

    while(true)
    {
	if(rear==arr.size()-1)
	    break;
	else if((arr[rear]<arr[rear+1]) and(arr[rear+1]<arr[front]))
	{
	    rear++;
	}
	else
	    break;

    }

    swap(arr[front], arr[rear]);
    sort(arr.begin()+front+1, arr.end(), compare);
    for(int i=0;i<arr.size();i++)
	cout<<arr[i]<<' ';
    cout<<endl;
    return;
}
