#include <stdio.h>
#include <stdlib.h>
#include"function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	clearFile();
	User user[100];
	int n=0;
	int choice;
	char choice_1[50];
	int role;
	char input[20];
	do{//role
		show_menu_management();
		do {
		    printf("\tEnter your choice: ");
		    if (fgets(input, sizeof(input), stdin) == NULL) {
		        printf("\tError reading input. Please try again.\n");
		        continue;
		    }
		    input[strcspn(input, "\n")] = '\0';
		
		    if (strlen(input) == 0) {
		        printf("\tChoice cannot be empty. Please enter a valid number.\n");
		        continue;
		    }
		    char *endptr;
		    role = strtol(input, &endptr, 10);
		    if (*endptr != '\0') {
		        printf("\tInvalid choice. Please enter a valid number.\n");
		        continue;
		    }
		    break;
		} while (1);
		if(role==1){
		    do{//user
		    	show_menu_user();
			    do {
				    printf("\tEnter your choice: ");
				    if (fgets(input, sizeof(input), stdin) == NULL) {
				        printf("\tError reading input. Please try again.\n");
				        continue;
				    }
				    input[strcspn(input, "\n")] = '\0';
				    if (strlen(input) == 0) {
				        printf("\tChoice cannot be empty. Please enter a valid number.\n");
				        continue;
				    }
				    char *endptr;
				    choice = strtol(input, &endptr, 10);
				    if (*endptr != '\0') {
				        printf("\tInvalid choice. Please enter a valid number.\n");
				        continue;
				    }
				    break;
				} while (1);	
			    if(choice==1){	
			    	Load_File(user,&n);
			    	Add_user(user,&n);
			    	writeToFile(user,n);
			    	do {
					    printf("\n\tGo back(b) or exit(0): ");
					    fgets(choice_1, sizeof(choice_1), stdin);  
					    choice_1[strcspn(choice_1,"\n")] = '\0'; 
					    if (strlen(choice_1) == 0) {
					        printf("\tOption cannot be empty. Please enter '0' or 'b'.\n");
					        continue;
					    }
					    if (strcmp(choice_1, "0") != 0 && strcmp(choice_1, "b") != 0) {
					        printf("\tInvalid option. Please enter '0' or 'b'.\n");
					    }
					} while (strcmp(choice_1, "0") != 0 && strcmp(choice_1, "b") != 0);
					if(choice_1[0]=='0'){
						break;
					}
					if(choice_1[0]=='b'){
						continue;
					}
				}
				else if(choice==2){
					Load_File(user,&n);
					show_user(user,n);
					do {
					    printf("\n\tGo back(b) or exit(0): ");
					    fgets(choice_1, sizeof(choice_1), stdin);  
					    choice_1[strcspn(choice_1,"\n")] = '\0'; 
					    if (strlen(choice_1) == 0) {
					        printf("\tOption cannot be empty. Please enter '0' or 'b'.\n");
					        continue;
					    }
					    if (strcmp(choice_1, "0") != 0 && strcmp(choice_1, "b") != 0) {
					        printf("\tInvalid option. Please enter '0' or 'b'.\n");
					    }
					} while (strcmp(choice_1, "0") != 0 && strcmp(choice_1, "b") != 0);
					if(choice_1[0]=='0'){
						break;
					}
					if(choice_1[0]=='b'){
						continue;
					}
				}
				else if(choice==3){
					Load_File(user,&n);
					show_user_detail(user,n);
					do {
					    printf("\n\tGo back(b) or exit(0): ");
					    fgets(choice_1, sizeof(choice_1), stdin);  
					    choice_1[strcspn(choice_1,"\n")] = '\0'; 
					    if (strlen(choice_1) == 0) {
					        printf("\tOption cannot be empty. Please enter '0' or 'b'.\n");
					        continue;
					    }
					    if (strcmp(choice_1, "0") != 0 && strcmp(choice_1, "b") != 0) {
					        printf("\tInvalid option. Please enter '0' or 'b'.\n");
					    }
					} while (strcmp(choice_1, "0") != 0 && strcmp(choice_1, "b") != 0);
					if(choice_1[0]=='0'){
						break;
					}
					if(choice_1[0]=='b'){
						continue;
					}
				}
				else if(choice==4){
					
				}
				else if(choice==5){
					
				}
				else if(choice==6){
					
				}
				else if(choice==0){
					break;
				}
				else {
					printf("\tInvalid choice!Please enter again.\n");
				}
			}while(1);
		}
		else if(role==2){
			
		}
		else if(role==0){
			printf("\n\t\t\t   ****** Exit ******");
			printf("\n\t\t\t======Thank you ==========");
			printf("\n\t\t\t======See you soon =======");
			return 0;
		}
		else {
			printf("\tInvalid choose role!\n");
		}
	}while(1);
}

