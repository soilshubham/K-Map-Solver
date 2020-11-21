#include<iostream>
#include<string.h>
#include<vector>
#include<map>

void g8(int a[][4], std::vector<std::vector<int>>* grp8);

struct kMap
{
    int n = 0;
    std::vector<int> group;
};

int main(){

    int KMap1[4][4];
    
    std::vector<std::vector<int>> grp8;

    // std::vector<int> grp8_i, grp8_j;

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

    g8(KMap1, &grp8);

    //Output of initial array
    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++)
        {
            std::cout<<KMap1[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"Group of 8 starts at index:\n";
    for (std::vector<int> i : grp8)
    {
        for(int j : i){
            std::cout<<"["<<j/10<<", "<<j%10<<"]"<<" , ";
        }
        std::cout<<"\n";
    }
}


void g8(int a[][4], std::vector<std::vector<int>>* grp8){

    int flag = 0;
    std::vector<int> grp;

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
                grp.push_back(10*(i%4) + abs(j - 2)%4);
                grp.push_back(10*(i%4) + abs((j+1) - 2)%4);
                grp.push_back(10*(i%4) + abs((j+2) - 2)%4);
                grp.push_back(10*(i%4) + abs((j+3) - 2)%4);

                grp.push_back(10*((i+1)%4) + abs(j - 2)%4);
                grp.push_back(10*((i+1)%4) + abs(j+1 - 2)%4);
                grp.push_back(10*((i+1)%4) + abs(j+2 - 2)%4);
                grp.push_back(10*((i+1)%4) + abs(j+3 - 2)%4);

                grp8->push_back(grp);
                grp.clear();
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
                grp.push_back(10*((i- 2)%4) + abs(j)%4);
                grp.push_back(10*((i+1- 2)%4) + abs(j)%4);
                grp.push_back(10*((i+2- 2)%4) + abs(j)%4);
                grp.push_back(10*((i+3- 2)%4) + abs(j)%4);

                grp.push_back(10*((i- 2)%4) + abs((j+1))%4);
                grp.push_back(10*((i+1- 2)%4) + abs((j+1))%4);
                grp.push_back(10*((i+2- 2)%4) + abs((j+1))%4);
                grp.push_back(10*((i+3- 2)%4) + abs((j+1))%4);

                grp8->push_back(grp);
                grp.clear();
                flag = 0;
                break;
            }
        }
    }
}

void g4(int a[][4], std::vector<int>* b, std::vector<int>* c){

    int flag = 0;
    

    //grp square
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 and a[(i+1)%4][j%4]==1 and a[(i+1)%4][(j+1)%4]==1) {
                    flag++;
                }
                else flag=0;
            }
            if (flag == 1){
                b->push_back(10*i + j);
                flag = 0;
                break;
            }
        }
    }
    
    //grp vertical line
    for (int i=0; i<4 ; i++){
        for (int j=0; j<4; j++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 or a[(i+1)%4][j%4]==1 ) {
                    flag++;
                }
                else flag=0;
            }
            if (flag == 3){
                b->push_back(10*i + j);
                flag = 0;
                break;
            }
        }
    }
    
    
    //grp horizontal line
    for (int j=0; j<4 ; j++){
        for (int i=0; i<4; i++){
            if (a[i][j]==1) {
                if (a[i%4][(j+1)%4]==1 or a[(i+1)%4][j%4]==1 ) {
                    flag++;
                }
                else flag=0;
            }
            if (flag == 3){
                b->push_back(10*i + j);
                flag = 0;
                break;
            }
        }
    }
    
}

// for 4s
    // if they r in square shape, the code is same as 8s but flag ==1 and we can use either grp_i or grp_j
    // if they r in vertical line, the code is same as 2s but flag == 3 and i for loop is followed by j for loop
    // if they r in vertical line, the code is same as 2s but flag == 3 and j for loop is followed by i for loop










// void g2(int* a[], vector<int>* b, vector<int>* c){

//     int flag = 0;
    

//     //grp i
//     for (int i=0; i<4 ; i++){
//         for (int j=0; j<4; j++){
//             if (a[i][j]==1) {
//                 if (a[i%4][(j+1)%4]==1 or a[(i+1)%4][j%4]==1 ) {
//                     flag++;
//                 }
//                 else flag=0;
//             }
//             if (flag == 1){
//                 b->push_back(10*i + j);
//                 flag = 0;
//                 break;
//             }
//         }
//     }

//     //grp8 j
//     for (int j=0; j<4 ; j++){
//         for (int i=0; i<4; i++){
//             if (a[i][j]==1) {
//                 if (a[i%4][(j+1)%4]==1 and a[(i+1)%4][j%4]==1 and a[(i+1)%4][(j+1)%4]==1) {
//                     flag++;
//                 }
//                 else flag=0;
//             }
//             if (flag == 1){
//                 c->push_back(10*i + j);
//                 flag = 0;
//                 break;
//             }
//         }
//     }
// }