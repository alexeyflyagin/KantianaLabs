// The laboratory work was performed by a 1st year student
// Direction: Mathematical support and administration of information systems
// Option: 8
// Flyagin Alexey


#include <iostream>
#include <iomanip>
#include <functional>


template<typename T, int N, int M>
class Matrix {
private:
    T data[N][M];

public:
    Matrix() { iterating_by_indexes([this](int i, int j) { data[i][j] = T(); }); }

    Matrix(const Matrix& other) { iterating_by_indexes([this, &other](int i, int j) { data[i][j] = other.data[i][j]; }); }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;

        iterating_by_indexes([this, &other](int i, int j) { data[i][j] = other.data[i][j]; });
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j)
                os << std::setw(5) << mat.data[i][j];
            os << '\n';
        }

        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& mat) {
        mat.iterating_by_indexes([&is, &mat](int i, int j) { is >> mat.data[i][j]; });
        return is;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result;
        iterating_by_indexes([this, &result, &other](int i, int j) { result.data[i][j] = data[i][j] + other.data[i][j]; });
        return result;
    }

    Matrix& operator+=(const Matrix& other) {
        iterating_by_indexes([this, &other](int i, int j) { data[i][j] += other.data[i][j]; });
        return *this;
    }

    Matrix operator*(const Matrix<T, M, N>& other) const {
        Matrix<T, N, N> result;
        for (int i = 0; i < N; ++i)
            iterating_by_indexes([this, &result, &other](int k, int j) { result.data[i][j] += data[i][k] * other.data[k][j]; });
        return result;
    }

    Matrix& operator*=(T scalar) {
        iterating_by_indexes([this, scalar](int i, int j) { data[i][j] *= scalar; });
        return *this;
    }

    Matrix& operator++() {
        iterating_by_indexes([this](int i, int j) { data[i][j]++; });
        return *this;
    }

    T determinant() const {
        if(N != M) throw std::logic_error("Determinant defined only for square matrices.");
        if (N == 2) {
            return data[0][0]*data[1][1] - data[0][1]*data[1][0];
        } else if (N == 3) {
            return data[0][0]*(data[1][1]*data[2][2] - data[1][2]*data[2][1]) -
                   data[0][1]*(data[1][0]*data[2][2] - data[1][2]*data[2][0]) +
                   data[0][2]*(data[1][0]*data[2][1] - data[1][1]*data[2][0]);
        } else {
            throw std::logic_error("Determinant not implemented for this size.");
        }
    }

    T& operator()(int i, int j) { return data[i][j]; }

    const T& operator()(int i, int j) const { return data[i][j]; }

private:
    template<typename Func>
    void iterating_by_indexes(Func action) const {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                action(i, j);
    }

    template<typename Func>
    void iterating_by_indexes(Func action) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                action(i, j);
    }
};

int main() {
    system("cls");
    
    Matrix<int, 2, 2> A, B;
    std::cout << "Enter 4 elements for matrix A:\n";
    std::cin >> A;
    std::cout << "Enter 4 elements for matrix B:\n";
    std::cin >> B;

    Matrix<int, 2, 2> C = A + B;
    std::cout << "Matrix C = A + B:\n" << C;

    ++C;
    std::cout << "Matrix C after ++:\n" << C;

    C *= 2;
    std::cout << "Matrix C after *= 2:\n" << C;

    std::cout << "Determinant of A: " << A.determinant() << "\n";

    C(0, 1) = 100;
    std::cout << "C after modifying element (0,1):\n" << C;

    return 0;
}
