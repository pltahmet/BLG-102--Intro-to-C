#include <stdio.h>

#define MAXSIZE 50

int inputSize();
void locateCars(int [][MAXSIZE], int, int);
void manhattanDistance(int [][MAXSIZE], int);

int main(){
    int enteredSize, enteredCarNumber, carSize, enteredCarNumberCheck = 0;
    int parkArea[MAXSIZE][MAXSIZE];

    int i, j;
    for(i = 0; i < MAXSIZE; i++){
        for(j = 0; j < MAXSIZE; j++){
            parkArea[i][j] = 0;
        }
    }

    enteredSize = inputSize();
    carSize = enteredSize * enteredSize;

    while(enteredCarNumberCheck != 1){
        printf("Cars: ");
        scanf("%d", &enteredCarNumber);
        if(enteredCarNumber > carSize || enteredCarNumber < 0){
            printf("Please enter valid number of car (it's must be between 0 and %d \n)", carSize);
        }
        else{
            enteredCarNumberCheck = 1;
        }
    }

    if(enteredCarNumber == 0){ //park is completely empty
        printf("Best Slot Found In: 1 1\n");
    }
    else if(enteredCarNumber == carSize){ //park is full
        printf("Best Slot Found In: 0 0\n");
    }
    else{
        locateCars(parkArea, enteredSize, enteredCarNumber);
        manhattanDistance(parkArea, enteredSize);
    }
    return 0;
}

//check enteredSize between 50 and 1
int inputSize(){
    int size, check = 0;
    while(check != 1){
        printf("Size: ");
        scanf("%d", &size);
        if(size < 1 || size > 50){
            printf("Size must be between 50 and 1\n");
        }
        else{
            check = 1;
        }
    }   
    return size;
}

void locateCars(int park[][MAXSIZE], int size, int carNumber){
    int i, x, y;
    for(i = 0; i < carNumber; i++){
        printf("Locations: ");
        scanf("%d %d", &x, &y);
        park[x - 1][y - 1] = 1;
    }
}

void manhattanDistance(int park[][MAXSIZE], int size){
    int i, j, k, l, x, y;
    int distance, x_distance, y_distance, temp = 101, max = 0;

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(park[i][j] == 0){
                temp = 101;
                for(k = 0; k < size; k++){
                    for(l = 0; l < size; l++){
                        if(park[k][l] == 1){
                            x_distance = i - k;
                            y_distance = j - l;
                            if(x_distance < 0){
                                x_distance *= (-1);
                            }
                            if(y_distance < 0){
                                y_distance *= (-1);
                            }                            
                            distance = x_distance + y_distance;
                            if(distance < temp){
                                temp = distance;
                            }
                        }
                    }
                }
                if(temp > max){
                    max = temp;
                    x = i;
                    y = j;
                }
                else if(temp == max){
                    if(i < x){
                        x = i;
                    }
                    else if(i == x){
                        if(j < y){
                            y = j;
                        }
                    }
                }
            }
        }
    }
    printf("Best Slot Found In: %d %d\n", (x + 1), (y + 1));
}
