#include "ir.h"
#include "semantic.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct InterCodes *ics;

Operand getOperandVariable(char *s) {
    Operand p = (Operand)malloc(sizeof(struct Operand_));
    p->kind = VARIABLE;
    strcpy(p->u.s, s);
    return p;
}

Operand getOperandConstant(int x) {
    Operand p = (Operand)malloc(sizeof(struct Operand_));
    p->kind = CONSTANT;
    p->u.value = x;
    return p;
}

Operand getOperandAddress(char *s) {
    Operand p = (Operand)malloc(sizeof(struct Operand_));
    p->kind = ADDRESS;
    strcpy(p->u.s, s);
    return p;
}

Operand getOperandMem(char *s) {
    Operand p = (Operand)malloc(sizeof(struct Operand_));
    p->kind = MEM;
    strcpy(p->u.s, s);
    return p;
}

void addtoIR(struct InterCodes *p) {
    ics->next = p;
    p->prev = ics;
    ics = p;
}


void addOneOp(struct InterCodes *p, char *varname) {
    p->code.u.oneop.op1 = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.oneop.op1->kind = VARIABLE;
    strcpy(p->code.u.oneop.op1->u.s, varname);
}

void addFunLabel(char *funName) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = FUNCTION;
    addOneOp(p, funName);
    if (ics == NULL) {
        ics = p;
        icsHead = ics;
    }else {
        ics->next = p;
        p->prev = ics;
        ics = p;
    }
   
}

void addCall(char *place, char *funName) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = CALL;
    p->code.u.call.op1 = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.call.result = (Operand)malloc(sizeof(struct Operand_));
    strcpy(p->code.u.call.op1->u.s, funName);
    strcpy(p->code.u.call.result->u.s, place);
   
    ics->next = p;
    p->prev = ics;
    ics = p;
}

void addArg(char *place) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = ARG;
    p->code.u.oneop.op1 = (Operand)malloc(sizeof(struct Operand_));
    strcpy(p->code.u.oneop.op1->u.s, place);
   
    ics->next = p;
    p->prev = ics;
    ics = p;
}


void addLabel(char *label) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = LABEL;
    addOneOp(p, label);

    ics->next = p;
    p->prev = ics;
    ics = p;
}

void addReturn(char *s) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = RETURN;
    addOneOp(p, s);

    ics->next = p;
    p->prev = ics;
    ics = p;
}

void addAssignConstant(char *place, int x) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = ASSIGN;
    p->code.u.assign.left = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.assign.right = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.assign.left->kind = VARIABLE;
    strcpy(p->code.u.assign.left->u.s, place);
    p->code.u.assign.right->kind = CONSTANT;
    p->code.u.assign.right->u.value = x;
   
    ics->next = p;
    p->prev = ics;
    ics = p;
}

void addAssignVariable(char *le, char *ri) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = ASSIGN;
    p->code.u.assign.left = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.assign.right = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.assign.left->kind = VARIABLE;
    strcpy(p->code.u.assign.left->u.s, le);
    p->code.u.assign.right->kind = VARIABLE;
    strcpy(p->code.u.assign.right->u.s, ri);
   
    ics->next = p;
    p->prev = ics;
    ics = p;
}

void addAssignAddress(char *le, char *ri) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = ASSIGN;
    p->code.u.assign.left = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.assign.right = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.assign.left->kind = VARIABLE;
    strcpy(p->code.u.assign.left->u.s, le);
    p->code.u.assign.right->kind = ADDRESS;
    strcpy(p->code.u.assign.right->u.s, ri);
   
    ics->next = p;
    p->prev = ics;
    ics = p;
}

void addAssignMem(char *le, char *ri) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = ASSIGN;
    p->code.u.assign.left = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.assign.right = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.assign.left->kind = VARIABLE;
    strcpy(p->code.u.assign.left->u.s, le);
    p->code.u.assign.right->kind = MEM;
    strcpy(p->code.u.assign.right->u.s, ri);
   
    ics->next = p;
    p->prev = ics;
    ics = p;
}

void addAssignMemleft(char *le, char *ri) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = ASSIGN;
    p->code.u.assign.left = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.assign.right = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.assign.left->kind = MEM;
    strcpy(p->code.u.assign.left->u.s, le);
    p->code.u.assign.right->kind = VARIABLE;
    strcpy(p->code.u.assign.right->u.s, ri);
   
    ics->next = p;
    p->prev = ics;
    ics = p;
}

void addPara(char *s) {
    struct InterCodes * p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = PARAM;
   
    addOneOp(p, s);

    ics->next = p;
    p->prev = ics;
    ics = p;
   
}

void addDec(char *s, int k) {
    struct InterCodes * p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = DEC;
    p->code.u.dec.op1 = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.dec.size = (Operand)malloc(sizeof(struct Operand_));
    strcpy(p->code.u.dec.op1->u.s, s);
    p->code.u.dec.size->u.value = k;
   
    ics->next = p;
    p->prev = ics;
    ics = p;
}

