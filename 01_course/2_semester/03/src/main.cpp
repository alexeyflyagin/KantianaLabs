// The laboratory work was performed by a 1st year student
// Direction: Mathematical support and administration of information systems
// Option: 8
// Flyagin Alexey


#include <iostream>
#include <cmath>

inline constexpr auto ENTER_EDGE_LENGTH = "Enter edge length: ";
inline constexpr auto SURFACE_AREA = "Surface area: ";
inline constexpr auto VALUE = "Volume: ";

class Tetrahedron {
private:
    double edgeLength;

public:
    Tetrahedron(double edge) : edgeLength(edge) {
        if (edge <= 0) {
            throw std::invalid_argument("Edge length must be greater than 0");
        }
    }

    double calculateSurfaceArea() const {
        return sqrt(3) * edgeLength * edgeLength;
    }

    double calculateVolume() const {
        return (edgeLength * edgeLength * edgeLength) / (6 * sqrt(2));
    }
};

int main() {
    system("cls");

    int edgeLength;
    std::cout << ENTER_EDGE_LENGTH;
    std::cin >> edgeLength;
    Tetrahedron tetrahedron(edgeLength);

    std::cout << SURFACE_AREA << tetrahedron.calculateSurfaceArea() << std::endl;
    std::cout << VALUE << tetrahedron.calculateVolume() << std::endl;

    return 0;
}
