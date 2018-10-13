#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************str*****************************/

char *str_init()
{
    char *p = (char *)malloc(1);
    p[0] = '\0';

    return p;
}

void str_free(char *p)
{
    free(p);
}

void str_append(char **src, const char *str)
{
    int len = strlen(*src) + strlen(str);

    char *str1_tmp = *src;  //保存原来指针位置
    *src = (char *)malloc(len + 1); //重新申请内存

    //操作
    strcpy(*src, str1_tmp);
    strcat(*src, str);
    (*src)[len] = '\0';

    free(str1_tmp);
}
/****************************str*****************************/


/****************************calculate*****************************/
void deal_split(char *a, int len, char *list[])
{
    int i = 0, j = 0;

    list[j++] = &a[0];
    for (i = 0; i < len; i++)
    {
        if (a[i] == ' ')
        {
            a[i] = '\0';
            list[j++] = &a[i + 1];
        }
    }
}

//加减
int deal_add_sub(char *str)
{
    //分割
    char *list[30] = { NULL };
    deal_split(str, strlen(str), list);

    int result = atoi(list[0]);
    int i = 0;
    for (i = 1; i < 10 && list[i] != NULL; i += 2)
    {
        if (*list[i] == '+')
        {
            result += atoi(list[i + 1]);
        }
        if (*list[i] == '-')
        {
            result -= atoi(list[i + 1]);
        }
    }
    return result;
}

//乘除
char *deal_mul_div(char *str)
{
    //分割
    char *list[30] = { NULL };
    deal_split(str, strlen(str), list);

    char *dst = str_init(); //输出字符串
    char *temp = list[0];

    char itoa_temp[10] = {0};

    int i = 0;
    for (i = 1; i < 30 && list[i] != NULL; i += 2)
    {
        if (*list[i] == '+')
        {
            str_append(&dst, temp);
            str_append(&dst, " + ");
            temp = list[i + 1];
        }
        else if (*list[i] == '-')
        {
            str_append(&dst, temp);
            str_append(&dst, " - ");
            temp = list[i + 1];
        }
        else if (*list[i] == '*')
        {
            int value = atoi(temp);
            value *= atoi(list[i + 1]);
            itoa(value, itoa_temp, 10);
            temp = itoa_temp;
        }
        else if (*list[i] == '/')
        {
            int value = atoi(temp);
            value /= atoi(list[i + 1]);
            itoa(value, itoa_temp, 10);
            temp = itoa_temp;
        }
    }
    str_append(&dst, temp);
    return dst;
}

void printf_list(char *list[])
{
    int iii = 0;
    for (iii = 0; iii < 30 && list[iii] != NULL; iii++)
    {
        printf("%s\n", list[iii]);
    }
}

//括号
char *deal_bracket(char *str)
{
    //分割
    char *list[30] = { NULL };
    deal_split(str, strlen(str), list);

    char *dst = str_init(); //输出字符串
    char *dst_temp = str_init();
    char *temp = list[0];

    char itoa_temp[10] = {0};

    int i = 0;
    for (i = 1; i < 30 && list[i] != NULL; i++)
    {
        if (*list[i] == '+')
        {
            str_append(&dst, temp);
            str_append(&dst, " + ");
            temp = list[i + 1];
        }
        else if (*list[i] == '-')
        {
            str_append(&dst, temp);
            str_append(&dst, " - ");
            temp = list[i + 1];
        }
        else if (*list[i] == '*')
        {
            str_append(&dst, temp);
            str_append(&dst, " * ");
            temp = list[i + 1];
        }
                else if (*list[i] == '/')
        {
            str_append(&dst, temp);
            str_append(&dst, " / ");
            temp = list[i + 1];
        }
        else if (*list[i] == '(')
        {
            i++;
            str_append(&dst_temp, list[i]);

            i++;
            while (*list[i] != ')')
            {
                str_append(&dst_temp, " ");
                str_append(&dst_temp, list[i]);
                i++;
            }

            char *p1 = deal_mul_div(dst_temp);
            int value = deal_add_sub(p1);

            itoa(value, itoa_temp, 10);
            temp = itoa_temp;
        }
    }
    str_append(&dst, temp);

    str_free(dst_temp);
    return dst;
}

/****************************calculate*****************************/

int main()
{
    char a[100] = "6 / 2 + ( 2 * 5 + 2 * 2 ) - 9 / 3";
    printf("original = %s\n", a);
    char *p = deal_bracket(a);
    printf("bracket  = %s\n", p);
    char *pp = deal_mul_div(p);
    str_free(p);
    printf("mul_div  = %s\n", pp);
    int ppp = deal_add_sub(pp);
    str_free(pp);
    printf("result   = %d\n", ppp);

    return 0;
}
