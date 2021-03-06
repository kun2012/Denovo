#include "semantic.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printErrorLine(int lineNo) {
	semanticError = 1;
	printf("Semantic error at line %d: ", lineNo);
}

int hash(char* name,int size) {
	unsigned int val = 0, i;
    for ( ; *name; ++name) {
		val = (val<< 2) + *name;
		if ( i = val& ~0x3fff) val = (val ^ (i>> 12)) & 0x3fff;
    }
    return val%size;
}

struct typeNode *findType(char* name) {
	int x = hash(name, MAX_TYPE_NUM);
	struct typeNode *p = typeMap[x];
	while (p != NULL) {
		if (strcmp(name, p->d) == 0)
		    return p;
		p = p->next;
	}
	return NULL;
}

int insertType(char* name) {
	if (findType(name) != NULL) return 0;
	int x = hash(name, MAX_TYPE_NUM);
	struct typeNode *p = (struct typeNode *)malloc(sizeof(struct typeNode));
	strcpy(p->d, name);
	p->next = typeMap[x];
	typeMap[x] = p;
	return 1;
}

/*
 * Check class definition.
 */
void checkType(struct treeNode *p) {
	if (p == NULL) return ;
	int typeNum = p->nodeType;
	if (typeNum == T_class) {
		if (!insertType(p->ch[1]->strconst)) {
			printErrorLine(p->lineNum);
			printf("Redefined class %s.\n", p->ch[1]->strconst);
			p->errorFlag = 1;
		}
		return ;
	}
	int i;
	for (i = 0; i < p->childNum; i++)
		checkType(p->ch[i]);
}


struct attriNode *findAttribute(struct attriNode *p, char *varn) {
	while(p != NULL) {
		if (strcmp(varn, p->varName) == 0) return p;
		p = p->next;
	}
	return NULL;
}

struct attriNode *insertAttribute(struct attriNode* p, char *tn, char *varn, int arrsize) {
	struct attriNode *q;
	if (findAttribute(p, varn) != NULL) return NULL;
	q = (struct attriNode *)malloc(sizeof(struct attriNode));
	strcpy(q->varName, varn);
	strcpy(q->typeName, tn);
	q->arraySize = arrsize;
	if (p == NULL) q->offset = 0;
	else q->offset = p->offset + 4; //All attributes are either Int or Address.
	q->next = p;
	return q;
}

int comfun(struct funNode *p1,struct funNode *p2){
	if (strcmp(p1->funName, p2->funName) != 0) return 0;
	struct attriNode *t1 = p1->arghead,*t2 = p2->arghead;
	while (t1 != NULL && t2 != NULL){
		if (strcmp(t1->typeName, t2->typeName) != 0 ) return 0;
		t1=t1->next; t2=t2->next;
	}
	if (t1 != NULL || t2 != NULL) return 0;
	return 1;
}

int insertfun(struct funNode *head,struct funNode *p){
	struct funNode *temp = head;
	while (1){
		if (comfun(temp,p)) return 0;
		if (temp->next == NULL) break;
		temp = temp->next;
	}
	temp->next = p;
	return 1;
}

struct typeNode *cls;
struct attriNode *lis;
struct funNode *ft;
int intoFunc = 0;
int funNum;

void numToString(int x, char *s) {
	int len = 0;
	while(x > 0) {
		s[len++] = (char)(x % 10 + 48);
		x /= 10;
	}
	int i;
	for (i = 0; i < len/2; i++) {
		char c = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = c;
	}
	s[len] = '\0';
}

