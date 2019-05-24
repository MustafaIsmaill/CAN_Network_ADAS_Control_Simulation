#include "std_lib.h"

size_t str_len(const char *string) {
    const char *ss;
    ss = string;
    while (*ss)
        ss++;
    return ss - string;
}
char *strrev(char *str) {
    char *p1, *p2;
    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + str_len(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}
char *itoa(int8_t n, char *s, int8_t b) {
    static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    int8_t i=0, sign;

    if ((sign = n) < 0)
        n = -n;
    do {
        s[i++] = digits[n % b];
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    return strrev(s);
}
