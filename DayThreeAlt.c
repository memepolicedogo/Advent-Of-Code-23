#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int LINELEN = 140;
const int LINECOUNT = 140;// max 140

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

int isValid(char (*fs)[LINELEN], int x1, int x2, int y){
    int adjY, adjX;
    int ymin = y-1;
    int ymax = y+1;
    int xmin = x1-1;
    for(adjY = ymin;adjY <= ymax;adjY++){
        for(adjX = xmin;adjX<=x2;adjX++){
            if(!(adjY<0 || adjX<0)){
                if(sym(fs[adjY][adjX])){
                    printf("Found symbol %c\n",fs[adjY][adjX]);
                    return 1;
                }
            }
        }
    }
    adjX = 0;
    adjY = 0;
    return 0;
}


int main() {
    FILE *fptr;
    fptr = fopen("DayThreeInputAlt.txt","r");
    if(fptr == NULL){
        return 1;
    }
    char fs[LINECOUNT][LINELEN];
    int i,count;
    count = 0;
    printf("Loading file\n");
    while(fgets(fs[count], LINELEN+2, fptr) && count < LINECOUNT){
        count++;
    }
    printf("File loaded\n");
    int partNum = 0;
    char *fT, neighbor;
    printf("Beginnning analysis\n");
    printf("\n");
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
                if(isValid(fs, fI, fI+fL, i) == 1){
                    printf("Adding %s\n",fT);
                    printf("\n");
                    partNum += atoi(fT);
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
    //prev: 508879, 552835
    //checking 
    printf("%i\n", partNum);
    if(partNum >= 597851){
        printf("too high");
    }else if (partNum <= 549041){
        printf("too low");
    }
    return 0;
}