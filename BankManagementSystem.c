//Bank Management System
//Customer Can Use Phone For All of This

#include <stdio.h>
#include <stdlib.h>

typedef struct date {
    int day;
    int month;
    int year;
};

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
    int pin; //make this up to four
    struct date deposit;
    struct date withdraw;
    struct date date_of_birth;
} add, update, rem, transaction, check, display; //deposit and withdraw are transaction only not add or remove

float interest(float principle, float time, float rate) { //time periods will be in months
    float simple_interest;
    simple_interest = (principle * time * rate) / 100;
    return simple_interest;
}

void create_new_account() { //creates new account and puts it in the file
    FILE *infile;
    infile = fopen("bank.data", "w");
    printf("CREATE NEW ACCOUNT");
    printf("Please Enter Today's Date");
    //date *hinichi = (date*)calloc(1, sizeof(date));
    //scanf("%d/%d/%d", date->month, date->day, date->year); //input the date
    scanf("%d/%d/%d\n", &add.deposit.month, &add.deposit.day, &add.deposit.year); //you have to include & for some reason when its an integer
    printf("Please Enter The Account Number");
    scanf("%d\n", &check.account_number);
    while(fscanf(infile,"Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",&add.account_number,add.name,add.email,&add.date_of_birth.month,
                    &add.account_number,add.name,add.email,
                    &add.date_of_birth.month,
                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                    ,add.account_type, &add.pin)!=EOF) { //fscanf() reads formatted input from the file(stream)
        if (check.account_number != add.account_number) {
            printf("Ready to create account!");
            printf("Enter Name:  ");
            scanf("%s\n", add.name);
            printf("Please Enter Birth Date In Format (Month/Date/Year)");
            scanf("%d/%d/%d\n", &add.date_of_birth.month, &add.date_of_birth.day, &add.date_of_birth_year);
            printf("Enter Age:  ");
            scanf("%d\n", add.age);
            printf("Enter Phone Number:  ");
            scanf("%lf\n", &add.phone);
            printf("Enter Address:  ");
            scanf("%s\n", add.address);
            printf("Add Citizenship No.:  ");
            scanf("%d\n", &add.citizenship);
            printf("Enter Checkings:  ");
            scanf("%d\n", &add.checkings);
            printf("Enter Savings:  ");
            scanf("%d\n", &add.savings);
            printf("Enter Depost $:  ");
            scanf("%f\n", &add.amount);
            printf("Enter Account Type:  ");
            scanf("%s\n", add.account_type);
            printf("Enter New Pin:  ");
            scanf("%d\n", add.pin);
            fprintf(infile, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", &add.account_number,add.name,add.email,
            &add.date_of_birth.month,
            &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
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

void delete_customer() {
    FILE *old_file, new_file;
    old_file = fopen("Bank.Database", "r");
    new_file = fopen("New.Bank.Database", "w")
    printf("Delete Account");
    printf("Please Enter Account Number To Delete ");
    scanf("%d\n", &rem.account_number);
    while (fscanf(old_file,"Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",&add.account_number,add.name,add.email,
            &add.date_of_birth.month,
            &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
            ,add.account_type, &add.pin)!=EOF) {
                if (rem.account_number != add.account_number) {
                    fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                    &add.account_number,add.name,add.email,
                    &add.date_of_birth.month,
                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                    ,add.account_type, &add.pin);
                }
            }
            printf("Successfully Deleted!\n");
            fclose(old_file);
            fclose(new_file);
            remove("Old.Bank.Database");
            rename("Bank.Database", "New.Bank.Database"); //recheck
}

int trans(void) {
    char reply[10];
    int option;
    char *deposit = "deposit";
    char *withdraw = "withdraw";
    FILE *infile;
    FILE *new_file
    infile = fopen("Bank.Database", "r");
    new_file = fopen("New.Bank.Database", "w");
    printf("Please Enter Account Number:  ");
    scanf("%d\n", &transaction.account_number);
    printf("Please Enter Your Pin");
    scanf("%d\n", &transaction.pin);
    if (transaction.pin == add.pin) {
        while(fscanf(infile,"Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                    &add.account_number,add.name,add.email,
                    &add.date_of_birth.month,
                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                    ,add.account_type, &add.pin)!=EOF) {
                    if (transaction.account_number == add.account_number && transaction.pin == add.pin) {
                        printf("Enter 1 for checkings and 2 for savings.\n");
                        scanf("%d\n", &option);//Another If Else Statement For Checking Or Savings
                        if (option == 1) {
                            printf("Would you like to Deposit or Withdraw From Your Checkings Account?\n");
                            scanf("%s\n", reply);
                            if (reply == deposit) {
                                printf("Enter Amount to Deposit From Your Checkings.\n");
                                scanf("%f\n", transaction.checkings);
                                add.checkings += transaction.checkings; 
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                &add.account_number,add.name,add.email,
                                &add.date_of_birth.month,
                                &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                ,add.account_type, &add.pin); 
                                printf("Successfully Deposited %d\n", transaction.checkings);
                            }
                                else if (reply == withdraw) {
                                printf("Enter Amount to Withdraw From Checkings Account\n");
                                scanf("%f\n", transaction.checkings);
                                add.checkings -= transaction.checkings;
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                                &add.account_number,add.name,add.email,
                                &add.date_of_birth.month,
                                &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                ,add.account_type, &add.pin); 
                                printf("Successfully Withdrew %d\n", transaction.checkings);
                        }
                        }
                            else if (option == 2) {
                                printf("Would you like to Deposit or Withdraw");
                                scanf("%s\n", reply);
                                if (reply == deposit) {
                                    printf("Enter Amount to Deposit From Savings\n");
                                    scanf("%f\n", transaction.savings);
                                    add.savings += transaction.savings; 
                                    fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                    ,add.account_type, &add.pin); 
                                    printf("Successfully Deposited %d\n", transaction.savings);
                            }
                                else if (reply == withdraw) {
                                    printf("Enter Amount to Withdraw From Savings\n");
                                    scanf("%f\n", transaction.savings);
                                    add.savings -= transaction.savings;
                                    fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                    ,add.account_type, &add.pin); 
                                    printf("Successfully Withdrew %d\n", transaction.savings);
                        }
    
                    }
                    else if (transaction.account_number != add.account_number) {
                        fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                &add.account_number,add.name,add.email,
                                &add.date_of_birth.month,
                                &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                ,add.account_type, &add.pin);
                        }
                    
                    else {
                        printf("Account Not Found");
                    }
            }
    }
    else {
        printf("Wrong Pin. Please Try Again");
        trans();
        break;
    }    
        fclose(infile);
        fclose(new_file);
        remove("Bank.Database");
        rename("Bank.Database", "New.Bank.Database"); //recheck
}

}
void upd(void) {
    int choice;
    int option;
    FILE *old_file = fopen("Bank.Database", "r");
    FILE *new_file = fopen("New.Database", "r");
    printf("Enter Account No. To Update:  ");
    scanf("%d\n", update.account_number);
    if (update.account_number == add.account_number) {
        while (fscanf(old_file,"Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                    &add.account_number,add.name,add.email,
                    &add.date_of_birth.month,
                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                    ,add.account_type, &add.pin)!=EOF) {
                printf("Enter 0 if you would like to update name, email, citizenship, account_type, or address\n");
                printf("Enter 1 if you would like to update account number, age, phone number, or birthday.\n");
                scanf("%d\n", &choice);
                if (choice == 0) {
                    printf("Enter 1 to update name, 2 to update email, 3 to update citizenship, 4 to update account type, or 5 for address";);
                    scanf("%d\n", &option);
                    switch(option) {
                        case 1: printf("Please Enter Name:  \n");
                                scanf("%s\n", update.name);
                                add.name = update.name;
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                    ,add.account_type, &add.pin);
                                printf("Name Successfully Updated\n");
                        case 2: printf("Please Enter Email:  \n");
                                scanf("%s\n", update.email);
                                add.email = update.email;
                                fprintf(new_file,"Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                    ,add.account_type, &add.pin);
                                printf("Email Successfully Updated!\n");
                        case 3: printf("Please Enter Citizenship:  \n");
                                scanf("%s\n", update.citizenship);
                                add.citizenship = update.citizenship;
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                    ,add.account_type, &add.pin);
                                printf("Citizenship Successfully Updated!\n");
                        case 4: printf("Please Enter Account Type:  \n");
                                scanf("%s\n", update.account_type);
                                add.account_type = update.account_type;
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                    ,add.account_type, &add.pin);
                                printf("Account Type Successfully Updated!\n");
                        case 5: printf("Please Enter Address:  \n");
                                scanf("%s\n", update.address);
                                add.address = update.address;
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                    ,add.account_type, &add.pin);
                                printf("Address Successfully Updated!\n");
                    }
                }
            }
                else if (choice == 1) {
                    printf("Enter 1 to update account number, 2 to update age, 3 to update phone number, or 4 to update your birthday";);
                    scanf("%d\n", &option);
                    switch(option) {
                        case 1: printf("Please Enter Account Number:  \n");
                                scanf("%d\n", update.account_number);
                                add.account_number = update.account_number;
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                    ,add.account_type, &add.pin);
                                printf("Account Number Successfully Updated!\n");
                        case 2: printf("Please Enter Age  \n");
                                scanf("%d\n", update.age);
                                add.account_number = update.age;
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                    ,add.account_type, &add.pin);
                                printf("Age Successfully Updated!\n");
                        case 3: printf("Please Enter Phone Number:  \n");
                                scanf("%d\n", update.phone);
                                add.phone = update.phone;
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", 
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                                    ,add.account_type, &add.pin);
                                printf("Phone Number Successfully Updated!\n");
                        case 4: printf("Please Enter Birth Date:  \n");
                                scanf("%d/%d/%d\n", update.date_of_birth.month, update.date_of_birth.day, update.date_of_birth.year);
                                add.account_number = update.account_number;
                                fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", add.account_number,add.email,add.name,add.date_of_birth.month,
                                    &add.account_number,add.name,add.email,
                                    &add.date_of_birth.month,
                                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                    ,               add.account_type, &add.pin);
                                printf("Birth Date Successfully Updated!\n");

                }

            }
                else {
                    fprintf(new_file, "Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n", add.account_number,add.name,add.date_of_birth.month,
                                add.date_of_birth.day,add.date_of_birth.year,add.age,add.phone,add.address,add.citizenship,add.amount
                                ,add.account_type, add.pin);
                }
    }
}