void addRead(char *s) {
    struct InterCodes * p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = READ;
    p->code.u.oneop.op1 = (Operand)malloc(sizeof(struct Operand_));
    strcpy(p->code.u.oneop.op1->u.s, s);
   
    addtoIR(p);
}

void addWrite(char *s) {
    struct InterCodes * p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = WRITE;
    p->code.u.oneop.op1 = (Operand)malloc(sizeof(struct Operand_));
    strcpy(p->code.u.oneop.op1->u.s, s);
   
    addtoIR(p);
}

void addBinop(Operand p1, Operand p2, Operand p3, int opt) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    switch(opt) {
        case T_PLUS:
            p->code.kind = ADD;
            break;
        case T_MINUS:
            p->code.kind = SUB;
            break;
        case T_MULT:
            p->code.kind = MUL;
            break;
        case T_DIV:
            p->code.kind = DIV;
            break;
    }
    p->code.u.binop.result = p1;
    p->code.u.binop.op1 = p2;
    p->code.u.binop.op2 = p3;
    addtoIR(p);
}

void addIfgoto(Operand o1, int relop, Operand o2, Operand o3) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = IFGOTO;
    p->code.u.ifgoto.op1 = o1;

    p->code.u.ifgoto.relop = (Operand)malloc(sizeof(struct Operand_));
    p->code.u.ifgoto.relop->kind = VARIABLE;
    switch(relop) {
        case T_NE:
            strcpy(p->code.u.ifgoto.relop->u.s, "!=");
            break;
        case T_EQ:
            strcpy(p->code.u.ifgoto.relop->u.s, "==");
            break;
        case T_GE:
            strcpy(p->code.u.ifgoto.relop->u.s, ">=");
            break;
        case T_LE:
            strcpy(p->code.u.ifgoto.relop->u.s, "<=");
            break;
        case T_GT:
            strcpy(p->code.u.ifgoto.relop->u.s, ">");
            break;
        case T_LT:
            strcpy(p->code.u.ifgoto.relop->u.s, "<");
            break;
    }

    p->code.u.ifgoto.op2 = o2;

    p->code.u.ifgoto.op3 = o3;

    addtoIR(p);
}


void addGoto(char *label) {
    struct InterCodes *p = (struct InterCodes *)malloc(sizeof(struct InterCodes));
    p->code.kind = GOTO;
    p->code.u.oneop.op1 = getOperandVariable(label);

    addtoIR(p);
}

int lcNum = 0;
int tnum = 0;
int labelNum = 0;

void setIdName(char *s1, char *s2, char *s3, char *s) {
    memset(s, 0, sizeof(s));
    struct attriNode *p = findAttribute(cls->attriHead, s3);
    strcat(s, s1);
    if (p == NULL) strcat(s, s2);
    strcat(s, s3);
}

void getTemp(char *t, int x) {
    memset(t, 0, sizeof(t));
    numToString(x, t + 1);
    t[0] = 't';
}

void getLabel(char *t, int x) {
    memset(t, 0, sizeof(t));
    numToString(x, t + 5);
    strncpy(t, "label", 5);
}



void visitChild(struct treeNode *p) {
    int i;
    for (i = 0; i < p->childNum; i++)
        getIC(p->ch[i]);
}

void insertArrayId(char *s, char *t, int x) {
    struct arrayId *p = arrayIdHead;
    while(p != NULL) {
        if (strcmp(p->idName, s) == 0) break;
        p = p->next;
    }
    struct arr *q = (struct arr *)malloc(sizeof(struct arr));
    q->size = x;
   
    if (p == NULL) {
        p = (struct arrayId *)malloc(sizeof(struct arrayId));
        strcpy(p->idName, s);
        strcpy(p->typeName, t);
       
        q->next = p->arrHead;
        p->arrHead = q;
       
        p->next = arrayIdHead;
        arrayIdHead = p;
    }else {
        q->next = p->arrHead;
        p->arrHead = q;
    }   
}

struct arrayId *findArrayId(char *s) {
    struct arrayId *p = arrayIdHead;
    while(p != NULL) {
        if (strcmp(p->idName, s) == 0) return p;
        p = p->next;
    }
    return NULL;
}

int getNewArraySize(char *s, char *t, struct treeNode *p) {
   
    if (p == NULL) return 1;
    if (p->childNum == 4) { //arrayExprDec LB INT RB
        int k = getNewArraySize(s, t, p->ch[0]);
        insertArrayId(s, t, p->ch[2]->digit);
        return k * p->ch[2]->digit;
    }else { //LB INT RB
        insertArrayId(s, t, p->ch[1]->digit);
        return p->ch[1]->digit;
    }
}

