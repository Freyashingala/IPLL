/* nanoC Lexer Test File
   Tests all lexical rules, multiline comment counting,
   and unrecognized tokens.*/

// 1. Keywords (Testing all 21 keywords)
int short long unsigned signed char float double _Bool void
if else for while do continue break return case default static

// 2. Identifiers
int _validId1;
float camelCaseIdentifier;
double MAX_VALUE;

// 3. Constants
// Integer constants (Including zero and non-zero start)
int zero_val = 0;
int non_zero_val = 123;

// Floating constants (Testing all fractional formats)
double pi = 3.14159;
float fraction_only = .5;
float whole_only = 10.;

// Character constants (Testing standard chars and escapes)
char normal_char = 'A';
char escape_newline = '\n';
char escape_quote = '\'';
char escape_slash = '\\';
char escape_tab = '\t';

// 4. String Literals
// Testing standard strings and internal escape sequences
char* basic_str = "Hello, World!";
char* complex_str = "String with \"quotes\" and \n newline.";

// 5. Punctuators
// Brackets and member access
[ ] ( ) { } . ->
// Arithmetic and increment/decrement
+ - * / % ++ --
// Bitwise and shift operators
~ & | ^ << >>
// Relational and logical operators
< > <= >= == != && || !
// Assignment and compound assignment
= += -= *= /= %= <<= >>= &= ^= |=
// Miscellaneous
? : ; ... , #

// 6. Error Handling
// The following characters are not part of nanoC and should trigger
// the catch-all error rule with correct line numbers.
@
$
`

/* End of test file. */