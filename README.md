
# Project Title

**Multithreaded Solution of Linear Equations using Cramer's Rule**

---

# Description

This project solves a **system of three linear equations** using **Cramer's Rule** in the C programming language. The program calculates determinants of matrices and uses **process creation (`fork()`)** to compute solutions for each variable in parallel.

Each child process calculates the determinant of a modified matrix and determines the value of a specific variable. This demonstrates **parallel execution and process management in Linux/Unix systems**.

The project highlights how **operating system concepts such as process creation and synchronization** can be applied to solve mathematical problems efficiently.

---

# 📂 Sections of Work

The following components were implemented independently:

* Writing the **complete C program**
* Implementing the **determinant calculation function**
* Implementing the **column replacement logic**
* Creating and managing **child processes using `fork()`**
* Handling **process synchronization using `wait()`**
* Testing the program with different **matrix inputs**
* Debugging and verifying program correctness

---

# ⚙️ Program Workflow

1. The user enters a **3×3 coefficient matrix**.
2. The user enters the **constants vector**.
3. The program computes the **determinant of matrix A (D)**.
4. If `D = 0`, the system does not have a unique solution.
5. The program creates **three child processes**.
6. Each child process:

   * Replaces one column of matrix **A** with vector **B**
   * Computes the determinant of the new matrix (**Di**)
   * Calculates the solution **Xi = Di / D**
7. The parent process waits until all children finish execution


Note:
The order of output may vary because **child processes execute concurrently**.

---

# 🧠 Concepts Demonstrated

* Cramer's Rule for solving linear equations
* Determinant calculation for a 3×3 matrix
* Process creation using `fork()`
* Parent-child process relationship
* Process synchronization using `wait()`
* Parallel computation in C

---

---

# 👨‍💻 Author
1.Bharath Reddy                                                                                                                           
2.Aman Das                                                                                                                                
3.Samam Roy                                                                                                                               
4.Saumya Kumari                                                                                                                           
5.Rinika Banerjee                                                                                                                         
6.Padelna Bhutiya                                                                                                                         
7.Vaddadhi Sruthi                                                                                                                                  
8.Anay Bhattacharya (Group Leader)                                                                                                                      
9.Dhrub Shah                                                                                                                              
