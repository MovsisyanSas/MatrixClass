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

		void swap(int* a, int* b) {
			*a = *a + *b;
			*b = *a - *b;
			*a = *a - *b;
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

		void ColSwap() {
			for (int i = 0; i < row; i++)
			{
				swap(&matrix[i][0], &matrix[i][2]);
			}
		}

		void RowSwap() {
			for (int i = 0; i < column; i++)
			{
				swap(&matrix[0][i], &matrix[2][i]);
			}
		}

		M(const M& obj) {
			this->row = obj.row;
			this->column = obj.column;
			this->matrix = new int* [row];

			for (int i = 0; i < row; i++) {
				matrix[i] = new int[column];
			}

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					matrix[i][j] = obj.matrix[i][j];
				}
			}
		}

		M& operator = (const M & obj) {
			if (this != &obj)
			{
				this->row = obj.row;
				this->column = obj.column;
				this->matrix = new int* [row];

				for (int i = 0; i < row; i++) {
					matrix[i] = new int[column];
				}

				for (int i = 0; i < row; i++) {
					for (int j = 0; j < column; j++) {
						matrix[i][j] = obj.matrix[i][j];
					}
				}
			}
			return *this;
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

	/*if (row >= 3 && columns >= 3)
	{
		matrix.ColSwap();
		matrix.print();
		matrix.ColSwap();
		matrix.RowSwap();
		matrix.print();
	}*/

	M matrix2(matrix);
	matrix2.print();

	M matrix3(row, columns);
	matrix3 = matrix;
	matrix3.print();
}

