#include<iostream>
#include<stdio.h>
using namespace std;
int main(void){
    int n =0;
    cin>>n;
    int ar[n];
    int sum =0;
    for(int i =0;i<n;i++){
        ar[i]=0;}
    for(int i=0;i<n;i++){
        printf("Enter the number\n");
        scanf("%d",&ar[i]);
            if(sum==0){sum+=ar[i];}
            else{
                    int j =i;
                    while(j>=0){
                            if(ar[j/2]>ar[j]){
                                int temp = ar[j/2];
                                ar[j/2]=ar[j];
                                ar[j]=temp;
                                j=j/2;}
                            else{break;}
                        }
                }
        }
        printf("\n");
    for(int i =0;i<n;i++){
            printf("%d ",ar[i]);
        }
        printf("\n");
    return 0;
    }
