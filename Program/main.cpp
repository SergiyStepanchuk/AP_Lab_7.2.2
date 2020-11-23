// Lab_7_2_2
#include <iostream>
#include <iomanip>
using namespace std;

int myrand(const int& min, const int& max) {
	return min > 0 ?
		rand() % (max - min + 1) + min :
		rand() % (abs(min) + max + 1) + min;
}

void full_matrix(int** matrix, const int *size, const int* dia, int i = 0, int j = 0)
{
	matrix[i][j] = myrand(dia[0], dia[1]);

	j++;
	if (j == size[1]) {
		i++;
		j = 0;
	}

	if (i < size[0])
		full_matrix(matrix, size, dia, i, j);
}

void draw_matrix(int** matrix, const int* size, int i = 0, int j = 0)
{
	cout << setw(4) << matrix[i][j];

	j++;
	if (j == size[1]) {
		i++;
		j = 0;
		cout << endl;
	}

	if (i < size[0])
		draw_matrix(matrix, size, i, j);
}

int min_(const int* mass, int size_i) {
	if (--size_i >= 1) {
		int min = min_(mass, size_i);
		if (mass[min] > mass[size_i])
			min = size_i;
		return min;
	}
	return 0;
}

void edit_matrix(int** matrix, const int& size, int i = 0) {
	if (i+1 < size)
		edit_matrix(matrix, size, i+1);

	swap(
		matrix[size - i - 1][i],
		matrix[size - i - 1][min_(matrix[size - i - 1], size)]
	);

	cout << matrix[size - i - 1][i] << " ";
}

void main() {
	srand(time(NULL));
	int** matrix = nullptr, n, dia[2] = { 0, 0 };
	cout << "n = "; cin >> n;
	cout << "start dia = "; cin >> dia[0];
	cout << "stop dia  = "; cin >> dia[1];

	int size[2] = { n, n };
	matrix = new int* [n];
	for (--n; n >= 0; n--)
		matrix[n] = new int[size[0]];

	full_matrix(matrix, size, dia);
	draw_matrix(matrix, size);
	edit_matrix(matrix, size[0]);
	cout << endl << endl;
	draw_matrix(matrix, size);

	for (n = 0; n < size[0]; n++)
		delete[] matrix[n];
	delete[] matrix;
}