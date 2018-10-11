#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A;
vector<int> O;

int operation(int n1, int n2, int opt);
int calculation();
void minmax();


int main()
{
    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
	int A_;
	cin>>A_;
	A.push_back(A_);
    }

    for(int i=0;i<4;i++)
    {
	int O_;
	cin>>O_;
	for(int j=0;j<O_;j++)
	{
	    O.push_back(i);
	}
    }

    minmax();

    return 0;

}

int operation(int n1, int n2, int opt)
{
    switch(opt)
    {
	case 0:
	    return n1+n2;
	case 1:
	    return n1-n2;
	case 2:
	    return n1*n2;
	case 3:
	    return n1/n2;
    }
}

int calculation()
{
    int x=0;
    for(int i=0;i<O.size()+1;i++)
    {
	if(i==0)
	{
	    x = A[0];
	}
	else
	{
	    x = operation(x,A[i],O[i-1]);
	}
    }
    return x;
}


void minmax()
{
    vector<int> results;
    do{
	int n = calculation();
	
	results.push_back(n);


    }while(next_permutation(O.begin(),O.end()));

    int min, max;
    sort(results.begin(),results.end());
    min = results.front();
    max = results.back();

    cout<<max<<endl<<min;
}
