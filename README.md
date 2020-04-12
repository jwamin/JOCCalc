#  JOCCalc

## A Command Line Calculator written in C

### Features

* Basic arithmetic operators `+ - * /` with `getchar()` keyboard input.
* Will accept a single line arithmetic statement. two operands with an operator in between `operand operator operand`
* Will accept an `operator operand` statement, using the "current" result in memory for the left hand operand.
* Dynamic prompt showing current memory value.
* Exit signal by entering X at the prompt

### TODO:

* Fix precision of input, truncates floats to ints
* Refactor Exit signal test to switch statement, enable more commands:
  * Clear command
  * Paper trail
  * Save paper trail
  * Clear paper trail
* More processes sqrt etc
* Arrow Up / Down command memory.
* More operations in one line.
* Static Library

#### Libraries
`<stdio.h>`  `<stdlib.h>` `<math.h>`
