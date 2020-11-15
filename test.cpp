#include<iostream>
#include<vector>
using namespace std;

int main(){
    int num;
    vector<int> testV;
    while (cin>>num)
    {
        testV.push_back(num);
    }
    for(int i : testV)
    cout<<i<<" ";
}