-- Create the database if it doesn't exist
CREATE DATABASE IF NOT EXISTS studentdb;

-- Use the created database
USE studentdb;

-- Create the students table if it doesn't exist
CREATE TABLE IF NOT EXISTS students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    age INT,
    department VARCHAR(100)
);

INSERT INTO students (name, age, department) VALUES ('John Doe', 20, 'Computer Science');
INSERT INTO students (name, age, department) VALUES ('Jane Smith', 22, 'Mechanical Engineering');
