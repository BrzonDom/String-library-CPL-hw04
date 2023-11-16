#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    // char *strpbrk( const char *dest, const char *breakset );
char* strpbrk_f(const char* dest, const char* breakset) {

/*  description:
        Scans the null-terminated byte string pointed to by dest for 
        any character from the null-terminated byte string pointed to 
        by breakset, and returns a pointer to that character.
    */

/*  parameters:
        dest     = pointer to the null-terminated byte string to be analyzed
        breakset = pointer to the null-terminated byte string that contains the characters to search for
    */

    if (dest == NULL || breakset == NULL)
        return NULL;

    const char *tempset;

    while (*dest != '\0') {

        tempset = breakset;

        while (*tempset != '\0') {

            if (*dest == *tempset)
                return (char*) dest;

            tempset++;
        }
        dest++;
    }


    return NULL;

/*  return:
        Pointer to the first character in dest, that is also in breakset, 
        or null pointer if no such character exists.
    */

}


    // char *strchr( const char *str, int ch );
char* strchr_f(const char *str, int ch) {

/*  description:
        Finds the first occurrence of ch (after conversion to char as if 
        by (char)ch) in the null-terminated byte string pointed to by str 
        (each character interpreted as unsigned char). The terminating null 
        character is considered to be a part of the string and can be 
        found when searching for '\0'.
    */

/*  parameters:
        str	= pointer to the null-terminated byte string to be analyzed
        ch  = character to search for
    */

    while (*str != '\0') {

        if (*str == ch) return (char*) str;

        str++;
    }

    if (ch == '\0') return (char*) str;

    return NULL;

/*  return:            
        Pointer to the found character in str, or null pointer if no such 
        character is found.
    */

}


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

    return len;

/*  return:
        The length of the maximum initial segment that contains only characters from byte string pointed to by src.
    */
}

static char* iter;

    // char *strtok( char *str, const char *delim ); 
char* strtok_f (char* str, const char* delim) {

/*  description:
        1) Finds the next token in a null-terminated byte string pointed to by str. The separator characters are identified by null-terminated byte string pointed to by delim.
        This function is designed to be called multiple times to obtain successive tokens from the same string.
        If str is not a null pointer, the call is treated as the first call to strtok for this particular string. The function searches for the first character which is not contained in delim.
        If no such character was found, there are no tokens in str at all, and the function returns a null pointer.
        If such character was found, it is the beginning of the token. The function then searches from that point on for the first character that is contained in delim.
        If no such character was found, str has only one token, and future calls to strtok will return a null pointer
        If such character was found, it is replaced by the null character '\0' and the pointer to the following character is stored in a static location for subsequent invocations.
        The function then returns the pointer to the beginning of the token
        If str is a null pointer, the call is treated as a subsequent call to strtok: the function continues from where it left in previous invocation. The behavior is the same as if the previously stored pointer is passed as str.
        The behavior is undefined if either str or delim is not a pointer to a null-terminated byte string.
    */

/* parameters:
        str	  = pointer to the null-terminated byte string to tokenize
        delim =	pointer to the null-terminated byte string identifying delimiters
    */

    char* token;

    if (str == NULL)
        str = iter;

    str += strspn_f(str, delim);

    if (*str == '\0') {
        iter = str;
        return NULL;
    }

    token = str;
    str = strpbrk_f(token, delim);

    if (str == NULL)
        iter = strchr_f(token, '\0');     // iter = __rawmemchr (token, '\0');
    else {
        *str = '\0';
        iter = str + 1;
    }

    return token;

/*  return:
        Returns pointer to the beginning of the next token or 
        a null pointer if there are no more tokens.
    */
}


int main(void) {

    int i, j;

    char str[] = "Part1 Part2 Part3 Part4 Part5";
    char splt[] = " ";

    int lenStr = strlen(str);
    // for (i = 0; i < lenStr; i++)
    //     printf("%c", str[i]);

    // printf("\n");

    int szStr = sizeof(str);
    // for (i = 0; i < szStr; i++)
    //     printf("%c", str[i]);


    printf("Str: %s\n", str);
    printf("\tlen: %d\n", lenStr);
    printf("\tsiz: %d\n", szStr);

    printf("\n");

    char* res;
    i = 1;

    printf("Library strtok function:\n\n");

    printf("\tStr: %s\n\n", str);

    res = strtok(str, splt);

    while (res != NULL) {
        
        printf("\t%d.part: %s\n", i, res);
        i++;

        // printf("\t\t");
        // for (j = 0; j < szStr; j++)
        //     printf("%c", str[j]);
        // printf("\n\n");

        res = strtok(NULL, splt);
    }

    printf("\nMy strtok function:\n\n");

    strcpy(str, "Part1 Part2 Part3 Part4 Part5");
    printf("\tStr: %s\n\n", str);

    res = strtok_f(str, splt);
    i = 1;

    while (res != NULL) {

        printf("\t%d.part: %s\n", i, res);
        i++;

        // printf("\t\t");
        // for (j = 0; j < szStr; j++)
        //     printf("%c", str[j]);
        // printf("\n\n");
    
        res = strtok_f(NULL, splt);
    }


    return 0;

}
