char* toLowerCase(char* s) {
    char* ptr = s;
    while (*ptr != '\0') {
        if (*ptr >= 'A' && *ptr <= 'Z') {
            *ptr += 32;
        }
        ptr++;
    }
    return s;
}
