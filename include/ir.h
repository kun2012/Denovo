#ifndef __IR_H__
#define __IR_H__

#include "type.h"

struct Operand_ {
    enum {VARIABLE, CONSTANT, ADDRESS, MEM} kind;
    union {
        char s[MAX_LABEL_LEN];
        int value;
    }u;
};

typedef struct Operand_* Operand;

struct InterCode {
    enum {ASSIGN, ADD, SUB, MUL, DIV, LABEL, FUNCTION, GOTO, IFGOTO,
        RETURN, DEC, ARG, CALL, PARAM, READ, WRITE} kind;
    union {
        struct {
            Operand right, left;
        }assign;
       
        struct {
            Operand op1;
        }oneop;
       
        struct {
            Operand op1, relop, op2, op3;
        }ifgoto;
       
        struct {
            Operand op1, size;
        }dec;
       
        struct {
            Operand result, op1;
        }call;
       
        struct {
            Operand result, op1, op2;
        }binop;
    }u;
};

struct InterCodes {
    struct InterCode code;
    struct InterCodes *prev, *next;
};

struct InterCodes *icsHead;

struct arr{
    int size;
    struct arr *next;
};

struct arrayId {
    char idName[MAX_LABEL_LEN];
    char typeName[MAX_LABEL_LEN];
    struct arr *arrHead;
    struct arrayId *next;
};

struct arrayId *arrayIdHead;

struct tempNode {
    char tempName[MAX_LABEL_LEN];
    int num;
    char idName[MAX_LABEL_LEN];
    struct tempNode *next;
};

struct tempNode *tempMap[MAX_TEMP_NUM];

extern void getIC(struct treeNode *p);
extern void generateIR(struct treeNode *root);
extern void printIR(struct InterCodes *p);
extern void optimizationIR(struct InterCodes *p);

#endif
