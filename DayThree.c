#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int numerical(char c){
    switch (c)
    {
    case '1':
        return 1;
        break;
    case '2':
        return 1;
        break;
    case '3':
        return 1;
        break;
    case '4':
        return 1;
        break;
    case '5':
        return 1;
        break;
    case '6':
        return 1;
        break;
    case '7':
        return 1;
        break;
    case '8':
        return 1;
        break;
    case '9':
        return 1;
        break;
    case '0':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

int sym(char c){
    switch (c)
    {
    case '#':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '=':
        return 1;
        break;
    case '*':
        return 1;
        break;
    case '+':
        return 1;
        break;
    case '@':
        return 1;
        break;
    case '$':
        return 1;
        break;
    case '&':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '%':
        return 1;
        break;
    
    default:
        return 0;
        break;
    }
}

void substr(char *sub, int l, int s, char *sup) {
    int i;
    for (i = 0; i < l; i++) {
        sub[i] = sup[s + i];
    }
    sub[i] = '\0';
}


int main() {
    const int LINELEN = 142;
    const int LINECOUNT = 140;// max 140
    FILE *fptr;
    fptr = fopen("DayThreeInput.txt","r");
    if(fptr == NULL){
        return 1;
    }
    char fs[LINECOUNT][143];
    //char filestring[142];
    int i,count;
    count = 0;
    printf("Loading file");
    while(fgets(fs[count], LINELEN+1, fptr) && count < LINECOUNT-1){
        count++;
    }
    printf("File loaded");
    int partNum = 0;
    char *fT, neighbor;
    printf("Beginnning analysis");
    for(i=0;i<LINECOUNT;i++){
        int fL = 1;
        int fI = 0;
        while(fL+fI < LINELEN){
            fT = malloc(fL);
            substr(fT, fL, fI, fs[i]);
            //printf("X: %i-%i Y: %i - %s\n", fI, (fI+fL), i, fT);
            if(fs[i][fL+fI] == '\n' || fs[i][fL+fI] == '\0'){
                fL = 1;
                fI = 0;
                free(fT);
                break;
            }//imp else
            if(!numerical(fs[i][fL+fI]) && atoi(fT)!=0){
                //fT val
                //check if its got a symbol
                // printf("Checking surroundings of num %s\n", fT);
                // printf("i: %i\nfL: %i\nfI: %i\n", i, fL, fI);
                char sur[12] = "";
                int lst = 0;
                int end, start;
                end = fL+1;
                start = -1;
                if(fI == 0){// If its the first thang
                    // printf("Is first\n");
                    neighbor = fs[i][fI+fL];
                    
                    // printf("Surrounding: (%i,%i) - %c\n",(fI+fL),i,neighbor);
                    // printf("Pos: %i\n", lst);
                    sur[lst] = neighbor;
                    start++;
                    lst++;
                    // printf("First if end\n");
                }else if(fI+fL == LINELEN){// if it the last thing
                    // printf("Is last\n");
                    neighbor = fs[i][fI-1];
                    // printf("Surrounding: (%i,%i) - %c\n",(fI-1),i,neighbor);
                    // printf("Pos: %i\n", lst);
                    sur[lst] = neighbor;
                    end--;
                    lst++;
                    // printf("Last if end\n");
                }else{
                    // printf("before/end if start\n");
                    neighbor = fs[i][fI-1];
                    // printf("Surrounding: (%i,%i) - %c\n",(fI-1),i,neighbor);
                    // printf("Pos: %i\n", lst);
                    sur[lst] = neighbor;
                    lst++;
                    neighbor = fs[i][fI+fL];
                    // printf("Surrounding: (%i,%i) - %c\n",(fI+fL),i,neighbor);
                    // printf("Pos: %i\n", lst);
                    sur[lst] = neighbor;
                    lst++;
                    // printf("before/end if end\n");
                }
                if(i == 0){//no top
                    // printf("Is top\n");
                    for(int sI = start; sI<end; sI++){
                        neighbor = fs[i+1][fI+sI];
                        // printf("Surrounding: (%i,%i) - %c\n",(fI+sI),i+1,neighbor);
                        // printf("Pos: %i\n", lst);
                        sur[lst] = neighbor;
                        lst++;
                    }
                    // printf("top if end\n");
                }else if( i == LINECOUNT-1){//no bottom
                    // printf("Is bottom\n");
                    for(int sI = start; sI<end; sI++){
                        neighbor = fs[i-1][fI+sI];
                        // printf("Surrounding: (%i,%i) - %c\n",(fI+sI),i-1,neighbor);
                        // printf("Pos: %i\n", lst);
                        sur[lst] = neighbor;
                        lst++;

                    }
                    // printf("bottom if end\n");
                }else{
                    // printf("above/below if start\n");
                    for(int sI = start; sI<end; sI++){
                        neighbor = fs[i+1][fI+sI];
                        // printf("Surrounding: (%i,%i) - %c\n",(fI+sI),i+1,neighbor);
                        // printf("Pos: %i\n", lst);
                        sur[lst] = neighbor;
                        lst++;
                        neighbor = fs[i-1][fI+sI];
                        // printf("Surrounding: (%i,%i) - %c\n",(fI+sI),i-1,neighbor);
                        // printf("Pos: %i\n", lst);
                        sur[lst] = neighbor;
                        lst++;
                    }
                    //printf("above/below if end\n");
                }
                printf("Surroundings: %s\n", sur);
                for(int n=0;n<12;n++){// Checks if there is a symbol
                    // printf("Char: %c\n", sur[n]);
                    // printf("Ascii: %i\n", sur[n]);
                    // printf("Sym: %i\n", sym(sur[n]));
                    if(sym(sur[n])==1){
                        partNum += atoi(fT);
                        // printf("Surroundings: %s\nLength: %lu\n", sur, strlen(sur));
                        printf("Symbol: %c\n", sur[n]);
                        printf("Added %i\n", atoi(fT));
                        break;
                    }
                }
                fL = 1;
                fI = fL+fI+2;
            }else if(atoi(fT)==0){
                fI++;
            }else{
                fL++;
            }
            free(fT);
        }
    }
    fclose(fptr);
    //prev: 508879, 
    printf("%i\n", partNum);
    return 0;
}