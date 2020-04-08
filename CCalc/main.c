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

const char* getKeyboardInput(){
  
  //look for end of line character \n
  
//  if (input[i] == EOF){
//    break;
//  }
  return "2 * 4";
}

int main(int argc, const char * argv[]) {
  
  //Main run loop
  int running = 1;
  
  float current = 0;
  
  while(running == 1){
    
    current = 5.0;
    
    //present pormpt with current value (nil)
    printPrompt(current);
    
    printf("\n");
    
    const char* input = getKeyboardInput();
    
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