void checkAttributes(struct treeNode *p) {
	if (p == NULL) return ;
	if (p->errorFlag) return ;
	
	int ptype = p->nodeType;
	if (ptype == T_class) {
	    cls = findType(p->ch[1]->strconst);
	    funNum = -1;
	}
	
	if (ptype == T_funDec) {
	  lis = NULL;
	  intoFunc = 1;
	  funNum++;
	 }
	if (ptype == T_inherits) {
		if (findType(p->ch[1]->strconst) == NULL) {
			printErrorLine(p->lineNum);
			printf("Undefined type %s.\n", p->ch[1]->strconst);
			p->errorFlag = 1;
		}else {
			cls->father = findType(p->ch[1]->strconst);
			p->errorFlag = 0;
		}
	}
	
	int i;
	for (i = 0; i < p->childNum; i++)
		checkAttributes(p->ch[i]);
	
	struct treeNode *ch0 = p->ch[0];
	struct attriNode* temp;
	
	switch(ptype) {
	    case T_varDec: 
	    	if (intoFunc) break;
		    if (ch0->nodeType == T_varDec) { //varDec COMMA ID | varDec COMMA ID ASSIGN expr 
			    p->errorFlag = ch0->errorFlag;
			    if (p->errorFlag != 1) {
			        if((temp=insertAttribute(cls->attriHead, ch0->strconst, p->ch[2]->strconst, ch0->digit))==NULL) {
			        	printErrorLine(p->lineNum);
				        printf("Redefined variable %s.\n", p->ch[2]->strconst);
				        p->errorFlag = 2;
				        strcpy(p->strconst, ch0->strconst);
				        p->digit = ch0->digit;
			        } else {
			            cls->attriHead=temp;
			            strcpy(p->strconst, ch0->strconst);
			            p->digit = ch0->digit;
			        }
			    }
			}
		    if (ch0->nodeType == T_type) {//type ID | type ID ASSIGN expr 
			    p->errorFlag = ch0->errorFlag;
			    if (p->errorFlag != 1) {
			    	if((temp=insertAttribute(cls->attriHead, ch0->strconst, p->ch[1]->strconst, ch0->digit))==NULL) {
						printErrorLine(p->lineNum);
						printf("Redefined variable %s.\n", p->ch[1]->strconst);
						p->errorFlag = 2;
						strcpy(p->strconst, ch0->strconst);
						p->digit = ch0->digit;
			    	} else {
					    cls->attriHead=temp;
						strcpy(p->strconst, ch0->strconst);
						p->digit = ch0->digit;
			    	}
			    }
			}
		    break;
		case T_type:
			if (findType(p->strconst) == NULL) {
				printErrorLine(p->lineNum);
				printf("Undefined type %s.\n", p->strconst);
			    p->errorFlag = 1;
			    break;
			}
			if (p->childNum == 2) //TYPE array
			    p->digit = p->ch[1]->digit;
			else //TYPE | VOID
				p->digit = 0;
			break;
        case T_array:  
	        if (ch0->nodeType == T_array) //T_array LB RB
		    	p->digit = ch0->digit + 1;
	         else  //LB RB
				p->digit = 1;
	        break;
	       
	   case T_argDec: 
	   		if (ch0 == NULL) break;
	   		p->errorFlag = ch0->errorFlag;
			if (p->errorFlag == 1) break;
			
	    	if (ch0->nodeType == T_argDec){ //argDec COMMA type ID
		        if((temp=insertAttribute(lis, p->ch[2]->strconst, p->ch[3]->strconst, p->ch[2]->digit))==NULL) {
		        	printErrorLine(p->lineNum);
			        printf("Redefined variable %s.\n", p->ch[3]->strconst);
			        p->errorFlag = 2;
		        } else lis=temp;
			}else if (ch0->nodeType == T_type) { //type ID
				if((temp=insertAttribute(lis, ch0->strconst, p->ch[1]->strconst, ch0->digit))==NULL) {
			    	printErrorLine(p->lineNum);
				    printf("Redefined variable %s.\n", p->ch[1]->strconst);
				    p->errorFlag = 2;
			    } else lis=temp;
			}
			break;
				
	    case T_funDec: //type ID LP argDec RP LC stmts RC
	    	intoFunc = 0;
			if  (ch0->errorFlag || p->ch[3] != NULL && p->ch[3]->errorFlag) p->errorFlag = 1; 
			else p->errorFlag = 0;
	     	
	     	if (p->errorFlag){
	     		printErrorLine(p->lineNum);
	     		printf("Error function %s definition.\n", p->ch[1]->strconst);
	     		break;
	     	}
	     	
	    	ft = (struct funNode *)malloc(sizeof(struct funNode)); 
	    	strcpy(ft->funName, p->ch[1]->strconst);
	    	strcpy(ft->typeName, p->ch[0]->strconst);
	    	ft->arraySize = ch0->digit;
	    	ft->arghead=lis;
	    	
	    	if (strcmp(p->ch[1]->strconst, "main") != 0) {
				strcat(ft->label, cls->d);
				strcat(ft->label, p->ch[1]->strconst);
				char s[MAX_STR_LEN];
				numToString(funNum, s);
				strcat(ft->label, s);
			}else {
				strcpy(ft->label, "main");
			}
	    	
    		if (cls->funhead == NULL) cls->funhead = ft;
    		else if (insertfun(cls->funhead,ft) == 0){
					printErrorLine(p->lineNum);
					printf("Redefined function %s.\n", p->ch[1]->strconst);
					p->errorFlag=1;
			}
			if (p->errorFlag == 0) {
				strcpy(p->label, ft->label);
			}
	    break;
			   		
	}
	
}


