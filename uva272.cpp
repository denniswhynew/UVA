#include <iostream>
using namespace std;
int main()
{
    char typein;
    bool times=true;
    while(cin.get(typein))
    {
        if(typein=='"')
        {
            if(times)
            {
                cout<<"``";
                times=false;continue;
            }
            if(!times)
            {
                cout<<"''";
                times=true;continue;
            }
        }
        else
            cout<<typein;
    }
}
