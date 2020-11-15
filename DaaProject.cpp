#include<iostream>
#include<vector>
using namespace std;

struct kMap
{
    vector<int> group;
};

int main(){
    kMap KMap1[4][4];
    vector<int> posOf1s;
    int noOf1s;
    cout<<"Enter number of min/max terms: ";
    cin>>noOf1s;
    cout<<"Enter postions of 1s: ";
    int input;
    for (int i = 0; i < noOf1s; i++)
        {
            cin>>input;
            if(input>=0 && input<=15)
            posOf1s.push_back(input);
        }

    for (int i : posOf1s)
    {
        cout<<i<<" ";
    }
    
}