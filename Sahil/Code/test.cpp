#include<algorithm>
#include<iostream>
#include<string.h>
#include<vector>
#include<map>

void g8(int a[][4], std::vector<std::vector<int>> &grp8){

    int flag = 0;
    std::vector<int> grp;

    //horizontal
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
                grp.push_back(10*(i%4) + abs(j - 2)%4);
                grp.push_back(10*(i%4) + abs((j+1) - 2)%4);
                grp.push_back(10*(i%4) + abs((j+2) - 2)%4);
                grp.push_back(10*(i%4) + abs((j+3) - 2)%4);

                grp.push_back(10*((i+1)%4) + abs(j - 2)%4);
                grp.push_back(10*((i+1)%4) + abs(j+1 - 2)%4);
                grp.push_back(10*((i+1)%4) + abs(j+2 - 2)%4);
                grp.push_back(10*((i+1)%4) + abs(j+3 - 2)%4);

                grp8.push_back(grp);
                grp.clear();
                flag = 0;
                break;
            }
        }
    }

    //vertical
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
                grp.push_back(10*((i- 2)%4) + abs(j)%4);
                grp.push_back(10*((i+1- 2)%4) + abs(j)%4);
                grp.push_back(10*((i+2- 2)%4) + abs(j)%4);
                grp.push_back(10*((i+3- 2)%4) + abs(j)%4);

                grp.push_back(10*((i- 2)%4) + abs((j+1))%4);
                grp.push_back(10*((i+1- 2)%4) + abs((j+1))%4);
                grp.push_back(10*((i+2- 2)%4) + abs((j+1))%4);
                grp.push_back(10*((i+3- 2)%4) + abs((j+1))%4);

                grp8.push_back(grp);
                grp.clear();
                flag = 0;
                break;
            }
        }
    }
}

void g4(int a[][4], std::vector<std::vector<int>> &grp4){

    int flag = 0;
    std::vector<int> grp;

    //grp square
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 and a[(i+1)%4][j%4]==1 and a[(i+1)%4][(j+1)%4]==1) {
                    grp.push_back(10*(i%4) + (j%4));
                    grp.push_back(10*((i)%4) + ((j+1)%4));
                    grp.push_back(10*((i+1)%4) + ((j)%4));
                    grp.push_back(10*((i+1)%4) + ((j+1)%4));
                    grp4.push_back(grp);
                    grp.clear();
                }
            }
        }
    }
    
    //grp vertical line
    for (int j=0; j<4 ; j++){
        for (int i=0; i<4; i++){
            if (a[i][j]==1) {
                if (a[i%4][(j)%4]==1 and a[(i+1)%4][(j)%4]==1 and a[(i+2)%4][(j)%4]==1 and a[(i+3)%4][(j)%4]==1) {
                    grp.push_back(10*((i)%4) + ((j)%4));
                    grp.push_back(10*((i+1)%4) + ((j)%4));
                    grp.push_back(10*((i+2)%4) + ((j)%4));
                    grp.push_back(10*((i+3)%4) + ((j)%4));
                    grp4.push_back(grp);
                    grp.clear();
                    break;
                }
            }
        }
    }
    
    
    //grp horizontal line
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (a[i][j]==1) {
                if (a[i%4][(j)%4]==1 and a[(i)%4][(j+1)%4]==1 and a[(i)%4][(j+2)%4]==1 and a[(i)%4][(j+3)%4]==1) {
                    grp.push_back(10*((i)%4) + ((j)%4));
                    grp.push_back(10*((i)%4) + ((j+1)%4));
                    grp.push_back(10*((i)%4) + ((j+2)%4));
                    grp.push_back(10*((i)%4) + ((j+3)%4));
                    grp4.push_back(grp);
                    grp.clear();
                    break;
                }
            }
        }
    }
    
}

void g2(int a[][4], std::vector<std::vector<int>> &grp2){

    std::vector<int> grp;

    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1) {
                    grp.push_back(10*(i%4) + (j)%4);
                    grp.push_back(10*(i%4) + ((j+1))%4);
                    grp2.push_back(grp);
                    grp.clear();
                }
                if (a[(i+1)%4][j%4]==1 ) {
                    grp.push_back(10*((i)%4) + (j)%4);
                    grp.push_back(10*((i+1)%4) + (j)%4);
                    grp2.push_back(grp);
                    grp.clear();
                }
            }
        }
    }
}

void elimGrps(std::vector<std::vector<int>> &grp8, std::vector<std::vector<int>> &grp4){

    std::vector<std::vector<int>> grp4_T;

    int flag=0;

    for(int i=0; i<grp4.size(); i++){
        std::sort(grp4[i].begin(), grp4[i].end());

        for (int j=0; j<grp8.size(); j++){
            std::sort(grp8[j].begin(), grp8[j].end());

            if(includes(grp8[j].begin(), grp8[j].end(), grp4[i].begin(), grp4[i].end()))
                flag++;
        }
        if (flag==0)
            grp4_T.push_back(grp4[i]);
        else flag=0;
    }
    grp4 = grp4_T;
}

void elimGrps(std::vector<std::vector<int>> &grp8, 
                std::vector<std::vector<int>> &grp4,
                std::vector<std::vector<int>> &grp2){
    
    for(int i=0; i<grp4.size(); i++){
        std::sort(grp4[i].begin(), grp4[i].end());

        for (int j=0; j<grp8.size(); j++){
            std::sort(grp8[j].begin(), grp8[j].end());
        }
    }
}

int main(){

    int KMap1[4][4];
    
    std::vector<std::vector<int>> grp8, grp4, grp2;

    //Sets all values of matrix 0
    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++) 
        KMap1[i][j] = 0;
    }
    
    //Map assignment
    std::map<int, int> getIndex;
    {
        getIndex[0] = 0;
        getIndex[1] = 1;
        getIndex[2] = 3;
        getIndex[3] = 2;
        getIndex[4] = 10;
        getIndex[5] = 11;
        getIndex[6] = 13;
        getIndex[7] = 12;
        getIndex[8] = 30;
        getIndex[9] = 31;
        getIndex[10] = 33;
        getIndex[11] = 32;
        getIndex[12] = 20;
        getIndex[13] = 21;
        getIndex[14] = 23;
        getIndex[15] = 22;
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
        KMap1[getIndex[input]/10][getIndex[input]%10] = 1;
    }

    g8(KMap1, grp8);
    g4(KMap1, grp4);
    g2(KMap1, grp2);
    elimGrps(grp8, grp4);
    elimGrps(grp4, grp2);
    elimGrps(grp8, grp2);
    

    //Output of initial array
    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++)
        {
            std::cout<<KMap1[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    std::cout<<"\n\nGroup of 8\n";
    for (std::vector<int> i : grp8)
    {
        for(int j : i){
            std::cout<<"["<<j/10<<", "<<j%10<<"]"<<", ";
        }
        std::cout<<"\n";
    }

    std::cout<<"\nGroup of 4\n";
    for (std::vector<int> i : grp4)
    {
        for(int j : i){
            std::cout<<"["<<j/10<<", "<<j%10<<"]"<<", ";
        }
        std::cout<<"\n";
    }
    
    std::cout<<"\nGroup of 2\n";
    for (std::vector<int> i : grp2)
    {
        for(int j : i){
            std::cout<<"["<<j/10<<", "<<j%10<<"]"<<" , ";
        }
        std::cout<<"\n";
    }

}