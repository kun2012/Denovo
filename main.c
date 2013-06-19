#include <stdio.h>
#include "include/tree.h"
#include "include/type.h"
#include "include/semantic.h"
#include "include/ir.h"
#include "include/mips.h"

int main(int argc, char** argv) {
    if (argc <= 2) return 1;
    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
    	perror(argv[1]);
    	return 1;
    }
    
    FILE *fout = fopen(argv[2], "w");
    if (!fout) {
    	perror(argv[2]);
    	return 1;
    }
    
    yyrestart(fin);
    yyparse();
    if (syntaxError) return 0;
   // printTree(root);
    checkSemantic(root);
    if (semanticError) return 0;
    generateIR(root);
	generateMIPS(icsHead, fout);
	fclose(fout);
    return 0;
}
