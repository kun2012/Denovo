#include <stdio.h>
#include "include/tree.h"
#include "include/type.h"
#include "include/semantic.h"
#include "include/ir.h"

int main(int argc, char** argv) {
    if (argc <= 1) return 1;
    FILE *f = fopen(argv[1], "r");
    if (!f) {
    	perror(argv[1]);
    	return 1;
    }
    yyrestart(f);
    yyparse();
    if (syntaxError) return 0;
   // printTree(root);
    checkSemantic(root);
    if (semanticError) return 0;
    generateIR(root);
    
    return 0;
}
