/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#ifndef COMMON_H
#include "common.h"
#endif

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }
0
  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
     not allowed to use big constants such as 0xffffffff.
     However, you are allowed to combine constants to values greater
     than 255 or less than 0. e.g. 250 + 250 = 500, so long as
     the operator you are using to combine the constants is listed as
     "legal" at the top of the method you are writing.
  2. Function arguments and local variables (no global variables).
  3. Any operators listed as "legal" at the top of the method you are writing.
  4. Shorthand versions of "legal" operators (ex. you can use ++ and += if + is legal)

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
  5. Write comments for your functions! These won't be graded, but it's good
     practice to write comments and may help you debug your code. See the
     above example to see what the comments should look like.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 */
#endif

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
 int or = ~(~x & ~y);
 //for this, the or int just represents using DeMorgan's Law to change an AND into and OR. ~(~A and ~B) = (A or B). 
 int and = ~(x & y);
//this and part and's the two ints together in order to see if the two just have any 1's in the same places and negates it 
//again using one of DeMorgan's Laws ~(A and B) = (~A or ~B), essencially just getting both sides of the OR's for both the negated values of the bits and the unnegated values
 int result = (or & and);
//this final AND is basically the exclusive or. So it deteremines whether both numbers have a 1 or 0 in the same places with both thier negated values AND together and their untouched values AND together, which is what the exclusive or operator does. 
 return result;
}

/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
//Basically just right shifting the x value to shift all the original bits of the number to the least 
//significant bit until you are left with the final two. The reason to and it with the previous value of x after each shift is basically to test whether there are 
//1's in the even numbered bits because if there is, the 1 will remain after the AND, but if not there will be a 0 and that pattern of a result 
//of a 1 or 0 will repeat until the last x & 1, which will show that if at any point there was a 0 in an even numbered place the result will come out to be 0 and if not the result will be a 1
x = x & x >> 16;
x = x & x >> 8;
x = x & x >> 4;
x = x & x >> 2;
return x & 1;
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
int shift  = (x >> n);
// right shift ing x by the amount of n so there can be a buffer of bits at the front of the original x value  
int leftSideTake = ~0 <<(32 + ~n)<< 1;
// basically just creating a mask to cover the left most bits; shifting them left by 32 - n
leftSideTake = ~leftSideTake;
return leftSideTake & shift;
}

/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !/
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
// this just makes the two's complement value of x
int negate = (~x + 1);
// this turns all the bits of x into 1's if the value is non-zero and 0's if the value is 0 
int or = (x | negate);
// // this is going to just copy the most significant bit of the number paste it to the front
int shift = or >> 31;
// // the XOR basically helps to either determine if the least  sig bit was a 1 or 0 of the value 
// and the AND 1 will just give the last answer if the result based on the least significant bit is a 0 or 1
int result = (shift ^1) & 1;
return result;
}

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
int result = ~(1 << 31);
// this just makes 1 the most significant bit in a the number, and the flips the bits so it presents the tmax value
return result;
}

/* 
 * twosBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: twosBits(5,3) = 0, twosBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int twosBits(int x, int n) {
//this is just doing 32 - n
int shift = 32 +(~n + 1);
//this is just shifting the least sig bit to the most sig spot by n
int firstShift = (x << shift);
//this just shifts that most sig bit back to the least sig bit spot where it originally was
int secondShift = (firstShift >> shift);
// this XOR just results in 0 if all of the bits are the same in each place or will return a 1 if the different in each spot. Then the ! flips it 
// to return the opposite
int result = (x ^ secondShift);
return !result;
}

/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
int bias = 127;
int fracField = uf & 0x7FFFFF;
// since there are 23 bits int the fraction field, you would shift the exponent bits over that much
int exponent = (uf >> 23) & 0xFF; // for the 8 bits in the exponent field
int eField = exponent - bias; 

if(!exponent){
  return 0;
 // just ends up going to 0
}

if(exponent == 0x7F800000){
  return 0x80000000u;
  //NaN
}

if(eField > 30){
// out of range
  return 0x80000000u;
}

if(eField < 0){
//no left shifts left
  return 0;
}

fracField = fracField | 0x800000; // add a 1 to the left of field

if(eField <= 23){
  fracField = fracField >> (23-eField); //right shift
}

else{
 fracField = fracField << (eField-23);// shift is greater than 23
}

if(( uf >> 31) & 1){
  return ~fracField + 1;
  //you just return the flipped sign 
}

  return fracField;
}
