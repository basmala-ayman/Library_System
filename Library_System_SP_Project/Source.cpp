#include<iostream>
#include<string>
using namespace std;
struct STUDENT
{
    string Firstname, Secondname, ID, Password, Email, Borrow[20];
}Student[30];
struct ADMIN
{
    string Firstname, Secondname, Password, Email;
}Admin;
struct BOOK
{
    string Name, Category, Author_Name, Availability;
    int Code, Edition;
};

void Welcome();
void Data_of_Books(BOOK Book[]);
void INVALID();

void Data_of_Admin();
int Log_In_Admin();
void Modify_Info_Admin();
void Add_Book(BOOK Book[], int& Size_Of_Books);
void Modify_Info_Book(BOOK Book[], int Size_Of_Books);
void Delete_Book(BOOK Book[], int& Size_Of_Books);

void Data_of_Students();
void Sign_Up_Student(int& Size_of_Student);
int Log_In_Student(int Size_Of_Students, int& Indix);
void Modify_Info_Student(int& Indix);
void Show_Name_Books(BOOK Book[], int Size_Of_Books);
void Info_Book(BOOK Books[], int Size_Of_Books);
void Select_Books(BOOK Book[], STUDENT Student[], int Size_Of_Books, int& Num_Books_Borrowed, int Indix);
void Modify_Order(BOOK Books[], STUDENT Student[], int Size_Of_Books, int& Num_Books_Borrowed, int Indix);

void Log_Out();

