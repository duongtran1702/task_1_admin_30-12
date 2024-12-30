#include"function.h"
#include<stdio.h>
#include<stdlib.h>
//logic ham
void show_menu_management() {
    printf("\n****Bank Account Management Using C****\n");
    printf("\n\t    CHOOSE YOUR ROLE\n");
    printf("\t======================\n");
    printf("\t[1]. Admin\n");
    printf("\t[2]. User\n");
    printf("\t[0]. Exit the program\n");
    printf("\t======================\n");
}
void show_menu_user(){
	printf("\n ****User Management System Using C****\n");
    printf("\n\t    	MENU\n");
    printf("\t======================\n");
    printf("\t[1]. Add a new user\n");
    printf("\t[2]. Show all users\n");
    printf("\t[3]. Show detail an user\n");
    printf("\t[4]. Lock (unlock) an user\n");
    printf("\t[5]. User guideline\n");
    printf("\t[6]. About us\n");
    printf("\t[0]. Exit the program\n");
    printf("\t======================\n");
}
void Load_File(User *user,int *n){
	FILE*f=fopen("users.dat","rb");
	if(f==NULL){
		//printf("Can not open file!\n");
		return;
	}
	fseek(f,0,SEEK_END);
	int size=ftell(f);
	if(size==0){
		*n=0;
		fclose(f);
		return;
	}
	*n=size/sizeof(User);
	rewind(f);
	fread(user,sizeof(User),*n,f);
	fclose(f);
}
void writeToFile(User *user,int n){
	FILE*f=fopen("users.dat","wb");
	if(f==NULL){
		printf("Can not open file!\n");
		return;
	}
	fwrite(user,sizeof(User),n,f);
	fclose(f);
}
int valid_digits(const char *input,int minlength,const char *message){
	if (input == NULL) {
        printf("\t%s cannot be empty.Please enter again.\n",message,minlength);
        return 0;
    }
	size_t len=strlen(input);
	if (len ==0) {
        printf("\t%s cannot be empty.Please enter again.\n",message,minlength);
        return 0; 
    }
	if(len<minlength){
		printf("\t%s must be less than %d characters.Please enter again.\n",message,minlength);
		return 0;
	}
	for(int i=0;i<len;i++){
		if(!isdigit(input[i])){
			printf("\t%s contains invalid characters.Please enter again.\n",message);
			return 0;
		}
	}
	return 1;
}
int valid_letters(const char *input, const char *message) {
    size_t len = strlen(input);
    if (len == 0) {
        printf("\t%s cannot be empty. Please enter again.\n", message);
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha((unsigned char)input[i]) && !isspace((unsigned char)input[i])) {
            printf("\t%s contains invalid characters. Please enter again.\n", message);
            return 0;
        }
    }
    return 1;
}

void format_2nd(char *name){
	size_t len=strlen(name);
	int new_word=1;
	for(int i=0;i<len;i++){
		if(isspace(*(name+i))){
			new_word=1;
		}
		else if(new_word==1){
			*(name+i)=toupper(*(name+i));
			new_word=0;
		}
		else{
			*(name+i)=tolower(*(name+i));
		}
	}
}
void format_1st(char *name){   
	size_t len=strlen(name);
	int i=0;
	int j=0;
	int space_found=0;
	while(isspace(name[i])) i++;
	for(;i<len;i++){
		if(!isspace(name[i])){
			name[j++]=name[i];
			space_found=0;
		}
		else if(space_found==0){
			name[j++]=' ';
			space_found=1;
		}
	}
	if(j>0&&name[j-1]==' '){
		j-=1;
	}
	name[j]='\0';
}

