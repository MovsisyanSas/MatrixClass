#include <iostream>

template<typename T>
class M {
private:

	T** matrix;
	int row;
	int column;

	void init() {
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new T[column];
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
			matrix = new T* [row];
			init();
			//fill();
		}
	}

	M(const M& obj) {
		this->row = obj.row;
		this->column = obj.column;
		this->matrix = new T * [row];

		for (int i = 0; i < row; i++) {
			matrix[i] = new T[column];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				matrix[i][j] = obj.matrix[i][j];
			}
		}
	}

	M& operator = (const M& obj) {
		if (this != &obj)
		{
			this->row = obj.row;
			this->column = obj.column;
			this->matrix = new T * [row];

			for (int i = 0; i < row; i++) {
				matrix[i] = new T[column];
			}

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					matrix[i][j] = obj.matrix[i][j];
				}
			}
		}
		return *this;
	}
	M(M&& obj) {
		this->row = obj.row;
		this->column = obj.column;
		this->matrix = obj.matrix;
		obj.matrix = nullptr;
		obj.row = 0;
		obj.column = 0;
		std::cout << "move constructor" << std::endl;
	}
	M& operator=(M&& obj) {
		if (this != &obj) {

			for (int i = 0; i < row; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;

			this->row = obj.row;
			this->column = obj.column;
			this->matrix = obj.matrix;

			obj.row = 0;
			obj.column = 0;
			obj.matrix = nullptr;
		}
		std::cout << "move operator = " << std::endl;
		return *this;
	}

	~M() {
		for (int i = 0; i < row; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;

		std::cout << "Matrix deleted" << std::endl;
	}
public:
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
};

int main() {
	M<int> mat(3, 3);
	M<double> mat2(3, 3);
}

