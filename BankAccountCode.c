#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

void checkbalance(char*);
void transfermoney(void);
void display(char*);
void login(void);
void account(void);
void accountcreated(void);
void logout(void);

struct pass {
    char username[50];
    int date, month, year;
    char pnumber[15];
    char dlnum[20]; // Changed from adharnum to dlnum
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
    char typeaccount[20];
};

struct money {
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};

struct userpass {
    char password[50];
};

int main() {
    int choice;

    printf("WELCOME TO AMARTYA'S BANK PVT LTD. INTERNET BANKING SYSTEM\n\n");
    printf("******************************************************************************\n");
    printf("1.... CREATE A BANK ACCOUNT\n");
    printf("2.... ALREADY A USER? SIGN IN\n");
    printf("3.... EXIT\n\n");

    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\n\n USERNAME 50 CHARACTERS MAX!!");
            printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
            account();
            break;
        case 2:
            login();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    return 0;
}

void account(void) {
    char password[50];
    FILE *fp;
    struct pass u1;
    struct userpass p1;

    fp = fopen("username.txt", "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n\n!!!!!CREATE ACCOUNT!!!!!\n");

    printf("FIRST NAME: ");
    scanf("%s", u1.fname);

    printf("LAST NAME: ");
    scanf("%s", u1.lname);

    printf("FATHER's NAME: ");
    scanf("%s", u1.fathname);

    printf("MOTHER's NAME: ");
    scanf("%s", u1.mothname);

    printf("ADDRESS: ");
    scanf("%s", u1.address);

    printf("ACCOUNT TYPE: ");
    scanf("%s", u1.typeaccount);

    printf("DATE OF BIRTH (DD MM YYYY): ");
    scanf("%d %d %d", &u1.date, &u1.month, &u1.year);

    printf("DRIVERS LICENSE NUMBER: ");
    scanf("%s", u1.dlnum);

    printf("PHONE NUMBER: ");
    scanf("%s", u1.pnumber);

    printf("USERNAME: ");
    scanf("%s", u1.username);

    printf("PASSWORD: ");
    scanf("%s", password);
    strcpy(p1.password, password);

    fwrite(&u1, sizeof(u1), 1, fp);
    fwrite(&p1, sizeof(p1), 1, fp);

    fclose(fp);
    accountcreated();
}

void accountcreated(void) {
    printf("PLEASE WAIT.... YOUR DATA IS PROCESSING....\n");
    for (int i = 0; i < 200000000; i++) {
        i++;
        i--;
    }

    printf("ACCOUNT CREATED SUCCESSFULLY....\n");
    printf("Press enter to login");
    getchar(); // Consume the newline character left by scanf
    getchar(); // Wait for user to press enter
    login();
}

void login(void) {
    char username[50];
    char password[50];
    FILE *fp;
    struct pass u1;
    struct userpass p1;

    fp = fopen("username.txt", "rb");
    if (fp == NULL) {
        printf("ERROR IN OPENING FILE\n");
        return;
    }

    printf("ACCOUNT LOGIN\n");
    printf("USERNAME: ");
    scanf("%s", username);

    printf("PASSWORD: ");
    scanf("%s", password);

    while (fread(&u1, sizeof(u1), 1, fp)) {
        fread(&p1, sizeof(p1), 1, fp);
        if (strcmp(username, u1.username) == 0 && strcmp(password, p1.password) == 0) {
            fclose(fp);
            display(username);
            return;
        }
    }

    fclose(fp);
    printf("\n\nInvalid username or password. Please try again.\n");
}

void display(char username1[]) {
    FILE* fp;
    int choice;
    struct pass u1;

    fp = fopen("username.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fread(&u1, sizeof(u1), 1, fp)) {
        if (strcmp(username1, u1.username) == 0) {
            printf("\nWELCOME, %s %s\n", u1.fname, u1.lname);
            printf("=====================================\n");
            printf("NAME: %s %s\n", u1.fname, u1.lname);
            printf("FATHER's NAME: %s\n", u1.fathname);
            printf("MOTHER's NAME: %s\n", u1.mothname);
            printf("DRIVERS LICENSE NUMBER: %s\n", u1.dlnum);
            printf("MOBILE NUMBER: %s\n", u1.pnumber);
            printf("DATE OF BIRTH: %d-%d-%d\n", u1.date, u1.month, u1.year);
            printf("ADDRESS: %s\n", u1.address);
            printf("ACCOUNT TYPE: %s\n", u1.typeaccount);
            printf("=====================================\n");
        }
    }

    fclose(fp);

    printf("\n HOME \n");
    printf("1....CHECK BALANCE\n");
    printf("2....TRANSFER MONEY\n");
    printf("3....LOG OUT\n");
    printf("4....EXIT\n\n");

    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            checkbalance(username1);
            break;
        case 2:
            transfermoney();
            break;
        case 3:
            logout();
            login();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            display(username1);
            break;
    }
}

void transfermoney(void) {
    int i, j;
    FILE *fm, *fp;
    struct pass u1;
    struct money m1;
    char usernamet[50];
    char usernamep[50];

    fp = fopen("username.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fm = fopen("mon.txt", "ab");
    if (fm == NULL) {
        printf("Error opening file!\n");
        fclose(fp);
        return;
    }

    printf("---- TRANSFER MONEY ----\n");

    printf("FROM (your username): ");
    scanf("%s", usernamet);

    printf("TO (username of person): ");
    scanf("%s", usernamep);

    while (fread(&u1, sizeof(u1), 1, fp)) {
        if (strcmp(usernamep, u1.username) == 0) {
            strcpy(m1.usernameto, u1.username);
            strcpy(m1.userpersonfrom, usernamet);
            break;
        }
    }

    printf("ENTER THE AMOUNT TO BE TRANSFERRED: ");
    scanf("%ld", &m1.money1);

    fwrite(&m1, sizeof(m1), 1, fm);

    printf("transferring amount, Please wait...\n");

    for (i = 0; i < 70; i++) {
        for (j = 0; j < 1200000; j++) {
            j++;
            j--;
        }
        printf("*");
        fflush(stdout);
    }

    printf("\nAMOUNT SUCCESSFULLY TRANSFERRED....\n");

    fclose(fp);
    fclose(fm);

    display(usernamet);
}

void checkbalance(char username2[]) {
    FILE *fm;
    struct money m1;
    int i = 1, summoney = 0;

    fm = fopen("mon.txt", "rb");
    if (fm == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("==== BALANCE DASHBOARD ====\n");
    printf("S no.\tTRANSACTION ID\tAMOUNT\n");

    while (fread(&m1, sizeof(m1), 1, fm)) {
        if (strcmp(username2, m1.usernameto) == 0) {
            printf("%d\t%s\t%ld\n", i, m1.userpersonfrom, m1.money1);
            i++;
            summoney += m1.money1;
        }
    }

    printf("TOTAL AMOUNT: %d\n", summoney);

    fclose(fm);
    display(username2    );
}

void logout(void) {
    int i, j;
    printf("please wait, logging out");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 25000000; j++) {
            i++;
            i--;
        }
        printf(".");
        fflush(stdout);
    }

    printf("\nSign out successfully..\n");
    printf("Press enter to continue..");

    getchar(); // Consume the newline character left by previous input
    getchar(); // Wait for user to press enter
}