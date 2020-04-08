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



void* parseKeyboardInput(float current, const char* input){
  
  char lhsString[10];
  int lhsStringCount = 0;
  char rhsString[10];
  int rhsStringCount = 0;
  
  int lhs, rhs; // integer, need to fix precision
  char operator = '\0';
  
  //assume single line calculation
  //PROMPT:> OPERAND/OPERATOR/OPERAND
  
  int inputSize = sizeof(char) * 5;
  
  for (int i = 0;i<inputSize;i++){
    
    char currentChar = input[i];
    
    //first check for whitespace characters
    if (currentChar == ' '){
      continue;
    }
    
    //first look for operators
    if (operator == '\0'){
       
       if (currentChar == MULTIPLY){
         operator = MULTIPLY;
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
  printf("%0.1f %c %0.1f\n",flhs,operator,flrhs);
  
struct ArithmeticSum *data = malloc(sizeof(struct ArithmeticSum));
  
  
  data->lhs = flhs;
  data->rhs = flrhs;
  data->op = operator;
  
  return data;
}

float calculate(struct ArithmeticSum* operation){
  
  //calculator code goes here
  char operator = operation->op;
  float product;
  
  switch(operator){
    case '*':
      product = operation->lhs * operation->rhs;
      break;
    default:
      return -1;
  }
  
  //if print selected // in this case yes
   printf("%0.2f %c %0.2f = %0.2f\n",operation->lhs,operator,operation->rhs,product);
  
  
  return product;
  
}
