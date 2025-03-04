#include <iostream>
#include <regex>

using namespace std;

enum TypeOfToken { IDENTIFIER, INTEGER, FLOAT, NUMBER, INVALID, LEXIME };

TypeOfToken classifyInput(const string& input) {
    // Regular Expressions
    string id_regex = R"([_A-Za-z][_A-Za-z0-9]*)";                // Identifier (e.g., abc, var1)
    string int_regex = R"([0-9]+)";                               // Integer (e.g., 123)
    string float_regex = R"([0-9]*\.[0-9]+)";                     // Float (e.g., 3.14)
    string num_regex = R"([+-]?([0-9]+|[0-9]*\.[0-9]+))";         // Number (e.g., -42, +3.14)
    string lex_regex = R"([_A-Za-z][_A-Za-z0-9]*)|([+-]?([0-9]+|[0-9]*\.[0-9]+))";    // lexime num or Id

    if (regex_match(input, regex(id_regex)))
        return IDENTIFIER;
    else if (regex_match(input, regex(int_regex)))
        return INTEGER;
    else if (regex_match(input, regex(float_regex)))
        return FLOAT;
    else if (regex_match(input, regex(num_regex)))
        return NUMBER;  
    else if (regex_match(input, regex(lex_regex)))
        return LEXIME;  
    else
        return INVALID;
}

int main() {
    string input;
    cout << "Enter a string to classify: ";
    cin >> input;

    // Classify input
    TypeOfToken type = classifyInput(input);

    // Use switch-case for output
    switch (type) {
        case IDENTIFIER: cout << "Classification: Identifier ---> id\n"; break;
		case INTEGER: cout << "Integer ---> int\n"; break;
		case FLOAT: cout << "Float ---> float\n"; break;
		case NUMBER: cout << "Number ---> num\n"; break;
		case LEXIME: cout << "Number ---> num\n"; break;
		default: cout << "Invalid Input\n"; break;
    }

    return 0;
}