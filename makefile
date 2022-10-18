employee_test: employee.cpp fullTimeEmployee.cpp employee_tester.cpp
	@g++ -Wall employee.cpp fullTimeEmployee.cpp employee_tester.cpp -o tester.out
run_test: tester.out employee_testing.txt
	@./tester.out < employee_testing.txt
