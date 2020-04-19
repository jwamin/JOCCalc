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

void printPrompt(float current){
  
  const char* prompt = "JOCCalc ";
  const char* endPrompt = " :> ";
  
  if (current == -1){
    printf("%s Syn Error %s",prompt,endPrompt);
    return;
  }
  
  if (ceil(current) == current) {
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
  
  float lhs, rhs;
  char operator = '\0';
  
  //assume single line calculation
  //PROMPT:> OPERAND/OPERATOR/OPERAND
  
  int inputSize = input->lenght;
  
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
    
    //no program commands, continue with calcualtor input?
    
    //first check for and discount whitespace characters
    if (isspace(currentChar)){
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
  
  //get input, but truncate to int with atoi function
  lhs = atof(lhsString);
  rhs = atof(rhsString);
  
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
