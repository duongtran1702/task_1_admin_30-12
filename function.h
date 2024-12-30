#include"datatype.h"
#include<string.h>
#include<ctype.h>
//nguyen mau ham
void show_menu_management();
void show_menu_user();
int valid_digits(const char *input,int minlength,const char *message);
void Load_File(User *user,int *n);
void writeToFile(User *user,int n);
int valid_letters(const char *input, const char *message);
void format_1st(char *name);
void format_2nd(char *name);
int validate_email(const char *email);
int isLeapYear(int year);
int valid_date(int day, int month, int year);
void format_date(int day, int month, int year, char *birth_date);
long long format_to_ll(const char *str);
int check_user_by_id(User *user, int n, char *input);
int check_user_by_email(User *user, int n, char *input);
int check_user_by_phone(User *user, int n, char *input);
int input_number(const char *input);


void Add_user(User *user,int *n);
void show_user(User *user,int n);
void clearFile();
void show_user_detail(User *user,int n);



















































