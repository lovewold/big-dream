#define _CRT_SECURE_NO_WARNINGS 1
char* find_char(char const* str, char const* chars)
{
    char* cp;
    //�п�
    if (str != NULL && chars != NULL) {
        for (; *str != '\0'; str++) {	//����str
            for (cp = chars; *cp != '\0'; cp++) {
                if (*str == *cp)
                    return str;
            }
        }
    }
    //û�ҵ�������NULL
    return NULL;
}