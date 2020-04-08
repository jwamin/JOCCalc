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

//Union unsuitable, shares the same memory for potentially multiple value, size of union is size of largest member
//union ArithmeticSum {
//  float lhs;
//  float rhs;
//  char operator;
//};

// struct will store all values
struct ArithmeticSum {
  float lhs;
  float rhs;
  char op;
};

void printPrompt(float current);

void* parseKeyboardInput(float current, const char* input);

float calculate(struct ArithmeticSum* operation);

#endif /* CalcHeader_h */
