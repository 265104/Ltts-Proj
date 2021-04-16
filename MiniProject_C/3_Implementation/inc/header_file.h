/** 
* @file header_file.h
* Employee Management System
*/
#ifndef __EMS_H__
#define __EMS_H__

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/**
 * @brief Structure to accept employee details
 */
struct emp
    {
        char fullname[40]; ///full name of employee
        int age; // age of employee
        char address[20];//address of employee
        float basic_salary; // basic salary of employee
    };

    struct emp e; /// structure variable creation

    void add_records();
    void display_records();
    void modify_records();
    void delete_records();

#endif  /* #define __EMS_H__ */