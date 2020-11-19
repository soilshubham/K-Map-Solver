#include<iostream>
#include<string.h>
#include<vector>
#include<map>

void g8(int a[][4], std::vector<int>*, std::vector<int>*);

struct kMap
{
    int n = 0;
    std::vector<int> group;
};

int main(){

    int KMap1[4][4];
    
    std::vector<int> grp8_i, grp8_j;

    //Sets all values of matrix 0
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

    g8(KMap1, &grp8_i, &grp8_j);

    //Output of initial array
    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++)
        {
            std::cout<<KMap1[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"Group of 8 starts at index:\n";
    for (int i : grp8_i)
    {
        std::cout<<i<<"["<<i/10<<", "<<i%10<<"]"<<std::endl;
    }

    for (int i : grp8_j)
    {
        std::cout<<i<<"["<<i/10<<", "<<i%10<<"]"<<std::endl;
    }
    

}


void g8(int a[][4], std::vector<int>* b, std::vector<int>* c){

    int flag = 0;
    
    //grp i
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 and a[(i+1)%4][j%4]==1 and a[(i+1)%4][(j+1)%4]==1) {
                    flag++;
                }
                else {
                    flag=0;
                    break;
                }
            }
            if (flag == 3){
                b->push_back(10*i + abs(j - 2)%4);
                flag = 0;
                break;
            }
        }
    }

    //grp8 j
    for (int j=0; j<4 ; j++){
        for (int i=0; i<4; i++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 and a[(i+1)%4][j%4]==1 and a[(i+1)%4][(j+1)%4]==1) {
                    flag++;
                }
                else {
                    flag=0;
                    break;
                }
            }
            if (flag == 3){
                c->push_back(10*(abs(i - 2)%4) + j);
                flag = 0;
                break;
            }
        }
    }
}