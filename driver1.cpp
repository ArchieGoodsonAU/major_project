#include <iostream>
#include "fullTimeEmployee.h"
#include "partTimeEmployee.h"
#include "employee.h"
#include <vector>
partTimeEmployee employees[10];
int main(void){
    std::string thisName = "Sarah";
    employees[0] = partTimeEmployee(thisName, 38, 1024);
    std::cout << employees[0].id;
}