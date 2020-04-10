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
#define DIVIDE '/'
#define SUBTRACT '-'
#define ADD '+'

//Union unsuitable, shares the same memory for potentially multiple value, size of union is size of largest member
//very intersting language feature though!
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

struct Input {
  int lenght;
  const char* input;
};

void printPrompt(float current);

void* parseKeyboardInput(float current, struct Input *input);

float calculate(struct ArithmeticSum* operation);

#endif /* CalcHeader_h */
