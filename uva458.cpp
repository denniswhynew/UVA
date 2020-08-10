#include <iostream>
using namespace std;
int main()
{
    char ch;
    while(cin.get(ch))
    {
        if(ch=='\n')
            cout<<ch;
        else
            cout<<char(ch-7);
    }
}
