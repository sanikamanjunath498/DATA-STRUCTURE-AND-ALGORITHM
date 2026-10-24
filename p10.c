int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int char_index[256];
    
    // Initialize character index tracker with -1
    for (int i = 0; i < 256; i++) {
        char_index[i] = -1;
    }
    
    int max_len = 0;
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        unsigned char c = s[right];
        
        if (char_index[c] >= left) {
            left = char_index[c] + 1;
        }
        
        char_index[c] = right;
        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }
    
    return max_len;
}
