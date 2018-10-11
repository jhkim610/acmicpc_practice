#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v(4);


    for(int i=4;i>0;i--)
    {
	v[4-i] = i;
    }

    do{

	for(int i=0;i<4;i++)
	{
	    cout<<v[i]<<' ';
	}

	cout<<endl;
    }while(next_permutation(v.begin(), v.end()));

    return 0;
}
