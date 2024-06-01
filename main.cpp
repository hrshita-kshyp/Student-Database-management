#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <mysql.h>

using namespace std;

MYSQL* conn;

void connectToDatabase() {
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "password", "studentdb", 3306, NULL, 0);
    if (conn) {
        cout << "Connected to the database successfully!" << endl;
    } else {
        cerr << "Failed to connect to the database: " << mysql_error(conn) << endl;
        exit(1);
    }
}

void executeSQL(const string& sql) {
    if (mysql_query(conn, sql.c_str())) {
        cerr << "SQL error: " << mysql_error(conn) << endl;
    }
}

void addStudent() {
    string name, department;
    int age;

    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student age: ";
    cin >> age;
    cout << "Enter student department: ";
    cin >> department;

    stringstream sql;
    sql << "INSERT INTO students (name, age, department) VALUES ('" << name << "', " << age << ", '" << department << "');";
    executeSQL(sql.str());
}

void viewStudents() {
    string sql = "SELECT * FROM students;";
    if (mysql_query(conn, sql.c_str())) {
        cerr << "SQL error: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES* res = mysql_store_result(conn);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(res))) {
        cout << "ID: " << row[0] << ", Name: " << row[1] << ", Age: " << row[2] << ", Department: " << row[3] << endl;
    }

    mysql_free_result(res);
}

void updateStudent() {
    int id;
    string name, department;
    int age;

    cout << "Enter student ID to update: ";
    cin >> id;
    cout << "Enter new student name: ";
    cin >> name;
    cout << "Enter new student age: ";
    cin >> age;
    cout << "Enter new student department: ";
    cin >> department;

    stringstream sql;
    sql << "UPDATE students SET name = '" << name << "', age = " << age << ", department = '" << department << "' WHERE id = " << id << ";";
    executeSQL(sql.str());
}

void deleteStudent() {
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;

    stringstream sql;
    sql << "DELETE FROM students WHERE id = " << id << ";";
    executeSQL(sql.str());
}

int main() {
    connectToDatabase();

    // Initialize the database
    string initSQL = "CREATE TABLE IF NOT EXISTS students ("
                     "id INT AUTO_INCREMENT PRIMARY KEY,"
                     "name VARCHAR(100),"
                     "age INT,"
                     "department VARCHAR(100));";
    executeSQL(initSQL);

    int choice;
    while (true) {
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                mysql_close(conn);
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
