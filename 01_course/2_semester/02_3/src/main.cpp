// The laboratory work was performed by a 1st year student
// Direction: Mathematical support and administration of information systems
// Option: 8
// Flyagin Alexey

#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

#include "constants.hpp"


struct GameData {
    size_t n_size;
    size_t m_size;
    std::pair<size_t, size_t> c_pos;
    std::vector<std::vector<char> > field;
    int total_steps;
    bool completed;

    GameData(
        const size_t n_size,
        const size_t m_size,
        const std::vector<std::vector<char> > &field,
        const std::pair<size_t, size_t> &c_pos
    ) : n_size(n_size), m_size(m_size), c_pos(c_pos), field(field), total_steps(0), completed(false) {
    }
};

std::vector<std::pair<size_t, size_t> > getAvailableSteps(const GameData &data) {
    std::vector<std::pair<size_t, size_t> > steps;

    steps.emplace_back(data.c_pos.first + 1, data.c_pos.second);
    steps.emplace_back(data.c_pos.first + 1, data.c_pos.second + 1);
    steps.emplace_back(data.c_pos.first, data.c_pos.second + 1);
    steps.emplace_back(data.c_pos.first - 1, data.c_pos.second + 1);
    steps.emplace_back(data.c_pos.first - 1, data.c_pos.second);
    steps.emplace_back(data.c_pos.first - 1, data.c_pos.second - 1);
    steps.emplace_back(data.c_pos.first, data.c_pos.second - 1);
    steps.emplace_back(data.c_pos.first + 1, data.c_pos.second - 1);


    for (auto pos = steps.begin(); pos != steps.end(); /* no increment */) {
        if (
            pos->first >= data.n_size || pos->second >= data.m_size ||
            pos->first == Lab1::MAX_SIZE_T || pos->second == Lab1::MAX_SIZE_T
        ) {
            pos = steps.erase(pos);
            continue;
        }
        const auto cell = data.field[pos->first][pos->second];
        if (cell == Lab1::FREE_CELL) {
            ++pos;
            continue;
        }
        if (cell == Lab1::END_CELL) {
            const auto pos_copy = *pos;
            steps.clear();
            steps.push_back(pos_copy);
            break;
        }
        pos = steps.erase(pos);
    }

    return steps;
}


GameData calculateSteps(GameData data) {
    if (data.field[data.c_pos.first][data.c_pos.second] == Lab1::END_CELL) {
        data.completed = true;
        return data;
    }

    const auto steps = getAvailableSteps(data);
    if (steps.empty())
        return data;

    std::vector<GameData> results;
    for (const auto step: steps) {
        auto new_data = data;
        new_data.c_pos = step;
        new_data.total_steps++;
        if (const auto cell = &new_data.field[step.first][step.second]; *cell != Lab1::END_CELL)
            *cell = Lab1::STEP_CELL;
        if (auto result = calculateSteps(new_data); result.completed) results.push_back(result);
    }
    if (results.empty()) return data;

    std::sort(results.begin(), results.end(), [](const GameData &a, const GameData &b) {
        return a.total_steps <= b.total_steps;
    });

    return results[0];
}


int main() {
    system("cls");

    int n, m;
    std::cout << Lab1::ENTER_N;
    std::cin >> n;
    std::cout << Lab1::ENTER_M;
    std::cin >> m;
    GameData data(n, m, std::vector(n, std::vector<char>(m)), std::make_pair(0, 0));

    std::cout << Lab1::ENTER_FIELD << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cell;
            std::cin >> cell;
            cell = toupper(cell);

            if (cell == Lab1::START_CELL) {
                data.c_pos.first = i;
                data.c_pos.second = j;
            }

            data.field[i][j] = cell;
        }
    }

    std::cout << std::endl;
    const auto res = calculateSteps(data);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << res.field[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << res.total_steps << std::endl;
}
