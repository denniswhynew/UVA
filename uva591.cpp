#include <iostream>

using namespace std;
int main()
{
    int t=0;
    while(true)
    {
        ++t;
        int num,ans=0;
        cin>>num;
        if(num == 0)
            return 0;
        else
        {
            int enter[num],avr=0;
            for(int i=0;i<num;i++)
            {
                cin>>enter[i];
                avr+=enter[i];
            }
            avr/=num;
            for(int i=0;i<num;i++)
            {
                if(enter[i]>avr)
                        ans+=(enter[i]-avr);
            }
        }
        cout<<"Set #"<<t<<endl<<"The minimum number of moves is "<<ans<<"."<<endl<<endl;
    }
}
