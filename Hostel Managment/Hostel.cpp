#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

// Function prototypes
void newStu();
void update();
void display();
void deleteStu();
void exitApp();
void login();
void signIn();
void menu();

struct Date {
    long long month, day, year;
};

struct Student {
    string name;
    long long age;
    string city;
    string mail;
    string hostel_name;
    string room;
    string father_name;
    string mother_name;
    long long phone;
    long long parent_phone;
    long long roll;
    Date dob;
} add, upd, rem, students[100], temp;

long long check;   // for entry check through roll numbers
long long i, j, mexit;

// File paths
string students_file = "/Users/shivaanjaynarula/Hostel Managment/STUDENTS.csv";
string user_file = "/Users/shivaanjaynarula/Hostel Managment/USER.csv";

// User login data (for login and sign-in functionality)
string registered_username = "admin";
string registered_password = "password";

int main() {
    long long ch;
    cout << "************ WELCOME TO CHITKARA UNIVERSITY ************" << endl;
    cout << "************         HOSTEL ALLOTMENT       ************" << endl;
    cout << "************ 1. LOGIN                       ************" << endl;
    cout << "************ 2. SIGN IN                     ************" << endl;
    cin >> ch;
    
    if (ch == 1)
        login();   // Call login function
    else if (ch == 2)
        signIn();  // Call sign-in function
    else
        cout << "Invalid choice. Try again.\n";

    return 0;
}

// Function to display the main menu
void menu() {
    long long choice;
    system("clear");  // Clear the screen for Unix-based systems like macOS
    cout << "************WELCOME TO CHITKARA UNIVERSITY************" << endl;
    cout << "************     HOSTEL ALLOTMENT:        ************" << endl;
    cout << "************           MAIN MENU          ************" << endl;
    cout << "1. ENTER NEW STUDENT DETAILS" << endl;
    cout << "2. UPDATE STUDENT DETAILS" << endl;
    cout << "3. DISPLAY STUDENT DETAILS" << endl;
    cout << "4. REMOVE STUDENT DETAILS" << endl;
    cout << "5. EXIT" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            newStu();
            break;
        case 2:
            update();
            break;
        case 3:
            display();
            break;
        case 4:
            deleteStu();
            break;
        case 5:
            exitApp();
            break;
        default:
            menu();
    }
}

// Login function to authenticate users
void login() {
    system("clear");
    string username, password;
    
    cout << "************      LOGIN     ************" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open the user file and verify credentials
    fstream file(user_file, ios::in);
    if (!file.is_open()) {
        cout << "Error opening user file.\n";
        exit(1);
    }

    string saved_username, saved_password;
    while (getline(file, saved_username, ',') && getline(file, saved_password)) {
        if (username == saved_username && password == saved_password) {
            cout << "Login successful!\n";
            file.close();
            menu();  // Direct to the main menu after successful login
            return;
        }
    }

    file.close();
    cout << "Invalid credentials, please try again.\n";
    main();  // Restart the login process
}

// Sign-in function for registering new users
void signIn() {
    system("clear");
    string new_username, new_password;

    cout << "************      SIGN IN     ************" << endl;
    cout << "Enter new username: ";
    cin >> new_username;
    cout << "Enter new password: ";
    cin >> new_password;

    // Write the new user credentials to the user file
    fstream file(user_file, ios::app);
    if (!file.is_open()) {
        cout << "Error opening user file.\n";
        exit(1);
    }

    file << new_username << "," << new_password << endl;
    file.close();

    cout << "Sign-in successful! Please login.\n";
    main();  // Redirect to login after successful sign-in
}

