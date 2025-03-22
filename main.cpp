/******************************************************************************************************
 *  TCP1101 Assignment                                                                                *
 * Trimester 1, 2021/2022                                                                             *
 * Team Leader : Nurzafirah Syazana, 0163452245, 1201101587@student.mmu.edu.my                        *
 * Team member:                                                                                       *
 * 1. Anis Balqis Binti Rizaludin,  01111529032 , 1201101872@student.mmu.edu.my                       *
 * 2. Nurfarra Sabreena Binti Zamzuri, 0133580332, 1201100740@student.mmu.edu.my                      *
 * 3. Ameera Farhana Binti Farizal, 0183226449, 1201101870@student.mmu.edu.my                         *
/*****************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>
#include <conio.h>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <cstdio>
#include <windows.h>

using namespace std;

/******************************************************************************************************
 *                                     FUNCTION PROTOTYPES                                            *
/*****************************************************************************************************/
void clearScreen();
void login(vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
void displayHeader(string);
bool loginPage(vector<vector<string>>&, string&, string&, string&, string&);
bool loginValidation(vector<vector<string>>&,string&, string&, string&, string&);
vector<vector<string>> openFile(string);
void displayAdminPage(vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
void displayBuyerPage(vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
void adminPage();
void buyerPage();
void changePassword(vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
bool testPassword(char[]);
bool initialIsAlpha(char[]);
int countDigits(char*);
int countCapitalLetters(char*);
void updatePass(vector<vector<string>>&, string&, string);
void passVerified(vector<vector<string>>&, string&, string&, string,string&, string&, vector<string>&);
void writeTodbUserAccount(vector<vector<string>>&);
void backToAdminOrBuyer(vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
void createNewUser(vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
void displayInstructionToCreate();
void deleteBuyer(vector<vector<string>>&, string&, string&, string&, string&);
void displayListOfUser (vector<vector<string>>&);
void logOut(vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
void analyzeData(vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
vector<vector<int>> openDataFile(string, vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
vector<int> newVector(string);
void dataCalculation(vector<vector<int>>, vector<vector<string>>&, string&, string&, string&, string&, vector<string>&, string&);
void operationHeader(string);
void displayInstruction();
bool openFile(const fstream&, const string&);
string renamefile(vector<string>&, string);
void statisticalMenu();
void nextOperation(vector<vector<int>>, vector<vector<string>>&, string&, string&, string&, string&, vector<string>&, string&);
void minInRow(vector<vector<int>>vect, int N, int M);
void minInCol(vector<vector<int>>vect, int N, int M);
void maxInRow(vector<vector<int>>vect, int N, int M);
void maxInCol(vector<vector<int>>vect, int N, int M);
void medianInRow(vector<vector<int>>vect, int N, int M);
void medianInCol(vector<vector<int>>vect, int N, int M);
vector<vector<int>> transpose(vector<vector<int>> vect, int N, int M);
void colSort(vector<vector<int>>& newvect);
void meanInRow(vector<vector<int>>vect, int N, int M);
void meanInCol(vector<vector<int>>vect, int N, int M);
void inputvarianceColumn();
void inputvarianceRow();
void inputstdeviationCol();
void inputstdeviationRow();
double varianceColumn(int);
double varianceRow(int);
double stdeviationCol(int);
double stdeviationRow (int);
void inputPearson();
void pearsoncoeff(int,int);
void printFrequency(vector<int> vec);
int chooseColumnTable (int option);
void displayTable (int &option);
void displayTable2 (int &option);
void displayTable3 (int &option);
void displayTable4 (int &option);
void displayTable5 (int &option);
int chooseColumnHis (int choice);
void displayHisto (int &choice, string&);
void displayHisto2 (int &choice, string&);
void displayHisto3 (int &choice, string&);
void displayHisto4 (int &choice, string&);
void displayHisto5 (int &choice, string&);
void displayLogTransaction(vector<string>& );
void continueHTMLmenu(vector<vector<int>>, vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
void continueTXTmenu(vector<vector<int>>, vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
void TXTreportsMenu(vector<vector<int>>, vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
void HTMLreportsMenu(vector<vector<int>>, vector<vector<string>>&, string&, string&, string&, string&, vector<string>&);
int allStatisticalReportHTML();
int IndividualReportHTML();
void createLogFile(vector<string>& transLog, string& user);


string fileName="data.txt";

int main() {
    int adminOption, buyerOption;
    string currentUser, currentPassword, currentType, currentStatus;
    vector<string> logTransaction; // declare 1D vector for lo transaction

    vector<vector<string>> userAccountVector = openFile("dbUserAccount.txt"); // store user details in 2D vector
    login(userAccountVector, currentUser, currentPassword, currentType, currentStatus, logTransaction); // call function to log in into program

    return 0;
}

/************************************************************************************
/ This function is to clear the whole screen before it is called.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void clearScreen() {
    system( "cls" ); // can change to either "cls" or "clear"
}


/************************************************************************************
/ This function will check whether the user has successfully log in or not.
/ if the log in failed, the user needs to re-enter their username.
/ if the log in succeed, the user will be leaded to next page dependin on their usertype.
/ The program will go to admin page for administator and buyer page for buyer.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void login(vector<vector<string>>& dbUserAcc, string& userName, string& userPassword, string& userType, string& userStatus, vector<string>& log) {
    bool accValid = false;   // declare boolean
    string transaction1 = "Log in into administrator account", transaction2 = "Log in into buyer account"; // log transaction
    do {
        accValid= loginPage(dbUserAcc, userName, userPassword, userType, userStatus); // ask input from user and pass boolean value
        if (!accValid) {
            cout << "Username and password entered are invalid. Please fill in again." << endl;
            userName = " ";
        }
        else {
            clearScreen();
            if (userStatus == "Active"){
                cout << "Successfully Login!" << endl << endl;
                if (userType == "Admin"){
                    log.push_back(transaction1);       // add name of transaction in vector logTransaction
                    clearScreen();
                    displayHeader(userName);
                    displayAdminPage(dbUserAcc, userName, userPassword, userType, userStatus, log);  // go to main page for admin
                }
                else{
                    log.push_back(transaction2);
                    clearScreen();
                    displayHeader(userName);
                    displayBuyerPage(dbUserAcc, userName, userPassword, userType, userStatus, log);  // go to main page for buyer
                }
            }
            else {
                cout << "Your account has been deleted. Please contact admin if you think this is a mistake." << endl;
            }
        }
    } while(!accValid);
}


/************************************************************************************
/ This function will display the header of the program along with the current user.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void displayHeader(string user) {
    cout << "*--------------------------------------*" << endl;
    cout << setw(10) << "- "<< "WELCOME " << "TO " << "BDAP" << " -" << endl;
    cout << "*--------------------------------------*" << endl ;
    cout << setw(15) << "Current " << "user: " << user << endl << endl;
}


/************************************************************************************
/ This function requires the user to input his username and password.
/ Username and password will be checked for validation.
/ Student : Nurzafirah Syazana
*************************************************************************************/
bool loginPage(vector<vector<string>>& dbUser, string& name, string& pass, string& type, string& status ) {
    bool valid = false;

    displayHeader(name);
    cout << "To continue to the system, please log in.\n\n"
         << "Enter your username: ";
    cin  >> name;
    cout << "Enter your password: ";
    cin  >> pass;
    valid = loginValidation(dbUser, name, pass, type, status);
    return valid;
}


/************************************************************************************
/ This function will compare the username and password entered by the user.
/ It checks whether the username and password exist or not in 2D vector dbUserAcc.
/ 2D vector dbUserAcc is loaded from dbUserAccount.txt.
/ Student : Nurzafirah Syazana
*************************************************************************************/
bool loginValidation(vector<vector<string>>& dbUserAcc, string& username, string& password, string& usertype, string& stat) {
    bool validity = false;

        for(int i = 0; i < dbUserAcc.size(); i++) {
            for( int j =0; j < 4; j++) {
                if (dbUserAcc[i][0] == username) {
                    if (dbUserAcc[i][1] == password) {
                        validity = true;
                        usertype = dbUserAcc[i][2];
                        stat = dbUserAcc[i][3];;
                    }
                }
            }
        }
    return validity;
}


/************************************************************************************
/ This function loads the file pass to it and store in 2D vector as string type.
/ The vector is returned to the main.
/ Student : Nurzafirah Syazana
*************************************************************************************/
vector<vector<string>> openFile(string fileName){
    vector<vector<string>> records;  // declare 2D vector
    fstream file;
    string filePath;
    file.open(fileName);

    string line, word;

    while(!file.eof()) {

        file >> line;

        stringstream strStream(line);
        vector<string> data;  // declare 1D vector
        string field;

        while(getline(strStream, word, ',')) {
            stringstream str(word);
            str >> field;
            data.push_back(field);
        }
        records.push_back(data);
    }
    file.close();
    return records;
}


/************************************************************************************
This function will input the option entered by the admin based on options in adminPage().
Admin will go to the specific operation chosen by him.
Error checking : wrong input will not be accepted and the admin needs to re-enter the option.
Student : Nurzafirah Syazana
*************************************************************************************/
void displayAdminPage(vector<vector<string>>& dbUser, string& name, string& pass, string& type, string& status, vector<string>& transLog ) {
    int option;
    adminPage();
    string transaction1 = "Change User Password", transaction2 = "Create New User";
    string transaction3 = "Delete User Account";

    while (option!=1 || option!=2 || option!=3 || option!=4) {
        cin >> option;
        if (option==1) {
            transLog.push_back(transaction1);
            clearScreen();
            changePassword(dbUser, name, pass, type,status, transLog);
        }
        else if (option==2) {
            transLog.push_back(transaction2);
            clearScreen();
            createNewUser(dbUser, name, pass, type,status, transLog);
        }
        else if (option==3) {
            transLog.push_back(transaction3);
            clearScreen();
            deleteBuyer(dbUser, name, pass, type,status);
            backToAdminOrBuyer(dbUser, name, pass, type, status, transLog);
        }
        else if (option ==4) {
            clearScreen();
            logOut(dbUser, name, pass, type, status, transLog);
        }
        else {
            cout << "\nPlease enter the correct option. " << endl;
        }
    }
}


/************************************************************************************
/ This function will input the option entered by the buyer based on options in buyerPage().
/ Buyer will go to the specific operation chosen by him.
/ Error checking : wrong input will not be accepted and the buyer needs to re-enter the option.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void displayBuyerPage(vector<vector<string>>& dbUser, string& name, string& pass, string& type, string& status, vector<string>& transLog ){
    int option;
    string transaction1 = "Change User Password";
    buyerPage();

    while (option!=1 || option!=2 || option!=3 || option!=4) {
        cin >> option;
        if (option==1) {
            transLog.push_back(transaction1);
            clearScreen();
            changePassword(dbUser, name, pass, type,status, transLog);
        }
        else if (option==2) {
            clearScreen();
            analyzeData(dbUser, name, pass,type, status, transLog);
        }
        else if (option ==3) {
            clearScreen();
            logOut(dbUser, name, pass, type, status, transLog);
        }
        else {
            cout << "\nPlease enter the correct option. " << endl;
        }
    }
}


/************************************************************************************
/ This function is to display all the operation that can be performed by admin.
/ The instruction is given to inform the admin that program only accept certain range of integer.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void adminPage(){
    cout << "+--------------------------------------------------------------------+\n"
         << "   Below is shown the operations that can be done by administator.\n\n"
         << "  1 >> Change user password for administator account\n"
         << "  2 >> Create new buyer account\n"
         << "  3 >> Delete existing buyer account\n"
         << "  4 >> Logout\n"
         << "\n+--------------------------------------------------------------------+\n\n"
         << "Please enter number 1 - 4." << endl;
}


/************************************************************************************
/ This function is to display all the operation that can be performed by buyer.
/ The instruction is given to inform the admin that program only accept certain range of integer.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void buyerPage(){
        cout << "+--------------------------------------------------------------------+\n"
         << "   Below is shown the operations that can be done by buyer.\n\n"
         << "  1 >> Change user password for buyer account\n"
         << "  2 >> Start Analyze Data File\n"
         << "  3 >> Logout\n"
         << "\n+--------------------------------------------------------------------+\n\n"
         << "Please enter number 1 - 3." << endl;
}


/************************************************************************************
/ This function input the new password from the user.
/ The new password will be checked whether it fulfill the condition stated or not.
/ The user needs to re-enter the new password if it does not meet the requirements.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void changePassword(vector<vector<string>>& userAccountVector, string& currentUser, string& currentPassword, string& currentType, string& currentStatus, vector<string>& log){

    clearScreen();
    displayHeader(currentUser);
    char newPassword[30];
    bool result = false;

    cout << "Enter your new password that starts with letter and must contain a digit and a capital letter: " ;
    cin.ignore(256,'\n'); // ignore white spaces
    cin.getline(newPassword, 30);

    if(testPassword(newPassword)) {
        passVerified(userAccountVector, currentUser, currentPassword,newPassword, currentType, currentStatus, log);
    }

    while(!testPassword(newPassword)){
        cin.getline(newPassword, 30);
        result = testPassword(newPassword);
        if(result) {
            passVerified(userAccountVector, currentUser, currentPassword,newPassword, currentType, currentStatus, log);
        }
        else {
            cout << "\nInvalid password. Please enter a password "
                 << "that starts with letter and must contain a digit and a capital letter." << endl;
            cout << "For example, Abcde3 is valid\n" << endl
                 << "Please enter your new password again: "<< endl;
        }
    }
}


/************************************************************************************
/ This function check whether the new password fulfill the condition stated or not.
/ If the new password is good, the new password will be updated in vector and dbUserAccount.txt file.
/ After password have been updated, the program back to user respective page.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void passVerified(vector<vector<string>>& dbUser, string& name, string& pass, string newpass,string& type, string& status, vector<string>& transLog){
    cout << "Your new password is being verified...\n" << endl;
    updatePass(dbUser, pass , newpass);
    pass = newpass;
    writeTodbUserAccount(dbUser);

    cout << "Your password have been updated!" << endl;
    backToAdminOrBuyer(dbUser,name, pass, type, status, transLog);
}


/************************************************************************************
/ This function check if the password starts with letter, contains a digit and a capital letter.
/ if the satement is true, then verify is returned true to changePassword().
/ Student : Nurzafirah Syazana
*************************************************************************************/
bool testPassword(char pass[]) {
    bool verify = false;
    bool initialChar = false;
    int numDigits, numCapitalLetters;

    initialChar = initialIsAlpha(pass);
    numDigits = countDigits(pass);
    numCapitalLetters = countCapitalLetters(pass);
    //cout << "\nError checking\n" <<"\ninitialChar :" << initialChar << "numDigits: " << numDigits << "numCapitalLetters" << numCapitalLetters << endl;

    if ( (initialChar) && (numDigits==1) && (numCapitalLetters==1) ){
        verify = true;
    }
    else {
        verify = false;
    }
    return verify;
}


/************************************************************************************
/ This function is to check the first character of password starts with letter.
/ Boolean value is returned to testPassword().
/ Student : Nurzafirah Syazana
*************************************************************************************/
bool initialIsAlpha(char newPassword[]){
    bool result = false;
    for (int i = 0; i < 30; i++) {
        if (isalpha(newPassword[0])) {
            result = true;
        }
    } return result;
}


/************************************************************************************
/ This function counts the number of digits occured in the new password.
/ The int value is return to testPassword().
/ Student : Nurzafirah Syazana
*************************************************************************************/
int countDigits(char *strPtr){
	int occurs = 0;		             // this keeps track how many times a digit occurs
	while (*strPtr != '\0') {
		if ( isdigit(*strPtr) )	     // Use isdigit() to determine if the character is a digit
			occurs++;
		strPtr++;
	}return occurs;
}


/************************************************************************************
/ This function counts the number of capital letter occured in the new password.
/ The int value is return to testPassword().
/ Student : Nurzafirah Syazana
*************************************************************************************/
int countCapitalLetters(char *strPtr) {
	int occurs = 0;
	while (*strPtr != '\0'){
		if ( isupper(*strPtr) )	    // Use isalpha() to determine if the character is a letter
			occurs++;
		strPtr++;
	} return occurs;
}


/************************************************************************************
/ This function updates the new password that has been verified in 2D vector records.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void updatePass(vector<vector<string>>& records, string& currentPass, string newpass){
    for (int i = 0; i < records.size(); i++) {
        for (int j = 0; j < records[i].size(); j++) {
            if (records[i][1] == currentPass) {
                records[i][1] = newpass;
            }
        }
    }
}


/************************************************************************************
/ This function opens and writes current 2D vector into dbUserAccount.txt
/ Each line is formatted to have ' , ' separated.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void writeTodbUserAccount(vector<vector<string>>& records){
    ofstream outputFile;
    outputFile.open("dbUserAccount.txt");
    for (int i = 0; i < (records.size()); i++){
        outputFile << records[i][0] << "," << records[i][1] << "," << records[i][2] << "," << records[i][3] << endl;
    }
    outputFile.close();
}


/************************************************************************************
/ This function brings the user to either admin page or buyer page after done an operation.
/ For administator, the program will bring to displayAdminPage().
/ For buyer, the program will bring to displayBuyerPage().
/ Student : Nurzafirah Syazana
*************************************************************************************/
void backToAdminOrBuyer(vector<vector<string>>& dbUser, string& name, string& pass, string& type, string& status, vector<string>& transLog){
    do {
        cout << "Press a key to continue...\n";
        getch();
        if (type == "Admin") {
            clearScreen();
            displayAdminPage(dbUser, name, pass, type, status, transLog);
        }
        else {
            clearScreen();
            displayBuyerPage(dbUser, name, pass, type, status, transLog);
        }
    } while (cin.get() != '\n');
}


/************************************************************************************
/ This function will ask for input for username, password and usertype to create a new user account.
/ The program will ask the user to re-enter the information if it does not meet the requirements.
/ Each data is stored in 1D data vector and then will be stored in 2D data vector.
/ The 2D vector is stored in dbUserAccount.txt.
*************************************************************************************/
void createNewUser(vector<vector<string>>& userAccountVector, string& currentUser, string& currentPassword, string& currentType, string& currentStatus, vector<string>& log) {
    char username[30], password [30];
    string usertype, status = "Active";
    vector<string> newUser;

    clearScreen();
    displayHeader(currentUser);
    displayInstructionToCreate();

    cout << "Username : " ;
    cin.ignore(256,'\n');
    cin.getline(username, 30);

    while (!initialIsAlpha(username)) {
    cout << "Username should start with letter.\n"
         << "Enter username again : " ;
    cin.getline(username, 30);
    }

    cout << "\nPassword : " ;
    cin.getline(password, 30);

    while (!testPassword(password)) {
    cout << "Password should start with letter, contain a digit and a capital letter.\n"
         << "Enter password again : " ;
    cin.getline(password, 30);
    }

    cout << "\nUser Type : " ;
    cin >> usertype;

    while (!(usertype == "Admin") && !(usertype == "Buyer")) {
    cout << "User type should be either \'Admin\' or \'Buyer\' only.\n"
         << "Enter user type again : " ;
    cin  >> usertype;
    }

    newUser.push_back(username);
    newUser.push_back(password);
    newUser.push_back(usertype);
    newUser.push_back(status);

    userAccountVector.push_back(newUser);
    writeTodbUserAccount(userAccountVector);
    cout << "New account is created!" << endl;
    backToAdminOrBuyer(userAccountVector, currentUser, currentPassword, currentType, currentStatus, log);
}


/************************************************************************************
/ This function display the instruction for administator before creating a new user.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void displayInstructionToCreate() {
    cout << "To create a new user, please fill in all the information according to the instruction shown as below\n\n"
         << "------------------------------------------------------------------------\n"<<endl;
    cout << "Username  -- must start with letter\n"
         << "Password  -- must start with letter, contain a digit and a capital letter\n"
         << "User Type -- must enter either \'Admin\' or \'Buyer\' only\n"
         << "------------------------------------------------------------------------\n" << endl;
}


/************************************************************************************
/ This function input the username entered by admin to be deleted.
/ If the username exist in 2D vector, the user status will be change to 'Deleted'.
/ Current vector is updated in dbUserAccount.txt.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void deleteBuyer(vector<vector<string>>& userAccountVector, string& currentUser, string& currentPassword, string& currentType, string& currentStatus) {
    string username;
    bool found= false;

    clearScreen();
    displayHeader(currentUser);
    cout << "\tBelow is shown the list of user in BDAP System.\n\n";
    displayListOfUser(userAccountVector);

    cout << "\n\nEnter the user account to be deleted: " ;
    cin >> username;

    for ( int i = 0; i < userAccountVector.size(); i++){
        if (userAccountVector[i][0]==username) {
            if (userAccountVector[i][3]=="Active"){
                userAccountVector[i][3] = "Deleted";
                cout << "Account: " << username << " has been successfully deleted." << endl;
                break;
            }
            else {
                cout << "This account already deleted." << endl;
                break;
            }
        }
    }
    writeTodbUserAccount(userAccountVector);
}


/************************************************************************************
/ This function will display all the username, user type and their status from dbUserAccount.txt.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void displayListOfUser (vector<vector<string>>& userAccountVector) {
    cout << "  Username \t      User type \tStatus" << endl;
    for ( int i = 0; i < userAccountVector.size(); i++) {
        cout << (i+1) << ". "<< userAccountVector[i][0] << "\t\t" << userAccountVector[i][2] << "\t\t" << userAccountVector[i][3]<< endl;
    }
}


/************************************************************************************
/ This function input the option entered by user either they really want to log out or not.
/ If yes, the program will go to login page.
/ If not, the program will go to admin or buyer page.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void logOut(vector<vector<string>>& userAccountVector, string& currentUser, string& currentPassword, string& currentType, string& currentStatus, vector<string>& log) {
    clearScreen();
    displayHeader(currentUser);

    char decision;
    string transaction = "Log out from user account";

    cout << "Are you sure to log out from this program?" << endl
         << "Enter \'Y\' or \'N\': ";

    do {
        cin >> decision;
        if (decision == 'Y' || decision == 'y' ) {
            clearScreen();
            log.push_back(transaction);
            displayLogTransaction(log);
            createLogFile(log, currentUser);
            currentUser= " ";


            do{
                cout << "\nPress a key to continue...\n";
                getch();
            } while (cin.get() != '\n');

            clearScreen();
            login(userAccountVector, currentUser, currentPassword,currentType, currentStatus, log);
        }
        else if (decision == 'N' || decision == 'n' ){
            clearScreen();
            backToAdminOrBuyer(userAccountVector, currentUser, currentPassword,currentType, currentStatus, log);
        }
        else{
            cout << "Please enter \'Y\' or \'N\':";
        }
    } while(decision != 'Y' || decision != 'y' || decision != 'N' || decision != 'n');
}


/************************************************************************************
/ This function input the file name that contains data to be analyzed from buyer.
/ The data is stored in new 2D vector and pass to dataCalculation() to continue to the statistical computation.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void analyzeData(vector<vector<string>>& userAccountVector, string& currentUser, string& currentPassword, string& currentType, string& currentStatus, vector<string>& log) {
    string filename,fileName, transaction = "Load data file";

    displayInstruction();
    cin >> filename;
    vector<vector<int>> dataFile = openDataFile(filename, userAccountVector, currentUser, currentPassword,currentType, currentStatus, log);

    clearScreen();
    cout << "File exists!\n" << endl;
    log.push_back(transaction);
    fileName = renamefile(log, filename);
    clearScreen();
    dataCalculation(dataFile, userAccountVector, currentUser, currentPassword,currentType, currentStatus, log, fileName);
}


/************************************************************************************
/ This function input the option chosen by the buyer to perform statistical computation.
/ Program calls specific function to perform computation.
/ Error checking : The buyer needs to re-enter the option if the option is invalid.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void dataCalculation(vector<vector<int>> data, vector<vector<string>>& dbUser, string& name, string& pass, string& type, string& status, vector<string>& transLog, string& file) {
    statisticalMenu();
    int opt, choice, option;
    int n = data.size();
    int m = data[0].size();



    string transaction1 = "Find minimum values of row and column", transaction2 = "Find maximum values of row and column",
           transaction3 = "Find median of row and column", transaction4 = "Find mean of row and column",
           transaction5 = "Find variance of row and column", transaction6 = "Find standard deviation of row and column",
           transaction7 = "Correlation between two selected column", transaction8 = "Distinct data member",
           transaction9 = "Plot a histogram";

    while (opt!=1 || opt!=2 || opt!=3 || opt!=4 || opt!=5 || opt!=6 || opt!=7 || opt!=8 || opt!=9 || opt!=10) {
        cin >> opt;
        if (opt ==1){
            clearScreen();
            transLog.push_back(transaction1);
            operationHeader(transaction1);
            minInRow(data,n,m);
            minInCol(data,n,m);
            nextOperation(data, dbUser, name, pass, type, status, transLog, file);
        }
        else if (opt ==2){
            clearScreen();
            transLog.push_back(transaction2);
            operationHeader(transaction2);
            maxInRow(data,n,m);
            maxInCol(data,n,m);
            nextOperation(data, dbUser, name, pass, type, status, transLog, file);
        }
        else if (opt ==3){
            clearScreen();
            transLog.push_back(transaction3);
            operationHeader(transaction3);
            medianInRow(data,n,m);
            medianInCol(data,n,m);
            nextOperation(data, dbUser, name, pass, type, status, transLog, file);

        }
        else if (opt ==4){
            clearScreen();
            transLog.push_back(transaction4);
            operationHeader(transaction4);
            meanInRow(data,n,m);
            meanInCol(data,n,m);
            nextOperation(data, dbUser, name, pass, type, status, transLog, file);
        }
        else if (opt ==5){
            clearScreen();
            transLog.push_back(transaction5);
            operationHeader(transaction5);
            inputvarianceRow();
            inputvarianceColumn();
            nextOperation(data, dbUser, name, pass, type, status, transLog, file);
        }
        else if (opt ==6){
            clearScreen();
            transLog.push_back(transaction6);
            operationHeader(transaction6);
            inputstdeviationRow();
            inputstdeviationCol();
            nextOperation(data, dbUser, name, pass, type, status, transLog, file);
        }
        else if (opt ==7){
            clearScreen();
            transLog.push_back(transaction7);
            operationHeader(transaction7);
            inputPearson();
            nextOperation(data, dbUser, name, pass, type, status, transLog, file);
        }
        else if (opt ==8){
            clearScreen();
            transLog.push_back(transaction8);
            operationHeader(transaction8);
            option = chooseColumnTable (option);
            displayTable(option);
            nextOperation(data, dbUser, name, pass, type, status, transLog, file);
        }
        else if (opt ==9){
            clearScreen();
            transLog.push_back(transaction9);
            operationHeader(transaction9);
            choice = chooseColumnHis (choice);
            displayHisto (choice, file);
            nextOperation(data, dbUser, name, pass, type, status, transLog, file);
        }
        else if (opt ==10){
            clearScreen();
            displayBuyerPage(dbUser, name, pass, type, status, transLog);
        }
        else {
            cout << "\nPlease enter the correct option. " << endl;
        }
    }
}


/************************************************************************************
/ This function display the header for displaying statistical computation.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void operationHeader(string operation){
    cout << "+--------------------------------------------------------------------+\n\n"
         << "\t" << operation << "\n\n"
         << "+--------------------------------------------------------------------+\n\n";
}


/************************************************************************************
/ This function display the instruction for buyer to load data file.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void displayInstruction(){
    cout << "+--------------------------------------------------------------------+\n"
         << "\t\t Instructions\n\n"
         << "  >> Enter the name of .txt file for analyzation.\n"
         << "  >> Please includes \'.txt\' at the end of the name. Example: 'data.txt'. "<< endl
         << "+--------------------------------------------------------------------+\n\n";
    cout << "Filename: " ;
}


/************************************************************************************
/ This function open the file provided by the buyer.
/ The data is stored in 2D vector in integer data type.
/ Student : Nurzafirah Syazana
*************************************************************************************/
vector<vector<int>> openDataFile(string file, vector<vector<string>>& dbUser, string& name, string& pass, string& type, string& status, vector<string>& transLog){
    int rowNum, colNum;
    string title, filePath, ln, compute;
    vector<vector<int>> records;
    vector<int> rowData1, rowData2;
    bool fileExist;

    fstream inFile;
    inFile.open(file);
    fileExist = openFile( inFile, filePath);
    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
    Htmlfile << endl;
    Htmlfile << "User: " << name << endl;
    Htmlfile.close();


    if (fileExist) {
        inFile >> rowNum;
        inFile >> title;
        inFile >> compute;
        rowData1 = newVector(compute);

        inFile >> colNum;
        while(!inFile.eof()) {
            inFile >> ln;
            rowData2 = newVector(ln);
            records.push_back(rowData2);
        }
    }
    else {
        cout << "The file is not exist. Please enter the right file name." << endl << endl;
        analyzeData(dbUser, name, pass, type, status, transLog);
    }
    inFile.close();
    return records;
}


/************************************************************************************
/ This function is to read the data in row from data file and stored in the 1D vector
/ stringstream is used to convert string to integer data type.
/ Student : Nurzafirah Syazana
*************************************************************************************/
vector<int> newVector(string line){
    string word;

    stringstream strStream(line);
    vector<int> rowData;
    int field;

    while(getline(strStream, word, ',')) {
        stringstream strToInt(word);
        strToInt >> field;
        rowData.push_back(field);
    }
    return rowData;
}


/************************************************************************************
/ This function check if filename entered can be open or not.
/ Boolean will be returned.
/ Student : Nurzafirah Syazana
*************************************************************************************/
bool openFile(const fstream& dataFile, const string& Path) {
    if (dataFile.fail()) {
        return false;
    }
    else {
        return true;
    }
}

/************************************************************************************
/ This function changes the name of the loaded data file to a new name.
/ Student : Anis Balqis
*************************************************************************************/
string renamefile (vector<string>& transLog, string oldname)
{
    string transaction = "Rename data file";
    string newname, filename;
    cout<<"+--------------------------------------------------------------------+"<<endl;
    cout<<"                            Instructions"<<endl<<endl;
    cout<<" >> Please enter a new file name"<<endl;
    cout<<" >> Please include '.txt' at the end of the filename. Example: 'newname.txt' "<<endl<<endl;
    cout<<"+--------------------------------------------------------------------+"<<endl;
    cout<<"Filename : ";
    cin>> newname;

   fileName=newname;

	if (rename(oldname.c_str(), newname.c_str()) != 0){
		cout<<"Error renaming file"<<endl<<endl;
    }
	else {
		cout << "File renamed successfully!"<<endl<<endl;
        transLog.push_back(transaction);
        return fileName;
    }

}

/************************************************************************************
/ This function input option by user whether user wants to continue to perform another statistical computation or not
/ If yes, the program go back to dataCalculation(), otherwise it will proceed to TXTreportsMenu().
/ Student : Nurzafirah Syazana
*************************************************************************************/
void nextOperation(vector<vector<int>> dataFile, vector<vector<string>>& userAccountVector, string& currentUser, string& currentPassword, string& currentType, string& currentStatus, vector<string>& log, string& filename){
    char decision;
    cout << "Operation is done!\n"
         << "Do you want to proceed with next operation?"<<endl
         << "Enter \'Y\' to proceed with next operation or \'N\' to proceed to reports menu.\n\n"
         << "Enter \'Y\' or \'N\':";

    do {
        cin >> decision;
        if (decision == 'Y' || decision == 'y' ) {
            clearScreen();
            dataCalculation(dataFile, userAccountVector, currentUser, currentPassword,currentType, currentStatus,log, filename);

        }
        else {
            clearScreen();
            TXTreportsMenu(dataFile, userAccountVector, currentUser, currentPassword,currentType, currentStatus,log);
        }
        cout << "Please enter \'Y\' or \'N\':";

    }while(decision != 'Y' || decision != 'y' || decision != 'N' || decision != 'n');
}


/************************************************************************************
/ This function dislay the list of statistical computation that can be performed by buyer.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void statisticalMenu(){
    cout << "+--------------------------------------------------------------------+\n"
         << "   Below is shown the statistical computation that can be done by buyer.\n\n"
         << "  1 >> Minimum value of each row and column\n"
         << "  2 >> Maximum value of each row and column\n"
         << "  3 >> Median of each row and column\n"
         << "  4 >> Mean of each row and column\n"
         << "  5 >> Variance of each row and column\n"
         << "  6 >> Standard of each row and column\n"
         << "  7 >> Correlation of two columns\n"
         << "  8 >> Distinct Data Member\n"
         << "  9 >> Plot a histogram \n"
         << "  10 >> Back\n"
         << "\n+--------------------------------------------------------------------+\n\n"
         << "Please enter number 1 - 10." << endl;
}


/************************************************************************************
/ This function will find the minimum of value in selected row
/ Student : Nurfarra Sabreena
*************************************************************************************/
void minInRow(vector<vector<int>> vect, int N, int M) {
    int min;
    int sRow;
    cout << "<< Select row to find minimum value >>: " << endl;
    cin >> sRow;

    if (sRow >= 1 && sRow <= N){
        for (int i = 0; i < sRow; i++) {
            min = vect[i][0];
            for (int j = 1; j < M; j++) {
                if (vect[i][j] < min){
                    min = vect[i][j];
                }
            }
        }
        cout << "Minimum value of row " << sRow << ": " << min << endl;
        ofstream Htmlfile;
        Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
        Htmlfile << "Minimum value of row " << sRow << ": " << min << endl;
        Htmlfile.close();

        ofstream HtmlFileIndividual;
        HtmlFileIndividual.open("MIN.txt", ios::out | ios::app);
        HtmlFileIndividual << "Minimum value of row " << sRow << ": " << min << endl;
        HtmlFileIndividual.close();

        ofstream TXTfile;
        TXTfile.open("TXTReport.txt", ios::out | ios::app);
        TXTfile << "Minimum value of row " << sRow << ": " << min << endl;
        TXTfile.close();

        ofstream TXTFileIndividual;
        TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
        TXTFileIndividual << "Minimum value of row " << sRow << ": " << min << endl;
        TXTFileIndividual.close();
    }
    else
    {
        cout << "<< row " << sRow << " is not available. Please enter the right row >>" << endl;
        minInRow(vect, N, M);
    }

}


/************************************************************************************
/ This function will find the minimum of value in selected column
/ Student : Nurfarra Sabreena
*************************************************************************************/
void minInCol(vector<vector<int>> vect, int N, int M)
{
    int min;
    int sCol;
    cout << "<< Select column to find minimum value >>: " << endl;
    cin >> sCol;

    if (sCol >= 1 && sCol <= M)
    {
         for (int i = 0; i < sCol; i++)
        {
            min = vect[0][i];

            for (int j = 1; j < N; j++)
            {
                if (vect[j][i] < min)
                {
                    min = vect[j][i];
                }
            }
        }
        cout << "Minimum value of column " << sCol << ": " << min << endl;
        ofstream Htmlfile;
        Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
        Htmlfile << "Minimum value of column " << sCol << ": " << min << endl;
        Htmlfile.close();

        ofstream HtmlFileIndividual;
        HtmlFileIndividual.open("MIN.txt", ios::out | ios::app);
        HtmlFileIndividual << "Minimum value of column " << sCol << ": " << min << endl;
        HtmlFileIndividual << endl;
        HtmlFileIndividual.close();

        ofstream TXTfile;
        TXTfile.open("TXTReport.txt", ios::out | ios::app);
        TXTfile << "Minimum value of column " << sCol << ": " << min << endl;
        TXTfile.close();

        ofstream TXTFileIndividual;
        TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
        TXTFileIndividual << "Minimum value of column " << sCol << ": " << min << endl;
        TXTFileIndividual.close();
    }
    else
    {
        cout << " << column " << sCol << " is not available. Please enter the right column >> " << endl;
        minInCol(vect, N, M);

    }

}


/************************************************************************************
/ This function will find the maximum of value in selected row
/ Student : Nurfarra Sabreena
*************************************************************************************/
void maxInRow(vector<vector<int>> vect, int N, int M)
{
    int max;
    int sRow;
    cout << "<< Select row to find maximum value >>: " << endl;
    cin >> sRow;

    if (sRow >= 1 && sRow <= N)
    {
        for (int i = 0; i < sRow; i++)
        {
            max = vect[i][0];
            for (int j = 1; j < M; j++)
            {
                while (vect[i][j] > max)
                {
                    max = vect[i][j];
                }
            }
        }
        cout << "Maximum value of row " <<  sRow << ": " << max << endl;
        ofstream Htmlfile;
        Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
        Htmlfile << "Maximum value of row " <<  sRow << ": " << max << endl;
        Htmlfile.close();

        ofstream HtmlFileIndividual;
        HtmlFileIndividual.open("MAX.txt", ios::out | ios::app);
        HtmlFileIndividual << "Maximum value of row " <<  sRow << ": " << max << endl;
        HtmlFileIndividual.close();

        ofstream TXTfile;
        TXTfile.open("TXTReport.txt", ios::out | ios::app);
        TXTfile << "Maximum value of row " <<  sRow << ": " << max << endl;
        TXTfile.close();

        ofstream TXTFileIndividual;
        TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
        TXTFileIndividual << "Maximum value of row " <<  sRow << ": " << max << endl;
        TXTFileIndividual.close();
    }
    else
    {
        cout << "<< row " << sRow << " is not available. Please enter the right row >>" << endl;
        maxInRow(vect, N, M);
    }

}


/************************************************************************************
/ This function will find the maximum of value in selected column
/ Student : Nurfarra Sabreena
*************************************************************************************/
void maxInCol(vector<vector<int>> vect, int N, int M)
{
    int max;
    int sCol;
    cout << "<< Select column to find maximum value >>: " << endl;
    cin >> sCol;

    if (sCol >= 1 && sCol <= M)
    {
        for (int i = 0; i < sCol; i++)
        {
            max = vect[0][i];
            for (int j = 1; j < N; j++)
            {
                if (vect[j][i] > max)
                {
                    max = vect[j][i];
                }
            }
        }
        cout << "Maximum value of column " << sCol << ": " << max << endl;
        ofstream Htmlfile;
        Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
        Htmlfile << "Maximum value of column " << sCol << ": " << max << endl;
        Htmlfile.close();

        ofstream HtmlFileIndividual;
        HtmlFileIndividual.open("MAX.txt", ios::out | ios::app);
        HtmlFileIndividual << "Maximum value of column " << sCol << ": " << max << endl;
        HtmlFileIndividual << endl;
        HtmlFileIndividual.close();

        ofstream TXTfile;
        TXTfile.open("TXTReport.txt", ios::out | ios::app);
        TXTfile << "Maximum value of column " << sCol << ": " << max << endl;
        TXTfile.close();

        ofstream TXTFileIndividual;
        TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
        TXTFileIndividual << "Maximum value of column " << sCol << ": " << max << endl;
        TXTFileIndividual.close();
    }
    else
    {
        cout << " << column " << sCol << " is not available. Please enter the right column >> " << endl;
        maxInCol(vect, N, M);
    }

}


/************************************************************************************
/ This function will calculate the median in selected row
/ Student : Nurfarra Sabreena
*************************************************************************************/
void medianInRow(vector<vector<int>> vect, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < M - j - 1; k++)
            {
                if (vect[i][k] > vect[i][k + 1])
                {
                    swap(vect[i][k], vect[i][k + 1]);
                }
            }
        }
    }

    double median;
    int sRow;
    cout << "<< Select row to calculate median >>: " << endl;
    cin >> sRow;

    if (sRow >= 1 && sRow <= N)
    {
        for (int i = 0;  i < sRow; i++)
        {
            if (M % 2 == 0) // EVEN
            {
                median = (vect[i][M/2] + vect[i][(M - 1)/2]) / 2.0;
            }
            else // ODD
            {
                median = vect[i][M/2];

            }
        }
        cout << setprecision(2) << fixed;
        cout << "Median of row " << sRow << ": " << median << endl;

        ofstream Htmlfile;
        Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
        Htmlfile << setprecision(2) << fixed;
        Htmlfile << "Median of row " << sRow << ": " << median << endl;
        Htmlfile.close();

        ofstream HtmlFileIndividual;
        HtmlFileIndividual.open("MEDIAN.txt", ios::out | ios::app);
        HtmlFileIndividual << setprecision(2) << fixed;
        HtmlFileIndividual << "Median of row " << sRow << ": " << median << endl;
        HtmlFileIndividual.close();

        ofstream TXTfile;
        TXTfile.open("TXTReport.txt", ios::out | ios::app);
        TXTfile << setprecision(2) << fixed;
        TXTfile << "Median of row " << sRow << ": " << median << endl;
        TXTfile.close();

        ofstream TXTFileIndividual;
        TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
        TXTFileIndividual << setprecision(2) << fixed;
        TXTFileIndividual << "Median of row " << sRow << ": " << median << endl;
        TXTFileIndividual.close();
    }
    else
    {
        cout << "<< row " << sRow << " is not available. Please enter the right row >>" << endl;
        medianInRow(vect, N, M);
    }


}


/************************************************************************************
/ This function will calculate the median in selected column
/ Student : Nurfarra Sabreena
*************************************************************************************/
void medianInCol(vector<vector<int>> vect, int N, int M)
{
    vector<vector<int>> newvect = transpose(vect, N, M); // // Function call to find transpose of vector vect
    colSort(newvect); // function call to sort column
    vect = transpose(newvect, M, N); //calculate transpose of newvect

    double median;
    int sCol;
    cout << "<< Select column to calculate median >>: " << endl;
    cin >> sCol;

    if (sCol >= 1 && sCol <= M)
    {

        for (int j = 0; j < sCol; j++) // find median
        {
            if (N % 2 == 0) // EVEN
            {
                median = (vect[N/2][j] + vect[(N - 1)/2][j]) / 2.0;
            }
            else // ODD
            {
                median = vect[N/2][j];
            }

        }
        cout << setprecision(2) << fixed << showpoint;
        cout << "Median of column " << sCol << ": " << median << endl;

        ofstream Htmlfile;
        Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
        Htmlfile << setprecision(2) << fixed;
        Htmlfile << "Median of column " << sCol << ": " << median << endl;
        Htmlfile.close();

        ofstream HtmlFileIndividual;
        HtmlFileIndividual.open("MEDIAN.txt", ios::out | ios::app);
        HtmlFileIndividual << setprecision(2) << fixed;
        HtmlFileIndividual << "Median of column " << sCol << ": " << median << endl;
        HtmlFileIndividual << endl;
        HtmlFileIndividual.close();

        ofstream TXTfile;
        TXTfile.open("TXTReport.txt", ios::out | ios::app);
        TXTfile << setprecision(2) << fixed;
        TXTfile << "Median of column " << sCol << ": " << median << endl;
        TXTfile.close();

        ofstream TXTFileIndividual;
        TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
        TXTFileIndividual << setprecision(2) << fixed;
        TXTFileIndividual << "Median of column " << sCol << ": " << median << endl;
        TXTFileIndividual.close();
    }
    else
    {
        cout << " << column " << sCol << " is not available. Please enter the right column >> " << endl;
        medianInCol(vect, N, M);
    }
}


/************************************************************************************
/ This function will change column manners(vertical) to horizontal
/ Student : Nurfarra Sabreena
*************************************************************************************/
vector<vector<int>> transpose(vector<vector<int>> vect, int N, int M)
{
    vector<vector<int>> newvect(M, vector<int>(N)); // store tranpose vect in newvect

    for (int i = 0; i < N; i++) // Tranverse each row of the matrix
    {
        for (int j = 0; j < M; j++) // Tranverse each column of the matrix
        {
            newvect[j][i] = vect[i][j];
        }
    }
    return newvect;
}


/************************************************************************************
/ This function will sort the number in each column in ascending order
/ Student : Nurfarra Sabreena
*************************************************************************************/
void colSort(vector<vector<int>>& newvect) //sorting column newvect
{
    for (int i = 0; i < newvect.size(); i++)
    {
        sort(newvect[i].begin(), newvect[i].end());

    }
}


/************************************************************************************
/ This function will calculate mean in selected row
/ Student : Nurfarra Sabreena
*************************************************************************************/
void meanInRow(vector<vector<int>> vect, int N, int M )
{
    double mean;
    double sum;
    int sRow;
    cout << "<< Select row to calculate mean >>: " << endl;
    cin >> sRow;

    if (sRow >= 1 && sRow <= N)
    {
        for (int j = 0; j < sRow; j++)
        {
            sum = 0.00;
            for (int i = 0; i < M; i++)
            {
                sum = sum + vect[j][i];
                mean = sum / M;
            }
        }
        cout << setprecision(2) << fixed << showpoint;
        cout << "Mean of row " << sRow << ": " << mean << endl;

        ofstream Htmlfile;
        Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
        Htmlfile << setprecision(2) << fixed;
        Htmlfile << "Mean of row " << sRow << ": " << mean << endl;
        Htmlfile.close();

        ofstream HtmlFileIndividual;
        HtmlFileIndividual.open("MEAN.txt", ios::out | ios::app);
        HtmlFileIndividual << setprecision(2) << fixed;
        HtmlFileIndividual << "Mean of row " << sRow << ": " << mean << endl;
        HtmlFileIndividual.close();

        ofstream TXTfile;
        TXTfile.open("TXTReport.txt", ios::out | ios::app);
        TXTfile << setprecision(2) << fixed;
        TXTfile << "Mean of row " << sRow << ": " << mean << endl;
        TXTfile.close();

        ofstream TXTFileIndividual;
        TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
        TXTFileIndividual << setprecision(2) << fixed;
        TXTFileIndividual << "Mean of row " << sRow << ": " << mean << endl;
        TXTFileIndividual.close();
    }
    else
    {
        cout << "<< row " << sRow << " is not available. Please enter the right row >>" << endl;
        meanInRow(vect, N, M);
    }
}


/************************************************************************************
/ This function will calculate mean in selected column
/ Student : Nurfarra Sabreena
*************************************************************************************/
void meanInCol(vector<vector<int>> vect, int N, int M )
{
    double mean;
    double sum;
    int sCol;
    cout << "<< Select column to calculate mean >>: " << endl;
    cin >> sCol;

    if (sCol >= 1 && sCol <= M)
    {
        for (int i = 0; i < sCol; i++)
        {
            sum = 0.00;
            for (int j = 0; j < N; j++)
            {
                sum = sum + vect[j][i];
                mean = sum / N;
            }
        }
        cout << setprecision(2) << fixed << showpoint;
        cout << "Mean of column " << sCol << ": " << mean << endl;

        ofstream Htmlfile;
        Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
        Htmlfile << setprecision(2) << fixed;
        Htmlfile << "Mean of column " << sCol << ": " << mean << endl;
        Htmlfile.close();

        ofstream HtmlFileIndividual;
        HtmlFileIndividual.open("MEAN.txt", ios::out | ios::app);
        HtmlFileIndividual << setprecision(2) << fixed;
        HtmlFileIndividual << "Mean of column " << sCol << ": " << mean << endl;
        HtmlFileIndividual << endl;
        HtmlFileIndividual.close();

        ofstream TXTfile;
        TXTfile.open("TXTReport.txt", ios::out | ios::app);
        TXTfile << setprecision(2) << fixed;
        TXTfile << "Mean of column " << sCol << ": " << mean << endl;
        TXTfile.close();

        ofstream TXTFileIndividual;
        TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
        TXTFileIndividual << setprecision(2) << fixed;
        TXTFileIndividual << "Mean of column " << sCol << ": " << mean << endl;
        TXTFileIndividual.close();
    }
    else
    {
        cout << " << column " << sCol << " is not available. Please enter the right column >> " << endl;
        meanInCol(vect, N, M);
    }
}

/************************************************************************************
/ This function will ask to input a column number to calculate variance
/ Student : Anis Balqis
*************************************************************************************/

void inputvarianceColumn()
{
    int colNo;
    cout << "<< Select column to calculate variance >>: " << endl;
    cin >> colNo;
    cout << setprecision(2) << fixed << showpoint;
    cout<< "Variance of column "<< ": "<<varianceColumn(colNo)<< endl;

    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
    Htmlfile << setprecision(2) << fixed;
    Htmlfile << "Variance of column "<< ": "<<varianceColumn(colNo)<< endl;
    Htmlfile.close();

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("VARIANCE.txt", ios::out | ios::app);
    HtmlFileIndividual << setprecision(2) << fixed;
    HtmlFileIndividual << "Variance of column "<< ": "<<varianceColumn(colNo)<< endl;
    HtmlFileIndividual.close();

    ofstream TXTfile;
    TXTfile.open("TXTReport.txt", ios::out | ios::app);
    TXTfile << setprecision(2) << fixed;
    TXTfile << "Variance of column "<< ": "<<varianceColumn(colNo)<< endl;
    TXTfile.close();

    ofstream TXTFileIndividual;
    TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
    TXTFileIndividual << setprecision(2) << fixed;
    TXTFileIndividual << "Variance of column "<< ": "<<varianceColumn(colNo)<< endl;
    TXTFileIndividual.close();

}

/************************************************************************************
/ This function will calculate variance for specific column
/ Student : Anis Balqis
*************************************************************************************/

double varianceColumn(int colNo)
{


    vector<vector<string>> varianceVector = openFile(fileName);
    int size = 0;
    double variance = 0 ,
        mean = 0,
        sqTotal = 0,
        total = 0;

    for(int i = 4; i < varianceVector.size(); i++) {
        double current = (double) stoi(varianceVector[i][colNo]);
        total += current;
        sqTotal += pow(current, 2);
        size++;

    }

    mean=total/(double)size;
   variance=(sqTotal - total*mean)/((double)size-1);
   return variance;
}

/************************************************************************************
/ This function will ask to input a row number to calculate variance
/ Student : Anis Balqis
*************************************************************************************/

void inputvarianceRow()
{
    int rowNo;
    cout << "<< Select row to calculate variance >>: " << endl;
    cin >> rowNo;
    rowNo=rowNo+4;
    cout << setprecision(2) << fixed << showpoint;
    cout<< "Variance of row "<< ": "<<varianceRow(rowNo)<< endl;

    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
    Htmlfile << setprecision(2) << fixed;
    Htmlfile << "Variance of row "<< ": "<<varianceRow(rowNo)<< endl;
    Htmlfile.close();

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("VARIANCE.txt", ios::out | ios::app);
    HtmlFileIndividual << setprecision(2) << fixed;
    HtmlFileIndividual << "Variance of row "<< ": "<<varianceRow(rowNo)<< endl;
    HtmlFileIndividual << endl;
    HtmlFileIndividual.close();

    ofstream TXTfile;
    TXTfile.open("TXTReport.txt", ios::out | ios::app);
    TXTfile << setprecision(2) << fixed;
    TXTfile << "Variance of row "<< ": "<<varianceRow(rowNo)<< endl;
    TXTfile.close();

    ofstream TXTFileIndividual;
    TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
    TXTFileIndividual << setprecision(2) << fixed;
    TXTFileIndividual << "Variance of row "<< ": "<<varianceRow(rowNo)<< endl;
    TXTFileIndividual.close();
}


/************************************************************************************
/ This function will calculate variance for a complete row
/ Student : Anis Balqis
*************************************************************************************/

double varianceRow(int rowNo)
{

    vector<vector<string>> varianceVector = openFile(fileName);
    int size = 0;
    double variance = 0 ,
        mean = 0,
        sqTotal = 0,
        total = 0;


    for(int i = 0; i< varianceVector[rowNo].size(); i++) {
        double current = (double) stoi(varianceVector[rowNo][i]);
        total += current;
        sqTotal += pow(current, 2);
        size+=1;
    }


   mean=total/(double)size;
   variance=(sqTotal - total*mean)/((double)size-1);
   return variance;
}
/************************************************************************************
/ This function will ask to input a column number to calculate standard deviation
/ Student : Anis Balqis
*************************************************************************************/

void inputstdeviationCol()
{
    int colNo;
    cout << "<< Select column to calculate standard deviation >>: " << endl;
    cin >> colNo;
    cout << setprecision(2) << fixed << showpoint;
    cout<< "Standard deviation of column "<<": "<<stdeviationCol(colNo)<< endl;

    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
    Htmlfile << setprecision(2) << fixed;
    Htmlfile << "Standard deviation of column "<<": "<<stdeviationCol(colNo)<< endl;
    Htmlfile.close();

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("STDEVIATION.txt", ios::out | ios::app);
    HtmlFileIndividual << setprecision(2) << fixed;
    HtmlFileIndividual << "Standard deviation of column "<<": "<<stdeviationCol(colNo)<< endl;
    HtmlFileIndividual.close();

    ofstream TXTfile;
    TXTfile.open("TXTReport.txt", ios::out | ios::app);
    TXTfile << setprecision(2) << fixed;
    TXTfile << "Standard deviation of column "<<": "<<stdeviationCol(colNo)<< endl;
    TXTfile.close();

    ofstream TXTFileIndividual;
    TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
    TXTFileIndividual << setprecision(2) << fixed;
    TXTFileIndividual << "Standard deviation of column "<<": "<<stdeviationCol(colNo)<< endl;
    TXTFileIndividual.close();


}

/************************************************************************************
/ This function will calculate standard deviation for specific column
/ Student : Anis Balqis
*************************************************************************************/

double stdeviationCol(int colNo)
{

   return sqrt((double)varianceColumn(colNo));

}
/************************************************************************************
/ This function will ask to input a row number to calculate standard deviation
/ Student : Anis Balqis
*************************************************************************************/

void inputstdeviationRow()
{
    int rowNo;
    cout << "<< Select row to calculate standard deviation >>: " << endl;
    cin >> rowNo;
    rowNo=rowNo+4;
    cout << setprecision(2) << fixed << showpoint;
    cout<< "Standard deviation of row "<<": "<<stdeviationRow(rowNo)<< endl;

    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
    Htmlfile << setprecision(2) << fixed;
    Htmlfile << "Standard deviation of row "<<": "<<stdeviationRow(rowNo)<< endl;
    Htmlfile.close();

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("STDEVIATION.txt", ios::out | ios::app);
    HtmlFileIndividual << setprecision(2) << fixed;
    HtmlFileIndividual << "Standard deviation of row "<<": "<<stdeviationRow(rowNo)<< endl;
    HtmlFileIndividual << endl;
    HtmlFileIndividual.close();

    ofstream TXTfile;
    TXTfile.open("TXTReport.txt", ios::out | ios::app);
    TXTfile << setprecision(2) << fixed;
    TXTfile << "Standard deviation of row "<<": "<<stdeviationRow(rowNo)<< endl;
    TXTfile.close();

    ofstream TXTFileIndividual;
    TXTFileIndividual.open("TXTReportIndividual.txt", ios::out | ios::app);
    TXTFileIndividual << setprecision(2) << fixed;
    TXTFileIndividual << "Standard deviation of row "<<": "<<stdeviationRow(rowNo)<< endl;
    TXTFileIndividual.close();
}

/************************************************************************************
/ This function will calculate standard deviation for a complete row
/ Student : Anis Balqis
*************************************************************************************/
double stdeviationRow(int rowNo)
{

   return sqrt((double)varianceRow(rowNo));

}
/************************************************************************************
/ This function will ask to input 2 column numbers to calculate the Pearson�s correlation
/ between any 2 selected columns
/ Student : Anis Balqis
*************************************************************************************/
void inputPearson()
{
    int X,Y;
    cout << "<< Select the first column to compute the correlation between any selected 2 columns>>: "<< endl;
    cin >> X;
    cout <<endl<<"<< Select the second column to compute the correlation between any selected 2 columns>>: " << endl;
    cin >> Y;
    cout << setprecision(2) << fixed << showpoint;
    pearsoncoeff(X,Y);

}
/************************************************************************************
/ This function will calculate the Pearson�s correlation between any 2 selected columns
/ and print the table of computation of the correlation.
/ Student : Anis Balqis
*************************************************************************************/
void pearsoncoeff(int X,int Y)
{

    vector<vector<string>> varianceVector = openFile(fileName);
    int size = 0;
    double totalX = 0,
        totalY = 0,
        totalXY = 0,
        sqTotalX = 0,
        sqTotalY = 0,
        nowX,nowY;

    for(int i = 4; i < varianceVector.size(); i++) {

        double currentX = (double) stoi(varianceVector[i][X]);
        totalX += currentX;

        double currentY = (double) stoi(varianceVector[i][Y]);
        totalY += currentY;

        totalXY += currentX*currentY;

        sqTotalX += currentX*currentX;
        sqTotalY += currentY*currentY;
        size++;
       nowX=currentX;
       nowY=currentY;
    }

double correlation=(double)(size*totalXY-totalX*totalY)/sqrt((size*sqTotalX-totalX*totalX))*(size*sqTotalY-totalY*totalY);
  cout  << endl<<"Table of computation of the correlation:"<<endl<<endl
        << left
        << setw(6)
        << "(X)"
        << left
        << setw(6)
        << "(Y)"
        << left
        << setw(7)
        << "(XY)"
        << left
        << setw(8)
        << "(X^2)"
        << left
        << setw(8)
        << "(Y^2)"
        << endl;

ofstream Htmlfile;
Htmlfile.open("HtmlReport.txt", ios::out | ios::app);
Htmlfile << setprecision(2) << fixed;
Htmlfile << endl<<"Table of computation of the correlation:"<<endl<<endl
         << left
         << setw(6)
         << "(X)"
         << left
         << setw(6)
         << "(Y)"
         << left
         << setw(7)
         << "(XY)"
         << left
         << setw(8)
         << "(X^2)"
         << left
         << setw(8)
         << "(Y^2)"
         << endl;


ofstream HtmlFileIndividual;
HtmlFileIndividual.open("PEARSON.txt", ios::out | ios::app);
HtmlFileIndividual << setprecision(2) << fixed;
HtmlFileIndividual << endl<<"Table of computation of the correlation:"<<endl<<endl
                   << left
                   << setw(6)
                   << "(X)"
                   << left
                   << setw(6)
                   << "(Y)"
                   << left
                   << setw(7)
                   << "(XY)"
                   << left
                   << setw(8)
                   << "(X^2)"
                   << left
                   << setw(8)
                   << "(Y^2)"
                   << endl;




 for (int i = 0; i < 1; i++)
    {
        cout
            << left
            << " "
            << setw(5)
            << X
            << left
            << " "
            << setw(5)
            << Y
            << left
            << setw(8)
            <<(int)(nowX*nowY)
            << left
            << setw(8)
            <<(int)(nowX*nowX)
            << left
            << setw(7)
            <<(int)(nowY*nowY)
            << endl<<endl;
    }

Htmlfile << setprecision(2) << fixed;
Htmlfile << left
        << " "
        << setw(5)
        << X
        << left
        << " "
        << setw(5)
        << Y
        << left
        << setw(8)
        <<(int)(nowX*nowY)
        << left
        << setw(8)
        <<(int)(nowX*nowX)
        << left
        << setw(7)
        <<(int)(nowY*nowY)
        << endl<<endl;


HtmlFileIndividual << setprecision(2) << fixed;
HtmlFileIndividual  << left
                    << " "
                    << setw(5)
                    << X
                    << left
                    << " "
                    << setw(5)
                    << Y
                    << left
                    << setw(8)
                    <<(int)(nowX*nowY)
                    << left
                    << setw(8)
                    <<(int)(nowX*nowX)
                    << left
                    << setw(7)
                    <<(int)(nowY*nowY)
                    << endl<<endl;




cout<<"Correlation between 2 selected columns: "<< correlation<<endl<<endl;

HtmlFileIndividual << setprecision(2) << fixed;
HtmlFileIndividual <<"Correlation between 2 selected columns: "<< correlation<<endl<<endl;
HtmlFileIndividual << endl;
HtmlFileIndividual.close();

Htmlfile << setprecision(2) << fixed;
Htmlfile <<"Correlation between 2 selected columns: "<< correlation<<endl<<endl;
Htmlfile.close();
}
/************************************************************************************
/ This function will ask user if user wants to go back to the previous page or continue with next operation.
/ If yes, the program will proceed to HTMLreportsMenu(). If no ,it will return to TXTreportsMenu().
/ Student : Anis Balqis
*************************************************************************************/
void continueTXTmenu(vector<vector<int>> dataFile, vector<vector<string>>& userAccountVector, string& currentUser, string& currentPassword, string& currentType, string& currentStatus, vector<string>& log){
    char choose;
    cout << "Operation is done!\n";
    cout <<"Do you want to proceed with next operation?"<<endl;
    cout<< "Enter \'Y\' to proceed with next operation or \'N\' to back to the previous page.\n\n"<<endl;
    cout<< "Enter \'Y\' or \'N\':";

    do {
        cin >> choose;
        if (choose == 'Y' || choose == 'y' ) {
            clearScreen();
            HTMLreportsMenu(dataFile, userAccountVector, currentUser, currentPassword,currentType, currentStatus,log);
        }
        else {
        clearScreen();
        TXTreportsMenu(dataFile, userAccountVector, currentUser, currentPassword,currentType, currentStatus,log);
        }

    }while(choose != 'Y' || choose != 'y' || choose != 'N' || choose != 'n');
}
/************************************************************************************
/ This function will ask user if user wants to go back to the previous page or return to buyer's menu.
/ If yes, the program will go back to HTMLreportsMenu(). If no ,it will return to displayBuyerPage().
/ Student : Anis Balqis
*************************************************************************************/
void continueHTMLmenu(vector<vector<int>> dataFile, vector<vector<string>>& userAccountVector, string& currentUser, string& currentPassword, string& currentType, string& currentStatus, vector<string>& log){
    char choose;
   cout << "Operation is done!\n";
    cout <<"Do you want to proceed with next operation?"<<endl;
    cout<< "Enter \'Y\' to go back to the previous page or \'N\' to go to buyer's menu.\n\n"<<endl;
    cout<< "Enter \'Y\' or \'N\':";

    do {
        cin >> choose;
        if (choose == 'Y' || choose == 'y' ) {
            clearScreen();
            HTMLreportsMenu(dataFile, userAccountVector, currentUser, currentPassword,currentType, currentStatus,log);
        }
        else {
            clearScreen();
            displayBuyerPage(userAccountVector, currentUser, currentPassword,currentType, currentStatus, log);
        }
        cout << "Please enter \'Y\' or \'N\':";

    }while(choose != 'Y' || choose != 'y' || choose != 'N' || choose != 'n');
}

/************************************************************************************
/ This function displays options for users to generate TXT reports.
/ Student : Anis Balqis
*************************************************************************************/
void TXTreportsMenu(vector<vector<int>> data, vector<vector<string>>& dbUser, string& name, string& pass, string& type, string& status, vector<string>& transLog){
    string transaction1 = "Display report for all statistical computations", transaction2 = "Display report for statistical computation individually";
    int option;
    cout << "+--------------------------------------------------------------------+"<<endl
         << "   Shown below are the provided options to generate your reports in txt file format."<<endl<<endl
         << "  1 >> Display report for all statistical computations"<<endl
         << "  2 >> Display report for statistical computation individually"<<endl
         << "  3 >> Back"<<endl
         << endl<< "+--------------------------------------------------------------------+"<<endl<<endl
         << "Please enter number 1 - 3." << endl;
         cin >> option;

         while (option!=1 || option!=2 || option!=3) {
        if (option==1){
        transLog.push_back(transaction1);
        clearScreen();
         //function
        continueTXTmenu(data, dbUser, name, pass, type, status, transLog);
        }
        else if (option==2){
        transLog.push_back(transaction2);
        clearScreen();
         //function
        continueTXTmenu(data, dbUser, name, pass, type, status, transLog);
        }
        else if (option==3){
            clearScreen();
            displayBuyerPage(dbUser, name, pass, type, status, transLog);
        }
        else {
            cout <<endl<<"Please enter the correct option. " << endl;
        }
    }

}
/************************************************************************************
/ This function displays options for users to generate HTML reports.
/ Student : Anis Balqis
*************************************************************************************/
void HTMLreportsMenu(vector<vector<int>> data, vector<vector<string>>& dbUser, string& name, string& pass, string& type, string& status, vector<string>& transLog){
    int option;
    string transaction1 = "Display report for all statistical computations", transaction2 = "Display report for statistical computation individually";
     cout << "+--------------------------------------------------------------------+"<<endl
         << "   Shown below are the provided options to generate your reports in HTML file format."<<endl<<endl
         << "  1 >> Display report for all statistical computations"<<endl
         << "  2 >> Display report for statistical computation individually"<<endl
         << "  3 >> Back"<<endl
         << endl<< "+--------------------------------------------------------------------+"<<endl<<endl
         << "Please enter number 1 - 3." << endl;
         cin >> option;

         while (option!=1 || option!=2 || option!=3) {
        if (option==1){
        transLog.push_back(transaction1);
        clearScreen();
        allStatisticalReportHTML();
        continueHTMLmenu(data, dbUser, name, pass, type, status, transLog);
        }
        else if (option==2){
        transLog.push_back(transaction2);
        clearScreen();
        IndividualReportHTML();
        continueHTMLmenu(data, dbUser, name, pass, type, status, transLog);
        }
        else if (option==3){
            clearScreen();
            displayBuyerPage(dbUser, name, pass, type, status, transLog);
        }
        else {
            cout <<endl<<"Please enter the correct option. " << endl;
        }
    }

}
/************************************************************************************
/ This function will call html browser to display report
/ Student : Nurfarra Sabreena
*************************************************************************************/
int allStatisticalReportHTML()
{
    char url[100] ="StatisticalComputation.html";
    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
    return 1;

}

int IndividualReportHTML()
{
    cout << "+--------------------------------------------------------------------+"<<endl
         << "  INDIVIDUAL REPORT\n"
         << "  1 >> Minimum value of each row and column\n"
         << "  2 >> Maximum value of each row and column\n"
         << "  3 >> Median of each row and column\n"
         << "  4 >> Mean of each row and column\n"
         << "  5 >> Variance of each row and column\n"
         << "  6 >> Standard of each row and column\n"
         << "  7 >> Correlation of two columns\n"
         << "  8 >> Distinct Data Member\n"
         << "  9 >> Plot a histogram \n"
         << "  10 >> Back\n"
         << endl<< "+--------------------------------------------------------------------+"<<endl<<endl
         << "Please enter number 1 - 10." << endl;

         int option;
         cin >> option;
         system("cls");

        while(option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6 || option != 7 || option != 8 || option != 9 || option != 10)
        {
            if (option == 1)
            {
                ifstream file("MIN.txt");
                if (file)
                {
                    char url[100] ="MINIMUM.html";
                    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
                    IndividualReportHTML();
                }
                else
                {
                    cout << "file does not exist" << endl;
                    IndividualReportHTML();
                }
            }
            else if (option == 2)
            {
                ifstream file("MAX.txt");
                if (file)
                {
                    char url[100] ="MAXIMUM.html";
                    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
                    IndividualReportHTML();
                }
                else
                {
                    cout << "file does not exist" << endl;
                    IndividualReportHTML();
                }
            }
            else if (option == 3)
            {
                ifstream file("MEDIAN.txt");
                if (file)
                {
                    char url[100] ="MEDIAN.html";
                    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
                    IndividualReportHTML();
                }
                else
                {
                    cout << "file does not exist" << endl;
                    IndividualReportHTML();
                }
            }
            else if (option == 4)
            {
                ifstream file("MEAN.txt");
                if (file)
                {

                    char url[100] ="MEAN.html";
                    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
                    IndividualReportHTML();
                }
                else
                {
                    cout << "file does not exist" << endl;
                    IndividualReportHTML();

                }
            }
            else if (option == 5)
            {
                ifstream file("VARIANCE.txt");
                if (file)
                {
                    char url[100] ="VARIANCE.html";
                    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
                    IndividualReportHTML();
                }
                else
                {
                    cout << "file does not exist" << endl;
                    IndividualReportHTML();
                }
            }
            else if (option == 6)
            {
                ifstream file("STDEVIATION.txt");
                if (file)
                {
                    char url[100] ="STDEVIATION.html";
                    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
                    IndividualReportHTML();
                }
                else
                {
                    cout << "file does not exist" << endl;
                    IndividualReportHTML();
                }
            }
            else if (option == 7)
            {
                ifstream file("PEARSON.txt");
                if (file)
                {
                    char url[100] ="PEARSON.html";
                    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
                    IndividualReportHTML();
                }
                else
                {
                    cout << "file does not exist" << endl;
                    IndividualReportHTML();
                }
            }
            else if (option == 8)
            {
                ifstream file("DISTINCT.txt");
                if (file)
                {
                    char url[100] ="DISTINCT.html";
                    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
                    IndividualReportHTML();
                }
                else
                {
                    cout << "file does not exist" << endl;
                    IndividualReportHTML();
                }
            }
            else if (option == 9)
            {
                ifstream file("HISTOGRAM.txt");
                if (file)
                {
                    char url[100] ="HISTOGRAM.html";
                    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
                    IndividualReportHTML();
                }
                else
                {
                    cout << "file does not exist" << endl;
                    IndividualReportHTML();
                }
            }
            else if (option == 10)
            {
                return 1;
            }
            return 1;
        }
    return 1;
}

/************************************************************************************
/ This function display columns options and
/ allows buyer to choose which column to display distinct data members, in a
/ table format
/ Student : Ameera Farhana
*************************************************************************************/
int chooseColumnTable (int option)
{
   cout << "Which column do you want to display?" << endl;
   cout << "1. Second column " << endl;
   cout << "2. Third column " << endl;
   cout << "3. Fourth column " << endl;
   cout << "4. Fifth column " << endl;
   cout << "Please enter number between 1-4:" << endl;
   cin >> option;
   if (option == 1 | option == 2 | option == 3 | option == 4 )    //return option value to chooseColumnTable function
   {
       return option;
   }
   else                                                //error check if number entered is not in range 1-4
   {
       chooseColumnTable (option);
   }
}

/************************************************************************************
/ This function is to call the specific function of displayTable (distinct data member)
/ based on chosen column to display in a table format
/ Student : Ameera Farhana
*************************************************************************************/
void displayTable (int &option)
{
    if (option == 1)
    {
        displayTable2 (option);            //function call to display second column
    }
     if (option == 2)
    {
        displayTable3 (option);            //function call to display third column
    }
     if (option == 3)
    {
        displayTable4 (option);            //function call to display fourth column
    }
     if (option == 4)
    {
        displayTable5 (option);            //function call to display fifth column
    }
}


/************************************************************************************
/ This function is to display the distinct data members of the second column
/ Student : Ameera Farhana
*************************************************************************************/
void displayTable2 (int &option)
{
    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("DISTINCT.txt", ios::out | ios::app);


   ofstream myFile ("distinctDataCol2.txt");                //open file to write the data
       if (myFile.is_open())
       {
                cout << "Values\t   Times Repeated" << endl;
                myFile << "Values\t   Times Repeated" << endl;
                Htmlfile << "Values\t   Times Repeated" << endl;
                HtmlFileIndividual << "Values\t   Times Repeated" << endl;


                vector<int> vec = {19,20,21,22,18,18,19,20,21,21,22,19,18,19,21,22,21,21,20,21,       //assign values in column to vector<int> vec
                                        22,21,20,19,19,19,20,20,20,21,21,22,23,21,19,21,22,19,21,19};

                printFrequency(vec);             //call printFrequency (vec) function to display results of frequency counted
       }
       else
       {
         cout << "Unable to open file";
       }
    myFile.close();
    HtmlFileIndividual.close();
    Htmlfile.close();
}

/************************************************************************************
/ This function is to display the distinct data members of the third column
/ Student : Ameera Farhana
*************************************************************************************/
void displayTable3 (int &option)
{

    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("DISTINCT.txt", ios::out | ios::app); 

   ofstream myFile ("distinctDataCol3.txt");                //open file to write the data
       if (myFile.is_open())
       {
                cout << "Values\t   Times Repeated" << endl;
                myFile << "Values\t   Times Repeated" << endl;
                Htmlfile << "Values\t   Times Repeated" << endl;
                HtmlFileIndividual << "Values\t   Times Repeated" << endl;

                vector<int> vec = {93, 45, 98, 56, 34, 56, 90, 100, 88, 34, 87, 90,67,88,67,81,41,56,67,67,   //assign values in column to vector<int> vec
                                        70,89,67,56,34,45,90,76,67,56,34,100,34,23,45,34,90,56,100,55};

                printFrequency(vec);                     //call printFrequency (vec) function to display results of frequency counted
       }
       else
       {
         cout << "Unable to open file";
       }
    myFile.close();
    HtmlFileIndividual.close();
    Htmlfile.close();
}

/************************************************************************************
/ This function is to display the distinct data members of the fourth column
/ Student : Ameera Farhana
*************************************************************************************/
void displayTable4 (int &option)
{

    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("DISTINCT.txt", ios::out | ios::app);

   ofstream myFile ("distinctDataCol4.txt");                //open file to write the data
       if (myFile.is_open())
       {
                cout << "Values\t   Times Repeated" << endl;
                myFile << "Values\t   Times Repeated" << endl;
                Htmlfile << "Values\t   Times Repeated" << endl;
                HtmlFileIndividual << "Values\t   Times Repeated" << endl;

                vector<int> vec = {92,78,78,45,78,78,89,98,76,56,76,89,45,72,58,54,67,78,89,89,      //assign values in column to vector<int> vec
                                        70,98,56,98,67,67,23,78,98,78,56,45,67,45,77,67,73,23,56,88};

                printFrequency(vec);                 //call printFrequency (vec) function to display results of frequency counted
       }
       else
       {
         cout << "Unable to open file";
       }
    myFile.close();
    HtmlFileIndividual.close();
    Htmlfile.close();
}

/************************************************************************************
/ This function is to display the distinct data members of the fifth column
/ Student : Ameera Farhana
*************************************************************************************/
void displayTable5 (int &option)
{
    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("DISTINCT.txt", ios::out | ios::app);


   ofstream myFile ("distinctDataCol5.txt");                //open file to write the data
       if (myFile.is_open())
       {
                cout << "Values\t   Times Repeated" << endl;
                myFile << "Values\t   Times Repeated" << endl;
                Htmlfile << "Values\t   Times Repeated" << endl;
                HtmlFileIndividual << "Values\t   Times Repeated" << endl;

                vector<int> vec = {87,78,98,79,59,90,99,98,67,78,65,56,67,64,99,71,89,98,77,45,
                                        98,100,34,34,78,89,56,98,90,45,98,67,89,78,88,66,92,69,78,99};

                printFrequency(vec);             //call printFrequency (vec) function to display results of frequency counted
       }
       else
       {
         cout << "Unable to open file";
       }
    myFile.close();
    HtmlFileIndividual.close();
    Htmlfile.close();
}

/************************************************************************************
/ This function is to do the frequency calculation of each value appear in the
/ column and displays the result.
/ Student : Ameera Farhana
*************************************************************************************/
void printFrequency(vector<int> vec)
{

    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("DISTINCT.txt", ios::out | ios::app);

    map<int, int> G;                         //a map is defined

    for (int i = 0; vec[i]; i++)             //traverse vector vec to check if current element is present or not
    {
        if (G.find(vec[i]) == G.end())       //if current element is not found, then current element's frequency will be 1
        {
            G[vec[i]] = 1;
        }

        else {                               //else, frequency will increase by 1
            G[vec[i]]++;
        }
    }

    for (auto& it : G)                       //traverse the map to print the frequency
    {
        cout << it.first << "\t\t"
             << it.second << '\n';

        Htmlfile << it.first << "\t\t"
                 << it.second << '\n';

        HtmlFileIndividual << it.first << "\t\t"
                           << it.second << '\n';
    }
}


/************************************************************************************
/ This function display columns choices and
/ allows buyer to choose which column to display as histogram
/ Student : Ameera Farhana
*************************************************************************************/
int chooseColumnHis (int choice)
{
   cout << "Which column do you want to display?" << endl;
   cout << "1. Second column " << endl;
   cout << "2. Third column " << endl;
   cout << "3. Fourth column " << endl;
   cout << "4. Fifth column " << endl;
   cout << "Please enter number between 1-4:" << endl;
   cin >> choice;
   if (choice == 1 || choice == 2 || choice == 3 || choice == 4 )   //if else to decide the return value based on choices input by user
   {
       return choice;
   }
   else                                                             //error check if number entered is not in range 1-4
   {
       chooseColumnHis (choice);
   }
}


/************************************************************************************
/ This function is to call the specific function based on chosen
/ column to display as histogram
/ Student : Ameera Farhana
*************************************************************************************/
void displayHisto (int &choice, string& file)
{
    if (choice == 1)
    {
        displayHisto2 (choice, file);            //function call to display second column
    }
     if (choice == 2)
    {
        displayHisto3 (choice, file);            //function call to display third column
    }
     if (choice == 3)
    {
        displayHisto4 (choice, file);            //function call to display fourth column
    }
     if (choice == 4)
    {
        displayHisto5 (choice, file);            //function call to display fifth column
    }
}


/************************************************************************************
/ This function is to display the histogram of the second column
/ Student : Ameera Farhana
*************************************************************************************/
void displayHisto2 (int &choice, string& filename)
{
    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("HISTOGRAM.txt", ios::out | ios::app);

    ofstream myFile ("histoCol2.txt");                //open file "histoCol2.txt" to write the data
       if (myFile.is_open())
       {
          ifstream columnFile (filename);           //open file "data.txt" to be read
             if (columnFile.is_open())
             {
                string line;
                int size = 0;
                int i;

                vector<vector<string>> secondColumn = openFile(filename);                  //function call of openFile (file)

                cout << "Row\t\tValues\t\tHistogram" << endl;
                myFile << "Row\t\tValues\t\tHistogram" << endl;
                Htmlfile << "Row\t\tValues\t\tHistogram" << endl;
                HtmlFileIndividual << "Row\t\tValues\t\tHistogram" << endl;

                     for  (i = 4; i < secondColumn.size(); i++)                        //for loop to read the list of numbers in column
                     {
                      choice = 1;
                      cout << i - 3 << "\t\t" <<  secondColumn[i][choice] << "\t";
                      myFile << i - 3  << "\t\t" <<  secondColumn[i][choice] << "\t";
                      Htmlfile << i - 3  << "\t\t" <<  secondColumn[i][choice] << "\t";
                      HtmlFileIndividual << i - 3  << "\t\t" <<  secondColumn[i][choice] << "\t";

                      cout << "|";
                      myFile << "|";
                      Htmlfile << "|";
                      HtmlFileIndividual << "|";

                        for (int j = 0; j < stoi(secondColumn[i][choice]); j++)         //for loop to count and display '*' in histogram
                        {
                            cout << "*";
                            myFile <<  "*";
                            Htmlfile <<  "*";
                            HtmlFileIndividual <<  "*";
                        }

                     cout << endl;
                     myFile << endl;
                     Htmlfile << endl;
                     HtmlFileIndividual << endl;

                    }
                    size++;                                                              //increase size by 1
              }

       cout << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"          //to display the scale of histogram
            << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       cout << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45  "
            << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       myFile << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
              << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       myFile << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
              << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       Htmlfile << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
                 << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       Htmlfile << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
                 << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       HtmlFileIndividual << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
                           << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       HtmlFileIndividual << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
                           << "50   55   60   65   70   75   80   85   90   95   100" << endl;
       }

       else
       {
         cout << "Unable to open file";
       }
    myFile.close();
}

/************************************************************************************
/ This function is to display the histogram of the third column
/ Student : Ameera Farhana
*************************************************************************************/
void displayHisto3 (int &choice, string& filename)
{
    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("HISTOGRAM.txt", ios::out | ios::app);

    ofstream myFile ("histoCol3.txt");                //open file "histoCol3.txt" to write the data
       if (myFile.is_open())
       {
          ifstream columnFile (filename);           //open file "data.txt" to be read
             if (columnFile.is_open())
             {
                string line;
                int size = 0;
                int i;

                vector<vector<string>> thirdColumn = openFile(filename);                    //function call of openFile (file)

                cout << "Row\t\tValues\t\tHistogram" << endl;
                myFile << "Row\t\tValues\t\tHistogram" << endl;
                Htmlfile << "Row\t\tValues\t\tHistogram" << endl;
                HtmlFileIndividual << "Row\t\tValues\t\tHistogram" << endl;

                     for  (i = 4; i < thirdColumn.size(); i++)                           //for loop to read the list of numbers in column
                     {
                      choice = 2;
                      cout << i - 3 << "\t\t" <<  thirdColumn[i][choice] << "\t";
                      myFile << i - 3  << "\t\t" <<  thirdColumn[i][choice] << "\t";
                      Htmlfile << i - 3  << "\t\t" <<  thirdColumn[i][choice] << "\t";
                      HtmlFileIndividual << i - 3  << "\t\t" <<  thirdColumn[i][choice] << "\t";

                      cout << "|";
                      myFile << "|";
                      Htmlfile << "|";
                      HtmlFileIndividual << "|";

                        for (int j = 0; j < stoi(thirdColumn[i][choice]); j++)            //for loop to count and display '*' in histogram
                        {
                            cout << "*";
                            myFile <<  "*";
                            Htmlfile <<  "*";
                            HtmlFileIndividual <<  "*";
                        }

                     cout << endl;
                     myFile << endl;
                     Htmlfile << endl;
                     HtmlFileIndividual << endl;

                    }
                    size++;                                                                //increase size by 1
              }

       cout << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"            //to display the scale of histogram
            << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       cout << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45  "
            << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       myFile << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
              << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       myFile << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
              << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       Htmlfile << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
                 << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       Htmlfile << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
                 << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       HtmlFileIndividual << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
                           << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       HtmlFileIndividual << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
                           << "50   55   60   65   70   75   80   85   90   95   100" << endl;
       }

       else
       {
         cout << "Unable to open file";
       }
     myFile.close();
}

/************************************************************************************
/ This function is to display the histogram of the fourth column
/ Student : Ameera Farhana
*************************************************************************************/
void displayHisto4 (int &choice, string& filename)
{   
    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("HISTOGRAM.txt", ios::out | ios::app);

    ofstream myFile ("histoCol4.txt");                //open file "histoCol4.txt" to write the data
       if (myFile.is_open())
       {
          ifstream columnFile (filename);           //open file "data.txt" to be read
             if (columnFile.is_open())
             {
                string line;
                int size = 0;
                int i;

                vector<vector<string>> fourthColumn = openFile(filename);               //function call of openFile (file)

                cout << "Row\t\tValues\t\tHistogram" << endl;
                myFile << "Row\t\tValues\t\tHistogram" << endl;
                Htmlfile << "Row\t\tValues\t\tHistogram" << endl;
                HtmlFileIndividual << "Row\t\tValues\t\tHistogram" << endl;


                     for  (i = 4; i < fourthColumn.size(); i++)                     //for loop to read the list of numbers in column
                     {
                      choice = 3;
                      cout << i - 3 << "\t\t" <<  fourthColumn[i][choice] << "\t";
                      myFile << i - 3  << "\t\t" <<  fourthColumn[i][choice] << "\t";
                      Htmlfile << i - 3  << "\t\t" <<  fourthColumn[i][choice] << "\t";
                      HtmlFileIndividual << i - 3  << "\t\t" <<  fourthColumn[i][choice] << "\t";

                      cout << "|";
                      myFile << "|";
                      Htmlfile << "|";
                      HtmlFileIndividual << "|";

                        for (int j = 0; j < stoi(fourthColumn[i][choice]); j++)      //for loop to count and display '*' in histogram
                        {
                            cout << "*";
                            myFile <<  "*";
                            Htmlfile <<  "*";
                            HtmlFileIndividual <<  "*";
                        }

                     cout << endl;
                     myFile << endl;
                     Htmlfile << endl;
                     HtmlFileIndividual << endl;


                    }
                    size++;                                                           //increase size by 1
              }

       cout << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"       //to display the scale of histogram
            << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       cout << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45  "
            << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       myFile << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
              << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       myFile << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
              << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       Htmlfile << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
                 << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       Htmlfile << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
                 << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       HtmlFileIndividual << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
                           << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       HtmlFileIndividual << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
                           << "50   55   60   65   70   75   80   85   90   95   100" << endl;    
       }

       else
       {
         cout << "Unable to open file";
       }
     myFile.close();
}

/************************************************************************************
/ This function is to display the histogram of the fifth column
/ Student : Ameera Farhana
*************************************************************************************/
void displayHisto5 (int &choice, string& filename)
{
    ofstream Htmlfile;
    Htmlfile.open("HtmlReport.txt", ios::out | ios::app);

    ofstream HtmlFileIndividual;
    HtmlFileIndividual.open("HISTOGRAM.txt", ios::out | ios::app);

    ofstream myFile ("histoCol5.txt");                //open file "histoCol5.txt" to write the data
       if (myFile.is_open())
       {
          ifstream columnFile (filename);           //open file "data.txt" to be read
             if (columnFile.is_open())
             {
                string line;
                int size = 0;
                int i;

                vector<vector<string>> fifthColumn = openFile(filename);                //function call of openFile (file)

                cout << "Row\t\tValues\t\tHistogram" << endl;
                myFile << "Row\t\tValues\t\tHistogram" << endl;
                Htmlfile << "Row\t\tValues\t\tHistogram" << endl;
                HtmlFileIndividual << "Row\t\tValues\t\tHistogram" << endl;


                     for  (i = 4; i < fifthColumn.size(); i++)                      //for loop to read the list of numbers in column
                     {
                      choice = 4;
                      cout << i - 3 << "\t\t" <<  fifthColumn[i][choice] << "\t";
                      myFile << i - 3  << "\t\t" <<  fifthColumn[i][choice] << "\t";
                      Htmlfile << i - 3  << "\t\t" <<  fifthColumn[i][choice] << "\t";
                      HtmlFileIndividual << i - 3  << "\t\t" <<  fifthColumn[i][choice] << "\t";

                      cout << "|";
                      myFile << "|";
                      Htmlfile << "|";
                      HtmlFileIndividual << "|";

                        for (int j = 0; j < stoi(fifthColumn[i][choice]); j++)      //for loop to count and display '*' in histogram
                        {
                            cout << "*";
                            myFile <<  "*";
                            Htmlfile <<  "*";
                            HtmlFileIndividual <<  "*";
                        }

                     cout << endl;
                     myFile << endl;
                     Htmlfile << endl;
                     HtmlFileIndividual << endl;

                    }
                    size++;                                                          //increase size by 1
              }

       cout << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"      //to display the scale of histogram
            << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       cout << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45  "
            << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       myFile << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
              << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       myFile << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
              << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       Htmlfile << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
                 << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       Htmlfile << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
                 << "50   55   60   65   70   75   80   85   90   95   100" << endl;

       HtmlFileIndividual << "\t\t\t" << "|----|----|----|----|----|----|----|----|----|----"
                           << "|----|----|----|----|----|----|----|----|----|----|" << endl;
       HtmlFileIndividual << "\t\t\t" << "0    5    10   15   20   25   30   35   40   45   "
                           << "50   55   60   65   70   75   80   85   90   95   100" << endl;
       }

       else
       {
         cout << "Unable to open file";
       }
     myFile.close();
}

/************************************************************************************
/ This function displays the log transaction (stored in 1D array).
/ Student : Nurzafirah Syazana
*************************************************************************************/
void displayLogTransaction(vector<string>& transLog){
    cout << "+-----------------------------------------+\n"
         << "    Below is shown your log transaction"
         << "\n+---------------------------------------+\n\n";
    for (int i=0; i < transLog.size(); i++){
        cout << (i+1) << ". "<< transLog[i] <<endl;
    }
}

/************************************************************************************
/ This function create a txt file for save the transaction log for each user
/ Every user has their individual txt file.
/ Student : Nurzafirah Syazana
*************************************************************************************/
void createLogFile(vector<string>& transLog, string& user){
    string filename = user + "Log.txt";
    string title = "This is the transaction log for user: " + user;

    ofstream outputFile;
    outputFile.open(filename);

    outputFile << title << endl << endl;

    for (int i = 0; i <transLog.size(); i++) {
        outputFile << transLog[i] << endl;
    }

    outputFile.close();
}
