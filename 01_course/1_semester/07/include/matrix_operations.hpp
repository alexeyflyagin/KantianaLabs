#pragma once

namespace MatrixOperations {

    class MatrixMaxAndMin {
        private:
            int _max, _min;

        public:
            MatrixMaxAndMin(int min, int max) : _min(min), _max(max) {}

            int max() const { return _max; }
            int min() const { return _min; }
    };

    void inputMatrix(int** matrix, int size);

    void processMatrix(int** matrix, int size);

    void showMatrix(int** matrix, int size);

    MatrixMaxAndMin getMinAndMax(int** matrix, int size);
}