#include<stdio.h>


int bubble(int arr[],int n){
int i,j;
for(i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(arr[j]>arr[j+1]){
int temp = arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
return 0;
}
int main(){

int n,i;
printf("\nEnter the number of Elements : ");
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++){
printf("\nEnter Element %d : ",i+1);
scanf("%d",&arr[i]);
}

bubble(arr,n);

printf("\n\n***Sorted Array***\n\n");
for(i=0;i<n;i++){
printf("%d \t",arr[i]);
}
return 0;
}