int getTypeSize(char *s) {
    struct typeNode *tcls = findType(s);
    if (strcmp(tcls->d, "Int") == 0) return 4;
    if (strcmp(tcls->d, "String") == 0) return 1;
    return tcls->attriHead->offset + 4;
}

void handleArrayExpr(struct treeNode *p, struct arr *q) {
    if (p == NULL) return ;
    if (p->childNum == 4) { //arrayExpr LB expr RB
        char t1[MAX_LABEL_LEN], t2[MAX_LABEL_LEN], t3[MAX_LABEL_LEN], t4[MAX_LABEL_LEN];
        int k = q->size;
        getTemp(t1, ++tnum);
        getTemp(t2, ++tnum);
        getTemp(t3, ++tnum);
       
        strcpy(p->ch[0]->place, t1);
        handleArrayExpr(p->ch[0], q->next);
       
       
        strcpy(p->ch[2]->place, t2);
        getIC(p->ch[2]);
       
        addBinop(getOperandVariable(t3), getOperandVariable(t1), getOperandConstant(k), T_MULT);
        addBinop(getOperandVariable(p->place), getOperandVariable(t2), getOperandVariable(t3), T_PLUS);
       
    }else { //LB expr RB
        strcpy(p->ch[1]->place, p->place);
        getIC(p->ch[1]);
    }
}

