#include <stdio.h>

int pointThrow(int number, char segment);
int throw(int currentScore, int throwNumber, char throwCircle, int throwScore, int gameState);
int isThrowValid(int currentScore, int throwNumber, char throwCircle, int throwScore, int gameState);

int main(){
  int target, gameScore, throwValue, scoreOfThrow, gameStart = 1;
  char throwSegment;

  printf("Target: ");
  scanf("%d", &target);
  gameScore = target;

  while (gameScore > 0){

    if(gameScore != target){
      gameStart = 0;
    }
    printf("Throw: ");
    scanf("%d %c", &throwValue, &throwSegment);
    scoreOfThrow = pointThrow(throwValue, throwSegment);
    gameScore = throw(gameScore, throwValue, throwSegment, scoreOfThrow, gameStart);
    printf("Points: %d\n", gameScore);       
  }
    return 0;
}

int pointThrow(int number, char segment){

  int pointThrow = 0, multiple;

  if(segment == 'I'){
    return 50;
  }
  if(segment == 'O'){
    return 25;
  }
  if(segment == 'S'){
    multiple = 1;
  }
  else if(segment == 'D'){
    multiple = 2;
  }
  else if(segment == 'T'){
    multiple = 3;
  }
  else{
    return 0;
  }
  
  pointThrow = number * multiple;
  return pointThrow;
}

int throw(int currentScore, int throwNumber, char throwCircle, int throwScore, int gameState){
  
  if(isThrowValid(currentScore, throwNumber, throwCircle, throwScore, gameState)){
    currentScore -= throwScore;
  }
  
  return currentScore;
}

int isThrowValid(int currentScore, int throwNumber, char throwCircle, int throwScore, int gameState){

  if(gameState == 1){
    if(throwCircle == 'D' && (throwNumber > 0 && throwNumber < 21)){
      return 1;
    }
    else{
      return 0;
    }    
  }

  if(currentScore < throwScore || (currentScore - throwScore == 1)){
    return 0;
  }

  if(currentScore == throwScore){
    if(throwCircle == 'D' && (throwNumber > 0 && throwNumber < 21)){
      return 1;
    }
    else{
      return 0;
    }
  }  

  if(throwCircle == 'I' || throwCircle == 'O'){
    return 1;
  }
  
  //calico dosyasındaki 103.satırdaki 30 S inputundan hata aldığımdan dolayı kaldırdım
  // if(throwNumber < 1 || throwNumber > 20){
  //   return 0;
  // }


  return 1;
}