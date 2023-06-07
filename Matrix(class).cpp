#include <iostream>

class M {
	private:

		int** matrix;
		int row;
		int column;

		void init() {
			for (int i = 0; i < row; i++)
			{
				matrix[i] = new int[column];
			}
		}

		void fill() {
			srand(time(0));
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					matrix[i][j] = rand() % 10;
				}
			}
		}

	public:
		M() {
			std::cout << "Error: Fill size values!" << std::endl;
		}
		M(int r, int c) {
			if (r < 0 || c < 0)
			{
				std::cout << "Error: Size values can't be less than 0 !" << std::endl;
			}
			else {
				row = r;
				column = c;
				matrix = new int* [row];
				init();
				fill();
			}
		}

		void print() {
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					std::cout << matrix[i][j] << ' ';
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		~M(){
			for (int i = 0; i < row; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;

			std::cout << "Matrix deleted" << std::endl;
		}
};

int main() {
	int row, columns;
	std::cout << "How many rows does matrix have? : ";
	std::cin >> row;
	std::cout << "How many columns does matrix have? : ";
	std::cin >> columns;

	M matrix(row,columns);
	matrix.print();
}