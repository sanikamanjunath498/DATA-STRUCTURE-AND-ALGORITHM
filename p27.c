#include <stdio.h>
#include <stdlib.h>

// Helper function to find the first occurrence of the target
int findFirst(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;
    int first = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            first = mid;
            high = mid - 1; // Search on the left side for the first occurrence
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

// Helper function to find the last occurrence of the target
int findLast(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;
    int last = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            last = mid;
            low = mid + 1; // Search on the right side for the last occurrence
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for the result array of size 2
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    result[0] = findFirst(nums, numsSize, target);
    result[1] = findLast(nums, numsSize, target);
    
    return result;
}
