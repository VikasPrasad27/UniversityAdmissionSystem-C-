#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

struct StudentInfo {
    string name, fatherName, motherName, address, city, state;
    string phone, email, gender;
    int age;
    long long aadhar, universityRollNo;
    float board12Marks, board12Percentage;
    string board12Name;
    float entranceMarks, entrancePercentage;
    string entranceExamType;
    float calculatedMerit;
    string admittedProgram;
    float scholarship;
    float totalFeesToPay;
};

void inputStudentDetails(StudentInfo &s);
void input12thDetails(StudentInfo &s);
void inputEntranceDetails(StudentInfo &s);
float calculateMerit(float board12, float entrance);
void displayPrograms();
void checkEligibilityAndAdmit(StudentInfo &s);
void calculateScholarship(StudentInfo &s);
void saveToDatabases(StudentInfo &s);

int main() {
    char continueChoice;
    cout << "\n========================================" << endl;
    cout << "  UNIVERSITY ADMISSION SYSTEM" << endl;
    cout << "  Bachelor's Degree Programs" << endl;
    cout << "========================================\n" << endl;
    do {
        StudentInfo student;
        cout << "\n[STEP 1] PERSONAL DETAILS INPUT" << endl;
        cout << "-----------------------------------" << endl;
        inputStudentDetails(student);
        cout << "\n[STEP 2] 12TH GRADE DETAILS" << endl;
        cout << "-----------------------------------" << endl;
        input12thDetails(student);
        cout << "\n[STEP 3] ENTRANCE EXAM DETAILS" << endl;
        cout << "-----------------------------------" << endl;
        inputEntranceDetails(student);
        student.calculatedMerit = calculateMerit(student.board12Percentage, student.entrancePercentage);
        cout << "\n[MERIT CALCULATED]: " << fixed << setprecision(2) << student.calculatedMerit << "%" << endl;
        cout << "\n[STEP 4] PROGRAM SELECTION" << endl;
        cout << "-----------------------------------" << endl;
        displayPrograms();
        checkEligibilityAndAdmit(student);
        calculateScholarship(student);
        saveToDatabases(student);
        cout << "\n========================================" << endl;
        cout << "  APPLICATION SUBMITTED SUCCESSFULLY!" << endl;
        cout << "========================================" << endl;
        cout << "\nStudent Merit: " << fixed << setprecision(2) << student.calculatedMerit << "%" << endl;
        cout << "Admitted Program: " << student.admittedProgram << endl;
        cout << "Scholarship: " << student.scholarship << "%" << endl;
        cout << "Total Fees to Pay: " << student.totalFeesToPay << endl;
        cout << "\n\nDo you want to process another application? (Y/N): ";
        cin >> continueChoice;
        cin.ignore();
    } while(continueChoice == 'Y' || continueChoice == 'y');
    cout << "\nThank you for using the admission system!" << endl;
    return 0;
}

void inputStudentDetails(StudentInfo &s) {
    cout << "Full Name: ";
    getline(cin, s.name);
    cout << "Father's Name: ";
    getline(cin, s.fatherName);
    cout << "Mother's Name: ";
    getline(cin, s.motherName);
    cout << "Age: ";
    cin >> s.age;
    cout << "Gender (M/F/Other): ";
    cin >> s.gender;
    cout << "Aadhar Number: ";
    cin >> s.aadhar;
    cout << "Phone Number (10 digits): ";
    cin >> s.phone;
    cin.ignore();
    cout << "Email: ";
    getline(cin, s.email);
    cout << "Address: ";
    getline(cin, s.address);
    cout << "City: ";
    getline(cin, s.city);
    cout << "State: ";
    getline(cin, s.state);
}

void input12thDetails(StudentInfo &s) {
    cout << "12th Board Name (CBSE/State Board/ICSE): ";
    getline(cin, s.board12Name);
    cout << "12th Marks Obtained: ";
    cin >> s.board12Marks;
    cout << "12th Percentage: ";
    cin >> s.board12Percentage;
    if(s.board12Percentage > 100) {
        cout << "[ERROR] Invalid percentage! Setting to 0." << endl;
        s.board12Percentage = 0;
    }
}

void inputEntranceDetails(StudentInfo &s) {
    cout << "Entrance Exam Type (JEE/NEET/State CET/Other): ";
    cin.ignore();
    getline(cin, s.entranceExamType);
    cout << "Entrance Exam Marks (out of 100): ";
    cin >> s.entranceMarks;
    s.entrancePercentage = s.entranceMarks;
    if(s.entrancePercentage > 100) {
        cout << "[ERROR] Invalid marks! Setting to 0." << endl;
        s.entrancePercentage = 0;
    }
}

float calculateMerit(float board12, float entrance) {
    float merit = (board12 * 0.30) + (entrance * 0.70);
    return merit;
}