/*
 * ID symbol table definition.
 */

int top = -1;

struct attriNode *findId(char *name) {
	int x = hash(name, MAX_ID_NUM);
	struct attriNode *p = idMap[x];
	while (p != NULL) {
		if (strcmp(name, p->varName) == 0)
		    return p;
		p = p->next;
	//	printf("here------- %s\n",p->varName);
	}
	///Inherit.....need to check father class.
	struct typeNode *c = cls;
	while(c != NULL) {
		p = findAttribute(c->attriHead, name);
		if (p != NULL) return p;
		c = c->father;
	}
 	return NULL;
}

void insertId(char* idName, char* idType, int arrsize) {
	int x = hash(idName, MAX_ID_NUM);
	struct stackNode *stackHead = idStack[top];
	struct attriNode *p = (struct attriNode *)malloc(sizeof(struct attriNode));
	strcpy(p->varName, idName);
	strcpy(p->typeName, idType);
	p->arraySize = arrsize;
	p->nextStackNode = stackHead->next;
	stackHead->next = p;
	p->next = idMap[x];
	idMap[x] = p;
}

void push() {
	top++;
	idStack[top] = (struct stackNode *)malloc(sizeof(struct stackNode));
}

void del(struct attriNode *p) {
	if (p == NULL) return;
	int x = hash(p->varName, MAX_ID_NUM);
	idMap[x]=idMap[x]->next;
	del(p->nextStackNode);
	free(p);
}

void pop() {
	del(idStack[top]->next);
	top--;
}

struct funNode *constructfun(struct treeNode *p){
	struct funNode *temp = (struct funNode *)malloc(sizeof(struct funNode));
	struct treeNode *rec;
	if (p->childNum == 4){
		strcpy(temp->funName,p->ch[0]->strconst);
		rec=p->ch[2];
	}else{
		strcpy(temp->funName,p->ch[2]->strconst);
		rec=p->ch[4];
	}
	struct attriNode *tail;
	
	while (rec != NULL){
		tail = (struct attriNode *)malloc(sizeof(struct attriNode));
		strcpy(tail->typeName,rec->ch[0]->strconst);
		tail->next=temp->arghead;
		temp->arghead=tail;
		if (rec->childNum > 1) rec=rec->ch[2];
		else break;
	}
	return temp;
}

struct funNode *findfun(struct typeNode *c, struct funNode *p){
	while(c != NULL) {
		struct funNode *fhead = c->funhead;
		while (fhead != NULL){
			if (comfun(fhead,p)) return fhead;
			fhead = fhead->next;
		}
		c = c->father;
	}
	return NULL;
}

