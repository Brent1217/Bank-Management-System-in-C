#include <stdio.h>
#include <stdlib.h>


typedef struct date {
    int day;
    int month;
    int year;
} date;

struct{
    char *name;
    char *email;
    int account_number, age;
    double phone;
    char *citizenship;
    char *account_type;
    char *address;
    float checkings;
    float savings;
    int pin; 
    struct date deposit;
    struct date withdraw;
    struct date date_of_birth;
} add, update, rem, transaction, check, display; //deposit and withdraw are transaction only not add or remove


void create_new_account() { //creates new account and puts it in the file
    FILE *infile;
    infile = fopen("Bank.Database", "w");
    int choice;
    printf("Create New Account\n");
    printf("Please Enter Today's Date\n");
    scanf("%d/%d/%d\n", &add.deposit.month, &add.deposit.day, &add.deposit.year); //you have to include & for some reason when its an integer
    printf("Please Enter The Account Number\n");
    scanf("%d\n", &check.account_number);
    while(fscanf(infile,"Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",&add.account_number,add.name,add.email,&add.date_of_birth.month,
                    &add.account_number,add.name,add.email,&add.date_of_birth.month,&add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checkings,add.account_type, &add.pin)!= EOF) { //fscanf() reads formatted input from the file(stream)
        if (check.account_number != add.account_number) {
            printf("Ready to create account!\n");
            printf("Enter Name:  \n");
            scanf("%s\n", add.name);
            printf("Please Enter Birth Date In Format (Month/Date/Year)\n");
            scanf("%d/%d/%d\n", &add.date_of_birth.month, &add.date_of_birth.day, &add.date_of_birth.year);
            printf("Enter Age:  \n");
            scanf("%d\n", add.age);
            printf("Enter Phone Number:  \n");
            scanf("%lf\n", &add.phone);
            printf("Enter Address:  ");
            scanf("%s\n", add.address);
            printf("Add Citizenship No.:  \n");
            scanf("%d\n", &add.citizenship);
            printf("Would you like to make your first deposit into your checkings or savings?\n");
            printf("Please Enter 0 for checkings and 1 for savings\n");
            int decision = scanf("%d\n", &choice);
            printf("Enter Depost $:  \n");
            scanf("%f\n", &transaction.checkings);
            if (decision == 0) {
                add.checkings += transaction.checkings;
            }
            else if (decision == 1) {
                add.savings += transaction.checkings;
            }
            else {
                printf("Please try again\n");
            }
            printf("Enter Account Type:  ");
            scanf("%s\n", add.account_type);
            printf("Enter New Pin:  ");
            scanf("%d\n", add.pin);
            fprintf(infile, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", &add.account_number,add.name,add.email,
            
            &add.date_of_birth.month,&add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.checkings, &add.savings
            ,add.account_type, &add.pin); //store the customer information into the file
            printf("Account Successfully Created!\n");
            
            
        }
        else if (check.account_number == add.account_number) {
            printf("This account is already in use.");
        }
        else {
            printf("ERROR");
        }
    }
    fclose(infile);
}

void delete_customer(void) {
    FILE *old_file;
    FILE *new_file;
    old_file = fopen("Bank.Database", "r");
    new_file = fopen("New.Bank.Database", "w");
    printf("Delete Account\n");
    printf("Please Enter Account Number To Delete \n");
    scanf("%d\n", &rem.account_number);
    while (fscanf(old_file,"Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",&add.account_number,add.name,add.email,
            &add.date_of_birth.month,
            &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checkings,
            add.account_type, &add.pin)!=EOF) {
                if (rem.account_number != add.account_number) {
                    fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                    &add.account_number,add.name,add.email,
                    &add.date_of_birth.month,
                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checkings,
                    add.account_type, &add.pin);
                }
                else {
                    printf("No account found\n");
                    break;
                    
                }
            }
            printf("Successfully Deleted!\n");
            fclose(old_file);
            fclose(new_file);
            remove("Bank.Database");
            rename("New.Bank.Database", "Bank.Database"); 
}