void getIC(struct treeNode *p) {
    if (p == NULL) return ;
    int ptype = p->nodeType;

    switch(ptype) {
        case T_class:
            cls = findType(p->ch[1]->strconst);
            ft = cls->funhead;
            visitChild(p);
            break;
        case T_funDec:
            addFunLabel(p->label);
            if (strcmp(ft->funName, "main") != 0) {
                char s[MAX_LABEL_LEN];
                setIdName(cls->d, ft->funName, "this", s);
                addPara(s);
            }
            intoFunc = 1;
            visitChild(p);
            break;
        case T_INT:
            if (strlen(p->place) != 0)
                addAssignConstant(p->place, p->digit);
            break;
        case T_ID:
            if (strlen(p->place) != 0) {
                char *s = (char *)malloc(MAX_LABEL_LEN);
                setIdName(cls->d, ft->funName, p->strconst, s);
                addAssignVariable(p->place, s);
            }
            break;
           
        case T_varDec:
           
            if (!intoFunc) {visitChild(p); break; }
            if (p->childNum == 5) {  //varDec COMMA ID ASSIGN expr
                setIdName(cls->d, ft->funName, p->ch[2]->strconst, p->ch[4]->place);
            }else if (p->childNum == 4) {  //type ID ASSIGN expr
                setIdName(cls->d, ft->funName, p->ch[1]->strconst, p->ch[3]->place);
            }
            visitChild(p);
            break;
        case T_expr:
           
            if (p->ch[0]->nodeType == T_INT) { //INT
                strcpy(p->ch[0]->place, p->place);
                visitChild(p);
            }
            if (p->childNum == 1 && p->ch[0]->nodeType == T_ID) { //ID
                strcpy(p->ch[0]->place, p->place);
                visitChild(p);
            }
            if (p->ch[0]->nodeType == T_expr) { //MINUS | PLUS | MULT | DIV
                Operand op1, op2;
                if (p->ch[0]->ch[0]->nodeType == T_INT) {
                    op1 = getOperandConstant(p->ch[0]->ch[0]->digit);
                //}else if (p->ch[0]->ch[0]->nodeType == T_ID) {
                //    op1 = getOperandVariable(p->ch[0]->ch[0]->strconst);
                }else {
                    getTemp(p->ch[0]->place, ++tnum);
                    getIC(p->ch[0]);
                    op1 = getOperandVariable(p->ch[0]->place);
                }
               
                if (p->ch[2]->ch[0]->nodeType == T_INT) {
                    op2 = getOperandConstant(p->ch[2]->ch[0]->digit);
                //}else if (p->ch[2]->ch[0]->nodeType == T_ID) {
                    //op2 = getOperandVariable(p->ch[2]->ch[0]->strconst);
                }else {
                    getTemp(p->ch[2]->place, ++tnum);
                    getIC(p->ch[2]);
                    op2 = getOperandVariable(p->ch[2]->place);
                }
                addBinop(getOperandVariable(p->place), op1, op2, p->ch[1]->nodeType);
            }
            if (p->ch[0]->nodeType == T_LP) { //LP expr RP
           
                strcpy(p->ch[1]->place, p->place);
                visitChild(p);
            }
            if (p->ch[0]->nodeType == T_MINUS) { //MINUS expr
                Operand op1;
                if (p->ch[1]->ch[0]->nodeType == T_INT) {
                    op1 = getOperandConstant(p->ch[1]->ch[0]->digit);
                //}else if (p->ch[1]->ch[0]->nodeType == T_ID) {
                    //op1 = getOperandVariable(p->ch[1]->ch[0]->strconst);
                }else {
                    getTemp(p->ch[1]->place, ++tnum);
                    getIC(p->ch[1]);
                    op1 = getOperandVariable(p->ch[1]->place);
                }
                addBinop(getOperandVariable(p->place), getOperandConstant(0), op1, T_MINUS);
            }
           
            if (p->childNum == 3 && p->ch[1]->nodeType == T_ASSIGN) { //ID ASSIGN expr
               
                char s[MAX_LABEL_LEN];
                setIdName(cls->d, ft->funName, p->ch[0]->strconst, s);
                strcpy(p->ch[2]->place, s);
                visitChild(p);
            }
           
           
            if (p->childNum == 4 && p->ch[1]->nodeType == T_arrayExpr) { //ID arrayExpr ASSIGN expr
           
                char t[MAX_LABEL_LEN], t1[MAX_LABEL_LEN], t2[MAX_LABEL_LEN], t3[MAX_LABEL_LEN], s[MAX_LABEL_LEN];
                setIdName(cls->d, ft->funName, p->ch[0]->strconst, s);
                struct arrayId *ai = findArrayId(s);
                struct arr *q = ai->arrHead;
               
                getTemp(t, ++tnum);
                getTemp(t1, ++tnum);
                getTemp(t2, ++tnum);
                getTemp(t3, ++tnum);
               
                strcpy(p->ch[1]->place, t);
                handleArrayExpr(p->ch[1], q);
               
                addBinop(getOperandVariable(t1), getOperandVariable(t), getOperandConstant(getTypeSize(ai->typeName)), T_MULT);
               
                addBinop(getOperandVariable(t2), getOperandVariable(t1), getOperandAddress(s), T_PLUS);
               
                strcpy(p->ch[3]->place, t3);
                getIC(p->ch[3]);
               
                addAssignMemleft(t2, t3);
           
            }
            if (p->childNum == 2 && p->ch[1]->nodeType == T_arrayExpr) {//ID arrayExpr
                char t[MAX_LABEL_LEN], t1[MAX_LABEL_LEN], t2[MAX_LABEL_LEN], s[MAX_LABEL_LEN];
                setIdName(cls->d, ft->funName, p->ch[0]->strconst, s);
                struct arrayId *ai = findArrayId(s);
                struct arr *q = ai->arrHead;
               
                getTemp(t, ++tnum);
                getTemp(t1, ++tnum);
                getTemp(t2, ++tnum);
                strcpy(p->ch[1]->place, t);
               
                handleArrayExpr(p->ch[1], q);
               
                addBinop(getOperandVariable(t1), getOperandVariable(t), getOperandConstant(getTypeSize(ai->typeName)), T_MULT);
               
                addBinop(getOperandVariable(t2), getOperandVariable(t1), getOperandAddress(s), T_PLUS);
                addAssignMem(p->place, t2);
            }
           
           
            if (p->childNum == 5 && p->ch[3]->nodeType == T_ASSIGN) {//ID DOT ID ASSIGN expr
                char t[MAX_LABEL_LEN], t1[MAX_LABEL_LEN];
                getTemp(t, ++tnum);
                getTemp(t1, ++tnum);
               
                strcpy(p->ch[4]->place, t);
                getIC(p->ch[4]);
               
                struct typeNode *tcls = findType(p->ch[0]->label);
                struct attriNode *q = findAttribute(tcls->attriHead, p->ch[2]->strconst);
                char s[MAX_LABEL_LEN];
                setIdName(cls->d, ft->funName, p->ch[0]->strconst, s);
               
                addBinop(getOperandVariable(t1), getOperandAddress(s), getOperandConstant(q->offset), T_PLUS);
                addAssignMemleft(t1, t);
            }
           
            if (p->childNum == 3 && p->ch[1]->nodeType == T_DOT) {//ID DOT ID
                struct typeNode *tcls = findType(p->ch[0]->label);
                struct attriNode *q = findAttribute(tcls->attriHead, p->ch[2]->strconst);
                char s[MAX_LABEL_LEN];
                setIdName(cls->d,  ft->funName, p->ch[0]->strconst, s);
               
                char t[MAX_LABEL_LEN];
                getTemp(t, ++tnum);
                addBinop(getOperandVariable(t), getOperandAddress(s), getOperandConstant(q->offset), T_PLUS);
                addAssignMem(p->place, t);
            }
           
            if (p->childNum == 3 && p->ch[0]->nodeType == T_NEW) { //NEW TYPE arrayExprDec
                int x = getNewArraySize(p->place, p->ch[1]->strconst, p->ch[2]);
                addDec(p->place, getTypeSize(p->ch[1]->strconst) * x);
            }
           
            if (p->childNum == 2 && p->ch[0]->nodeType == T_NEW) { //NEW TYPE
                addDec(p->place, getTypeSize(p->ch[1]->strconst));
            }
           
            if (p->childNum ==6  && p->ch[0]->nodeType == T_ID) { //ID DOT ID LP args RP
                visitChild(p);
                char s[MAX_LABEL_LEN];
                setIdName(cls->d, ft->funName, p->ch[0]->strconst, s);
                addArg(s);
                addCall(p->place,p->label);
            }
           
            if (p->childNum ==4  && p->ch[1]->nodeType == T_LP) { //ID LP args RP
                if (strcmp("read", p->ch[0]->strconst) == 0) {
                    addRead(p->place);
                }else if (strcmp("write", p->ch[0]->strconst) == 0) {
                    getTemp(p->ch[2]->ch[0]->place, ++tnum);
                    getIC(p->ch[2]->ch[0]);
                    addWrite(p->ch[2]->ch[0]->place);
                }else {
                    getIC(p->ch[2]);
                    char s[MAX_LABEL_LEN];
                    setIdName(cls->d, ft->funName, "this", s);
                    addArg(s);
                    addCall(p->place,p->label);
                }
            }
            break;
       
        case T_args:
            if (p != NULL && p->childNum > 0){// expr
                getTemp(p->ch[0]->place, ++tnum);
            }
            visitChild(p);
            addArg(p->ch[0]->place);
            break;

        case T_logexpr:
            if (p->ch[0]->nodeType == T_expr) { // expr NE EQ GE LE GT LT expr
                    Operand op1, op2, op3;
                if (p->ch[0]->ch[0]->nodeType == T_INT) {
                    op1 = getOperandConstant(p->ch[0]->ch[0]->digit);
                }else {
                    getTemp(p->ch[0]->place, ++tnum);
                    getIC(p->ch[0]);
                    op1 = getOperandVariable(p->ch[0]->place);
                }
               
                if (p->ch[2]->ch[0]->nodeType == T_INT) {
                    op2 = getOperandConstant(p->ch[2]->ch[0]->digit);
                }else {
                    getTemp(p->ch[2]->place, ++tnum);
                    getIC(p->ch[2]);
                    op2 = getOperandVariable(p->ch[2]->place);
                }
                op3 = getOperandVariable(p->label);
               
                addIfgoto(op1, p->ch[1]->nodeType, op2, op3);
                addGoto(p->label1);
                break;
            }
            if (p->ch[0]->nodeType == T_NOT) { //NOT logexpr
                strcpy(p->ch[1]->label1, p->label);
                strcpy(p->ch[1]->label, p->label1);
                getIC(p->ch[1]);
                break;
            }
            if (p->ch[1]->nodeType == T_AND) { //logexpr AND logexpr
                getLabel(p->ch[0]->label, ++labelNum);
                strcpy(p->ch[0]->label1, p->label1);
                getIC(p->ch[0]);
                addLabel(p->ch[0]->label);
                strcpy(p->ch[2]->label, p->label);
                strcpy(p->ch[2]->label1, p->label1);
                getIC(p->ch[2]);
                break;
            }
            if (p->ch[1]->nodeType == T_OR) { //logexpr OR logexpr
                strcpy(p->ch[0]->label, p->label);
                getLabel(p->ch[0]->label1, ++labelNum);
                getIC(p->ch[0]);
                addLabel(p->ch[0]->label1);
                strcpy(p->ch[2]->label, p->label);
                strcpy(p->ch[2]->label1, p->label1);
                getIC(p->ch[2]);
                break;
            }
            if (p->ch[0]->nodeType == T_LP) { //LP logexpr RP
                strcpy(p->ch[1]->label, p->label);
                strcpy(p->ch[1]->label1, p->label1);
                getIC(p->ch[1]);
                break;
            }
            visitChild(p);
            break;
        case T_compSt: //LC stmts RC
            strcpy(p->ch[1]->label, p->label);
            strcpy(p->ch[1]->label1, p->label1);
            visitChild(p);
            break;
        case T_stmts: //stmt stmts
            if (p->childNum == 2) {
                strcpy(p->ch[0]->label, p->label);
                strcpy(p->ch[0]->label1, p->label1);
                getIC(p->ch[0]);
                if (p->ch[1] != NULL) {
                    strcpy(p->ch[1]->label, p->label);
                    strcpy(p->ch[1]->label1, p->label1);
                    getIC(p->ch[1]);
                }
            }
            break;
        case T_stmt:
            if (p->ch[0]->nodeType == T_RETURN) { // RETURN expr;
                getTemp(p->ch[1]->place, ++tnum);
                getIC(p->ch[1]);
                break;
            }
            if (p->ch[0]->nodeType == T_BREAK) { //BREAK SEMI
                addGoto(p->label1);
                break;
            }
            if (p->ch[0]->nodeType == T_CONTINUE) { //CONTINUE SEMI
                addGoto(p->label);
                break;
            }
            if (p->ch[0]->nodeType == T_compSt) { //compSt
                strcpy(p->ch[0]->label, p->label);
                strcpy(p->ch[0]->label1, p->label1);
                getIC(p->ch[0]);
                break;
            }
            if (p->ch[0]->nodeType == T_IF && p->childNum == 5) { // IF LP logexpr RP stmt
                getLabel(p->ch[2]->label, ++labelNum);
                getLabel(p->ch[2]->label1, ++labelNum);
                getIC(p->ch[2]);
                addLabel(p->ch[2]->label);
                strcpy(p->ch[4]->label, p->label);
                strcpy(p->ch[4]->label1, p->label1);
                getIC(p->ch[4]);
                addLabel(p->ch[2]->label1);
                break;
            }
            if (p->ch[0]->nodeType == T_IF && p->childNum == 7) { // IF LP logexpr RP stmt ELSE stmt
                char s[MAX_LABEL_LEN];
                getLabel(p->ch[2]->label, ++labelNum);
                getLabel(p->ch[2]->label1, ++labelNum);
                getLabel(s, ++labelNum);
                getIC(p->ch[2]);
                addLabel(p->ch[2]->label);
                strcpy(p->ch[4]->label, p->label);
                strcpy(p->ch[4]->label1, p->label1);
                getIC(p->ch[4]);
                addGoto(s);
                addLabel(p->ch[2]->label1);
                strcpy(p->ch[6]->label, p->label);
                strcpy(p->ch[6]->label1, p->label1);
                getIC(p->ch[6]);
                addLabel(s);
                break;
            }
            if (p->ch[0]->nodeType == T_WHILE) { //WHILE LP logexpr RP stmt
                char s[MAX_LABEL_LEN];
                getLabel(s, ++labelNum);
                getLabel(p->ch[2]->label, ++labelNum);
                getLabel(p->ch[2]->label1, ++labelNum);
                addLabel(s);
                getIC(p->ch[2]);
                addLabel(p->ch[2]->label);
                strcpy(p->ch[4]->label, s);
                strcpy(p->ch[4]->label1, p->ch[2]->label1);
                getIC(p->ch[4]);
                addGoto(s);
                addLabel(p->ch[2]->label1);
                break;
            }
            if (p->ch[0]->nodeType == T_FOR) { //FOR LP forexpr SEMI logexpr SEMI forexpr RP stmt
                getIC(p->ch[2]);
                char s[MAX_LABEL_LEN];
                getLabel(s, ++labelNum);
                getLabel(p->ch[4]->label, ++labelNum);
                getLabel(p->ch[4]->label1, ++labelNum);
                addLabel(s);
                getIC(p->ch[4]);
                addLabel(p->ch[4]->label);
                strcpy(p->ch[8]->label, s);
                strcpy(p->ch[8]->label1, p->ch[4]->label1);
                getIC(p->ch[8]);
                getIC(p->ch[6]);
                addGoto(s);
                addLabel(p->ch[4]->label1);
                break;
            }
        default:
            visitChild(p);
    }
   
    switch(ptype) {
        case T_class:
            cls = NULL;
            break;
        case T_funDec:
            intoFunc = 0;
            ft = ft->next;
            break;
        case T_argDec:
                if (p->childNum == 4) {
                    char s[MAX_LABEL_LEN];
                    memset(s, 0, sizeof(s));
                    strcat(s, cls->d);
                    strcat(s, ft->funName);
                    strcat(s, p->ch[3]->strconst);
                    addPara(s);
                }else {
                    char s[MAX_LABEL_LEN];
                    memset(s, 0, sizeof(s));
                    strcat(s, cls->d);
                    strcat(s, ft->funName);
                    strcat(s, p->ch[1]->strconst);   
                    addPara(s);
                }
            break;

        case T_stmt:
            if (p->ch[0]->nodeType == T_RETURN) { // RETURN expr;
                addReturn(p->ch[1]->place);
            }
            break;

    }
}

