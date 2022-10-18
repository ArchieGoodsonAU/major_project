employee_test: employee.cpp fullTimeEmployee.cpp employee_tester.cpp
	@g++ -Wall employee.cpp fullTimeEmployee.cpp employee_tester.cpp -o tester.out
run_test: tester.out employee_testing.txt
	@./tester.out < employee_testing.txt

1-1: function-1-1.cpp main-1-1.cpp
	@g++ function-1-1.cpp main-1-1.cpp -o main-1-1.out
	@./main-1-1.out
1-2: function-1-2.cpp main-1-2.cpp
	@g++ function-1-2.cpp main-1-2.cpp -o main-1-2.out
	@./main-1-1.out
1-3: function-1-3.cpp main-1-3.cpp
	@g++ function-1-3.cpp main-1-3.cpp -o main-1-3.out
	@./main-1-3.out
1-4: function-1-4.cpp main-1-4.cpp
	@g++ function-1-4.cpp main-1-4.cpp -o main-1-4.out
	@./main-1-4.out
1-5: function-1-5.cpp main-1-5.cpp
	@g++ function-1-5.cpp main-1-5.cpp -o main-1-5.out
	@./main-1-5.out
2-1: function-2-1.cpp main-2-1.cpp
	@g++ function-2-1.cpp main-2-1.cpp -o main-2-1.out
	@./main-2-1.out
2-2: function-2-2.cpp main-2-2.cpp
	@g++ function-2-2.cpp main-2-2.cpp -o main-2-2.out
	@./main-2-2.out
2-3: function-2-3.cpp main-2-3.cpp
	@g++ function-2-3.cpp main-2-3.cpp -o main-2-3.out
	@./main-2-3.out
2-4: function-2-4.cpp main-2-4.cpp
	@g++ function-2-4.cpp main-2-4.cpp -o main-2-4.out
	@./main-2-4.out
2-5: function-2-5.cpp main-2-5.cpp
	@g++ function-2-5.cpp main-2-5.cpp -o main-2-5.out
	@./main-2-5.out
3-1: function-3-1.cpp main-3-1.cpp
	@g++ function-3-1.cpp main-3-1.cpp -o main-3-1.out
	@./main-3-1.out
3-2: function-3-2.cpp main-3-2.cpp
	@g++ function-3-2.cpp main-3-2.cpp -o main-3-2.out
	@./main-3-2.out
3-3: function-3-3.cpp main-3-3.cpp
	@g++ function-3-3.cpp main-3-3.cpp -o main-3-3.out
	@./main-3-3.out
3-4: function-3-4.cpp main-3-4.cpp
	@g++ function-3-4.cpp main-3-4.cpp -o main-3-4.out
	@./main-3-4.out
3-5: function-3-5.cpp main-3-5.cpp
	@g++ function-3-5.cpp main-3-5.cpp -o main-3-5.out
	@./main-3-5.out
4-1: function-4-1.cpp main-4-1.cpp
	@g++ function-4-1.cpp main-4-1.cpp -o main-4-1.out
	@./main-4-1.out