int trans() {
    int reply;
    int option;
    int deposit = 0;
    int withdraw = 1;
    FILE *infile;
    FILE *new_file;
    infile = fopen("Bank.Database", "r");
    new_file = fopen("New.Bank.Database", "w");
    printf("Please Enter Account Number:  \n");
    scanf("%d\n", &transaction.account_number);
    printf("Please Enter Your Pin\n");
    scanf("%d\n", &transaction.pin);
    if (transaction.pin == add.pin) {
        while(fscanf(infile,"Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                    &add.account_number,add.name,add.email,
                    &add.date_of_birth.month,
                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checkings,
                    add.account_type, &add.pin)!=EOF) {
                    if (transaction.account_number == add.account_number && transaction.pin == add.pin) {
                        printf("Enter 1 for checkings and 2 for savings.\n"); //make this so if account type if checkings or savings
                        scanf("%d\n", &option);//Another If Else Statement For Checking Or Savings
                        if (option == 1) {
                            printf("Would you like to Deposit or Withdraw From Your Checkings Account?\n");
                            printf("Enter 0 for deposit and 1 for withdraw\n");
                            scanf("%d\n", &reply);
                            if (reply == deposit) { //they have to enter deposit
                                printf("Enter Amount to Deposit From Your Checkings.\n");
                                scanf("%f\n", transaction.checkings);
                                add.checkings += transaction.checkings; 
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                &add.account_number,add.name,add.email,
                                &add.date_of_birth.month,
                                &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checkings,
                                add.account_type, &add.pin); 
                                printf("Successfully Deposited %d\n", transaction.checkings);
                            }
                                else if (reply == withdraw) {
                                printf("Enter Amount to Withdraw From Checkings Account\n");
                                scanf("%f\n", transaction.checkings);
                                add.checkings -= transaction.checkings;
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                                &add.account_number,add.name,add.email,
                                &add.date_of_birth.month,
                                &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checkings,
                                add.account_type, &add.pin); 
                                printf("Successfully Withdrew %d\n", transaction.checkings);
                        }
                        }
                            else if (option == 2) {
                                printf("Would you like to Deposit or Withdraw");
                                printf("Enter 0 for deposit and 1 for withdraw\n");
                                scanf("%d\n", &reply);
                                if (reply == deposit) {
                                    printf("Enter Amount to Deposit From Savings\n");
                                    scanf("%f\n", transaction.savings);
                                    add.savings += transaction.savings; 
                                    fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checkings,
                                    add.account_type, &add.pin); 
                                    printf("Successfully Deposited %d\n", transaction.savings);
                            }
                                else if (reply == withdraw) {
                                    printf("Enter Amount to Withdraw From Savings\n");
                                    scanf("%f\n", transaction.savings);
                                    add.savings -= transaction.savings;
                                    fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checkings,
                                    add.account_type, &add.pin); 
                                    printf("Successfully Withdrew %d\n", transaction.savings);
                        }
                        else {
                            printf("Please Try Again\n");
                            trans();
                        }
    
                    }
                    else if (transaction.account_number != add.account_number) {
                        fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                &add.account_number,add.name,add.email,
                                &add.date_of_birth.month,
                                &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checkings,
                                add.account_type, &add.pin);
                        }
                    
                    else {
                        printf("Account Not Found\n");
                    }
            }
    }}
    else {
        printf("Wrong Pin");
    }    
        fclose(infile);
        fclose(new_file);
        remove("Bank.Database");
        rename("New.Bank.Database", "Bank.Database"); 
}



void close(void) {
    printf("Thank you have a good day!\n");
}



int main(void) {
    int choice;
    printf("Welcome To The Bank Management System!\n\n");
    printf("Please choose:\n1 for create new account\n2 for deleting an account\n3 for transactions\n4 to close!\n");
    scanf("%d\n", &choice);
    switch(choice) {
        case 1: create_new_account();
        break;
        case 2: delete_customer();
        break;
        case 3: trans();
        break;
        case 4: close();
        break;
        default:
        printf("Please Enter A Digit 1 to 4\n");
        break;
    
    }
}
