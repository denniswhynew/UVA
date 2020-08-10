#include <iostream>
#define MAX 5001
#define length 3000
using namespace std;
int fib[MAX][length];
int main()
{
    fib[0][0]=0;
    fib[1][0]=1;
    for(int i=2;i<MAX;i++)
    {
        for(int j=0;j<length;j++)
        {
            fib[i][j]+=fib[i-1][j]+fib[i-2][j];
            if(fib[i][j]>9)
            {
                fib[i][j+1]=fib[i][j]/10;
                fib[i][j]=fib[i][j]%10;
            }
        }
    }
    int n;
    while(cin>>n)
    {
        cout<<"The Fibonacci number for "<<n<<" is ";
        int i;
        for(i=length-1;i>=0;i--)
        {
            if(n==0)
            {
                i=0;
                break;
            }
            if(fib[n][i]!=0)
                break;
        }

        for(int j=i;j>=0;j--)
        {
            cout<<fib[n][j];
        }
        cout<<endl;
    }
    return 0;
}
