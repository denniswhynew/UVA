#include <iostream>
using namespace std;

int area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
}

bool overrec(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    int a1,a2,a3,a4;
    a1=area(x1,y1,x3,y3,x2,y2);
    a2=area(x1,y1,x4,y4,x2,y2);
    a3=area(x3,y3,x1,y1,x4,y4);
    a4=area(x3,y3,x2,y2,x4,y4);
    if(a1*a2<0 && a3*a4<0)
        return true;
    if(a1==0 && (x3-x1)*(x3-x2)<=0 && (y3-y1)*(y3-y2)<=0)
        return true;
    if(a2==0 && (x4-x1)*(x4-x2)<=0 && (y4-y1)*(y4-y2)<=0)
        return true;
    if(a3==0 && (x1-x3)*(x1-x4)<=0 && (y1-y3)*(y1-y4)<=0)
        return true;
    if(a4==0 && (x2-x3)*(x2-x4)<=0 && (y2-y3)*(y2-y4)<=0)
        return true;
    return false;
}

int main(){
    int times;
    int firstx,firsty,secondx,secondy,leftx,yon,rightx,downy;
    bool isinter;
    cin>>times;
    for(int i=1;i<=times;i++)
    {
        isinter=false;
        cin>>firstx>>firsty>>secondx>>secondy>>leftx>>yon>>rightx>>downy;
        if(leftx > rightx)
        {
            int temp = rightx;
            rightx = leftx;
            leftx = temp;
        }
        if(downy > yon)
        {
            int temp = downy;
            downy = yon;
            yon = temp;
        }
        if(overrec(firstx,firsty,secondx,secondy,leftx,yon,rightx,yon))
            isinter = true;
        else if(overrec(firstx,firsty,secondx,secondy,leftx,downy,rightx,downy))
            isinter = true;
        else if(overrec(firstx,firsty,secondx,secondy,leftx,yon,leftx,downy))
            isinter = true;
        else if(overrec(firstx,firsty,secondx,secondy,rightx,yon,leftx,downy))
            isinter = true;
        else if(firstx >= leftx&&firstx <= rightx&&secondx >= leftx&&secondx <= rightx&&firsty >= downy&&firsty <= yon&&secondy >= downy&&secondy <= yon)
            isinter = true;

        if(isinter)
            cout<<"T"<<endl;
        else
            cout<<"F"<<endl;
    }
}
