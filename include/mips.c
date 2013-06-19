#include "mips.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printData(FILE *f) {
	fprintf(f, ".data\n_prompt: .asciiz \"Enter an integer:\"\n");
	fprintf(f, "_ret: .asciiz \"\\n\"\n.globl main\n");
	fprintf(f, ".text\n");
}

void printRead(FILE *f) {
	fprintf(f, "read:\nli $v0, 4\nla $a0, _prompt\n");
	fprintf(f, "syscall\nli $v0, 5\nsyscall\njr $ra\n\n");
}

void printWrite(FILE *f) {
	fprintf(f, "write:\nli $v0, 1\nsyscall\nli $v0, 4\n");
	fprintf(f, "la $a0, _ret\nsyscall\nmove $v0, $0\njr $ra\n\n");
}

void printInstruction(struct InterCodes *p, FILE *f) {
	int argnum, paranum;
	char s1[MAX_LABEL_LEN], s2[MAX_LABEL_LEN];
	switch(p->code.kind) {
		case LABEL:
			fprintf(f, "%s:\n", p->code.u.oneop.op1->u.s);
			break;
		case FUNCTION:
			fprintf(f, "%s:\n", p->code.u.oneop.op1->u.s);
			argnum = 0;
			break;
		case PARAM:
			break;
		case ARG:
			break;
		case ASSIGN:
			if (p->code.u.assign.right->kind == CONSTANT)
				fprintf(f, "li $t0, %d\n", k);
			else {
				getReg(p->code.u.assign.right->u.s, s2);
				fprintf(f, "move %s, %s\n", s1, s2);
			}
			break;
		case ADD:
			
			break;
		case SUB:
			break;
		case MUL:
			break;
		case DIV:
			break;
		case IFGOTO:
			break;
		case GOTO:
			break;
		case RETURN:
			break;
		case CALL:
			break;
		case DEC:
			break;
		case READ:
			break;
		case WRITE:
			break;
	}
}

void generateMIPS(struct InterCodes *p, FILE *f) {
	printData(f);
	printRead(f);
	printWrite(f);
	while(p != NULL) {
		printInstruction(p, f);
		p = p->next;
	}
}
