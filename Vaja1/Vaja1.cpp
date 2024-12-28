// COUNTING SORT & ROMAN SORT ALGORITHMS

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Function to read numbers from a file into a vector
bool readNumbers(vector<int>& vec, const char fileName[]) {
    ifstream input(fileName);
    int number;

    if (!input.is_open()) {
        return false; 
    }

    while (!input.eof()) {
        input >> number;
        vec.push_back(number);                      // Add the number to the vector
        while (isspace(input.peek())) input.get();  // Skip any extra whitespace
    }
    input.close();
    return true; 
}

// Function to find and handle the minimum value in the vector
int findMinimum(vector<int>& A) {
    int min = 0;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] < min)
            min = A[i];
    }

    // Adjust all elements by subtracting the minimum value
    for (int i = 0; i < A.size(); i++) {
        A[i] -= min; // Subtracting a negative number effectively adds it
    }

    return min;
}

// Function to find the maximum value in the vector
int findMaximum(vector<int> A) {
    int max = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    return max;
}

// Function to normalize the sorted array by adding back the minimum value
void normalize(int* B, int min, int maxSize) {
    for (int i = 0; i < maxSize; i++) {
        B[i] += min;
    }
}

// Function to write sorted data to a file
void printToFile(int* array, unsigned int size) {
    ofstream output("out.txt");

    for (int i = 0; i < size; i++) {
        output << array[i] << ' ';
    }
}

// Counting Sort algorithm
void countingSort(vector<int>& A) {
    int min = findMinimum(A); 
    int max = findMaximum(A); 

    int* C = new int[max + 1];

    // Initialize all values in C to 0
    for (int i = 0; i < (max + 1); i++) {
        C[i] = 0;
    }

    // Count the occurrences of each number in the input array
    for (int i = 0; i < A.size(); i++) {
        C[A[i]]++;
    }

    // Accumulate the counts to determine positions
    for (int i = 1; i < (max + 1); i++) {
        C[i] += C[i - 1];
    }

    // Create the output array (B)
    int* B = new int[A.size()];
    for (int i = A.size() - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    normalize(B, min, A.size());    // Add back the minimum value to all elements

    printToFile(B, A.size());       // Output the sorted array to a file

    delete[] C; // Free memory for count array
    delete[] B; // Free memory for output array
}

// Roman Sort algorithm
void romanSort(vector<int>& A) {
    int min = findMinimum(A); 
    int max = findMaximum(A); 

    int* C = new int[max + 1];

    // Initialize all values in C to 0
    for (int i = 0; i < (max + 1); i++) {
        C[i] = 0;
    }

    // Count the occurrences of each number in the input array
    for (int i = 0; i < A.size(); i++) {
        C[A[i]]++;
    }

    // Create the output array (B)
    int* B = new int[A.size()];
    int index = 0; // Index to insert elements in B

    // Populate B with sorted elements based on the count array
    for (int i = 0; i < (max + 1); i++) {
        if (C[i] != 0) {
            for (int j = 0; j < C[i]; j++) {
                B[index] = i;
                index++;
            }
        }
    }

    normalize(B, min, A.size());    // Add back the minimum value to all elements

    printToFile(B, A.size());       // Output the sorted array to a file

    delete[] C; // Free memory for count array
    delete[] B; // Free memory for output array
}

int main(int argc, const char* argv[]) {
    vector<int> A;

    // Read numbers from the input file
    if (!readNumbers(A, argv[2]))
        cout << "ERROR reading file!" << endl;
        return 0;

    // Determine the sorting algorithm to use
    if (argv[1][0] == '0') {
        countingSort(A);
    }
    else {
        romanSort(A);
    }

    return 0;
}