int main()
{
    BOOK Books[100];
    int Size_Of_Students = 5;
    int Size_Of_Books = 7;
    int Indix, Num_Books_Borrowed;
    char Repeat;
    Data_of_Admin();
    Data_of_Students();
    Data_of_Books(Books);
    while (true)
    {
        int Choice_1, Choice_4;
        Welcome();
        cout << "PRESS:" << endl;
        cout << "=======" << endl;
        cout << "1 ==> If you are a Student." << endl;
        cout << "2 ==> If you are an Admin." << endl;
        cout << "============================" << endl;
        cin >> Choice_1;
        if (Choice_1 == 1)
        {
            while (true)
            {
                int Choice_2;
                bool New_Student = 0;
                cout << "PRESS:" << endl;
                cout << "=======" << endl;
                cout << "1 ==> To Sign Up, if you do not have an account." << endl;
                cout << "2 ==> To Log In, if you already have an account." << endl;
                cout << "=================================================" << endl;
                cin >> Choice_2;
                if (Choice_2 == 1)
                {
                    Sign_Up_Student(Size_Of_Students);
                    New_Student = 1;
                }
                if (Choice_2 == 2 || New_Student == 1)
                {
                    while (true)
                    {
                        int LOG_Student = Log_In_Student(Size_Of_Students, Indix);
                        if (LOG_Student == 1)
                        {
                            while (true)
                            {
                                int Choice_3;
                                cout << "PRESS:" << endl;
                                cout << "=======" << endl;
                                cout << "1 ==> To Modify your informayion." << endl;
                                cout << "2 ==> To Show information about Books." << endl;
                                cout << "3 ==> To Borrow Books." << endl;
                                cout << "=======================================" << endl;
                                cin >> Choice_3;
                                if (Choice_3 == 1)
                                {
                                    Modify_Info_Student(Indix);
                                }
                                else if (Choice_3 == 2)
                                {
                                    Info_Book(Books, Size_Of_Books);
                                }
                                else if (Choice_3 == 3)
                                {
                                    char Answer_1;
                                    Select_Books(Books, Student, Size_Of_Books, Num_Books_Borrowed, Indix);
                                    do
                                    {
                                        cout << "Do you want to modify your Order (Y/N)? ";
                                        cin >> Answer_1;
                                        if (Answer_1 == 'Y' || Answer_1 == 'y')
                                        {
                                            Modify_Order(Books, Student, Size_Of_Books, Num_Books_Borrowed, Indix);
                                            break;
                                        }
                                        else if (Answer_1 == 'N' || Answer_1 == 'n')
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            INVALID();
                                            continue;
                                        }
                                    } while (true);
                                }
                                else
                                {
                                    INVALID();
                                    continue;
                                }
                                do
                                {
                                    cout << "PRESS:" << endl;
                                    cout << "=======" << endl;
                                    cout << "1 ==> To Go back to the Previous list to do another Operation." << endl;
                                    cout << "2 ==> To Log Out." << endl;
                                    cout << "===============================================================" << endl;
                                    cin >> Choice_4;
                                    if (Choice_4 == 1)
                                    {
                                        break;
                                    }
                                    else if (Choice_4 == 2)
                                    {
                                        Log_Out();
                                        break;
                                    }
                                    else
                                    {
                                        INVALID();
                                        continue;
                                    }
                                } while (true);
                                if (Choice_4 == 1)
                                {
                                    continue;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            break;
                        }
                        else if (LOG_Student == 2)
                        {
                            cout << "=================================================" << endl;
                            cout << "You have exhausted all attempts!!" << endl;
                            cout << "So, you have to Sign Up to enter to Our Libaray." << endl;
                            cout << "=================================================" << endl;
                            Sign_Up_Student(Size_Of_Students);
                            continue;
                        }
                        else if (LOG_Student == -1)
                        {
                            cout << "=================================================" << endl;
                            cout << "This Email is INVALID!!" << endl;
                            cout << "So, you have to Sign Up to enter to Our Libaray." << endl;
                            cout << "=================================================" << endl;
                            Sign_Up_Student(Size_Of_Students);
                            continue;
                        }
                    }
                }
                else
                {
                    INVALID();
                    continue;
                }
                break;
            }
        }
        else if (Choice_1 == 2)
        {
            int Choice_6 = 0;
            cout << "Please, Log in:" << endl;
            cout << "================" << endl;
            int LOG_Admin = Log_In_Admin();
            if (LOG_Admin == 1)
            {
                cout << "============================================" << endl;
                cout << "You have registered successfully." << endl;
                cout << "============================================================" << endl;
                int Choice_5;
                while (true)
                {
                    cout << "PRESS:" << endl;
                    cout << "=======" << endl;
                    cout << "1 ==> To Modify your Information." << endl;
                    cout << "2 ==> To Modify Information about a Book." << endl;
                    cout << "3 ==> To Add a new Book." << endl;
                    cout << "4 ==> To Delete a Book." << endl;
                    cout << "=======================================" << endl;
                    cin >> Choice_5;
                    if (Choice_5 == 1)
                    {
                        Modify_Info_Admin();
                    }
                    else if (Choice_5 == 2)
                    {
                        Modify_Info_Book(Books, Size_Of_Books);
                    }
                    else if (Choice_5 == 3)
                    {
                        Add_Book(Books, Size_Of_Books);
                    }
                    else if (Choice_5 == 4)
                    {
                        Delete_Book(Books, Size_Of_Books);
                    }
                    else
                    {
                        INVALID();
                        continue;
                    }
                    do
                    {
                        cout << "PRESS:" << endl;
                        cout << "=======" << endl;
                        cout << "1 ==> To Go back to the Previous list to do another Operation." << endl;
                        cout << "2 ==> To Log Out." << endl;
                        cout << "================================================================" << endl;
                        cin >> Choice_6;
                        if (Choice_6 == 1)
                        {
                            break;
                        }
                        else if (Choice_6 == 2)
                        {
                            Log_Out();
                            break;
                        }
                        else
                        {
                            INVALID();
                            continue;
                        }
                    } while (true);
                    if (Choice_6 == 1)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (LOG_Admin == 2)
            {
                cout << "==================================" << endl;
                cout << "This Email is INVALID!!" << endl;
                cout << "Please, try again from Beginning." << endl;
                cout << "==================================" << endl;
                continue;
            }
            else
            {
                cout << "==================================" << endl;
                cout << "This Password is INVALID!!" << endl;
                cout << "Please, try again from Beginning." << endl;
                cout << "==================================" << endl;
                continue;
            }
        }
        else
        {
            INVALID();
            continue;
        }
        do
        {
            cout << "Do you want to EXIT the Program (Y/N)? ";
            cin >> Repeat;
            if (Repeat == 'Y' || Repeat == 'y' || Repeat == 'N' || Repeat == 'n')
            {
                break;
            }
            else
            {
                INVALID();
                continue;
            }
        } while (true);
        if (Repeat == 'N' || Repeat == 'n')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    cout << "===============================================================================================" << endl;
    return 0;
}

void Welcome()
{
    cout << "                                   Welcome to ASU Library" << endl;
    cout << "                                ============================" << endl;
}
void Data_of_Books(BOOK Book[])
{
    Book[0].Name = "Encyclopedia of medicine and life";
    Book[0].Code = 101;
    Book[0].Category = "Medical";
    Book[0].Author_Name = "Allen Richardson";
    Book[0].Edition = 3;
    Book[0].Availability = "Available";

    Book[1].Code = 307;
    Book[1].Name = "Zeros to one";
    Book[1].Category = "Scientific";
    Book[1].Author_Name = "Peter thiel";
    Book[1].Edition = 7;
    Book[1].Availability = "Not Available";

    Book[2].Code = 441;
    Book[2].Name = "Emergency Medicine";
    Book[2].Category = "Medical";
    Book[2].Author_Name = "pete watson";
    Book[2].Edition = 5;
    Book[2].Availability = "Available";

    Book[3].Code = 110;
    Book[3].Name = "THE SELF-TAUGHT PROGRAMMER";
    Book[3].Category = "Programing";
    Book[3].Author_Name = "Cory Althoff";
    Book[3].Edition = 2;
    Book[3].Availability = "Available";

    Book[4].Code = 66;
    Book[4].Name = "The Passions of the Soul";
    Book[4].Category = "Psychology";
    Book[4].Author_Name = "René Descartes";
    Book[4].Edition = 1;
    Book[4].Availability = "Not Available";

    Book[5].Code = 1067;
    Book[5].Name = "The Psychopath Test";
    Book[5].Category = "Psychology";
    Book[5].Author_Name = "Jon Ronson";
    Book[5].Edition = 3;
    Book[5].Availability = "Available";

    Book[6].Code = 1003;
    Book[6].Name = "Introduction to Algorithms";
    Book[6].Category = "Programing";
    Book[6].Author_Name = "Thomas H.Cormen";
    Book[6].Edition = 4;
    Book[6].Availability = "Available";
}
void INVALID()
{
    cout << "====================" << endl;
    cout << "INVALID ANSWER!!" << endl;
    cout << "Please, try again." << endl;
    cout << "====================" << endl;
}
//Functions of Admin
void Data_of_Admin()
{
    Admin.Firstname = "Abdallah";
    Admin.Secondname = "ElSayed";
    Admin.Password = "11223344";
    Admin.Email = "AbdallahElsayed_admin@Library.com";
}
int Log_In_Admin()
{
    string email, pass;
    cout << "Please, enter your Email: ";
    cin >> email;
    if (email == Admin.Email)
    {
        cout << "Please, enter your Password: ";
        cin >> pass;
        if (pass == Admin.Password)
        {
            return 1;
        }
        else
        {
            return 3;
        }
    }
    else
    {
        return 2;
    }
}
void Modify_Info_Admin()
{
    int Choice;
    char Answer;
    while (true)
    {
        cout << "PRESS:" << endl;
        cout << "======" << endl;
        cout << "1 ==> To Modify your First Name." << endl;
        cout << "2 ==> To Modify your Second Name." << endl;
        cout << "3 ==> To Modify your Password." << endl;
        cout << "=====================================" << endl;
        cin >> Choice;
        if (Choice == 1)
        {
            cout << "Enter the updated First Name: ";
            cin >> Admin.Firstname;
            Admin.Email = Admin.Firstname + Admin.Secondname + "_admin@Library.com";
            cout << "Your First Name is modified successfully." << endl;
            cout << "And your email is: " << Admin.Email << endl;
            cout << "==========================================" << endl;
        }
        else if (Choice == 2)
        {
            cout << "Enter the updated Second Name: ";
            cin >> Admin.Secondname;
            Admin.Email = Admin.Firstname + Admin.Secondname + "_admin@Library.com";
            cout << "Your Second Name is modified successfully." << endl;
            cout << "And your email is: " << Admin.Email << endl;
            cout << "==========================================" << endl;
        }
        else if (Choice == 3)
        {
            cout << "Enter the updated Password: ";
            cin >> Admin.Password;
            cout << "Your Password is modified successfully." << endl;
            cout << "========================================" << endl;
        }
        else
        {
            INVALID();
            continue;
        }
        do
        {
            cout << "Do you want to modify another information (Y/N)? ";
            cin >> Answer;
            if (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n')
            {
                INVALID();
                continue;
            }
            else
            {
                break;
            }
        } while (true);
        if (Answer == 'Y' || Answer == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    cout << "===========================================================" << endl;
}
void Modify_Info_Book(BOOK Book[], int Size_Of_Books)
{
    char Ans;
    int Choice, Option;
    do
    {
        cout << "PRESS:\n";
        cout << "=======\n";
        for (int i = 0; i < Size_Of_Books; i++)
        {
            cout << i + 1 << " ==> To Modify " << Book[i].Name << endl;
        }
        cout << "================================================" << '\n';
        while (true)
        {
            cin >> Choice;
            if (Choice <= 0 || Choice > Size_Of_Books)
            {
                INVALID();
                continue;
            }
            else
            {
                break;
            }
        }
        while (true)
        {
            cout << "PRESS:\n";
            cout << "======\n";
            cout << 1 << " ==> To Modify the name of book" << '\n';
            cout << 2 << " ==> To Modify the code of book" << '\n';
            cout << 3 << " ==> To Modify the category of book" << '\n';
            cout << 4 << " ==> To Modify the author_name of book" << '\n';
            cout << 5 << " ==> To Modify the Edition of book" << '\n';
            cout << 6 << " ==> To Modify the availability of book" << '\n';
            cout << "================================================" << '\n';
            while (true)
            {
                cin >> Option;
                if (Option < 1 || Option > 6)
                {
                    INVALID();
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (Option == 1)
            {
                cin.ignore();
                cout << "Enter the new name of book: ";
                getline(cin, Book[Choice - 1].Name);
                cout << "The name of book " << Choice << " modified successfully." << '\n';
                cout << "=======================================================" << '\n';
            }
            else if (Option == 2)
            {
                cout << "Enter the new code of book: ";
                cin >> Book[Choice - 1].Code;
                cout << "The code of book " << Choice << " modified successfully." << '\n';
                cout << "=======================================================" << '\n';
            }
            else if (Option == 3)
            {
                cin.ignore();
                cout << "Enter the new category of book: ";
                getline(cin, Book[Choice - 1].Category);
                cout << "The category of book " << Choice << " modified successfully." << '\n';
                cout << "===========================================================" << '\n';
            }
            else if (Option == 4)
            {
                cin.ignore();
                cout << "Enter the new author name of book: ";
                getline(cin, Book[Choice - 1].Author_Name);
                cout << "The author name of book " << Choice << " modified successfully." << '\n';
                cout << "===============================================================" << '\n';
            }
            else if (Option == 5)
            {
                cout << "Enter the new edition of book: ";
                cin >> Book[Choice - 1].Edition;
                cout << "The edition of book " << Choice << " modified successfully." << '\n';
                cout << "==========================================================" << '\n';
            }
            else if (Option == 6)
            {
                cin.ignore();
                cout << "Enter availability:" << '\n';
                cout << "But please, enter (Available) if the book is available or (Not Available) if is not available: ";
                getline(cin, Book[Choice - 1].Availability);
                cout << "The availability of book " << " " << Choice << " " << " modified successfully." << '\n';
                cout << "===============================================================" << '\n';
            }
            cout << "Do you want to modify another information (Y/N)? ";
            while (true)
            {
                cin >> Ans;
                if (Ans != 'Y' && Ans != 'y' && Ans != 'N' && Ans != 'n')
                {
                    INVALID();
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (Ans == 'N' || Ans == 'n')
            {
                cout << "============================================================" << '\n';
                cout << "The information has been modified successfully." << '\n';
                cout << "Now, the information of book " << Choice << " after modifying is:" << '\n';
                cout << "============================================================" << '\n';
                cout << "Name: " << Book[Choice - 1].Name << "\n";
                cout << "Code: " << Book[Choice - 1].Code << "\n";
                cout << "Category: " << Book[Choice - 1].Category << "\n";
                cout << "Author Name: " << Book[Choice - 1].Author_Name << "\n";
                cout << "Edition: " << Book[Choice - 1].Edition << "\n";
                cout << "Availability: " << Book[Choice - 1].Availability << "\n";
                break;
            }
        }
        cout << "Do you want to modify another book (Y/N)? ";
        while (true)
        {
            cin >> Ans;
            if (Ans != 'Y' && Ans != 'y' && Ans != 'N' && Ans != 'n')
            {
                INVALID();
                continue;
            }
            else
            {
                break;
            }
        }

    } while (Ans == 'Y' || Ans == 'y');
}
void Add_Book(BOOK Book[], int& Size_Of_Books)
{
    char Ans;
    cin.ignore();
    while (true)
    {
        cout << "Enter the information about the new book:" << '\n';
        cout << "=========================================" << '\n';
        cout << "Enter the Name of book: ";
        getline(cin, Book[Size_Of_Books].Name);
        cout << "Enter the Code of book: ";
        cin >> Book[Size_Of_Books].Code;
        cin.ignore();
        cout << "Enter the Category of book: ";
        getline(cin, Book[Size_Of_Books].Category);
        cout << "Enter The Author Name of book: ";
        getline(cin, Book[Size_Of_Books].Author_Name);
        cout << "Enter the Edition of book: ";
        cin >> Book[Size_Of_Books].Edition;
        cin.ignore();
        cout << "Enter the Availability of book: " << '\n';
        cout << "But please, enter (Available) if the book is available or (Not Available) if is not available." << '\n';
        getline(cin, Book[Size_Of_Books].Availability);
        cout << "======================================================" << '\n';
        cout << "Now, " << Book[Size_Of_Books].Name << " is added." << endl;
        cout << "======================================================" << '\n';
        Size_Of_Books++;
        cout << "Do you want to add another book?" << '\n';
        while (true)
        {
            cin >> Ans;
            cin.ignore();
            if (Ans != 'Y' && Ans != 'y' && Ans != 'N' && Ans != 'n')
            {
                INVALID();
                continue;
            }
            else
            {
                break;
            }
        }
        if (Ans == 'N' || Ans == 'n')
        {
            cout << "The book/books have been added successfully." << '\n';
            cout << "=============================================" << endl;
            break;
        }
    }
    cout << "===========================================================" << endl;
}
void Delete_Book(BOOK Book[], int& Size_Of_Books)
{
    int Num_Book;
    char Answer;
    while (true)
    {
        cout << "PRESS:" << endl;
        cout << "======" << endl;
        for (int i = 0; i < Size_Of_Books; i++)
        {
            cout << i + 1 << " ==> To Delete " << Book[i].Name << endl;
        }
        cin >> Num_Book;
        if (Num_Book < 1 || Num_Book > Size_Of_Books)
        {
            INVALID();
            continue;
        }
        else
        {
            Num_Book--;
            cout << "Now, " << Book[Num_Book].Name << " is delted." << endl;
            cout << "=========================================" << endl;
            for (int i = Num_Book; i < Size_Of_Books; i++)
            {
                Book[i] = Book[i + 1];
            }
            Size_Of_Books--;
        }
        do
        {
            cout << "Do you want to delete another book (Y/N)? ";
            cin >> Answer;
            if (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n')
            {
                INVALID();
                continue;
            }
            else
            {
                break;
            }
        } while (true);
        if (Answer == 'Y' || Answer == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    cout << "===========================================================" << endl;
}
//Functions of Students
void Data_of_Students()
{
    Student[0].Firstname = "Basmala";
    Student[0].Secondname = "Ayman";
    Student[0].ID = "2022123456";
    Student[0].Password = "12345678";
    Student[0].Email = "BasmalaAyman_student@Library.com";

    Student[1].Firstname = "Ahmed";
    Student[1].Secondname = "Sakr";
    Student[1].ID = "2022012345";
    Student[1].Password = "87654321";
    Student[1].Email = "AhmedSakr_student@Library.com";

    Student[2].Firstname = "Tasneem";
    Student[2].Secondname = "Mohamed";
    Student[2].ID = "2022654321";
    Student[2].Password = "01234567";
    Student[2].Email = "TasneemMohamed_student@Library.com";

    Student[3].Firstname = "Toka";
    Student[3].Secondname = "Karam";
    Student[3].ID = "2022543210";
    Student[3].Password = "76543210";
    Student[3].Email = "TokaKaram_student@Library.com";

    Student[4].Firstname = "Basmala";
    Student[4].Secondname = "Tarek";
    Student[4].ID = "2022987654";
    Student[4].Password = "23456789";
    Student[4].Email = "BasmalaTarek_student@Library.com";
}
void Sign_Up_Student(int& Size_of_Student)
{
    cout << "We need some information about you to create a new account:" << endl;
    cout << "============================================================" << endl;
    cout << "Enter your First Name: ";
    cin >> Student[Size_of_Student].Firstname;
    cout << "Enter your Second Name: ";
    cin >> Student[Size_of_Student].Secondname;
    cout << "Enter your ID: ";
    cin >> Student[Size_of_Student].ID;
    cout << "Enter your Password (Without Spaces): ";
    cin >> Student[Size_of_Student].Password;
    Student[Size_of_Student].Email = Student[Size_of_Student].Firstname + Student[Size_of_Student].Secondname + "_student@Library.com";
    cout << "===========================================================" << endl;
    cout << "Congartulation!!" << endl;
    cout << "=================" << endl;
    cout << "Now, you have an account." << endl;
    cout << "And your Email is: " << Student[Size_of_Student].Email << endl;
    cout << "===========================================================" << endl;
    Size_of_Student++;
}
int Log_In_Student(int Size_Of_Students, int& Indix)
{
    string Email, Password, Actual_Password;
    bool Is_Found = 1;
    cout << "Please, enter your Email: ";
    cin >> Email;
    for (int i = 0; i < Size_Of_Students; i++)
    {
        int Count = 0;
        if (Email != Student[i].Email)
        {
            Is_Found = 0;
            continue;
        }
        else if (Email == Student[i].Email)
        {
            Actual_Password = Student[i].Password;
            Indix = i;
            do
            {
                cout << "Please, enter your Password (Without Spaces): ";
                cin >> Password;
                if (Actual_Password == Password)
                {
                    cout << "================================================" << endl;
                    cout << "You have registered successfully." << endl;
                    cout << "============================================================" << endl;
                    return 1;
                }
                Count++;
                if (Count < 3)
                {
                    cout << "=====================================" << endl;
                    cout << "This Pssword is WRONG!!" << endl;
                    cout << "Please, try again" << endl;
                    cout << "============================================================" << endl;
                }
                else if (Count == 3)
                {
                    return 2;
                }
            } while (Count < 3);
        }
    }
    return -1;
}
void Modify_Info_Student(int& Indix)
{
    int Choice;
    char Answer;
    while (true)
    {
        cout << "PRESS:" << endl;
        cout << "=======" << endl;
        cout << "1 ==> To Modify your First Name." << endl;
        cout << "2 ==> To Modify your Second Name." << endl;
        cout << "3 ==> To Modify your ID." << endl;
        cout << "4 ==> To Modify your Password." << endl;
        cout << "===================================" << endl;
        cin >> Choice;
        if (Choice == 1)
        {
            cout << "Enter your updated First Name: ";
            cin >> Student[Indix].Firstname;
            Student[Indix].Email = Student[Indix].Firstname + Student[Indix].Secondname + "_student@Library.com";
            cout << "Your First Name is modified successfully." << endl;
            cout << "And new your Email is: " << Student[Indix].Email << endl;
            cout << "==========================================" << endl;
        }
        else if (Choice == 2)
        {
            cout << "Enter your updated Second Name: ";
            cin >> Student[Indix].Secondname;
            cout << "Your Second Name is modified successfully." << endl;
            Student[Indix].Email = Student[Indix].Firstname + Student[Indix].Secondname + "_student@Library.com";
            cout << "Your First Name is modified successfully." << endl;
            cout << "And your Email is: " << Student[Indix].Email << endl;
            cout << "==========================================" << endl;
        }
        else if (Choice == 3)
        {
            cout << "Enter your updated ID: ";
            cin >> Student[Indix].ID;
            cout << "Your ID is modified successfully." << endl;
            cout << "==================================" << endl;
        }
        else if (Choice == 4)
        {
            cout << "Enter your updated Password: ";
            cin >> Student[Indix].Password;
            cout << "Your Password is modified successfully." << endl;
            cout << "========================================" << endl;
        }
        else
        {
            INVALID();
            continue;
        }
        do
        {
            cout << "Do you want to modify another information (Y/N)? ";
            cin >> Answer;
            if (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n')
            {
                INVALID();
                continue;
            }
            else
            {
                break;
            }
        } while (true);
        cout << "===========================================================" << endl;
        if (Answer == 'Y' || Answer == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
}
void Show_Name_Books(BOOK Book[], int Size_Of_Books)
{
    cout << "PRESS:" << endl;
    cout << "=======" << endl;
    for (int i = 0; i < Size_Of_Books; i++)
    {
        cout << i + 1 << " ==> To Show " << Book[i].Name << endl;
    }
    cout << "================================================" << endl;
}
void Info_Book(BOOK Books[], int Size_Of_Books)
{
    int Choice;
    char Answer;
    while (true)
    {
        Show_Name_Books(Books, Size_Of_Books);
        cin >> Choice;
        if (Choice < 1 || Choice > Size_Of_Books)
        {
            INVALID();
            continue;
        }
        cout << "Name: " << Books[Choice - 1].Name << endl;
        cout << "Code: " << Books[Choice - 1].Code << endl;
        cout << "Category: " << Books[Choice - 1].Category << endl;
        cout << "Author Name: " << Books[Choice - 1].Author_Name << endl;
        cout << "Edition: " << Books[Choice - 1].Edition << endl;
        cout << "Availability: " << Books[Choice - 1].Availability << endl;
        cout << "=============================================================" << endl;
        do
        {
            cout << "Do you want to show information about another book (Y/N)? ";
            cin >> Answer;
            if (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n')
            {
                INVALID();
                continue;
            }
            else
            {
                break;
            }
        } while (true);
        if (Answer == 'Y' || Answer == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    cout << "===========================================================" << endl;
}
void Select_Books(BOOK Book[], STUDENT Student[], int Size_Of_Books, int& Num_Books_Borrowed, int Indix)
{
    int Num_Book;
    Num_Books_Borrowed = 0;
    cout << "Enter the book numbers you want to borrow (Enter 0 to finish your Order):" << endl;
    cout << "==========================================================================" << endl;
    for (int i = 0; i < Size_Of_Books; i++)
    {
        cout << i + 1 << " - " << Book[i].Name << endl;
    }
    cout << "================================================" << endl;
    while (true)
    {
        cin >> Num_Book;
        if (Num_Book == 0)
        {
            break;
        }
        else if (Num_Book >= 1 && Num_Book <= Size_Of_Books)
        {
            Num_Book--;
            if (Book[Num_Book].Availability == "Not Available")
            {
                cout << "=============================" << endl;
                cout << "This book is Not Available!!" << endl;
                cout << "Choose another book." << endl;
                cout << "=============================" << endl;
                continue;
            }
            else
            {
                Student[Indix].Borrow[Num_Books_Borrowed] = Book[Num_Book].Name;
                Book[Num_Book].Availability = "Not Available";
                Num_Books_Borrowed++;
            }
        }
        else
        {
            INVALID();
            continue;
        }
    }
    cout << "The Books you have borrowed:" << endl;
    cout << "=============================" << endl;
    for (int j = 0; j < Num_Books_Borrowed; j++)
    {
        cout << j + 1 << " - " << Student[Indix].Borrow[j] << endl;
    }
    cout << "===========================================================" << endl;
}
void Modify_Order(BOOK Books[], STUDENT Student[], int Size_Of_Books, int& Num_Books_Borrowed, int Indix)
{
    int Choice_1, Choice_2, Num_Book;
    char Answer;
    while (true)
    {
        cout << "PRESS:" << endl;
        cout << "======" << endl;
        cout << "1 ==> To change one book to another book." << endl;
        cout << "2 ==> To Add a new book to your Order." << endl;
        cout << "3 ==> To Delete a book from your Order." << endl;
        cout << "=============================================" << endl;
        cin >> Choice_1;
        if (Choice_1 == 1)
        {
            while (true)
            {
                cout << "Enter the number of the book you want to change it from your Order:" << endl;
                cout << "====================================================================" << endl;
                for (int i = 0; i < Num_Books_Borrowed; i++)
                {
                    cout << i + 1 << " - " << Student[Indix].Borrow[i] << endl;
                }
                cout << "================================================" << endl;
                cin >> Choice_2;
                if (Choice_2 >= 1 && Choice_2 <= Num_Books_Borrowed)
                {
                    Choice_2--;
                    Books[Choice_2].Availability = "Available";
                    cout << "PRESS:" << endl;
                    cout << "======" << endl;
                    for (int j = 0; j < Size_Of_Books; j++)
                    {
                        cout << j + 1 << " ==> To Get to " << Books[j].Name << endl;
                    }
                    cout << "=============================================" << endl;
                    do
                    {
                        cin >> Num_Book;
                        if (Num_Book >= 1 && Num_Book <= Size_Of_Books)
                        {
                            Num_Book--;
                            if (Books[Num_Book].Availability == "Available")
                            {
                                Student[Indix].Borrow[Choice_2] = Books[Num_Book].Name;
                                Books[Num_Book].Availability = "Not Available";
                                do
                                {
                                    cout << "Do you want to change another book (Y/N)? ";
                                    cin >> Answer;
                                    if (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n')
                                    {
                                        INVALID();
                                        continue;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                } while (true);
                                break;
                            }
                            else
                            {
                                cout << "=============================" << endl;
                                cout << "This book is Not Available!!" << endl;
                                cout << "Choose another book." << endl;
                                cout << "=============================" << endl;
                                continue;
                            }
                        }
                        else
                        {
                            INVALID();
                            continue;
                        }
                    } while (true);
                }
                else
                {
                    INVALID();
                    continue;
                }
                if (Answer == 'Y' || Answer == 'y')
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        else if (Choice_1 == 2)
        {
            do
            {
                cout << "Enter the number of the book you want to add to your Order:" << endl;
                cout << "============================================================" << endl;
                cout << "PRESS:" << endl;
                cout << "======" << endl;
                for (int i = 0; i < Size_Of_Books; i++)
                {
                    cout << i + 1 << " ==> To Add " << Books[i].Name << endl;
                }
                cout << "=============================================" << endl;
                do
                {
                    cin >> Num_Book;
                    if (Num_Book >= 1 && Num_Book <= Size_Of_Books)
                    {
                        Num_Book--;
                        if (Books[Num_Book].Availability == "Not Available")
                        {
                            cout << "=============================" << endl;
                            cout << "This book is Not Available!!" << endl;
                            cout << "Please, choose another book." << endl;
                            cout << "=============================" << endl;
                            continue;
                        }
                        else
                        {
                            Student[Indix].Borrow[Num_Books_Borrowed] = Books[Num_Book].Name;
                            Books[Num_Book].Availability = "Not Available";
                            Num_Books_Borrowed++;
                            break;
                        }
                    }
                    else
                    {
                        INVALID();
                        continue;
                    }
                } while (true);
                do
                {
                    cout << "Do you want to add another book to your Order (Y/N)? ";
                    cin >> Answer;
                    if (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n')
                    {
                        INVALID();
                        continue;
                    }
                    else
                    {
                        break;
                    }
                } while (true);
            } while (Answer == 'Y' || Answer == 'y');
        }
        else if (Choice_1 == 3)
        {
            while (true)
            {
                cout << "Enter the number of the book you want to delete from your Order:" << endl;
                cout << "=================================================================" << endl;
                for (int i = 0; i < Num_Books_Borrowed; i++)
                {
                    cout << i + 1 << " ==> To Delete " << Student[Indix].Borrow[i] << endl;
                }
                cout << "=============================================" << endl;
                do
                {
                    cin >> Choice_2;
                    if (Choice_2 >= 1 && Choice_2 <= Num_Books_Borrowed)
                    {
                        Choice_2--;
                        Num_Books_Borrowed--;
                        Books[Choice_2].Availability = "Available";
                        for (int i = Choice_2; i < Num_Books_Borrowed; i++)
                        {
                            Student[Indix].Borrow[i] = Student[Indix].Borrow[i + 1];
                        }
                        break;
                    }
                    else
                    {
                        INVALID();
                        continue;
                    }
                } while (true);
                do
                {
                    cout << "Do you want to delete another book from your Order (Y/N)? ";
                    cin >> Answer;
                    if (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n')
                    {
                        INVALID();
                        continue;
                    }
                    else
                    {
                        break;
                    }
                } while (true);
                if (Answer == 'Y' || Answer == 'y')
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            INVALID();
            continue;
        }
        do
        {
            cout << "Do you want to modify something else (Y/N)? ";
            cin >> Answer;
            if (Answer != 'N' && Answer != 'n' && Answer != 'Y' && Answer != 'y')
            {
                INVALID();
                continue;
            }
            else if (Answer == 'N' || Answer == 'n')
            {
                cout << "=================================================" << endl;
                cout << "You have modified your order successfully." << endl;
                cout << "Now, The Books you have borrowed after modifying:" << endl;
                cout << "=================================================" << endl;
                for (int j = 0; j < Num_Books_Borrowed; j++)
                {
                    cout << j + 1 << " - " << Student[Indix].Borrow[j] << endl;
                }
                cout << "=================================================" << endl;
                break;
            }
            else
            {
                break;
            }
        } while (true);
        if (Answer == 'Y' || Answer == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
}

void Log_Out()
{
    cout << "THANK YOU :)" << endl;
    cout << "===========================================================" << endl;
}