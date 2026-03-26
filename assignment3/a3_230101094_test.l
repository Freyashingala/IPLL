/* Testing multi-line comments
   nanoC Lexer Test
*/

int main() {
    int count = 10;
    float pi = 3.14159;
    char newline = '\n';
    char* greeting = "Hello, world!";
    
    // Testing single line comment and punctuators
    if (count >= 5 && pi != 0.0) {
        count++;
    } else {
        count -= 2;
    }
    
    @ // This is an intentional error to test line reporting
    
    return 0;
}