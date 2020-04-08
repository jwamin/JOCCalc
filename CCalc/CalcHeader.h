//
//  CalcHeader.h
//  CCalc
//
//  Created by Joss Manger on 4/8/20.
//  Copyright © 2020 Joss Manger. All rights reserved.
//

#ifndef CalcHeader_h
#define CalcHeader_h

#define MULTIPLY '*'

union ArithmeticSum {
  float lhs;
  float rhs;
  char operator;
};

void printPrompt(float current);

void* parseKeyboardInput(float current, const char* input);

float calculate(union ArithmeticSum* operation);

#endif /* CalcHeader_h */