void displayPrograms() {
    cout << "Available Bachelor's Programs:\n" << endl;
    cout << "ENGINEERING PROGRAMS:" << endl;
    cout << "1. B.E CSE (Computer Science & Engineering) - Cutoff: 75%" << endl;
    cout << "2. B.E ECE (Electronics & Communication) - Cutoff: 70%" << endl;
    cout << "3. B.E ME (Mechanical Engineering) - Cutoff: 65%" << endl;
    cout << "\nSCIENCE PROGRAMS:" << endl;
    cout << "4. B.Sc Physics - Cutoff: 60%" << endl;
    cout << "5. B.Sc Mathematics - Cutoff: 55%" << endl;
    cout << "\nARTS PROGRAMS:" << endl;
    cout << "6. B.A English - Cutoff: 50%" << endl;
    cout << "\nSelect Program (1-6): ";
}

void checkEligibilityAndAdmit(StudentInfo &s) {
    int choice;
    cin >> choice;
    bool eligible = false;
    switch(choice) {
        case 1:
            if(s.calculatedMerit >= 75) {
                s.admittedProgram = "B.Tech CSE";
                eligible = true;
                cout << "\nCongratulations! You are eligible for B.Tech CSE!" << endl;
            }
            break;
        case 2:
            if(s.calculatedMerit >= 70) {
                s.admittedProgram = "B.Tech ECE";
                eligible = true;
                cout << "\nCongratulations! You are eligible for B.Tech ECE!" << endl;
            }
            break;
        case 3:
            if(s.calculatedMerit >= 65) {
                s.admittedProgram = "B.Tech ME";
                eligible = true;
                cout << "\nCongratulations! You are eligible for B.Tech ME!" << endl;
            }
            break;
        case 4:
            if(s.calculatedMerit >= 60) {
                s.admittedProgram = "B.Sc Physics";
                eligible = true;
                cout << "\nCongratulations! You are eligible for B.Sc Physics!" << endl;
            }
            break;
        case 5:
            if(s.calculatedMerit >= 55) {
                s.admittedProgram = "B.Sc Mathematics";
                eligible = true;
                cout << "\nCongratulations! You are eligible for B.Sc Mathematics!" << endl;
            }
            break;
        case 6:
            if(s.calculatedMerit >= 50) {
                s.admittedProgram = "B.A English";
                eligible = true;
                cout << "\nCongratulations! You are eligible for B.A English!" << endl;
            }
            break;
        default:
            cout << "\nInvalid choice!" << endl;
    }
    if(!eligible) {
        cout << "\nSorry! You are not eligible for the selected program." << endl;
        cout << "Your merit (" << fixed << setprecision(2) << s.calculatedMerit << "%) is below the cutoff." << endl;
        s.admittedProgram = "Not Admitted";
    }
}

void calculateScholarship(StudentInfo &s) {
    float baseFee = 100000;
    if(s.admittedProgram == "Not Admitted") {
        s.totalFeesToPay = 0;
        s.scholarship = 0;
        return;
    }
    if(s.admittedProgram.find("B.Tech") != string::npos) {
        baseFee = 150000;
    }
    if(s.calculatedMerit >= 90) {
        s.scholarship = 60;
        s.totalFeesToPay = baseFee * (1 - s.scholarship / 100);
        cout << "Scholarship: 60% Merit Scholarship Awarded!" << endl;
    }
    else if(s.calculatedMerit >= 80) {
        s.scholarship = 40;
        s.totalFeesToPay = baseFee * (1 - s.scholarship / 100);
        cout << "Scholarship: 40% Merit Scholarship Awarded!" << endl;
    }
    else if(s.calculatedMerit >= 70) {
        s.scholarship = 20;
        s.totalFeesToPay = baseFee * (1 - s.scholarship / 100);
        cout << "Scholarship: 20% Merit Scholarship Awarded!" << endl;
    }
    else {
        s.scholarship = 0;
        s.totalFeesToPay = baseFee;
        cout << "Scholarship: No scholarship. Full fees applicable." << endl;
    }
}

void saveToDatabases(StudentInfo &s) {
    ofstream mainFile("University_Admissions.txt", ios::app);
    if(mainFile.is_open()) {
        mainFile << "Name: " << s.name << endl;
        mainFile << "Father's Name: " << s.fatherName << endl;
        mainFile << "Aadhar: " << s.aadhar << endl;
        mainFile << "12th Percentage: " << s.board12Percentage << "% (" << s.board12Name << ")" << endl;
        mainFile << "Entrance Exam: " << s.entranceExamType << " - " << s.entrancePercentage << "%" << endl;
        mainFile << "Merit: " << s.calculatedMerit << "%" << endl;
        mainFile << "Program: " << s.admittedProgram << endl;
        mainFile << "Scholarship: " << s.scholarship << "%" << endl;
        mainFile << "Fees to Pay: " << s.totalFeesToPay << endl;
        mainFile << "------------------------------" << endl;
        mainFile.close();
    }
    if(s.admittedProgram != "Not Admitted") {
        string filename = s.admittedProgram + "_Students.txt";
        ofstream programFile(filename.c_str(), ios::app);
        if(programFile.is_open()) {
            programFile << s.name << "\t" << s.aadhar << "\t" << s.calculatedMerit << "\t" << s.email << endl;
            programFile.close();
        }
    } else {
        ofstream rejectedFile("Not_Eligible_Students.txt", ios::app);
        if(rejectedFile.is_open()) {
            rejectedFile << s.name << "\t" << s.aadhar << "\t" << s.calculatedMerit << "\t" << s.entranceExamType << endl;
            rejectedFile.close();
        }
    }
}