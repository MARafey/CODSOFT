#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool passwordChecker(string pass)
{
    if (pass.length() < 9)
    {
        cout << "Password must be at least 9 characters long!" << endl;
        return false;
    }
    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;

    for (int i = 0; i < pass.length(); i++)
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            flag1 = true;
        }
        else if (pass[i] >= 'a' && pass[i] <= 'z')
        {
            flag2 = true;
        }
        else if (pass[i] >= '0' && pass[i] <= '9')
        {
            flag3 = true;
        }
    }

    if (flag1 == false)
    {
        cout << "Password must contain at least one uppercase letter!" << endl;
    }
    if (flag2 == false)
    {
        cout << "Password must contain at least one lowercase letter!" << endl;
    }
    if (flag3 == false)
    {
        cout << "Password must contain at least one digit!" << endl;
    }

    return flag1 && flag2 && flag3;
}

class To_do_list
{
private:
    string name;
    string password;

public:
    To_do_list(string n = "", string p = "") : name(n), password(p){};

    void Menu()
    {
        while (true)
        {
            system("cls");
            cout << "1. Add task" << endl;
            cout << "2. Remove task" << endl;
            cout << "3. Display tasks" << endl;
            cout << "4. Mark as done" << endl;
            cout << "5. Exit" << endl;

            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                display();
                break;
            case 4:
                mark_as_done();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    }

    bool check_if_exits()
    {
        ifstream fin;
        fin.open(name + ".txt");

        if (fin)
        {
            fin.close();
            return true;
        }
        else
        {
            fin.close();
            return false;
        }
    }

    void setName(string n)
    {
        name = n;
    }
    void setPassword(string p)
    {
        password = p;
    }

    void Input()
    {
        bool flag = false;
        cout << "Enter your name: ";
        cin >> name;

        if (check_if_exits())
        {
        retry:
            cout
                << "Enter your password: ";
            cin >> password;

            while (!passwordChecker(password))
            {
                cout << "Enter your password: ";
                cin >> password;
            }

            ifstream fin;
            fin.open(name + ".txt");

            string temp;
            while (getline(fin, temp))
            {
                if (temp == password)
                {
                }
                else
                {
                    if (flag == true)
                    {
                        cout << "invalid password!" << endl;
                        cout << "You are out of tries!" << endl;

                        exit(1);
                    }
                    cout << "invalid password!" << endl;
                    flag = true;
                    goto retry;
                }
            }
        }
        else
        {
            cout << "Enter your password: ";
            cin >> password;

            while (!passwordChecker(password))
            {
                cout << "Enter your password: ";
                cin >> password;
            }

            ofstream fout;
            fout.open(name + ".txt");
            fout << password << endl;
            fout.close();
        }
    }

    void display()
    {
        ifstream fin;
        fin.open(name + ".txt");

        string temp;
        while (getline(fin, temp))
        {
            cout << temp << endl;
        }

        fin.close();
    }
    void addTask()
    {
        string task;
        cout << "Enter your task: ";
        getline(cin, task);

        ofstream fout;
        fout.open(name + ".txt", ios::app);

        fout << task << '\n'
             << "Not Done" << endl;

        fout.close();
    }

    void mark_as_done()
    {
        string task;
        cout << "Enter the task you want to mark as done: ";
        cin >> task;

        ifstream fin;
        fin.open(name + ".txt");

        ofstream fout;
        fout.open("temp.txt");

        string temp;
        while (getline(fin, temp))
        {
            if (temp != task)
            {
                fout << temp << endl;
            }
            else
            {
                fout << temp << endl;
                fout << "Done" << endl;
            }
        }

        fin.close();
        fout.close();

        remove((name + ".txt").c_str());
        rename("temp.txt", (name + ".txt").c_str());
    }

    void removeTask()
    {
        string task;
        cout << "Enter the task you want to remove: ";
        cin >> task;

        ifstream fin;
        fin.open(name + ".txt");

        ofstream fout;
        fout.open("temp.txt");

        string temp;
        while (getline(fin, temp))
        {
            if (temp != task)
            {
                fout << temp << endl;
            }
            else
            {
                getline(fin, temp);
            }
        }

        fin.close();
        fout.close();

        remove((name + ".txt").c_str());
        rename("temp.txt", (name + ".txt").c_str());
    }
};

int main()
{
    To_do_list T;

    T.Input();
    T.Menu();

    return 0;
}