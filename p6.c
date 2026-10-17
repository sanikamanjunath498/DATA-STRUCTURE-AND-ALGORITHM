char* addBinary(char* a, char* b) {
   
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    // Allocate memory for the result string (+2 for carry and null-terminator)
    int maxLen = lenA > lenB ? lenA : lenB;
    char* res = (char*)malloc(maxLen + 2);
    
    int i = lenA - 1;
    int j = lenB - 1;
    int carry = 0;
    int k = 0;
    
    // Loop through both strings from right to left
    while (i >= 0 || j >= 0 || carry) {
        int total = carry;
        
        if (i >= 0) {
            total += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            total += b[j] - '0';
            j--;
        }
        
        carry = total / 2;
        res[k++] = (total % 2) + '0';
    }
    
    res[k] = '\0';
    
    // Reverse the result string since we built it backwards
    int start = 0;
    int end = k - 1;
    while (start < end) {
        char temp = res[start];
        res[start] = res[end];
        res[end] = temp;
        start++;
        end--;
    }
    
    return res;

}
