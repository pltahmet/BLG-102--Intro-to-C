#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//My code is working n my laptop but first word is not printed on ssh

struct instruction_s{
    int step[MAX];
    int index[MAX];
};

char* get_word(char* s, int n){

    int numberWord = 0, i = 0;

    char *word;
    char temp[100];
    word = &temp[0];
    char *tempS = NULL;

    while(*s != '\0'){            
        if(*s != ' ') {
            if(( tempS == NULL) || (*tempS == ' ')){
                numberWord++;
            }
            if(numberWord == n){
                temp[i] = *s;
                i++;
            }
        }
        s++;
        tempS = s - 1;                         
    }

    temp[i] = '\0';

    return word;
}

void get_sentence(char lines[10000][200], struct instruction_s* instructions, int n_instructions, char* sentence){

    int i, j, k, l;
    int a = 1;
    int sumInstructions = 0;
    char *temp;

    for(i = 0; i <= n_instructions; i++){

        sumInstructions = sumInstructions + instructions->step[a];
        temp = &lines[sumInstructions][1];
        sentence = get_word(temp, instructions->index[a]);

        //convert all upper case letters to lower case
        for(j = 0; j <= strlen(sentence); j++){
            if(sentence[j] >= 65 && sentence[j] <= 92){
                sentence[j] += 32; 
            }
        }

        //remove all punctuation marks attached to the words
        for(k = 0; sentence[k] != '\0'; k++){
            while(!((sentence[k] >= 'a' && sentence[k] <= 'z') || (sentence[k] >= 'A' && sentence[k] <= 'Z') || sentence[k] == '\0')){
                for(l = k; sentence[l] != '\0'; l++){
                    sentence[l] = sentence[l + 1];
                }
                sentence[l] = '\0';
            }
        }
        printf("%s ", sentence);
        a++;
    }
}


int main(int argc, char *argv[]){

    int lineArray = 1, charArray = 1; //line and character of arrayBook
    int lineInstructios = 1, numberInstructions = 0;
    char arrayBook[10000][200];
    struct instruction_s *instructions;
    struct instruction_s temp;
    temp.index[MAX] = '\0';
    temp.step[MAX] = '\0';
    instructions = &temp;
    char *sentence = NULL;

    FILE *fpBook = fopen(argv[1], "r");
    FILE *fpInstructions = fopen(argv[2], "r");

    while (!feof(fpInstructions)){

        fscanf(fpInstructions, "%d %d", &temp.step[lineInstructios], &temp.index[lineInstructios]);
        lineInstructios++;
        numberInstructions++;
    }

    while ((arrayBook[lineArray][charArray] = getc(fpBook)) != EOF){
        if(arrayBook[lineArray][charArray] == '\n'){
            lineArray++;
            charArray = 1;
        }
        else{
            charArray++;
        }    
    }

    get_sentence(arrayBook, instructions, numberInstructions, sentence);

    fclose(fpBook);
    fclose(fpInstructions);
    
    return 0;
}