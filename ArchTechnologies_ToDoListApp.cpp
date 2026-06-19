//======================================================================
//                   Arch Technologies To-Do List App Project 1
//======================================================================

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Task {
private:
    string Studentname;
    string Rollnum;
    string Taskname;
    string date;
   
public:
    Task() {
        Studentname = "";
        Rollnum = "";
        Taskname = "";
        date = "";
    }

    void Set_Task_Details() {
        cin.ignore();
        cout << "Enter Student Name: " << endl;
        getline(cin, Studentname);

        cout << "Enter Student Roll Number: " << endl;
        getline(cin, Rollnum);

        cout << "Enter Task Name: " << endl;
        getline(cin, Taskname);

        cout << "Enter Date of Submission (DD/MM/YYYY): " << endl;
        getline(cin, date);
        
        cout << "Task Added Successfully!" << endl;
    }

    void Display_Task_Details() {
        cout << "\n----------------------------------\n";
        cout << "Student Name: " << Studentname << endl;
        cout << "Student Roll Number: " << Rollnum << endl;
        cout << "Task Name: " << Taskname << endl;
        cout << "Date of Submission: " << date << endl;
        cout << "----------------------------------" << endl;
    }

    string GetTaskName() {
        return Taskname;
    }

    string GetRollNumber() {
        return Rollnum;
    }

    bool isEmpty() {
        return Taskname == "";
    }

    void SaveToFile(ofstream &file) {
        file << "Student Name:"<< Studentname << endl;
        file << "Student Roll Number:"<< Rollnum << endl;
        file << "Task Name:"<< Taskname << endl;
        file << "Date of Submission:"<< date << endl;
    }
};

class ToDoListApp {
private:
    Task arr[100];  // Storing task upto 100
    int TotalTask;

public:
    ToDoListApp() {
        TotalTask = 0;  // Default Constructor
    }

    // Add Task

    void AddTask() {
        if (TotalTask >= 100) {
            cout << "Maximum Task Limit Reached!" << endl;
            return;
        }
        
        arr[TotalTask].Set_Task_Details();
        TotalTask++;
        SaveTasks();
    }

    // View Task

    void ViewTasks() {
        if (TotalTask == 0) {
            cout << "Sorry! No Tasks Available." << endl;
            return;
        }
        
        cout << "========== View Analytics ==========\n";
        for (int i = 0; i < TotalTask; i++) {
            cout << "Task #" << i + 1;
            arr[i].Display_Task_Details();
            cout << "-----------------------------------" << endl;
        }
    }

    // Search Task

    void SearchTask() {
        if (TotalTask == 0) {
            cout << "Sorry! No Tasks Available." << endl;
            return;
        }
        
        string roll;
        cin.ignore();
        cout << "Enter Student Roll Number: ";
        getline(cin, roll);
        
        bool found = false;
        
        for (int i = 0; i < TotalTask; i++) {
            if (arr[i].GetRollNumber() == roll) {
                cout << "Task Found Successfully!" << endl;
                arr[i].Display_Task_Details();
                cout << "--------------------------------- " << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "No Record Found for Roll Number: " << roll << endl;
        }
    }

    // Delete Task

    void DeleteTask() {
        if (TotalTask == 0) {
            cout << "Sorry! No Tasks Available." << endl;
            return;
        }
        
        int Tasknum;
        cout << "Enter Task Number To Delete: ";
        cin >> Tasknum;
        
        if (Tasknum < 1 || Tasknum > TotalTask) {
            cout << "Invalid Task Number!" << endl;
            return;
        }
        
        for (int i = Tasknum - 1; i < TotalTask - 1; i++) {
            arr[i] = arr[i + 1];
        }
        
        TotalTask--;
        SaveTasks();
        cout << "Task Deleted Successfully!" << endl;
    }

    // Save Tasks to File ( File Handling )

    void SaveTasks() {
        ofstream file("tasks.txt");
        if (file.is_open()) {
            for (int i = 0; i < TotalTask; i++) {
                arr[i].SaveToFile(file);
            }
            file.close();
            cout << "Tasks Saved Successfully!" << endl;
        } else {
            cout << "Error: Unable to save tasks to file!" << endl;
        }
    }

    // Main Menu

    void Menu() {
        int choice;

        do {
            cout << "====================================" << endl;
            cout << "                 MENU               " << endl;
            cout << "====================================" << endl;
            cout << "1. Add Task" << endl;
            cout << "2. View Tasks" << endl;
            cout << "3. Search Task" << endl;
            cout << "4. Delete Task" << endl;
            cout << "5. Exit" << endl;
            cout << "====================================" << endl;
            cout << "Enter Choice: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    AddTask();
                    break;
                case 2:
                    ViewTasks();
                    break;
                case 3:
                    SearchTask();
                    break;
                case 4:
                    DeleteTask();
                    break;
                case 5:
                    cout << "Thank You For Using The App!" << endl;
                    break;
                default:
                    cout << "Invalid Choice! Please try again." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    ToDoListApp TodoList;
    TodoList.Menu();

    return 0;
}