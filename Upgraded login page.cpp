#include<iostream>
#include<fstream>
using namespace std;

class Project {
    private:
        string name, email, password;
        fstream file;

    public:
        void signup() {
            cin.ignore(); 
            cout << "\nEnter Your Name: ";
            getline(cin, name);

            cout << "Enter Your Email Address: ";
            getline(cin, email);

            cout << "Enter Your Password: ";
            getline(cin, password);

            file.open("LoginData.txt", ios::out | ios::app);

            file << name << "*" << email << "*" << password << endl;
            file.close();

            cout << "\nSignup Successful!\n";
        }

        void login() {
            string searchname, searchpassword;
            cin.ignore();
            cout << "\n----LOGIN----\n";
            cout << "Enter Your Name: ";
            getline(cin, searchname);
            cout << "Enter Your Password: ";
            getline(cin, searchpassword);

            file.open("LoginData.txt", ios::in);
            bool found = false;

            
            while(getline(file, name, '*') && getline(file, email, '*') && getline(file, password)) {
                if(name == searchname && password == searchpassword) {
                    cout << "\nYou Login Successfully...!" << endl;
                    cout << "Username: " << name << endl;
                    cout << "Email: " << email << endl;
                    found = true;
                    break;
                }
            }

            if(!found) {
                cout << "\nPassword or Username is incorrect...!" << endl;
            }

            file.close();
        }

        void forget() {
            string searchname, searchemail;
            cin.ignore();
            cout << "\nEnter Your Name: ";
            getline(cin, searchname);
            cout << "Enter Your Email: ";
            getline(cin, searchemail);

            file.open("LoginData.txt", ios::in);
            bool found = false;

            while(getline(file, name, '*') && getline(file, email, '*') && getline(file, password)) {
                if(name == searchname && email == searchemail) {
                    cout << "\nPassword Found...!" << endl;
                    cout << "Your Password is: " << password << endl;
                    found = true;
                    break;
                }
            }

            if(!found) {
                cout << "\nUser not found or email incorrect!" << endl;
            }

            file.close();
        }
};

int main() {
    Project obj;
    char choice;
    char again;

    do {
        cout << "\n1. Login";
        cout << "\n2. Sign-up";
        cout << "\n3. Forget Password";
        cout << "\n4. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                obj.login();
                break;

            case '2':
                obj.signup();
                break;

            case '3':
                obj.forget();
                break;

            case '4':
                cout << "\nProgram Terminated\n";
                return 0;

            default:
                cout << "Invalid Selection!" << endl;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> again;

    } while(again=='y' || again=='Y');

    cout << "\nProgram Terminated\n";
    return 0;
}