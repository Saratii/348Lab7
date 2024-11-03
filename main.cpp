#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 4; 

class Matrix {
    private:
        int data[SIZE][SIZE];
    public:
        // 1. Read values from stdin into a matrix
        //NOTE the file format having both matrices in one file then reading each matrix without being able to specify which one to read is complete nonsense. I will use 2 files so the directions dont contradict themselves as much. 
        void readFromStdin(string path) { //NOTE I assume whoever wrote this made a typo in either this or the directions because it conflicts whether it should be read from a file or stdin. I will assume file. 
            ifstream file(path);
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    file >> data[i][j];
                }
            }
            file.close();
        }
        // 2. Display a matrix
        void display() const {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    cout << data[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        // 3. Add two matrices (operator overloading for +)
        Matrix operator+(const Matrix& other) const {
            Matrix result;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    result.data[i][j] = this->data[i][j] + other.data[i][j];
                }
            }
            return result;
        }
        // 4. Multiply two matrices (operator overloading for *)
        //NOTE this does not specify element wise or standard matrix multiplication. I will assume standard matrix multiplication.
        Matrix operator*(const Matrix& other) const {
            Matrix result;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    result.data[i][j] = 0;
                    for (int k = 0; k < SIZE; k++) {
                        result.data[i][j] += this->data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }
        // 5. Compute the sum of matrix diagonal elements
        int sumOfDiagonals() const {
            int sum = 0;
            for (int i = 0; i < SIZE; i++) {
                sum += data[i][i];
                if (i != SIZE - 1 - i) {
                    sum += data[i][SIZE - 1 - i];
                }
            }
            return sum;
        }
        // 6. Swap matrix rows
        void swapRows(int row1, int row2) {
            swap(data[row1], data[row2]);
            cout << "\n";
        }
};
int main() {
    // Example usage:
    Matrix mat1;
    //cout << "Enter values for Matrix 1:" << endl; NOTE: this line conflicts with the directions where it says read from file so I will comment it out. 
    mat1.readFromStdin("matrix1.txt");
    cout << "Matrix 1:" << endl;
    mat1.display();
    Matrix mat2;
    //cout << "Enter values for Matrix 2:" << endl;  NOTE: this line conflicts with the directions where it says read from file so I will comment it out. 
    mat2.readFromStdin("matrix2.txt");
    cout << "Matrix 2:" << endl;
    mat2.display();
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();
    return 0;
}