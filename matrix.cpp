
#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin() {
    int x;
    cout << "Matrix data: ";
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        cin >> x;
        data[i][j] = x;
      }
    }
  };

  // 2. Display a matrix
  void display() const {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        cout << data[i][j];
        cout << " ";
      }
      cout << "\n";
    }
  };

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        result.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    return result;
  };

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        result.data[i][j] = 0;
        for (int k = 0; k < SIZE; k++) {
          result.data[i][j] += (data[i][k] * other.data[k][j]);
        }
      }
    }
    return result;
  };

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const {
    int x = 0;
    int y = 0;
    for (int i = 0; i < SIZE; i++) {
      x += (data[i][i]);
    }
    for (int j = 0; j < SIZE; j++) {
      y += (data[j][SIZE-i-1]);
    } 
    return x + y;
  };

  // 6. Swap matrix rows
  void swapRows(int row1, int row2) {
    for (int i = 0; i < SIZE; i++) {
      int hold = data[row1][i];
      data[row1][i] = data[row2][i];
      data[row2][i] = hold;
    }
  };
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "\nEnter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "\nMatrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "\nEnter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "\nMatrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "\nSum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "\nProduct of matrices:" << endl;
  product.display();

  cout << "\nSum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "\nMatrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
