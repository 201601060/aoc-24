#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>  // For abs()
#include <algorithm> // For sort()

int main() {
    std::ifstream input("input.txt"); // Open the input file
    std::vector<int> list1, list2;    // Vectors to store the two lists

    // Read data from file
    int n1, n2;
    while (input >> n1 >> n2) {
        list1.push_back(n1);
        list2.push_back(n2);
    }

    // Sort both lists
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    // Calculate the sum of absolute differences
    int sum_diff = 0;
    for (size_t i = 0; i < list1.size(); ++i) {
        sum_diff += std::abs(list1[i] - list2[i]);
    }

    // Output the result
    std::cout << "Sum of differences: " << sum_diff << std::endl;

    return 0;
}

