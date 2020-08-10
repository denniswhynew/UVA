#include <iostream>

using namespace std;

int main()
{
    int times, height, loop;
    cin >> times;
    while(times--)
    {
        cin>>height>>loop;
        while(loop--)
        {
            for(int i = 1; i <= height; i++)
            {
                for(int j = 1; j <= i; j++)
                {
                    cout << i;
                }
                cout << endl;
            }
            for(int i = height-1; i >= 1; i--)
            {
                for(int j = i; j >= 1; j--)
                {
                    cout << i;
                }
                cout << endl;
            }
            if(loop)
                cout << endl;
        }
        if(times)
            cout << endl;
    }
}
