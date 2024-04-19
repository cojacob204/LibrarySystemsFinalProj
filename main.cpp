#include <iostream>
using namespace std;

class books{
public:
    string title;
    int id;
};

class account {
private:
    string password;
public:
    string fname;
    string lname;
    string titleout[2] = {"None","None"};
    unsigned int idout[2] = {0,0};
    int numbook=0;

    //Private Functions//
    void setpass(string p){
        password=p;
    }
    bool login(string fn,string ln,string p){
        bool log=false;
        if(fn==fname && ln==lname && p==password){
            log=true;
            cout<<"\n***Access Granted***\n\n***Welcome "<<fn<<" "<<ln<<"***\n\n";}
        else;
        return log;
    }
    void addbook1(string title,int id){
        if(titleout[0]=="None") {
            titleout[0] = title;
            idout[0] = id;
            numbook += 1;
        }
        else addbook2(title, id);
    }
    void addbook2(string title,int id){
        if(titleout[1]=="None") {
            titleout[1] = title;
            idout[1] = id;
            numbook += 1;
        }
        else addbook1(title, id);
    }
    void removebook(int i){
        titleout[i-1]="None";
        idout[i-1]=0;
        numbook-=1;
    }
};

int main() {
    //Variables//
    unsigned int uin = 5;       //User Input Variable//
    unsigned int rc, i, bid;    //Used for Return and Checkout input//
    string bt;                  //Used for Return and Checkout input//
    string fname, lname, pass;  //Login//
    int catin, *cid;                  //Used in Catalogue//
    string *ct;               //Used in Catalogue//
    bool log = false, log2 = false, log3 = false; //Login Access//

    //Books in System//
    books b1;
    b1.title = "To Kill a Mockingbird";
    b1.id = 1245;

    books b2;
    b2.title = "The Fox and the Hound";
    b2.id = 1265;

    books b3;
    b3.title = "Fellowship of the Ring";
    b3.id = 1589;

    books b4;
    b4.title = "Harry Potter and the Sorcerer's Stone";
    b4.id = 1934;

    books b5;
    b5.title = "Ender's Game";
    b5.id = 2099;

    books b6;
    b6.title = "Fahrenheit 451";
    b6.id = 1251;

    books b7;
    b7.title = "Eragon";
    b7.id = 1599;

    string catalogue[7] = {b1.title,b2.title,b3.title,b4.title,b5.title,b6.title,b7.title};
    int catalogueid[7] = {b1.id,b2.id,b3.id,b4.id,b5.id,b6.id,b7.id};

    //User Accounts in System//
    account a1, a2, a3;

    a1.fname = "James";
    a1.lname = "Madison";
    a1.setpass("Deco245$");
    a1.addbook1(b1.title, b1.id);
    a1.addbook2(b2.title, b2.id);

    a2.fname = "Rebecca";
    a2.lname = "Sutherland";
    a2.setpass("ILOVECATS1234");
    a2.addbook1(b4.title, b4.id);

    a3.fname = "Loretta";
    a3.lname = "Smith";
    a3.setpass("P41Hn$");

    //Login//
    cout << "Library Services\n"
            "-----------------------------------------\n";
    while (!log && !log2 && !log3) {
        cout << "Login\n"
                "Enter Full Name:";
        cin >> fname >> lname;
        cout << "Enter Password:";
        cin >> pass;
        log = a1.login(fname, lname, pass);
        log2 = a2.login(fname, lname, pass);
        log3 = a3.login(fname, lname, pass);
        if (!log && !log2 && !log3)
            cout << "\n***Access Denied: Please Try Again***\n\n";
    }

    //Main Menu//
    while (uin != 0) {
        cout << "\n\nMain Menu\n"
                "-----------------------------------------\n"
                "1. Books Checked Out\n"
                "2. Return/Check Out\n"
                "3. Catalogue\n"
                "0. Close System\n\n"
                "**Enter a number to continue**\n";
        cin >> uin;

        //Account 1//
        if (log) {
            switch (uin) {

                //Books Checked Out//
                case 1: {
                    cout << "Books Checked Out (Max=2): " << a1.numbook <<
                         "\n-----------------------------------------\n";
                    if (a1.numbook != 0) {
                        cout << "Title:\n"
                             << a1.titleout[0] << "\n"
                             << a1.titleout[1] << "\n"
                                                  "Id:\n"
                             << a1.idout[0] << "\n"
                             << a1.idout[1];
                    } else {
                        cout << "You have 0 books out";
                    }
                    break;
                }

                    //Book Return/Checkout//
                case 2: {
                    cout << "Select an Option from the list:\n"
                            "1. Return\n"
                            "2. Check Out (Max=2)\n"
                            "3. Check Out (Catalogue)\n";
                    cin >> rc;
                    if (rc == 1) {
                        cout << "Which book would you like to return?\n"
                             <<"1. "<< a1.titleout[0] << "\n"
                             <<"2. "<< a1.titleout[1] << "\n";
                        cin >> i;
                        a1.removebook(i);
                    } else if (rc == 2){
                        if (a1.numbook == 2)
                            cout << "Maximum Checkout Reached.";
                        else if (a1.numbook == 1) {
                            cout << "Enter book Title and ID: ";
                            cin >> bt;
                            cin >> bid;
                            a1.addbook2(bt, bid);
                        } else if (a1.numbook == 0) {
                            cout << "Enter book Title and ID: ";
                            cin >> bt;
                            cin >> bid;
                            a1.addbook1(bt, bid);
                        }
                    }
                    else if(rc==3){
                        if (a1.numbook == 2)
                            cout << "Maximum Checkout Reached.";
                        else if (a1.numbook == 1) {
                            a1.addbook2(*ct, *cid);
                        } else if (a1.numbook == 0) {
                            a1.addbook1(*ct, *cid);
                        }
                    }
                        break;
                }

                //Catalogue//
                case 3: {
                    cout << "Catalogue:"
                            "\n-----------------------------------------\n";
                    for (int k = 0; k < 7; k++) {
                        cout <<(k+1)<<": "<< catalogue[k] << "\n"
                             << catalogueid[k]
                             << "\n\n";
                    }
                    cout<<"Enter the book number you would like to check out (enter 8 to continue without)";
                    cin>>catin;
                    if(catin!=8) {
                        ct = &catalogue[catin-1];
                        cid = &catalogueid[catin-1];
                        cout<<"\nYour book choice has been saved.\n"
                              "Return to the \"Checkout\" screen to continue.";
                    }
                    else;
                }

                //Exit Case//
                case 0:{
                    cout<<"\n\n***Thank you for using library services!***\n\n";
                }
                default: {
                    cout<<"Please Enter a Proper Input";
                    break;
                }
            }
        }

        //Account 2//
        else if (log2) {
            switch (uin) {

                //Books Checked Out//
                case 1: {
                    cout << "Books Checked Out (Max=2): " << a2.numbook <<
                         "\n-----------------------------------------\n";
                    if (a2.numbook != 0) {
                        cout << "Title:\n"
                             << a2.titleout[0] << "\n"
                             << a2.titleout[1] << "\n"
                                                  "\nId:\n"
                             << a2.idout[0] << "\n"
                             << a2.idout[1];}
                    else {
                        cout << "You have 0 books out";
                    }
                    break;
                }

                //Book Return/Checkout//
                case 2: {
                    cout << "Select an Option from the list:\n"
                            "1. Return\n"
                            "2. Check Out (Max=2)\n"
                            "3. Check Out (Catalogue)\n";
                    cin >> rc;
                    if (rc == 1) {
                        cout << "Which book would you like to return?\n"
                             <<"1. "<< a2.titleout[0] << "\n"
                             <<"2. "<< a2.titleout[1] << "\n";
                        cin >> i;
                        a2.removebook(i);
                    } else if (rc == 2){
                        if (a2.numbook == 2)
                            cout << "Maximum Checkout Reached.";
                        else if (a2.numbook == 1) {
                            cout << "Enter book Title and ID: ";
                            cin >> bt;
                            cin >> bid;
                            a2.addbook2(bt, bid);
                        } else if (a2.numbook == 0) {
                            cout << "Enter book Title and ID: ";
                            cin >> bt;
                            cin >> bid;
                            a2.addbook1(bt, bid);
                        }}
                    else if(rc==3){
                        if (a2.numbook == 2)
                            cout << "Maximum Checkout Reached.";
                        else if (a2.numbook == 1) {
                            a2.addbook2(*ct, *cid);
                        } else if (a2.numbook == 0) {
                            a2.addbook1(*ct, *cid);
                        }
                    }
                        break;
                }

                //Catalogue//
                case 3: {
                    cout << "Catalogue:"
                            "\n-----------------------------------------\n";
                    for (int k = 0; k < 7; k++) {
                        cout <<(k+1)<<": "<< catalogue[k] << "\n"
                             << catalogueid[k]
                             << "\n\n";
                    }
                    cout<<"Enter the book number you would like to check out (enter 8 to continue without):\n";
                    cin>>catin;
                    if(catin!=8) {
                        ct = &catalogue[catin-1];
                        cid = &catalogueid[catin-1];
                        cout<<"\nYour book choice has been saved.\n"
                              "Return to the \"Checkout\" screen to continue.";
                    }
                    else;
                }

                //Exit Case//
                case 0:{
                    cout<<"\n\n***Thank you for using library services!***\n\n";
                }
                default:{
                    cout<<"Please Enter a Proper Input";
                    break;
                }
            }
        }

        //Account 3//
        else {
            switch (uin) {
                //Books Checked Out//
                case 1: {
                    cout << "Books Checked Out (Max=2): " << a3.numbook <<
                         "\n-----------------------------------------\n";
                    if (a3.numbook != 0) {
                        cout << "Title:\n"
                             << a3.titleout[0] << "\n"
                             << a3.titleout[1] << "\n"
                                                  "Id:\n"
                             << a3.idout[0] << "\n"
                             << a3.idout[1];
                    } else {
                        cout << "You have 0 books out";
                    }
                    break;
                }

                //Book Return/Checkout//
                case 2: {
                    cout << "Select an Option from the list:\n"
                            "1. Return\n"
                            "2. Check Out (Max=2)\n"
                            "3. Check Out (Catalogue)\n";
                    cin >> rc;
                    if (rc == 1) {
                        cout << "Which book would you like to return?\n"
                             <<"1. "<< a2.titleout[0] << "\n"
                             <<"2. "<< a2.titleout[1] << "\n";
                        cin >> i;
                        a3.removebook(i);
                    } else if (rc == 2){
                        if (a3.numbook == 2)
                            cout << "Maximum Checkout Reached.";
                        else if (a3.numbook == 1) {
                            cout << "Enter book Title and ID: ";
                            cin >> bt;
                            cin >> bid;
                            a3.addbook2(bt, bid);
                        } else if (a3.numbook == 0) {
                            cout << "Enter book Title and ID: ";
                            cin >> bt;
                            cin >> bid;
                            a3.addbook1(bt, bid);
                        }
                    }
                    else if(rc==3){
                        if (a3.numbook == 2)
                            cout << "Maximum Checkout Reached.";
                        else if (a3.numbook == 1) {
                            a3.addbook2(*ct, *cid);
                        } else if (a3.numbook == 0) {
                            a3.addbook1(*ct, *cid);
                        }
                    }
                        break;
                }

                //Catalogue//
                case 3: {
                    cout << "Catalogue:"
                            "\n-----------------------------------------\n";
                    for (int k = 0; k < 7; k++) {
                        cout <<(k+1)<<": "<< catalogue[k] << "\n"
                             << catalogueid[k]
                             << "\n\n";
                    }
                    cout<<"Enter the book number you would like to check out (enter 8 to continue without)";
                    cin>>catin;
                    if(catin!=8) {
                        ct = &catalogue[catin-1];
                        cid = &catalogueid[catin-1];
                        cout<<"\nYour book choice has been saved.\n"
                              "Return to the \"Checkout\" screen to continue.";
                    }
                    else;
                }

                //Exit Case//
                case 0:{
                    cout<<"\n\n***Thank you for using library services!***\n\n";
                }
                default: {
                    cout<<"Please Enter a Proper Input";
                    break;
                }
            }
        }
    }
}