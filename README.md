# Project Title

**Multithreaded Solution of Linear Equations using Cramer's Rule**

---

# Description

This project solves a **system of three linear equations** using **Cramer's Rule** in the C programming language. The program calculates determinants of matrices and uses **process creation (`fork()`)** to compute solutions for each variable in parallel.

Each child process calculates the determinant of a modified matrix and determines the value of a specific variable. This demonstrates **parallel execution and process management in Linux/Unix systems**.

The project highlights how **operating system concepts such as process creation and synchronization** can be applied to solve mathematical problems efficiently.

---

# 📂 Sections of Work
Problem Statement:
Solve a system of 3 linear equations:
A * X = B
Where:
A = 3×3 coefficient matrix
B = constants vector
X = solution vector [x1, x2, x3]
Using Cramer's Rule:
Xi = Di / D
Where:
D = determinant of matrix A
Di = determinant of matrix A after replacing column i with vector B

---

# ⚙️ Program Workflow
Take input of:
Coefficient matrix A (3×3)
Constant vector B (3×1)
Compute determinant D of matrix A.
If D = 0
The system has no unique solution.
If D ≠ 0
Create 3 child processes using fork().
Each child:
Replaces one column of matrix A with vector B
Computes determinant Di
Calculates solution Xi = Di / D
Prints the result.
Parent process waits for all child processes using wait().
Process Structure
Parent Process

├── Child Process 1 → Calculates X1
├── Child Process 2 → Calculates X2
└── Child Process 3 → Calculates X3

Each child process independently computes its assigned variable.

Note:
The order of output may vary because child processes execute concurrently.
   ---


# 🧠 Concepts Demonstrated

* Cramer's Rule for solving linear equations
* Determinant calculation for a 3×3 matrix
* Process creation using `fork()`
* Parent-child process relationship
* Process synchronization using `wait()`
* Parallel computation in C

---

# 👨‍💻 Author
1.Bharath Reddy
2.Aman Das
3.Samam Roy
4.Saumya Kumari
5.Rinika Banerjee
6.Padelna Bhutiya
7.Sruthi
8.Anay Bhattacharya
9.Dhrub Shah


