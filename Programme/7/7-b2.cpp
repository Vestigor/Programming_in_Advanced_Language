/* 2353814 马小龙 信05 */

/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */
#include <iostream>
#include <conio.h>
using namespace std;

#include "7-b2.h"
#include "cmd_console_tools.h"

/* 例：声明仅本源程序文件需要的结构体，不要放到.h中
       仅为示例，不需要可删除 */
struct xxx {
   // ...
};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/
static void len(const char str[],int *pchang)
{
    *pchang = strlen(str);
    if (*pchang % 2==1) 
        *pchang= *pchang+1;
        
   // ...; //仅为示例，不需要可删除
}

static void title_copy(const char str[], char* s,int X)
{
    int len = strlen(str), num = 0, ret = 0;
    int col, line, buffer_col, buffer_line;
    cct_getconsoleborder(col, line, buffer_col, buffer_line);
    for (int i = 0; i < len; i++, s++) {
        if (i + X == buffer_col && ret == 0) {
            if (num % 2 == 0 && (unsigned char)str[i] >= 0xA1 && (unsigned char)str[i] <= 0xFE) {
                *s = ' ';
                i--;
                ret++;
            }
            else
                *s = str[i];
        }
        else{
            *s = str[i];
            if ((unsigned char)str[i] >= 0xA1 && (unsigned char)str[i] <= 0xFE) {
                num++;
                cct_gotoxy(0, 0);
            }
        }
    }
    if (len % 2) {
        *s=' ';
        s++;
    }
    *s = '\0';
}

static void copy(const char str[], char* ps, int min_width, int X)
{
    int num = 0, len = strlen(str), ret = 0;
    int col, line, buffer_col, buffer_line;
    cct_getconsoleborder(col, line, buffer_col, buffer_line);
    for (int i = 0; i < min_width; i++, ps++) {
        if (i == min_width-1) {
            if((num % 2==0&& (unsigned char)str[i] >= 0xA1 && (unsigned char)str[i] <= 0xFE)|| i >= len)
                *ps = ' ';
            else 
                *ps = str[i];
        }
        else if(i+X+3== buffer_col&&ret==0){
            if (num % 2 == 0 && (unsigned char)str[i] >= 0xA1 && (unsigned char)str[i] <= 0xFE || i >= len) {
                *ps = ' ';
                i--;
                min_width--;
                ret++;
            }
            else
                *ps = str[i];
        }
        else if (i < len) {
            *ps = str[i];
            if ((unsigned char)str[i] >= 0xA1 && (unsigned char)str[i] <= 0xFE) {
                num++;
                cct_gotoxy(0, 0);
            }
        }
        else
            *ps = ' ';
    }
    *ps = '\0';
    
}

/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    cct_setcursor(CURSOR_INVISIBLE);
    int in_widen, chang=0, in_high = 10;
    len(original_para->title, &chang);
    if ((original_para->width) % 2==1)
        in_widen = (original_para->width) + 1;
    else
        in_widen = (original_para->width);
    int min_width = in_widen > chang ? in_widen : chang;
    int max_high = (original_para->high) < in_high ? (original_para->high) : in_high;
    char str_title[20] = { 0 };
    title_copy(original_para->title, str_title, original_para->start_x + (4 + min_width) / 2 - chang / 2 -1);
    for(int i=1;i<= 4 + min_width;i+=2){
        if (i == 1)
            cct_showstr(original_para->start_x, original_para->start_y, "╔", original_para->bg_color, original_para->fg_color, 1);
        else if (i >= ((4 + min_width) / 2 - chang / 2) && i < ((4 + min_width) / 2 + chang / 2)) {
            cct_showstr(original_para->start_x + i - 1, original_para->start_y, str_title, original_para->bg_color, original_para->fg_color, 1);
            i += (chang - 2);
        }
        else if(i==3 + min_width)
            cct_showstr(original_para->start_x + i - 1, original_para->start_y, "╗", original_para->bg_color, original_para->fg_color, 1);
        else
            cct_showstr(original_para->start_x + i - 1, original_para->start_y, "═", original_para->bg_color, original_para->fg_color, 1);
    }
    for (int i = 1; i <= max_high; i++) {
        cct_showstr(original_para->start_x, original_para->start_y + i, "║", original_para->bg_color, original_para->fg_color, 1);
        int num = 0;
        char s[MAX_ITEM_LEN+1] = {0};
        copy(menu[i - 1], s, min_width, original_para->start_x);
        cct_showstr(original_para->start_x + 2, original_para->start_y + i, s, original_para->bg_color, original_para->fg_color, 1);
        cout << "║";
    }
    for (int i = 1; i <= 4 + min_width; i += 2) {
        if (i == 1)
            cct_showstr(original_para->start_x, original_para->start_y+ max_high +1, "╚", original_para->bg_color, original_para->fg_color, 1);
        else if (i==3 + min_width)
            cct_showstr(original_para->start_x + i - 1, original_para->start_y+ max_high +1, "╝", original_para->bg_color, original_para->fg_color, 1);
        else
            cct_showstr(original_para->start_x + i - 1, original_para->start_y+ max_high +1, "═", original_para->bg_color, original_para->fg_color, 1);
    }
    int para1 = 1,para2 = 1;
    while (1) {
        int up_down = 0;
        char mark[MAX_ITEM_LEN + 1] = { 0 };
        copy(menu[para1 - 1], mark, min_width, original_para->start_x);
        cct_showstr(original_para->start_x + 2, original_para->start_y + para2, mark, original_para->fg_color, original_para->bg_color, 1);
        while (1) {
            char ret1 = _getch();
            if (ret1 == '\r') {
                cct_setcursor(CURSOR_VISIBLE_NORMAL);
                return para1;
            }
            else if (ret1 == -32) {
                int ret2 = _getch();
                if (ret2 == 72) {
                    up_down = -1;
                    break;
                }
                else if (ret2 == 80) {
                    up_down = 1;
                    break;
                }
            }
        }
        cct_showstr(original_para->start_x + 2, original_para->start_y + para2, mark, original_para->bg_color, original_para->fg_color, 1);
        if (up_down == -1) {

            if (para2 >= 2)
                para2--;
            else if (para2 == 1 && para1 != 1) {
                for (int i = para1 - 1,j=1; j<= max_high; i++,j++) {
                    int tmp[MAX_ITEM_LEN + 1] = { 0 };
                    copy(menu[i - 1], mark, min_width, original_para->start_x);
                    cct_showstr(original_para->start_x + 2, original_para->start_y + j, mark, original_para->bg_color, original_para->fg_color, 1);
                }
            }
            if (para1 >= 2)
                para1--;
        }
        else if(up_down ==1) {
            if (para2 < max_high)
                para2++;
            else if (para2 == max_high && para1 != 10) {
                for (int i = para1+1, j = max_high; j >= 1; i--, j--) {
                    int tmp[MAX_ITEM_LEN + 1] = { 0 };
                    copy(menu[i - 1], mark, min_width, original_para->start_x);
                    cct_showstr(original_para->start_x + 2, original_para->start_y + j, mark, original_para->bg_color, original_para->fg_color, 1);
                }
            }
            if (para1 <= 9)
                para1++;
        }
    }
   

	return 0; //按需返回
}
