//
//  jccalculator.c
//  CCalc
//
//  Created by Joss Manger on 4/8/20.
//  Copyright © 2020 Joss Manger. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "jccalculator.h"

#define MAX 20

enum ValidOperators {divide = DIVIDE, mult = MULTIPLY, add = ADD, sub = SUBTRACT};

int isValidOperator(const char* inputValue) {
    switch (*inputValue){
        case divide:
            return 1;
        case mult:
            return 1;
        case add:
            return 1;
        case sub:
            return 1;
        default:
            return 0;
    }
}

void printPrompt(float current){
  
  const char* prompt = "JOCCalc ";
  const char* endPrompt = " :> ";
  
  if (current == -1){
    printf("%s Syn Error %s",prompt,endPrompt);
    return;
  }
  
  if (ceilf(current) == current) {
    //round number
    printf("%s%.0f%s",prompt,current,endPrompt);
  } else {
    printf("%s%.2f%s",prompt,current,endPrompt);
  }
  
}


struct KeyboardInput* getKeyboardInput(){
  
  //get character input until newline character
  
  char *input = malloc(MAX * sizeof(char));
  int index = 0;
  
  int c = getchar();
  while (c != '\n'){
    input[index] = c;
    index++;
    c = getchar();
  }
  
  struct KeyboardInput *myinput = malloc(sizeof(struct KeyboardInput));
  myinput->length = index;
  myinput->input = input;
  
  return myinput;//"2 * 4";
}


void* parseKeyboardInput(float current, struct KeyboardInput *input){
  
  char lhsString[MAX];
  int lhsStringCount = 0;
  char rhsString[MAX];
  int rhsStringCount = 0;
  
  double lhs, rhs;
  char operator = '\0';
  
  //assume single line calculation
  //PROMPT:> OPERAND/OPERATOR/OPERAND
  
  int inputSize = input->length;
  
  for (int i = 0;i<inputSize;i++){
    
    char currentChar = input->input[i];
    
    //quit
    if ( i == 0 && (currentChar == 'X' || currentChar == 'x') ){
      char* kill = malloc(sizeof(char));
      *kill = currentChar;
      return kill;
    }
    
    //clear
    if ( i == 0 && (currentChar == 'C' || currentChar == 'c') ){
      char* clear = malloc(sizeof(char));
      *clear = currentChar;
      return clear;
    }
    
    //no program commands, continue with calculator input?
    
    //first check for and discount whitespace characters
    if (isspace(currentChar)){
      continue;
    }
    
    //then look for operators
    if (operator == '\0') {

        if (isValidOperator(&currentChar)) {
            operator = currentChar;
            continue;
        }

    }
    
    //then operands
    if (operator == '\0'){
      //we are on lhs
      lhsString[lhsStringCount] = currentChar;
      lhsStringCount++;
      
    } else {
      //we are on rhs
      rhsString[rhsStringCount] = currentChar;
      rhsStringCount++;
    }
    
  }
  
  //get input, but truncate to int with atoi function
  lhs = strtod(lhsString,NULL);
  rhs = strtod(rhsString,NULL);
  
  float fllhs = (float)lhs;
  float flrhs = (float)rhs;
  
  struct ArithmeticOperation *data = malloc(sizeof(struct ArithmeticOperation));
  
  data->lhs = (fllhs == 0) ? current : fllhs; // if there was not left hand size, insert current
  data->rhs = flrhs;
  data->op = operator;
  
  return data;
}

float calculate(struct ArithmeticOperation* operation){
  
  //calculator code goes here
  char operator = operation->op;
  float product;
  
  switch(operator){
    case '*':
      product = operation->lhs * operation->rhs;
      break;
    case '/':
      product = operation->lhs / operation->rhs;
      break;
    case '+':
      product = operation->lhs + operation->rhs;
      break;
    case '-':
      product = operation->lhs - operation->rhs;
      break;
    default:
      printf("Syntax Error\n");
      return -1;
  }
  
  //if print selected // in this case yes
  //fix precision
  printf("%0.2f %c %0.2f = %0.2f\n",operation->lhs,operator,operation->rhs,product);
  
  return product;
  
}
