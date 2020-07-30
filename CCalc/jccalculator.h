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
//very interesting language feature though!
//union ArithmeticSum {
//  float lhs;
//  float rhs;
//  char operator;
//};

// struct will store all values
struct ArithmeticOperation {
  float lhs;
  float rhs;
  char op;
};

//
struct KeyboardInput {
  int length;
  const char* input;
};

void printPrompt(float current);
struct KeyboardInput* getKeyboardInput(void);
void* parseKeyboardInput(float current, struct KeyboardInput *input);
float calculate(struct ArithmeticOperation* operation);

#endif /* CalcHeader_h */
