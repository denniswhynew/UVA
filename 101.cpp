#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int s;//size
    while(cin>>s)
    {
        vector<vector<int> >arr;//arr[s][n]
        arr.resize(s);
        for(int i=0;i<s;i++)
        {
            arr[i].resize(1);
            arr[i][1]=i;
        }
        string first,second;
        while(cin>>first&&first!="quit")
        {
            int one,two;
            cin>>one>>second>>two;
            switch first
            case "move":
                switch second
                case "onto":
                    break;
                case "over":
                    break;
                break;
            case "pile":
                switch second
                case "onto":
                    break;
                case "over":
                    break;
                break;
        }
    }
}
