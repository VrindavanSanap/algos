#include <stdio.h>


void print_int_array(int nums[], int size){
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%d ", nums[i]);
    }
    printf("]\n");
}
void swap(int nums[], int i, int j){
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}
void print_permutations(int* nums, int start, int size){
  if(start == size-1){
    print_int_array(nums, size);
    return;
  }
  for(int i = start; i < size; i++){
    swap(nums, start, i);
    print_permutations(nums, start+1, size);
    swap(nums, start, i);
  }
}
int main(){
  int nums[3] = {1,2,3};
  print_permutations(nums, 0, 3);
  return 0;
}
