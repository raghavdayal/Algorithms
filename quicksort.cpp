#include<iostream>
#include<stdio.h>
class quicksort{
    protected:
    int length;
    int* ar;
    int pass;
    public:
    int swaps;
    int count;
    quicksort(int a[],int len);
    void sort(int beg,int last);
    void swap(int *a,int *b);
    void print();
    void print_stats();
    };
    quicksort::quicksort(int a[],int len){
        ar = a;
        length = len;
        pass =0;
        count =0;
        swaps =0;
        }
    void quicksort :: print_stats(){
        printf("Total counts: %d\n Total swaps %d\n Total operations %d\n",count,swaps,(count+swaps));
        }
    void quicksort :: print(){
            for(int i =0;i<length;i++){
                printf("%d ",ar[i]);
                }
            printf("\n");
       }
    void quicksort::swap(int*a, int*b){
        swaps++;
        int temp = *a;
        *a=*b;
        *b=temp;}
    void quicksort::sort(int beg,int last){
        count++;
            if(beg>=last){
                return;}
            int pivot = last;
            int j = beg;
            int i = j-1;
            while(j<pivot){
                count++;
                    if(ar[j]>=ar[pivot]){
                        j++;}
                        else{
                              swap(&ar[i+1],&ar[j]);
                              i++;
                              j++;  
                            }
                }
            swap(&ar[i+1],&ar[pivot]);
            printf("Pass %d: ",pass);
            print();
            pass++;
            sort(beg,i);
            sort(i+2,last);
        }

int main(int num,char** argv){
    FILE *fp = fopen("./quick.dat","a+");
    int ar[num-1];
    for(int i=1;i<num;i++){
        ar[i-1] = atoi(argv[i]);
        }
        quicksort Q(ar,num-1);
        Q.sort(0,num-2);
        Q.print_stats();
        fprintf(fp,"%d\t%d\n",num-1,(Q.swaps+Q.count));
        fclose(fp);
    return 0;
    }