void checkAll(struct treeNode *p) {
    if (p == NULL) return ;
    if (p->errorFlag) return ;
    p->errorFlag = 0;
    
	int ptype = p->nodeType;
	switch(ptype) {
		case T_class:
			cls = findType(p->ch[1]->strconst);
			ft = cls->funhead;
			break;

		case T_funDec:
			push();
			struct attriNode *argNode = ft->arghead;
			while(argNode != NULL) {
				insertId(argNode->varName, argNode->typeName, argNode->arraySize);
				argNode = argNode->next;
			}
			break;
		case T_compSt:
			push();
			break;
	}
	
	int i;
	for (i = 0; i < p->childNum; i++)
		checkAll(p->ch[i]);
	
	switch(ptype) {
		case T_stmt:
			if (p->ch[0]->nodeType == T_RETURN) { //RETURN expr SEMI
				if (p->ch[1]->errorFlag) break;
				if (strcmp(ft->typeName, p->ch[1]->strconst) != 0 || ft->arraySize != p->ch[1]->digit) {
					printErrorLine(p->lineNum);
					printf("Return type %s not suit current method.\n", p->ch[1]->strconst);
					p->errorFlag = 1;
				}
			}
			break;
		case T_varDec:
			switch(p->childNum) {
				case 5:      //varDec COMMA ID ASSIGN expr
					if (p->errorFlag == 1) break;
					if (top != -1) {
						if (findId(p->ch[2]->strconst) != NULL) {
							printErrorLine(p->lineNum);
							printf("Redefined variable %s.\n", p->ch[2]->strconst);
							p->errorFlag = 2;
						} else {
							insertId(p->ch[2]->strconst, p->ch[0]->strconst, p->ch[0]->digit);
							if (strcmp(p->ch[0]->strconst, p->ch[4]->strconst) != 0) {
								printErrorLine(p->lineNum);
								printf("Can't assign %s to %s.\n", p->ch[4]->strconst, p->ch[0]->strconst);
								p->errorFlag = 2;
							}else if (p->ch[0]->digit != p->ch[4]->digit) {
								printErrorLine(p->lineNum);
								printf("Assign with array size not matched.\n");
								p->errorFlag = 2;
							}else {
								strcpy(p->strconst, p->ch[0]->strconst);
								p->digit = p->ch[0]->digit;
							}
						}
					} else {
						if (strcmp(p->ch[0]->strconst, p->ch[4]->strconst) != 0) {
							printErrorLine(p->lineNum);
							printf("Can't assign %s to %s.\n", p->ch[4]->strconst, p->ch[0]->strconst);
							p->errorFlag = 2;
						}else if (p->ch[0]->digit != p->ch[4]->digit) {
								printErrorLine(p->lineNum);
								printf("Assign with array size not matched.\n");
								p->errorFlag = 2;
						}else {
							strcpy(p->strconst, p->ch[0]->strconst);
							p->digit = p->ch[0]->digit;
						}
					}
					break;
					
				case 4:  //type ID ASSIGN expr
					if (top != -1) {
						if (findType(p->ch[0]->strconst) == NULL) {
							printErrorLine(p->lineNum);
							printf("type %s Undefined.\n", p->ch[0]->strconst);
							p->errorFlag = 1;
						}else {
							if (findId(p->ch[1]->strconst) != NULL) {
								printErrorLine(p->lineNum);
								printf("Redefined variable %s.\n", p->ch[1]->strconst);
								p->errorFlag = 2;
							} else {
								insertId(p->ch[1]->strconst, p->ch[0]->strconst, p->ch[0]->digit);
								if (strcmp(p->ch[0]->strconst, p->ch[3]->strconst) != 0) {
									printErrorLine(p->lineNum);
									printf("Can't assign %s to %s.\n", p->ch[3]->strconst, p->ch[0]->strconst);
									p->errorFlag = 2;
								}else if (p->ch[0]->digit != p->ch[3]->digit) {
									printErrorLine(p->lineNum);
									printf("Assign with array size not matched.\n");
									p->errorFlag = 2;
								}else {
									strcpy(p->strconst, p->ch[0]->strconst);
									p->digit = p->ch[0]->digit;
								}
							}
						}
				//		printf("----end----\n");
					} else { //Attribute
						if (strcmp(p->ch[0]->strconst, p->ch[3]->strconst) != 0) {
							printErrorLine(p->lineNum);
							printf("Can't assign %s to %s.\n", p->ch[3]->strconst, p->ch[0]->strconst);
							p->errorFlag = 2;
						}else if (p->ch[0]->digit != p->ch[3]->digit) {
								printErrorLine(p->lineNum);
								printf("Assign with array size not matched.\n");
								p->errorFlag = 2;
						}else {
							strcpy(p->strconst, p->ch[0]->strconst);
							p->digit = p->ch[0]->digit;
						}
					}
					
					break;
				case 3: //varDec COMMA ID
					if (p->errorFlag == 1) break;
					if (top != -1) {
						if (findId(p->ch[2]->strconst) != NULL) {
							printErrorLine(p->lineNum);
							printf("Redefined variable %s.\n", p->ch[2]->strconst);
							p->errorFlag = 2;
						}
						else {
							insertId(p->ch[2]->strconst, p->ch[0]->strconst, p->ch[0]->digit);
						}
					}
					strcpy(p->strconst, p->ch[0]->strconst);
					p->digit = p->ch[0]->digit;
					break;
				case 2: //type ID
					if (top != -1) {
						if (findType(p->ch[0]->strconst) == NULL ) {
							printErrorLine(p->lineNum);
							printf("type %s Undefined.\n", p->ch[0]->strconst);
							p->errorFlag = 1;
						}else {
							if (findId(p->ch[1]->strconst) != NULL) {
								printErrorLine(p->lineNum);
								printf("Redefined variable %s.\n", p->ch[1]->strconst);
								p->errorFlag = 2;
							}
							else insertId(p->ch[1]->strconst, p->ch[0]->strconst, p->ch[0]->digit);
						}
					}
					strcpy(p->strconst, p->ch[0]->strconst);
					p->digit = p->ch[0]->digit;
					break;
			}
			break;
			
        case T_array:  
	        if (p->ch[0]->nodeType == T_array) //T_array LB RB
		    	p->digit = p->ch[0]->digit + 1;
	         else  //LB RB
				p->digit = 1;
	        break;
		case T_type:
			if (findType(p->strconst) == NULL) {
				printErrorLine(p->lineNum);
				printf("Undefined type %s.\n", p->strconst);
			    p->errorFlag = 1;
			    break;
			}
			if (p->childNum == 2) //TYPE array
			    p->digit = p->ch[1]->digit;
			else //TYPE | VOID
				p->digit = 0;
			break;
			
			
		case T_expr:
			if (p->ch[0]->nodeType == T_NUL) {  //NUL
				strcpy(p->strconst, "void");
				p->digit = 0;
				break;
			}
			if (p->ch[0]->nodeType == T_INT) { //Int
				strcpy(p->strconst, "Int");
				p->digit = 0;
				break;
			}
			if (p->ch[0]->nodeType == T_STR) { //StringConstant
				strcpy(p->strconst, "String");
				p->digit = 0;
				break;
			}
			if (p->childNum == 1 && p->ch[0]->nodeType == T_ID) { //ID
				struct attriNode *q = findId(p->ch[0]->strconst);
				if (q == NULL) {
					printErrorLine(p->lineNum);
					printf("id %s Undefined.\n", p->ch[0]->strconst);
					p->errorFlag = 1;
				} else {
					strcpy(p->strconst, q->typeName);
					p->digit = 0;
				}
				break;
			}
			if (p->ch[0]->nodeType == T_NEW && p->childNum == 2) { // NEW TYPE 
				if (findType(p->ch[1]->strconst) == NULL ) {
					printErrorLine(p->lineNum);
					printf("type %s Undefined.\n", p->ch[1]->strconst);
					p->errorFlag = 1;
				}else {
					strcpy(p->strconst, p->ch[1]->strconst);
					p->digit = 0;
				}
				break;
			}
			if (p->ch[0]->nodeType == T_NEW && p->childNum == 3) { // NEW TYPE arrayExprDec
				
				if (findType(p->ch[1]->strconst) == NULL ) {
					printErrorLine(p->lineNum);
					printf("type %s Undefined.\n", p->ch[1]->strconst);
					p->errorFlag = 1;
				}else {
					strcpy(p->strconst, p->ch[1]->strconst);
					p->digit = p->ch[2]->digit;
				}
				break;
			}
			if (p->childNum == 3 && p->ch[1]->nodeType == T_DOT) {//ID DOT ID
			
				struct attriNode *tid=findId(p->ch[0]->strconst);
				if (tid == NULL){
					printErrorLine(p->lineNum);
					printf("Undefined variable %s.\n", p->ch[0]->strconst);
					p->errorFlag = 1;
					break;
				}
				strcpy(p->ch[0]->label, tid->typeName); //for IR
				
				struct typeNode *tcls = findType(tid->typeName);
				struct attriNode *q = findAttribute(tcls->attriHead, p->ch[2]->strconst);
				if ( q == NULL) {
					printErrorLine(p->lineNum);
					printf("Undefined attribute %s.\n", p->ch[2]->strconst);
					p->errorFlag = 1;
					break;
				}else {
					strcpy(p->strconst, q->typeName);
					p->digit = p->ch[2]->digit;
				}
				break;
			}
			
			if (p->childNum == 5 && p->ch[1]->nodeType == T_DOT && p->ch[3]->nodeType == T_ASSIGN) { //ID DOT ID ASSIGN expr
				struct attriNode *tid=findId(p->ch[0]->strconst);
				if (tid == NULL){
					printErrorLine(p->lineNum);
					printf("Undefined variable %s.\n", p->ch[0]->strconst);
					p->errorFlag = 1;
					break;
				}
				strcpy(p->ch[0]->label, tid->typeName); //for IR
				
				struct typeNode *tcls = findType(tid->typeName);
				struct attriNode *q = findAttribute(tcls->attriHead, p->ch[2]->strconst);
				if ( q == NULL) {
					printErrorLine(p->lineNum);
					printf("Undefined attribute %s.\n", p->ch[2]->strconst);
					p->errorFlag = 1;
					break;
				}else if(strcmp(q->typeName, p->ch[4]->strconst) != 0 || q->arraySize != p->ch[4]->digit ){
					printErrorLine(p->lineNum);
					printf("Assign error.\n");
					p->errorFlag = 1;
				}else{
					strcpy(p->strconst, q->typeName);
					p->digit = p->ch[4]->digit;
				}
				break;
			}

			if (p->childNum == 6 && p->ch[0]->nodeType == T_ID && p->ch[1]->nodeType == T_DOT) {//ID DOT ID LP args RP
				struct typeNode *tcls;
				struct attriNode *tid=findId(p->ch[0]->strconst);
				if (tid == NULL){
					printErrorLine(p->lineNum);
					printf("Undefined variable %s.\n", p->ch[0]->strconst);
					p->errorFlag = 1;
				}else{
					struct funNode *q = constructfun(p);
					tcls=findType(tid->typeName);
					if ((q=findfun(tcls, q)) == NULL){
						printErrorLine(p->lineNum);
						printf("No function matches %s.\n", p->ch[2]->strconst);
						p->errorFlag = 1;
					}else {
						strcpy(p->strconst,q->typeName);
						p->digit = q->arraySize;
						strcpy(p->label, q->label);
					}
				}
				break;
			}
			if (p->childNum == 4 && p->ch[0]->nodeType == T_ID && p->ch[1]->nodeType == T_LP) {//ID LP args RP
				struct funNode *q = constructfun(p);
				if ((q=findfun(cls, q)) == NULL){
					printErrorLine(p->lineNum);
					printf("No function matches %s.\n", p->ch[0]->strconst);
					p->errorFlag = 1;
				}else {
					strcpy(p->strconst,q->typeName);
					p->digit = q->arraySize;
					strcpy(p->label, q->label);
				}
				
				break;
			}
			
			if (p->ch[0]->nodeType == T_MINUS) {   //MINUS EXPR
				p->errorFlag = p->ch[1]->errorFlag;
				if (p->errorFlag == 0) {
					if (strcmp(p->ch[1]->strconst, "Int") != 0 || p->ch[1]->digit != 0) {
						printErrorLine(p->lineNum);
						printf("Minus require type Int.\n");
						p->errorFlag = 1;
					}else {
						strcpy(p->strconst, p->ch[1]->strconst);
						p->digit = 0;
					}
				}
				break;
			}
			
			if (p->ch[0]->nodeType == T_LP) { //LP expr RP
				p->errorFlag = p->ch[1]->errorFlag;
				if (p->errorFlag == 0) {
					strcpy(p->strconst, p->ch[1]->strconst);
					p->digit = p->ch[1]->digit;
				}
				break;
			}
			
			if (p->childNum == 3 && p->ch[1]->nodeType == T_DIV) { //expr DIV expr
				if (p->ch[0]->errorFlag == 0 && p->ch[2]->errorFlag == 0) {
					if (strcmp(p->ch[0]->strconst, "Int") != 0 || strcmp(p->ch[0]->strconst, "Int") != 0 
							|| p->ch[0]->digit != 0 || p->ch[2]->digit != 0) {
						printErrorLine(p->lineNum);
						printf("Div require type Int.\n");
						p->errorFlag = 1;
					}else {
						strcpy(p->strconst, p->ch[0]->strconst);
						p->digit =0;
					}
				}else {
					p->errorFlag = 1;
				}
				break;
			}
			
			if (p->childNum == 3 && p->ch[1]->nodeType == T_MULT) { //expr MULT expr
				if (p->ch[0]->errorFlag == 0 && p->ch[2]->errorFlag == 0) {
					if (strcmp(p->ch[0]->strconst, "Int") != 0 || strcmp(p->ch[0]->strconst, "Int") != 0
						|| p->ch[0]->digit != 0 || p->ch[2]->digit != 0) {
						printErrorLine(p->lineNum);
						printf("Multiply require type Int.\n");
						p->errorFlag = 1;
					}else {
						strcpy(p->strconst, p->ch[0]->strconst);
						p->digit = 0;
					}
				}else {
					p->errorFlag = 1;
				}
				break;
			}
			
			if (p->childNum == 3 && p->ch[1]->nodeType == T_PLUS) { //expr PLUS expr
				if (p->ch[0]->errorFlag == 0 && p->ch[2]->errorFlag == 0) {
					if (strcmp(p->ch[0]->strconst, "Int") != 0 || strcmp(p->ch[0]->strconst, "Int") != 0
						|| p->ch[0]->digit != 0 || p->ch[2]->digit != 0) {
						printErrorLine(p->lineNum);
						printf("Plus require type Int.\n");
						p->errorFlag = 1;
					}else {
						strcpy(p->strconst, p->ch[0]->strconst);
						p->digit = 0;
					}
				}else {
					p->errorFlag = 1;
				}
				break;
			}
			
			if (p->childNum == 3 && p->ch[1]->nodeType == T_MINUS) { //expr MINUS expr
				if (p->ch[0]->errorFlag == 0 && p->ch[2]->errorFlag == 0) {
					if (strcmp(p->ch[0]->strconst, "Int") != 0 || strcmp(p->ch[0]->strconst, "Int") != 0
						|| p->ch[0]->digit != 0 || p->ch[2]->digit != 0) {
						printErrorLine(p->lineNum);
						printf("Minus require type Int.\n");
						p->errorFlag = 1;
					}else {
						strcpy(p->strconst, p->ch[0]->strconst);
						p->digit = 0;
					}
				}else {
					p->errorFlag = 1;
				}
				break;
			}
			
			if (p->childNum == 2 && p->ch[1]->nodeType == T_arrayExpr) {//ID arrayExpr
				p->errorFlag = p->ch[1]->errorFlag;
				if (p->errorFlag == 0) {
					struct attriNode *q = findId(p->ch[0]->strconst);
					if (q == NULL) {
						printErrorLine(p->lineNum);
						printf("id %s Undefined.\n", p->ch[0]->strconst);
						p->errorFlag = 1;
					}else if (q->arraySize != p->ch[1]->digit) {
							printErrorLine(p->lineNum);
							printf("%s array size wrong.\n", p->ch[0]->strconst);
							p->errorFlag = 1;
					}else {
						strcpy(p->strconst, q->typeName);
						p->digit = 0;
					}
				}
				break;
			}
			
			if (p->childNum == 4 && p->ch[1]->nodeType == T_arrayExpr) {//ID arrayExpr ASSIGN expr
				p->errorFlag = p->ch[1]->errorFlag;
				if (p->errorFlag == 0) {
					struct attriNode *q = findId(p->ch[0]->strconst);
					if (q == NULL) {
						printErrorLine(p->lineNum);
						printf("id %s Undefined.\n", p->ch[0]->strconst);
						p->errorFlag = 1;
					}else if (q->arraySize != p->ch[1]->digit) {
						printErrorLine(p->lineNum);
						printf("%s array size wrong.\n", p->ch[0]->strconst);
					}else if (strcmp(q->typeName, p->ch[3]->strconst) != 0 || p->ch[3]->digit != 0) {
						printErrorLine(p->lineNum);
						printf("Assign error.\n");
						p->errorFlag = 1;
					}else {
						strcpy(p->strconst, q->typeName);
						p->digit = 0;
					}
				}
				break;
			}
			
			if (p->childNum == 3 && p->ch[1]->nodeType == T_ASSIGN) { //ID ASSIGN expr
				if (p->ch[2]->errorFlag == 0) {
					
					struct attriNode *q = findId(p->ch[0]->strconst);
					if (q == NULL) {
						printErrorLine(p->lineNum);
						printf("id %s Undefined.\n", p->ch[0]->strconst);
						p->errorFlag = 1;
					} else {
						
						if (strcmp(q->typeName, p->ch[2]->strconst) != 0 || p->ch[2]->digit != q->arraySize) {
							printErrorLine(p->lineNum);
							printf("Can't assign %s to %s.\n", p->ch[2]->strconst, q->typeName);
							p->errorFlag = 1;
						}else {
							strcpy(p->strconst, q->typeName);
							p->digit = 0;
							
						}
					}
				}else {
					p->errorFlag = 1;
				}
				break;
			}
		case T_arrayExpr: 
			if (p->childNum == 4) {//arrayExpr LB expr RB
				if (p->ch[0]->errorFlag != 0 || p->ch[2]->errorFlag != 0) {
					p->errorFlag = 1;
					break;
				}
				if (strcmp(p->ch[2]->strconst, "Int") != 0) {
					printErrorLine(p->lineNum);
					printf("Array size error.\n");
					p->errorFlag = 1;
				}else {
					p->digit = p->ch[0]->digit + 1;
				}
			}else {//LB expr RB
				if (p->ch[1]->errorFlag != 0) {
					p->errorFlag = 1;
					break;
				}				
				if (strcmp(p->ch[1]->strconst, "Int") != 0) {
					printErrorLine(p->lineNum);
					printf("Array use error.\n");
					p->errorFlag = 1;
				}else {
					p->digit = 1;
				}
			}
			break;
		case T_arrayExprDec: 
			if (p->childNum == 4) {//arrayExprDec LB INT RB
				if (p->ch[0]->errorFlag != 0) {
					p->errorFlag = 1;
					break;
				}
				p->digit = p->ch[0]->digit + 1;
			}else {//LB INT RB		
				p->digit = 1;
			}
			break;
		case T_logexpr:
			if (p->childNum == 3 && p->ch[0]->nodeType != T_LP) {
			//logexpr AND logexpr | logexpr OR logexpr | expr NE expr | expr EQ expr | expr GE expr | expr LE expr | expr GT expr | expr LT expr
				if ( strcmp(p->ch[0]->strconst, "Int") != 0 || strcmp(p->ch[2]->strconst, "Int") != 0) {
					printErrorLine(p->lineNum);
					printf("LogExpr require type Int.\n");
					p->errorFlag = 1;
				}else {
					strcpy(p->strconst, p->ch[0]->strconst);
					p->digit = 0;
					p->errorFlag = 0;
				}
			}else { //LP logexpr RP | NOT logexpr
				if (strcmp(p->ch[1]->strconst, "Int") != 0) {
					printErrorLine(p->lineNum);
					printf("LogExpr require type Int.\n");
					p->errorFlag = 1;
				}else {
					strcpy(p->strconst, p->ch[1]->strconst);
					p->digit = 0;
					p->errorFlag = 0;
				}
			}
			break;
		case T_funDec:
			ft = ft->next;
			pop();
			break;
		case T_compSt:
			pop();
			break;
	}
	
}


void setDefaultType() {
	insertType("Int");
	insertType("String");
	insertType("void");
	insertType("IO");
}

void setDefaultMethod() {
	//add IO method
	struct typeNode *ioc = findType("IO");
	if (ioc == NULL) return ;
	struct funNode *r = (struct funNode *)malloc(sizeof(struct funNode));
	strcpy(r->funName, "read");
	strcpy(r->typeName, "Int");
	r->arraySize = 0;
	strcpy(r->label,"read");
	r->arghead = NULL;
	ioc->funhead = r;
	
	struct funNode *w = (struct funNode *)malloc(sizeof(struct funNode));
	strcpy(w->funName, "write");
	strcpy(w->typeName, "Int");
	w->arraySize = 0;
	strcpy(w->label,"write");
	
	struct attriNode *ati = (struct attriNode *)malloc(sizeof(struct attriNode));
	strcpy(ati->varName, "n");
	strcpy(ati->typeName, "Int");
	ati->arraySize = 0;
	ati->offset = 0;
	w->arghead = ati;
	insertfun(ioc->funhead,w);
	
}

void checkSemantic(struct treeNode *root) {
	setDefaultType();
	setDefaultMethod();
	checkType(root);
	checkAttributes(root);
	checkAll(root);
}















