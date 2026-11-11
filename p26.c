#include <stdlib.h>
#include <stdbool.h>

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Helper function for Binary Search
bool binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Sort nums2 to enable binary search
    qsort(nums2, nums2Size, sizeof(int), compare);
    
    int maxSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(maxSize * sizeof(int));
    bool added[1001] = {false};
    int count = 0;
    
    for (int i = 0; i < nums1Size; i++) {
        int val = nums1[i];
        if (!added[val] && binarySearch(nums2, nums2Size, val)) {
            result[count++] = val;
            added[val] = true;
        }
    }
    
    *returnSize = count;
    return result;
}
