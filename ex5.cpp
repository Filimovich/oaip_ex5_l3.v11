#include <iostream>
#include <cmath>
#include <random>
#include <climits>

using namespace std;

int array_type()
{
	string str;

	while(1){

		while (str.size() != 1) {
			cout << "Please choose - M/(r): ";
			cin >> str;
		}

		if (str[0] == 'm' || str[0] == 'M')
			return (1);
		if (str[0] == 'r' || str[0] == 'R')
			return (0);
	}
}

void inputOutOfRange_error()
{
	cout << "Out of range error. Try again." << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}

void input_error(void)
{
	cout << "Input data type error. Try again." << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}

double digit_input()
{
	double digit;
	while(1) {
		string str;
		size_t pos{};
		cin >> str;
		try {
			digit = stod(str, &pos);
			if (cin && pos == str.size())
				break;
			else {
				input_error();
			}
		}
		catch (invalid_argument const&) {
			input_error();
		}
		catch (out_of_range const&) {
			inputOutOfRange_error();
		}
	}

	return (digit);
}

int get_array_size()
{
	int size;
	double input;

	while(1) {
		cout << "Enter array size: ";
		input = digit_input();

		if (input - round(input) == 0) {
			if (input > 0 && input < 20)
				return (size = input);
		}
	}
}

double** get_array()
{
	int arraySize;
	double **userArray;
	
	arraySize = get_array_size();

	userArray = new double*[arraySize + 1]; //Инициализация массива
	for (int i = 0; i <= arraySize; i++) {
		userArray[i] = new double[arraySize + 1];
	}

	for (int i = 1; i <= arraySize; i++) { //Заполнение массива
		
		for (int j = 1; j <= arraySize; j++) {
			cout << "Enter element[" << i << "]" << "[" << j << "]: ";
			userArray[i][j] = digit_input();
		}
	}

	userArray[0][0] = arraySize;

	return (userArray);
}

double** get_random_array()
{
	int arraySize = get_array_size();
	double lower = -30;
	double higher = 30;
	double **randomArray;

	mt19937 gen(time(0)); //Вихрь Мерсенна с сидом на текущее время
	uniform_real_distribution<double> range(lower, higher);

	randomArray = new double*[arraySize + 1];
	for (int i = 0; i <= arraySize; i++) {
		randomArray[i] = new double[arraySize + 1];
	}

	for (int i = 1; i <= arraySize; i++) {
		
		for (int j = 1; j <= arraySize; j++) {
			randomArray[i][j] = range(gen);
		}
	}

	randomArray[0][0] = arraySize;

	return (randomArray);
}

int** get_result_array(double **array)
{
	int size = array[0][0];
	int **resultArray;

	resultArray = new int*[size];

	for (int i = 0; i < size; i++) {
		resultArray[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i + 1][j + 1] > array[i + 1][i + 1])
				resultArray[i][j] = 1;
			else
				resultArray[i][j] = 0;
		}
	}

	return (resultArray);
}

int main()
{
	double **array;
	int **resultArray;

	cout << "Do you want to enter the array Manually or use a Random one?" << endl;

	if (array_type() == 1) {
		array = get_array();
	} else array = get_random_array();

	cout << endl;

	for (int i = 1; i <= array[0][0]; i++) {
		for (int j = 1; j <= array[0][0]; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	resultArray = get_result_array(array); //TODO: Оформить красивывй вывод. Перепроверить работу проверок.

	cout << endl;

	for (int i = 0; i < array[0][0]; i++) {
		for (int j = 0; j < array[0][0]; j++) {
			cout << resultArray[i][j] << " ";
		}
		cout << endl;
	}

	return (0);
}
