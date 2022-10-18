//include header files and libraries
#include "employee.h"
#include "partTimeEmployee.h"
#include "fullTimeEmployee.h"
#include "manager.h"

//defensive programming
#ifndef ROSTER_H
#define ROSTER_H

class roster{
    //this class aggregates and manages all employees
    public:
    roster(); //initialiser
    void input_employees(); //allow user to input employee data
    void roster_employees(); //allow user to input employee rosters
    partTimeEmployee* part_time_employees; //aggregation of all part timers
    fullTimeEmployee* full_time_employees; //aggregation of all full timers
    int employeeCount; //number of part time employees
    int ft_employeeCount; //number of full time employees
    manager Manager; //Manager object
};
#endif
