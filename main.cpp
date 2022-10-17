#include <iostream>
#include "fullTimeEmployee.h"
#include "partTimeEmployee.h"
#include "employee.h"
#include <vector>
int main(void){
    std::string thisName = "Sarah";
    partTimeEmployee employees = partTimeEmployee(thisName, 38, 1024);
    std::cout << employees.id;
}