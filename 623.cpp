#include <iostream>
#define MAX 1001
#define length 3000
using namespace std;
int str[MAX][length];
void factorial()
{
    str[0][0]=1;
    str[1][0]=1;
   for(int i=2;i<MAX;i++)
   {
       for(int j=0;j<length;j++)
       {
           str[i][j]+=str[i-1][j]*i;
           if(str[i][j]>9)
           {
               str[i][j+1]=str[i][j]/10;
               str[i][j]=str[i][j]%10;
           }
       }
   }
}
int main()
{
    factorial();
    int n;

    while(cin>>n)
    {
        cout<<n<<"!"<<endl;
        int i;
        for(i=length-1;i>=0;i--)
        {
            if(n==0)
            {
                i=0;
                break;
            }
            if(str[n][i]!=0)
                break;
        }

        for(int j=i;j>=0;j--)
        {
            cout<<str[n][j];
        }
        cout<<endl;

    }

    return 0;
}
