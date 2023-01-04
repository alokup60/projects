#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<windows.h>

using namespace std;

void menu();

class ManageMenu
{
    protected:
       string userName;
    
    public:     
    //constructor
        ManageMenu()
        {
            system("color 0A");  //change terminal colour
            cout << "\n\n\n\n\n\n\n\n\t Enter your name to continue as an Admin: ";
            cin>> userName;
            system("CLS");
            menu();
        }
        ~ManageMenu() {}
};

class Customers 
{
    public:
        string name, gender, address;
        int age, mobileNO;
        static int  cusID;
        char all[999];

        void getDetails() 
        {
            // for save the details in text format
            ofstream out("old-customer.txt", ios::app);
            {
                cout<<"Enter Customer ID: ";
                cin>>cusID;
                cout<<"Enter Customer Name: ";
                cin>>name;
                cout<<"\nEnter Customer gender: ";
                cin>>gender;
                cout<<"\nEnter Customer address: ";
                cin>>address;
                cout<<"\nEnter Customer age: ";
                cin>>age;
                cout<<"\nEnter Customer mobileNo: ";
                cin>>mobileNO;
            }
            
            out<<"\n CustomerID: "<< cusID << "\n Name: "<<name <<"\n Age: "<<age <<"\n Mobile Number: "<<mobileNO <<"\n Address: "<<address<<"\nGender: "<<gender <<endl;
            out.close(); //close the file

            cout<<"\n SAVED \n NOTE: we save your details record for the future purposes\n" <<endl;
        }

        //show save files which is above
        void showDetails() 
        {
            ifstream in("old-customers.txt");
            {
                if(!in)
                {
                    cout<< "File Error!" <<endl;
                }
                while(!(in.eof()))
                {
                    in.getline(all, 999);
                    cout<< all <<endl;
                }
                in.close();
            }
        }
};

int  Customers::cusID;

class Cabs 
{

    public:
        int cabChoice;
        int kilometers;
        float cost;
        static float lastcabCost;

        void cabDetails() 
        {
            cout<< "We colloborated with fastest , safest and smartest cab service around the country" <<endl;
            cout<< "--------------OVERSEAS CAB SERVICE----------------\n" <<endl;
            cout<< "1. Rent a Standard cab - Rs.15 for 1KM" << endl;
            cout<< "2. Rent a Luxury Cab - Rs.25 per 1KM" << endl;

            cout<<"\n Calculate for your journey: "<<endl;
            cout<<"Enter which kind of cab you want: ";
            cin>>cabChoice;
            cout<<"Enter kilometers you have to travel";
            cin>>kilometers;

            int hireCab;

            if(cabChoice == 1) {
                cost = kilometers * 15;
                cout<<"\n Your total cost " <<cost <<"rupees for a standard Cab"<<endl;
                cout<< "Press 1 to hire this cab : or";
                cout<< "Press 2 to select another cab: ";
                cin>>hireCab;

                system("CLS");

                if(hireCab == 1) {
                    lastcabCost = cost;
                    cout<< "\n You have succesfully hired a standard cab" <<endl;
                    cout<<"Go to Main Menu and take the receipt" <<endl;
                }
                else if(hireCab == 2) {
                    cabDetails();
                }
                else{
                    cout<< "\n Invalid Input! Redirecting to previous menu "<<endl;
                    Sleep(999);
                    system("CLS");
                    cabDetails();
                }
            }

            else if(cabChoice == 2) 
            {
                cabDetails();
            }
            else 
            {
                cout<< "\n Invalid Input! Redirecting to Main menu "<<endl;
                    Sleep(999);
                    system("CLS");
                    menu();
            }

            cout<< "Press 1 to Redirect to Main Menu: ";
            cin>> hireCab;
            system("CLS");
            if(hireCab == 1)
            {
                menu();
            }
            else {
                menu();
            }
        }
    
};

float Cabs ::lastcabCost;

class Booking 
{

public:
    int chHotel;
    int packCh;
    static float hotelCost;

