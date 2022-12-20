#define _CRT_SECURE_NO_WARNINGS 1
char* find_char(char const* str, char const* chars)
{
    char* cp;
    //判空
    if (str != NULL && chars != NULL) {
        for (; *str != '\0'; str++) {	//遍历str
            for (cp = chars; *cp != '\0'; cp++) {
                if (*str == *cp)
                    return str;
            }
        }
    }
    //没找到，返回NULL
    return NULL;
}