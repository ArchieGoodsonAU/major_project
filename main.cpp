#include <iostream>
#include "fullTimeEmployee.h"
#include "partTimeEmployee.h"
#include "employee.h"
#include <vector>
int main(void){
    int IDs[5] = {111, 222, 333, 444, 555};
    std::string names[5] = {"Sarah", "John", "Luke", "Alexandra", "Jane"};
    
    partTimeEmployee* employees[2];
    employees[0] = new partTimeEmployee(names[0], 38, IDs[0]);
    employees[1] = new partTimeEmployee(names[1], 38, IDs[1]);
    employees[0]->setData(names[0], 14, IDs[0]);
    std::cout << employees[0]->maxHours;
}