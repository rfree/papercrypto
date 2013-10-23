#include <stdio.h> /* printf */
#include <stdlib.h> /* getenv */
#include <iostream>
#include <string>

int main ()
{
        char a='a', z='z';
        using namespace std;

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
		char cs[2];
		switch (i)	
		{
			case 'I': cs[0]='i'; cs[1]='\0'; alphatest += string(cs); break;
			case 'O': cs[0]='o'; cs[1]='\0'; alphatest += string(cs); break;
			default: cs[0]=i; cs[1]='\0'; alphatest += string(cs); break;
		} 
	}

        for (int i=0; i<=9; ++i) { char cs[2]; cs[0]='0'+i; cs[1]='\0'; alphatest += string(cs); }
        for (int i=0; i<chars.size(); ++i) { alphatest += chars.at(i); }

        alpha = "ABCDEFGHiJKLMNoPQRSTUVWXYZ0123456789^?!.*+-/=@$:"; // XXX
//        alpha = "ABCD" ;


        cout << alpha.size() << endl;
        cout << alpha << endl;
	cout << alphatest.size() << endl;
	cout << alphatest << endl;
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
