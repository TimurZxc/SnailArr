

#include <iostream>

int main()
{
	int rows, cols;

	do { std::cout << "Rows: "; std::cin >> rows; } while (rows < 1);
	do { std::cout << "Columns: "; std::cin >> cols; } while (cols < 1);

	int** M;
	
	M = new int* [rows];
	for (int i = 0; i < rows; ++i)
		M[i] = new int[cols];

	int k = 1;
	int x = 0, y = 0;
	int left = 0, right = cols - 1, top = 1, bot = rows - 1;
	
	int Vx = 1, Vy = 0;
	do {
		M[y][x] = k++;
		x += Vx; y += Vy;
		if (x == right && Vx == 1) { Vx = 0; Vy = 1; --right; }
		if (x == left && Vx == -1) { Vx = 0; Vy = -1; ++left; }
		if (y == bot && Vy == 1) { Vx = -1; Vy = 0; --bot; }
		if (y == top && Vy == -1) { Vx = 1; Vy = 0; ++top; }
	} while (k <= rows * cols);

	
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << M[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	
	for (int i = 0; i < rows; ++i)
		delete[] M[i];
	delete[] M;

	return 0;
}
