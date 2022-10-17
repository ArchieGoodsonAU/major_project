#include "employee.h"
#include "partTimeEmployee.h"
#include <iostream>
partTimeEmployee::partTimeEmployee(std::string name, int max_hours, int ID){
    //countAvailability(availability);
    //unavailability = setAvailability(unavailability_count, availability);
    this->firstName = name;
    this->maxHours = max_hours;
    this->id = ID;
}

void partTimeEmployee::call_off(){
        maxHours--;
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


