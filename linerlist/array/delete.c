/*
 * Delete a element from a array
 * 
 * success: return 0; failed: return -1
 */
#include <stdio.h>
#define MAXSIZE 100

int delete(int nums[], int *pLength, int index)
{
    if (*pLength == 0 || *pLength > MAXSIZE)
        return -1;

    if (index < 0 || index >= *pLength)
        return -1;

    for (int i = index + 1; i < *pLength; i++)
    {
        nums[i-1] = nums[i];
    }
    *pLength -= 1;
    
    return 0;
}

int main(void){
    int nums[MAXSIZE] = {5, 4, 6, 12, -1};
    int length = 5;
    int index = 3;

    delete(nums, &length, index);

    for (int i = 0; i < length; i++)
    {
        printf("i = %d, num = %d\n", i, nums[i]);
    }

    return 0;
}