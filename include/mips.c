#include "mips.h"
#include "semantic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int stackoffset = -4;
int regturn = 0;
int mainFlag;

struct idRegNode *findIdReg(char *idName) {
	int k = hash(idName, MAX_ID_NUM);
	struct idRegNode * p = idRegMap[k];
	while(p != NULL) {
		if (strcmp(p->idName, idName) == 0) return p;
		p = p->next;
	}
	return NULL;
}

struct idRegNode *insertIdReg(char *idName, char *regName, int inReg, int offset) {
	int k = hash(idName, MAX_ID_NUM);
	struct idRegNode *p = idRegMap[k];
	while(p != NULL) {
		if (strcmp(p->idName, idName) == 0) return p;
		p = p->next;
	}
	if (p == NULL) {
		p = (struct idRegNode *)malloc(sizeof(struct idRegNode));
		strcpy(p->idName, idName);
		strcpy(p->regName, regName);
		p->inReg = inReg;
		p->offset = offset;
		p->next = idRegMap[k];
		idRegMap[k] = p;
		return idRegMap[k];
	}else {
		strcpy(p->idName, idName);
		strcpy(p->regName, regName);
		p->inReg = inReg;
		p->offset = offset;
		return p;
	}
}

void getRegName(int num, char *regName) {
	strcpy(regName, "$t0");
	if (num < 10) regName[2] = num + 48;
	else {
		regName[1] = 's';
		regName[2] = num - 10 + 48;
	}
}

void genlw(char *regName, int offset, FILE *f) {
	fprintf(f, "lw %s, %d($fp)\n", regName, offset);
}

void regSpill(char *regName, char *idName, FILE *f) {
	struct idRegNode *p = findIdReg(idName);
	fprintf(f, "sw %s, %d($fp)\n", regName, p->offset);
	p->inReg = 0;
}

void allocateReg(struct idRegNode *p, char *regName, FILE *f, int firstuse) {
	int i;
	for (i = 0; i < MAX_REG_NUM; i++) {
		if (strlen(regMap[i]) == 0) {
			strcpy(regMap[i], p->idName);
			getRegName(i, regName);
			strcpy(p->regName, regName);
			p->inReg = 1;
			if (!firstuse) genlw(regName, p->offset, f);
			return ;
		}
	}
	getRegName(regturn, regName);
	regSpill(regName, regMap[regturn], f);
	strcpy(p->regName, regName);
	p->inReg = 1;
	genlw(regName, p->offset, f);
	regturn++;
	if (regturn == MAX_REG_NUM) regturn = 0;
}

void getReg(char *idName, char *regName, FILE *f) {
	struct idRegNode *p = findIdReg(idName);
	if (p != NULL) {
		if (p->inReg)
			strcpy(regName, p->regName);
		else
			allocateReg(p, regName, f, 0);
		return ;
	}
	stackoffset -= 4;
	fprintf(f, "addi $sp, $sp, -4\n");
	p = insertIdReg(idName, "", 0, stackoffset);
	allocateReg(p, regName, f, 1);
}

int getOffset(char *idName, FILE *f) {
	struct idRegNode *p = findIdReg(idName);
	if (p == NULL) {
		stackoffset -= 4;
		fprintf(f, "addi $sp, $sp, -4\n");
		p = insertIdReg(idName, "", 0, stackoffset);
	}
	return p->offset;
}


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

void saveInStack(char *reg, FILE *f) {
	fprintf(f, "addi $sp, $sp, -4\n");
	fprintf(f, "sw %s, 0($sp)\n", reg);
}

void getFromStack(char *reg, FILE *f) {
	fprintf(f, "lw %s, 0($sp)\n", reg);
	fprintf(f, "addi $sp, $sp, 4\n");
}

int handlePara(struct InterCodes *p, FILE *f, int dep) {
	if (p->code.kind != PARAM) return -1;
	int cnt = handlePara(p->next, f, dep + 1) + 1;
	char reg1[MAX_LABEL_LEN];
	if (cnt < 4) {
		getReg(p->code.u.oneop.op1->u.s, reg1, f);
		fprintf(f, "move %s, $a%d\n", reg1, cnt);
	}else {
		insertIdReg(p->code.u.oneop.op1->u.s, "", 0, 4 + dep * 4);
	}
	return cnt;
}

