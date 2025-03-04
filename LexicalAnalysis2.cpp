#include <iostream>
#include <regex>
#include <vector>

using namespace std;

enum TypeOfToken { IDENTIFIER, INTEGER, FLOAT, NUMBER, INVALID };

TypeOfToken ClassifyLexicaly(const string& input){
	vector<pair<string, TypeOfToken>> patterns = {
		{R"([_A-Za-z][_A-Za-z0-9]*)", IDENTIFIER},  // Identifier (e.g., abc, var1)
        {R"([0-9]+)", INTEGER},                    // Integer (e.g., 123)
        {R"([0-9]*\.[0-9]+)", FLOAT},              // Float (e.g., 3.14)
        {R"([+-]?([0-9]+|[0-9]*\.[0-9]+))", NUMBER} // Number (e.g., -42, +3.14)
	};
	
	// Destructuring aka Structured Binding pattern, type from the vector patterns
	// string pattern = pair.first;
    // TokenType type = pair.second;
	for(const auto& [pattern, type] : patterns)	{
		if(regex_match(input, regex(pattern)))
		    return type;
	}
	return INVALID;
}

int main(){
	string input;
    cout << "Enter a string: ";
    cin >> input;
    
    switch(ClassifyLexicaly(input)){
    	case IDENTIFIER: 
    	{
    	   	cout << "Identifier (id)\n"; 
			break;
		}
        case INTEGER: cout << "Integer (int)\n"; break;
        case FLOAT: cout << "Float (float)\n"; break;
        case NUMBER: cout << "Number (num)\n"; break;
        default: cout << "Invalid Input\n"; break;
	}
}