

#include <stdbool.h>
#include <string.h>
bool match(char *pattern, char *string)
{
    if (*pattern == '\0')
		return (*string == '\0');
    if (*pattern == '*')
	{
        while (*string != '\0')
		{
            if (match(pattern + 1, string))
				return true;
            string++;
        }
        return (match(pattern + 1, string));
    }
    if (*pattern == '?')
	{
        if (*string == '\0')
			return false;
        return (match(pattern + 1, string + 1));
    }
    if (*pattern == *string) 
	{
        if (*string == '\0')
            return true;
        return (match(pattern + 1, string + 1));
    }
    return false;
}

#include <stdio.h>

int main() {
    char *pattern = "?c";
    char *string1 = "gc";
    char *string2 = "main.c";
    char *string3 = "test.c";

    if (match(pattern, string1)) {
        printf("%s matches %s\n", string1, pattern);
    }
    if (match(pattern, string2)) {
        printf("%s matches %s\n", string2, pattern);
    }
    if (match(pattern, string3)) {
        printf("%s matches %s\n", string3, pattern);
    }

    return 0;
}