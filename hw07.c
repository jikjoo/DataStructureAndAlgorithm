#include<stdio.h>
#include <stdlib.h>

void print_array(int A[]){
    printf("[");
    for(int i=0; A[i]!=0; i++){
        printf("%d, ",A[i]);
    }
    printf("]\n");
}
void swap( int* a1,  int* a2){
    int temp;
    temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
int median3(int a[], int left, int right ){
    int center;
    center = (left + right) / 2;
    if( a[left] > a[center] )
        swap( &a[left], &a[center] );
    if( a[left] > a[right] )
        swap( &a[left], &a[right] );
    if( a[center] > a[right] )
        swap( &a[center], &a[right] );
    swap( &a[center], &a[right-1] );
    return a[right-1];
}
void quick_sort(int a[], int left, int right){
    int L = left, R = right;
    int temp;
    int pivot = median3(a,left,right);
    while(L<=R){
        //printf("pivot : %d\n",pivot);
        //print_array(a);
        while(a[L] < pivot) L++;
        while(a[R] > pivot) R--;
        if(L <= R){
            if(L != R){
                swap(&a[L],&a[R]);
            }
            L++;
            R--;
        }
    }
    if(left < R)
        quick_sort(a,left,R);
    if(L < right)
        quick_sort(a,L,right);
}


int main(void){
    FILE* fp;
    int i;
    int mnum[1000];
    fp = fopen("Data4Qsort.txt","r");
    //txt 파일에서 첫 숫자는 띄어줘야함
    if ( fp == NULL)
        printf("file open error"); 
    else{
        printf("[");
        for(i=0;fgetc(fp)!=EOF;i++){
            fscanf(fp,"%d",&mnum[i]);
            printf("%d, ",mnum[i]);
        }
        printf("]\n");
    }
    printf("(0 is over)\n");
    for(;;i++){
        printf("Input : ");
        scanf("%d",&mnum[i]);
        if(mnum[i]==0)
            break;
    }
    quick_sort(mnum,0,i-1);
    print_array(mnum);
    return 0;
}