    void hotels() {
        string hotelNo[] = {"Hawana", "Hayat", "Reflena"};
        for(int i = 0; i<3; i++) {
            cout<< (i+1) <<". Hotel" <<hotelNo[i] <<endl;
        }

        cout << "\n Currently we collaborated above hotels!" <<endl;

        cout<< "Press Any key to back or \n Enter number of the hotel you want to book: ";
        cin >> chHotel;

        system("CLS");

        if(chHotel == 1) 
        {
            cout<< "============WELCOME TO HOTEL AVENDRA==============\n " <<endl;

            cout << "The Garden, food and beverages. Enjoy all you can drink, stay cool and get chilled in the summer sun." <<endl;

            cout <<"Packages offered by Yurveda:\n  "<<endl;

            cout<< "1. Standard Pack" <<endl;
            cout<< "\t All basic facilities you need just for: Rs.5000.00 " <<endl;
            cout << "2. Premium Pack" << endl;
            cout << "\t Enjoy premium Rs. 10000.00" <<  endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\t Live a Luxury at AYurveda: Rs.15000.00" << endl;

            cout << "\nPress another key to back or \nEnter package number you want to book: ";
            cin >> packCh;

            if (packCh == 1)
            {
                hotelCost = 5000.00;
                cout << "\n You have successfully booked standard pack at ayurveda " <<endl;
                cout << "Goto Menu and take the receipt" <<endl;
            }
            else if(packCh == 2) 
            {
                hotelCost = 10000.00;
                cout << "\n You have successfully booked premium pack at ayurveda " <<endl;
                cout << "Goto Menu and take the receipt" <<endl;
            }
            else if(packCh == 3) 
            {
                hotelCost = 15000.00;
                cout << "\n You have successfully booked luxurious pack at ayurveda " <<endl;
                cout << "Goto Menu and take the receipt" <<endl;
            }
            else
            {   
                cout<< "\n Invalid Input! Redirecting to Main menu "<<endl;
                Sleep(999);
                system("CLS");
                hotels();
            }

            int gotoMenu;
            cout << "\n Press 1 to Reirect main menu: ";
            cin>> gotoMenu;
            if(gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else 
        {
            cout<< "\n Invalid Input! Redirecting to Main menu "<<endl;
            Sleep(999);
            system("CLS");
            hotels();
        }
    }

};

float Booking ::hotelCost;
class Charges : public Booking, Cabs, Customers
{
    public:
        void printBill()
        {

            ofstream outf("receipt.txt");
            {

                outf << "================Formal Travel Agency===================" << endl;
                outf << "=======================Receipt========================="<<endl;
                outf << "_______________________________________________________" << endl;

                outf << "Customer ID: " << Customers ::cusID <<endl << endl;
                outf << "Description\t\t\t Total "<<endl;
                outf << "Hotel cost:\t\t" << fixed  << setprecision(2) << Booking::hotelCost << endl;
                outf << "Travel (cabs) cost:\t\t" << fixed  << setprecision(2) << Cabs::lastcabCost << endl;

                outf << "_____________________________________"<<endl;
                outf << "Total Charge:\t\n "<<fixed <<setprecision(2) << Booking::hotelCost+Cabs::lastcabCost << endl;
                outf << "______________________________________"<< endl;
                outf <<"------------------THANK YOU-----------"<< endl;

            }

                outf.close();

        }

        void showBill() {
            ifstream inf("receipt.txt");
            {
                if(!inf)
                {
                    cout<< " File Opening error!" << endl;
                }
                while(!inf.eof())
                {
                    inf.getline(all, 999);
                    cout<<all << endl;
                }
            }
            inf.close();
        }
};

void menu() 
{

    int mainCh;
    int inCh;
    int gotoMenu;

    cout << "\t\t           * TRAVEL AGENCY * \n" <<endl;
    cout << "-----------------------MAIN MENU -----------------" << endl;

    cout <<"\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" <<endl;
    cout << "\t\t\t\t\t\t" << endl;
    cout << "\t\t Customer Management -> 1\t" << endl;
    cout << "\t\t Cabs Management -> 2\t" << endl;
    cout << "\t\t Booking Management -> 3\t" << endl;
    cout << "\t\t Charges & Bill -> 4\t" << endl;
    cout << "\t\t Exit -> 5\t" << endl;
    cout << "\t\t\t\t" << endl;
    cout <<"\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" <<endl;

    cout << "\nEnter Your Choice: ";
    cin>>mainCh;

    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if (mainCh == 1)
    {
        cout << "-----------Customers-----------\n" << endl;
        cout << "1. Enter New Customers"<< endl;
        cout << "2. See Old Customers"<< endl;

        cout << "\n Enter Your Choice: ";
        cin>>inCh;

        system("CLS");
        if(inCh == 1)
        {
            a2.getDetails();
        }
        else if(inCh == 2)
        {
            a2.showDetails();
        }
        else
        {
            cout<< "\n Invalid Input! Redirecting to Main menu "<<endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout <<"\n Press 1 to Redirect main menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1) 
        {
            menu();
        }
        else
        {
            menu();
        }
    }

    else if(mainCh == 2)
    {
        a3.cabDetails();
    }
    else if(mainCh == 3)
    {
        cout<< "---> Book a luxury Hotel using the system <---"<< endl;
        a4.hotels();
    }
    else if (mainCh ==  4)
    {
        cout << "---> Get Your Receipt <---" << endl;
        a5.printBill();

        cout << "Your Receipt is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back to main menu: ";

        cin>>gotoMenu;

        if(gotoMenu == 1)
        {
            system("CLS");
            a5.showBill();
            cout << "\n Press 1 to redirect min menu: ";
            cin>> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if (mainCh == 5)
    {
        cout << "----GOOD-BYE-----"<<endl;
        Sleep(999);
        system("CLS");
        menu();
    }
    else
    {
        cout<< "\n Invalid Input! Redirecting to Main menu "<<endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{

    ManageMenu startobj;

return 0;
}