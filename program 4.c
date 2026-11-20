char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        // Odd length palindromes
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }
        // Even length palindromes
        l = i; r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }
    }
    char* res = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';
    return res;
}