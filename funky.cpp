#include<iostream>
#include<stdio.h>
int funky(int num){
    int t =0;
    int i =0;
    while(i<=num){
            if(i*(i+1)==2*num){
                t=1;
                break;
                }
            i++;
        }
        return t;    
    }
int main(){
    int num;
    int i =0;
    int t =0;
    int ans =0;
    scanf("%d",&num);
    //funky numbers
    int g = funky(num);
    if(g==1){
        printf("hi");} 
    while(num-i>0){
        if((t=funky(i))==1){
            if((t=funky(num-i))==1){
                 ans =1;
                 break;   
                }
        }
         i++;   
        }
        if(ans==1){
            printf("YES\n");}
            else{
                printf("NO\n");}
    return 0;
    }
