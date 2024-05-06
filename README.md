# data-structure.cpp
This program demonstrates date management functionalities using a `Date` struct in C++. 
It includes features to validate dates, calculate the day of the week, print dates in a formatted manner, calculate date differences, and sort a list of dates.

## How to Compile and Run
1. **Compile the Code:**
   - Ensure you have a C++ compiler (e.g., `g++`) installed on your system.
   - Open a terminal/command prompt.
   - Navigate to the directory containing your code (`date_management.cpp`).
   - Run the following command to compile the code:
     ```bash
     g++ -o date_management date_management.cpp
     ```

2. **Run the Program:**
   - After successful compilation, run the executable:
     ```bash
     ./date_management
     ```

## Usage
- The program initializes date objects, manipulates them, and performs various operations:
  - Validation of dates using `isValidDate()`.
  - Printing dates in a formatted string using `printDate()`.
  - Calculating the day of the week using `getDayOfWeek()`.
  - Calculating differences between dates using `calculateDifference()`.
  - Sorting a vector of dates based on chronological order using `operator<`.

## Sample Output
10 June 2024 is Monday
The difference between 21 February 2001 and 10 June 2024 is 8496 days
Sorted dates:
21 February 2001
27 July 2015
6 June 2024
10 June 2024
25 October 2009
