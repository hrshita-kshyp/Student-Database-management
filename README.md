# Student Database Management System

This is a simple Student Database Management System implemented in C++ using MySQL for database management. The system allows users to add, view, update, and delete student records from a MySQL database.

## Features

- **Add Student**: Add a new student record to the database.
- **View Students**: Retrieve and display all student records.
- **Update Student**: Update existing student records.
- **Delete Student**: Delete a student record from the database.

## Requirements

- C++ Compiler
- MySQL Server
- MySQL Connector/C++ (for database connectivity)
- CMake (optional, for building the project)

## Setup

### MySQL Setup

1. Install MySQL Server on your system.
2. Create a new database named `studentdb`.
3. Create a `students` table in the `studentdb` database using the following SQL script:

```sql
CREATE DATABASE IF NOT EXISTS studentdb;

USE studentdb;

CREATE TABLE IF NOT EXISTS students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    age INT,
    department VARCHAR(100)
);
