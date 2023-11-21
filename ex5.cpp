#include <iostream>
#include <cmath>
#include <random>

using namespace std;

double** get_array()
{
	return (0);
}

double** get_random_array()
{
	int arraySize = 5;
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

	array = get_random_array();

	cout << array[0][0] << endl << endl;

	for (int i = 1; i <= array[0][0]; i++) {
		for (int j = 1; j <= array[0][0]; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	resultArray = get_result_array(array);

	cout << endl;

	for (int i = 0; i < array[0][0]; i++) {
		for (int j = 0; j < array[0][0]; j++) {
			cout << resultArray[i][j] << " ";
		}
		cout << endl;
	}

	return (0);
}
