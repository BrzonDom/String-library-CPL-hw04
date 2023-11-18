#include <stdio.h>
#include <string.h>


    // char *strcat(char *dest, const char *src);
char* strcat_f(char* dest, const char* src) {

/*  description:
        Appends a copy of the null-terminated byte string pointed to by src to the end of the null-terminated byte string pointed to by dest. 
        The character src[0] replaces the null terminator at the end of dest. The resulting byte string is null-terminated.
        The behavior is undefined if the destination array is not large enough for the contents of both src and dest and the terminating null character.
        The behavior is undefined if the strings overlap. The behavior is undefined if either dest or src is not a pointer to a null-terminated byte string.
    */

/*  parameters:
        dest = pointer to the null-terminated byte string to append to 
        src  = pointer to the null-terminated byte string to copy from 
    */

        // while loop - loops through the char in dest string setting the pointer to null terminator
    while (*dest != '\0') dest++;

        // while loop - loops through the char in src string
    while (*src != '\0') {

            // sets the dest char pointer to src char pointer
        *dest = *src;
    
        dest++;
        src++;
    }

        // adds a null pointer to the end of dest string
    *dest = '\0';


    return dest;

/*  return: 
        returns a copy of dest
    */
}


int main(void) {

    char str1[20] = "Test1";
    char str2[] = "Test2";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int siz1 = sizeof(str1);
    int siz2 = sizeof(str2);

    int lenRes = len1 + len2 + 1;

    printf("str1: %s\n", str1);
    printf("\tlen1: %d\n", len1);
    printf("\tsiz1: %d\n\n", siz1);

    printf("str2: %s\n", str2);
    printf("\tlen2: %d\n", len2);
    printf("\tsiz2: %d\n\n", siz2);
    
    char res[50];

    printf("Library strcat function:\n\n");

    printf("\tStr1: %s\n", str1);
    printf("\tStr2: %s\n\n", str2);

    strcat(str1, str2);
        printf("\tRes: %s\n", str1);


    printf("\nMy strcat function:\n\n");

    printf("\tStr1: %s\n", str1);
    printf("\tStr2: %s\n\n", str2);

    strcat_f(str1, str2);
        printf("\tRes: %s\n", str1);


    return 0;

}
