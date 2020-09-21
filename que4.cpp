#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
 int n,k;
 int sum =0;
 scanf("%d %d",&n,&k);
 int pass = k;
 int a[n];
 for(int i=0;i<n;i++){
     scanf("%d",&a[i]);}
     if(a[k-1]==0){
            for(int i=0;i<=k-1;i++){
                if(a[i]>0){
                    sum++;}
                    else{pass--;};
                    }
            if(sum==0){printf("%d",0);}
            else{printf("%d",pass);}
         }
     else{ 
            for(int i =k-1;i<n-1;i++){
                if(a[i]==a[i+1]){
                     pass++;
                    }
                else{break;}
                    }
    printf("%d",pass);
     }
return 0 ;}
