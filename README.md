# University Admission Management System

Complete **Indian University Admission System** for Bachelor's programs (B.E CSE/ECE/ME, B.Sc Physics/Maths, B.A English) with merit calculation, eligibility checking, scholarships, and file-based data management.

## ✨ **Features**

- **Merit Calculation**: 30% (12th Board) + 70% (Entrance Exam - JEE/NEET/CET)
- **6 Programs** with cutoffs: B.Tech CSE(75%), ECE(70%), ME(65%), B.Sc Physics(60%), Maths(55%), B.A English(50%)
- **Scholarships**: 60% (≥90%), 40% (≥80%), 20% (≥70%)
- **File Outputs**: Main log + Program-specific + Rejected applicants
- **Input Validation**: Percentage bounds checking with auto-correction
- **Unlimited Processing**: Continuous student application loop

## 📊 **Demo Output Files**
University_Admissions.txt # Main admission records
B.Tech_CSE_Students.txt # Admitted CSE students
Not_Eligible_Students.txt # Rejected applicants


## 🚀 **Quick Start**
g++ -o admission main.cpp -std=c++17
./admission # Linux/Mac
admission.exe # Windows


## 🎮 **Sample Run**
UNIVERSITY ADMISSION SYSTEM
Bachelor's Degree Programs
[STEP 1] PERSONAL DETAILS INPUT
Full Name: Raj Kumar
...
Calculated Merit: 82.50%
✓ Congratulations! Eligible for B.E CSE!
Scholarship: 40% Merit Scholarship Awarded!
Total Fees: ₹90,000

## 📸 Sample Outputs
Below are sample screenshots demonstrating the console execution and generated files from the University Admission System.

![Console Input and Output](output1.png)
![Console Input and Output](output2.png)

![Generated Admission File](fileoutput.png)

![Program-wise Student List](fileoutput2.png)