// Add new student details
void newStu() {
    system("clear");
    fstream file(students_file, ios::app | ios::in);

    // Roll number validation
    roll:
    cout << "************      ADD STUDENT DETAILS     ************" << endl;
    cout << "ENTER ROLL NUMBER: ";
    cin >> check;

    string line;
    while (getline(file, line)) {
        // Parse the line to check for roll numbers
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        if (stoll(token) == check) {
            cout << "Student's roll number is already in use" << endl;
            file.close();
            goto roll;
        }
    }
    file.close();

    add.roll = check;
    cout << "ENTER THE NAME: ";
    cin.ignore();
    getline(cin, add.name);

    // Validate date of birth
    bool valid = false;
    while (!valid) {
        cout << "ENTER THE DATE OF BIRTH (DD MM YYYY): ";
        cin >> add.dob.day >> add.dob.month >> add.dob.year;

        // Date validation
        if (add.dob.year >= 1900 && add.dob.year <= 9999) {
            if (add.dob.month >= 1 && add.dob.month <= 12) {
                if (((add.dob.day >= 1 && add.dob.day <= 31) && (add.dob.month == 1 || add.dob.month == 3 || add.dob.month == 5 || add.dob.month == 7 || add.dob.month == 8 || add.dob.month == 10 || add.dob.month == 12)) ||
                    ((add.dob.day >= 1 && add.dob.day <= 30) && (add.dob.month == 4 || add.dob.month == 6 || add.dob.month == 9 || add.dob.month == 11)) ||
                    ((add.dob.day >= 1 && add.dob.day <= 28) && (add.dob.month == 2)) || (add.dob.day == 29 && add.dob.month == 2 && (add.dob.year % 400 == 0 || (add.dob.year % 4 == 0 && add.dob.year % 100 != 0)))) {
                    valid = true;
                } else {
                    cout << "Day is invalid.\n";
                }
            } else {
                cout << "Month is not valid.\n";
            }
        } else {
            cout << "Year is not valid.\n";
        }
    }

    cout << "ENTER THE AGE: ";
    cin >> add.age;
    cout << "ENTER THE CITY: ";
    cin.ignore();
    getline(cin, add.city);
    cout << "ENTER THE PHONE NUMBER: ";
    cin >> add.phone;
    cout << "ENTER THE EMAIL ID: ";
    cin.ignore();
    getline(cin, add.mail);
    cout << "ENTER THE FATHER'S NAME: ";
    cin.ignore();
    getline(cin, add.father_name);
    cout << "ENTER THE PARENT'S PHONE NUMBER: ";
    cin >> add.parent_phone;
    cout << "ENTER THE ROOM NUMBER: ";
    cin.ignore();
    getline(cin, add.room);
    cout << "ENTER THE HOSTEL NAME: ";
    getline(cin, add.hostel_name);

    // Write the new student details to the file
    file.open(students_file, ios::app);
    if (!file.is_open()) {
        cout << "Error opening students file.\n";
        exit(1);
    }

    file << add.roll << "," << add.name << "," << add.dob.day << "/" << add.dob.month << "/" << add.dob.year << "," << add.age << "," << add.city << "," << add.phone << "," << add.mail << "," << add.father_name << "," << add.parent_phone << "," << add.room << "," << add.hostel_name << endl;
    file.close();

    cout << "***********  STUDENT ADDED SUCCESSFULLY   ************" << endl;

    cout << "ENTER 1 TO GO TO MAIN MENU AND 0 TO EXIT: ";
    cin >> mexit;

    if (mexit == 1)
        menu();
    else if (mexit == 0)
        exitApp();
}

// Update student details
void update() {
    system("clear");
    long long choice;
    bool recordFound = false;

    fstream oldFile, newFile;
    oldFile.open(students_file, ios::in);
    newFile.open("/Users/shivaanjaynarula/Hostel Managment/NEW_RECORD.csv", ios::out);

    if (!oldFile.is_open() || !newFile.is_open()) {
        cout << "Error opening file.\n";
        return;
    }

    cout << "ENTER THE ROLL NUMBER YOU WANT TO CHANGE THE DETAILS OF: ";
    cin >> upd.roll;

    string line;
    while (getline(oldFile, line)) {
        stringstream ss(line);
        string token;

        // Read the roll number (first field in the CSV)
        getline(ss, token, ',');
        
        // Check if the token is not empty
        if (!token.empty()) {
            try {
                long long roll_num = stoll(token);  // Convert to long long

                // If the roll number matches, allow updates
                if (roll_num == upd.roll) {
                    recordFound = true;
                    cout << "Record found for roll number: " << upd.roll << endl;

                    cout << "ENTER 1 TO UPDATE ROOM NUMBER OR 2 TO UPDATE PHONE NUMBER: ";
                    cin >> choice;

                    string name, dob, city, mail, father_name, room, hostel_name;
                    long long age, phone, parent_phone;

                    // Parse the rest of the fields
                    getline(ss, name, ',');
                    getline(ss, dob, ',');
                    ss >> age;
                    getline(ss, token, ',');  // Skip the comma
                    getline(ss, city, ',');
                    ss >> phone;
                    getline(ss, token, ',');  // Skip the comma
                    getline(ss, mail, ',');
                    getline(ss, father_name, ',');
                    ss >> parent_phone;
                    getline(ss, token, ',');  // Skip the comma
                    getline(ss, room, ',');
                    getline(ss, hostel_name, ',');

                    // Update based on user's choice
                    if (choice == 1) {
                        cout << "ENTER NEW ROOM NUMBER: ";
                        cin.ignore();
                        getline(cin, upd.room);
                        room = upd.room;  // Update room
                    } else if (choice == 2) {
                        cout << "ENTER NEW PHONE NUMBER: ";
                        cin >> upd.phone;
                        phone = upd.phone;  // Update phone
                    }

                    // Write the updated record to the new file
                    newFile << roll_num << "," << name << "," << dob << "," << age << "," << city << "," << phone << "," << mail << ","
                            << father_name << "," << parent_phone << "," << room << "," << hostel_name << endl;

                    cout << "Changes saved successfully!" << endl;

                } else {
                    // If roll number doesn't match, copy the existing record as-is
                    newFile << line << endl;
                }
            } catch (const invalid_argument& e) {
                cout << "Invalid roll number format in the file: " << token << endl;
                continue;  // Skip invalid lines
            }
        }
    }

    oldFile.close();
    newFile.close();

    // Replace the old file with the new file
    remove(students_file.c_str());
    rename("/Users/shivaanjaynarula/Hostel Managment/NEW_RECORD.csv", students_file.c_str());

    if (!recordFound) {
        cout << "Record not found!" << endl;
    }

    cout << "ENTER 1 TO RETURN TO MAIN MENU AND 0 TO EXIT: ";
    cin >> mexit;

    if (mexit == 1)
        menu();
    else
        exitApp();
}




