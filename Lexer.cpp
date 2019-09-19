#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <ctype.h>
//#include <fstream>
#include "Lexer.h"
#include "Tokens.h"

using namespace std;

Lexer::Lexer(char* readMe) {
    

	ifstream myfile;
	myfile.open(readMe);

	char item;
	int line_num = 1;
	char hold;
	string currentString = "";
	string temp;
	Tokens t;
	
	while (myfile.get(item)) {
	    
        cout << item;
        cout << "stuck1?\n";
        
        
		if (isalpha(item)) {

			while (isalnum(item)) {
			    
				currentString = currentString + item;
				myfile.get(item);
			}
			if (currentString == "Queries")
			{
				t = Tokens("QUERIES", currentString, line_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
			}
			else if (currentString == "Rules")
			{
				t = Tokens("RULES", currentString, line_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
			}
			else if (currentString == "Facts")
			{
				t = Tokens("FACTS", currentString, line_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
			}
			else if (currentString == "Schemes")
			{
				t = Tokens("SCHEMES", currentString, line_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
			}
			else{
			    t = Tokens("ID", currentString, line_num);
				myTokens.push_back(t);
				currentString == "";
				currentString.clear();
			}

			//myfile.putback(item);
		//	myfile.get(item);
		}

        else {
			switch (item) {
                  cout <<"66";
			case '+':
			cout << "stuck2?\n";
				t = Tokens("ADD", "+", line_num);
				myTokens.push_back(t);

				cout << "stuck3?\n";
				break;
			case '*':
			cout << "stuck4?\n";
				t = Tokens("MULTIPLY", "*", line_num);
				myTokens.push_back(t);

				cout << "stuck5?\n";
				break;
			case ':':
			
			    cout << "stuck6?\n";
			    hold = myfile.peek();
			    isColon(item, hold, line_num);

				break;
			case '(':
			cout << "stuck8?\n";
				t = Tokens("LEFT_PARAN", "(", line_num);
				myTokens.push_back(t);

				cout << "stuck9?\n";
				break;
			case ')':
			cout << "stuck10?\n";

				t = Tokens("RIGHT_PARAN", ")", line_num);
				myTokens.push_back(t);

				cout << "stuck11?\n";
				break;
			case '?':
			cout << "stuck13?\n";
				t = Tokens("Q_MARK", "?", line_num);
				myTokens.push_back(t);

				cout << "stuck14?\n";
				break;
			case '.':
			cout << "stuck15?\n";
				t = Tokens("PERIOD", ".", line_num);
				myTokens.push_back(t);

				cout << "stuck6?\n";
				break;
			case ',':
			cout << "stuck17?\n";
				t = Tokens("COMMA", ",", line_num);
				myTokens.push_back(t);

				cout << "stuck18?\n";
				break;
			case '#':
			 cout << "stuck20?\n";
				if (myfile.peek() == '|') {
                       
                        cout << "stuck22?\n";
					while (item != '|' && myfile.peek() != '#' || !myfile.eof()) {
						 cout << "stuck23?\n";
						 
						if (item == '\n') {
						    currentString = currentString + item;
						    
							cout << "stuck24?\n";
						}
						else {
						    currentString = currentString + item;
						    cout << "stuck25?\n";
		
						}
						myfile.get(item);
					} 
                    
					currentString = currentString + item;
					myfile.get(item);
			        line_num++;
					currentString = currentString + item;
                     cout << "stuck28?\n";
					t = Tokens("BLOCK_COMMENT", currentString, line_num);
					myTokens.push_back(t);
					currentString = "";
					cout << currentString;
					break;
				}
				else {

					while ( item != '\n') {

					    cout << "stuck30?\n";

						currentString = currentString + item;
						myfile.get(item);
						cout << "stuck31?\n";
					}
			
				    cout << "stuck32?\n";
					t = Tokens("COMMENT", currentString, line_num);
					myTokens.push_back(t);
					currentString == "";
					currentString.clear();
					cout << "stuck33?\n";
					cout << item;
					line_num++;
					break;
				}
				cout << "stuck40?\n";

          //  case '\'':
            //    currentString = currentString + item;
			//	myfile.get(item);
              //  while(item != '\''){
                //    currentString = currentString + item;
				//	myfile.get(item);
				//	if(item =='\'' && myfile.peek() == '\''){
				//	    myfile.get(item);
				//	    currentString = currentString + item;
				//	    myfile.get(item);
				//	}
                //}
                
                
                //break;

			case '\n':
			    cout << "55";
				line_num++;
				
				break;
			case ' ':
				break;
			case '\t':
				break;
			default :
					    currentString = currentString + item;
			            
			            t = Tokens("UNDEFINED", currentString, line_num);
						myTokens.push_back(t);
						currentString = "";
						cout << currentString;
				break;
			}
            cout << "stucksw?\n";
        }
       cout << item;

       cout << "stuckwhile?\n";
	}
       
        t = Tokens("EOF", "", line_num);
    	myTokens.push_back(t);

        cout << myTokens.size();
        for(int i = 0; i < myTokens.size(); i++){
        myTokens[i].toString();
        
        }

}




void Lexer::isColon(char item, char hold, int line_num){
    
    Tokens t;
    	if (isspace(hold)){
			t = Tokens("COLON", ":", line_num);
			myTokens.push_back(t);

		}
		else {

			if (hold == '-') {
				t = Tokens("COLON_DASH", ":-", line_num);
				myTokens.push_back(t);

			}
		}
}
