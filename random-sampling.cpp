//g++ -std=c++11 random-sampling.cpp -o random-sampling
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

std::default_random_engine generator(time(0));

void Update(std::vector<int>& S, int& n, int x) {
    n++;
    std::uniform_int_distribution<int> distribution(1, n);
    int i = distribution(generator);
    if (i <= S.size()) {
        S[i-1] = x; 
    }
    
}

std::vector<int> Merge(const std::vector<int>& S1, int n1, const std::vector<int>& S2, int n2) {
    std::vector<int> S;
    int k1 = 0, k2 = 0;
    for (int i = 0; i < S1.size() + S2.size(); ++i) {
        std::uniform_int_distribution<int> distribution(1, n1 + n2);
        int j = distribution(generator);
        if (j <= n1 && k1 < S1.size()) {
            S.push_back(S1[k1++]);
            n1--;
        } else if (k2 < S2.size()) {
            S.push_back(S2[k2++]);
            n2--;
        }
    }
    return S;
}

std::vector<int> Initialize(const std::vector<int>& A) {
    return A;
}

int main() {
    std::vector<int> A = {1, 2, 3, 4, 5};
    std::vector<int> sample = Initialize(A);
    int n = sample.size();

    for (int elem : sample) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // Update sample
    Update(sample, n, 6);
    Update(sample, n, 7);

    // Print updated sample
    for (int elem : sample) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // Merge with another sample
    std::vector<int> B = {8, 9, 10};
    std::vector<int> mergedSample = Merge(sample, n, B, B.size());

    // Print merged sample
    for (int elem : mergedSample) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    return 0;
}
