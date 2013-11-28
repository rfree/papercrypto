#include <stdio.h> /* printf */
#include <stdlib.h> /* getenv */
#include <iostream>
#include <string>
#include <stdexcept>
#include <time.h>  //for randomizing 
#include <assert.h>

using namespace std;

//ready

class cOTP { 
	public:  
		static string ProgramName;
		static string ProgramVersion; 
		void menu ();	// main menu of program
	
	
	private:
		static string alpha; 
		string gen (size_t _mess);//random pad generator
		string conv_mess(string); //conversion message 
		void alpha_test(); // simple alphabet testing
		void base ();	// basic table to manually generate pad with 1k6 and 1k8 dices
		void coding_print(); //printing coding table
		void decoding_print();	//printing decoding table
		string enc(string,string); //encoding function
		void enc_menu();	//encryption menu
		void dec_menu(); 	//decoding menu 
		string dec(string,string); 
		
	
	
};

//VARIABLES
string cOTP::ProgramName = "Paper-Crypto";
string cOTP::ProgramVersion = "0.1wip";
string cOTP::alpha = "ABCDEFGHiJKLMNoPQRSTUVWXYZ0123456789^?!.*+-/=@$:";

void cOTP::alpha_test()
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

void cOTP::menu ()
{	
	string rerun; //decide looping variable

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
			case 5: dec_menu(); break;
			case 6: alpha_test(); break;
			default: cout <<"random number was picked"<< endl; break;
		}
	
		cout << "Once more? (y/n)"<< endl;
		getline (cin, rerun);
	} while (rerun == "y");
}

void cOTP::base ()
{
	cout << "Begining of printing basic table which contains 6x8 signs." << endl
	<< "Used for random PAD generator" << endl;

	int nr=0;
                cout << endl << "Random 6*8 table:" << endl;

                int nrBig=1; // the 1..8 dice

                cout << "   |";         for (int x=1; x<=6; ++x) cout << x << (x<=6 ? "|" : " "); // header
                cout << endl;
                while (nr<alpha.size()) {

                        cout << nrBig <<"->|";

                        for (int x=1; x<=6; ++x) {
                                cout << alpha.at(nr) << (x<=6 ? "|" : " ");
                                ++nr;
                        }
                        cout << endl;

                        if ((0==(nrBig%4)) && (nrBig<7)) { cout<<"   |";
                                for(int x=1; x<=6; ++x) { cout<<"-|"; }
                                cout << endl;
                        }

                        ++nrBig;
                }
}

void cOTP::coding_print()
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
 
void cOTP::decoding_print()
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

string cOTP::gen (size_t _mess)
{
	
	string pad ="";
	for (int ipad = 0; ipad <_mess; ipad++) pad += (alpha.at(rand()%48));       
			
	//cout << pad <<" <---totally random pad"<< endl;  <---testing random pad look

	return pad;
	
}

string cOTP::conv_mess(string mess) 
{ 
	string mess_u="";
	
	for (int i=0; i<mess.length(); i++) 
	{
		if (mess.at(i) == 'i') 
			mess_u += "i"; else
		if (mess.at(i) == 'o') 
			mess_u += "o"; else
		if (mess.at(i) == 'O') 
			mess_u += "o"; else
		if (mess.at(i) == ',') 
			mess_u += "."; else
		if (mess.at(i) == ' ') 
			mess_u += "/";
		else mess_u += toupper(mess.at(i));
	}
	//mess = mess_u; 
	return mess_u;
	
}

void cOTP::enc_menu() 
{ 
	string mess, dec;//mess - message to cipher, dec - decision to make, mess_u - for normal looking message generator
	string pad, less; //pad - secret code for operation, less - if too less characters in handmade pad, coded - coded message
	
	mess=get_mess();
	
	//cout << mess.length() << endl;
	//cout << mess <<endl; //<---printing message ready for coding
	cout << "Do you want autogenerated pad or you want to write down your own pad?(A/O) ";
	getline (std::cin, dec);
	if (dec == "A") 		
	{
		pad=gen(mess.length());
		/*for (int i=0; i<mess.length();i++)
			cout << mess.at(i) << " " << pad.at(i) << endl;*/ // <---printing message and pad side by side
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
	
	cout << "Coded message is: "<<mess << endl
	<< "Coding pad is: " << pad << endl
	<< "Coded message is: " << enc(mess,pad) << endl; 
	
}

string cOTP::enc(string mess, string pad)
{ 
	cout << pad.length() << endl << mess.length() << endl;
	assert (pad.length()<=mess.length());

	
	string coded="";
	for (int i = 0; i < mess.length(); i++)
	{
		
		coded += alpha.at((alpha.find(mess.at(i), 0)+ alpha.find(pad.at(i), 0)) % alpha.size()); //coding message
		/*cout << "Position of message letter in alphabet is: "<< alpha.find (mess.at(i), 0)<<endl;
		cout << "Position of pad letter in alphabet is: "<< alpha.find (pad.at(i), 0)<<endl;
		cout << "position of encrypted letter in alphabet is: " << alpha.find(mess.at(i), 0)+ alpha.find(pad.at(i), 0) % alpha.size() << endl;*/ //<---Debugging message for position in alphabet for each letter
		//cout << coded << endl;
	}
	/*for (int i=0; i<mess.length();i++)
			cout << mess.at(i) << " " << pad.at(i) << " " << coded.at(i) << endl; */ //printing singe under sign whole message, pad and coded message
	/*cout << "Coded message is: "<<mess << endl
	<< "Coding pad is: " << pad << endl
	<< "Coded message is: " << coded << endl; */
	return coded;
}

void cOTP::dec_menu()
{	
	string enc_mess, pad; // enc_mess - encrypted message, pad, mess - 
	
	enc_mess = pad  =""; //just to be sure that it's empty string
	cout << "Starting decoding of message!!" << endl;
	do
	{		
		cout << "Please write your encrypted message: ";
		getline(std::cin, enc_mess);
		cout << "Please write your pad: ";
		getline(std::cin, pad);
	if (enc_mess.length() != pad.length()) cout << "Message or pad are invalid! Please write them again!" << endl; //error message
	}while (enc_mess.length() != pad.length()); //checking length of strings
	cout << "Decoded message is: " << dec(enc_mess,pad) << endl; //result 
		
} 

string cOTP::dec(string enc_mess, string pad) 
{ 
	string mess=""; //decoded message
	for (int i = 0; i < pad.length(); i++) //decoding loop
	{	
		int num = alpha.find(enc_mess.at(i), 0)- alpha.find(pad.at(i), 0);
		if (num < 0) num += alpha.length();
		mess += alpha.at(num);
	}
	
	return mess;
}

string cOTP::get_mess() 
{ 
	string mess;
	cout << "Write your message to code: ";
	getline (std::cin, mess);
	//cout << "Length of your message is: "<< mess.length() << endl ; // <--- length of message
	
	mess=conv_mess(mess); 
	return mess;
}

// MAIN
int main ()
{
	srand (time(NULL));
	cOTP encryption;
	cout << "Welcome to " << cOTP::ProgramName << " version " << cOTP::ProgramVersion << endl;
	encryption.menu ();
}
