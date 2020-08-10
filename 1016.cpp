#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
int main()
{
    int n,t=0,T[10000],Q[10000],M[10000];

    while(cin>>n,n)
    {
        bool V[10000]={0};
        int Min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>T[i];
            Q[i]=T[i];
            Min=min(Min,T[i]);
        }
        sort(Q,Q+n);
        for(int i=0;i<n;i++)
        {
            M[Q[i]]=i;
        }

        int answer=0;
        for(int i=0;i<n;i++)
        {
            if(V[i])continue;
            int cycle=0,MIN=INT_MAX,sum=0;
            for(int j=i;!V[j];j=M[T[j]])
            {
                V[j]=true;
                sum+=T[j];
                MIN=min(MIN,T[j]);
                cycle++;
            }
            answer+=min(sum+(cycle-2)*MIN,sum+MIN+Min*(cycle+1));
        }
        cout<<"Case "<<++t<<": "<<answer<<endl<<endl;
    }
}
