#include <iostream>
using namespace std;
bool test(float pointx,float pointy,float x1,float y1,float x2,float y2)
{
    bool testa=false,testb=false;
    if(x1<pointx<x2)
        testa=true;
    if(y2<pointy<y1)
        testb=true;
    if(testa==true&&testb==true)
        return true;
    else
        return false;
}
int main()
{
    char gar;
    float squar[10][4];
    int k=0,m=0;
    while(1)
    {
        cin>>gar;
        if(gar=='r')
        {
            for(int i=0;i<4;i++)
                cin>>squar[m][i];
            m++;k++;
        }
        else
            break;
    }
    float pointx,pointy,num=9999.9;
    int points=1;
    bool notin=true;
    while(1)
    {
        cin>>pointx>>pointy;
        if(pointx==num&&pointy==num)
        {
            return 0;
        }
        for(int x=0;x<k;x++)
        {
            cout<<test(pointx,pointy,squar[x][0],squar[x][1],squar[x][2],squar[x][3]);
            if(test(pointx,pointy,squar[x][0],squar[x][1],squar[x][2],squar[x][3]))
            {
                cout<<"Point "<<points<<" is ";
                cout<<"contained in figure "<<x+1<<endl;
                notin=false;
            }
        }
        if(notin)
            cout<<"Point "<<points<<" is "<<"not contained in any figure"<<endl;
        points++;
    }
}
