#include <stdio.h> /* printf */
#include <stdlib.h> /* getenv */
#include <iostream>
#include <string>
#include <stdexcept>

//ready
void menu ();
void base ();
void coding_print(); 
void decoding_print();
//Not ready yet
/*void enc_menu();
void dec_menu(); */

using namespace std;
int main ()
{
        char a='a', z='z';
        

        string chars = string("^?!.*+-/=@$:");
        /*

? ! .
+ - * /
/ :
+ / =
@
#
~


^?!.*+-/=@$~



        
         */

        int az = ((int)(z-a+1)) ;
        int num = 10;
        int ch = chars.size();
        int all = az + num + ch;

        string alpha="";
	string alphatest="";
        for (char i='A'; i<='Z'; ++i) 
	{ 
		char cs[2]; // TODO switch to stirng(c,1) method -rfreeman
		switch (i)	
		{
			case 'I': cs[0]='i'; cs[1]='\0'; alphatest += string(cs); break;
			case 'O': cs[0]='o'; cs[1]='\0'; alphatest += string(cs); break;
			default: cs[0]=i; cs[1]='\0'; alphatest += string(cs); break;
		} 
	}

        for (int i=0; i<=9; ++i) { char c; c='0'+i; alphatest += string(1,c); }
        for (int i=0; i<chars.size(); ++i) { alphatest += chars.at(i); } // speciall characters

        alpha = "ABCDEFGHiJKLMNoPQRSTUVWXYZ0123456789^?!.*+-/=@$:"; // this is the expected standarized alphabet
//        alpha = "ABCD" ;


        cout << alpha.size() << endl;
        cout << alpha << endl;
	cout << alphatest.size() << endl;
	cout << alphatest << endl;
	if (alpha != alphatest) {
		cerr << "Warning, alphabet is not matching." << endl;
		throw std::runtime_error("Assert");
	}

	cout << "Do you want to see 6+8 dice coding table?(y/n)" << endl;
	string dec;
	getline(cin,dec);


        if (dec == "y")
        { // table for 6 + 8 dice random 48 number generation

                int nr=0;
                cout <<endl<< "Random 6*8 table:" << endl;

                int nrBig=1; // the 1..8 dice

                cout << " |";         for (int x=1; x<=6; ++x) cout << x << (x<=6 ? "|" : " "); // header
                cout << endl;
                while (nr<alpha.size()) {

                        cout << nrBig<<"->|";

                        for (int x=1; x<=6; ++x) {
                                cout << alpha.at(nr) << (x<=6 ? "|" : " ");
                                ++nr;
                        }
                        cout << endl;

                        if ((0==(nrBig%4)) && (nrBig<7)) { cout<<" |";
                                for(int x=1; x<=6; ++x) { cout<<"-|"; }
                                cout << endl;
                        }

                        ++nrBig;
                }
        }
        
	cout << "Do you want to see table of codes?(y/n)" << endl;
	getline(std::cin,dec);
	bool do_decode = 0;
	if (dec == "y")
        { 
		cout << "(C)oding or (d)ecoding table?" << endl;
		getline(std::cin,dec);

		
                
		// table of code/decode
                int nr=0;
                cout << endl << " the ROT table:" << endl;

                int S = alpha.size();

 	// if ((0==(y%5)) && (y<700)) {
				cout<< endl;
                                cout << ">>>>>║";         for (int x=0; x<S; ++x) cout << alpha.at(x) << "║" ; // header
                                cout << "<<<<<" << endl;
        //}
                for (int y=0; y<S; ++y) {
                      

                        char c=alpha.at(y);
                        cout << c<< c<< c <<"->┊";
			if (dec == "C") do_decode = 0;
			else do_decode=1;
                        for (int x=0; x<S; ++x) {
                                int nr;
                                if (!do_decode) nr = (x+y)%S; // <--- encoding
                                else { nr = x-y; if (nr<0) nr+=S; }
                                cout << alpha.at(nr) << "┊";
                                // ║┊
                        }
                        cout << endl;

                }
        }
	cout << "Write your message to code: ";
	string mess;
	getline (std::cin, mess);
	cout << "Length of your message is: "<< mess.length() <<endl <<"Write your pad: ";
	string pad;
	getline (std::cin, pad);
	for (int i=0; i<mess.length();i++)
		cout << mess.at(i) << " " << pad.at(i) << endl;
	//encrypt (mess, pad);
        


}

void menu ()
{
	cout << "What you want to do?" << endl
	<< "1 - Print 6x8 char table" << endl
	<< "2 - Print coding table" << endl
	<< "3 - Print decoding table" << endl
	<< "4 - Encode message" << endl
	<< "5 - Decode message" << endl;

	int dec;

	switch (dec)
	{
		case 1: cout << "Ain't ready yet" <<endl;/*base();*/ break;
		case 2: cout << "Ain't ready yet" <<endl;/*coding_print();*/ break;
		case 3: cout << "Ain't ready yet" <<endl;/*decoding_print();*/ break;
		case 4: cout << "Ain't ready yet" <<endl;/*enc_menu();*/ break;
		case 5: cout << "Ain't ready yet" <<endl;/*dec_menu();*/ break;
		default: cout <<"random number was picked"<<endl; break;
	}
}

void menu ();
void base ();
void coding_print(); 
void decoding_print();
