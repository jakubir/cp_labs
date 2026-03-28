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
					data[i][j] = rand() % 10;
			}
		}

		Matrix(const Matrix& m2) {
			size = m2.size;
			data = new float* [size];

			for (int i = 0; i < size; i++) {
				data[i] = new float[size];

				for (int j = 0; j < size; j++) {
					data[i][j] = m2.data[i][j];
				}
			}
		}

		~Matrix()
		{
			for (int i = 0; i < size; i++)
				delete [] data[i];

			delete[] data;
		}

		Matrix& operator=(const Matrix& m2) {
			for (int i = 0; i < size; i++)
				delete [] data[i];

			delete[] data;

			size = m2.size;
			data = new float* [size];

			for (int i = 0; i < size; i++) {
				data[i] = new float[size];

				for (int j = 0; j < size; j++) {
					data[i][j] = m2.data[i][j];
				}
			}

			return *this;
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

		Matrix operator-(const Matrix &m2) const
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
						sum += data[i][k] * m2.data[k][j];

					m3.data[i][j] = sum;
				}

			return m3;
		}

		void print()
		{
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++)
					std::cout << data[i][j] << " ";

				std::cout << "\n";
			}
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

			return result_matrix;
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

	Network n(2);
	n.initialize(5);
	for (int i = 0; i < n.v.size(); i++)
		n.v.at(i).print();

	n.calculate().print(); 

	return 0;
}
