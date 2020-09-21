#include<iostream>
#include<stdio.h>
void merge(int *ar,int beg,int mid,int end){
  int left[(mid-beg)+1];
  int right[(end-mid)];
  for(int i =0;i<(mid-beg)+1;i++){
    left[i] = ar[i+beg];
  }
  for(int j=0;j<(end-mid);j++){
    right[j] = ar[j+mid+1];
  }
  int i =0;int j =0; int k=beg;
  while(i<(mid-beg)+1&&j<end-mid){
    if(left[i]<=right[j]){
      ar[k] = left[i];
      i++;
    }
    else{
      ar[k] = right[j];
      j++;
    }
    k++;
  }
  if(i<mid-beg+1){
    while(i<(mid-beg)+1)
    {ar[k] = left[i];
    i++;
    k++;}
  }
  else{
    while(j<end-mid)
    {ar[k] = right[j];
    k++;
    j++;}
  }
  for(int i=0;i<=end;i++){
    printf("%d ",ar[i]);
  }
  printf("\n");
}
void mergesort(int *ar,int beg,int end){
if(beg>=end){
  return;
}
int mid = (end+beg)/2;
mergesort(ar,beg,mid);
mergesort(ar,mid+1,end);
merge(ar,beg,mid,end);
for(int i =beg;i<=end;i++){
  printf("%d ",ar[i]);
}
printf("\n");
}
int main(int num,char** argv){
  int n = num-1;
  printf("%d\n",n);
  int ar[n];
  for(int i =1;i<num;i++){
    ar[i-1] = atoi(argv[i]);
  }
  mergesort(ar,0,n-1);
  printf("Sorted array: ");
  for(int i =0;i<n;i++){
    printf("%d ",ar[i]);
  }
  printf("\n");
  return 0;
}
