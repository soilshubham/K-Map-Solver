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
                if (a[i%4][(j+1)%4]==1 and 
                    a[(i+1)%4][j%4]==1 and 
                    a[(i+1)%4][(j+1)%4]==1) {
                    flag++;
                }
                else {
                    flag=0;
                    break;
                }
            }
            if (flag == 3){
                for(int k : {0, 1, 2, 3}){
                    for(int m : {0, 1})
                        grp.push_back(10*((i+m)%4) + abs(j+k-2)%4);
                }
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
                if (a[i%4][(j+1)%4]==1 and 
                    a[(i+1)%4][j%4]==1 and 
                    a[(i+1)%4][(j+1)%4]==1) {
                    flag++;
                }
                else {
                    flag=0;
                    break;
                }
            }
            if (flag == 3){
                for(int k : {0, 1, 2, 3}){
                    for(int m : {0, 1})
                        grp.push_back(10*((i+k-2)%4) + abs((j+m))%4);
                }
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
                if (a[i%4][(j+1)%4]==1 and 
                    a[(i+1)%4][j%4]==1 and 
                    a[(i+1)%4][(j+1)%4]==1) {
                    for(int k:{0,1}){
                        for(int m:{0,1})
                        grp.push_back(10*((i+k)%4) + ((j+m)%4));
                    }
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
                if (a[i%4][(j)%4]==1 and a[(i+1)%4][(j)%4]==1 and 
                    a[(i+2)%4][(j)%4]==1 and 
                    a[(i+3)%4][(j)%4]==1) {
                    for(int k:{0, 1, 2, 3})
                        grp.push_back(10*((i+k)%4) + ((j)%4));
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
                if (a[i%4][(j)%4]==1 and a[(i)%4][(j+1)%4]==1 and 
                    a[(i)%4][(j+2)%4]==1 and 
                    a[(i)%4][(j+3)%4]==1){
                    for(int k:{0, 1, 2, 3})
                        grp.push_back(10*((i)%4) + ((j+k)%4));
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
                    for(int k: {0, 1})
                        grp.push_back(10*(i%4) + (j+k)%4);
                    grp2.push_back(grp);
                    grp.clear();
                }
                if (a[(i+1)%4][j%4]==1 ) {
                    for(int k: {0, 1})
                        grp.push_back(10*((i+k)%4) + (j)%4);
                    grp2.push_back(grp);
                    grp.clear();
                }
            }
        }
    }
}

void g1(int a[][4], std::vector<int> &grp1){
    
    for(int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i][j] == 1){
                if( a[(i+1)%4][j%4]  != 1 and 
                    a[i%4][(j+1)%4] != 1 and 
                    a[abs(i+3)%4][j%4] != 1 and 
                    a[i%4][abs(j+3)%4] != 1){
                    grp1.push_back(10*i + j);
                }
            }
        }
    }
}

void elimGrps4(std::vector<std::vector<int>> &grp8, 
                std::vector<std::vector<int>> &grp4){
    
    std::vector<std::vector<int>> grp4_T;
    std::vector<int>::iterator it;

    int flag=0;
    for(int i=0; i<grp4.size(); i++){
        for (int j=0; j<4; j++){
            
            for (std::vector<int> k : grp4)
            {
                it = std::find (k.begin(),k.end(), grp4[i][j]);
                if (it != k.end()){
                    flag++;
                }
            }

            for (std::vector<int> k : grp8)
            {
                it = std::find (k.begin(),k.end(), grp4[i][j]);
                if (it != k.end()){
                    flag++;
                }
            }

            if(flag == 1){
                grp4_T.push_back(grp4[i]);
                flag=0;
                break;
            }
            else flag=0;
        }
    }
    grp4 = grp4_T;
}

void elimGrps2(std::vector<std::vector<int>> &grp8, 
                std::vector<std::vector<int>> &grp4,
                std::vector<std::vector<int>> &grp2){
    
    std::vector<std::vector<int>> grp2_T, grp2_copy;
    std::vector<int>::iterator it; 

    grp2_copy = grp2;
    int flag=0;
    int flag2=0;

    for(int i=0; i<grp2.size(); i++){
        for (int j=0; j<2; j++){
            flag2++;
            for (std::vector<int> k : grp2)
            {
                it = std::find (k.begin(),k.end(), grp2[i][j]);
                if (it != k.end()){
                    flag++;
                }
            }

            for (std::vector<int> k : grp4)
            {
                it = std::find (k.begin(),k.end(), grp2[i][j]);
                if (it != k.end()){
                    flag++;
                }
            }

            for (std::vector<int> k : grp8)
            {
                it = std::find (k.begin(),k.end(), grp2[i][j]);
                if (it != k.end()){
                    flag++;
                }
            }

            if(flag == 1){
                grp2_T.push_back(grp2[i]);
                flag=0;
                flag2=0;
                break;
            }
            else flag=0;
            if(flag2==2){
                grp2[i] = {9, 9};
            }
        }
    }
    grp2 = grp2_T;
}


int main(){

    int KMap1[4][4];
    
    std::vector<std::vector<int>> grp8, grp4, grp2;
    std::vector<int> grp16, grp1;

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
    
    std::map<int, int> getKey;
    {
        getKey[0] = 0;
        getKey[1] = 1;
        getKey[3] = 2;
        getKey[2] = 3;
        getKey[10] = 4;
        getKey[11] = 5;
        getKey[13] = 6;
        getKey[12] = 7;
        getKey[30] = 8;
        getKey[31] = 9;
        getKey[33] = 10;
        getKey[32] = 11;
        getKey[20] = 12;
        getKey[21] = 13;
        getKey[23] = 14;
        getKey[22] = 15;
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

    if(noOf1s == 16){
        std::cout<<"No Simplification possible";
        return 0;
    }
    else if(noOf1s <16 and noOf1s>=8){
        g8(KMap1, grp8);
        g4(KMap1, grp4);
        g2(KMap1, grp2);
        g1(KMap1, grp1);
    }
    else if(noOf1s <8 and noOf1s>=4){
        g4(KMap1, grp4);
        g2(KMap1, grp2);
        g1(KMap1, grp1);
    }
    else if(noOf1s <4 and noOf1s>=2){
        g2(KMap1, grp2);
        g1(KMap1, grp1);
    }
    else if(noOf1s <2 and noOf1s>=1){
        g1(KMap1, grp1);
    }
    else
    {
        std::cout<<"Invalid input. Try again!";
        return 0;
    }
    
    elimGrps2(grp8, grp4, grp2);
    elimGrps4(grp8, grp4);
    
    
    
    //Output of initial array
    std::cout<<"Your Kmap:\n";
    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++)
        {
            std::cout<<KMap1[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    int c=1;
    std::cout<<"\n\nGroups you should form: \n"; 
    for (std::vector<int> i : grp8)
    {
        std::cout<<"\n"<<c<<") ";
        c++;
        for(int j : i){
            std::cout<<getKey[j]<<" ";
        }
        std::cout<<"\n";
    }

    for (std::vector<int> i : grp4)
    {
        std::cout<<"\n"<<c<<") ";
        c++;
        for(int j : i){
            
            std::cout<<getKey[j]<<" ";
        }
        std::cout<<"\n";
    }
    
    for (std::vector<int> i : grp2)
    {
        std::cout<<"\n"<<c<<") ";
        c++;
        for(int j : i){
            std::cout<<getKey[j]<<" ";
        }
        std::cout<<"\n";
    }
    
    for (int i : grp1)
    {
        std::cout<<"\n"<<c<<") ";
        c++;
        std::cout<<getKey[i]<<" ";
        std::cout<<"\n";
    }

    
}