#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>

using namespace std;

// Функция для расчета суммы
double computeSum(const vector<double>& nums) {
    return accumulate(nums.begin(), nums.end(), 0.0);
}

// Функция для расчета среднего арифметического
double computeAverage(const vector<double>& nums) {
    return computeSum(nums) / static_cast<double>(nums.size());
}

// Функция для расчета медианы
double computeMedian(vector<double> nums) {
    sort(nums.begin(), nums.end());
    size_t count = nums.size();
    return (count % 2 == 0) ? (nums[count / 2 - 1] + nums[count / 2]) / 2.0 : nums[count / 2];
}

int main(int argc, char* argv[]) {
    if (argc < 4) { // Здесь изменено на 4 из-за переработки аргументов
        cerr << "Usage: " << argv[0] << " -o <operation> <numbers>\n";
        cerr << "Valid operations: sum, average, median\n";
        return 1;
    }

    string op;
    vector<double> values;

    // Обработка именованных параметров
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-o") {
            if (i + 1 < argc) {
                op = argv[++i];
            } else {
                cerr << "Missing operation argument\n";
                return 1;
            }
        } else {
            try {
                values.push_back(stod(argv[i]));
            } catch (const invalid_argument&) {
                cerr << "Invalid number: " << argv[i] << "\n";
                return 1;
            }
        }
    }

    if (values.size() < 7 || values.size() > 9) {
        cerr << "Number of operands must be between 7 and 9.\n";
        return 1;
    }

    double output;
    if (op == "sum") {
        output = computeSum(values);
    } else if (op == "average") {
        output = computeAverage(values);
    } else if (op == "median") {
        output = computeMedian(values);
    } else {
        cerr << "Invalid operation: " << op << "\n";
        return 1;
    }

    cout << "Result of operation '" << op << "': " << output << "\n";
    return 0;
}
