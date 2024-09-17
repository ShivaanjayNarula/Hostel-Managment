# Hostel Allotment System - Project README
# Project Overview
This project is a Hostel Allotment System designed for managing student information for hostel allotments at Chitkara University. The system uses simple CSV files to store student data and user credentials, providing basic functionalities such as adding, updating, displaying, and deleting student records. It also includes a login and sign-in mechanism for user authentication.

Current Features
Login and Sign-In Functionality:

Registered users can log in to access the system.

New users can create an account through the sign-in option.

# Student Record Management:

**Add New Student:** Add student details such as roll number, name, date of birth, contact information, and hostel/room details.

**Update Student:** Update student details such as room number or phone number by roll number.

**Display Student:** View details of all students stored in the system.

**Delete Student:** Remove student records based on roll number.

**File Management:**

The project stores student information in a CSV file (STUDENTS.csv) and user login credentials in another CSV file (USER.csv).

File Structure
STUDENTS.csv: Stores student information with fields such as roll number, name, date of birth, phone number, room, hostel name, and parent contact details.
USER.csv: Stores usernames and passwords for system login.

**Technologies Used**

Language: C++

File Handling: CSV files for data storage

Console-Based: Text-based user interface


# How to Run

Clone or Download the repository to your local machine.

Ensure the file paths to the STUDENTS.csv and USER.csv files are correctly set for your environment.

These are currently set to absolute paths (e.g., /Users/shivaanjaynarula/Hostel Managment/).

Modify these paths in the code to suit your system.

Compile the C++ code using a standard compiler (e.g., g++): bash
Copy code
g++ hostel_allotment.cpp -o hostel_allotment
Run the compiled program:
bash
Copy code
./hostel_allotment
Use the menu to navigate between options like login, adding, or updating student details.

# Future Enhancements
**Database Integration:**

Transition from CSV files to a Relational Database such as MySQL or SQLite.

This will ensure better scalability, security, and efficiency for managing student records and user authentication.

Implement SQL Queries for more advanced filtering and sorting of student data.

**Graphical User Interface (GUI):**

Integrate a GUI using frameworks like Qt or SFML to make the system more user-friendly.

The GUI will replace the current console-based input and output, providing better interaction with buttons, forms, and search fields.

**Security Improvements:**

Implement password hashing and better user authentication using techniques like salted hashes to secure user login.

Add role-based access control, where only authorized administrators can modify student data.

**Additional Features:**

**Search Functionality:** Allow users to search for students based on various fields (e.g., roll number, name, city).

**Export/Import:** Add options to export or import student data in different formats (e.g., PDF, Excel).

**Notifications:** Implement a system to send automatic notifications to students or administrators for hostel assignments or updates.

# Contribution

Feel free to fork this repository and create pull requests for any additional features or improvements. Any feedback is welcome to improve the overall functionality of the project.

**Contact**
For any questions or support, please contact the project developer at:

Shivaanjay Narula

Email: shivaanjaynarula@gmail.com

Insta: [shivaanjaynarula](https://www.instagram.com/shivaanjaynarula/)

Twitter: [shivaanjaynarula](https://x.com/shivanjaynarula)
