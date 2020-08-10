#include <iostream>
#include <cstring>
using namespace std;
int number[15],matrix[15][15],pathm[15][15];

int makematrix(int a,int b)
{
    int &num=matrix[a][b];
    if(num!=-1) return num;
    if(a==b) return num=0;
    for(int k=a;k<b;k++)
    {
        int cost=number[a-1]*number[k]*number[b]+makematrix(a,k)+makematrix(k+1,b);
        if(num==-1||cost<num)
        {
            num=cost;
            pathm[a][b]=k;
        }
    }
    return num;
}

void path(int a,int b)
{
    if(a==b)cout<<"A"<<a;
    else
    {
        cout<<"(";
        path(a,pathm[a][b]);
        cout<<" x ";
        path(pathm[a][b]+1,b);
        cout<<")";
    }
}

int main()
{
    int p,t=1;
    while(cin>>p,p)
    {
        for(int i=0;i<p;i++)
        {
            cin>>number[i]>>number[i+1];
        }
        memset(matrix,-1,sizeof matrix);
        makematrix(1,p);
        cout<<"Case "<<t++<<": ";
        path(1,p);
        cout<<endl;
    }
}
