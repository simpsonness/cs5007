#include <stdio.h>

#include <stdlib.h>


int main(int argc, char *argv[]) {

FILE* myfile =fopen(argv[1],"r");

char mychar[250];

int addc = 0;

int subc = 0;

int mulc = 0;

int divc = 0;

int movc = 0;

int leac = 0;

int pushc = 0;

int popc = 0;

int retc = 0;

while (myfile && fgets(mychar, sizeof(mychar), myfile)) {

        if(strcasestr(mychar, "addq")
	|| strcasestr(mychar, "addl")
	|| strcasestr(mychar, "addb")) {

                addc++;

        }

        if (strcasestr(mychar, "subq")
	|| strcasestr(mychar, "subl")) {

                subc++;

        }

        if (strcasestr(mychar, "mulq")
	|| strcasestr(mychar, "mull")) {

                mulc++;

        }

        if (strcasestr(mychar, "divq")
	|| strcasestr(mychar, "divb")
	|| strcasestr(mychar, "divw")
	|| strcasestr(mychar, "divl")) {

                divc++;

        }

        if (strcasestr(mychar, "movq")
	|| strcasestr(mychar, "movl")
	|| strcasestr(mychar, "movw")
	|| strcasestr(mychar, "movb")) {

                movc++;

        }

        if (strcasestr(mychar, "leaq")
	|| strcasestr(mychar, "leal")) {

                leac++;

        }

        if (strcasestr(mychar, "pushq")
	|| strcasestr(mychar, "pushl")) {

                pushc++;

        }


        if (strcasestr(mychar, "popq")
	|| strcasestr(mychar, "popl")
	|| strcasestr(mychar, "popw")
	|| strcasestr(mychar, "popb")) {

                popc++;

        }

        if (strcasestr(mychar, "retq")) {

                retc++;

        }

}


printf("ADD%d \n",addc);

printf("SUB%d \n", subc);

printf("MUL%d \n", mulc);

printf("DIV%d \n", divc);

printf("MOV%d \n", movc);

printf("LEA%d \n", leac);

printf("PUSH%d \n", pushc);

printf("POP%d \n", popc);

printf("RET%d \n", retc);



int total = addc + subc + mulc + divc + movc + leac + pushc + popc + retc;


printf("Total instruction is %d ", total);


int cycle = addc * 1 + subc * 1 + mulc * 4 + divc * 15 + movc * 1 + leac * 1 + pushc * 1 + popc * 1 + retc * 3;

printf("Total cycle is %d", cycle);
return 0;
}

