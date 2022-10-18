#include "employee.h"
#include "partTimeEmployee.h"
#include "schedule.h"
#include <iostream>
partTimeEmployee::partTimeEmployee(std::string name, int max_hours, int ID){
    //countAvailability(availability);
    //unavailability = setAvailability(unavailability_count, availability);
    this->firstName = name;
    this->maxHours = max_hours;
    this->id = ID;
}
partTimeEmployee::partTimeEmployee(){
    this->firstName = "N/A";
    this->maxHours = -1;
    this->id = 0;
    //this->mySchedule = schedule();
}
partTimeEmployee::partTimeEmployee(std::string name, int max_hours, int ID, int hourly_rate){
    //std::cout << "attempt made";
    mySchedule = schedule();
    hourly_wage = hourly_rate;
    firstName = name;
    maxHours = max_hours;
    id = ID;
    //this->mySchedule = schedule();
}

void partTimeEmployee::setData(std::string name, int max_hours, int ID){
    //std::cout << "attempt made";
    hourly_wage = 21;
    firstName = name;
    maxHours = max_hours;
    id = ID;
    //this->mySchedule = schedule();
}

void partTimeEmployee::call_off(int day, int shift){
        mySchedule.update_schedule(day, shift, 1);
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 3; j++){
                std::cout << j <<  mySchedule.mySchedule[i][j] << " ";
            }
            std::cout << std::endl;
        }
}
void partTimeEmployee::call_of(int day, int shift){
        mySchedule.update_schedule(day, shift, 1);
        std::cout << shift << std::endl;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 3; j++){
                std::cout << mySchedule.mySchedule[i][j] << " ";
            }
            std::cout << std::endl;
        }
}

void partTimeEmployee::setData(std::string name, int max_hours, int ID, int hourly_rate){
    hourly_wage = hourly_rate;
    firstName = name;
    maxHours = max_hours;
    id = ID;
    //this->mySchedule = schedule();
}
/*
void partTimeEmployee::countAvailability(int availability[]){
    int unavailability_count = 0;
    for(int i = 0; i < 15; i++){
        unavailability_count += availability[i];
    }
}
int* partTimeEmployee::setAvailability(int n, int availability[]){
    unavailability = new int[n];
    for(int i = 0; i < )
}
*/


