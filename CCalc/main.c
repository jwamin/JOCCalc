//
//  main.c
//  CCalc
//
//  Created by Joss Manger on 4/8/20.
//  Copyright © 2020 Joss Manger. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CalcHeader.h"

struct Input* getKeyboardInput(){
  
  //get character input until newline character
  
  char *input = malloc(20 * sizeof(char));
  int index = 0;
  
  char c = getchar();
  while (c != '\n'){
    input[index] = c;
    index++;
    c = getchar();
  }
  
  struct Input *myinput = malloc(sizeof(struct Input));
  myinput->lenght = index;
  myinput->input = input;
  
  return myinput;//"2 * 4";
}

int main(int argc, const char * argv[]) {
  
  //Main run loop
  int running = 1;
  
  float current = 0;
  
  while(running == 1){
    
    //present pormpt with current value (nil)
    printPrompt(current);
    
    struct Input* input = getKeyboardInput();
    printf("this is my meyboard input |%s| :end\n",input->input);
    
    void* currentOperation = (struct ArithmeticSum*)parseKeyboardInput(current, input);
    
    current = calculate(currentOperation);
    
    printPrompt(current);
     printf("\n");
    
    //get keyboard input,
    
    //parse keyboard in put
    // just operator and operand - use current as first operand
    // operand operator and operand
    
    // c key + enter clears
    
    //calculate answer
    
    
    
    //continue loop
    
    //exit loop
    running = 0;
    
  }
  
  return EXIT_SUCCESS;
}
