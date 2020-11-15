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
    int noOf1s, input, i;

    //Input
    cout<<"Enter number of min/max terms: ";
    cin>>noOf1s;
    cout<<"Enter postions of 1s: ";
    for (int i = 0; i < noOf1s; i++)
    {
        cin>>input;
        if(input>=0 && input<=15)
        posOf1s.push_back(input);
    }
    
}