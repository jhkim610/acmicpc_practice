#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int next_perm(vector<int> &arr);

int main()
{
    int N;
    vector<int> arr;

    cin>>N;
    for(int i=0;i<N;i++)
    {
	int n;
	cin>>n;
	arr.push_back(n);
    }

    next_perm(arr);
    return 0;
}

int next_perm(vector<int> &arr)
{
    int front;
    front = arr.size() -1;

    while(true)
    {
	if(front <= 0)
	{
	    int i = -1;
	    cout<<i;
	    return -1;
	}
	if(arr[front-1]<arr[front])
	{
	    front--;
	    break;
	}
	front--;

    }

    int rear;
    rear = front+1;

    while(true)
    {
	if(rear>=arr.size()-1)
	{
	    rear = arr.size()-1;
	    break;
	}
	if((arr[rear] > arr[rear+1]) and (arr[rear+1]>arr[front]))
	    rear++;
	else
	    break;

    }
    
    // cout<<"swap "<<arr[front]<<' '<<arr[rear]<<endl;
    swap(arr[front], arr[rear]);

    sort(arr.begin()+front+1, arr.end());

    for(int i=0;i<arr.size();i++)
	cout<<arr[i]<<' ';

    return 0;
}
