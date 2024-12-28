# Sorting Utility

This is a terminal-based application designed to sort numbers using one of two algorithms: **Counting Sort** or **Roman Sort**. The program reads input from a file, processes it, and writes the sorted output to a file.

---

## 🚀 Features

- 🛠️ **Two Sorting Algorithms**:
  - `0`: Counting Sort
  - `1`: Roman Sort
- 📂 **Input from File**: Reads numbers from a file in the same directory as the program.
- 📤 **Output to File**: Writes the sorted output to a file (`out.txt`) in the same directory.
- 📉 **Handles Negative Numbers**: The program can process negative values gracefully.
- ⚡ **Efficient Sorting**: Optimized to handle sorting tasks with high performance.

---

## 📋 How to Use

### 1. **Prepare the Input File**

Ensure there is an input file (e.g., `input.txt`) in the same directory as the program. The file should contain a list of integers separated by spaces or newlines.

### 2. **Run the Program**

Use the terminal to execute the program with the following command structure:

```bash
./sorting_utility <algorithm_number> <input_file>
```

#### Parameters:
- `<algorithm_number>`: Specifies the sorting algorithm to use:
  - `0` for Counting Sort
  - `1` for Roman Sort
- `<input_file>`: The name of the file containing the numbers to sort.

#### Example:
```bash
./sorting_utility 0 input.txt
```
This command will use Counting Sort to sort the numbers in `input.txt`.

### 3. **Check the Output**

The sorted numbers will be written to a file named `out.txt` in the same directory as the program. Open the file to view the results.

---

## 🛡️ Requirements

- C++ Compiler
- Input file with numbers in the correct format

---

## 📝 Notes

- If the input file is missing or cannot be opened, the program will terminate with an error.
- The input file must be in the same directory as the program.
- Negative numbers are supported, and the sorting algorithms handle them properly.

---

