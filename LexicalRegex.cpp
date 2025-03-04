#include <iostream>
#include <regex>

using namespace std;

enum TokenType { IDENTIFIER, INTEGER, FLOAT, NUMBER, INVALID };

TokenType classifyInput(const string& input) {
    // Regular Expressions
    string id_regex = R"([_A-Za-z][_A-Za-z0-9]*)";                // Identifier (id)
    string int_regex = R"([0-9]+)";                               // Integer (int)
    string float_regex = R"([0-9]*\.[0-9]+)";                     // Floating point (float)
    string num_regex = R"([+-]?([0-9]+|[0-9]*\.[0-9]+))";         // Number (Num)
    

    if (regex_match(input, regex(id_regex)))
        return IDENTIFIER;
    else if (regex_match(input, regex(int_regex)))
        return INTEGER;
    else if (regex_match(input, regex(float_regex)))
        return FLOAT;
    else if (regex_match(input, regex(num_regex)))
        return NUMBER;
    else
        return INVALID;
}

int main() {
    string input;
    cout << "Enter a string to classify: ";
    cin >> input;

    // Classify input
    TokenType type = classifyInput(input);

    // Use switch-case for output
    switch (type) {
        case IDENTIFIER:
            cout << "Classification: Identifier (id)\n";
            break;
        case INTEGER:
            cout << "Classification: Integer (int)\n";
            break;
        case FLOAT:
            cout << "Classification: Float (float)\n";
            break;
        case NUMBER:
            cout << "Classification: Number (Num)\n";
            break;
        default:
            cout << "Classification: Invalid\n";
            break;
    }

    return 0;
}