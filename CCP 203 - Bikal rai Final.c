#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTR 100
#define LEN 50
#define FILENAME "entries.txt"
#define TEMPFILE "temp.txt"

typedef struct {
    char fname[LEN];
    char lname[LEN];
    char phone[LEN];
    char sex[LEN];
    char email[LEN];
} Entry;

typedef struct {
	char fname[LEN];
	char lname[LEN];
	char sex[LEN];
	char email[LEN];
	char phone[LEN];
} Category;


// functions
int first_render();
int login_opt(); 
int login();
void pass_mask(char pass[9]);
int display_menu();
char operation();
void add_entry();
void list_entries();
void search();
void edit_entry();
void del_entry();
void display_header();


int main () {
	
	int logged_in = 0, render = 1, first_opt, login_menu, login_status, menu_opt;
	
	while(render) {
		start:
		first_opt = first_render();
		
		if(first_opt == 1) {
			while (!logged_in) {
				login_menu = login_opt();
				if(login_menu == 1) {
					login_status = login();
					if (login_status == 1) {
						logged_in = 1;
						while(logged_in) {
							main_menu:
							switch(display_menu()) {
								case 1:
									if(operation() == 1)
									{
										add_entry();
									} else {
										break;
									}
									break;
								case 2:
									list_entries();
									break;
								case 3:
									search();
									break;
								case 4:
									edit_entry();
									break;
								case 5:
									del_entry();
									break;
								case 6:
									printf("\t\t\t\tYou have logged out...");
									getch();
									logged_in = 0;
									break;
								default:
									printf("\t\t\t\tInvalid option!!");
									getch();
									goto main_menu;
							}
						}
					} else {
						logged_in = 0;
					}
				} else if(login_menu == 2) {
					goto start;
				} 
			}
		} else if(first_opt == 2) {
			render = 0;
		} else {
			printf("\t\t\t\tInvalid option!!");
			getch();
		}
	}
	
	
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\tThank you for using the Phonebook Application!!");
	getch();
	return 0;
}

// function to render first render to display first menu
int first_render() {
	int opt;
	system("cls");
	display_header();
	fflush(stdin);
	printf("\t\t\t\t\xdb                                                                                        \xdb\n");
	printf("\t\t\t\t\xdb                                                                                        \xdb\n");
	printf("\t\t\t\t\xdb Welcome to Phonebook Application!!                                                     \xdb\n");
	printf("\t\t\t\t\xdb 1) Login                                                                               \xdb\n");
	printf("\t\t\t\t\xdb 2) Exit                                                                                \xdb\n");
	printf("\t\t\t\t\xdb                                                                                        \xdb\n");
	printf("\t\t\t\t\xdb                                                                                        \xdb\n");
	printf("\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\n\t\t\t\t Enter your choice: ");
	scanf("%d", &opt);
	
	return opt;
	
}


