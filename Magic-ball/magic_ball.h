/* 2353814 ÂíĞ¡Áú ĞÅ05 */
#pragma once

void menu(char* porder);
void input(int* prow, int* pcolumn);
void base(int* array[][9], int row, int column,char order);
void graph(int* array[][9], int row, int column, char order);
void game(int* array[][9], int row, int column, char order);
void initial(int* array[][9], int row, int column);
void tabulation(int* array[][9], int row, int column, int* pa[][9], int inst);
void judge(int* array[][9], int row, int column, int* pa[][9]);
void fall(int* array[][9], int row, int column, int* pa[][9],char order);
void fill(int* array[][9], int row, int column, int* pa[][9],char order);
int tj_strcasecmp(const char s1[], const char s2[]);
void hint(int* array[][9], int row, int column, int* pa[][9],char order);
void pause_judge();
int equal_num(int* array[][9], int row, int column, int* pa[][9]);

void frame(int row, int column, char order, int* pcol, int* pline, int* pbuffer_col, int* pbuffer_line);
void ball(int* arry[][9], int row, int column, int* pa[][9], char order,int ins=2);
void climinate(int* array[][9], int row, int column, int* pa[][9]);
void cartoon_fall(int* array[][9], int* pa[][9], int X, int Y);
void pad(int* array[][9], int* pa[][9], int X, int Y);

int End_judge(int a[][9], int time, char order);
int mouse_read_judge(int* array[][9], int row, int column, int read_I[], int read_J[]);