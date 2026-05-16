# 📊 Student Grade Tracker

A command-line application built in **C++** that helps track and manage student grades efficiently. Built as a personal project to strengthen C++ fundamentals including structs, functions, arrays, and input validation.

---

## ✨ Features

- ➕ **Add Students** — Enter student name, number of subjects, and marks for each
- 📋 **View All Students** — Displays a clean table with name, average and grade
- 🏆 **Find Topper** — Automatically finds the student with the highest average
- 🔍 **Search Student** — Look up any student by name and view their full details
- ✅ **Input Validation** — Handles invalid input gracefully without crashing
- 🔤 **Letter Grades** — Automatically assigned based on average (A/B/C/D/F)

---

## 🎯 Grade Scale

| Marks  | Grade |
|--------|-------|
| 90-100 | A     |
| 80-89  | B     |
| 70-79  | C     |
| 60-69  | D     |
| 0-59   | F     |

---

## 🛠️ How to Run

### Requirements
- A C++ compiler (g++ recommended)
- Windows / Linux / Mac terminal

### Steps

**1. Clone the repository**
```bash
git clone https://github.com/Manajain20/Student-Grade-Tracker.git
cd Student-Grade-Tracker
```

**2. Compile the code**
```bash
g++ -o grade_tracker grade_tracker.cpp
```

**3. Run the program**
```bash
./grade_tracker
```
> On Windows use: `grade_tracker` instead of `./grade_tracker`

---

## 💻 Sample Output

```
 Welcome to the Student Grade Tracker!
     STUDENT GRADE TRACKER
 1. Add Student
 2. View All Students
 3. Find Topper
 4. Search Student
 5. Exit
 Enter your choice: 1

 Enter student name: Manan Jain
 How many subjects? (1-5): 3
   Subject 1 marks (0-100): 88
   Subject 2 marks (0-100): 92
   Subject 3 marks (0-100): 79

 Student "Manan Jain" added successfully!
```

```
 Name                Average     Grade   Subjects
 Manan Jain          86.33       B       3 subject(s)
 Rahul Sharma        91.00       A       3 subject(s)

 Topper: Rahul Sharma
   Average: 91.00%
   Grade  : A
```

---

## 📁 Project Structure

```
Student-Grade-Tracker/
│
└── grade_tracker.cpp    # Main source file
```

---

## 🧠 Concepts Used

- Structs
- Arrays & Functions
- Loops & Switch-case
- Input validation with `cin.fail()`
- String handling with `getline()`
- Formatted output with `iomanip`

---

## 👨‍💻 Author

**Manan Jain**
First Year B.Tech — Information Technology
Bhagwan Parshuram Institute of Technology, Delhi
GGSIPU

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue)](https://www.linkedin.com/in/manan-jain-89a12937b)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-black)](https://github.com/Manajain20)
