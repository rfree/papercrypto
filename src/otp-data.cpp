#include <stdio.h> /* printf */
#include <stdlib.h> /* getenv */
#include <iostream>
#include <string>
#include <stdexcept>
#include <time.h>  //for randomizing

using namespace std;

//ready
void alpha_test();
void menu ();
void base ();
void coding_print(); 
void decoding_print();
string gen (size_t _mess);
void enc_menu();
//Not ready yet
/*
void dec_menu(); */

const string gProgramName = "Paper-Crypto";
const string gProgramVersion = "0.1wip";
const string alpha = "ABCDEFGHiJKLMNoPQRSTUVWXYZ0123456789^?!.*+-/=@$:";


int main ()
{
	srand (time(NULL));

	cout << "Welcome to " << gProgramName << " version " << gProgramVersion << endl;
        
	menu ();
}

void alpha_test()
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
        for (int i=0; i<chars.size(); ++i) { alphatest += chars.at(i); } // special characters

        cout << alpha.size() << endl;
        cout << alpha << endl;
	cout << alphatest.size() << endl;
	cout << alphatest << endl;
	if (alpha != alphatest) {
		cerr << "Warning, alphabet is not matching." << endl;
		throw std::runtime_error("Assert");
	}
}

void menu ()
{	
	string rerun;

	do
	{
		cout << "What you want to do?" << endl
		<< "1 - Print 6x8 char table" << endl
		<< "2 - Print coding table" << endl
		<< "3 - Print decoding table" << endl
		<< "4 - Encode message" << endl
		<< "5 - Decode message" << endl
		<< "6 - Test alphabet sample string" << endl;

		string dec;
		getline(std::cin, dec);
		int _dec = atoi(dec.c_str());
		switch (_dec)
		{
			case 1: base(); break;
			case 2: coding_print(); break;
			case 3: decoding_print(); break;
			case 4: enc_menu(); break;
			case 5: cout << "Ain't ready yet" << endl;/*dec_menu();*/ break;
			case 6: alpha_test(); break;
			default: cout <<"random number was picked"<< endl; break;
		}
	
		cout << "Once more? (y/n)"<< endl;
		getline (cin, rerun);
	} while (rerun == "y");
}

void base ()
{
	cout << "Begining of printing basic table which contains 6x8 signs." << endl
	<< "Used for random PAD generator" << endl;

	int nr=0;
                cout << endl << "Random 6*8 table:" << endl;

                int nrBig=1; // the 1..8 dice

                cout << " |";         for (int x=1; x<=6; ++x) cout << x << (x<=6 ? "|" : " "); // header
                cout << endl;
                while (nr<alpha.size()) {

                        cout << nrBig <<"->|";

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

void coding_print()
{
	cout << "Printing coding table" << endl;

	string dec;
	bool do_decode = 0;		
                
	// table of code/decode
        int nr=0;
        cout << endl << " the ROT table:" << endl;

        int S = alpha.size();

 	// if ((0==(y%5)) && (y<700)) {
	cout<< endl;
        cout << ">>>>>║";         for (int x=0; x<S; ++x) cout << alpha.at(x) << "║" ; // header
        cout << "<<<<<" << endl;
        //}
        for (int y=0; y<S; ++y) 
	{
		char c=alpha.at(y);
                cout << c<< c<< c <<"->┊";
		
                for (int x=0; x<S; ++x) 
		{
	                int nr;
	                if (!do_decode) nr = (x+y)%S; // <--- encoding
	                else { nr = x-y; if (nr<0) nr+=S; }
                        cout << alpha.at(nr) << "┊";
                                // ║┊
                }
                cout << endl;

         }
        
}
 
void decoding_print()
{
	cout << "Printing coding table" << endl;

	string dec;
	bool do_decode = 1;		
                
	// table of code/decode
        int nr=0;
        cout << endl << " the ROT table:" << endl;

        int S = alpha.size();

 	// if ((0==(y%5)) && (y<700)) {
	cout<< endl;
        cout << ">>>>>║";         for (int x=0; x<S; ++x) cout << alpha.at(x) << "║" ; // header
        cout << "<<<<<" << endl;
        //}
        for (int y=0; y<S; ++y) 
	{
		char c=alpha.at(y);
                cout << c<< c<< c <<"->┊";
		
                for (int x=0; x<S; ++x) 
		{
	                int nr;
	                if (!do_decode) nr = (x+y)%S; // <--- encoding
	                else { nr = x-y; if (nr<0) nr+=S; }
                        cout << alpha.at(nr) << "┊";
                                // ║┊
                }
                cout << endl;

         }
}

string gen (size_t _mess)
{
	string pad ="";
	for (int ipad = 0; ipad <_mess; ipad++) pad += (alpha.at(rand()%48));        // ║┊
			
	cout << pad <<" <---totally random pad"<< endl;

	return pad;
	
}

void enc_menu()
{
	string mess, dec;
	string pad, less, coded;
	
	cout << "Write your message to code with capital letters (I=i, O=o): ";
	getline (std::cin, mess);
	cout << "Length of your message is: "<< mess.length() << endl 
	<< "Do you want autogenerated pad or you want to write down your own pad?(A/O) ";
	getline (std::cin, dec);
	if (dec == "A") 		
	{
		pad = gen (mess.length());
		for (int i=0; i<mess.length();i++)
			cout << mess.at(i) << " " << pad.at(i) << endl;
	} else {
		pad="";
		cout<< "Write down your pad: ";
		getline (std::cin, pad);
		while (pad.length() < mess.length()) 
		{	
			less = "";
			cout << "Type one more sign!" << endl;
			getline(std::cin, less);
			pad += less;
		}
		
	}
	cout << "Started encrypting..." << endl;
	
	coded="";
	for (int i = 0; i < mess.length(); i++)
	{
		
		coded += alpha.at((alpha.find(mess.at(i), 0)+ alpha.find(pad.at(i), 0)) % alpha.size());
		cout << "Position of message letter in alphabet is: "<< alpha.find (mess.at(i), 0)<<endl;
		cout << "Position of pad letter in alphabet is: "<< alpha.find (pad.at(i), 0)<<endl;
		cout << "position of encrypted letter in alphabet is: " << alpha.find(mess.at(i), 0)+ alpha.find(pad.at(i), 0) % alpha.size() << endl;
		//cout << coded << endl;
	}
	for (int i=0; i<mess.length();i++)
			cout << mess.at(i) << " " << pad.at(i) << " " << coded.at(i) << endl;
}
