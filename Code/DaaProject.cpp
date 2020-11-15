#include<iostream>
#include<string.h>
#include<vector>
#include<map>
struct kMap
{
    int n = 0;
    std::vector<int> group;
};

int main(){

    int KMap1[4][4];
    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++) 
        KMap1[i][j] = 0;
    }
    
    //Map assignment
    std::map<int, std::string> getIndex;
    {
        getIndex[0] = "00";
        getIndex[1] = "01";
        getIndex[2] = "03";
        getIndex[3] = "02";
        getIndex[4] = "10";
        getIndex[5] = "11";
        getIndex[6] = "13";
        getIndex[7] = "12";
        getIndex[8] = "30";
        getIndex[9] = "31";
        getIndex[10] = "33";
        getIndex[11] = "32";
        getIndex[12] = "20";
        getIndex[13] = "21";
        getIndex[14] = "23";
        getIndex[15] = "22";
    }
    
    int noOf1s, input;

    //Input
    std::cout<<"Enter number of min/max terms: ";
    std::cin>>noOf1s;
    std::cout<<"Enter postions of min/max terms: ";
    for (int i = 0; i < noOf1s; i++)
    {
        std::cin>>input;
        if(input>=0 && input<=15)
        KMap1[stoi(getIndex[input])/10][stoi(getIndex[input])%10] = 1;
    }

    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++)
        {
            std::cout<<KMap1[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}