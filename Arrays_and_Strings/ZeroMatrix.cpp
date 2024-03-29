//
// Created by wangxing on 19-7-4.
//

// 1.8 M x N 矩阵中某单元为0,则将该单元对应的行和列设置为0

#include <iostream>

// 将第row行设置为0
void nullifyRow(int **matrix, int N, int row)
{
    for (int j = 0; j < N; j++)
    {
        matrix[row][j] = 0;
    }
}

// 将第col列设置为0
void nullifyCol(int **matrix, int M, int col)
{
    for (int i = 0; i < M; i++)
    {
        matrix[col][i] = 0;
    }
}

// 将 M x N阶矩阵中出现0位置对应的行和列设置为0
void nullifyMatrix(int **matrix, int M, int N)
{
    bool firstRow = false;
    // 如果第一行中有0元素,将firRow标志修改为true
    for (int i = 0; i < N; i++)
    {
        if (matrix[0][i] == 0)
        {
            firstRow = true;
            break;
        }
    }

    // rest of the matrix
    for (int i = 1; i < M; i++)
    {
        bool nullifyThisRow = false;
        for (int j = 0; j < N; ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;         // 将该0元素对应的列设置为0
                nullifyThisRow = true;    // 该行中有0元素的标志设置为true
            }
        }
        // 含有0元素的该行设置为0
        if (nullifyThisRow)
            nullifyRow(matrix, N, i);
    }

    // 将第一列中存储的标志为0对应的列设置为0
    for (int j = 0; j < N; ++j)
    {
        if (matrix[0][j] == 0)
        {
            nullifyCol(matrix, M, j);
        }
    }

    // 如果原始的第一行存在0元素,将第一行设置为0
    if (firstRow)
        nullifyRow(matrix, N, 0);
}

void printMatrix(int **matrix, int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int M, N;
    std::cout << "Enter number of rows";
    std::cin >> M;
    std::cout << "Enter number of cols";
    std::cin >> N;
    int **matrix = new int*[M];
    for (int i = 0; i < M; i++)
    {
        matrix[i] = new int[N];
    }
    std::cout << "Provide M x N matrix \n";
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "Matrix Before:\n";
    printMatrix(matrix, M, N);
    nullifyMatrix(matrix, M, N);
    std::cout << "Matrix After:\n";
    printMatrix(matrix, M, N);
    return 0;
}



