int validate_email(const char *email) {
    const char *at_sign = strchr(email, '@');
    if (!at_sign) {
        printf("\tInvalid email: Missing '@' symbol.\n");
        return 0;
    }
    if (at_sign == email) {
        printf("\tInvalid email: Missing username before '@'.\n");
        return 0;
    }
    if (*(at_sign + 1) == '\0') {
        printf("\tInvalid email: Missing domain after '@'.\n");
        return 0;
    }
    if (strchr(at_sign + 1, '@')) {
        printf("\tInvalid email: Contains more than one '@'.\n");
        return 0;
    }
    const char *domain = at_sign + 1;
    if (strlen(domain) < 3 || !strchr(domain, '.') || domain[strlen(domain) - 1] == '.'||domain[strlen(domain) - 2] == '.'||domain[strlen(domain) - 3] == '.'||domain[0] == '.') {
       	printf("\tInvalid email: Invalid domain or missing at least 3 characters after the dot, or domain starts with a dot.\n");
	    return 0;
    }
    for (int i = 0; email[i] != '\0'; i++) {
	    if (email[i] =='@'|| email[i] =='.'||isalnum(email[i])||email[i] =='-'||email[i] == '_') {
	        continue;
	    }
	    printf("\tInvalid email: Contains invalid characters.\n");
	    return 0;
	}
    return 1;
}
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}
int valid_date(int day, int month, int year) {
    if (year< 1) {
        printf("\tInvalid year. Please enter a positive year.\n");
        return 0;
    }
    if (month< 1 || month > 12) {
        printf("\tInvalid month. Please enter a month between 1 and 12.\n");
        return 0;
    }
    int days[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > days[month - 1]) {
        printf("\tInvalid day. Month %d of year %d has %d days.Please enter again.\n",month,year,days[month-1]);
        return 0;
    }
    return 1;
}
void format_date(int day, int month, int year, char *birth_date) {
    sprintf(birth_date,"%d/%d/%d", day, month, year); 
}
long long format_to_ll(const char *str) {
    return atoll(str); 
}
int input_number(const char *input) {
    int number;
    char content[50];
    while (1) {
        printf("\tEnter the %s: ",input);
        fgets(content,50,stdin);
        
        content[strcspn(content, "\n")] = '\0';
        if (content[0] == '\0') {
            printf("\tThe %s cannot be empty. Please enter again.\n",input);
            continue;
        }
        number= atoi(content);
        if (number == 0 && strcmp(content, "0") != 0) {
            printf("\tInvalid %s. Please enter a valid number.\n",input);
        } else {
            return number;
        }
    }
}
int check_user_by_id(User *user, int n, char *input) {
    for (int i = 0; i < n; i++) {
        if (strcmp(user[i].id, input) == 0) {
            return i;
        }
    }
    return -1;
}
int check_user_by_email(User *user, int n, char *input) {
    for (int i = 0; i < n; i++) {
        if (strcmp(user[i].email, input) == 0) {
            return i;
        }
    }
    return -1;
}
int check_user_by_phone(User *user, int n, char *input) {
    for (int i = 0; i < n; i++) {
        if (strcmp(user[i].phone, input) == 0) {
            return i;
        }
    }
    return -1;
}
int check_user_by_username(User *user, int n, char *input) {
    for (int i = 0; i < n; i++) {
        if (strcmp(user[i].username, input) == 0) {
            return i;
        }
    }
    return -1;
}
int check_user_by_name(User *user, int n, char *input) {
    for (int i = 0; i < n; i++) {
        if (strcmp(user[i].name, input) == 0) {
            return i;
        }
    }
    return -1;
}
void show_user_1(User *user, int n, char *input){
	printf("\n=================================================================================\n");
	printf("|    %-*s|      %-*s|",6,"ID",14,"Name");
	printf("        %-*s|  %-*s| %-*s |\n",17,"Email",10,"Phone",4,"Status");
	printf("=================================================================================\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(user[i].name, input) == 0) {
           	printf("|%-*s|%-*s|",10,user[i].id,20,user[i].name);
			printf("%-*s|%-*s|%-*s|\n",25,user[i].email,12,user[i].phone,8,user[i].status);
			printf("---------------------------------------------------------------------------------\n"); 
        }
    }
}


