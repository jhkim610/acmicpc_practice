#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int E, S, M;

void year(int E, int S, int M);

int main()
{
    cin>>E>>S>>M;

    year(E,S,M);

    return 0;

}

void year(int E, int S, int M)
{
    int year=0;
    while(true)
    {
	int e, s, m;
	year++;
	e = year%15;
	s = year%28;
	m = year%19;
	
	if(e==0)
	    e = 15;
	if(s==0)
	    s = 28;
	if(m==0)
	    m = 19;

	// cout<<e<<' '<<s<<' '<<m<<' '<<endl;
	if((E==e) and (S==s) and (M==m))
	    break;
	    

    }

    cout<<year<<endl;

}
