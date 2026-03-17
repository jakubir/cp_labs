#include <iostream>
#include <time.h>
#include <vector>

class Matrix
{
	public:
		float** data;
		int size;

		Matrix(int size):size(size) {
			data = new float*[size];

			for (int i = 0; i < size; i++)
			{
				data[i] = new float[size];
				for (int j = 0; j < size; j++)
					data[i][j] = rand() % 100;
			}
		}

		Matrix(const Matrix& other) {
			size = other.size;

			data = new float* [size];

			for (int i = 0; i < size; i++) {
				data[i] = new float[size];

				for (int j = 0; j < size; j++) {
					data[i][j] = other.data[i][j];
				}
			}
		}

		~Matrix()
		{
			for (int i = 0; i < size; i++)
				delete [] data[i];

			delete[] data;
		}

		void print()
		{
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++)
					std::cout << data[i][j] << " ";

				std::cout << "\n";
			}
		}

		Matrix operator+(Matrix &m2) 
		{
			Matrix m3(size);

			if (m2.size < size)
				return m3;


			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					m3.data[i][j] = data[i][j] + m2.data[i][j];

			return m3;
		}

		Matrix operator-(Matrix &m2)
		{
			Matrix m3(size);

			if (m2.size < size)
				return m3;

			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					m3.data[i][j] = data[i][j] - m2.data[i][j];

			return m3;
		}

		Matrix operator*(Matrix &m2)
		{
			Matrix m3(size);

			if (m2.size < size)
				return m3;

			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
				{
					float sum = 0;

					for (int k = 0; k < size; k++)
						sum += data[i][k] * m2.data[k][i];

					m3.data[i][j] = sum;
				}

			return m3;
		}
};

class Network
{
	public:
		std::vector <Matrix>v;

		int matrix_size;

		Network(int matrix_size): matrix_size(matrix_size) {}

		void initialize(int num)
		{
			for (int i = 0; i < num; i++)
				v.push_back(Matrix(matrix_size));
		}

		Matrix calculate()
		{
			Matrix result_matrix = v.at(0);
			for (int i = 1; i < v.size(); i++)
			{
				result_matrix = result_matrix * v.at(i);
			}
		}
};

int main()
{
	srand(time(NULL));

	Matrix m(2);
	Matrix m2(2);
	Matrix m3 = m + m2;
	Matrix m4 = m - m2;
	Matrix m5 = m * m2;

	m.print();
	m2.print();
	m3.print();
	m4.print();
	m5.print();

	// network with array of matrices, calc (multypliying all matrices)

	return 0;
}