void display(void) {
    FILE *infile = fopen("Bank.Database", 'r');
    printf("Please Enter Your Account No.: ");
    scanf("%d\n", &display.account_number);
    printf("Please Enter Pin:  ");
    scanf("%d\n", &display.pin);
    if(display.account_number == add.account_number && display.pin == add.account_number) {
        while (fscanf(infile,"Account Number: %d | Name: %s | Email: %s | Birth Date: %d/%d/%d | Age: %d | Phone Number: %d | Address: %s | Citizenship: %s | Savings: %f | Checkings: %f | Account Type: %s | Pin: %d\n",
                    &add.account_number,add.name,add.email,
                    &add.date_of_birth.month,
                    &add.date_of_birth.day,&add.date_of_birth.year,&add.age,&add.phone,add.address,add.citizenship,&add.savings, &add.checking,
                    ,add.account_type, &add.pin)!=EOF) {
                        printf("Checkings: %f\n", add.checkings);
                        printf("Savings: %f\n", add.savings);
                        printf("Enter any number to return to menu.\n");
                        int option;
                        scanf("%d\n", &option);
                        if (option == 0 || 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9 ||) {
                            menu();
                            break;
                        }
                    }
    }
    else {
        printf("Error: Your Account Number or Pin Does Not Work.");
        int choice;
        printf("Please Enter 1 to go back to the menu or 2 to try again.\n");
        scanf("%d\n", &choice);
        if (choice == 1) {
            menu();
            break;
        }
        else if (choice==2) {
            display();
            break;
        }
    }
}

void close(void) {
    printf("Thank you have a good day!\n");
    break;
}

void menu(void) {
    int choice;
    printf("Bank Management System\n");
    printf("Please choose 1 for create new account, 2 for deleting an account, 
    3 for transactions, 4 to go back to the menu, 5 to check your checking or savings accounts, and 6 to close!\n");
    scanf("%d\n"&choice);
    switch(choice) {
        case 1: create_new_account();
        break;
        case 2: delete_customer();
        break;
        case 3: trans();
        break;
        case 4: menu();
        break;
        case 5: display();
        break;
        case 6: close();
        default:
        printf("Please Enter A Digit 1 to 5\n");
        menu();
        break;
    }
}

int main(void) {
    int option;
    printf("Welcome To The Bank Management System!\n");
    printf("Please Enter Any Number To Get Started.\n");
    scanf("%d\n", option);
    if (option == 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9 || 0) {
        menu();
        break;
    }
    else {
        printf("Please Enter A Digit\n");
        main();
        break;
    }
}

            




