#include<stdio.h>
#include<limits.h>
#include<math.h>
void swap(int *nums , int *j , int *i);
int threeSumClosest(int* nums, int numsSize, int target);
void sort(int * nums , int numsSize);
int main(){
    int nums[10]={-5,1,4,0,5,4,1,8,-9,6};
    printf("\n%d\n",threeSumClosest(nums,10,1));
    return 0;
}
int threeSumClosest(int* nums, int numsSize, int target){
    sort(nums,numsSize);
    for(int *i=nums;i<nums+numsSize;i++)
        printf("%d ",*i);
    int error = INT_MAX;int ans=0;int temp=0;
    for(int *i=nums ; i<nums+numsSize-2; i++){
        int *start_pointer=i+1;
        int *end_pointer=nums+numsSize-1;
        while(start_pointer<end_pointer){
            temp=*i + *start_pointer + *end_pointer;
            if(target==temp)
                return target;
            if(abs(target-temp)<error){
                error=abs(target-temp);
                ans=temp;
            }
            if(target>temp)
                start_pointer++;
            else
                end_pointer--;

        }
    }
    return ans;
}
void sort(int * nums , int numsSize){
    for(int *i=nums+numsSize-1;i>nums;i--){
        for(int *j=nums;j<i;j++){
            if(*j>*(j+1)){
                swap(nums,j,j+1);
            }
        }
    }
}
void swap(int *nums , int *j , int *i){
    int temp=*i;
    *i=*j;
    *j=temp;
}