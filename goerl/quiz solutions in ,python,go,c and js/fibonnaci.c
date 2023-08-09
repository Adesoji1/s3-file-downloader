// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h> 

// typedef enum TypeTag {
//     ADD, 
//     SUB,
//     MUL,
//     DIV,
//     FIBO
// } TypeTag;

// typedef struct Node {
//     TypeTag type;
//     int val1;
//     int val2;
// } Node;

// Node* makeNode(TypeTag type, int val1, int val2) {
//     Node* node = (Node*)malloc(sizeof(Node));
//     node->type = type;
//     node->val1 = val1;
//     node->val2 = val2;
//     return node;
// }

// int fibonacci(int n) {
//     if (n < 1)
//         return 0;
//     int a = 0, b = 1, fib;
//     for(int i = 2; i <= n; i++) {
//         fib = a + b;
//         a = b;
//         b = fib;
//     }
//     return fib;
// }





// int calc(Node* node) {
//     switch(node->type) {
//         case ADD:
//             return node->val1 + node->val2;
//         case SUB:
//             return node->val1 - node->val2;
//         case MUL:
//             return node->val1 * node->val2;
//         case DIV:
//             if(node->val2 != 0) 
//                 return node->val1 / node->val2;
//             else {
//                 printf("Error: Division by zero is not allowed\n");
//                 return -1;
//             }
//         case FIBO:
//             if(node->val1 >= 0)
//                 return fibonacci(node->val1);
//             else 
//                 return fibonacci(abs(node->val1));
//         default:
//             printf("Error: Unknown operation\n");
//             return -1;
//     }
// }

// int main() {
//     Node *add = makeNode(ADD, 10, 6);
//     Node *mul = makeNode(MUL, 5, 4);
//     Node *sub = makeNode(SUB, calc(mul), calc(add));
//     Node *fibo = makeNode(FIBO, abs(calc(sub))-1, 0); // Changed here

//     printf("add: %d\n", calc(add));
//     printf("mul: %d\n", calc(mul));
//     printf("sub: %d\n", calc(sub));
//     printf("fibo: %d\n", calc(fibo));

//     free(add);
//     free(mul);
//     free(sub);
//     free(fibo);

//     return 0;
// }




#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum TypeTag {
    ADD, 
    SUB,
    MUL,
    DIV,
    FIBO
} TypeTag;

typedef struct Node {
    TypeTag type;
    int val1;
    int val2;
} Node;

Node* makeNode(TypeTag type, int val1, int val2) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->val1 = val1;
    node->val2 = val2;
    return node;
}

int fibonacci(int n) {
    if (n < 1)
        return 0;
    int a = 0, b = 1, fib;
    for(int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int calc(Node* node) {
    switch(node->type) {
        case ADD:
            return node->val1 + node->val2;
        case SUB:
            return node->val1 - node->val2;  // The subtraction is corrected here.
        case MUL:
            return node->val1 * node->val2;
        case DIV:
            if(node->val2 != 0) 
                return node->val1 / node->val2;
            else 
                printf("Error: Division by zero is not allowed\n");
                return -1;
        case FIBO:
            return fibonacci(node->val1);
        default:
            printf("Error: Unknown operation\n");
            return -1;
    }
}

int main() {
    Node *add = makeNode(ADD, 10, 6);
    Node *mul = makeNode(MUL, 5, 4);
    Node *sub = makeNode(SUB, calc(add), calc(mul));  // The subtraction is made here.
    Node *fibo = makeNode(FIBO, abs(calc(sub))-1, 0); // We subtract 1 from the absolute value of the sub result.

    printf("add: %d\n", calc(add));
    printf("mul: %d\n", calc(mul));
    printf("sub: %d\n", calc(sub));
    printf("fibo: %d\n", calc(fibo));

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}
