/* 2353814 ��С�� ��05 */

#include <cstdio>   //NULL
//�������������κ�ϵͳͷ�ļ�

/* ----- �����������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ���str����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char *str)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    int i=0;
    if (str == NULL)
        return 0;
    for (; *str != '\0'; str++,i++)
        ;
    return i;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ���s2׷�ӵ�s1���棬��\0
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    char* str;
    if (s1 != NULL && s2 != NULL) {
        str = s1 + tj_strlen(s1);
        for (; *s2 !='\0'; str++, s2++)
            *str = *s2;
        *str = *s2;
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ���s2��ǰlen���ַ�׷�ӵ�s1���棬������\0
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    char* str = s1;
    if (s1 != NULL && s2 != NULL) {
        str = s1 + tj_strlen(s1);
        for (int i = 1; i <= len && *s2 != '\0'; str++, s2++, i++)
            *str = *s2;
        *str = '\0';
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    char* str = s1;
    if (s1 != NULL) {
        if (s2 == NULL)
            *str = '\0';
        else {
            for (; *s2 != '\0'; str++, s2++)
                *str = *s2;
            *str = *s2;
        }
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ���s2ǰlen���ַ����Ƶ�s1�У�����ʱ����\0
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* str = s1;
    if (s1 != NULL && s2 != NULL) {
        for (int i = 1; i <= len && *s2 != '\0'; str++, s2++, i++)
            *str = *s2;
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Ƚ��ַ���s1��s2�Ĵ�С��Ӣ����ĸ���ִ�Сд
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else if (s1 == NULL && s2 != NULL)
        return - 1;
    else {
        for (; *s1 != '\0' || *s2 != '\0'; s1++, s2++) {
            if (*s1 != *s2)
                return *s1 - *s2;
        }
        return 0;
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else {
        for (; *s1 != '\0' || *s2 != '\0'; s1++, s2++) {
            if (*s1 != *s2) {
                if (*s1 >= 97 && *s1 <= 122 && *s1 - *s2 == 32)
                    continue;
                else if (*s1 >= 65 && *s1 <= 90 && *s2 - *s1 == 32)
                    continue;
                else {
                    if (*s1 >= 65 && *s1 <= 90)
                        return *s1 - *s2 + 32;
                    else if (*s2 >= 65 && *s2 <= 90)
                        return *s1 - *s2 - 32;
                    else
                        return *s1 - *s2;
                }
            }
        }
        return 0;
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Ƚ��ַ���s1��s2ǰlen���ַ��Ĵ�С��Ӣ����ĸ���ִ�Сд
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else {
        for (int i=1;i<=len&&( *s1 != '\0' || *s2 != '\0'); s1++, s2++,i++) {
            if (*s1 != *s2)
                return *s1 - *s2;
        }
        return 0;
    }

    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Ƚ��ַ���s1��s2ǰlen���ַ��Ĵ�С��Ӣ����ĸ�����ִ�Сд
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 != NULL && s2 == NULL)
        return 1;
    else if (s1 == NULL && s2 != NULL)
        return -1;
    else {
        for (int i = 1; i <= len && (*s1 != '\0' || *s2 != '\0'); s1++, s2++, i++) {
            if (*s1 != *s2) {
                if (*s1 >= 97 && *s1 <= 122 && *s1 - *s2 == 32)
                    continue;
                else if (*s1 >= 65 && *s1 <= 90 && *s2 - *s1 == 32)
                    continue;
                else {
                    if (*s1 >= 65 && *s1 <= 90)
                        return *s1 - *s2 + 32;
                    else if (*s2 >= 65 && *s2 <= 90)
                        return *s1 - *s2 - 32;
                    else
                        return *s1 - *s2;
                }
            }
        }
        return 0;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ����е�����Сд��ĸתΪ��д�������ַ����䣬ת�������ԭ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strupr(char *str)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    char* s = str;
    if (str != NULL) {
        for (; *s != '\0'; s++) {
            if (*s >= 97 && *s <= 122)
                *s -= 32;
        }
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ַ����е����д�д��ĸתΪСд�������ַ����䣬ת�������ԭ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    char* s = str;
    if (str != NULL) {
        for (; *s != '\0'; s++) {
            if (*s >= 65 && *s <= 90)
                *s += 32;
        }
    }
    return str;
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ���str��Ѱ���ַ�ch��һ�γ��ֵ�λ�ã�˳���Ǵ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (str != NULL) {
        for (int i = 1; *str != '\0'; i++, str++) {
            if (*str == ch)
                return i;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ���str��Ѱ���ַ���substr��һ�γ��ֵ�λ�ã�˳���Ǵ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (str != NULL && substr != NULL) {
        for(int i = 1; *str != '\0'; i++, str++) {
            if (*str == *substr) {
                int j = 0;
                for (; *substr != '\0'&&*str!='\0'; str++, substr++, j++) {
                    if (*str != *substr)
                        break;
                }
                str -= j;
                substr -= j;
                if (j == tj_strlen(substr))
                    return i;
            }
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ���str��Ѱ���ַ�ch��һ�γ��ֵ�λ�ã�˳���Ǵ��ҵ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (str != NULL && *str != '\0') {
        int i = tj_strlen(str);
        str += tj_strlen(str) - 1;
        for (; i >= 0; i--, str--) {
            if (*str == ch)
                return i;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ַ���str��Ѱ���ַ���substr��һ�γ��ֵ�λ�ã�˳���Ǵ��ҵ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (str != NULL && substr != NULL&&*str!='\0'&&*substr!='\0') {
        int i = tj_strlen(str);
        int ret = tj_strlen(substr);
        str += tj_strlen(str) - 1;
        substr += tj_strlen(substr) - 1;
        for (; i > 0; i--, str--) {
            if (*str == *substr) {
                int j = ret;
                for (; j>0; str--, substr--, j--) {
                    if (*str != *substr)
                        break;
                }
                str += (ret-j);
                substr += (ret - j);
                if (j == 0)
                    return i-ret+1;
            }
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ַ�����ת������ԭ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strrev(char *str)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (str != NULL&&*str!='\0') {
        char* a = str;
        char* b = str + tj_strlen(str) - 1;
        for (;a<=b;a++,b--) {
            char ret = *a;
            *a = *b;
            *b = ret;
        }
    }
    return str;
}