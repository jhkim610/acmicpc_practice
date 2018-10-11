#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void choice(vector<int> &S, int idx, int cnt);
vector<int> L;

int main()
{
    while(true)
    {
        int k;
        cin>>k;
        vector<int> S;
        
        while(true)
        {
            if(cin.get()=='\n')
                break;
            int n;
            cin>>n;
            S.push_back(n);
        }
        if(k==0)
            break;
        choice(S,0,0);
        cout<<endl;
    }
    return 0;
}

void choice(vector<int> &S,int idx, int cnt)
{
    if(cnt==6)
    {
        for(int i=0;i<6;i++)
        {
            cout<<L[i]<<' ';
        }
        cout<<endl;
    }
    
    if(S.size()==idx)
        return;
    
    L.push_back(S[idx]);
    choice(S,idx+1,cnt+1);
    L.pop_back();
    choice(S,idx+1,cnt);

}
