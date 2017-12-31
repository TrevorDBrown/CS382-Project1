/*
 *      Simple Lexical Analyzer
 *      By: Trevor D. Brown on March 5th, 2017, for CS 382 (Programming Languages).
 *      Professor: Dr. Qi Li
 *
 *      Summary: This application accepts strings of data via the 
 *      keyboard. Using the finite state machine for lexical analysis,
 *      the application will determine the type of tokens present in 
 *      the string. Addtionally, unrecognizable tokens are pulled from 
 *      the entry, as well as digits, parenthesis, and mathematical 
 *      operations.
 */

#include <stdio.h>      // Standard Input/Ouput Header
#include <iostream>     // Input/Output Stream
#include <string>       // String Class
#include <vector>       // Vector Class

using namespace std;    // Standard Namespace

int main ( ) {
    //////////////////////////////////////////
    
    // Program Variables
    
    // Generic pointer.
    int i;
    
    // Counters for program output
    int left_parenthesis_count = 0;
    int right_parenthesis_count = 0;
    int add_op_count = 0;
    int mul_op_count = 0;
    int id_count = 0;
    int digit_count = 0;
    int unidentified_token_count = 0;
    
    // Arrays for storing content:
    vector<string> enteredIDs;
    vector<string> enteredDigits;
    vector<string> unidentifiedTokens;
    
    // Input Array
    string input;
    
    //////////////////////////////////////////
    
    // The Output:
    
    // Basic introduction message.
    cout << "Simple Lexical Analyzer  \n";
	cout << "By Trevor D. Brown. \n";
	
    // Request and Accept input from user:
    cout << "Enter the text you wish to analyze:\n";
    getline(cin, input);
    
    //////////////////////////////////////////
    
    // Begin Checking for Lexemes:
    
    i = 0;                             // Reset the generic pointer.
    
    // Examine while the pounter is less than the size of input.
    while(i < input.size()){
        if (input[i] == '('){
            left_parenthesis_count++;   // If the character is a '(', increment the left parenthesis counter.
        }
        else if (input[i] == ')'){
            right_parenthesis_count++;  // If the character is a ')', increment the right parentehsis counter.
        }
        else if (input[i] == '+' || input[i] == '-'){
            add_op_count++;             // If the character is a '+' or '-', increment the add/subtract operations counter.
        }
        else if (input[i] == '*' || input[i] == '/'){
            mul_op_count++;             // If the character is a '*' or '/'. increment the multiply/divide operations counter.
        }
        else if (isalpha(input[i])){
            // If the character is an alpha.
            string currentID;                   // Create a temporary string variable.
            currentID.operator+=(input[i]);     // Add the current character to the temporary string.
            
            while ((isalpha(input[i+1]) || isdigit(input[i+1])) && (i < input.size())){
                // While the next character is an alpha or digit,
                i++;                                // Increment the generic pointer by 1.
                currentID.operator+=(input[i]);     // Add the current character to the temporary string.
            }

            enteredIDs.push_back(currentID);        // Add the temporary string to the IDs vector.
            id_count++;                             // Increment the ID counter by 1.
        }
        else if (isdigit(input[i])){
            // If the chacter is a digit.
            string currentDigit;                // Create a temporary string variable.
            currentDigit.operator+=(input[i]);  // Add the current character to the temporary string.
            
            while (isdigit(input[i+1]) && (i < input.size())){
                // Whilte the next character is a digit.
                i++;                                // Increment the generic pointer by 1.
                currentDigit.operator+=(input[i]);  // Add the current character to the temporary string.
            }
            
            enteredDigits.push_back(currentDigit);  // Add the temporary string to the Digits vector.
            digit_count++;                          // Increment the Digit counter by 1.
        }
        else{
            if (input[i] != ' '){// If the character is unidentified:
            string currentCharacter;                            // Create a temporary string variable.
            currentCharacter.operator+=(input[i]);              // Add the current character to the string variable.
            unidentifiedTokens.push_back(currentCharacter);     // Add the temporary string to the unidentified token vector.
            unidentified_token_count++;                         // Increment the Unidentified Token Counter by 1.
        }
        }
        
        i++;                                        // Increment the generic pointer by 1.
    }
    
    //////////////////////////////////////////
    
    // Display Output
    
    if (input != ""){
    // If input is not blank:
        
    cout << "\nID: ";                               // Display the label "ID:"
    i = 0;                                          // Reset the generic pointer.
    
    if (id_count > 0){
        // If the ID counter is greater than 0:
        
        for(i=0; i < id_count; i++){
            // While the generic pounter is less than the ID count.
            cout << enteredIDs.at(i);                // Display the current ID string.
            
            if (i < id_count - 1){
                // If the generic pointer is less than one less than the ID counter:
                cout << ", ";                       // Add a comma to the display, to separate values.
            }
        }
    } else {
        // If the ID counter is less than or equal to 0:
        cout << "None.";                            // Display the "None" label.
    }
    
    cout << "\nINT: ";                              // Display the label "INT:"
    i = 0;                                          // Reset the generic pointer.
    
    if (digit_count > 0){
        // If the digit count is greater than 0:
        for(i=0; i < digit_count;i++){
            cout << enteredDigits.at(i);            // Display the current Digit string.
            if (i < digit_count - 1){
                // If the generic pounter is less than one less than the Digit counter:
                cout << ", ";                       // Add a comma to the display, to separate values.
            }
        }
    } else {
        // If the Digit counter is less than or equal to 0:
        cout << "None.\n";                          // Display the "None" label.
    }
    
    cout << "\nThe number(s) of LEFT PARENTHESIS, RIGHT PARENTHESIS, ADD_OP, and MUL_OP: " << left_parenthesis_count << ", " << right_parenthesis_count << ", " << add_op_count << ", " << mul_op_count << "\n"; // Display the label for the left parenthesis count, right parenthesis count, add/subtract operations count, and multiply/divide operations count, and the respective counts.
    
    if (left_parenthesis_count != right_parenthesis_count){
        // If the parentehsis counts are not equal:
        cout << "\nError: Parenthesis Mismatch. ";  // Display the error message.
        
        if (left_parenthesis_count > right_parenthesis_count){
            // If the left parenthesis count is great than the right parenthesis count,
            // report the difference and that the left parenthesis count is greater.
            cout << left_parenthesis_count - right_parenthesis_count << " more left parenthesis than right parenthesis. \n";
        } else if (right_parenthesis_count > left_parenthesis_count){
            // If the right parenthesis count is great than the left parenthesis count,
            // report the difference and that the right parenthesis count is greater.
            cout << right_parenthesis_count - left_parenthesis_count << " more right parenthesis than left parenthesis.\n";
        }
    }else{
        cout << "\nNo parenthesis mismatch.\n";  // Display "No parenthesis mismatch" message.
    }
     
        if (unidentified_token_count > 0){
           cout << "\nError: Unidentified tokens entered: ";
            
                for(i=0; i < unidentified_token_count;i++){
                    cout << unidentifiedTokens.at(i);            // Display the current Unidentified Token string.
                    if (i < unidentified_token_count - 1){
                        // If the generic pounter is less than one less than the unidentified token counter:
                        cout << ", ";                       // Add a comma to the display, to separate values.
                    }
                }
            } else {
                // If the unidentified token counter is less than or equal to 0:
                cout << "\nNo unidentified tokens found.\n";
            }
            
        }
    else if (input == ""){
        // If there is no input, report the error.
        cout << "\nError: No input. Terminating.\n";
    }
    
    cout << "\nGod bless.\n\n";
	return 0; // Program termination code.
}
