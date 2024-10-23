#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.1 pek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71pek
{
	TEST_CLASS(UnitTest71pek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rows = 2, cols = 2;
            int** matrix = new int* [rows];
            for (int i = 0; i < rows; i++)
                matrix[i] = new int[cols];

            Create(matrix, rows, cols, -17, 14);

            // Перевіряємо, чи всі елементи в правильному діапазоні
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    Assert::IsTrue(matrix[i][j] >= -17 && matrix[i][j] <= 14);

            for (int i = 0; i < rows; i++)
                delete[] matrix[i];
            delete[] matrix;
		}
	};
}
