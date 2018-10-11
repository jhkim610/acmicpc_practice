#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;


vector<int> D;
vector<int> S;
void real_dwarf(int idx, int cnt, int height);

int main()
{
    for(int i=0;i<9;i++)
    {
	int n;
	cin>>n;
	D.push_back(n);
    }
    
    real_dwarf(0,0,100);

}

void real_dwarf(int idx, int cnt, int height)
{
    //cout<<idx<<' '<<cnt<<' '<<height<<endl;
    if(cnt==7)
    {
	if(height==0)
	{
	    sort(S.begin(), S.end());
	    for(int i=0;i<7;i++)
	    {
		cout<<S[i]<<endl;
	    }
	}
	return;
    }

    if(idx==9)
	return;

    S.push_back(D[idx]);
    real_dwarf(idx+1,cnt+1,height-D[idx]);
    S.pop_back();
    real_dwarf(idx+1,cnt,height);

}
