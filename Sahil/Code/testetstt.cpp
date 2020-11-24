#include<iostream>
#include <vector>
#include<algorithm>

int main(){
    std::vector<int> a = {1, 2, 3, 4};
    int serch = 4;

    std::vector<int>::iterator i;

    i = std::find (a.begin(),a.end(), serch);
    
    if (i != a.end()){
        // std::cout<<"found";
    }

    for(int a : {0, 1}){
        std::cout<<a;
    }
}