void printOperand(Operand p) {
    switch(p->kind) {
        case VARIABLE:
            printf("%s", p->u.s);
            break;
        case CONSTANT:
            printf("#%d", p->u.value);
            break;
        case ADDRESS:
            printf("&%s", p->u.s);
            break;
        case MEM:
            printf("*%s", p->u.s);
            break;
    }
}

void printIR(struct InterCodes *p) {
    if (p == NULL) return ;
    switch(p->code.kind) {
        case FUNCTION:
            printf("FUNCTION %s :\n", p->code.u.oneop.op1->u.s);
            break;
        case ASSIGN:
            printOperand(p->code.u.assign.left);
            printf(" := ");
            printOperand(p->code.u.assign.right);
            printf("\n");
            break;
        case PARAM:
            printf("PARAM %s\n", p->code.u.oneop.op1->u.s);
            break;
        case ADD:
            printOperand(p->code.u.binop.result);
            printf(" := ");
            printOperand(p->code.u.binop.op1);
            printf(" + ");
            printOperand(p->code.u.binop.op2);
            printf("\n");
            break;
        case SUB:
            printOperand(p->code.u.binop.result);
            printf(" := ");
            printOperand(p->code.u.binop.op1);
            printf(" - ");
            printOperand(p->code.u.binop.op2);
            printf("\n");
            break;
        case MUL:
            printOperand(p->code.u.binop.result);
            printf(" := ");
            printOperand(p->code.u.binop.op1);
            printf(" * ");
            printOperand(p->code.u.binop.op2);
            printf("\n");
            break;
        case DIV:
            printOperand(p->code.u.binop.result);
            printf(" := ");
            printOperand(p->code.u.binop.op1);
            printf(" / ");
            printOperand(p->code.u.binop.op2);
            printf("\n");
            break;
        case RETURN:
            printf("RETURN ");
            printOperand(p->code.u.oneop.op1);
            printf("\n");
            break;
        case IFGOTO:
            printf("IF ");
            printOperand(p->code.u.ifgoto.op1);
            printf(" %s ", p->code.u.ifgoto.relop->u.s);
            printOperand(p->code.u.ifgoto.op2);
            printf(" GOTO %s\n", p->code.u.ifgoto.op3->u.s);
            break;
        case GOTO:
            printf("GOTO %s\n", p->code.u.oneop.op1->u.s);
            break;
        case LABEL:
            printf("LABEL %s :\n", p->code.u.oneop.op1->u.s);
            break;
        case CALL:
            if (strlen(p->code.u.call.result->u.s) != 0)
                printf("%s := CALL %s\n", p->code.u.call.result->u.s, p->code.u.call.op1->u.s);
            else
                printf("CALL %s\n", p->code.u.call.op1->u.s);
            break;
        case ARG:
            printf("ARG ");
            printOperand(p->code.u.oneop.op1);
            printf("\n");
            break;
        case DEC:
            printf("DEC %s %d\n", p->code.u.dec.op1->u.s, p->code.u.dec.size->u.value);
            break;
        case READ:
            printf("READ %s\n", p->code.u.oneop.op1->u.s);
            break;
        case WRITE:
            printf("WRITE ");
            printOperand(p->code.u.oneop.op1);
            printf("\n");
            break;
    }
    printIR(p->next);
}

