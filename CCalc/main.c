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
#include "jccalculator.h"

int main(int argc, const char * argv[]) {
  
  //Main run loop flag
  int running = 1;
  
  //the result of the last calculation, visible in prompt
  float current = 0;
  
  while(running == 1){
    
    //present prompt with current value (nil)
    printPrompt(current);
    
    //Get Input from Keyboard
    struct KeyboardInput* input = getKeyboardInput();
    
    //Parse keyboard input
    void* currentOperation = parseKeyboardInput(current, input);
    
    //test for exit signal
    char* signal = (char*)currentOperation;
    
    if (*signal == 'X' || *signal == 'x'){
      // if x key
      //exit loop when current scope ends
      running = 0;
    } else if (*signal == 'C' || *signal == 'c') {
      current = 0;
    } else {
      //perform Calculation
      current = calculate(currentOperation);
      //then continue input run loop
    }
    
  }
  
  printf("Bye.\n");
  return EXIT_SUCCESS;
  
}
