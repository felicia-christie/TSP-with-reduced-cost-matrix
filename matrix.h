#ifndef MTRX
#define MTRX

class Matrix{
	public:
		int **M;
		int i;
		int j;
		~Matrix();
		Matrix& operator= (const Matrix &);

		void InputMatrix();
		void Print();

		int LeastValue(char, int);
		bool CRD();
		Matrix CostReducing();
		int totalValue();
		int VCostReduce();

		Matrix NullMatrix(char, int);
};

#endif