// function for login option or quit
int login_opt() {
	int opt, attempts = 0;
    while (attempts < 3) { // Allow only 3 attempts
        system("cls");
        display_header();
        printf("\t\t\t\t\xdb                                                                                        \xdb\n");
		printf("\t\t\t\t\xdb                                                                                        \xdb\n");
		printf("\t\t\t\t\xdb 1) Enter credentials                                                                   \xdb\n");
		printf("\t\t\t\t\xdb 2) Exit                                                                                \xdb\n");
		printf("\t\t\t\t\xdb                                                                                        \xdb\n");
		printf("\t\t\t\t\xdb                                                                                        \xdb\n");
		printf("\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
		printf("\n\t\t\t\t Enter your choice: ");
        fflush(stdin);
        scanf("%d", &opt);
        if (opt != 1 && opt != 2) {
            printf("\t\t\t\tInvalid option!!\n");
            getch();
            attempts++;
        } else {
            return opt;
        }
    }
    printf("\n\t\t\t\tMaximum attempts reached. Exiting...\n");
    return 2; // to exit program
}


// function to handle login
int login() {
    char username[9], password[9];
    int attempts = 0;
    while (attempts < 3) {
    	
    	system("cls");
    	display_header();
	    fflush(stdin);
	    
	    printf("\n\n\t\t\t\t\t\t\t\t********** Login **********\n");
	    printf("\n\n\n\n\t\t\t\tEnter username:\t");
	    scanf("%s", username);
	    printf("\t\t\t\tEnter password:\t");
	    //scanf("%s", password);
	    pass_mask(password);
	    attempts++;
	    
	    if(strcmp(strlwr(username), "test") == 0 && strcmp(strlwr(password), "test123") == 0) {
	    	system("cls");
	        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t************** Login successful... **************\n");
	        printf("\t\t\t\t\t\t\tpress any key to continue...");
	        getch();
	        return 1;
	    } else {
	    	system("cls");
	        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tIncorrect username or password!!\n");
	        printf("\t\t\t\tpress any key to continue...\n");
	        getch();    
	        
	    }
	}
	
	
	printf("\n\n\t\t\t\tMaximum attempts reached. Exiting...\n");
	getch();
    
}


//function to display menu
int display_menu() {
	system("cls");
	fflush(stdin);
	int option;
	display_header();
	printf("\n\n\n\t\t\t\t1) Add new entry\n\t\t\t\t2) List all entries\n\t\t\t\t3) Search\n\t\t\t\t4) Edit an entry\n\t\t\t\t5) Delete\n\t\t\t\t6) Logout\n");
	printf("\t\t\t\tEnter your choice: ");
	scanf("%d", &option);
	return option;
}

// function to add entry
void add_entry() {
	
	Entry entry;
	FILE *fptr;
	fptr = fopen(FILENAME, "a");
	
	system("cls");
	fflush(stdin);
	display_header();
	printf("\n\n\t\t\t\t\t\t\t\t********** Add new **********\n");
	
	printf("\n\n\t\t\t\tEnter first name:\t");
	scanf("%s", entry.fname);
	printf("\t\t\t\tEnter last name:\t");
	scanf("%s", entry.lname);
	printf("\t\t\t\tEnter phone:\t");
	scanf("%s", entry.phone);
	printf("\t\t\t\tEnter gender:\t");
	scanf("%s", entry.sex);
	printf("\t\t\t\tEnter email:\t");
	scanf("%s", entry.email);
	
	fprintf(fptr, "%s %s %s %s %s\n", strlwr(entry.fname), strlwr(entry.lname), strlwr(entry.sex), strlwr(entry.email), entry.phone);
	

	
	
	printf("\t\t\t\tSuccessfully created new entry...");
	getch();
	
	
	
	fclose(fptr);
}

// function to list all entries
void list_entries() {
	
	char ch[MAXSTR];
	FILE *fptr;
	fptr = fopen(FILENAME, "r");
	
	if (fptr == NULL) {
		system("cls");
		printf("Error!! An error occured!!");
		getch();
	} else {
		system("cls");
		fflush(stdin);
		display_header();
		printf("\n\n\t\t\t\t\t\t\t\t******** All Entries ********\n\n\n");
		
		
		Category cat = {"First name", "Last name", "Gender", "Email", "Phone number"};
		Entry entry;
		while (fscanf(fptr, "%s %s %s %s %s", entry.fname, entry.lname, entry.sex, entry.email, entry.phone) != EOF) {
			
            printf("\t\t\t\t%s:\t%s\n", cat.fname, entry.fname);
            printf("\t\t\t\t%s:\t%s\n", cat.lname, entry.lname);
            printf("\t\t\t\t%s:\t\t%s\n", cat.sex, entry.sex);
            printf("\t\t\t\t%s:\t\t%s\n", cat.email, entry.email);
            printf("\t\t\t\t%s:\t%s\n", cat.phone, entry.phone);
            printf("\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
            
        }
		printf("\n\t\t\t\tPress any key to go continue...");
		getch();
	}
	fclose(fptr);
}

// function to search entry
void search() {
	system("cls");
	
	char query[MAXSTR], str[MAXSTR];
	Entry entry;
	
	FILE *fptr;
	fptr = fopen(FILENAME, "r");
	display_header();
	printf("\n\n\t\t\t\tEnter first name to search:\t");
	scanf("%s", strlwr(query));
	fflush(stdin);
	if (fptr == NULL) {
		system("cls");
		printf("Error!! An error occured!!");
		getch();
	} else {
		fflush(stdin);
		int found = 0;
		Category cat = {"First name", "Last name", "Gender", "Email", "Phone number"};
		while(fscanf(fptr, "%s %s %s %s %s", entry.fname, entry.lname, entry.sex, entry.email, entry.phone) != EOF) {
			if (strcmp(entry.fname, query) == 0) {
				found = 1;
				system("cls");
				display_header();
				printf("\n\n\t\t\t\t%s:\t%s\n", cat.fname, entry.fname);
	            printf("\t\t\t\t%s:\t%s\n", cat.lname, entry.lname);
	            printf("\t\t\t\t%s:\t\t%s\n", cat.sex, entry.sex);
	            printf("\t\t\t\t%s:\t\t%s\n", cat.email, entry.email);
	            printf("\t\t\t\t%s:\t%s\n", cat.phone, entry.phone);
	            printf("\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
            	
			} 
		}
		if(!found) {
			printf("\t\t\t\tNo such entry!!");
		}
		
		printf("\n\t\t\t\tPress any key to continue...");		
		getch();
		
	}
	
	fclose(fptr);
	
}

// function to edit entry
void edit_entry() {
	int found = 0;
	system("cls");
	fflush(stdin);
	char query[MAXSTR], choice[MAXSTR];
	Entry entry;
	FILE *fptr, *temp;
	fptr = fopen(FILENAME, "r");
	temp = fopen(TEMPFILE, "w+");
	display_header();
	printf("\n\n\t\t\t\tEnter first name to edit:\t");
	scanf("%s", query);
	
	if (fptr == NULL || temp == NULL) {
		system("cls");
		printf("\t\t\t\tError!! An error occured!!");
		getch();
	} else {
		Category cat = {"First name", "Last name", "Gender", "Email", "Phone number"};
		while(fscanf(fptr, "%s %s %s %s %s", entry.fname, entry.lname, entry.sex, entry.email, entry.phone) != EOF) {
			//fscanf(fptr, "%s %s %s %s %s", entry.fname, entry.lname, entry.sex, entry.email, entry.phone);
			if(strcmp(entry.fname, strlwr(query)) == 0) {
				system("cls");
				found = 1;
				//printing entry to be edited
				display_header();
				printf("\n\n\t\t\t\t%s:\t%s\n", cat.fname, entry.fname);
	            printf("\t\t\t\t%s:\t%s\n", cat.lname, entry.lname);
	            printf("\t\t\t\t%s:\t\t%s\n", cat.sex, entry.sex);
	            printf("\t\t\t\t%s:\t\t%s\n", cat.email, entry.email);
	            printf("\t\t\t\t%s:\t%s\n", cat.phone, entry.phone);
	            printf("\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
            	printf("\n\t\t\t\tPress any key to continue...\n\n");
				getch();
				
				
				printf("\t\t\t\tDo you want to edit this entry? (y/n)?:\t");
				scanf("%s", strlwr(choice));
				
				//inputting if yes
				if(strcmp(choice, "y") == 0) {
					printf("\t\t\t\tEnter new first name:\t");
					scanf("%s", strlwr(entry.fname));
					printf("\t\t\t\tEnter new last name:\t");
					scanf("%s", strlwr(entry.lname));
					printf("\t\t\t\tEnter new gender:\t");
					scanf("%s", strlwr(entry.sex));
					printf("\t\t\t\tEnter new email:\t");
					scanf("%s", strlwr(entry.email));
					printf("\t\t\t\tEnter new phone:\t");
					scanf("%s", strlwr(entry.phone));
					
					// writing to temporary file
					fprintf(temp, "%s %s %s %s %s\n", entry.fname, entry.lname, entry.sex, entry.email, entry.phone);
				} else if (strcmp(choice, "n") == 0) {
					// writing original file to temp
					fprintf(temp, "%s %s %s %s %s\n", entry.fname, entry.lname, entry.sex, entry.email, entry.phone);
				} else {
					printf("\t\t\t\tInvalid choice!!");
					printf("\t\t\t\tPress any key to continue...");
					getch();
					continue;
				}
			} else {
				// writing original file to temp
				fprintf(temp, "%s %s %s %s %s\n", entry.fname, entry.lname, entry.sex, entry.email, entry.phone);
			}
	
	
		}
		
		fclose(fptr);
        fclose(temp);
        remove(FILENAME);
        rename(TEMPFILE, FILENAME);

        if(found == 1) {
            printf("\t\t\t\tSuccessfully updated entry...");
        } else {
            printf("\t\t\t\tNo such entry found!!");
        }

        getch();
	}
}

//function to delete an entry
void del_entry() {	
	char query[MAXSTR], str[MAXSTR], choice[MAXSTR];
	int found = 0;
	Entry entry;
	FILE *fptr, *temp;
	fptr = fopen(FILENAME, "r");
	temp = fopen(TEMPFILE, "w");
	
	fflush(stdin);
	printf("\t\t\t\tEnter first name to delete entry:\t");
	scanf("%s", query);
	
	if(fptr == NULL || temp == NULL) {
		system("cls");
		printf("\t\t\t\tError!! An error occured!!");
		getch();
	} else {
		Category cat = {"First name", "Last name", "Gender", "Email", "Phone number"};
		while(fscanf(fptr, "%s %s %s %s %s", entry.fname, entry.lname, entry.sex, entry.email, entry.phone) != EOF) {
			if(strcmp(entry.fname, strlwr(query)) == 0) {
				system("cls");
				display_header();
				fflush(stdin);
				found = 1;
				//printing entry to be edited
				printf("\n\n\t\t\t\t%s:\t%s\n", cat.fname, entry.fname);
	            printf("\t\t\t\t%s:\t%s\n", cat.lname, entry.lname);
	            printf("\t\t\t\t%s:\t\t%s\n", cat.sex, entry.sex);
	            printf("\t\t\t\t%s:\t\t%s\n", cat.email, entry.email);
	            printf("\t\t\t\t%s:\t%s\n", cat.phone, entry.phone);
	            printf("\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
            	printf("\n\t\t\t\tPress any key to continue...\n\n");
				getch();
				
				printf("\t\t\t\tDo you want to delete this entry? (y/n)?:\t");
				scanf("%s", strlwr(choice));
				
				if(strcmp(choice, "y") == 0) {
					while(fscanf(fptr, "%s %s %s %s %s", entry.fname, entry.lname, entry.sex, entry.email, entry.phone) != EOF) {
						if(strcmp(entry.fname, strlwr(query)) != 0) {
							// writing to temporary file
							fprintf(temp, "%s %s %s %s %s\n", entry.fname, entry.lname, entry.sex, entry.email, entry.phone);
							
						} else {
							// writing original file to temp
							fprintf(temp, "%s %s %s %s %s\n", entry.fname, entry.lname, entry.sex, entry.email, entry.phone);
						}
						
					}
					printf("\t\t\t\\ntSuccessfully deleted...");
					printf("\n\t\t\t\tPress any key to continue...\n\n");
					getch();
				} else if (strcmp(choice, "n") == 0) {
					// writing original file to temp
					fprintf(temp, "%s %s %s %s %s\n", entry.fname, entry.lname, entry.sex, entry.email, entry.phone);
					printf("\t\t\t\tDid not delete any entry...");
					printf("\n\t\t\t\tPress any key to continue...\n\n");
					getch();
				} else {
					printf("\t\t\t\t\nInvalid choice!!");
					printf("\t\t\t\t\nPress any key to continue...");
					getch();
					continue;
				}
								
			} else {
				// writing original file to temp
				fprintf(temp, "%s %s %s %s %s\n", entry.fname, entry.lname, entry.sex, entry.email, entry.phone);
			}
		}
	}
	fclose(fptr);
	fclose(temp);
	remove(FILENAME);
	rename(TEMPFILE, FILENAME);
	getch();
}

// function to continue operation
char operation() {
	char opt[4];
	system("cls");
	fflush(stdin);
	printf("\n\n\n\n\n\t\t\t\t\t\tDo you want to continue the operation(yes/no)? ");
	scanf("%s", opt);
	if (strcmp(strlwr(opt), "yes") == 0) {
		return 1;
	} else if(strcmp(strlwr(opt), "no") == 0){
		return 2;
	} else {
		printf("\n\n\n\n\t\t\t\t\t\tInvalid option!!");
		getch();
	}
	
}

// function to mask password
void pass_mask(char pass[9]) {
	int i = 0;
	char ch;
	
	while ((i < sizeof(pass)) && (ch = getch()) != '\r') {
		if (ch == '\b') {
			if (i > 0) {
				printf("\b \b");
				i--;
			}
		} else {
			pass[i++] = ch;
			printf("*");
		}
		
	}
	pass[i] = '\0';
}

// function to display application header
void display_header() {
	printf("\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
	printf("\t\t\t\t\xdb                                                                                        \xdb\n");
	printf("\t\t\t\t\xdb                              Phonebook Application                                     \xdb\n");
	printf("\t\t\t\t\xdb                                                                                        \xdb\n");
	printf("\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
}
