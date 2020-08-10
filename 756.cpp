#include <iostream>
using namespace std;
int main()
{
    int tc=1, p, e, i, d;
    while (cin>>p>>e>>i>>d)
    {
        if(p==-1&&e==-1&&i==-1&&d==-1)
            return 0;
        d=(p*5544+e*14421+i*1288-d+21251)%21252+1;
        cout <<"Case "<<tc++<<": the next triple peak occurs in "<<d<<" days.\n";
    }
}