void Add_user(User *user,int *n){
	char content[50];
	int check;
	printf("\n\t**** Add an user ****\n\n");
	do{	
		do{	//ID
			printf("\tEnter the ID:");
			fgets(content,50,stdin);
			content[strcspn(content,"\n")]='\0';
		}while(valid_digits(content,4,"ID")==0);
		format_1st(content);
		check=check_user_by_id(user,*n,content);
		if(check==-1){
			strcpy(user[*n].id,content);
		}
		if(check!=-1){
			printf("\tID already exists!\n");
		}
	}while(check!=-1);
	//name
	do{
		printf("\tEnter the name:");
		fgets(content,50,stdin);
		content[strcspn(content,"\n")]='\0';
	}while(valid_letters(content,"Name")==0);
	strcpy(user[*n].name,content);
	format_1st(user[*n].name);
	format_2nd(user[*n].name);	
	//Email
	do{
		do{
			printf("\tEnter the email:");
			fgets(content,50,stdin);
			content[strcspn(content,"\n")]='\0';
		}while(validate_email(content)==0);
		format_1st(content);
		check=check_user_by_email(user,*n,content);
		if(check==-1){
			strcpy(user[*n].email,content);
		}
		if(check!=-1){
			printf("\tEmail already exists!\n");
		}
	}while(check!=-1);
	//phone
	do{
		do{
			do{
				printf("\tEnter the phone number:");
				fgets(content,50,stdin);
				content[strcspn(content,"\n")]='\0';
				if(strlen(content)>12){
					printf("\tPhone number is too long.Please enter again.\n");
					continue;
				}
			}while(strlen(content)>12);	
		}while(valid_digits(content,10,"Phone number")==0);
		format_1st(content);
		check=check_user_by_phone(user,*n,content);
		if(check==-1){
			strcpy(user[*n].phone,content);
		}
		if(check!=-1){
			printf("\tPhone number already exists!\n");
		}
	}while(check!=-1);

	do{//gender
		printf("\tChoose the gender:\n");
		printf("\ta. Male.\n");
		printf("\tb. Female.\n");
		char option[50];
	    do {
	        printf("\tEnter the option: ");
	        fgets(option, sizeof(option), stdin);
	        option[1] = '\0'; 
	        if (option[0] == '\n' || option[0] == '\0') {
	            printf("\tNo option entered. Please enter 'a' or 'b'.\n");
	        } else if (option[0] != 'a' && option[0] != 'b') {
	            printf("\tInvalid option. Please enter 'a' or 'b'.\n");
	        }
	    } while (option[0] != 'a' && option[0] != 'b');
		if(option[0]=='a'){
			strcpy(user[*n].gender,"Male");
			break;
		}
		if(option[0]=='b'){
			strcpy(user[*n].gender,"Female");
			break;
		}
	}while(1);
	
	do{//date
        printf("\tEnter the date of birth:\n");
        user[*n].date.day = input_number("day");
        user[*n].date.month = input_number("month");
        user[*n].date.year = input_number("year");
	}while(valid_date(user[*n].date.day,user[*n].date.month,user[*n].date.year)==0);
	format_date(user[*n].date.day,user[*n].date.month,user[*n].date.year,user[*n].birth_date);

	//username
	do{
		printf("\tEnter the username:");
		fgets(content,50,stdin);
		content[strcspn(content,"\n")]='\0';
		if (content[0] == '\0') {
	        printf("\tUsername cannot be empty. Please enter a valid username.\n");
	        continue;
  		}
  		format_1st(content);
		check=check_user_by_username(user,*n,content);
		if(check==-1){
			strcpy(user[*n].username,content);
		}
		if(check!=-1){
			printf("\tUser name already exists!\n");
		}
	}while(check!=-1);
	
	do{//balace
		printf("\tEnter the balance:");
		fgets(content,50,stdin);
		content[strcspn(content,"\n")]='\0';
	}while(valid_digits(content,1,"Balance")==0);
	format_1st(content);
	strcpy(user[*n].balances,content);
	user[*n].balance=format_to_ll(user[*n].balances);
    strcpy(user[*n].status, "Open");  
	*n+=1;
	printf("\tUser added successfully!\n");
}
void show_user(User *user,int n){
	printf("\n\t\t\t\t**** Show all users ****\n\n");
	printf("\n=================================================================================\n");
	printf("|    %-*s|      %-*s|",6,"ID",14,"Name");
	printf("        %-*s|  %-*s| %-*s |\n",17,"Email",10,"Phone",4,"Status");
	printf("=================================================================================\n");
	for(int i=0;i<n;i++){
	printf("|%-*s|%-*s|",10,user[i].id,20,user[i].name);
	printf("%-*s|%-*s|%-*s|\n",25,user[i].email,12,user[i].phone,8,user[i].status);
	printf("---------------------------------------------------------------------------------\n"); 
	}
}
void clearFile() {
    FILE *f = fopen("users.dat", "wb"); 
    if (f == NULL) {
        printf("Cannot open file to clear!\n");
        return;
    }
    fclose(f);
}











void show_user_detail(User *user,int n){
	char content[50];
	printf("\n\t\t\t**** Show user details ****\n\n");
	printf("\tEnter your choice:\n");
	printf("\ta. Search by name.\n");
	printf("\tb. Search by ID.\n");
	char option[50];
    do {
        printf("\tEnter the option: ");
        fgets(option, 50, stdin);
        option[1] = '\0';
        if (option[0] == '\n' || option[0] == '\0') {
            printf("\tNo option entered. Please enter 'a' or 'b'.\n");
        } else if (option[0] != 'a' && option[0] != 'b') {
            printf("\tInvalid option. Please enter 'a' or 'b'.\n");
        }
    } while (option[0] != 'a' && option[0] != 'b');
    if(option[0]=='a'){
		do{
			printf("\tEnter the name to search: ");
			fgets(content,50,stdin);
			content[strcspn(content,"\n")]='\0';
		}while(valid_letters(content,"Name")==0);
		format_1st(content);
		format_2nd(content);
		int check=check_user_by_name(user,n,content);
		if(check==-1){
			printf("\tName %s does not exist!\n",content);
		}
		else{
			show_user_1(user,n,content);
		}
	}
	if(option[0]=='b'){
		do{
			printf("\tEnter the ID to search: ");
			fgets(content,50,stdin);
			content[strcspn(content,"\n")]='\0';
		}while(valid_digits(content,4,"ID")==0);
		format_1st(content);
		int check=check_user_by_id(user,n,content);
		if(check==-1){
			printf("\tID %s does not exist!\n",content);
		}
		else{
			printf("\n=================================================================================================\n");
			printf("|    %-*s|      %-*s|",6,"ID",14,"Name");
			printf("        %-*s|  %-*s|  %-*s| %-*s |\n",17,"Email",10,"Phone",13,"Username",4,"Status");
			printf("=================================================================================================\n");
			printf("|%-*s|%-*s|",10,user[check].id,20,user[check].name);
			printf("%-*s|%-*s|%-*s|%-*s|\n",25,user[check].email,12,user[check].phone,15,user[check].username,8,user[check].status);
			printf("-------------------------------------------------------------------------------------------------\n"); 
		}
	}
}


























