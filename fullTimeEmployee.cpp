#include <iostream>
#include "employee.h"
#include "fullTimeEmployee.h"

fullTimeEmployee::fullTimeEmployee(std::string name, int ID, int mySalary){
    //countAvailability(availability);
    //unavailability = setAvailability(unavailability_count, availability);
    salary = mySalary;
    this->firstName = name;
    this->maxHours = 38;
    this->id = ID;
}

fullTimeEmployee::fullTimeEmployee(std::string name, int ID){
    //countAvailability(availability);
    //unavailability = setAvailability(unavailability_count, availability);
    salary = 42255;
    this->firstName = name;
    this->maxHours = 38;
    this->id = ID;
}

fullTimeEmployee::fullTimeEmployee(){
    this->firstName = "N/A";
    this->maxHours = -1;
    this->id = 0;
    //this->mySchedule = schedule();
}
void fullTimeEmployee::setData(std::string name, int ID, int mySalary){

    //std::cout << "attempt made";
    this->firstName = name;
    this->maxHours = 38;
    this->id = ID;
    this->salary = mySalary;
    //this->mySchedule = schedule();
}
void fullTimeEmployee::setData(std::string name, int ID){
    //std::cout << "attempt made";
    this->firstName = name;
    this->maxHours = 38;
    this->id = ID;
    //this->mySchedule = schedule();
}

void fullTimeEmployee::call_off(int day, int shift){
    std::cout << "Yeezus";
}
