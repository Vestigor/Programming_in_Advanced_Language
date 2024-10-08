/* 信05 2353814 马小龙 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：求字符串str长度
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;

    return i; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2追加到s1后面，含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, j;
    i = tj_strlen(s1);
    for (j = 0; j <= tj_strlen(s2); j++) {
        s1[i] = s2[j];
        i++;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：将字符串s2的前len个字符追加到s1后面，并添加\0
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, j;
    i = tj_strlen(s1);
    if (len < tj_strlen(s2)) {
        for (j = 0; j < len; j++) {
            s1[i] = s2[j];
            i++;
        }                                                       
        s1[i] = '\0';
    }
    else
        tj_strcat(s1, s2);

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2复制到s1中，覆盖s1原内容，复制时包含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    for (i = 0; i <= tj_strlen(s2); i++)
        s1[i] = s2[i];

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2前len个字符复制到s1中，复制时不含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i=0,j=0;
    if (len <= tj_strlen(s2)) {
        for (i = 0; i < len; i++) {
            while (s2[j] == '\0')
                j++;
            s1[i] = s2[j];
            j++;
        }
    }
    else {
        for (j = 0; j < tj_strlen(s2); j++) {
            while (s2[j] == '\0')
                j++;
            s1[i] = s2[j];
            i++;
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2的大小，英文字母区分大小写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int min = tj_strlen(s1) + 1 < tj_strlen(s2) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1;
    for (int i = 0; i < min; i++) {
        if (s1[i] != s2[i])
        
            return int(s1[i] - s2[i]);
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2的大小，英文字母不区分大小写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int min = tj_strlen(s1) + 1 < tj_strlen(s2) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1;
    char f1=0, f2=0;
    for (int i = 0; i < min; i++) {
        if (s1[i] >= 65 && s1[i] <= 90)
            f1 = s1[i] + 32;
        else
            f1 = s1[i];
        if (s2[i] >= 65 && s2[i] <= 90)
            f2 = s2[i] + 32;
        else
            f2 = s2[i];
        if (f1 != f2)
            return int(f1 - f2);
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2前len个字符的大小，英文字母区分大小写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int min;
    min = tj_strlen(s1) + 1 < tj_strlen(s2) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1;
    min = min < len ? min : len;
    for (int i = 0; i < min; i++) {
        if (s1[i] != s2[i])
            return int(s1[i] - s2[i]);
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：比较字符串s1和s2前len个字符的大小，英文字母不区分大小写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int min;
    min = tj_strlen(s1) + 1 < tj_strlen(s2) + 1 ? tj_strlen(s1) + 1 : tj_strlen(s2) + 1;
    min = min < len ? min : len;
    char f1 = 0, f2 = 0;
    for (int i = 0; i < min; i++) {
        if (s1[i] >= 65 && s1[i] <= 90)
            f1 = s1[i] + 32;
        else
            f1 = s1[i];
        if (s2[i] >= 65 && s2[i] <= 90)
            f2 = s2[i] + 32;
        else
            f2 = s2[i];
        if (f1 != f2)
            return int(f1 - f2);
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串中的所有小写字母转为大写，其他字符不变，转换后放在原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    for (int i = 0; i < tj_strlen(str); i++) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：将字符串中的所有大写字母转为小写，其他字符不变，转换后放在原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    for (int i = 0; i < tj_strlen(str); i++) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串str中寻找字符ch第一次出现的位置，顺序是从左到右
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    for (int i = 0; i <= tj_strlen(str); i++) {
        if (str[i] == ch)
            return 1 + i;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串str中寻找字符串substr第一次出现的位置，顺序是从左到右
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, j=1, k;
    for (i = 0; i <=tj_strlen(str); i++) {
        if (str[i] == substr[0]) {
            k = i;
            for (j = 1; j < tj_strlen(substr); j++) {
                k++;
                if (str[k] != substr[j])
                    break;
            }
            if (j == tj_strlen(substr))
                return i + 1;
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串str中寻找字符ch第一次出现的位置，顺序是从右到左
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    for (int i = tj_strlen(str)-1; i >=0; i--) {
        if (str[i] == ch)
           return i+1;
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：在字符串str中寻找字符串substr第一次出现的位置，顺序是从右到左
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, j , k;
    for (i = tj_strlen(str)-1; i >= 0; i--) {
        if (str[i] == substr[tj_strlen(substr)-1]) {
            k = i;
            for (j= tj_strlen(substr) - 2; j>=0; j--) {
                k--;
                if (str[k] != substr[j])
                    break;
            }
            if (j == -1)
                return k + 1;
        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：字符串反转，放在原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int ret, mid = (tj_strlen(str) + 1) / 2;
    for (int i = 0; i < mid; i++) {
        ret = str[i];
        str[i] = str[tj_strlen(str)-1 - i];
        str[tj_strlen(str)-1 - i] = ret;
    }

    return 0; //return值可根据需要修改
}