void insertTemp(char *s, int x) {
    struct tempNode *p = (struct tempNode *)malloc(sizeof(struct tempNode));
    int k = hash(s, MAX_TEMP_NUM);
    strcpy(p->tempName, s);
    p->num = x;
    p->next = tempMap[k];
    tempMap[k] = p;
}

void insertTempVar(char *t, char *s) {
    struct tempNode *p = (struct tempNode *)malloc(sizeof(struct tempNode));
    int k = hash(t, MAX_TEMP_NUM);
    strcpy(p->tempName, t);
    strcpy(p->idName, s);
    p->next = tempMap[k];
    tempMap[k] = p;
}

struct tempNode *findTemp(char *s) {
    struct tempNode *p = tempMap[hash(s, MAX_TEMP_NUM)];
    while(p != NULL) {
        if (strcmp(p->tempName, s) == 0) return p;
        p = p->next;
    }
    return NULL;
}

void handleBinopOpt(struct InterCodes *p) {
    Operand op1 = p->code.u.binop.op1;
    Operand op2 = p->code.u.binop.op2;
    if (op1->kind == VARIABLE && op1->u.s[0] == 't') {
        struct tempNode *q = findTemp(op1->u.s);
        if (q != NULL) {
            free(p->code.u.binop.op1);
            if (strlen(q->idName) == 0)
                p->code.u.binop.op1 = getOperandConstant(q->num);
            else
                p->code.u.binop.op1 = getOperandVariable(q->idName);
        }
    }
    if (op2->kind == VARIABLE && op2->u.s[0] == 't') {
        struct tempNode *q = findTemp(op2->u.s);
        if (q != NULL) {
            free(p->code.u.binop.op2);
            if (strlen(q->idName) == 0)
                p->code.u.binop.op2 = getOperandConstant(q->num);
            else
                p->code.u.binop.op2 = getOperandVariable(q->idName);
        }
    }
}

