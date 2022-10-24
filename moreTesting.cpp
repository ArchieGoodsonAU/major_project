#include <iostream>
#include "employee.h"
#include "schedule.h"
#include "fullTimeEmployee.h"
#include "partTimeEmployee.h"
using std::string;

int main(void) {
    fullTimeEmployee* A = new fullTimeEmployee;
    A->setData("Andrew", 1234, 5555);
    std::cout << A->firstName << std::endl;
    std::cout << A->id << std::endl;
    std::cout << A->salary << std::endl;
    delete A;
    partTimeEmployee* B = new partTimeEmployee;
    B->setData("Bob", 10, 12345, 333);
    std::cout << B->firstName << std::endl;
    std::cout << B->max_hours << std::endl;
    std::cout << B->id << std::endl;
    std::cout << B->hourly_wage << std::endl;
    delete B;


}