#include <stdio.h>
#include <string.h>


    // size_t strspn( const char* dest, const char* src );
size_t strspn_f(const char* dest, const char* src) {

/*  description:
        Returns the length of the maximum initial segment (span) of the byte string pointed to by dest,
        that consists of only the characters found in byte string pointed to by src.
    */

/*  parametrs:   
        dest = pointer to the null-terminated byte string to be analyzed
        src	 = pointer to the null-terminated byte string that contains the characters to search for
    */

/*    // strspn function written without pointer arithmetics
    size_t len = 0, i, j;

    size_t lenDest = 0;
        while (dest[lenDest] != '\0') lenDest++;

    size_t lenSrc = 0;
        while (src[lenSrc] != '\0') lenSrc++; 
    
    int match = 0;

    for (i = 0; i < lenDest; i++) {

        match = 0;

        for (j = 0; j < lenSrc; j++) {
            if (dest[i] == src[j]) {
                match = 1;
                break;
            }
        }

        if (!match) break;
        else len++;

    }
*/

        // size_t len = (return variable) The length of the maximum initial segment that contains only characters from byte string pointed to by src.  
    size_t len = 0;
    
        // size_t shift = (work varaible) Used for returning pointer to src string back to 1. char
    size_t shift = 0;

        // int match = (boolean-like variable) 
    int match = 0;


        // while loop - loops through each char in dest string
    while (*dest != '\0') {

            // setting values of variables to default values 
        match = 0;
        shift = 0;

            // while - loops through each char in src string
        while (*src != '\0') {

                // if - char in dest match with char in src - break 
            if (*dest == *src) {
                match = 1;
                break;
            }
            shift++;
            src++;
        }
            // returning pointer to src string back to 1. char
        src -= shift;

            // if - char in dest didn't match with any char in src - break
        if (!match) break;

        len++;
        dest++;
    }

    return len;

/*  return:
        The length of the maximum initial segment that contains only characters from byte string pointed to by src.
    */
}



int main(void) {

    char str1[] = "1234567890abcdefgh";
    char str2[] = "abc4321";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int siz1 = sizeof(str1);
    int siz2 = sizeof(str2);


    printf("str1: %s\n", str1);
    printf("\tlen1: %d\n", len1);
    printf("\tsiz1: %d\n\n", siz1);

    printf("str2: %s\n", str2);
    printf("\tlen2: %d\n", len2);
    printf("\tsiz2: %d\n\n", siz2);

    printf("Library strspn function:\n");

    int lenRes = strspn(str1, str2);
        printf("\tlenRes: %d\n", lenRes);

    printf("\nMy strspn function:\n");

    lenRes = strspn_f(str1, str2);
        printf("\tlenRes: %d\n", lenRes);


    return 0;

}
