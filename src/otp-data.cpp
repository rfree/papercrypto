#include <stdio.h>      /* printf */
#include <stdlib.h>     /* getenv */
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
	for (char i='A'; i<='Z'; ++i) { char cs[2]; cs[0]=i; cs[1]='\0'; alpha += string(cs); }
	for (int i=0; i<=9; ++i) { char cs[2]; cs[0]='0'+i; cs[1]='\0'; alpha += string(cs); }
	for (int i=0; i<chars.size(); ++i) { alpha += chars.at(i); }

	alpha = "ABCDEFGHiJKLMNoPQRSTUVWXYZ0123456789^?!.*+-/=@$:"; // XXX
//	alpha = "ABCD" ;


	cout << alpha.size() << endl;
	cout << alpha << endl;


	if (1)
	{ // table for 6 + 8 dice random 48 number generation

		int nr=0;
		cout << "\nRandom 6*8 table:" << endl;

		int nrBig=1; // the 1..8 dice

		cout << "   |";  	for (int x=1; x<=6; ++x) cout << x << (x<=6 ? "|" : " "); // header
		cout << endl;
		while (nr<alpha.size()) {

			cout << nrBig<<"->|";

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
	


	{ // table of code/decode
		int nr=0;
		cout << "\n the ROT table:" << endl;

		int S = alpha.size();


		for (int y=0; y<S; ++y) {
			if ((0==(y%5)) && (y<700)) { 
cout<<endl;
				cout << ">>>>>║";  	for (int x=0; x<S; ++x) cout << alpha.at(x) << "║" ; // header
				cout << "<<<<<" << endl;
			} 

			char c=alpha.at(y);
			cout << c<<c<<c <<"->┊";

			bool do_decode=1;

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
	


}

