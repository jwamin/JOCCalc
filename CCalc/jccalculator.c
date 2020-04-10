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
#include "CalcHeader.h"
#define MAX 20


void printPrompt(float current){
  
  const char* prompt = "JOCCalc ";
  const char* endPrompt = " :> ";
  
  if (ceil(current) == current) {
    //round number
    printf("%s%.0f%s",prompt,current,endPrompt);
  } else {
    printf("%s%.2f%s",prompt,current,endPrompt);
  }
  
}


struct KeyboardInput* getKeyboardInput(){
  
  //get character input until newline character
  
  char *input = malloc(20 * sizeof(char));
  int index = 0;
  
  char c = getchar();
  while (c != '\n'){
    input[index] = c;
    index++;
    c = getchar();
  }
  
  struct KeyboardInput *myinput = malloc(sizeof(struct KeyboardInput));
  myinput->lenght = index;
  myinput->input = input;
  
  return myinput;//"2 * 4";
}


void* parseKeyboardInput(float current, struct KeyboardInput *input){
  
  char lhsString[MAX];
  int lhsStringCount = 0;
  char rhsString[MAX];
  int rhsStringCount = 0;
  
  int lhs, rhs; // integer, need to fix precision
  char operator = '\0';
  
  //assume single line calculation
  //PROMPT:> OPERAND/OPERATOR/OPERAND
  
  int inputSize = input->lenght;
  
  for (int i = 0;i<inputSize;i++){
    
    char currentChar = input->input[i];
    
    //quit
    if (i == 0 && currentChar == 'X'){
      char* kill = malloc(sizeof(char));
      *kill = currentChar;
      return kill;
    }
    
    //first check for and discount whitespace characters
    if (currentChar == ' '){
      continue;
    }
    
    //then look for operators
    if (operator == '\0'){
      
      switch(currentChar){
        case MULTIPLY:
          operator = currentChar;
          continue;
        case DIVIDE:
          operator = currentChar;
          continue;
        case ADD:
          operator = currentChar;
          continue;
        case SUBTRACT:
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
  
  
  lhs = atoi(lhsString);
  rhs = atoi(rhsString);
  
  float flhs = (float)lhs;
  float flrhs = (float)rhs;
  
  struct ArithmeticOperation *data = malloc(sizeof(struct ArithmeticOperation));
  
  data->lhs = (flhs == 0) ? current : flhs; // if there was not left hand size, insert current
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
      return -1;
  }
  
  //if print selected // in this case yes
  //fix precision
  printf("%0.2f %c %0.2f = %0.2f\n",operation->lhs,operator,operation->rhs,product);
  
  return product;
  
}