// Display all student details
void display() {
    system("clear");
    fstream file(students_file, ios::in);

    if (!file.is_open()) {
        cout << "Error opening students file.\n";
        exit(1);
    }

    cout << "************ STUDENT RECORD ************" << endl;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        cout << "Roll Number: " << token << endl;

        getline(ss, token, ',');
        cout << "Name: " << token << endl;

        getline(ss, token, ',');
        cout << "DOB: " << token << endl;

        getline(ss, token, ',');
        cout << "Age: " << token << endl;

        getline(ss, token, ',');
        cout << "City: " << token << endl;

        getline(ss, token, ',');
        cout << "Phone: " << token << endl;

        getline(ss, token, ',');
        cout << "Email: " << token << endl;

        getline(ss, token, ',');
        cout << "Father's Name: " << token << endl;

        getline(ss, token, ',');
        cout << "Parent's Phone: " << token << endl;

        getline(ss, token, ',');
        cout << "Room: " << token << endl;

        getline(ss, token, ',');
        cout << "Hostel: " << token << endl;

        cout << "--------------------------------------" << endl;
    }
    file.close();

    cout << "ENTER 1 TO RETURN TO MAIN MENU AND 0 TO EXIT: ";
    cin >> mexit;

    if (mexit == 1)
        menu();
    else
        exitApp();
}

// Delete a student record
void deleteStu() {
    system("clear");
    long long roll;
    fstream oldFile, newFile;
    oldFile.open(students_file, ios::in);
    newFile.open("/Users/shivaanjaynarula/Hostel Managment/NEW_RECORD.csv", ios::out);

    if (!oldFile.is_open() || !newFile.is_open()) {
        cout << "Error opening file.\n";
        return;
    }

    cout << "ENTER ROLL NUMBER OF STUDENT TO REMOVE: ";
    cin >> roll;

    string line;
    bool recordFound = false;

    while (getline(oldFile, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');  // Get the roll number as a string

        // Check if token is not empty and can be converted to a number
        if (!token.empty()) {
            try {
                long long roll_num = stoll(token);  // Convert to long long

                // If the roll number doesn't match, copy the line to the new file
                if (roll_num != roll) {
                    newFile << line << endl;
                } else {
                    recordFound = true;  // Indicate that the record was found
                }
            } catch (const invalid_argument& e) {
                cout << "Invalid roll number format in the file: " << token << endl;
                continue;  // Skip invalid lines
            }
        }
    }

    oldFile.close();
    newFile.close();

    // Replace the old file with the new file
    remove(students_file.c_str());
    rename("/Users/shivaanjaynarula/Hostel Managment/NEW_RECORD.csv", students_file.c_str());

    if (recordFound) {
        cout << "STUDENT RECORD DELETED!" << endl;
    } else {
        cout << "Record not found!" << endl;
    }

    cout << "ENTER 1 TO RETURN TO MAIN MENU AND 0 TO EXIT: ";
    cin >> mexit;

    if (mexit == 1)
        menu();
    else
        exitApp();
}


// Exit the application
void exitApp() {
    cout << "THANK YOU FOR USING THE SYSTEM!" << endl;
    exit(0);
}
