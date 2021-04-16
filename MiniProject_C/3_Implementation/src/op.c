#include <header_file.h>

void add_records(FILE *fp){
    fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
            /// here 0 indicates moving 0 distance from the end of the file

            char another = 'y';
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

                fwrite(&e,sizeof(e),1,fp); /// write the record in the file

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
}
void display_records(FILE *fp){
    printf("EMPLOYEE's RECORD LIST (name, id, age, address, salary)");
            rewind(fp); ///this moves file cursor to start of the file
            while(fread(&e,sizeof(e),1,fp)==1)  /// read the file and fetch the record one record per fetch
            {
            	
                printf("\n\n%s \t\t%d \t%s \t%.2f",e.fullname,e.age,e.address,e.basic_salary); /// print the name, age and basic salary
            }
            printf("\n");
            printf("\n Press any key to go to main menu.....\n");
            getch();
}
void modify_records(FILE *fp){
    char another = 'y'; char empname[15];
            while(another == 'y')
            {
                printf("Enter the employee name to modify: ");
                scanf("%s", empname);
                rewind(fp);
                while(fread(&e,sizeof(e),1,fp)==1)  /// fetch all record from file
                {
                    if(strcmp(e.fullname,empname) == 0)  ///if entered name matches with that in file
                    {
                        printf("\nEnter new name, age, address and basic salary: ");
                        scanf("%s%d%s%f",e.fullname,&e.age,&e.address,&e.basic_salary);
                        fseek(fp,-sizeof(e),SEEK_CUR); /// move the cursor 1 step back from current position
                        fwrite(&e,sizeof(e),1,fp); /// override the record
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
           void delete_records(FILE *fp){
           char another = 'y';
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
            }}