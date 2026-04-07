// nanoC Parser Test File: Tests all phase structure grammar rules from Assignment 4

// 1. DECLARATIONS & TYPE SPECIFIERS 
static int global_var = 10;
unsigned long uli = 100;
_Bool flag = 1;
float f_val = 3.14;
double d_val = 2.71828;
char c = 'A';
signed short ss = 5;
void empty_func(void) {}

// 2. EXPRESSIONS & FUNCTION PARAMETERS 
int expression_tester(int a, int b) {
    // Local Declarations 
    int x;
    int y = 5;
    int arr[10];
    
    // Initializer Lists & Designators 
    int designator_arr[5] = { [0] = 1, [4] = 25 }; 
    
    // Primary Expressions 
    "This is a string literal testing primary-expression";
    
    // Postfix Expressions 
    arr[0] = a;
    arr[1] = b++;
    arr[2] = b--;
    empty_func();
    
    // Unary Expressions 
    ++a;
    --b;
    x = &a;    // Address-of operator 
    y = *arr;  // Dereference operator 
    y = +a;
    y = -b;
    y = ~a;
    y = !flag;
    
    // Multiplicative & Additive Expressions 
    x = (a * b) + (a / 2) - (b % 3);
    
    // Shift Expressions 
    x = a << 2;
    y = b >> 1;
    
    // Relational & Equality Expressions 
    flag = (x < y) == (x > y) != (x <= y) >= (x >= y);
    
    // Bitwise & Logical Expressions 
    x = (a & b) ^ (a | b);
    flag = (a && b) || !flag;
    
    // Conditional Expression 
    y = (a > b) ? a : b;
    
    // Assignment Expressions 
    x = 10;
    x *= 2;
    x /= 2;
    x %= 3;
    x += 5;
    x -= 1;
    x <<= 1;
    x >>= 1;
    x &= a;
    x ^= b;
    x |= 1;
    
    return x;
}

// 3. STATEMENTS & CONTROL FLOW 
void statement_tester() {
    int i = 0;
    
    // Selection Statements 
    if (i == 0) {
        i++;
    } else {
        i--;
    }
    
    // Iteration Statements 
    while (i < 10) {
        i++;
        if (i == 5) continue;
        if (i == 8) break;
    }
    
    do {
        i--;
    } while (i > 0);
    
    // For loop with declaration (C99 style) 
    for (int j = 0; j < 5; j++) {
        i += j;
    }
    
    // For loop with empty optional expressions 
    for ( ; ; ) {
        break;
    }
    
    // Labeled Statements 
       (nanoC includes case/default but not switch) 
    my_label: 
        i = 100;
        
    case 1: 
        i = 200;
        
    default:
        i = 300;
}

// 4. TRANSLATION UNIT (MAIN) 
int main() {
    // Tests argument-expression-list 
    expression_tester(global_var, 5); 
    statement_tester();
    
    return 0;
}