void printInstruction(struct InterCodes *p, FILE *f) {
	if (p == NULL) return ;
	char reg1[MAX_LABEL_LEN], reg2[MAX_LABEL_LEN], reg3[MAX_LABEL_LEN];
	int cnt;
	switch(p->code.kind) {
		case LABEL:
			fprintf(f, "%s:\n", p->code.u.oneop.op1->u.s);
			break;
		case FUNCTION:
			fprintf(f, "%s:\n", p->code.u.oneop.op1->u.s);
			if (strcmp(p->code.u.oneop.op1->u.s, "main") == 0) mainFlag = 1;
			else mainFlag = 0;
			stackoffset = -4;
			break;
		case PARAM:
			handlePara(p, f, 0);
			while(p->code.kind == PARAM) p = p->next;
			printInstruction(p, f);
			return ;
		case ARG:
			cnt = 0;
			while(p->code.kind == ARG) {
				getReg(p->code.u.oneop.op1->u.s, reg1, f);
				if (cnt < 4) fprintf(f, "move $a%d, %s\n", cnt, reg1);
				else saveInStack(reg1, f);
				cnt++;
				p = p->next;
			}
			printInstruction(p, f);
			return ;
		case ASSIGN:
			getReg(p->code.u.assign.left->u.s, reg1, f);
			if (p->code.u.assign.left->kind == VARIABLE && 
				p->code.u.assign.right->kind == CONSTANT) {
				fprintf(f, "li %s, %d\n", reg1, p->code.u.assign.right->u.value);
			}
			if (p->code.u.assign.left->kind == VARIABLE &&
				p->code.u.assign.right->kind == VARIABLE){
				getReg(p->code.u.assign.right->u.s, reg2, f);
				fprintf(f, "move %s, %s\n", reg1, reg2);
			}
			if (p->code.u.assign.left->kind == MEM && 
				p->code.u.assign.right->kind == VARIABLE) {
				getReg(p->code.u.assign.right->u.s, reg2, f);
				fprintf(f, "sw %s, 0(%s)\n", reg2, reg1);
				}
			if (p->code.u.assign.left->kind == MEM && 
				p->code.u.assign.right->kind == CONSTANT) {
					getReg(p->code.u.assign.right->u.s, reg2, f);
					fprintf(f, "li $s7, %d\n", p->code.u.assign.right->u.value);
					fprintf(f, "sw $s7, 0(%s)\n", reg1);
				}
			if (p->code.u.assign.left->kind == VARIABLE && 
				p->code.u.assign.right->kind == MEM) {
				getReg(p->code.u.assign.right->u.s, reg2, f);
				fprintf(f, "lw %s, 0(%s)\n", reg1, reg2);
			}
			if (p->code.u.assign.left->kind == VARIABLE && 			//ADDRESS
				p->code.u.assign.right->kind == ADDRESS) {
				fprintf(f, "addi %s, $fp, -%d\n", reg1, getOffset(p->code.u.assign.right->u.s, f));
			}

			break;
		case ADD:
			getReg(p->code.u.binop.result->u.s, reg1, f);
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == VARIABLE) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "add %s, %s, %s\n", reg1, reg2, reg3);
				}
			if (p->code.u.binop.op1->kind == CONSTANT && 
				p->code.u.binop.op2->kind == VARIABLE) {
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "addi %s, %s, %d\n", reg1, reg3, p->code.u.binop.op1->u.value);
				}
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == CONSTANT) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					fprintf(f, "addi %s, %s, %d\n", reg1, reg2, p->code.u.binop.op2->u.value);
				}
			break;
		case SUB:
			getReg(p->code.u.binop.result->u.s, reg1, f);
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == VARIABLE) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "sub %s, %s, %s\n", reg1, reg2, reg3);
				}
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == CONSTANT) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					fprintf(f, "addi %s, %s, -%d\n", reg1, reg2, p->code.u.binop.op2->u.value);
				}
			if (p->code.u.binop.op1->kind == CONSTANT && 
				p->code.u.binop.op2->kind == VARIABLE) {
					fprintf(f, "li $s7, %d\n", p->code.u.binop.op1->u.value);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "sub %s, $s7, %s\n", reg1, reg3);
				}
			break;
		case MUL:
			getReg(p->code.u.binop.result->u.s, reg1, f);
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == VARIABLE) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "mul %s, %s, %s\n", reg1, reg2, reg3);
				}
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == CONSTANT) {
					fprintf(f, "li $s7, %d\n", p->code.u.binop.op2->u.value);
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					fprintf(f, "mul %s, %s, $s7\n", reg1, reg2);
				}
			if (p->code.u.binop.op1->kind == CONSTANT && 
				p->code.u.binop.op2->kind == VARIABLE) {
					fprintf(f, "li $s7, %d\n", p->code.u.binop.op1->u.value);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "mul %s, $s7, %s\n", reg1, reg3);
				}
			break;
		case DIV:
			getReg(p->code.u.binop.result->u.s, reg1, f);
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == VARIABLE) {
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "div %s, %s\n", reg2, reg3);
					fprintf(f, "mflo %s\n", reg1);
				}
			if (p->code.u.binop.op1->kind == VARIABLE && 
				p->code.u.binop.op2->kind == CONSTANT) {
					fprintf(f, "li $s7, %d\n", p->code.u.binop.op2->u.value);
					getReg(p->code.u.binop.op1->u.s, reg2, f);
					fprintf(f, "div %s, $s7\n", reg2);
					fprintf(f, "mflo %s\n", reg1);
				}
			if (p->code.u.binop.op1->kind == CONSTANT && 
				p->code.u.binop.op2->kind == VARIABLE) {
					fprintf(f, "li $s7, %d\n", p->code.u.binop.op1->u.value);
					getReg(p->code.u.binop.op2->u.s, reg3, f);
					fprintf(f, "div $s7, %s\n", reg3);
					fprintf(f, "mflo %s\n", reg1);
				}
			break;
		case IFGOTO:
			if (p->code.u.ifgoto.op1->kind == VARIABLE) {
				getReg(p->code.u.ifgoto.op1->u.s, reg1, f);
			} else {
				fprintf(f, "li $s7, %d\n", p->code.u.ifgoto.op1->u.value);
				strcpy(reg1, "$s7");
			}
			
			if (p->code.u.ifgoto.op2->kind == VARIABLE) 
				getReg(p->code.u.ifgoto.op2->u.s, reg2, f);
			else {
				fprintf(f, "li $s7, %d\n", p->code.u.ifgoto.op2->u.value);
				strcpy(reg2, "$s7");
			}

            if (strcmp(p->code.u.ifgoto.relop->u.s, "==") == 0) {
            	fprintf(f, "beq ");
            }else if (strcmp(p->code.u.ifgoto.relop->u.s, "!=") == 0) {
            	fprintf(f, "bne ");
            }else if (strcmp(p->code.u.ifgoto.relop->u.s, ">") == 0) {
            	fprintf(f, "bgt ");
            }else if (strcmp(p->code.u.ifgoto.relop->u.s, "<") == 0) {
            	fprintf(f, "blt ");
            }else if (strcmp(p->code.u.ifgoto.relop->u.s, ">=") == 0) {
            	fprintf(f, "bge ");
            }else if (strcmp(p->code.u.ifgoto.relop->u.s, "<=") == 0) {
            	fprintf(f, "ble ");
            }
            fprintf(f, "%s, %s, %s\n", reg1, reg2, p->code.u.ifgoto.op3->u.s);
			break;
		case GOTO:
			fprintf(f, "j %s\n", p->code.u.oneop.op1->u.s);
			break;
		case RETURN:
			if (!mainFlag)
				fprintf(f, "addi $sp, $fp, -4\n");
				
			if (p->code.u.oneop.op1->kind == VARIABLE) {
				getReg(p->code.u.oneop.op1->u.s, reg1, f);
				fprintf(f, "move $v0, %s\n", reg1);
			}else if (p->code.u.oneop.op1->kind == CONSTANT)
				fprintf(f, "li $v0, %d\n", p->code.u.oneop.op1->u.value);
			fprintf(f, "jr $ra\n");
			break;
		case CALL:
			saveInStack("$fp", f);
			fprintf(f, "move $fp, $sp\n");
			saveInStack("$ra", f);
			
			fprintf(f, "jal %s\n", p->code.u.call.op1->u.s);
			getFromStack("$ra", f);
			getFromStack("$fp", f);
			
			getReg(p->code.u.call.result->u.s, reg1, f);
			fprintf(f, "move %s, $v0\n", reg1);
			break;
		case DEC:
			fprintf(f, "addi $sp, $sp, -%d\n", p->code.u.dec.size->u.value);
			insertIdReg(p->code.u.dec.op1->u.s, "", 0, stackoffset - p->code.u.dec.size->u.value);
			break;
		case READ:
			saveInStack("$ra", f);
			fprintf(f, "jal read\n");
			getFromStack("$ra", f);
			getReg(p->code.u.oneop.op1->u.s, reg1, f);
			fprintf(f, "move %s, $v0\n", reg1);
			break;
		case WRITE:
			saveInStack("$ra", f);
			getReg(p->code.u.oneop.op1->u.s, reg1, f);
			fprintf(f, "move $a0, %s\n", reg1);
			fprintf(f, "jal write\n");
			getFromStack("$ra", f);
			break;
	}
	printInstruction(p->next, f);
}

void generateMIPS(struct InterCodes *p, FILE *f) {
	printData(f);
	printRead(f);
	printWrite(f);
	printInstruction(p, f);
}
