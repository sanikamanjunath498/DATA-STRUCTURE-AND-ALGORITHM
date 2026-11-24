#include <stdbool.h>
#include <stdlib.h>

static unsigned int hashInt(int key, unsigned int capacity) {
    unsigned int x = (unsigned int)key;
    x = ((x >> 16) ^ x) * 0x45d9f3bU;
    x = ((x >> 16) ^ x) * 0x45d9f3bU;
    x = (x >> 16) ^ x;
    return x & (capacity - 1);
}

bool containsDuplicate(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 1) {
        return false;
    }

    unsigned int capacity = 1;
    while (capacity < (unsigned int)numsSize * 2) {
        capacity <<= 1;
    }

    int *keys = (int *)malloc(capacity * sizeof(int));
    unsigned char *occupied = (unsigned char *)calloc(capacity, sizeof(unsigned char));
    if (keys == NULL || occupied == NULL) {
        free(keys);
        free(occupied);
        return false;
    }

    bool hasDup = false;
    unsigned int mask = capacity - 1;

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        unsigned int idx = hashInt(val, capacity);

        while (occupied[idx]) {
            if (keys[idx] == val) {
                hasDup = true;
                break;
            }
            idx = (idx + 1) & mask;
        }

        if (hasDup) {
            break;
        }

        keys[idx] = val;
        occupied[idx] = 1;
    }

    free(keys);
    free(occupied);
    return hasDup;
}