void handleOneopOpt(struct InterCodes *p) {
    Operand op1 = p->code.u.oneop.op1;
    if (op1->kind == VARIABLE && op1->u.s[0] == 't') {
        struct tempNode *q = findTemp(op1->u.s);
        if (q != NULL) {
            free(p->code.u.oneop.op1);
            if (strlen(q->idName) == 0)
                p->code.u.oneop.op1 = getOperandConstant(q->num);
            else
                p->code.u.oneop.op1 = getOperandVariable(q->idName);
        }
    }
}

void delInterCode(struct InterCodes *p) {
    if (p->prev == NULL) {
        icsHead = p->next;
        free(p);
        optimizationIR(icsHead);  
    }else {
        struct InterCodes *q = p->prev;
        q->next = p->next;
        free(p);
        optimizationIR(q->next);
    }
}

void optimizationIR(struct InterCodes *p) {
    if (p == NULL) return ;
    Operand op1, op2;
    switch(p->code.kind) {
        case ASSIGN:
            op1 = p->code.u.assign.left;
            op2 = p->code.u.assign.right;
            if (op1->kind == VARIABLE && op1->u.s[0] == 't'  //tvAR := CONSTANT
                && op2->kind == CONSTANT) {
                insertTemp(op1->u.s, op2->u.value);
                delInterCode(p);
                return ;
            }
            if (op1->kind == VARIABLE && op1->u.s[0] == 't'
                && op2->kind == VARIABLE && op2->u.s[0] != 't') { // tVAR := VARABLE
                insertTempVar(op1->u.s, op2->u.s);
                delInterCode(p);
                return ;
            }
            if (op2->kind == VARIABLE && op2->u.s[0] == 't') {
                struct tempNode *q = findTemp(op2->u.s);
                if (q != NULL) {
                    free(p->code.u.assign.right);
                    if (strlen(q->idName) == 0)
                        p->code.u.assign.right = getOperandConstant(q->num);
                    else
                        p->code.u.assign.right = getOperandVariable(q->idName);
                }
            }
            break;
        case ADD:
            handleBinopOpt(p);
            //Combine
            op1 = p->code.u.binop.op1;
            op2 = p->code.u.binop.op2;
            if (op1->kind == CONSTANT && op2->kind == CONSTANT
                && p->code.u.binop.result->u.s[0] == 't') {
                int k = op1->u.value + op2->u.value;
                insertTemp(p->code.u.binop.result->u.s, k);
                delInterCode(p);
                return ;
            }
            break;
        case SUB:
            handleBinopOpt(p);
            //Combine
            op1 = p->code.u.binop.op1;
            op2 = p->code.u.binop.op2;
            if (op1->kind == CONSTANT && op2->kind == CONSTANT
                && p->code.u.binop.result->u.s[0] == 't') {
                int k = op1->u.value - op2->u.value;
                insertTemp(p->code.u.binop.result->u.s, k);
                delInterCode(p);
                return ;
            }
            break;
        case MUL:
            handleBinopOpt(p);
            //Combine
            op1 = p->code.u.binop.op1;
            op2 = p->code.u.binop.op2;
            if (op1->kind == CONSTANT && op2->kind == CONSTANT
                && p->code.u.binop.result->u.s[0] == 't') {
                int k = op1->u.value * op2->u.value;
                insertTemp(p->code.u.binop.result->u.s, k);
                delInterCode(p);
                return ;
            }
            break;
        case DIV:
            handleBinopOpt(p);
            //Combine
            op1 = p->code.u.binop.op1;
            op2 = p->code.u.binop.op2;
            if (op1->kind == CONSTANT && op2->kind == CONSTANT
                && p->code.u.binop.result->u.s[0] == 't') {
                int k = op1->u.value / op2->u.value;
                insertTemp(p->code.u.binop.result->u.s, k);
                delInterCode(p);
                return ;
            }
            break;
        case IFGOTO:
            op1 = p->code.u.ifgoto.op1;
            op2 = p->code.u.ifgoto.op2;
            if (op1->kind == VARIABLE && op1->u.s[0] == 't') {
                struct tempNode *q = findTemp(op1->u.s);
                if (q != NULL) {
                    free(p->code.u.ifgoto.op1);
                    if (strlen(q->idName) == 0)
                        p->code.u.ifgoto.op1 = getOperandConstant(q->num);
                    else
                        p->code.u.ifgoto.op1 = getOperandVariable(q->idName);
                }
            }
            if (op2->kind == VARIABLE && op2->u.s[0] == 't') {
                struct tempNode *q = findTemp(op2->u.s);
                if (q != NULL) {
                    free(p->code.u.ifgoto.op2);
                    if (strlen(q->idName) == 0)
                        p->code.u.ifgoto.op2 = getOperandConstant(q->num);
                    else
                        p->code.u.ifgoto.op2 = getOperandVariable(q->idName);
                }
            }
            break;
        case RETURN:
            handleOneopOpt(p);
            break;
        case WRITE:
            handleOneopOpt(p);
            break;
        case ARG:
        	handleOneopOpt(p);
            break;
    }
    optimizationIR(p->next);
}

void generateIR(struct treeNode *root) {
    getIC(root);   
   	optimizationIR(icsHead);
    //printIR(icsHead);
}
