# 📝 To-Do List App

>**Project 1 — C++ CLI Application**

A terminal-based To-Do List application built in C++ using Object-Oriented Programming concepts. The app allows users to add, view, search, and delete student tasks, with persistent file storage.

---

## 📁 Project Structure

```
ToDoListApp/
├── main.cpp        # Source code
├── tasks.txt       # Auto-generated file storing task records
└── README.md       # Project documentation
```

---

## ⚙️ Features

- **Add Task** — Enter student name, roll number, task name, and submission date
- **View Tasks** — Display all saved tasks in a formatted list
- **Search Task** — Look up tasks by student roll number
- **Delete Task** — Remove a task by its number (auto-shifts remaining tasks)
- **File Storage** — Tasks are saved to `tasks.txt` automatically after every add or delete

---

## 🧱 OOP Concepts Used

| Concept | Usage |
|---|---|
| **Classes** | `Task` and `ToDoListApp` classes |
| **Encapsulation** | Private data members with public methods |
| **Constructors** | Default constructors to initialize data |
| **Object Arrays** | Array of `Task` objects (up to 100) |
| **File Handling** | `ofstream` used to persist tasks |

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`, MinGW, or any IDE like Code::Blocks / Visual Studio)

### Compilation

```bash
g++ main.cpp -o todoapp
```

### Run

```bash
./todoapp
```

---

## 🖥️ Menu Options

```
====================================
                MENU
====================================
1. Add Task
2. View Tasks
3. Search Task
4. Delete Task
5. Exit
====================================
```

---

## 📌 Usage Example

```
Enter Student Name:
Ali Hassan
Enter Student Roll Number:
CS-2023-45
Enter Task Name:
OOP Assignment 1
Enter Date of Submission (DD/MM/YYYY):
25/06/2025
Task Added Successfully!
Tasks Saved Successfully!
```

---

## 💾 File Output (`tasks.txt`)

```
Student Name:Ali Hassan
Student Roll Number:CS-2023-45
Task Name:OOP Assignment 1
Date of Submission:25/06/2025
```

---

## ⚠️ Limitations

- Supports a maximum of **100 tasks**
- Tasks are **not loaded back** from `tasks.txt` on restart (in-memory only per session)
- No task completion/status tracking in this version

---

## 🛠️ Future Improvements

- Load tasks from file on startup
- Mark tasks as complete
- Sort/filter tasks by date or roll number
- Add update/edit functionality

---

## 👨‍💻 Author

**Hamza Khan Sherwani**
**Assigned by ArchTechnologies.Tech**
> Building real-world projects through code.
