#include<stdbool.h>
// cau truc struct
typedef struct{
	int day;
	int month;
	int year;
}Date;

typedef struct{
	char id[20];
	char name[50];
	char email[50];
	char phone[20];
	Date date;
	char birth_date[20];
	char gender[20];
	char balances[20];
	long long balance;
	char username[50];	
	char status[10];
}User;
