#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <string.h>  

/*
*@brief: Creation of the main
*/
int main()
{
    char username[15]; 
    char password[12]; 
 
 
    printf("-----------------Enter your username:----------------------\n"); 
    scanf("%s",&username); 
 
    printf("-----------------Enter your password:-----------------------\n"); 
    scanf("%s",&password); 
 
    if(strcmp(username,"265104")==0){ 
        if(strcmp(password,"265104")==0){ 
 
        printf("\nLogin Successful!"); 
 
 
        }else{ 
    printf("\nWrong password"); 
} 
    }else{ 
    printf("\nUsername doesn't exist"); 
} 


	int i=0;
    FILE *fp, *ft; /// file pointers
    char another, choice;
    struct emp
    {
        char fullname[40]; ///full name of employee
        int age; // age of employee
        char address[20];//address of employee
        float basic_salary; // basic salary of employee
    };

    struct emp e; /// structure variable creation

    char empname[40]; /// string to store name of the employee

    long int recsize; /// size of each record of employee

    /** open the file in binary read and write mode
    * if the file employee.DAT already exists then it opens that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    fp = fopen("employee.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("employee.DAT","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
    // sizeo of each record i.e. size of structure variable e
    recsize = sizeof(e);

    // infinite loop continues untile the break statement is encountered
    while(1)
    {
    	
        system("cls"); ///clear the console window 
        printf("\n   ==========================             |WELCOME|           ========================== \n");
        printf(" \n  ::::::::::::::::::::::::::  |EMPLOYEES MANAGEMENT SYSTEM|  :::::::::::::::::::::::::: \n");
		printf("1> Add Employee's Records\n"); /// option for add record
        printf("2> List Employee's Records\n"); /// option for showing existing record
        printf("3> Modify Employee's Records\n"); /// option for editing record
        printf("4> Delete Employee's Records\n"); /// option for deleting record
        printf("5> Exit System\n"); /// exit from the program
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        choice  = getche(); /// get the input from keyboard
        switch(choice)
        
        
        {
        case '1':  /// if user press 1
            system("cls");
            fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
            /// here 0 indicates moving 0 distance from the end of the file

            another = 'y';
            while(another == 'y')  /// if user want to add another record
            {
                printf("\nEnter full name with underscore: ");
                scanf("%s",e.fullname);
                printf("\nEnter age: ");
                scanf("%d", &e.age);
                printf("\nEnter Address:");
                scanf("%s",e.address);
                printf("\nEnter basic salary: ");
                scanf("%f", &e.basic_salary);

                fwrite(&e,recsize,1,fp); /// write the record in the file

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
            case '2':
            system("cls");
            printf("EMPLOYEE's RECORD LIST (name, id, age, address, salary)");
            rewind(fp); ///this moves file cursor to start of the file
            while(fread(&e,recsize,1,fp)==1)  /// read the file and fetch the record one record per fetch
            {
            	
                printf("\n\n%s \t\t%d \t%s \t%.2f",e.fullname,e.age,e.address,e.basic_salary); /// print the name, age and basic salary
            }
            printf("\n");
            printf("\n Press any key to go to main menu.....\n");
            getch();
            break;

        case '3':  /// if user press 3 then do editing existing record
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the employee name to modify: ");
                scanf("%s", empname);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file
                {
                    if(strcmp(e.fullname,empname) == 0)  ///if entered name matches with that in file
                    {
                        printf("\nEnter new name, age, address and basic salary: ");
                        scanf("%s%d%s%f",e.fullname,&e.age,&e.address,&e.basic_salary);
                        fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                        fwrite(&e,recsize,1,fp); /// override the record
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of employee to delete: ");
                scanf("%s",empname);
                ft = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                rewind(fp); /// move record to starting of file
                while(fread(&e,recsize,1,fp) == 1)  /// read all records from file
                {
                    if(strcmp(e.fullname,empname) != 0)  /// if the entered record match
                    {
                        fwrite(&e,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("employee.DAT"); /// remove the orginal file
                rename("Temp.dat","employee.DAT"); /// rename the temp file to original file name
                fp = fopen("employee.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            fclose(fp);  /// close the file
            exit(0); /// exit from the program
        }
    }
    return 0;
}
