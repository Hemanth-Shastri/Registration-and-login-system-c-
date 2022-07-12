#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

bool loggedIn(){
    string username, password , USERNAME , PASSWORD;

    cout<< "Username : " ;
    cin >> username;
    cout << endl << "password : " ;
    cin >> password;


    ifstream read("data\\" + username + ".txt");

    getline(read, USERNAME);
    getline(read, PASSWORD);

    if(username == USERNAME && password == PASSWORD)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void changePassword(){
    string  username, password;

     cout<< "Enter your username : " ; cin >> username ;
    cout<< "Enter new password : " ; cin >> password;

    ifstream file;
    file.open("data\\" + username + ".txt");
    if(file){

        ofstream file;
        file.open("data\\" + username + ".txt");
        file  << username << endl << password;
        file.close();
        cout << "password change successfully" << endl;
    }
    else{
        cout << "invalid username" << endl;
        changePassword();
    }
}

int main(){
    int choice;
    cout << "1 : Register\n" << "2 : Login" << endl;
    cin >> choice;

    if(choice == 1)
    {
        string username, password;

        cout<< "Please enter username: " ; cin>> username;
        cout<< "Please enter a password: " ; cin>> password;

        //Checking if the username already exists or not
        ifstream check;
        check.open("data\\" + username + ".txt");
        if(check){ 
            // If the username already exists, start the process again
            cout << "Username already exists" << endl;
        }
        else{
            //If the username doesn't exist, create the file
            ofstream file;
            file.open("data\\" + username + ".txt");
            file  << username << endl << password;
            file.close();

            cout<< "Successfully registered"<< endl;
        }

        //Once registration is complete go back to the home portal
        main();

    }
    else if(choice == 2)
    {
        if(loggedIn()){
            cout << "Successfully logged in" << endl;

            int choice;

            cout << "Do you want to change password ?\n 1: Yes \n 2: No" << endl;
            cin >> choice;

            if(choice==1){

               changePassword();

            }

            system("PAUSE");
        }
        else{
            cout << "Invalid login credentials" << endl;
            main();
        }
        return 1;
    }

}