#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    // char *strstr( const char *str, const char *substr );
char* strstr_f(const char *str, const char *substr) {

/*  description:
        Finds the first occurrence of the null-terminated byte 
        string pointed to by substr in the null-terminated byte 
        string pointed to by str. The terminating null characters 
        are not compared.    
    */

/*  parameters:
        str    = pointer to the null-terminated byte string to examine
        substr = pointer to the null-terminated byte string to search for
    */

    if (str == NULL) return NULL;
    
    if (*substr == '\0') return (char*) str;

    const char* tempStr = str;
    const char* tempSubstr = substr;

    int true = 1;

    for ( ; *str != '\0'; str++) {

        if (*str != *substr) continue;

        tempStr = str;

        while (true) {

            if (*tempSubstr == '\0') return (char*) str;

            if (*tempStr++ != *tempSubstr++) break;
        }
        tempSubstr = substr;
    }


    return NULL;

/*  return:
        Pointer to the first character of the found substring in str, 
        or a null pointer if such substring is not found. If substr 
        points to an empty string, str is returned.  
    */

}


int main(void) {

    char str1[] = "Test1 Test2 Test3 Test4 Test5";
    char str2[] = "Object1 Object2 Test1 Test2 Object3";

    char fin[] = "Test2";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int siz1 = sizeof(str1);
    int siz2 = sizeof(str2);

    int lenFin = strlen(fin);
    int sizFin = sizeof(fin);


    printf("str1: %s\n", str1);
    printf("\tlen1: %d\n", len1);
    printf("\tsiz1: %d\n\n", siz1);

    printf("str2: %s\n", str2);
    printf("\tlen2: %d\n", len2);
    printf("\tsiz2: %d\n\n", siz2);

    printf("fin: %s\n", fin);
    printf("\tlenFin: %d\n", lenFin);
    printf("\tsizFin: %d\n\n", sizFin);

    char* res;
    
    printf("Library strstr function:\n\n");

    res = strstr(str1, fin);

    printf("\tRes1: \n");
    printf("\t\t        str1: %s\n", str1);
    printf("\t\tRest of str1: %s\n\n", res);

    res = strstr(str2, fin);

    printf("\tRes2: \n");
    printf("\t\t        str2: %s\n", str2);
    printf("\t\tRest of str2: %s\n\n", res);


    printf("\nMy strstr function:\n\n");

    res = strstr_f(str1, fin);

    printf("\tRes1: \n");
    printf("\t\t        str1: %s\n", str1);
    printf("\t\tRest of str1: %s\n\n", res);

    res = strstr_f(str2, fin);

    printf("\tRes2: \n");
    printf("\t\t        str2: %s\n", str2);
    printf("\t\tRest of str2: %s\n\n", res);


    return 0;

}
