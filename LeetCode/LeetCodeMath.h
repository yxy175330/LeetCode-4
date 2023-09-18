﻿#pragma once
#ifndef LeetcodeMath_H
#define LeetCodeMath_H
#include <stdint.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm> 
#include <functional> 
#include <bitset> 
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <vector> 
#include <stack> 
using namespace std;
/// <summary>
/// The class is to implement some math solution 
/// </summary>
class LeetCodeMath
{
public:
    /// <summary>
    /// Leet code #6. ZigZag Conversion
    /// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
    ///  P   A   H   N
    ///  A P L S I I G
    ///  Y   I   R
    ///  And then read line by line : "PAHNAPLSIIGYIR"
    ///  Write the code that will take a string and make this conversion given a number of rows :
    /// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
    /// </summary>
    string convertZigZag(string s, int numRows);

    /// <summary>
    /// Leet code #7. Reverse Integer
    /// 
    /// Given a 32-bit signed integer, reverse digits of an integer.
    /// Example 1:
    /// Input: 123
    /// Output: 321
    ///
    /// Example 2:
    /// Input: -123
    /// Output: -321
    ///
    /// Example 3:
    /// Input: 120
    /// Output: 21
    /// Note:
    /// Assume we are dealing with an environment which could only store integers 
    /// within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose 
    /// of this problem, assume that your function returns 0 when the reversed 
    /// integer overflows.
    /// </summary>
    int reverse(int x);

    /// <summary>
    /// Leet code #8. String to Integer (atoi)
    /// 
    /// Implement atoi which converts a string to an integer.
    /// The function first discards as many whitespace characters as necessary 
    /// until the first non-whitespace character is found. Then, starting from 
    /// this character, takes an optional initial plus or minus sign followed 
    /// by as many numerical digits as possible, and interprets them as a 
    /// numerical value.
    /// The string can contain additional characters after those that form the 
    /// integral number, which are ignored and have no effect on the behavior of 
    /// this function.
    /// If the first sequence of non-whitespace characters in str is not a valid 
    /// integral number, or if no such sequence exists because either str is 
    /// empty or it contains only whitespace characters, no conversion is 
    /// performed.
    /// If no valid conversion could be performed, a zero value is returned.
    /// Note:
    /// Only the space character ' ' is considered as whitespace character.
    /// Assume we are dealing with an environment which could only store integers 
    /// within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the  
    /// numerical value is out of the range of representable values, 
    /// INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.
    /// Example 1:
    /// Input: "42"
    /// Output: 42
    ///
    /// Example 2:
    /// Input: "   -42"
    /// Output: -42
    /// Explanation: The first non-whitespace character is '-', which is the minus 
    /// sign. Then take as many numerical digits as possible, which gets 42.
    ///
    /// Example 3:
    /// Input: "4193 with words"
    /// Output: 4193
    /// Explanation: Conversion stops at digit '3' as the next character is not a 
    /// numerical digit.
    ///
    /// Example 4:
    /// Input: "words and 987"
    /// Output: 0
    /// Explanation: The first non-whitespace character is 'w', which is not a 
    /// numerical digit or a +/- sign. Therefore no valid conversion could be 
    /// performed.
    ///
    /// Example 5:
    /// Input: "-91283472332"
    /// Output: -2147483648
    /// Explanation: The number "-91283472332" is out of the range of a 32-bit 
    /// signed integer. Thefore INT_MIN (−231) is returned.
    /// </summary>
    int myAtoi(string str);

    /// <summary>
    /// Leet code #9. Palindrome Number
    /// Determine whether an integer is a palindrome. Do this without extra space.
    /// </summary>
    bool isPalindrome(int x);

    /// <summary>
    /// Leet code #396. Rotate Function 
    ///
    /// Given an array of integers A and let n to be its length. 
    /// Assume Bk to be an array obtained by rotating the array A k positions clock-wise, 
    /// we define a "rotation function" F on A as follow:
    /// F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
    /// Calculate the maximum value of F(0), F(1), ..., F(n-1).
    /// Note:
    ///
    /// Example:
    ///
    /// A = [4, 3, 2, 6]
    /// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
    ///	F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
    /// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
    /// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
    /// So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
    /// </summary>
    int maxRotateFunction(vector<int>& A);

    /// <summary>
    /// Leet code #455. Assign Cookies 
    ///
    /// Assume you are an awesome parent and want to give your children some 
    /// cookies. But, you should give each child at most one cookie. Each 
    //// child i has a greed factor gi, which is the minimum size of a 
    /// cookie that the child will be content with; and each cookie j 
    /// has a size sj. If sj >= gi, we can assign the cookie j to the child i, 
    /// and the child i will be content. Your goal is to maximize the number 
    /// of your content children and output the maximum number. 
    /// Note:
    /// You may assume the greed factor is always positive. 
    /// You cannot assign more than one cookie to one child. 
    ///
    /// Example 1:
    /// Input: [1,2,3], [1,1]
    /// Output: 1
    /// Explanation: You have 3 children and 2 cookies. The greed factors 
    /// of 3 children are 1, 2, 3. 
    /// And even though you have 2 cookies, since their size is both 1, you 
    /// could only make the child whose greed factor is 1 content.
    /// You need to output 1.
    ///
    /// Example 2:
    /// Input: [1,2], [1,2,3]
    /// Output: 2
    /// Explanation: You have 2 children and 3 cookies. The greed factors of 2 
    /// children are 1, 2. 
    /// You have 3 cookies and their sizes are big enough to gratify all of 
    /// the children, 
    /// You need to output 2.
    /// </summary>
    int findContentChildren(vector<int>& g, vector<int>& s);

    /// <summary>
    /// Leet code #507. Perfect Number          
    /// 
    /// We define the Perfect Number is a positive integer that is equal to the 
    /// sum of all its positive divisors except itself. 
    /// Now, given an integer n, write a function that returns true when it is a 
    /// perfect number and false when it is not. 
    ///
    /// Example:
    ///
    /// Input: 28
    /// Output: True
    /// Explanation: 28 = 1 + 2 + 4 + 7 + 14
    /// </summary>
    bool checkPerfectNumber(int num);

    /// <summary>
    /// Leet code #537. Complex Number Multiplication       
    /// </summary>
    void parseComplexNumber(string str, pair<int, int>& complex);

    /// <summary>
    /// Leet code #537. Complex Number Multiplication       
    /// 
    /// Given two strings representing two complex numbers. 
    /// You need to return a string representing their multiplication. 
    /// Note i^2 = -1 according to the definition.
    ///
    /// Example 1:
    /// Input: "1+1i", "1+1i"
    /// Output: "0+2i"
    /// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need 
    /// convert it to the form of 0+2i.
    /// Example 2:
    /// Input: "1+-1i", "1+-1i"
    /// Output: "0+-2i"
    /// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need 
    /// convert it to the form of 0+-2i.
    /// Note:
    ///
    /// The input strings will not have extra blank.
    /// The input strings will be given in the form of a+bi, where the integer 
    /// a and b will both belong to the range of [-100, 100]. And the output 
    /// should be also in this form.	 
    /// </summary>
    string complexNumberMultiply(string a, string b);

    /// <summary>
    /// Leet code #564. Find the Closest Palindrome          
    /// 
    /// Given an integer n, find the closest integer (not including itself), which 
    /// is a palindrome. 
    /// The 'closest' is defined as absolute difference minimized between two 
    /// integers.
    /// Example 1:
    /// Input: "123"
    /// Output: "121"
    /// Note:
    /// 1.The input n is a positive integer represented by string, whose length will not exceed 18.
    /// 2.If there is a tie, return the smaller one as answer.
    /// </summary>
    string nearestPalindromic(string n);

    /// <summary>
    /// Leet code #592. Fraction Addition and Subtraction
    /// </summary>
    long long gcd(long long a, long long b);

    /// <summary>
    /// Leet code #592. Fraction Addition and Subtraction
    /// </summary>
    void parseFraction(string& expression, int& index, int& numerator, int& denominator);

    /// <summary>
    /// Leet code #592. Fraction Addition and Subtraction
    /// </summary>
    void addFraction(int n_a, int d_a, int n_b, int d_b, int& numerator, int& denominator);

    /// <summary>
    /// Leet code #592. Fraction Addition and Subtraction
    /// 
    /// Given a string representing an expression of fraction addition and 
    /// subtraction, you need to return the calculation result in string format. 
    /// The final result should be irreducible fraction. If your final result is 
    /// an integer, say 2, you need to change it to the format of fraction that 
    /// has denominator 1. So in this case, 2 should be converted to 2/1.
    /// Example 1:
    /// Input:"-1/2+1/2"
    /// Output: "0/1"
    /// 
    /// Example 2:
    /// Input:"-1/2+1/2+1/3"
    /// Output: "1/3"
    /// 
    /// Example 3:
    /// Input:"1/3-1/2"
    /// Output: "-1/6"
    ///
    /// Example 4:
    /// Input:"5/3+1/3"
    /// Output: "2/1"
    ///
    /// Note:
    /// 1.The input string only contains '0' to '9', '/', '+' and '-'. So does the 
    ///   output.
    /// 2. Each fraction (input and output) has format ±numerator/denominator. If 
    ///    the first input fraction or the output is positive, then '+' will be 
    ///    omitted.
    /// 3. The input only contains valid irreducible fractions, where the numerator
    ///    and denominator of each fraction will always be in the range [1,10]. If 
    ///    the denominator is 1, it means this fraction is actually an integer in a 
    ///    fraction format defined above.
    /// 4. The number of given fractions will be in the range [1,10].
    /// 5. The numerator and denominator of the final result are guaranteed to be 
    ///    valid and in the range of 32-bit int.
    /// </summary>
    string fractionAddition(string expression);

    /// <summary>
    /// Leet code #672. Bulb Switcher II 
    /// 
    /// There is a room with n lights which are turned on initially and 4 
    /// buttons on the wall. After performing exactly m unknown operations 
    /// towards buttons, you need to return how many different kinds of 
    /// status of the n lights could be.
    ///
    /// Suppose n lights are labeled as number [1, 2, 3 ..., n], function of 
    /// these 4 buttons are given below:
    ///
    /// Flip all the lights.
    /// Flip lights with even numbers.
    /// Flip lights with odd numbers.
    /// Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
    ///
    /// Example 1:
    /// Input: n = 1, m = 1.
    /// Output: 2
    /// Explanation: Status can be: [on], [off]
    ///
    /// Example 2:
    /// Input: n = 2, m = 1.
    /// Output: 3
    /// Explanation: Status can be: [on, off], [off, on], [off, off]
    ///
    /// Example 3:
    /// Input: n = 3, m = 1.
    /// Output: 4
    /// Explanation: Status can be: [off, on, off], [on, off, on], 
    /// [off, off, off], [off, on, on].
    /// Note: n and m both fit in range [0, 1000].
    /// </summary>
    int flipLights(int n, int m);

    /// <summary>
    /// Leet code #780. Reaching Points
    ///
    /// A move consists of taking a point (x, y) and transforming it to either
    /// (x, x+y) or (x+y, y).
    ///
    /// Given a starting point (sx, sy) and a target point (tx, ty), return 
    /// True if and only if a sequence of moves exists to transform the point 
    /// (sx, sy) to (tx, ty). Otherwise, return False.
    ///
    /// Examples:
    /// Input: sx = 1, sy = 1, tx = 3, ty = 5
    /// Output: True
    /// Explanation:
    /// One series of moves that transforms the starting point to the target is:
    /// (1, 1) -> (1, 2)
    /// (1, 2) -> (3, 2)
    /// (3, 2) -> (3, 5)
    ///
    /// Input: sx = 1, sy = 1, tx = 2, ty = 2
    /// Output: False
    ///
    /// Input: sx = 1, sy = 1, tx = 1, ty = 1
    /// Output: True
    ///
    /// Note:
    ///
    /// sx, sy, tx, ty will all be integers in the range [1, 10^9].
    /// </summary>
    bool reachingPoints(int sx, int sy, int tx, int ty);

    /// <summary>
    /// Leet code #878. Nth Magical Number
    /// 
    /// A positive integer is magical if it is divisible by either A or B.
    ///
    /// Return the N-th magical number.  Since the answer may be very large, 
    /// return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: N = 1, A = 2, B = 3
    /// Output: 2
    ///
    /// Example 2:
    /// Input: N = 4, A = 2, B = 3
    /// Output: 6
    ///
    /// Example 3:
    /// Input: N = 5, A = 2, B = 4
    /// Output: 10
    ///
    /// Example 4:
    /// Input: N = 3, A = 6, B = 4
    /// Output: 8
    ///
    /// Note:
    /// 1. 1 <= N <= 10^9
    /// 2. 2 <= A <= 40000
    /// 3. 2 <= B <= 40000
    /// </summary>
    int nthMagicalNumber(int N, int A, int B);

    /// <summary>
    /// Leet code #914. X of a Kind in a Deck of Cards
    /// 
    /// In a deck of cards, each card has an integer written on it.
    ///
    /// Return true if and only if you can choose X >= 2 such that it is possible 
    /// to split the entire deck into 1 or more groups of cards, where:
    ///
    /// Each group has exactly X cards.
    /// All the cards in each group have the same integer.
    /// 
    /// Example 1:
    ///
    /// Input: [1,2,3,4,4,3,2,1]
    /// Output: true
    /// Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
    ///
    /// Example 2:
    ///
    /// Input: [1,1,1,2,2,2,3,3]
    /// Output: false
    /// Explanation: No possible partition.
    ///
    /// Example 3:
    ///
    /// Input: [1]
    /// Output: false
    /// Explanation: No possible partition.
    ///
    /// Example 4:
    ///
    /// Input: [1,1]
    /// Output: true
    /// Explanation: Possible partition [1,1]
    ///
    /// Example 5:
    ///
    /// Input: [1,1,2,2,2,2]
    /// Output: true
    /// Explanation: Possible partition [1,1],[2,2],[2,2]
    ///
    /// Note:
    ///
    /// 1. 1 <= deck.length <= 10000
    /// 2. 0 <= deck[i] < 10000
    /// </summary>
    bool hasGroupsSizeX(vector<int>& deck);

    /// <summary>
    /// Leet code #932. Beautiful Array
    /// </summary>
    vector<int> beautifulArray(int N, unordered_map<int, vector<int>>& memo);

    /// <summary>
    /// Leet code #932. Beautiful Array
    /// 
    /// For some fixed N, an array A is beautiful if it is a permutation of the 
    /// integers 1, 2, ..., N, such that:
    ///
    /// For every i < j, there is no k with i < k < j such that 
    //// A[k] * 2 = A[i] + A[j].
    ///
    /// Given N, return any beautiful array A.  (It is guaranteed that one exists.)
    ///
    /// Example 1:
    /// Input: 4
    /// Output: [2,1,4,3]
    /// Example 2:
    /// 
    /// Input: 5
    /// Output: [3,1,2,5,4]
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= N <= 1000
    /// </summary>
    vector<int> beautifulArray(int N);

    /// <summary>
    /// Leet code #1118. Number of Days in a Month
    /// 
    /// Given a year Y and a month M, return how many days there are in that month.
    /// 
    /// Example 1:
    /// Input: Y = 1992, M = 7
    /// Output: 31
    ///
    /// Example 2:
    /// Input: Y = 2000, M = 2
    /// Output: 29
    /// Example 3:
    ///
    /// Input: Y = 1900, M = 2
    /// Output: 28
    /// 
    /// Note:
    /// 1. 1583 <= Y <= 2100
    /// 2. 1 <= M <= 12
    /// </summary>
    int numberOfDays(int Y, int M);

    /// <summary>
    /// Leet code #1131. Maximum of Absolute Value Expression
    /// 
    /// Given two arrays of integers with equal lengths, return the maximum 
    /// value of:
    ///
    /// |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
    ///
    /// where the maximum is taken over all 0 <= i, j < arr1.length.
    /// 
    ///  
    /// Example 1:
    /// Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
    /// Output: 13
    ///
    /// Example 2:
    /// Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
    /// Output: 20
    /// 
    /// Constraints:
    /// 1. 2 <= arr1.length == arr2.length <= 40000
    /// 2. -10^6 <= arr1[i], arr2[i] <= 10^6
    /// </summary>
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2);

    /// <summary>
    /// Leet code #1137. N-th Tribonacci Number
    /// 
    /// The Tribonacci sequence Tn is defined as follows: 
    ///
    /// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
    ///
    /// Given n, return the value of Tn.
    /// 
    /// Example 1:
    ///
    /// Input: n = 4
    /// Output: 4
    /// Explanation:
    /// T_3 = 0 + 1 + 1 = 2
    /// T_4 = 1 + 1 + 2 = 4
    ///
    /// Example 2:
    ///
    /// Input: n = 25
    /// Output: 1389537
    /// Constraints:
    /// 1. 0 <= n <= 37
    /// 2. The answer is guaranteed to fit within a 32-bit integer, 
    ///    ie. answer <= 2^31 - 1.
    /// </summary>
    int tribonacci(int n);

    /// <summary>
    /// Leet code #1134. Armstrong Number
    /// 
    /// The k-digit number N is an Armstrong number if and only if the k-th 
    /// power of each digit sums to N.
    ///
    /// Given a positive integer N, return true if and only if it is an 
    /// Armstrong number.
    ///
    /// Example 1:
    /// Input: 153
    /// Output: true
    /// Explanation: 
    /// 153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.
    ///
    /// Example 2:
    /// Input: 123
    /// Output: false
    /// Explanation: 
    /// 123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.
    /// 
    /// Note:
    /// 1. 1 <= N <= 10^8
    /// </summary>
    bool isArmstrong(int N);

    /// <summary>
    /// Leet code #1144. Decrease Elements To Make Array Zigzag
    /// 
    /// Given an array nums of integers, a move consists of choosing any 
    /// element and decreasing it by 1.
    ///
    /// An array A is a zigzag array if either:
    ///
    /// Every even-indexed element is greater than adjacent elements, 
    /// ie. A[0] > A[1] < A[2] > A[3] < A[4] > ... OR, every odd-indexed 
    /// element is greater than adjacent elements, ie. 
    /// A[0] < A[1] > A[2] < A[3] > A[4] < ...
    /// Return the minimum number of moves to transform the given array 
    /// nums into a zigzag array.
    ///
    /// Example 1:
    ///
    /// Input: nums = [1,2,3]
    /// Output: 2
    /// Explanation: We can decrease 2 to 0 or 3 to 1.
    ///
    /// Example 2:
    /// 
    /// Input: nums = [9,6,1,6,2]
    /// Output: 4
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 1000
    /// </summary>
    int movesToMakeZigzag(vector<int>& nums);

    /// <summary>
    /// Leet code #1154. Day of the Year
    /// 
    /// Given a string date representing a Gregorian calendar date formatted 
    /// as YYYY-MM-DD, return the day number of the year.
    /// Example 1:
    /// Input: date = "2019-01-09"
    /// Output: 9
    /// Explanation: Given date is the 9th day of the year in 2019.
    ///
    /// Example 2:
    /// Input: date = "2019-02-10"
    /// Output: 41
    ///
    /// Example 3:
    /// Input: date = "2003-03-01"
    /// Output: 60
    ///
    /// Example 4:
    /// Input: date = "2004-03-01"
    /// Output: 61
    ///  
    /// Constraints:
    /// 1. date.length == 10
    /// 2. date[4] == date[7] == '-', and all other date[i]'s are digits
    /// 3. date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
    /// </summary>
    int dayOfYear(string date);

    /// <summary>
    /// Leet code #553. Optimal Division
    /// 
    /// Given a list of positive integers, the adjacent integers will perform 
    /// the float division. For example, [2,3,4] -> 2 / 3 / 4.
    /// However, you can add any number of parenthesis at any position to 
    /// change the priority of operations. You should find out how to add 
    /// parenthesis to get the maximum result, and return the corresponding 
    /// expression in string format. Your expression should NOT contain 
    /// redundant parenthesis.
    /// Example:
    /// Input: [1000,100,10,2]
    /// Output: "1000/(100/10/2)"
    /// Explanation:
    /// 1000/(100/10/2) = 1000/((100/10)/2) = 200
    /// However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
    /// since they don't influence the operation priority. So you should return 
    /// "1000/(100/10/2)". 
    ///
    /// Other cases:
    /// 1000/(100/10)/2 = 50
    /// 1000/(100/(10/2)) = 50
    /// 1000/100/10/2 = 0.5
    /// 1000/100/(10/2) = 2
    /// Note: 
    /// 1. The length of the input array is [1, 10].
    /// 2. Elements in the given array will be in range [2, 1000].
    /// 3. There is only one optimal division for each test case.
    /// </summary>
    string optimalDivision(vector<int>& nums);

    /// <summary>
    /// Leet code #1175. Prime Arrangements
    /// 
    /// Return the number of permutations of 1 to n so that prime numbers are 
    /// at prime indices (1-indexed.)
    /// (Recall that an integer is prime if and only if it is greater than 1, 
    /// and cannot be written as a product of two positive integers both 
    /// smaller than it.)
    /// Since the answer may be large, return the answer modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: n = 5
    /// Output: 12
    /// Explanation: For example [1,2,5,4,3] is a valid permutation, but 
    /// [5,2,3,4,1] is not because the prime number 5 is at index 1.
    ///
    /// Example 2:
    /// Input: n = 100
    /// Output: 682289015
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// </summary>
    int numPrimeArrangements(int n);

    /// <summary>
    /// Leet code #1185. Day of the Week
    /// 
    /// Given a date, return the corresponding day of the week for that date.
    /// The input is given as three integers representing the day, month and 
    /// year respectively.
    /// Return the answer as one of the following values {"Sunday", "Monday", 
    /// "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
    /// 
    /// Example 1:
    /// Input: day = 31, month = 8, year = 2019
    /// Output: "Saturday"
    ///
    /// Example 2:
    /// Input: day = 18, month = 7, year = 1999
    /// Output: "Sunday"
    ///
    /// Example 3:
    /// Input: day = 15, month = 8, year = 1993
    /// Output: "Sunday"
    /// 
    /// Constraints:
    /// The given dates are valid dates between the years 1971 and 2100.
    /// </summary>
    string dayOfTheWeek(int day, int month, int year);

    /// <summary>
    /// Leet code #1201. Ugly Number III
    /// 
    /// Write a program to find the n-th ugly number.
    /// Ugly numbers are positive integers which are divisible by a or b or c.
    /// 
    /// Example 1:
    /// Input: n = 3, a = 2, b = 3, c = 5
    /// Output: 4
    /// Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
    /// Example 2:
    /// Input: n = 4, a = 2, b = 3, c = 4
    /// Output: 6
    /// Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
    /// Example 3:
    /// Input: n = 5, a = 2, b = 11, c = 13
    /// Output: 10
    /// Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th 
    /// is 10.
    /// Example 4:
    /// Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
    /// Output: 1999999984
    /// 
    /// Constraints:
    /// 1. 1 <= n, a, b, c <= 10^9
    /// 2. 1 <= a * b * c <= 10^18
    /// 3. It's guaranteed that the result will be in range [1, 2 * 10^9]
    /// </summary>
    int nthUglyNumber(int n, int a, int b, int c);

    /// <summary>
    /// Leet code #1217. Play with Chips      
    ///
    /// There are some chips, and the i-th chip is at position chips[i].
    /// You can perform any of the two following types of moves any number of 
    /// times (possibly zero) on any chip:
    /// Move the i-th chip by 2 units to the left or to the right with a cost of 0.
    /// Move the i-th chip by 1 unit to the left or to the right with a cost of 1.
    /// There can be two or more chips at the same position initially.
    /// Return the minimum cost needed to move all the chips to the same position 
    /// (any position).
    /// 
    /// Example 1:
    /// Input: chips = [1,2,3]
    /// Output: 1
    /// Explanation: Second chip will be moved to positon 3 with cost 1. First 
    /// chip will be moved to position 3 with cost 0. Total cost is 1.
    /// Example 2:
    /// Input: chips = [2,2,2,3,3]
    /// Output: 2
    /// Explanation: Both fourth and fifth chip will be moved to position two 
    /// with cost 1. Total minimum cost will be 2.
    /// 
    /// Constraints:
    /// 1. 1 <= chips.length <= 100
    /// 2. 1 <= chips[i] <= 10^9
    /// </summary>
    int minCostToMoveChips(vector<int>& chips);

    /// <summary>
    /// Leet code #1227. Airplane Seat Assignment Probability
    /// 
    /// n passengers board an airplane with exactly n seats. The first 
    /// passenger has lost the ticket and picks a seat randomly. But 
    /// after that, the rest of passengers will:
    ///
    /// Take their own seat if it is still available, 
    /// Pick other seats randomly when they find their seat occupied 
    /// What is the probability that the n-th person can get his own seat?
    ///
    /// Example 1:
    /// Input: n = 1
    /// Output: 1.00000
    /// Explanation: The first person can only get the first seat.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: 0.50000
    /// Explanation: The second person has a probability of 0.5 to get the 
    /// second seat (when first person gets the first seat).
    /// 
    /// 1. Constraints:
    /// 2. 1 <= n <= 10^5
    /// </summary>
    double nthPersonGetsNthSeat(int n);

    /// <summary>
    /// Leet code #1232. Check If It Is a Straight Line
    /// 
    /// You are given an array coordinates, coordinates[i] = [x, y], where 
    /// [x, y] represents the coordinate of a point. Check if these points 
    /// make a straight line in the XY plane.
    /// 
    /// Example 1:
    /// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    /// Output: true
    ///
    /// Example 2:
    /// Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    /// Output: false
    /// 
    /// Constraints:
    /// 1. 2 <= coordinates.length <= 1000
    /// 2. coordinates[i].length == 2
    /// 3. -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    /// 4. coordinates contains no duplicate point.
    /// </summary>
    bool checkStraightLine(vector<vector<int>>& coordinates);

    /// <summary>
    /// Leet code #1250. Check If It Is a Good Array
    ///  
    /// Given an array nums of positive integers. Your task is to select some 
    /// subset of nums, multiply each element by an integer and add all these 
    /// numbers. The array is said to be good if you can obtain a sum of 1 from 
    /// the array by any possible subset and multiplicand.
    ///
    /// Return True if the array is good otherwise return False.
    ///
    /// Example 1:
    ///
    /// Input: nums = [12,5,7,23]
    /// Output: true
    /// Explanation: Pick numbers 5 and 7.
    /// 5*3 + 7*(-2) = 1
    ///
    /// Example 2:
    ///
    /// Input: nums = [29,6,10]
    /// Output: true
    /// Explanation: Pick numbers 29, 6 and 10.
    /// 29*1 + 6*(-3) + 10*(-1) = 1
    ///
    /// Example 3:
    /// 
    /// Input: nums = [3,6]
    /// Output: false
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    bool isGoodArray(vector<int>& nums);

    /// <summary>
    /// Leet code #1040. Moving Stones Until Consecutive II
    /// 
    /// On an infinite number line, the position of the i-th stone is given by 
    /// stones[i].  Call a stone an endpoint stone if it has the smallest or 
    /// largest position.
    ///
    /// Each turn, you pick up an endpoint stone and move it to an unoccupied 
    /// position so that it is no longer an endpoint stone.
    ///
    /// In particular, if the stones are at say, stones = [1,2,5], you cannot 
    /// move the endpoint stone at position 5, since moving it to any position 
    /// (such as 0, or 3) will still keep that stone as an endpoint stone.
    ///
    /// The game ends when you cannot make any more moves, ie. the stones are 
    /// in consecutive positions.
    ///
    /// When the game ends, what is the minimum and maximum number of moves that 
    /// you could have made?  Return the answer as an length 2 array: answer = 
    /// [minimum_moves, maximum_moves]
    ///
    /// Example 1:
    ///
    /// Input: [7,4,9]
    /// Output: [1,2]
    /// Explanation: 
    /// We can move 4 -> 8 for one move to finish the game.
    /// Or, we can move 9 -> 5, 4 -> 6 for two moves to finish the game.
    ///
    /// Example 2:
    ///
    /// Input: [6,5,4,3,10]
    /// Output: [2,3]
    /// We can move 3 -> 8 then 10 -> 7 to finish the game.
    /// Or, we can move 3 -> 7, 4 -> 8, 5 -> 9 to finish the game.
    /// Notice we cannot move 10 -> 2 to finish the game, because that would be 
    /// an illegal move.
    ///
    /// Example 3:
    ///
    /// Input: [100,101,104,102,103]
    /// Output: [0,0]
    /// Note:
    ///
    /// 1. 3 <= stones.length <= 10^4
    /// 2. 1 <= stones[i] <= 10^9
    /// 3. stones[i] have distinct values.
    /// </summary>
    vector<int> numMovesStonesII(vector<int>& stones);

    /// <summary>
    /// Leet code #1058. Minimize Rounding Error to Meet Target
    /// 
    /// Given an array of prices [p1,p2...,pn] and a target, round each price 
    /// pi to Roundi(pi) so that the rounded array [Round1(p1),Round2(p2)...,
    /// Roundn(pn)] sums to the given target. Each operation Roundi(pi) could 
    /// be either Floor(pi) or Ceil(pi).
    /// Return the string "-1" if the rounded array is impossible to sum to 
    /// target. Otherwise, return the smallest rounding error, which is 
    /// defined as Σ |Roundi(pi) - (pi)| for i from 1 to n, as a string with 
    /// three places after the decimal.
    ///
    /// Example 1:
    /// Input: prices = ["0.700","2.800","4.900"], target = 8
    /// Output: "1.000"
    /// Explanation: 
    /// Use Floor, Ceil and Ceil operations to get (0.7 - 0) + (3 - 2.8) + 
    /// (5 - 4.9) = 0.7 + 0.2 + 0.1 = 1.0 .
    /// 
    /// Example 2:
    /// Input: prices = ["1.500","2.500","3.500"], target = 10
    /// Output: "-1"
    /// Explanation: 
    /// It is impossible to meet the target.
    ///
    /// Note:
    /// 1. 1 <= prices.length <= 500.
    /// 2. Each string of prices prices[i] represents a real number which 
    ///    is between 0 and 1000 and has exactly 3 decimal places.
    /// 3. target is between 0 and 1000000.
    /// </summary>
    string minRoundError(vector<string>& prices, int target);

    /// <summary>
    /// Leet code #1085. Sum of Digits in the Minimum Number
    /// 
    /// Given an array A of positive integers, let S be the sum of the digits 
    /// of the minimal element of A.
    /// 
    /// Return 0 if S is odd, otherwise return 1.
    ///
    /// Example 1:
    ///
    /// Input: [34,23,1,24,75,33,54,8]
    /// Output: 0
    /// Explanation: 
    /// The minimal element is 1, and the sum of those digits is S = 1 
    /// which is odd, so the answer is 0.
    ///
    /// Example 2:
    ///
    /// Input: [99,77,33,66,55]
    /// Output: 1
    /// Explanation: 
    /// The minimal element is 33, and the sum of those digits is 
    /// S = 3 + 3 = 6 which is even, so the answer is 1.
    ///  
    /// Note:
    /// 1. 1 <= A.length <= 100
    /// 2. 1 <= A[i].length <= 100
    /// </summary>
    int sumOfDigits(vector<int>& A);

    /// <summary>
    /// Leet code #1088. Confusing Number II
    /// </summary>
    int confusingNumberII(string& str_n, int index, int leading, int is_last, vector<vector<int>>& cache);

    /// <summary>
    /// Leet code #1088. Confusing Number II
    /// 
    /// We can rotate digits by 180 degrees to form new digits. When 
    /// 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 
    /// respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they 
    /// become invalid.
    ///
    /// A confusing number is a number that when rotated 180 degrees 
    /// becomes a different number with each digit valid.(Note that the 
    /// rotated number can be greater than the original number.)
    ///
    /// Given a positive integer N, return the number of confusing numbers 
    /// between 1 and N inclusive.
    /// 
    /// Example 1:
    ///
    /// Input: 20
    /// Output: 6
    /// Explanation: 
    /// The confusing numbers are [6,9,10,16,18,19].
    /// 6 converts to 9.
    /// 9 converts to 6.
    /// 10 converts to 01 which is just 1.
    /// 16 converts to 91.
    /// 18 converts to 81.
    /// 19 converts to 61.
    ///
    /// Example 2:
    ///
    /// Input: 100
    /// Output: 19
    /// Explanation: 
    /// The confusing numbers are [6,9,10,16,18,19,60,61,66,68,80,81,86,89,
    /// 90,91,98,99,100].
    ///
    ///
    /// Note:
    ///
    ///  1. 1 <= N <= 10^9
    /// </summary>
    int confusingNumberII(int N);

    /// <summary>
    /// Leet code #1093. Statistics from a Large Sample
    /// 
    /// We sampled integers between 0 and 255, and stored the results in an 
    /// array count:  count[k] is the number of integers we sampled equal to k.
    ///
    /// Return the minimum, maximum, mean, median, and mode of the sample 
    /// respectively, as an array of floating point numbers.  The mode is 
    /// guaranteed to be unique.
    ///
    /// (Recall that the median of a sample is:
    ///
    /// The middle element, if the elements of the sample were sorted and the 
    /// number of elements is odd;
    /// The average of the middle two elements, if the elements of the sample 
    /// were sorted and the number of elements is even.)
    ///
    /// Example 1:
    ///
    /// Input: count = 
    /// [0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0]
    /// Output: [1.00000,3.00000,2.37500,2.50000,3.00000]
    /// Example 2:
    /// Input: count = 
    /// [0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    ///  0,0,0,0,0,0,0,0,0,0,0]
    /// Output: [1.00000,4.00000,2.18182,2.00000,1.00000]
    /// 
    /// Constraints:
    ///
    /// 1. count.length == 256
    /// 2. 1 <= sum(count) <= 10^9
    /// 3. The mode of the sample that count represents is unique.
    /// 4. Answers within 10^-5 of the true value will be accepted as correct.
    /// </summary>
    vector<double> sampleStats(vector<int>& count);

    /// <summary>
    /// Leet code #1103. Distribute Candies to People
    /// 
    /// We distribute some number of candies, to a row of n = num_people people 
    /// in the following way:
    ///
    /// We then give 1 candy to the first person, 2 candies to the second person, 
    /// and so on until we give n candies to the last person.
    ///
    /// Then, we go back to the start of the row, giving n + 1 candies to the 
    /// first person, n + 2 candies to the second person, and so on until we give 
    /// 2 * n candies to the last person.
    ///
    /// This process repeats (with us giving one more candy each time, and moving 
    /// to the start of the row after we reach the end) until we run out of 
    /// candies.  The last person will receive all of our remaining candies 
    /// (not necessarily one more than the previous gift).
    ///
    /// Return an array (of length num_people and sum candies) that represents the 
    /// final distribution of candies.
    ///
    /// Example 1:
    ///
    /// Input: candies = 7, num_people = 4
    /// Output: [1,2,3,1]
    ///
    /// Explanation:
    /// On the first turn, ans[0] += 1, and the array is [1,0,0,0].
    /// On the second turn, ans[1] += 2, and the array is [1,2,0,0].
    /// On the third turn, ans[2] += 3, and the array is [1,2,3,0].
    /// On the fourth turn, ans[3] += 1 (because there is only one candy left), and
    /// the final array is [1,2,3,1].
    ///
    /// Example 2:
    ///
    /// Input: candies = 10, num_people = 3
    /// Output: [5,2,3]
    /// Explanation: 
    /// On the first turn, ans[0] += 1, and the array is [1,0,0].
    /// On the second turn, ans[1] += 2, and the array is [1,2,0].
    /// On the third turn, ans[2] += 3, and the array is [1,2,3].
    /// On the fourth turn, ans[0] += 4, and the final array is [5,2,3].
    ///  
    /// Constraints:
    /// 1. 1 <= candies <= 10^9
    /// 2. 1 <= num_people <= 1000
    /// </summary>
    vector<int> distributeCandies(int candies, int num_people);

    /// <summary>
    /// Leet code #66. Plus One
    ///  
    /// Given a non-empty array of digits representing a non-negative 
    /// integer, plus one to the integer.
    ///
    /// The digits are stored such that the most significant digit is at 
    /// the head of the list, and each element in the array contain a 
    /// single digit.
    ///
    /// You may assume the integer does not contain any leading zero, 
    /// except the number 0 itself.
    ///
    /// Example 1:
    ///
    /// Input: [1,2,3]
    /// Output: [1,2,4]
    /// Explanation: The array represents the integer 123.
    ///
    /// Example 2:
    ///
    /// Input: [4,3,2,1]
    /// Output: [4,3,2,2]
    /// Explanation: The array represents the integer 4321.
    /// </summary>
    vector<int> plusOne(vector<int>& digits);

    /// <summary>
    /// Leet code #258. Add Digits
    ///  
    /// Given a non-negative integer num, repeatedly add all its digits until
    /// the result has only one digit.
    ///
    /// Example:
    ///
    /// Input: 38
    /// Output: 2 
    /// Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
    ///              Since 2 has only one digit, return it.
    /// Follow up:
    /// Could you do it without any loop/recursion in O(1) runtime?
    /// </summary>
    int addDigits(int num);

    /// <summary>
    /// Leet code #335. Self Crossing
    ///  
    /// You are given an array x of n positive numbers. You start at 
    /// point (0,0) and moves x[0] metres to the north, then x[1] metres 
    /// to the west, x[2] metres to the south, x[3] metres to the east 
    /// and so on. In other words, after each move your direction changes 
    /// counter-clockwise.
    /// 
    /// Write a one-pass algorithm with O(1) extra space to determine, if 
    /// your path crosses itself, or not.
    ///
    /// Example 1:
    /// ┌───┐
    /// │   │
    /// └───┼──>
    ///     │
    /// 
    /// Input: [2,1,1,2]
    /// Output: true
    ///
    /// Example 2:
    /// ┌──────┐
    /// │      │
    /// │
    /// │
    /// └────────────>
    ///
    /// Input: [1,2,3,4]
    /// Output: false 
    /// 
    /// Example 3:
    /// ┌───┐
    /// │   │
    /// └───┼>
    ///
    /// Input: [1,1,1,1]
    /// Output: true 
    /// </summary>
    bool isSelfCrossing(vector<int>& x);

    /// <summary>
    /// Leet code #319. Bulb Switcher
    ///  
    /// There are n bulbs that are initially off. You first turn on all the 
    /// bulbs. Then, you turn off every second bulb. On the third round, 
    /// you toggle every third bulb (turning on if it's off or turning off 
    /// if it's on). For the i-th round, you toggle every i bulb. For the 
    /// n-th round, you only toggle the last bulb. Find how many bulbs are 
    /// on after n rounds.
    ///
    /// Example:
    /// 
    /// Input: 3
    /// Output: 1 
    /// Explanation: 
    /// At first, the three bulbs are [off, off, off].
    /// After first round, the three bulbs are [on, on, on].
    /// After second round, the three bulbs are [on, off, on].
    /// After third round, the three bulbs are [on, off, off]. 
    ///
    /// So you should return 1, because there is only one bulb is on.
    /// </summary>
    int bulbSwitch(int n);

    /// <summary>
    /// Leet code #29. Divide Two Integers
    ///  
    /// Given two integers dividend and divisor, divide two integers without 
    /// using multiplication, division and mod operator.
    ///
    /// Return the quotient after dividing dividend by divisor.
    ///
    /// The integer division should truncate toward zero.
    ///
    /// Example 1:
    ///
    /// Input: dividend = 10, divisor = 3
    /// Output: 3
    ///
    /// Example 2:
    ///
    /// Input: dividend = 7, divisor = -3
    /// Output: -2
    /// Note:
    /// Both dividend and divisor will be 32-bit signed integers.
    /// The divisor will never be 0.
    /// Assume we are dealing with an environment which could only store 
    /// integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
    /// For the purpose of this problem, assume that your function 
    /// returns 2^31 − 1 when the division result overflows.
    /// </summary>
    int divide(int dividend, int divisor);

    /// <summary>
    /// Leet code #149. Max Points on a Line
    ///  
    /// Given n points on a 2D plane, find the maximum number of points that 
    /// lie on the same straight line.
    ///
    /// Example 1:
    ///
    /// Input: [[1,1],[2,2],[3,3]]
    /// Output: 3
    /// Explanation:
    /// ^
    /// |
    /// |        o
    /// |     o
    /// |  o  
    /// +------------->
    /// 0  1  2  3  4
    ///
    /// Example 2:
    ///
    /// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
    /// Output: 4
    /// Explanation:
    /// ^
    /// |
    /// |  o
    /// |     o        o
    /// |        o
    /// |  o        o
    /// +------------------->
    /// 0  1  2  3  4  5  6
    /// NOTE: input types have been changed on April 15, 2019. Please reset 
    /// to default code definition to get new method signature.
    /// </summary>
    int maxPoints(vector<Point>& points);

    /// <summary>
    /// Leet code #172. Factorial Trailing Zeroes
    ///  
    /// Given an integer n, return the number of trailing zeroes in n!.
    ///
    /// Example 1:
    ///
    /// Input: 3
    /// Output: 0
    /// Explanation: 3! = 6, no trailing zero.
    ///
    /// Example 2:
    /// Input: 5
    /// Output: 1
    /// Explanation: 5! = 120, one trailing zero.
    /// Note: Your solution should be in logarithmic time complexity.
    /// </summary>
    int trailingZeroes(int n);

    /// <summary>
    /// Leet code #441. Arranging Coins 
    ///
    /// You have a total of n coins that you want to form in a staircase 
    /// shape, where every k-th row must have exactly k coins.
    /// Given n, find the total number of full staircase rows that can be 
    /// formed.
    /// n is a non-negative integer and fits within the range of a 32-bit 
    /// signed integer.
    ///
    /// Example 1: 
    /// n = 5
    /// The coins can form the following rows:
    /// #
    /// # #
    /// # #
    /// Because the 3rd row is incomplete, we return 2.
    /// 
    /// Example 2: 
    /// n = 8
    /// The coins can form the following rows:
    /// #
    /// # #
    /// # # #
    /// # #
    /// Because the 4th row is incomplete, we return 3.
    /// </summary>
    int arrangeCoins(int n);

    /// <summary>
    /// Leet code #1037. Valid Boomerang
    /// </summary>
    double distance(vector<int>& x, vector<int>& y);

    /// <summary>
    /// Leet code #1037. Valid Boomerang
    /// 
    /// A boomerang is a set of 3 points that are all distinct and not in a 
    /// straight line.
    ///
    /// Given a list of three points in the plane, return whether these points 
    /// are a boomerang.
    ///
    /// 
    ///
    /// Example 1:
    ///
    /// Input: [[1,1],[2,3],[3,2]]
    /// Output: true
    /// Example 2:
    ///
    /// Input: [[1,1],[2,2],[3,3]]
    /// Output: false
    ///  
    /// Note:
    /// 1. points.length == 3
    /// 2. points[i].length == 2
    /// 3. 0 <= points[i][j] <= 100
    /// </summary>
    bool isBoomerang(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #1033. Moving Stones Until Consecutive
    /// 
    /// Three stones are on a number line at positions a, b, and c.
    ///
    /// Each turn, let's say the stones are currently at positions x, y, z with 
    /// x < y < z.  You pick up the stone at either position x or position z, and 
    /// move that stone to an integer position k, with x < k < z and k != y.
    ///
    /// The game ends when you cannot make any more moves, ie. the stones are in 
    /// consecutive positions.
    ///
    /// When the game ends, what is the minimum and maximum number of moves that 
    /// you could have made?  Return the answer as an length 2 array: answer = 
    /// [minimum_moves, maximum_moves]
    ///
    /// Example 1:
    /// Input: a = 1, b = 2, c = 5
    /// Output: [1, 2]
    /// Explanation: Move stone from 5 to 4 then to 3, or we can move it directly 
    /// to 3.
    ///
    /// Example 2:
    /// Input: a = 4, b = 3, c = 2
    /// Output: [0, 0]
    /// Explanation: We cannot make any moves.
    ///
    /// Note:
    /// 1. 1 <= a <= 100
    /// 2. 1 <= b <= 100
    /// 3. 1 <= c <= 100
    /// 4. a != b, b != c, c != a
    /// </summary>
    vector<int> numMovesStones(int a, int b, int c);

    /// <summary>
    /// Leet code #1015. Smallest Integer Divisible by K
    /// 
    /// Given a positive integer K, you need find the smallest positive integer 
    /// N such that N is divisible by K, and N only contains the digit 1.
    ///
    /// Return the length of N.  If there is no such N, return -1.
    ///
    /// Example 1:
    /// Input: 1
    /// Output: 1
    /// Explanation: The smallest answer is N = 1, which has length 1.
    ///
    /// Example 2:
    /// Input: 2
    /// Output: -1
    /// Explanation: There is no such positive integer N divisible by 2.
    ///
    /// Example 3:
    /// Input: 3
    /// Output: 3
    /// Explanation: The smallest answer is N = 111, which has length 3.
    /// 
    /// Note:
    ///
    /// 1 <= K <= 10^5
    /// </summary>
    int smallestRepunitDivByK(int K);

    /// <summary>
    /// Leet code #1256. Encode Number
    /// 
    /// Given a non-negative integer num, Return its encoding string.
    /// 
    /// The encoding is done by converting the integer to a string using 
    /// a secret function that you should deduce from the following table:
    ///
    /// Example 1:
    ///
    /// Input: num = 23
    /// Output: "1000"
    ///
    /// Example 2:
    ///
    /// Input: num = 107
    /// Output: "101100"
    /// </summary>
    string encode(int num);

    /// <summary>
    /// Leet code #1262. Greatest Sum Divisible by Three
    /// 
    /// Given an array nums of integers, we need to find the maximum possible 
    /// sum of elements of the array such that it is divisible by three.
    ///
    /// Example 1:
    ///
    /// Input: nums = [3,6,5,1,8]
    /// Output: 18
    /// Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum 
    /// divisible by 3).
    ///
    /// Example 2:
    /// 
    /// Input: nums = [4]
    /// Output: 0
    /// Explanation: Since 4 is not divisible by 3, do not pick any number.
    ///
    /// Example 3:
    ///
    /// Input: nums = [1,2,3,4,4]
    /// Output: 12
    /// Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum 
    /// divisible by 3).
    ///
    ///
    /// Constraints:
    ///
    /// 1. 1 <= nums.length <= 4 * 10^4
    /// 2. 1 <= nums[i] <= 10^4
    /// </summary>
    int maxSumDivThree(vector<int>& nums);

    /// <summary>
    /// Leet code #292. Nim Game
    /// 
    /// You are playing the following Nim Game with your friend: There is 
    /// a heap of stones on the table, each time one of you take turns to 
    /// remove 1 to 3 stones. The one who removes the last stone will be 
    /// the winner. You will take the first turn to remove the stones.
    ///
    /// Both of you are very clever and have optimal strategies for the 
    /// game. Write a function to determine whether you can win the game 
    /// given the number of stones in the heap.
    ///
    /// Example:
    ///
    /// Input: 4
    /// Output: false 
    /// Explanation: If there are 4 stones in the heap, then you will never 
    /// win the game; No matter 1, 2, or 3 stones you remove, the last stone 
    /// will always be removed by your friend.
    /// </summary>
    bool canWinNim(int n);

    /// <summary>
    /// Leet code #273. Integer to English Words
    /// 
    /// Convert a non-negative integer to its english words representation. 
    /// Given input is guaranteed to be less than 231 - 1.
    ///
    /// Example 1:
    ///
    /// Input: 123
    /// Output: "One Hundred Twenty Three"
    ///
    /// Example 2:
    ///
    /// Input: 12345
    /// Output: "Twelve Thousand Three Hundred Forty Five"
    ///
    /// Example 3:
    ///
    /// Input: 1234567
    /// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred 
    /// Sixty Seven"
    ///
    /// Example 4:
    ///
    /// Input: 1234567891
    /// Output: "One Billion Two Hundred Thirty Four Million Five Hundred 
    /// Sixty Seven Thousand Eight Hundred Ninety One"
    /// </summary>
    string numberToWords(int num);

    /// <summary>
    /// Leet code #50. Pow(x, n) 
    /// 
    /// Implement pow(x, n), which calculates x raised to the power n (x^n).
    ///
    /// Example 1:
    /// 
    /// Input: 2.00000, 10
    /// Output: 1024.00000
    ///
    /// Example 2:
    ///
    /// Input: 2.10000, 3
    /// Output: 9.26100
    ///
    /// Example 3:
    ///
    /// Input: 2.00000, -2
    /// Output: 0.25000
    /// Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
    ///
    /// Note:
    ///
    /// 1. -100.0 < x < 100.0
    /// 2. n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
    /// </summary>
    double myPow(double x, int n);

    /// <summary>
    /// Leet code #223. Rectangle Area 
    /// 
    /// Find the total area covered by two rectilinear rectangles in a 2D 
    /// plane.
    ///
    /// Each rectangle is defined by its bottom left corner and top right 
    /// corner as shown in the figure.
    ///
    /// Rectangle Area
    ///
    /// Example:
    ///
    /// Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
    /// Output: 45
    /// Note:
    ///
    /// Assume that the total area is never beyond the maximum possible 
    /// value of int.
    /// </summary>
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);

    /// <summary>
    /// Leet code #43. Multiply Strings
    /// 
    /// Given two non-negative integers num1 and num2 represented as strings, 
    /// return the product of num1 and num2, also represented as a string.
    ///
    /// Example 1:
    /// Input: num1 = "2", num2 = "3"
    /// Output: "6"
    ///
    /// Example 2:
    ///
    /// Input: num1 = "123", num2 = "456"
    /// Output: "56088"
    ///
    /// Note:
    ///
    /// 1. The length of both num1 and num2 is < 110.
    /// 2. Both num1 and num2 contain only digits 0-9.
    /// 3. Both num1 and num2 do not contain any leading zero, except the number 
    ///    0 itself.
    /// 4. You must not use any built-in BigInteger library or convert the inputs 
    ///    to integer directly.
    /// </summary>
    string multiply(string num1, string num2);

    /// <summary>
    /// Leet code #365. Water and Jug Problem  
    ///
    /// You are given two jugs with capacities x and y litres. There is an 
    /// infinite amount of water supply available. 
    /// You need to determine whether it is possible to measure exactly z 
    //  litres using these two jugs.
    /// If z liters of water is measurable, you must have z liters of water 
    /// contained within one or both buckets by the end.
    /// Operations allowed: 
    /// Fill any of the jugs completely with water.
    /// Empty any of the jugs.
    /// Pour water from one jug into another till the other jug is completely 
    /// full or the first jug itself is empty.
    ///
    /// Example 1: (From the famous "Die Hard" example)
    /// Input: x = 3, y = 5, z = 4 
    /// Output: True
    /// 
    /// Example 2:
    /// Input: x = 2, y = 6, z = 5
    /// Output: False 	
    /// </summary>
    bool canMeasureWater(int x, int y, int z);

    /// <summary>
    /// Leet code #447. Number of Boomerangs  
    ///
    /// Given n points in the plane that are all pairwise distinct, a 
    /// "boomerang" is a tuple of points (i, j, k) 
    /// such that the distance between i and j equals the distance between 
    /// i and k (the order of the tuple matters).
    ///
    /// Find the number of boomerangs. You may assume that n will be at 
    /// most 500 and coordinates of points are all in the 
    /// range [-10000, 10000] (inclusive).
    ///
    /// Example:
    ///
    /// Input:
    /// [[0,0],[1,0],[2,0]]
    /// Output:
    /// 2
    /// Explanation:
    /// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
    /// </summary>
    int numberOfBoomerangs(vector<pair<int, int>>& points);

    /// <summary>
    /// Leet code #372. Super Pow 
    ///
    /// Your task is to calculate a^b mod 1337 where a is a positive integer 
    /// and b is an extremely large 
    /// positive integer given in the form of an array.  
    ///
    /// Example1: 
    /// a = 2
    /// b = [3]
    /// Result: 8
    /// 
    /// Example2: 
    /// a = 2
    /// b = [1,0]
    /// Result: 1024
    /// </summary>
    int superPow(int a, vector<int>& b);

    /// <summary>
    /// Leet code #356. Line Reflection       
    /// 
    /// Given n points on a 2D plane, find if there is such a line parallel 
    /// to y-axis that reflect the given points.
    ///
    /// Example 1:
    /// Given points = [[1,1],[-1,1]], return true. 
    ///
    /// Example 2:
    /// Given points = [[1,1],[-1,-1]], return false. 
    /// Follow up:
    /// Could you do better than O(n2)? 
    /// Hint:
    /// 1.Find the smallest and largest x-value for all points.
    /// 2.If there is a line then it should be at y = (minX + maxX) / 2.
    /// 3.For each point, make sure that it has a reflected point in the 
    ///   opposite side.
    /// </summary>
    bool isReflected(vector<pair<int, int>>& points);

    /// <summary>
    /// Leet code #469. Convex Polygon 
    /// determinant of 2x2 matrix [point1-point0, point2-point0]
    /// </summary>
    long det2(vector<int>& point0, vector<int>& point1, vector<int>& point2);

    /// <summary>
    /// Leet code #469. Convex Polygon       
    /// 
    /// Given a list of points that form a polygon when joined sequentially, 
    /// find if this polygon is convex 
    /// (Convex polygon definition).
    /// 
    /// Note: 
    /// 1.There are at least 3 and at most 10,000 points.
    /// 2.Coordinates are in the range -10,000 to 10,000.
    /// 3.You may assume the polygon formed by given points is always a simple 
    ///   polygon 
    /// (Simple polygon definition). In other words, we ensure that exactly 
    /// two edges intersect at each vertex, and that edges otherwise don't 
    /// intersect each other. 
    ///
    /// Example 1: 
    /// [[0,0],[0,1],[1,1],[1,0]]
    ///
    /// Answer: True
    /// Example 2: 
    /// [[0,0],[0,10],[10,10],[10,0],[5,5]]
    /// Answer: False
    /// </summary>
    /// Great solution inspired by @Ipeq1! Here is a C++ version with 
    /// extracted determinant calculation.
    /// The key observation for convexity is that vector pi+1-pi always 
    /// turns to the same direction 
    /// to pi+2-pi formed by any 3 sequentially adjacent vertices, i.e., 
    /// cross product (pi+1-pi) x (pi+2-pi) 
    /// does not change sign when traversing sequentially along polygon 
    /// vertices.
    /// Note that for any 2D vectors v1, v2,
    /// v1 x v2 = det([v1, v2])
    /// which is the determinant of 2x2 matrix [v1, v2]. And the sign of 
    /// det([v1, v2]) represents 
    /// the positive z-direction of right-hand system from v1 to v2. 
    /// So det([v1, v2]) ≥ 0 
    /// if and only if v1 turns at most 180 degrees counterclockwise to v2.
    bool isConvex(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #483. Smallest Good Base       
    /// </summary>
    unsigned long long sumBase(unsigned long long base, int digits);

    /// <summary>
    /// Leet code #483. Smallest Good Base       
    /// 
    /// For an integer n, we call k>=2 a good base of n, if all digits of n 
    /// base k are 1. 
    /// Now given a string representing n, you should return the smallest 
    /// good base of n 
    /// in string format.
    /// 
    /// Example 1: 
    /// Input: "13"
    /// Output: "3"
    /// Explanation: 13 base 3 is 111.
    /// 
    /// Example 2:
    /// Input: "4681" 
    /// Output: "8"
    /// Explanation: 4681 base 8 is 11111.
    /// 
    ///
    /// Example 3:
    /// Input: "1000000000000000000" 
    /// Output: "999999999999999999"
    /// Explanation: 1000000000000000000 base 999999999999999999 is 11.
    /// Note:
    /// 1.The range of n is [3, 10^18].
    /// 2.The string representing n is always valid and will not have 
    ///   leading zeros.
    /// </summary>
    string smallestGoodBase(string n);

    /// <summary>
    /// Leet code #360. Sort Transformed Array        
    /// 
    /// Given a sorted array of integers nums and integer values a, b and c. 
    /// Apply a function of the form f(x) = ax2 + bx + c to each element x in 
    /// the array.  
    /// The returned array must be in sorted order. 
    /// Expected time complexity: O(n) 
    ///
    /// Example:
    /// nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5, 
    /// Result: [3, 9, 15, 33]
    /// 
    /// nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5. 
    /// Result: [-23, -5, 1, 7]
    /// </summary>
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c);

    /// <summary>
    /// Leet code #343. Integer Break
    /// 
    /// Given a positive integer n, break it into the sum of at least two 
    /// positive integers and maximize the product of those integers. 
    /// Return the maximum product you can get.
    ///
    /// Example 1:
    ///
    /// Input: 2
    /// Output: 1
    /// Explanation: 2 = 1 + 1, 1 × 1 = 1.
    ///
    /// Example 2:
    ///
    /// Input: 10
    /// Output: 36
    /// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
    /// Note: You may assume that n is not less than 2 and not larger than 58.
    /// </summary>
    int integerBreak(int n);

    /// <summary>
    /// Leet code #38. Count and Say 
    ///
    /// The count-and-say sequence is the sequence of integers beginning as follows:
    /// 1, 11, 21, 1211, 111221, ...  
    /// 1 is read off as "one 1" or 11. 
    /// 11 is read off as "two 1s" or 21.
    /// 21 is read off as "one 2, then one 1" or 1211.
    /// Given an integer n, generate the nth sequence.	
    /// Note: The sequence of integers will be represented as a string. 
    /// </summary>
    string countAndSay(int n);

    /// <summary>
    /// Leet code #391. Perfect Rectangle
    ///
    /// Given N axis-aligned rectangles where N > 0, determine if they all 
    /// together form an exact cover of a rectangular region. 
    /// Each rectangle is represented as a bottom-left point and a top-right point. 
    /// For example, a unit square is represented as [1,1,2,2]. 
    /// (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)). 
    /// Example 1: 
    /// rectangles = 
    /// [
    ///   [1,1,3,3],
    ///   [3,1,4,2],
    ///   [3,2,4,4],
    ///   [1,3,2,4],
    ///   [2,3,3,4]
    /// ]
    /// Return true. All 5 rectangles together form an exact cover of a 
    /// rectangular region.
    /// Example 2: 
    /// rectangles = 
    /// [
    ///   [1,1,2,3],
    ///   [1,3,2,4],
    ///   [3,1,4,2],
    ///   [3,2,4,4]
    /// ]
    /// Return false. Because there is a gap between the two rectangular regions.
    /// Example 3: 
    /// rectangles = 
    /// [
    ///   [1,1,3,3],
    ///   [3,1,4,2],
    ///   [1,3,2,4],
    ///   [3,2,4,4]
    /// ]
    /// Return false. Because there is a gap in the top center.
    /// Example 4: 
    /// rectangles = 
    /// [
    ///   [1,1,3,3],
    ///   [3,1,4,2],
    ///   [1,3,2,4],
    ///   [2,2,4,4]
    /// ]
    /// Return false. Because two of the rectangles overlap with each other.
    /// </summary>
    bool isRectangleCover(vector<vector<int>>& rectangles);

    /// <summary>
    /// Leet code #458. Poor Pigs
    /// 
    /// There are 1000 buckets, one and only one of them is poisonous, while 
    /// the rest are filled with water. They all look identical. If a pig 
    /// drinks the poison it will die within 15 minutes. What is the minimum 
    /// amount of pigs you need to figure out which bucket is poisonous within 
    /// one hour?
    /// 
    /// Answer this question, and write an algorithm for the general case.
    ///
    /// General case:
    ///
    /// If there are n buckets and a pig drinking poison will die within m 
    /// minutes, how many pigs (x) you need to figure out the poisonous bucket 
    /// within p minutes? There is exactly one bucket with poison.
    ///
    /// Note:
    ///
    /// A pig can be allowed to drink simultaneously on as many buckets as one 
    /// would like, and the feeding takes no time.
    /// After a pig has instantly finished drinking buckets, there has to be a 
    /// cool down time of m minutes. During this time, only observation is 
    /// allowed and no feedings at all.
    /// Any given bucket can be sampled an infinite number of times 
    /// (by an unlimited number of pigs).
    /// </summary>
    int poorPigs(int buckets, int minutesToDie, int minutesToTest);

    /// <summary>
    /// Leet code #492. Construct the Rectangle       
    /// 
    /// For a web developer, it is very important to know how to design a 
    /// web page's size. 
    /// So, given a specific rectangular web page’s area, your job by now is 
    /// to design a rectangular web page, whose length L and width W satisfy 
    /// the following requirements:
    ///
    /// 1. The area of the rectangular web page you designed must equal to the 
    ///    given target area.
    /// 2. The width W should not be larger than the length L, which 
    ///    means L >= W.
    ///	3. The difference between length L and width W should be as small as 
    ///   possible.
    /// 
    /// You need to output the length L and the width W of the web page you 
    /// designed in sequence. 
    ///
    /// Example:
    /// 
    /// Input: 4
    /// Output: [2, 2]
    /// Explanation: The target area is 4, and all the possible ways to 
    /// construct it are [1,4], [2,2], [4,1]. 
    /// But according to requirement 2, [1,4] is illegal; according to 
    /// requirement 3, [4,1] is not optimal compared to [2,2]. So the length L 
    /// is 2, and the width W is 2.
    ///
    /// Note:
    /// 1.The given area won't exceed 10,000,000 and is a positive integer
    /// 2.The web page's width and length you designed must be positive integers.
    /// </summary>
    vector<int> constructRectangle(int area);

    /// <summary>
    /// Leet code #504. Base 7         
    /// 
    /// Given an integer, return its base 7 string representation.
    /// Example 1:
    /// Input: 100
    /// Output: "202"
    ///
    /// Example 2:
    /// Input: -7
    /// Output: "-10"
    ///
    /// Note: The input will be in range of [-1e7, 1e7]. 
    /// </summary>
    string convertToBase7(int num);

    /// <summary>
    /// Leet code #509. Fibonacci Number
    /// 
    /// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the 
    /// Fibonacci sequence, such that each number is the sum of the two preceding 
    /// ones, starting from 0 and 1. That is,
    ///
    /// F(0) = 0,   F(1) = 1
    /// F(N) = F(N - 1) + F(N - 2), for N > 1.
    /// Given N, calculate F(N).
    ///
    /// Example 1:
    ///
    /// Input: 2
    /// Output: 1
    /// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
    ///
    /// Example 2:
    /// Input: 3
    /// Output: 2
    /// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
    ///
    /// Example 3:
    /// Input: 4
    /// Output: 3
    /// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
    ///  
    /// Note:
    /// 1. 0 ≤ N ≤ 30.
    /// </summary>
    int fib(int N);

    /// <summary>
    /// Leet code #587. Erect the Fence          
    /// </summary>
    int orientation(Point p, Point q, Point r);

    /// <summary>
    /// Leet code #587. Erect the Fence          
    /// 
    /// There are some trees, where each tree is represented by (x,y) coordinate 
    /// in a two-dimensional garden. Your job is to fence the entire garden 
    /// using the minimum length of rope as it is expensive. The garden is well 
    /// fenced only if all the trees are enclosed. Your task is to help find the 
    /// coordinates of trees which are exactly located on the fence perimeter.
    ///
    /// Example 1:
    /// Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
    /// Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
    /// Explanation:
    ///
    /// Example 2:
    /// Input: [[1,2],[2,2],[4,2]]
    /// Output: [[1,2],[2,2],[4,2]]
    /// Explanation:
    ///
    /// Even you only have trees in a line, you need to use rope to enclose them. 
    ///
    /// Note: 
    /// 1. All trees should be enclosed together. You cannot cut the rope to enclose 
    ///    trees that will separate them in more than one group.
    /// 2. All input integers will range from 0 to 100. 
    /// 3. The garden has at least one tree. 
    /// 4. All coordinates are distinct. 
    /// 5. Input points have NO order. No order required for output.
    /// </summary>
    vector<Point> outerTrees(vector<Point>& points);

    /// <summary>
    /// Leet code #593. Valid Square 
    /// </summary>
    int distance_square(vector<int>& p1, vector<int>& p2);

    /// <summary>
    /// Leet code #593. Valid Square 
    ///
    /// Given the coordinates of four points in 2D space, return whether the 
    /// four points could construct a square.
    /// The coordinate (x,y) of a point is represented by an integer array 
    /// with two integers.
    ///
    /// Example:
    /// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
    /// Output: True
    /// Note:
    /// All the input integers are in the range [-10000, 10000].
    /// A valid square has four equal sides with positive length and four 
    /// equal angles (90-degree angles).
    /// Input points have no order.
    /// </summary>
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4);

    /// <summary>
    /// Leet code #611. Valid Triangle Number
    /// 
    /// Given an array consists of non-negative integers, your task is to 
    /// count the number of triplets chosen from the array that can make 
    /// triangles if we take them as side lengths of a triangle. 
    ///
    /// Example 1:
    ///
    /// Input: [2,2,3,4]
    /// Output: 3
    /// Explanation:
    /// Valid combinations are: 
    /// 2,3,4 (using the first 2)
    /// 2,3,4 (using the second 2)
    /// 2,2,3
    /// Note:
    /// 1.The length of the given array won't exceed 1000.
    /// 2.The integers in the given array are in the range of [0, 1000].
    /// </summary>
    int triangleNumber(vector<int>& nums);

    /// <summary>
    /// Leet code #812. Largest Triangle Area
    /// 
    /// You have a list of points in the plane. Return the area of the largest 
    /// triangle that can be formed by any 3 of the points.
    /// 
    /// Example:
    /// Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
    /// Output: 2
    /// Explanation: 
    /// The five points are show in the figure below. The red triangle is the 
    /// largest.
    ///
    /// Notes:
    /// 1. 3 <= points.length <= 50.
    /// 2. No points will be duplicated.
    /// 3. -50 <= points[i][j] <= 50.
    /// 4. Answers within 10^-6 of the true value will be accepted as correct.
    /// </summary>
    double largestTriangleArea(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #858. Mirror Reflection
    /// 
    /// There is a special square room with mirrors on each of the four walls.  
    /// Except for the southwest corner, there are receptors on each of the 
    /// remaining corners, numbered 0, 1, and 2.
    ///
    /// The square room has walls of length p, and a laser ray from the southwest 
    /// corner first meets the east wall at a distance q from the 0th receptor.
    ///
    /// Return the number of the receptor that the ray meets first.  (It is 
    /// guaranteed that the ray will meet a receptor eventually.)
    ///
    /// Example 1:
    ///
    /// Input: p = 2, q = 1
    /// Output: 2
    /// Explanation: The ray meets receptor 2 the first time it gets reflected 
    /// back to the left wall.
    ///
    /// Note:
    /// 1. 1 <= p <= 1000
    /// 2. 0 <= q <= p
    /// </summary>
    int mirrorReflection(int p, int q);

    /// <summary>
    /// Leet code #866. Prime Palindrome
    /// </summary>
    bool isPrime(int N);

    /// <summary>
    /// Leet code #866. Prime Palindrome
    /// 
    /// Find the smallest prime palindrome greater than or equal to N.
    ///
    /// Recall that a number is prime if it's only divisors are 1 and itself, 
    /// and it is greater than 1. 
    ///
    /// For example, 2,3,5,7,11 and 13 are primes.
    ///
    /// Recall that a number is a palindrome if it reads the same from left 
    /// to right as it does from right to left. 
    ///
    /// For example, 12321 is a palindrome.
    ///
    /// Example 1:
    /// Input: 6
    /// Output: 7
    ///
    /// Example 2:
    /// Input: 8
    /// Output: 11
    ///
    /// Example 3:
    /// Input: 13
    /// Output: 101
    ///
    /// Note:
    /// 
    /// 1. 1 <= N <= 10^8
    /// 2. The answer is guaranteed to exist and be less than 2 * 10^8.
    /// </summary>
    int primePalindrome(int N);

    /// <summary>
    /// Leet code #869. Reordered Power of 2
    /// 
    /// Starting with a positive integer N, we reorder the digits in any order 
    /// (including the original order) such that the leading digit is not zero.
    ///
    /// Return true if and only if we can do this in a way such that the 
    /// resulting number is a power of 2.
    ///
    /// Example 1:
    /// Input: 1
    /// Output: true
    ///
    /// Example 2:
    /// Input: 10
    /// Output: false
    ///
    /// Example 3:
    /// Input: 16
    /// Output: true
    ///
    /// Example 4:
    /// Input: 24
    /// Output: false
    ///
    /// Example 5:
    /// Input: 46
    /// Output: true
    ///  
    /// Note:
    /// 1. 1 <= N <= 10^9
    /// </summary>
    bool reorderedPowerOf2(int N);

    /// <summary>
    /// Leet code #906. Super Palindromes
    /// 
    /// Let's say a positive integer is a superpalindrome if it is a palindrome, 
    /// and it is also the square of a palindrome.
    ///
    /// Now, given two positive integers L and R (represented as strings), return 
    /// the number of superpalindromes in the inclusive range [L, R].
    /// 
    /// Example 1:
    /// Input: L = "4", R = "1000"
    /// Output: 4
    /// Explanation: 4, 9, 121, and 484 are superpalindromes.
    /// Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a 
    /// palindrome.
    ///  
    /// Note:
    /// 1. 1 <= len(L) <= 18
    /// 2. 1 <= len(R) <= 18
    /// 3. L and R are strings representing integers in the range [1, 10^18).
    /// 4. int(L) <= int(R)
    /// </summary>
    int superpalindromesInRange(string L, string R);

    /// <summary>
    /// Leet code #949. Largest Time for Given Digits
    /// 
    /// Given an array of 4 digits, return the largest 24 hour time that can 
    /// be made.
    ///
    /// The smallest 24 hour time is 00:00, and the largest is 23:59.  
    /// Starting from 00:00, a time is larger if more time has elapsed since 
    /// midnight.
    /// 
    /// Return the answer as a string of length 5.  If no valid time can be 
    /// made, return an empty string.
    ///
    /// Example 1:
    ///
    /// Input: [1,2,3,4]
    /// Output: "23:41"
    ///
    /// Example 2:
    ///
    /// Input: [5,5,5,5]
    /// Output: ""
    /// 
    /// Note:
    ///
    /// 1. A.length == 4
    /// 2. 0 <= A[i] <= 9
    /// </summary>
    string largestTimeFromDigits(vector<int>& A);

    /// <summary>
    /// Leet code #976. Largest Perimeter Triangle
    /// 
    /// Given an array A of positive lengths, return the largest perimeter of a 
    /// triangle with non-zero area, formed from 3 of these lengths.
    ///
    /// If it is impossible to form any triangle of non-zero area, return 0.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: [2,1,2]
    /// Output: 5
    ///
    /// Example 2:
    ///
    /// Input: [1,2,1]
    /// Output: 0
    ///
    /// Example 3:
    ///
    /// Input: [3,2,3,4]
    /// Output: 10
    ///
    /// Example 4:
    ///
    /// Input: [3,6,2,3]
    /// Output: 8
    /// 
    /// Note:
    /// 
    /// 1. 3 <= A.length <= 10000
    /// 2. 1 <= A[i] <= 10^6
    /// </summary>
    int largestPerimeter(vector<int>& A);

    /// <summary>
     /// Leet code #991. Broken Calculator
     /// 
     /// On a broken calculator that has a number showing on its display, 
     /// we can perform two operations:
     ///
     /// Double: Multiply the number on the display by 2, or;
     /// Decrement: Subtract 1 from the number on the display.
     /// Initially, the calculator is displaying the number X.
     ///
     /// Return the minimum number of operations needed to display the number Y.
     /// 
     /// Example 1:
     /// Input: X = 2, Y = 3
     /// Output: 2
     /// Explanation: Use double operation and then decrement 
     /// operation {2 -> 4 -> 3}.
     ///
     /// Example 2:
     /// Input: X = 5, Y = 8
     /// Output: 2
     /// Explanation: Use decrement and then double {5 -> 4 -> 8}.
     ///
     /// Example 3:
     /// Input: X = 3, Y = 10
     /// Output: 3
     /// Explanation:  Use double, decrement and double {3 -> 6 -> 5 -> 10}.
     ///
     /// Example 4:
     /// Input: X = 1024, Y = 1
     /// Output: 1023
     /// Explanation: Use decrement operations 1023 times.
     ///
     /// Note:
     /// 1. 1 <= X <= 10^9
     /// 2. 1 <= Y <= 10^9
     /// </summary>
    int brokenCalc(int X, int Y);

    /// <summary>
    /// Leet code #963. Minimum Area Rectangle II
    /// 
    /// Given a set of points in the xy-plane, determine the minimum area of any 
    /// rectangle formed from these points, with sides not necessarily parallel 
    /// to the x and y axes.
    ///
    /// If there isn't any rectangle, return 0.
    /// 
    /// Example 1:
    /// Input: [[1,2],[2,1],[1,0],[0,1]]
    /// Output: 2.00000
    /// Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], 
    /// with an area of 2.
    ///
    /// Example 2:
    /// Input: [[0,1],[2,1],[1,1],[1,0],[2,0]]
    /// Output: 1.00000
    /// Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], 
    /// with an area of 1.
    ///
    /// Example 3:
    /// Input: [[0,3],[1,2],[3,1],[1,3],[2,1]]
    /// Output: 0
    /// Explanation: There is no possible rectangle to form from these points.
    ///
    /// Example 4:
    /// Input: [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
    /// Output: 2.00000
    /// Explanation: The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], 
    /// with an area of 2.
    ///
    /// Note:
    /// 1. 1 <= points.length <= 50
    /// 2. 0 <= points[i][0] <= 40000
    /// 3. 0 <= points[i][1] <= 40000
    /// 4. All points are distinct.
    /// 5. Answers within 10^-5 of the actual value will be accepted as correct.
    /// </summary>
    double minAreaFreeRect(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #1266. Minimum Time Visiting All Points
    /// 
    /// On a plane there are n points with integer coordinates 
    /// points[i] = [xi, yi]. Your task is to find the minimum time in 
    /// seconds to visit all points.
    ///
    /// You can move according to the next rules:
    ///
    /// In one second always you can either move vertically, horizontally 
    /// by one unit or diagonally (it means to move one unit vertically and 
    /// one unit horizontally in one second).
    /// You have to visit the points in the same order as they appear in the 
    /// array.
    ///
    /// Example 1:
    /// 
    /// Input: points = [[1,1],[3,4],[-1,0]]
    /// Output: 7
    /// Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> 
    /// [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
    /// Time from [1,1] to [3,4] = 3 seconds 
    /// Time from [3,4] to [-1,0] = 4 seconds
    /// Total time = 7 seconds
    ///
    /// Example 2:
    ///
    /// Input: points = [[3,2],[-2,2]]
    /// Output: 5
    /// 
    /// Constraints:
    /// 1. points.length == n
    /// 2. 1 <= n <= 100
    /// 3. points[i].length == 2
    /// 4. -1000 <= points[i][0], points[i][1] <= 1000
    /// </summary>
    int minTimeToVisitAllPoints(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #1271. Hexspeak
    /// 
    /// A decimal number can be converted to its Hexspeak representation by 
    /// first converting it to an uppercase hexadecimal string, then 
    /// replacing all occurrences of the digit 0 with the letter O, and the
    /// digit 1 with the letter I.  Such a representation is valid if and 
    /// only if it consists only of the letters in the set {"A", "B", "C",
    /// "D", "E", "F", "I", "O"}.
    ///
    /// Given a string num representing a decimal integer N, return the 
    ///  Hexspeak representation of N if it is valid, otherwise return "ERROR".
    /// 
    /// Example 1:
    ///
    /// Input: num = "257"
    /// Output: "IOI"
    /// Explanation:  257 is 101 in hexadecimal.
    ///
    /// Example 2:
    ///
    /// Input: num = "3"
    /// Output: "ERROR"
    ///
    /// Constraints:
    /// 1. 1 <= N <= 10^12
    /// 2. There are no leading zeros in the given string.
    /// 3. All answers must be in uppercase letters.
    /// </summary>
    string toHexspeak(string num);

    /// <summary>
    /// Leetcode #1276. Number of Burgers with No Waste of Ingredients
    /// 
    /// Given two integers tomatoSlices and cheeseSlices. The ingredients 
    /// of different burgers are as follows:
    ///
    /// Jumbo Burger: 4 tomato slices and 1 cheese slice.
    /// Small Burger: 2 Tomato slices and 1 cheese slice.
    /// Return [total_jumbo, total_small] so that the number of remaining 
    /// tomatoSlices equal to 0 and the number of remaining cheeseSlices 
    /// equal to 0. If it is not possible to make the remaining tomatoSlices 
    /// and cheeseSlices equal to 0 return [].
    ///
    ///
    /// Example 1:
    /// Input: tomatoSlices = 16, cheeseSlices = 7
    /// Output: [1,6]
    /// Explantion: To make one jumbo burger and 6 small burgers we 
    /// need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese. There will be no 
    /// remaining ingredients.
    ///
    /// Example 2:
    ///
    /// Input: tomatoSlices = 17, cheeseSlices = 4
    /// Output: []
    /// Explantion: There will be no way to use all ingredients to make small 
    /// and jumbo burgers.
    ///
    /// Example 3:
    ///
    /// Input: tomatoSlices = 4, cheeseSlices = 17
    /// Output: []
    /// Explantion: Making 1 jumbo burger there will be 16 cheese remaining 
    /// and making 2 small burgers there will be 15 cheese remaining.
    ///
    /// Example 4:
    ///
    /// Input: tomatoSlices = 0, cheeseSlices = 0
    /// Output: [0,0]
    ///
    /// Example 5:
    ///
    /// Input: tomatoSlices = 2, cheeseSlices = 1
    /// Output: [0,1]
    /// 
    /// Constraints:
    /// 1. 0 <= tomatoSlices <= 10^7
    /// 2. 0 <= cheeseSlices <= 10^7
    /// </summary>
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices);

    /// <summary>
    /// Leet code #412. Fizz Buzz 
    /// Write a program that outputs the string representation of numbers from 1 to n.
    /// But for multiples of three it should output 揊izz?instead of the number and for the multiples of five output 揃uzz? 
    /// For numbers which are multiples of both three and five output 揊izzBuzz?
    /// Example: 
    /// Return:
    /// [
    ///    "1",
    ///    "2",
    ///    "Fizz",
    ///    "4",
    ///    "Buzz",
    ///    "Fizz",
    ///    "7",
    ///    "8",
    ///    "Fizz",
    ///    "Buzz",
    ///    "11",
    ///    "Fizz",
    ///    "13",
    ///    "14",
    ///    "FizzBuzz"
    /// ]
    /// </summary>
    vector<string> fizzBuzz(int n);

    /// <summary>
    /// Leet code #453. Minimum Moves to Equal Array Elements
    ///
    /// Given a non-empty integer array of size n, find the minimum number 
    /// of moves required to make all 
    /// array elements equal, where a move is incrementing n - 1 elements by 1. 
    ///
    /// Example: 
    /// Input:
    /// [1,2,3] 
    /// Output:
    /// 3
    /// 
    /// Explanation:
    /// Only three moves are needed (remember each move increments two elements):
    /// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
    /// </summary>
    int minMoves(vector<int>& nums);

    /// <summary>
    /// Leet code #462. Minimum Moves to Equal Array Elements II   
    /// Given a non-empty integer array, find the minimum number of moves 
    /// required to make all 
    /// array elements equal, where a move is incrementing a selected 
    /// element by 1 or decrementing 
    /// a selected element by 1.
    /// You may assume the array's length is at most 10,000.  
    ///
    /// Example: 
    /// Input:
    /// [1,2,3]
    /// Output:
    /// 2
    /// Explanation:
    /// Only two moves are needed (remember each move increments or decrements one element):
    /// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
    /// </summary>
    int minMoves2(vector<int>& nums);

    /// <summary>
    /// Leet code #326. Power of Three    
    /// Given an integer, write a function to determine if it is a power 
    /// of three. 
    /// Follow up:
    /// Could you do it without using any loop / recursion? 
    /// </summary>
    bool isPowerOfThree(int n);

    /// <summary>
    /// Leet code #625. Minimum Factorization
    /// 
    /// Given a positive integer a, find the smallest positive integer b whose 
    /// multiplication of each digit equals to a. 
    ///
    /// If there is no answer or the answer is not fit in 32-bit signed 
    /// integer, then return 0.
    ///
    /// Example 1
    /// Input: 48 
    /// Output: 68
    ///
    /// Example 2
    /// Input: 15
    /// Output: 35
    /// </summary>
    int smallestFactorization(int a);

    /// <summary>
    /// Leet code #633. Sum of Square Numbers
    /// 
    /// Given a non-negative integer c, your task is to decide whether 
    /// there're two integers a and b such that a^2 + b^2 = c. 
    /// Example 1:
    /// Input: 5
    /// Output: True
    ///
    /// Explanation: 1 * 1 + 2 * 2 = 5
    /// Example 2:
    /// Input: 3
    /// Output: False
    /// </summary>
    bool judgeSquareSum(int c);

    /// <summary>
    /// Leet code #479. Largest Palindrome Product 
    /// 
    /// Find the largest palindrome made from the product of two n-digit 
    /// numbers. 
    /// Since the result could be very large, you should return the largest 
    /// palindrome mod 1337.
    /// Example: 
    /// Input: 2
    /// Output: 987
    /// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987 
    ///
    /// Note: 
    /// The range of n is [1,8].
    /// </summary>
    int largestPalindrome(int n);

    /// <summary>
    /// Leet code #657. Judge Route Circle 
    /// 
    /// Initially, there is a Robot at position (0, 0). Given a sequence of 
    /// its moves, judge if this robot makes a circle, which means it moves 
    /// back to the original place. 
    /// The move sequence is represented by a string. And each move is 
    /// represent by a character. The valid robot moves are R (Right), 
    /// L (Left), U (Up) and D (down). The output should be true or false 
    /// representing whether the robot makes a circle. 
    /// Example 1:
    /// Input: "UD"
    /// Output: true
    ///
    /// Example 2:
    /// Input: "LL"
    /// Output: false
    /// </summary>
    bool judgeCircle(string moves);

    /// <summary>
    /// Leet code #754. Reach a Number    
    /// You are standing at position 0 on an infinite number line. There is a 
    /// goal at position target.
    ///
    /// On each move, you can either go left or right. During the n-th move 
    /// (starting from 1), you take n steps.
    /// 
    /// Return the minimum number of steps required to reach the destination.
    ///
    /// Example 1:
    /// Input: target = 3
    /// Output: 2
    /// Explanation:
    /// On the first move we step from 0 to 1.
    /// On the second step we step from 1 to 3.
    /// Example 2:
    /// Input: target = 2
    /// Output: 3
    /// Explanation:
    /// On the first move we step from 0 to 1.
    /// On the second move we step  from 1 to -1.
    /// On the third move we step from -1 to 2.
    /// Note:
    /// 1. target will be a non-zero integer in the range [-10^9, 10^9].
    /// </summary>
    int reachNumber(int target);

    /// <summary>
    /// Leet code #781. Rabbits in Forest    
    ///
    /// In a forest, each rabbit has some color. Some subset of rabbits 
    /// (possibly all of them) tell you how many other rabbits have the 
    /// same color as them. Those answers are placed in an array.
    ///
    /// Return the minimum number of rabbits that could be in the forest.
    ///
    /// Examples:
    /// Input: answers = [1, 1, 2]
    /// Output: 5
    /// Explanation:
    /// The two rabbits that answered "1" could both be the same color, 
    /// say red.
    /// The rabbit than answered "2" can't be red or the answers would be 
    /// inconsistent.
    /// Say the rabbit that answered "2" was blue.
    /// Then there should be 2 other blue rabbits in the forest that didn't 
    /// answer into the array.
    /// The smallest possible number of rabbits in the forest is therefore 
    /// 5: 3 that answered plus 2 that didn't.
    ///
    /// Input: answers = [10, 10, 10]
    /// Output: 11
    ///
    /// Input: answers = []
    /// Output: 0
    /// Note:
    ///
    /// 1. answers will have length at most 1000.
    /// 2. Each answers[i] will be an integer in the range [0, 999].
    /// </summary>
    int numRabbits(vector<int>& answers);

    /// <summary>
    /// Leet code #794. Valid Tic-Tac-Toe State
    ///
    /// A Tic-Tac-Toe board is given as a string array board. Return True if 
    /// and only if it is possible to reach this board position during the 
    /// course of a valid tic-tac-toe game.
    ///
    /// The board is a 3 x 3 array, and consists of characters " ", "X", and 
    /// "O".  The " " character represents an empty square.
    ///
    /// Here are the rules of Tic-Tac-Toe:
    ///
    /// Players take turns placing characters into empty squares (" ").
    /// The first player always places "X" characters, while the second player
    /// always places "O" characters.
    /// "X" and "O" characters are always placed into empty squares, never 
    /// filled ones.
    /// The game ends when there are 3 of the same (non-empty) character 
    /// filling any row, column, or diagonal.
    /// The game also ends if all squares are non-empty.
    /// No more moves can be played if the game is over.
    /// Example 1:
    /// Input: board = ["O  ", "   ", "   "]
    /// Output: false
    /// Explanation: The first player always plays "X".
    ///
    /// Example 2:
    /// Input: board = ["XOX", " X ", "   "]
    /// Output: false
    /// Explanation: Players take turns making moves.
    ///
    /// Example 3:
    /// Input: board = ["XXX", "   ", "OOO"]
    /// Output: false
    ///
    /// Example 4:
    /// Input: board = ["XOX", "O O", "XOX"]
    /// Output: true
    /// Note:
    ///
    /// board is a length-3 array of strings, where each string board[i] has 
    /// length 3.
    /// Each board[i][j] is a character in the set {" ", "X", "O"}.
    /// </summary>
    bool validTicTacToe(vector<string>& board);

    /// <summary>
    /// Leet code #728. Self Dividing Numbers      
    /// 
    /// A self-dividing number is a number that is divisible by every digit it 
    /// contains.
    ///
    /// For example, 128 is a self-dividing number because 128 % 1 == 0, 
    /// 128 % 2 == 0, and 128 % 8 == 0.
    ///
    /// Also, a self-dividing number is not allowed to contain the digit zero.
    ///
    /// Given a lower and upper number bound, output a list of every possible 
    /// self dividing number, including the bounds if possible.
    ///
    /// Example 1:
    /// Input: 
    /// left = 1, right = 22
    /// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
    /// Note:    
    /// 1. The boundaries of each input argument are 1 <= left <= right <= 10000.
    /// </summary>
    vector<int> selfDividingNumbers(int left, int right);

    /// <summary>
    /// Leet code #782. Transform to Chessboard    
    /// </summary>
    void countBoardPattern(int row, int col, vector<vector<int>>& board, int& pattern, int& one);

    /// <summary>
    /// Leet code #782. Transform to Chessboard    
    /// </summary>
    bool checkBoardPattern(int one, int N);

    /// <summary>
    /// Leet code #782. Transform to Chessboard    
    /// </summary>
    bool checkBoardPatternMap(unordered_set<int>& pattern_map);

    /// <summary>
    /// Leet code #782. Transform to Chessboard    
    /// </summary>
    int calculateBoardPattern(int pattern, int N);

    /// <summary>
    /// Leet code #782. Transform to Chessboard    
    ///
    /// An N x N board contains only 0s and 1s. In each move, you can swap 
    /// any 2 rows with each other, or any 2 columns with each other.
    ///
    /// What is the minimum number of moves to transform the board into a 
    /// "chessboard" - a board where no 0s and no 1s are 4-directionally 
    /// adjacent? If the task is impossible, return -1.
    ///
    /// Examples:
    /// Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
    /// Output: 2
    /// Explanation:
    /// One potential sequence of moves is shown below, from left to right:
    ///
    /// 0110     1010     1010
    /// 0110 --> 1010 --> 0101
    /// 1001     0101     1010
    /// 1001     0101     0101
    ///
    /// The first move swaps the first and second column.
    /// The second move swaps the second and third row.
    ///
    /// Input: board = [[0, 1], [1, 0]]
    /// Output: 0
    /// Explanation:
    /// Also note that the board with 0 in the top left corner,
    /// 01
    /// 10
    ///
    /// is also a valid chessboard.
    /// 
    /// Input: board = [[1, 0], [1, 0]]
    /// Output: -1
    /// Explanation:
    /// No matter what sequence of moves you make, you cannot end with a valid 
    /// chessboard.
    /// 
    /// Note:
    /// 1. board will have the same number of rows and columns, a number in the 
    ///    range [2, 30].
    /// 2. board[i][j] will be only 0s or 1s.
    /// </summary>
    int movesToChessboard(vector<vector<int>>& board);

    /// <summary>
    /// Leet code #789. Escape The Ghosts
    /// 
    /// You are playing a simplified Pacman game. You start at the point 
    /// (0, 0), and your destination is (target[0], target[1]). There are 
    /// several ghosts on the map, the i-th ghost starts at (ghosts[i][0], 
    /// ghosts[i][1]).
    /// Each turn, you and all ghosts simultaneously *may* move in one of 
    /// 4 cardinal directions: north, east, west, or south, going from the 
    /// previous point to a new point 1 unit of distance away.
    /// You escape if and only if you can reach the target before any ghost 
    /// reaches you (for any given moves the ghosts may take.)  If you reach 
    /// any square (including the target) at the same time as a ghost, it 
    /// doesn't count as an escape.
    /// Return True if and only if it is possible to escape.
    /// Example 1:
    /// Input: 
    /// ghosts = [[1, 0], [0, 3]]
    /// target = [0, 1]
    /// Output: true
    /// Explanation: 
    /// You can directly reach the destination (0, 1) at time 1, while the 
    /// ghosts located at (1, 0) or (0, 3) have no way to catch up with you.
    /// Example 2:
    /// Input: 
    /// ghosts = [[1, 0]]
    /// target = [2, 0]
    /// Output: false
    /// Explanation: 
    /// You need to reach the destination (2, 0), but the ghost at (1, 0) 
    /// lies between you and the destination.
    /// Example 3:
    /// Input: 
    /// ghosts = [[2, 0]]
    /// target = [1, 0]
    /// Output: false
    /// Explanation: 
    /// The ghost can reach the target at the same time as you.
    /// Note:
    /// 1. All points have coordinates with absolute value <= 10000.
    /// 2. The number of ghosts will not exceed 100.
    /// </summary>
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target);

    /// <summary>
    /// Leet code #829. Consecutive Numbers Sum
    /// 
    /// Given a positive integer N, how many ways can we write it as a sum of 
    /// consecutive positive integers?
    ///
    /// Example 1:
    /// Input: 5
    /// Output: 2
    /// Explanation: 5 = 5 = 2 + 3
    ///
    /// Example 2:
    /// Input: 9
    /// Output: 3
    /// Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
    /// 
    /// Example 3:
    /// Input: 15
    /// Output: 4
    /// Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
    ///
    /// 1. Note: 1 <= N <= 10 ^ 9.
    /// </summary>
    int consecutiveNumbersSum(int N);

    /// <summary>
    /// Leet code #836. Rectangle Overlap
    /// 
    /// A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) 
    /// are the coordinates of its bottom-left corner, and (x2, y2) are the 
    /// coordinates of its top-right corner.
    ///
    /// Two rectangles overlap if the area of their intersection is positive.  
    /// To be clear, two rectangles that only touch at the corner or edges do 
    /// not overlap.
    ///
    /// Given two rectangles, return whether they overlap.
    ///
    /// Example 1:
    ///
    /// Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
    /// Output: true
    ///
    /// Example 2:
    ///
    /// Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
    /// Output: false
    /// Notes:
    ///
    /// Both rectangles rec1 and rec2 are lists of 4 integers.
    /// All coordinates in rectangles will be between -10^9 and 10^9.
    /// </summary>
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2);

    /// <summary>
    /// Leet code #910. Smallest Range II
    /// 
    /// Given an array A of integers, for each integer A[i] we need to choose 
    /// either x = -K or x = K, and add x to A[i] (only once).
    ///
    /// After this process, we have some array B.
    ///
    /// Return the smallest possible difference between the maximum value of B 
    /// and the minimum value of B.
    ///
    /// Example 1:
    /// Input: A = [1], K = 0
    /// Output: 0
    /// Explanation: B = [1]
    ///
    /// Example 2:
    /// Input: A = [0,10], K = 2
    /// Output: 6
    /// Explanation: B = [2,8]
    ///
    /// Example 3:
    /// 
    /// Input: A = [1,3,6], K = 3
    /// Output: 3
    /// Explanation: B = [4,6,3]
    /// 
    /// Note:
    /// 
    /// 1. 1 <= A.length <= 10000
    /// 2. 0 <= A[i] <= 10000
    /// 3. 0 <= K <= 10000
    /// </summary>
    int smallestRangeII(vector<int>& A, int K);

    /// <summary>
    /// Leet code #970. Powerful Integers
    /// 
    /// Given two non-negative integers x and y, an integer is powerful if it is 
    /// equal to x^i + y^j for some integers i >= 0 and j >= 0.
    ///
    /// Return a list of all powerful integers that have value less than or equal 
    /// to bound.
    ///
    /// You may return the answer in any order.  In your answer, each value should 
    /// occur at most once.
    ///
    /// Example 1:
    /// Input: x = 2, y = 3, bound = 10
    /// Output: [2,3,4,5,7,9,10]
    /// Explanation: 
    /// 2 = 2^0 + 3^0
    /// 3 = 2^1 + 3^0
    /// 4 = 2^0 + 3^1
    /// 5 = 2^1 + 3^1
    /// 7 = 2^2 + 3^1
    /// 9 = 2^3 + 3^0
    /// 10 = 2^0 + 3^2
    ///
    /// Example 2:
    ///
    /// Input: x = 3, y = 5, bound = 15
    /// Output: [2,4,6,8,10,14]
    ///
    /// Note:
    ///
    /// 1. 1 <= x <= 100
    /// 2. 1 <= y <= 100
    /// 3. 0 <= bound <= 10^6
    /// </summary>
    vector<int> powerfulIntegers(int x, int y, int bound);

    /// <summary>
    /// Leet code #969. Pancake Sorting
    /// 
    /// Given an array A, we can perform a pancake flip: We choose some positive 
    /// integer k <= A.length, then reverse the order of the first k elements of A. 
    /// We want to perform zero or more pancake flips (doing them one after 
    /// another in succession) to sort the array A.
    ///
    /// Return the k-values corresponding to a sequence of pancake flips that 
    /// sort A.  Any valid answer that sorts the array within 10 * A.length flips 
    /// will be judged as correct.
    /// 
    /// Example 1:
    /// Input: [3,2,4,1]
    /// Output: [4,2,4,3]
    /// Explanation: 
    /// We perform 4 pancake flips, with k values 4, 2, 4, and 3.
    /// Starting state: A = [3, 2, 4, 1]
    /// After 1st flip (k=4): A = [1, 4, 2, 3]
    /// After 2nd flip (k=2): A = [4, 1, 2, 3]
    /// After 3rd flip (k=4): A = [3, 2, 1, 4]
    /// After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 
    ///
    /// Example 2:
    /// Input: [1,2,3]
    /// Output: []
    /// Explanation: The input is already sorted, so there is no need to flip 
    /// anything.
    /// Note that other answers, such as [3, 3], would also be accepted.
    /// 
    /// Note:
    /// 1. 1 <= A.length <= 100
    /// 2. A[i] is a permutation of [1, 2, ..., A.length]
    /// </summary>
    vector<int> pancakeSort(vector<int>& A);

    /// <summary>
    /// Leet code #1006. Clumsy Factorial
    /// </summary>
    int clumsyFactor(int& N, int& op);

    /// <summary>
    /// Leet code #1006. Clumsy Factorial
    /// 
    /// Normally, the factorial of a positive integer n is the product of all 
    /// positive integers less than or equal to n.  For example, factorial(10) 
    /// = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
    ///
    /// We instead make a clumsy factorial: using the integers in decreasing 
    /// order, we swap out the multiply operations for a fixed rotation of 
    /// operations: multiply (*), divide (/), add (+) and subtract (-) in this 
    /// order.
    ///
    /// For example, clumsy(10) = 10 * 9 / 8 + 7 - 
    /// 6 * 5 / 4 + 3 - 2 * 1.  However, these operations are still applied 
    /// using the usual order of operations of arithmetic: we do all 
    /// multiplication and division steps before any addition or subtraction 
    /// steps, and multiplication and division steps are processed left to 
    /// right.
    ///
    /// Additionally, the division that we use is floor division such that 
    /// 10 * 9 / 8 equals 11.  This guarantees the result is an integer.
    ///
    /// Implement the clumsy function as defined above: given an integer N, 
    /// it returns the clumsy factorial of N.
    ///
    /// Example 1:
    /// 
    /// Input: 4
    /// Output: 7
    /// Explanation: 7 = 4 * 3 / 2 + 1
    ///
    /// Example 2:
    /// 
    /// Input: 10
    /// Output: 12
    /// Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
    /// 
    /// Note:
    /// 1. 1 <= N <= 10000
    /// 2. -2^31 <= answer <= 2^31 - 1  (The answer is guaranteed to fit 
    ///    within a 32-bit integer.)
    /// </summary>
    int clumsy(int N);

    /// <summary>
    /// Leet code #1056. Confusing Number
    /// 
    /// Given a number N, return true if and only if it is a confusing number, 
    /// which satisfies the following condition:
    ///
    /// We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 
    /// are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 
    /// 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid. A confusing 
    /// number is a number that when rotated 180 degrees becomes a different 
    /// number with each digit valid.
    ///
    /// Example 1:
    ///
    /// Input: 6
    /// Output: true
    /// Explanation: 
    /// We get 9 after rotating 6, 9 is a valid number and 9!=6.
    ///
    /// Example 2:
    ///
    /// Input: 89
    /// Output: true
    /// Explanation: 
    /// We get 68 after rotating 89, 86 is a valid number and 86!=89.
    ///
    /// Example 3:
    ///
    /// Input: 11
    /// Output: false
    /// Explanation: 
    /// We get 11 after rotating 11, 11 is a valid number but the value remains 
    /// the same, thus 11 is not a confusing number.
    ///
    /// Example 4:
    ///
    /// Input: 25
    /// Output: false
    /// Explanation: 
    /// We get an invalid number after rotating 25.
    ///
    /// Note:
    /// 1. 0 <= N <= 10^9
    /// 2. After the rotation we can ignore leading zeros, for example if after 
    /// rotation we have 0008 then this number is considered as just 8.
    /// </summary>
    bool confusingNumber(int N);

    /// <summary>
    /// Leet code #1281. Subtract the Product and Sum of Digits of an Integer
    ///
    /// Easy
    ///
    /// Given an integer number n, return the difference between the product 
    /// of its digits and the sum of its digits. 
    ///
    /// Example 1:
    /// Input: n = 234
    /// Output: 15 
    /// Explanation: 
    /// Product of digits = 2 * 3 * 4 = 24 
    /// Sum of digits = 2 + 3 + 4 = 9 
    /// Result = 24 - 9 = 15
    ///
    /// Example 2:
    /// Input: n = 4421
    /// Output: 21
    /// Explanation: 
    /// Product of digits = 4 * 4 * 2 * 1 = 32 
    /// Sum of digits = 4 + 4 + 2 + 1 = 11 
    /// Result = 32 - 11 = 21
    /// </summary>
    int subtractProductAndSum(int n);

    /// <summary>
    /// Leet code #1291. Sequential Digits
    ///
    /// Medium
    ///
    /// An integer has sequential digits if and only if each digit in the 
    /// number is one more than the previous digit.
    ///
    /// Return a sorted list of all the integers in the range [low, high] 
    /// inclusive that have sequential digits.
    /// 
    /// Example 1:
    /// Input: low = 100, high = 300
    /// Output: [123,234]
    ///
    /// Example 2:
    /// Input: low = 1000, high = 13000
    /// Output: [1234,2345,3456,4567,5678,6789,12345]
    ///
    /// Constraints:
    /// 1. 10 <= low <= high <= 10^9
    /// </summary>
    vector<int> sequentialDigits(int low, int high);

    /// <summary>
    /// Leetcode #1295. Find Numbers with Even Number of Digits
    /// 
    /// Given an array nums of integers, return how many of them contain an 
    /// even number of digits.
    /// 
    /// Example 1:
    ///
    /// Input: nums = [12,345,2,6,7896]
    /// Output: 2
    /// Explanation: 
    /// 12 contains 2 digits (even number of digits). 
    /// 345 contains 3 digits (odd number of digits). 
    /// 2 contains 1 digit (odd number of digits). 
    /// 6 contains 1 digit (odd number of digits). 
    /// 7896 contains 4 digits (even number of digits). 
    /// Therefore only 12 and 7896 contain an even number of digits.
    ///
    /// Example 2:
    ///  
    /// Input: nums = [555,901,482,1771]
    /// Output: 1 
    /// Explanation: 
    /// Only 1771 contains an even number of digits.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 500
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int findNumbers(vector<int>& nums);

    /// <summary>
    /// Leet code #800. Similar RGB Color
    /// 
    /// In the following, every capital letter represents some hexadecimal 
    /// digit from 0 to f.
    ///
    /// The red-green-blue color "#AABBCC" can be written as "#ABC" in 
    /// shorthand.  For example, "#15c" is shorthand for the color "#1155cc".
    ///
    /// Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" 
    /// is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.
    ///
    /// Given the color "#ABCDEF", return a 7 character color that is most 
    /// similar to #ABCDEF, and has a shorthand (that is, it can be represented
    /// as some "#XYZ"
    ///
    /// Example 1:
    /// Input: color = "#09f166"
    /// Output: "#11ee66"
    /// Explanation:  
    /// The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 
    /// = -64 -9 -0 = -73.
    /// This is the highest among any shorthand color.
    /// Note:
    ///
    /// 1. color is a string of length 7.
    /// 2. color is a valid RGB color: for i > 0, color[i] is a hexadecimal 
    ///    digit from 0 to f
    /// 3. Any answer which has the same (highest) similarity as the best 
    ///    answer will be accepted.
    /// 4. All inputs and outputs should use lowercase letters, and the 
    ///    output is 7 characters.
    /// </summary>
    string similarRGB(string color);

    /// <summary>
    /// Leet code #810. Chalkboard XOR Game
    /// 
    /// We are given non-negative integers nums[i] which are written on a 
    /// chalkboard.  Alice and Bob take turns erasing exactly one number 
    /// from the chalkboard, with Alice starting first.  If erasing a number 
    /// causes the bitwise XOR of all the elements of the chalkboard to become 
    /// 0, then that player loses.  (Also, we'll say the bitwise XOR of one 
    /// element is that element itself, and the bitwise XOR of no elements is 
    /// 0.)
    ///
    /// Also, if any player starts their turn with the bitwise XOR of all the 
    /// elements of the chalkboard equal to 0, then that player wins.
    ///
    /// Return True if and only if Alice wins the game, assuming both players 
    /// play optimally.
    ///
    /// Example:
    /// Input: nums = [1, 1, 2]
    /// Output: false
    /// Explanation: 
    /// Alice has two choices: erase 1 or erase 2. 
    /// If she erases 1, the nums array becomes [1, 2]. The bitwise XOR of all 
    /// the elements of the chalkboard is 1 XOR 2 = 3. Now Bob can remove any 
    /// element he wants, because Alice will be the one to erase the last 
    /// element and she will lose. 
    /// If Alice erases 2 first, now nums becomes [1, 1]. The bitwise XOR of 
    /// all the elements of the chalkboard is 1 XOR 1 = 0. Alice will lose.
    ///
    /// Notes:
    ///
    /// 1. 1 <= N <= 1000. 
    /// 2. 0 <= nums[i] <= 2^16.
    /// </summary>
    bool xorGame(vector<int>& nums);

    /// <summary>
    /// Leetcode #1304. Find N Unique Integers Sum up to Zero
    ///
    /// Easy	
    ///
    /// Given an integer n, return any array containing n unique integers 
    /// such that they add up to 0.
    /// 
    /// Example 1: 
    /// Input: n = 5
    /// Output: [-7,-1,1,3,4]
    /// Explanation: These arrays also are accepted [-5,-1,1,2,3], 
    /// [-3,-1,2,-2,4].
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: [-1,0,1]
    ///
    /// Example 3:
    ///
    /// Input: n = 1
    /// Output: [0]
    ///  
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// </summary>
    vector<int> sumZero(int n);

    /// <summary>
    /// Leet code #1317. Convert Integer to the Sum of Two No-Zero Integers
    ///
    /// Easy
    ///
    /// Given an integer n. No-Zero integer is a positive integer which doesn't 
    /// contain any 0 in its decimal representation.
    ///
    /// Return a list of two integers [A, B] where:
    ///
    /// A and B are No-Zero integers.
    /// A + B = n
    /// It's guarateed that there is at least one valid solution. If there are 
    /// many valid solutions you can return any of them.
    /// 
    /// Example 1:
    /// Input: n = 2
    /// Output: [1,1]
    /// Explanation: A = 1, B = 1. A + B = n and both A and B don't contain 
    /// any 0 in their decimal representation.
    ///
    /// Example 2:
    /// Input: n = 11
    /// Output: [2,9]
    ///
    /// Example 3:
    /// Input: n = 10000
    /// Output: [1,9999]
    ///
    /// Example 4:
    /// Input: n = 69
    /// Output: [1,68]
    //
    /// Example 5:
    /// Input: n = 1010
    /// Output: [11,999]
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^4
    /// </summary>
    vector<int> getNoZeroIntegers(int n);

    /// <summary>
    /// Leet code #1318. Minimum Flips to Make a OR b Equal to c
    ///
    /// Medium
    ///
    /// Given 3 positives numbers a, b and c. Return the minimum flips required 
    /// in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
    /// Flip operation consists of change any single bit 1 to 0 or change the 
    /// bit 0 to 1 in their binary representation.
    /// 
    /// Example 1:
    /// Input: a = 2, b = 6, c = 5
    /// Output: 3
    /// Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
    ///
    /// Example 2:
    /// Input: a = 4, b = 2, c = 7
    /// Output: 1
    ///
    /// Example 3:
    /// Input: a = 1, b = 2, c = 3
    /// Output: 0
    ///
    /// Constraints:
    /// 1. 1 <= a <= 10^9
    /// 2. 1 <= b <= 10^9
    /// 3. 1 <= c <= 10^9
    /// </summary>
    int minFlips(int a, int b, int c);

    /// <summary>
    /// Leet code #1323. Maximum 69 Number
    ///
    /// Easy
    ///
    /// Given a positive integer num consisting only of digits 6 and 9.
    ///
    /// Return the maximum number you can get by changing at most one digit 
    /// (6 becomes 9, and 9 becomes 6).
    ///
    /// Example 1:
    ///
    /// Input: num = 9669
    /// Output: 9969
    /// Explanation: 
    /// Changing the first digit results in 6669.
    /// Changing the second digit results in 9969.
    /// Changing the third digit results in 9699.
    /// Changing the fourth digit results in 9666. 
    /// The maximum number is 9969.
    /// 
    /// Example 2:
    /// Input: num = 9996
    /// Output: 9999
    /// Explanation: Changing the last digit 6 to 9 results in the maximum 
    /// number.
    ///
    /// Example 3:
    /// Input: num = 9999
    /// Output: 9999
    /// Explanation: It is better not to apply any change.
    /// 
    /// Constraints:
    /// 1. 1 <= num <= 10^4
    /// 2. num's digits are 6 or 9.
    /// </summary>
    int maximum69Number(int num);

    /// <summary>
    /// Leet code #204. Count Primes
    /// 
    /// Count the number of prime numbers less than a non - negative number, n.
    /// </summary>
    int countPrimes(int n);

    /// <summary>
    /// Leet code #1342. Number of Steps to Reduce a Number to Zero
    ///
    /// Easy
    ///
    /// Given a non-negative integer num, return the number of steps to 
    /// reduce it to zero. If the current number is even, you have to 
    /// divide it by 2, otherwise, you have to subtract 1 from it.
    /// 
    /// Example 1:
    /// Input: num = 14
    /// Output: 6
    /// Explanation: 
    /// Step 1) 14 is even; divide by 2 and obtain 7. 
    /// Step 2) 7 is odd; subtract 1 and obtain 6.
    /// Step 3) 6 is even; divide by 2 and obtain 3. 
    /// Step 4) 3 is odd; subtract 1 and obtain 2. 
    /// Step 5) 2 is even; divide by 2 and obtain 1. 
    /// Step 6) 1 is odd; subtract 1 and obtain 0.
    ///
    /// Example 2:
    /// Input: num = 8
    /// Output: 4
    /// Explanation: 
    /// Step 1) 8 is even; divide by 2 and obtain 4. 
    /// Step 2) 4 is even; divide by 2 and obtain 2. 
    /// Step 3) 2 is even; divide by 2 and obtain 1. 
    /// Step 4) 1 is odd; subtract 1 and obtain 0.
    ///
    /// Example 3:
    /// Input: num = 123
    /// Output: 12
    ///
    /// Constraints:
    /// 1. 0 <= num <= 10^6
    /// </summary>
    int numberOfSteps(int num);

    /// <summary>
    /// Leet code #1344. Angle Between Hands of a Clock 
    ///
    /// Medium
    ///
    /// Given two numbers, hour and minutes. Return the smaller angle 
    /// (in sexagesimal units) formed between the hour and the minute hand.
    ///
    /// Example 1:
    /// Input: hour = 12, minutes = 30
    /// Output: 165
    ///
    /// Example 2:
    /// Input: hour = 3, minutes = 30
    /// Output: 75
    ///
    /// Example 3:
    /// Input: hour = 3, minutes = 15
    /// Output: 7.5
    ///
    /// Example 4:
    /// Input: hour = 4, minutes = 50
    /// Output: 155
    ///
    /// Example 5:
    /// Input: hour = 12, minutes = 0
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. 1 <= hour <= 12
    /// 2. 0 <= minutes <= 59
    /// 3. Answers within 10^-5 of the actual value will be accepted as 
    /// correct.
    /// </summary>
    double angleClock(int hour, int minutes);

    /// <summary>
    /// Leet code #1354. Construct Target Array With Multiple Sums
    ///
    /// Hard
    ///
    /// Given an array of integers target. From a starting array, A 
    /// consisting of all 1's, you may perform the following procedure
    ///
    /// let x be the sum of all elements currently in your array.
    /// choose index i, such that 0 <= i < target.size and set the value of 
    /// A at index i to x.
    /// You may repeat this procedure as many times as needed.
    /// Return True if it is possible to construct the target array from A 
    /// otherwise return False.
    ///
    /// Example 1:
    /// Input: target = [9,3,5]
    /// Output: true
    /// Explanation: Start with [1, 1, 1] 
    /// [1, 1, 1], sum = 3 choose index 1
    /// [1, 3, 1], sum = 5 choose index 2
    /// [1, 3, 5], sum = 9 choose index 0
    /// [9, 3, 5] Done
    ///
    /// Example 2:
    /// Input: target = [1,1,1,2]
    /// Output: false
    /// Explanation: Impossible to create target array from [1,1,1,1].
    ///
    /// Example 3:
    /// Input: target = [8,5]
    /// Output: true
    /// 
    /// Constraints:
    /// 1. N == target.length
    /// 2. 1 <= target.length <= 5 * 10^4
    /// 3. 1 <= target[i] <= 10^9
    /// </summary>
    bool isPossible(vector<int>& target);

    /// <summary>
    /// Leet code #1356. Sort Integers by The Number of 1 Bits
    ///
    /// Easy
    ///
    /// Given an integer array arr. You have to sort the integers in the 
    /// array in ascending order by the number of 1's in their binary 
    /// representation and in case of two or more integers have the same 
    /// number of 1's you have to sort them in ascending order.
    ///
    /// Return the sorted array.
    ///
    /// Example 1:
    /// Input: arr = [0,1,2,3,4,5,6,7,8]
    /// Output: [0,1,2,4,8,3,5,6,7]
    /// Explantion: [0] is the only integer with 0 bits.
    /// [1,2,4,8] all have 1 bit.
    /// [3,5,6] have 2 bits.
    /// [7] has 3 bits.
    /// The sorted array by bits is [0,1,2,4,8,3,5,6,7]
    ///
    /// Example 2:
    /// Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
    /// Output: [1,2,4,8,16,32,64,128,256,512,1024]
    /// Explantion: All integers have 1 bit in the binary representation, 
    /// you should just sort them in ascending order.
    ///
    /// Example 3:
    /// Input: arr = [10000,10000]
    /// Output: [10000,10000]
    ///
    /// Example 4:
    /// Input: arr = [2,3,5,7,11,13,17,19]
    /// Output: [2,3,5,17,7,11,13,19]
    ///
    /// Example 5:
    /// Input: arr = [10,100,1000,10000]
    /// Output: [10,100,10000,1000]
    /// 
    /// Constraints:
    /// 1. 1 <= arr.length <= 500
    /// 2. 0 <= arr[i] <= 10^4
    /// </summary>
    vector<int> sortByBits(vector<int>& arr);

    /// <summary>
    /// Leet code #1359. Count All Valid Pickup and Delivery Options
    ///
    /// Hard
    ///
    /// Given n orders, each order consist in pickup and delivery services. 
    ///
    /// Count all valid pickup/delivery possible sequences such that 
    /// delivery(i) is always after of pickup(i). 
    ///
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: n = 1
    /// Output: 1
    /// Explanation: Unique order (P1, D1), Delivery 1 always is after of 
    /// Pickup 1.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: 6
    /// Explanation: All possible orders: 
    /// (P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), 
    /// (P2,P1,D2,D1) and (P2,D2,P1,D1).
    /// This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after 
    /// of Delivery 2.
    ///
    /// Example 3:
    /// Input: n = 3
    /// Output: 90
    ///
    /// Constraints:
    /// 1. 1 <= n <= 500
    /// </summary>
    int countOrders(int n);

     /// <summary>
     /// Leet code #1360. Number of Days Between Two Dates
     /// </summary>
     bool isLeapYear(int year);

    /// <summary>
    /// Leet code #1360. Number of Days Between Two Dates
    ///
    /// Easy
    ///
    /// Write a program to count the number of days between two dates.
    ///
    /// The two dates are given as strings, their format is YYYY-MM-DD as 
    /// shown in the examples.
    ///
    /// Example 1:
    /// Input: date1 = "2019-06-29", date2 = "2019-06-30"
    /// Output: 1
    ///
    /// Example 2:
    /// Input: date1 = "2020-01-15", date2 = "2019-12-31"
    /// Output: 15
    /// 
    /// Constraints:
    /// 1. The given dates are valid dates between the years 1971 and 2100.
    /// </summary>
    int daysBetweenDates(string date1, string date2);

    /// <summary>
    /// Leet code #1363. Largest Multiple of Three
    ///
    /// Hard
    ///
    /// Given an integer array of digits, return the largest multiple of 
    /// three that can be formed by concatenating some of the given 
    /// digits in any order.
    ///
    /// Since the answer may not fit in an integer data type, return the 
    /// answer as a string.
    ///
    /// If there is no answer return an empty string.
    /// 
    /// Example 1:
    /// Input: digits = [8,1,9]
    /// Output: "981"
    ///
    /// Example 2:
    /// Input: digits = [8,6,7,1,0]
    /// Output: "8760"
    ///
    /// Example 3:
    /// Input: digits = [1]
    /// Output: ""
    ///
    /// Example 4:
    /// Input: digits = [0,0,0,0,0,0]
    /// Output: "0"
    /// 
    /// Constraints:
    /// 1. 1 <= digits.length <= 10^4
    /// 2. 0 <= digits[i] <= 9
    /// 3. The returning answer must not contain unnecessary leading zeros.
    /// </summary>
    string largestMultipleOfThree(vector<int>& digits);

    /// <summary>
    /// Leet code #1362. Closest Divisors
    ///
    /// Medium
    ///
    /// Given an integer num, find the closest two integers in absolute 
    /// difference whose product equals num + 1 or num + 2.
    /// 
    /// Return the two integers in any order.
    ///
    /// Example 1:
    /// Input: num = 8
    /// Output: [3,3]
    /// Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for 
    /// num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
    ///
    /// Example 2:
    /// Input: num = 123
    /// Output: [5,25]
    ///
    /// Example 3:
    /// Input: num = 999
    /// Output: [40,25]
    ///
    /// Constraints:
    /// 1. 1 <= num <= 10^9
    /// </summary>
    vector<int> closestDivisors(int num);

    /// <summary>
    /// Leet code #1375. Bulb Switcher III
    ///  
    /// Medium
    ///
    /// There is a room with n bulbs, numbered from 1 to n, arranged in a 
    /// row from left to right. Initially, all the bulbs are turned off.
    ///
    /// At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. 
    /// A bulb change color to blue only if it is on and all the previous 
    /// bulbs (to the left) are turned on too.
    ///
    /// Return the number of moments in which all turned on bulbs are blue.
    /// 
    /// Example 1:
    /// Input: light = [2,1,3,5,4]
    /// Output: 3
    /// Explanation: All bulbs turned on, are blue at the moment 1, 2 and 4.
    ///
    /// Example 2:
    /// Input: light = [3,2,4,1,5]
    /// Output: 2
    /// Explanation: All bulbs turned on, are blue at the moment 3, and 4 
    /// (index-0).
    ///
    /// Example 3:
    /// Input: light = [4,1,2,3]
    /// Output: 1
    /// Explanation: All bulbs turned on, are blue at the moment 3 (index-0).
    /// Bulb 4th changes to blue at the moment 3.
    ///
    /// Example 4:
    /// Input: light = [2,1,4,3,6,5]
    /// Output: 3
    ///
    /// Example 5:
    /// Input: light = [1,2,3,4,5,6]
    /// Output: 6
    /// 
    /// Constraints:
    /// 1. n == light.length
    /// 2. 1 <= n <= 5 * 10^4
    /// 3. light is a permutation of  [1, 2, ..., n]
    /// </summary>
    int numTimesAllBlue(vector<int>& light);

    /// <summary>
    /// Leet code #1390. Four Divisors
    /// 
    /// Medium
    ///
    /// Given an integer array nums, return the sum of divisors of the 
    /// integers in that array that have exactly four divisors.
    /// 
    /// If there is no such integer in the array, return 0.
    /// Example 1:
    /// Input: nums = [21,4,7]
    /// Output: 32
    /// Explanation:
    /// 21 has 4 divisors: 1, 3, 7, 21
    /// 4 has 3 divisors: 1, 2, 4
    /// 7 has 2 divisors: 1, 7
    /// The answer is the sum of divisors of 21 only.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^4
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int sumFourDivisors(vector<int>& nums);

    /// <summary>
    /// Leet code #1399. Count Largest Group
    /// 
    /// Easy
    ///
    /// Given an integer n. Each number from 1 to n is grouped according to 
    /// the sum of its digits. 
    ///
    /// Return how many groups have the largest size.
    /// 
    /// Example 1:
    /// Input: n = 13
    /// Output: 4
    /// Explanation: There are 9 groups in total, they are grouped according 
    /// sum of its digits of numbers from 1 to 13:
    /// [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. 
    /// There are 4 groups with largest size.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: 2 
    /// Explanation: There are 2 groups [1], [2] of size 1.
    ///
    /// Example 3:
    /// Input: n = 15
    /// Output: 6
    ///
    /// Example 4:
    /// Input: n = 24
    /// Output: 5
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// </summary>
    int countLargestGroup(int n);

    /// <summary>
    /// Leet code #1401. Circle and Rectangle Overlapping
    /// 
    /// Medium
    ///
    /// Given a circle represented as (radius, x_center, y_center) and an 
    /// axis-aligned rectangle represented as (x1, y1, x2, y2), 
    /// where (x1, y1) are the coordinates of the bottom-left corner, 
    /// and (x2, y2) are the coordinates of the top-right corner of the 
    /// rectangle.
    ///
    /// Return True if the circle and rectangle are overlapped otherwise 
    /// return False.
    /// In other words, check if there are any point (xi, yi) such that 
    /// belongs to the circle and the rectangle at the same time.
    /// 
    /// Example 1:
    /// Input: radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, 
    /// x2 = 3, y2 = 1
    /// Output: true
    /// Explanation: Circle and rectangle share the point (1,0) 
    ///
    /// Example 2:
    /// Input: radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, 
    /// x2 = 0, y2 = 1
    /// Output: true
    ///
    /// Example 3:
    /// Input: radius = 1, x_center = 1, y_center = 1, 
    /// x1 = -3, y1 = -3, x2 = 3, y2 = 3
    /// Output: true
    ///
    /// Example 4: 
    /// Input: radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, 
    /// x2 = 2, y2 = -1
    /// Output: false
    ///
    /// Constraints:
    /// 1. 1 <= radius <= 2000
    /// 2. -10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4
    /// 3. x1 < x2
    /// 4. y1 < y2
    /// </summary>
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2);

    /// <summary>
    /// Leet code #1414. Find the Minimum Number of Fibonacci Numbers Whose 
    ///                  Sum Is K 
    /// 
    /// Medium
    ///
    /// Given the number k, return the minimum number of Fibonacci numbers 
    /// whose sum is equal to k, whether a Fibonacci number could be used 
    /// multiple times.
    ///
    /// The Fibonacci numbers are defined as:
    /// 
    /// F1 = 1
    /// F2 = 1
    /// Fn = Fn-1 + Fn-2 , for n > 2.
    /// It is guaranteed that for the given constraints we can always find 
    /// such fibonacci numbers that sum k.
    /// 
    /// Example 1:
    /// Input: k = 7
    /// Output: 2 
    /// Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
    /// For k = 7 we can use 2 + 5 = 7.
    ///
    /// Example 2:
    /// Input: k = 10
    /// Output: 2 
    /// Explanation: For k = 10 we can use 2 + 8 = 10.
    ///
    /// Example 3:
    /// Input: k = 19
    /// Output: 3 
    /// Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
    ///
    /// Constraints:
    /// 1. 1 <= k <= 10^9
    /// </summary>
    int findMinFibonacciNumbers(int k);

    /// <summary>
    /// Leet code #1415. The k-th Lexicographical String of All Happy Strings 
    ///                  of Length n 
    /// 
    /// Medium
    ///
    /// A happy string is a string that:
    ///
    /// consists only of letters of the set ['a', 'b', 'c'].
    /// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 
    /// (string is 1-indexed).
    /// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy 
    /// strings and strings "aa", "baa" and "ababbc" are not happy strings.
    ///
    /// Given two integers n and k, consider a list of all happy strings of 
    /// length n sorted in lexicographical order.
    ///
    /// Return the kth string of this list or return an empty string if there 
    /// are less than k happy strings of length n.
    ///
    /// Example 1:
    /// Input: n = 1, k = 3
    /// Output: "c"
    /// Explanation: The list ["a", "b", "c"] contains all happy strings of 
    /// length 1. The third string is "c".
    ///
    /// Example 2:
    /// Input: n = 1, k = 4
    /// Output: ""
    /// Explanation: There are only 3 happy strings of length 1.
    ///
    /// Example 3:
    /// Input: n = 3, k = 9
    /// Output: "cab"
    /// Explanation: There are 12 different happy string of length 3 ["aba", 
    /// "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", 
    /// "cbc"]. You will find the 9th string = "cab"
    ///
    /// Example 4:
    /// Input: n = 2, k = 7
    /// Output: ""
    ///
    /// Example 5:
    /// Input: n = 10, k = 100
    /// Output: "abacbabacb"
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10
    /// 2. 1 <= k <= 100
    /// </summary>
    string getHappyString(int n, int k);

    /// <summary>
    /// Leet code #1432. Max Difference You Can Get From Changing an Integer
    /// 
    /// Medium
    ///
    /// You are given an integer num. You will apply the following steps 
    /// exactly two times:
    ///
    /// Pick a digit x (0 <= x <= 9).
    /// Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
    /// Replace all the occurrences of x in the decimal representation of num 
    /// by y.
    /// The new integer cannot have any leading zeros, also the new integer 
    /// cannot be 0.
    /// Let a and b be the results of applying the operations to num the first 
    /// and second times, respectively.
    ///
    /// Return the max difference between a and b.
    /// 
    /// Example 1:
    /// Input: num = 555
    /// Output: 888
    /// Explanation: The first time pick x = 5 and y = 9 and store the new 
    /// integer in a.
    /// The second time pick x = 5 and y = 1 and store the new integer in b.
    /// We have now a = 999 and b = 111 and max difference = 888
    ///
    /// Example 2:
    /// Input: num = 9
    /// Output: 8
    /// Explanation: The first time pick x = 9 and y = 9 and store the new 
    /// integer in a.
    /// The second time pick x = 9 and y = 1 and store the new integer in b.
    /// We have now a = 9 and b = 1 and max difference = 8
    ///
    /// Example 3:
    /// Input: num = 123456
    /// Output: 820000
    ///
    /// Example 4:
    /// Input: num = 10000
    /// Output: 80000
    ///
    /// Example 5:
    /// Input: num = 9288
    /// Output: 8700
    ///
    /// Constraints:
    /// 1. 1 <= num <= 10^8
    /// </summary>
    int maxDiff(int num);

    /// <summary>
    /// Leet code #1447. Simplified Fractions
    ///
    /// Medium
    ///
    /// Given an integer n, return a list of all simplified fractions 
    /// between 0 and 1 (exclusive) such that the denominator is 
    /// less-than-or-equal-to n. The fractions can be in any order.
    ///
    /// Example 1:
    /// Input: n = 2
    /// Output: ["1/2"]
    /// Explanation: "1/2" is the only unique fraction with a denominator 
    /// less-than-or-equal-to 2.
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: ["1/2","1/3","2/3"]
    ///
    /// Example 3:
    /// Input: n = 4
    /// Output: ["1/2","1/3","1/4","2/3","3/4"]
    /// Explanation: "2/4" is not a simplified fraction because it can be 
    /// simplified to "1/2".
    ///
    /// Example 4:
    /// Input: n = 1
    /// Output: []
    ///
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// </summary>
    vector<string> simplifiedFractions(int n);

    /// <summary>
    /// Leet code #1453. Maximum Number of Darts Inside of a Circular Dartboard
    ///                  
    /// Hard
    ///
    /// You have a very large square wall and a circular dartboard placed on 
    /// the wall. You have been challenged to throw darts into the board 
    /// blindfolded. Darts thrown at the wall are represented as an array of 
    /// points on a 2D plane. 
    ///
    /// Return the maximum number of points that are within or lie on any 
    /// circular dartboard of radius r.
    /// 
    /// Example 1: 
    /// Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
    /// Output: 4
    /// Explanation: Circle dartboard with center in (0,0) and radius = 2 
    /// contain all points.
    ///
    /// Example 2:
    /// Input: points = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
    /// Output: 5
    /// Explanation: Circle dartboard with center in (0,4) and radius = 5 
    /// contain all points except the point (7,8).
    ///
    /// Example 3:
    /// Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 1
    /// Output: 1
    ///
    /// Example 4:
    /// Input: points = [[1,2],[3,5],[1,-1],[2,3],[4,1],[1,3]], r = 2
    /// Output: 4
    ///
    /// Constraints:
    /// 1. 1 <= points.length <= 100
    /// 2. points[i].length == 2
    /// 3. -10^4 <= points[i][0], points[i][1] <= 10^4
    /// 4. 1 <= r <= 5000
    /// </summary>
    int numPoints(vector<vector<int>>& points, int r);

    /// <summary>
    /// Leet code #12. Integer to Roman
    ///  
    /// Roman numerals are represented by seven different 
    /// symbols: I, V, X, L, C, D and M.
    ///
    /// Symbol       Value
    /// I             1
    /// V             5
    /// X             10
    /// L             50
    /// C             100
    /// D             500
    /// M             1000
    /// For example, two is written as II in Roman numeral, just two one's 
    /// added together. Twelve is written as, XII, which is simply X + II. 
    /// The number twenty seven is written as XXVII, which is XX + V + II.
    ///
    /// Roman numerals are usually written largest to smallest from left to 
    /// right. However, the numeral for four is not IIII. Instead, the number 
    /// four is written as IV. Because the one is before the five we subtract 
    /// it making four. The same principle applies to the number nine, which 
    /// is written as IX. There are six instances where subtraction is used:
    ///
    /// I can be placed before V (5) and X (10) to make 4 and 9. 
    /// X can be placed before L (50) and C (100) to make 40 and 90. 
    /// C can be placed before D (500) and M (1000) to make 400 and 900.
    /// Given an integer, convert it to a roman numeral. Input is guaranteed 
    /// to be within the range from 1 to 3999.
    ///
    /// Example 1:
    /// 
    /// Input: 3
    /// Output: "III"
    ///
    /// Example 2:
    ///
    /// Input: 4
    /// Output: "IV"
    ///
    /// Example 3:
    ///
    /// Input: 9
    /// Output: "IX"
    ///
    /// Example 4:
    ///
    /// Input: 58
    /// Output: "LVIII"
    /// Explanation: L = 50, V = 5, III = 3.
    ///
    /// Example 5:
    ///
    /// Input: 1994
    /// Output: "MCMXCIV"
    /// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
    /// </summary>
    string intToRoman(int num);

    /// <summary>
    /// Leet code 13. Roman to Integer
    /// Given a roman numeral, convert it to an integer.
    /// Input is guaranteed to be within the range from 1 to 3999.
    /// </summary>
    int romanToInt(string s);

    /// <summary>
    /// Leet code #231. Power of Two    
    /// Given an integer, write a function to determine if it is a power of two. 
    /// </summary>
    bool isPowerOfTwo(int n);

    /// <summary>
    /// Leet code #171. Excel Sheet Column Number 
    /// Related to question Excel Sheet Column Title
    /// Given a column title as appear in an Excel sheet, return its corresponding column number.
    /// For example:
    /// A -> 1
    /// B -> 2
    /// C -> 3
    /// ...
    /// Z -> 26
    /// AA -> 27
    /// AB -> 28 
    /// </summary>
    int titleToNumber(string s);

    /// <summary>
    /// Leet code #168. Excel Sheet Column Title 
    /// Related to question Excel Sheet Column Title
    /// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
    /// For example:
    /// 1 -> A
    /// 2 -> B
    /// 3 -> C
    /// ...
    /// 26 -> Z
    /// 27 -> AA
    /// 28 -> AB 
    ///</summary>
    string convertToTitle(int n);

    /// <summary>
    /// Leet code #263. Ugly Number
    /// Write a program to check whether a given number is an ugly number. 
    /// Ugly numbers are positive numbers whose prime factors only include 
    /// 2, 3, 5. For example, 6, 8 are ugly 
    /// while 14 is not ugly since it includes another prime factor 7. 
    /// Note that 1 is typically treated as an ugly number. 
    /// </summary>
    bool isUgly(int num);

    /// <summary>
    /// Leet code #400. Nth Digit 
    /// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 
    /// Note: 
    /// n is positive and will fit within the range of a 32-bit signed integer (n < 2^31). 
    /// Example 1: 
    /// Input:
    /// 3
    /// Output:
    /// 3
    /// Example 2:
    /// Input:
    /// 11
    ///	Output:
    /// 0
    /// Explanation:
    /// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
    /// 11, ... is a 0, which is part of the number 10.
    /// </summary>
    int findNthDigit(int n);

    /// <summary>
    /// Leet code #386. Lexicographical Numbers
    ///
    /// Given an integer n, return 1 - n in lexicographical order. 
    /// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9]. 
    /// Please optimize your algorithm to use less time and space. The input 
    /// size may be as large as 5,000,000. 
    /// </summary>
    vector<int> lexicalOrder(int n);

    /// <summary>
    /// Leet code #233. Number of Digit One 
    /// </summary>
    int countDigitOne(string& str_n, int is_last, int index, vector<int> &cache);

    /// <summary>
    /// Leet code #233. Number of Digit One 
    ///
    /// Given an integer n, count the total number of digit 1 appearing 
    /// in all non-negative integers less than or equal to n.
    /// For example: 
    /// Given n = 13,
    /// Return 6, because digit 1 occurred in the following numbers: 
    /// 1, 10, 11, 12, 13. 
    /// Hint: 
    /// 1.Beware of overflow.
    /// </summary>
    int countDigitOne(int n);

    /// <summary>
    /// Leet code #1067. Digit Count in Range
    /// </summary>
    int digitsCount(string& str_n, int d, int is_first, int is_last, int index, vector<int>& cache);

    /// <summary>
    /// Leet code #1067. Digit Count in Range
    /// 
    /// Given an integer d between 0 and 9, and two positive integers low and 
    /// high as lower and upper bounds, respectively. Return the number of 
    /// times that d occurs as a digit in all integers between low and high, 
    /// including the bounds low and high.
    /// 
    /// Example 1:
    /// Input: d = 1, low = 1, high = 13
    /// Output: 6
    /// Explanation: 
    /// The digit d=1 occurs 6 times in 1,10,11,12,13. Note that the digit d=1 
    /// occurs twice in the number 11.
    ///
    /// Example 2:
    ///
    /// Input: d = 3, low = 100, high = 250
    /// Output: 35
    /// Explanation: 
    /// The digit d=3 occurs 35 times in 103,113,123,130,131,...,238,239,243.
    ///
    ///
    /// Note:
    ///
    /// 0 <= d <= 9
    /// 1 <= low <= high <= 2×10^8
    /// </summary>
    int digitsCount(int d, int low, int high);

    /// <summary>
    /// Leet code #60. Permutation Sequence
    /// The set [1,2,3,?n] contains a total of n! unique permutations.
    /// By listing and labeling all of the permutations in order,
    /// We get the following sequence (ie, for n = 3): 
    /// 1."123"
    /// 2."132"
    /// 3."213"
    /// 4."231"
    /// 5."312"
    /// 6."321"
    /// Given n and k, return the kth permutation sequence.
    /// Note: Given n will be between 1 and 9 inclusive.
    /// </summary>
    string getPermutation(int n, int k);


    /// <summary>
    /// Leet code #31. Next Permutation
    /// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 
    /// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). 
    /// The replacement must be in-place, do not allocate extra memory. 
    /// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
    /// 1,2,3 -> 1,3,2
    /// 3,2,1 -> 1,2,3
    /// 1,1,5 -> 1,5,1 
    /// </summary>
    void nextPermutation(vector<int>& nums);

    /// <summary>
    /// Leet code #357. Count Numbers with Unique Digits
    ///
    /// Given a non-negative integer n, count all numbers with unique digits, 
    /// x, where 0 <= x < 10^n.
    ///
    /// Example: 
    /// Given n = 2, return 91. (The answer should be the total numbers in 
    /// the range of 0 <= x < 100, excluding [11,22,33,44,55,66,77,88,99]) 
    /// Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13. 
    /// Hint:
    /// 1.A direct way is to use the backtracking approach.
    /// 2.Backtracking should contains three states which are (the current number, number 
    //// of steps to get that number and a bitmask which represent 
    /// which number is marked as visited so far in the current number). Start with state 
    /// (0,0,0) and count all valid number till we reach number of steps equals to 10n.
    /// 3.This problem can also be solved using a dynamic programming approach and some
    /// knowledge of combinatorics.
    /// 4.Let f(k) = count of numbers with unique digits with length equals k.
    /// 5.f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 
    /// because a number cannot start with 0].
    /// </summary>
    int countNumbersWithUniqueDigits(int n);

    /// <summary>
    /// Leet code #908. Smallest Range I
    /// 
    /// Given an array A of integers, for each integer A[i] we may choose any x 
    /// with -K <= x <= K, and add x to A[i].
    ///
    /// After this process, we have some array B.
    ///
    /// Return the smallest possible difference between the maximum value of B 
    /// and the minimum value of B.
    ///
    /// 
    /// Example 1:
    ///
    /// Input: A = [1], K = 0
    /// Output: 0
    /// Explanation: B = [1]
    /// Example 2:
    ///
    /// Input: A = [0,10], K = 2
    /// Output: 6
    /// Explanation: B = [2,8]
    /// Example 3:
    ///
    /// Input: A = [1,3,6], K = 3
    /// Output: 0
    /// Explanation: B = [3,3,3] or B = [4,4,4]
    /// 
    ///
    /// Note:
    ///
    /// 1. 1 <= A.length <= 10000
    /// 2. 0 <= A[i] <= 10000
    /// 3. 0 <= K <= 10000
    /// </summary>
    int smallestRangeI(vector<int>& A, int K);

    /// <summary>
    /// Leet code #398. Random Pick Index     
    /// Given an array of integers with possible duplicates, randomly output the index of a given target number. 
    /// You can assume that the given target number must exist in the array.  
    /// 
    /// Note:
    /// The array size can be very large. Solution that uses too much extra space will not pass the judge. 
    ///
    /// Example: 
    /// int[] nums = new int[] {1,2,3,3,3};
    /// Solution solution = new Solution(nums);
    /// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
    /// solution.pick(3);
    /// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
    /// solution.pick(1);
    /// </summary>
    int pickRandom(vector<int>& nums, int target);

    /// <summary>
    /// Leet code #1012. Numbers With Repeated Digits
    /// </summary>
    int numDupDigitsAtMostN(string& str_n, int index, int leading, int is_last, int bit_mask, vector<vector<int>>& cache);

    /// <summary>
    /// Leet code #1012. Numbers With Repeated Digits
    /// 
    /// Given a positive integer N, return the number of positive integers less 
    /// than or equal to N that have at least 1 repeated digit.
    ///
    /// Example 1:
    /// Input: 20
    /// Output: 1
    /// Explanation: The only positive number (<= 20) with at least 1 repeated 
    /// digit is 11.
    ///
    /// Example 2:
    /// Input: 100
    /// Output: 10
    /// Explanation: The positive numbers (<= 100) with atleast 1 repeated digit 
    /// are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
    ///
    /// Example 3:
    /// Input: 1000
    /// Output: 262
    /// 
    ///
    /// Note:
    ///
    /// 1 <= N <= 10^9
    /// </summary>
    int numDupDigitsAtMostN(int N);


    /// <summary>
    /// Leet code #1000. Minimum Cost to Merge Stones
    /// </summary>
    int mergeStones(int i, int j, int m, int K, vector<vector<vector<int>>>& dp, vector<int>& sum);

    /// <summary>
    /// Leet code #1000. Minimum Cost to Merge Stones
    /// 
    /// There are N piles of stones arranged in a row.  The i-th pile has 
    /// stones[i] stones.
    ///
    /// A move consists of merging exactly K consecutive piles into one pile, 
    /// and the cost of this move is equal to the total number of stones in these 
    /// K piles.
    ///
    /// Find the minimum cost to merge all piles of stones into one pile.  If it 
    /// is impossible, return -1.
    ///
    /// 
    ///
    /// Example 1:
    ///
    /// Input: stones = [3,2,4,1], K = 2
    /// Output: 20
    /// Explanation: 
    /// We start with [3, 2, 4, 1].
    /// We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
    /// We merge [4, 1] for a cost of 5, and we are left with [5, 5].
    /// We merge [5, 5] for a cost of 10, and we are left with [10].
    /// The total cost was 20, and this is the minimum possible.
    ///
    /// Example 2:
    ///
    /// Input: stones = [3,2,4,1], K = 3
    /// Output: -1
    /// Explanation: After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
    ///
    /// Example 3:
    ///
    /// Input: stones = [3,5,1,2,6], K = 3
    /// Output: 25
    /// Explanation: 
    /// We start with [3, 5, 1, 2, 6].
    /// We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
    /// We merge [3, 8, 6] for a cost of 17, and we are left with [17].
    /// The total cost was 25, and this is the minimum possible.
    ///  
    /// Note:
    /// 1. 1 <= stones.length <= 30
    /// 2. 2 <= K <= 30
    /// 3. 1 <= stones[i] <= 100
    /// </summary>
    int mergeStones(vector<int>& stones, int K);

    /// <summary>
    /// Leet code #964. Least Operators to Express Number
    /// </summary>
    int leastOpsExpressTarget(int exp, int x, int target, unordered_map<int, unordered_map<int, int>>& cache);

    /// <summary>
    /// Leet code #964. Least Operators to Express Number
    /// 
    /// Given a single positive integer x, we will write an expression of the 
    /// form x (op1) x (op2) x (op3) x ... where each operator op1, op2, etc. 
    /// is either addition, subtraction, multiplication, or division 
    /// (+, -, *, or /).  For example, with x = 3, we might write 
    /// 3 * 3 / 3 + 3 - 3 which is a value of 3.
    ///
    /// When writing such an expression, we adhere to the following conventions:
    ///
    /// The division operator (/) returns rational numbers.
    /// There are no parentheses placed anywhere.
    /// We use the usual order of operations: multiplication and division happens 
    /// before addition and subtraction.
    /// It's not allowed to use the unary negation operator (-).  For example, 
    /// "x - x" is a valid expression as it only uses subtraction, but "-x + x" 
    /// is not because it uses negation.
    /// We would like to write an expression with the least number of operators 
    /// such that the expression equals the given target.  Return the least number 
    /// of operators used.
    ///
    /// Example 1:
    /// Input: x = 3, target = 19
    /// Output: 5
    /// Explanation: 3 * 3 + 3 * 3 + 3 / 3.  The expression contains 5 operations.
    ///
    /// Example 2:
    /// Input: x = 5, target = 501
    /// Output: 8
    /// Explanation: 5 * 5 * 5 * 5 - 5 * 5 * 5 + 5 / 5.  The expression contains 
    /// 8 operations.
    ///
    /// Example 3:
    /// Input: x = 100, target = 100000000
    /// Output: 3
    /// Explanation: 100 * 100 * 100 * 100.  The expression contains 3 operations.
    ///  
    ///
    /// Note:
    /// 
    /// 1. 2 <= x <= 100
    /// 2. 1 <= target <= 2 * 10^8
    /// </summary>
    int leastOpsExpressTarget(int x, int target);

    /// <summary>
    /// Leet code # 517. Super Washing Machines 
    ///
    /// You have n super washing machines on a line. Initially, 
    /// each washing machine has some dresses or is empty.
    /// 
    /// For each move, you could choose any m (1 <= m <= n) washing machines, 
    /// and pass one dress of each washing machine to one of its adjacent 
    /// washing machines at the same time .
    ///
    /// Given an integer array representing the number of dresses in each 
    /// washing machine from left to right on the line, you should find the 
    /// minimum number of moves to make all the washing machines have the 
    /// same number of dresses. If it is not possible to do it, return -1.
    /// 
    /// Example1
    /// Input: [1,0,5]
    /// Output: 3
    /// Explanation: 
    /// 1st move:    1     0 <-- 5    =>    1     1     4
    /// 2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
    /// 3rd move:    2     1 <-- 3    =>    2     2     2   
    ///
    /// Example2 
    /// Input: [0,3,0]
    /// Output: 2
    /// Explanation: 
    /// 1st move:    0 <-- 3     0    =>    1     2     0    
    /// 2nd move:    1     2 --> 0    =>    1     1     1     
    ///
    /// Example3
    /// Input: [0,2,0]
    /// Output: -1
    /// 
    /// Explanation: 
    /// It's impossible to make all the three washing machines have the 
    /// same number of dresses. 
    /// Note:
    /// The range of n is [1, 10000].
    /// The range of dresses number in a super washing machine is [0, 1e5].
    /// </summary>
    int findMinMoves(vector<int>& machines);

    /// <summary>
    /// Leet code #384. Shuffle an Array
    /// Shuffle a set of numbers without duplicates. 
    /// Example: 
    /// Init an array with set 1, 2, and 3.
    /// int[] nums = {1,2,3};
    /// Solution solution = new Solution(nums);
    ///
    /// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned
    /// solution.shuffle();
    ///
    /// Resets the array back to its original configuration [1,2,3].
    /// solution.reset(); 
    /// Returns the random shuffling of array [1,2,3].
    /// solution.shuffle();
    /// </summary>
    vector<int> shuffle(vector<int> nums);

    /// <summary>
    /// Leet code #1467. Probability of a Two Boxes Having The Same Number of 
    ///                  Distinct Balls
    /// </summary>
    double getProbability(vector<int>& balls, int index, double sum_count, 
        int left_count, int right_count, int left_color, int right_color, 
        int ball_count);

    /// <summary>
    /// Leet code #1467. Probability of a Two Boxes Having The Same Number of 
    ///                  Distinct Balls
    /// 
    /// Hard
    ///
    /// Given 2n balls of k distinct colors. You will be given an integer 
    /// array balls of size k where balls[i] is the number of balls of 
    /// color i. 
    ///
    /// All the balls will be shuffled uniformly at random, then we will 
    /// distribute the first n balls to the first box and the remaining n 
    /// balls to the other box (Please read the explanation of the second 
    /// example carefully).
    ///
    /// Please note that the two boxes are considered different. For 
    /// example, if we have two balls of colors a and b, and two boxes [] 
    /// and (), then the distribution [a] (b) is considered different than 
    /// the distribution [b] (a) (Please read the explanation of the first 
    /// example carefully).
    ///
    /// We want to calculate the probability that the two boxes have the same 
    /// number of distinct balls.
    /// 
    /// Example 1:
    /// Input: balls = [1,1]
    /// Output: 1.00000
    /// Explanation: Only 2 ways to divide the balls equally:
    /// - A ball of color 1 to box 1 and a ball of color 2 to box 2
    /// - A ball of color 2 to box 1 and a ball of color 1 to box 2
    /// In both ways, the number of distinct colors in each box is equal. 
    /// The probability is 2/2 = 1
    ///
    /// Example 2:
    /// Input: balls = [2,1,1]
    /// Output: 0.66667
    /// Explanation: We have the set of balls [1, 1, 2, 3]
    /// This set of balls will be shuffled randomly and we may have one of 
    /// the 12 distinct shuffles with equale probability (i.e. 1/12):
    /// [1,1 / 2,3], [1,1 / 3,2], [1,2 / 1,3], [1,2 / 3,1], [1,3 / 1,2], 
    /// [1,3 / 2,1], [2,1 / 1,3], [2,1 / 3,1], [2,3 / 1,1], [3,1 / 1,2], 
    /// [3,1 / 2,1], [3,2 / 1,1]
    /// After that we add the first two balls to the first box and the 
    /// second two balls to the second box.
    /// We can see that 8 of these 12 possible random distributions have the 
    /// same number of distinct colors of balls in each box.
    /// Probability is 8/12 = 0.66667
    ///
    /// Example 3:
    /// Input: balls = [1,2,1,2]
    /// Output: 0.60000
    /// Explanation: The set of balls is [1, 2, 2, 3, 4, 4]. It is hard to 
    /// display all the 180 possible random shuffles of this set but it is 
    /// easy to check that 108 of them will have the same number of distinct 
    /// colors in each box.
    /// Probability = 108 / 180 = 0.6
    ///
    /// Example 4:
    /// Input: balls = [3,2,1]
    /// Output: 0.30000
    /// Explanation: The set of balls is [1, 1, 1, 2, 2, 3]. It is hard to 
    /// display all the 60 possible random shuffles of this set but it is 
    /// easy to check that 18 of them will have the same number of distinct 
    /// colors in each box.
    /// Probability = 18 / 60 = 0.3
    ///
    /// Example 5:
    /// Input: balls = [6,6,6,6,6,6]
    /// Output: 0.90327
    /// Constraints:
    /// 1. 1 <= balls.length <= 8
    /// 2. 1 <= balls[i] <= 6
    /// 3. sum(balls) is even.
    /// 4. Answers within 10^-5 of the actual value will be accepted as 
    ///    correct.
    /// </summary>
    double getProbability(vector<int>& balls);

    /// <summary>
    /// Leet code #1464. Maximum Product of Two Elements in an Array 
    /// 
    /// Easy
    ///
    /// Given the array of integers nums, you will choose two different 
    /// indices i and j of that array. Return the maximum value of 
    /// (nums[i]-1)*(nums[j]-1).
    /// 
    /// Example 1:
    /// Input: nums = [3,4,5,2]
    /// Output: 12 
    /// Explanation: If you choose the indices i=1 and j=2 
    /// (indexed from 0), you will get the maximum value, that is, 
    /// (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
    ///
    /// Example 2:
    /// Input: nums = [1,5,4,5]
    /// Output: 16
    /// Explanation: Choosing the indices i=1 and j=3 (indexed from 0), 
    /// you will get the maximum value of (5-1)*(5-1) = 16.
    ///
    /// Example 3:
    /// Input: nums = [3,7]
    /// Output: 12
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 500
    /// 2. 1 <= nums[i] <= 10^3
    /// </summary>
    int maxProduct(vector<int>& nums);

    /// <summary>
    /// Leet code #1465. Maximum Area of a Piece of Cake After Horizontal 
    ///                  and Vertical Cuts 
    /// 
    /// Medium
    ///
    /// Given a rectangular cake with height h and width w, and two arrays of 
    /// integers horizontalCuts and verticalCuts where horizontalCuts[i] is 
    /// the distance from the top of the rectangular cake to the ith horizontal
    /// cut and similarly, verticalCuts[j] is the distance from the left of the
    /// rectangular cake to the jth vertical cut.
    ///
    /// Return the maximum area of a piece of cake after you cut at each 
    /// horizontal and vertical position provided in the arrays horizontalCuts 
    /// and verticalCuts. Since the answer can be a huge number, return this 
    /// modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
    /// Output: 4 
    /// Explanation: The figure above represents the given rectangular cake. 
    /// Red lines are the horizontal and vertical cuts. After you cut the cake, 
    /// the green piece of cake has the maximum area.
    ///
    /// Example 2:
    /// Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
    /// Output: 6
    /// Explanation: The figure above represents the given rectangular cake. 
    /// Red lines are the horizontal and vertical cuts. After you cut the 
    /// cake, the green and yellow pieces of cake have the maximum area.
    ///
    /// Example 3:
    /// Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
    /// Output: 9
    ///
    /// Constraints:
    /// 1. 2 <= h, w <= 10^9
    /// 2. 1 <= horizontalCuts.length < min(h, 10^5)
    /// 3. 1 <= verticalCuts.length < min(w, 10^5)
    /// 4. 1 <= horizontalCuts[i] < h
    /// 5. 1 <= verticalCuts[i] < w
    /// 6. It is guaranteed that all elements in horizontalCuts are distinct.
    /// 7. It is guaranteed that all elements in verticalCuts are distinct.
    /// </summary>
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts);

    /// <summary>
    /// Leet code #670. Maximum Swap 
    /// 
    /// Given a non-negative integer, you could swap two digits at most once 
    /// to get the maximum valued number. Return the maximum valued number 
    /// you could get.
    ///
    /// Example 1:
    /// Input: 2736
    /// Output: 7236
    /// Explanation: Swap the number 2 and the number 7.
    /// Example 2:
    /// Input: 9973
    /// Output: 9973
    /// Explanation: No swap.
    /// Note:
    /// The given number is in the range [0, 10^8]
    /// </summary>
    int maximumSwap(int num);

    /// <summary>
    /// Leet code #825. Friends Of Appropriate Ages
    /// 
    /// Some people will make friend requests. The list of their ages is given 
    /// and ages[i] is the age of the ith person. 
    ///
    /// Person A will NOT friend request person B (B != A) if any of the 
    /// following conditions are true:
    ///
    /// age[B] <= 0.5 * age[A] + 7
    /// age[B] > age[A]
    /// age[B] > 100 && age[A] < 100
    /// Otherwise, A will friend request B.
    ///
    /// Note that if A requests B, B does not necessarily request A.  Also, 
    /// people will not friend request themselves.
    ///
    /// How many total friend requests are made?
    ///
    /// Example 1:
    ///
    /// Input: [16,16]
    /// Output: 2
    /// Explanation: 2 people friend request each other.
    /// Example 2:
    ///
    /// Input: [16,17,18]
    /// Output: 2
    /// Explanation: Friend requests are made 17 -> 16, 18 -> 17.
    ///
    /// Example 3:
    /// Input: [20,30,100,110,120]
    /// Output: 
    /// Explanation: Friend requests are made 110 -> 100, 120 -> 110, 
    /// 120 -> 100.
    ///
    ///
    /// Notes:
    ///
    /// 1. 1 <= ages.length <= 20000.
    /// 2. 1 <= ages[i] <= 120.
    /// </summary>
    int numFriendRequests(vector<int>& ages);

    /// <summary>
    /// Leet code #939. Minimum Area Rectangle
    /// 
    /// Given a set of points in the xy-plane, determine the minimum area of a 
    /// rectangle formed from these points, with sides parallel to the x and y 
    /// axes.
    ///
    /// If there isn't any rectangle, return 0.
    /// 
    /// Example 1:
    ///
    /// Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
    /// Output: 4
    ///
    /// Example 2:
    /// 
    /// Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
    /// Output: 2
    ///  
    /// Note:
    ///
    /// 1. 1 <= points.length <= 500
    /// 2. 0 <= points[i][0] <= 40000
    /// 3. 0 <= points[i][1] <= 40000
    /// 4. All points are distinct.
    /// </summary>
    int minAreaRect(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #1492. The kth Factor of n
    /// 
    /// Medium
    ///
    /// Given two positive integers n and k.
    ///
    /// A factor of an integer n is defined as an integer i where n % i == 0.
    ///
    /// Consider a list of all factors of n sorted in ascending order, return 
    /// the kth factor in this list or return -1 if n has less than k factors.
    /// 
    /// Example 1:
    /// Input: n = 12, k = 3
    /// Output: 3
    /// Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
    ///
    /// Example 2:
    /// Input: n = 7, k = 2
    /// Output: 7
    /// Explanation: Factors list is [1, 7], the 2nd factor is 7.
    ///
    /// Example 3:
    /// Input: n = 4, k = 4
    /// Output: -1
    /// Explanation: Factors list is [1, 2, 4], there is only 3 factors. We 
    /// should return -1.
    ///
    /// Example 4:
    /// Input: n = 1, k = 1
    /// Output: 1
    /// Explanation: Factors list is [1], the 1st factor is 1.
    ///
    /// Example 5:
    /// Input: n = 1000, k = 3
    /// Output: 4
    /// Explanation: Factors list is [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 
    /// 125, 200, 250, 500, 1000].
    ///
    /// Constraints:
    /// 1. 1 <= k <= n <= 1000
    /// </summary>
    int kthFactor(int n, int k);

    /// <summary>
    /// Leet code #1503. Last Moment Before All Ants Fall Out of a Plank
    /// 
    /// Medium
    ///
    /// We have a wooden plank of the length n units. Some ants are walking 
    /// on the plank, each ant moves with speed 1 unit per second. Some of 
    /// the ants move to the left, the other move to the right.
    /// 
    /// When two ants moving in two different directions meet at some point, 
    /// they change their directions and continue moving again. Assume 
    /// changing directions doesn't take any additional time.
    ///
    /// When an ant reaches one end of the plank at a time t, it falls out of 
    /// the plank imediately.
    ///
    /// Given an integer n and two integer arrays left and right, the 
    /// positions of the ants moving to the left and the right. Return the 
    /// moment when the last ant(s) fall out of the plank.
    /// 
    /// Example 1:
    /// Input: n = 4, left = [4,3], right = [0,1]
    /// Output: 4
    /// Explanation: In the image above:
    /// -The ant at index 0 is named A and going to the right.
    /// -The ant at index 1 is named B and going to the right.
    /// -The ant at index 3 is named C and going to the left.
    /// -The ant at index 4 is named D and going to the left.
    /// Note that the last moment when an ant was on the plank is t = 4 
    /// second, after that it falls imediately out of the plank. (i.e. We can 
    /// say that at t = 4.0000000001, there is no ants on the plank).
    ///
    /// Example 2:
    /// Input: n = 7, left = [], right = [0,1,2,3,4,5,6,7]
    /// Output: 7
    /// Explanation: All ants are going to the right, the ant at index 0 
    /// needs 7 seconds to fall.
    ///
    /// Example 3:
    /// 
    /// Input: n = 7, left = [0,1,2,3,4,5,6,7], right = []
    /// Output: 7
    /// Explanation: All ants are going to the left, the ant at index 7 
    /// needs 7 seconds to fall.
    ///
    /// Example 4:
    /// Input: n = 9, left = [5], right = [4]
    /// Output: 5
    /// Explanation: At t = 1 second, both ants will be at the same intial 
    /// position but with different direction.
    ///
    /// Example 5:
    ///
    /// Input: n = 6, left = [6], right = [0]
    /// Output: 6
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// 2. 0 <= left.length <= n + 1
    /// 3. 0 <= left[i] <= n
    /// 4. 0 <= right.length <= n + 1
    /// 5. 0 <= right[i] <= n
    /// 5. 1 <= left.length + right.length <= n + 1
    /// 6. All values of left and right are unique, and each value can appear 
    ///    only in one of the two arrays.
    /// </summary>
    int getLastMoment(int n, vector<int>& left, vector<int>& right); 

    /// <summary>
    /// Leet code #1515. Best Position for a Service Centre
    /// </summary>
    double getMinDistSum(double x, double y, vector<vector<int>>& positions);

    /// <summary>
    /// Leet code #1515. Best Position for a Service Centre
    /// 
    /// Hard
    ///
    /// A delivery company wants to build a new service centre in a new city. 
    /// The company knows the positions of all the customers in this city on 
    /// a 2D-Map and wants to build the new centre in a position such that 
    /// the sum of the euclidean distances to all customers is minimum.
    /// Given an array positions where positions[i] = [xi, yi] is the position 
    /// of the ith customer on the map, return the minimum sum of the 
    /// euclidean distances to all customers.
    ///
    /// In other words, you need to choose the position of the service centre 
    /// [xcentre, ycentre] such that the following formula is minimized:
    /// Answers within 10^-5 of the actual value will be accepted.
    /// 
    /// Example 1:
    /// Input: positions = [[0,1],[1,0],[1,2],[2,1]]
    /// Output: 4.00000
    /// Explanation: As shown, you can see that choosing 
    /// [xcentre, ycentre] = [1, 1] will make the distance to each 
    /// customer = 1, the sum of all distances is 4 which is the minimum 
    /// possible we can achieve.
    ///
    /// Example 2:
    /// Input: positions = [[1,1],[3,3]]
    /// Output: 2.82843
    /// Explanation: The minimum possible sum of distances = 
    /// sqrt(2) + sqrt(2) = 2.82843
    ///
    /// Example 3:
    /// Input: positions = [[1,1]]
    /// Output: 0.00000
    ///
    /// Example 4:
    /// Input: positions = [[1,1],[0,0],[2,0]]
    /// Output: 2.73205
    /// Explanation: At the first glance, you may think that locating the 
    /// centre at [1, 0] will achieve the minimum sum, but locating it 
    /// at [1, 0] will make the sum of distances = 3.
    /// Try to locate the centre at [1.0, 0.5773502711] you will see that 
    /// the sum of distances is 2.73205.
    /// Be careful with the precision!
    ///
    /// Example 5:
    /// Input: positions = [[0,1],[3,2],[4,5],[7,6],[8,9],[11,1],[2,12]]
    /// Output: 32.94036
    /// Explanation: You can use [4.3460852395, 4.9813795505] as the position 
    /// of the centre.
    ///
    /// Constraints:
    /// 1. 1 <= positions.length <= 50
    /// 2. positions[i].length == 2
    /// 3. 0 <= positions[i][0], positions[i][1] <= 100
    /// </summary>
    double getMinDistSum(vector<vector<int>>& positions);

    /// <summary>
    /// Leet code #1518. Water Bottles
    /// 
    /// Easy
    ///
    /// Given numBottles full water bottles, you can exchange numExchange 
    /// empty water bottles for one full water bottle.
    ///
    /// The operation of drinking a full water bottle turns it into an empty 
    /// bottle.
    ///
    /// Return the maximum number of water bottles you can drink.
    /// Example 1:
    /// Input: numBottles = 9, numExchange = 3
    /// Output: 13
    /// Explanation: You can exchange 3 empty bottles to get 1 full water 
    /// bottle.
    /// Number of water bottles you can drink: 9 + 3 + 1 = 13.
    ///
    /// Example 2:
    /// Input: numBottles = 15, numExchange = 4
    /// Output: 19
    /// Explanation: You can exchange 4 empty bottles to get 1 full water 
    /// bottle. 
    /// Number of water bottles you can drink: 15 + 3 + 1 = 19.
    ///
    /// Example 3:
    /// Input: numBottles = 5, numExchange = 5
    /// Output: 6
    ///
    /// Example 4:
    /// Input: numBottles = 2, numExchange = 3
    /// Output: 2
    /// 
    /// Constraints:
    /// 1. 1 <= numBottles <= 100
    /// 2. 2 <= numExchange <= 100
    /// </summary>
    int numWaterBottles(int numBottles, int numExchange);

    /// <summary>
    /// Leet code #1523. Count Odd Numbers in an Interval Range
    /// 
    /// Easy
    ///
    /// Given two non-negative integers low and high. Return the count of odd 
    /// numbers between low and high (inclusive).
    ///
    /// Example 1:
    /// Input: low = 3, high = 7
    /// Output: 3
    /// Explanation: The odd numbers between 3 and 7 are [3,5,7].
    ///
    /// Example 2:
    /// Input: low = 8, high = 10
    /// Output: 1
    /// Explanation: The odd numbers between 8 and 10 are [9].
    /// 
    /// Constraints:
    /// 1. 0 <= low <= high <= 10^9
    /// </summary>
    int countOdds(int low, int high);

    /// <summary>
    /// Leet code #1551. Minimum Operations to Make Array EqualMedium
    /// 
    /// Medium
    ///
    /// You have an array arr of length n where arr[i] = (2 * i) + 1 for 
    /// all valid values of i (i.e. 0 <= i < n).
    ///
    /// In one operation, you can select two indices x and y where 
    /// 0 <= x, y < n and subtract 1 from arr[x] and add 1 to arr[y] 
    /// (i.e. perform arr[x] -=1 and arr[y] += 1). The goal is to make all 
    /// the elements of the array equal. It is guaranteed that all the 
    /// elements of the array can be made equal using some operations.
    ///
    /// Given an integer n, the length of the array. Return the minimum 
    /// number of operations needed to make all the elements of arr equal.
    ///
    /// Example 1:
    /// Input: n = 3
    /// Output: 2
    /// Explanation: arr = [1, 3, 5]
    /// First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
    /// In the second operation choose x = 2 and y = 0 again, thus 
    /// arr = [3, 3, 3].
    ///
    /// Example 2:
    /// Input: n = 6
    /// Output: 9
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// </summary>
    int minOperations(int n);

    /// <summary>
    /// Leet code #1558. Minimum Numbers of Function Calls to Make Target Array
    /// 
    /// Medium
    ///
    /// Your task is to form an integer array nums from an initial array of 
    /// zeros arr that is the same size as nums.
    ///
    /// Return the minimum number of function calls to make nums from arr.
    ///
    /// The answer is guaranteed to fit in a 32-bit signed integer.
    /// 
    /// Example 1:
    /// Input: nums = [1,5]
    /// Output: 5
    /// Explanation: Increment by 1 (second element): [0, 0] to 
    /// get [0, 1] (1 operation).
    /// Double all the elements: [0, 1] -> [0, 2] -> [0, 4] (2 operations).
    /// Increment by 1 (both elements)  [0, 4] -> [1, 4] -> [1, 5] 
    /// (2 operations).
    /// Total of operations: 1 + 2 + 2 = 5.
    ///
    /// Example 2:
    /// Input: nums = [2,2]
    /// Output: 3
    /// Explanation: Increment by 1 (both elements) [0, 0] -> [0, 1] -> [1, 1] 
    /// (2 operations).
    /// Double all the elements: [1, 1] -> [2, 2] (1 operation).
    /// Total of operations: 2 + 1 = 3.
    ///
    /// Example 3:
    /// Input: nums = [4,2,5]
    /// Output: 6
    /// Explanation: (initial)[0,0,0] -> [1,0,0] -> [1,0,1] -> [2,0,2] -> 
    /// [2,1,2] -> [4,2,4] -> [4,2,5](nums).
    ///
    /// Example 4:
    /// Input: nums = [3,2,2,4]
    /// Output: 7
    ///
    /// Example 5:
    /// Input: nums = [2,4,8,16]
    /// Output: 8
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i] <= 10^9
    /// </summary>
    int minOperations(vector<int>& nums);

    /// <summary>
    /// Leet code #1560. Most Visited Sector in a Circular Track
    /// 
    /// Easy
    ///
    /// Given an integer n and an integer array rounds. We have a circular 
    /// track which consists of n sectors labeled from 1 to n. A marathon 
    /// will be held on this track, the marathon consists of m rounds. The 
    /// ith round starts at sector rounds[i - 1] and ends at sector rounds[i]. 
    /// For example, round 1 starts at sector rounds[0] and ends at sector 
    /// rounds[1]
    ///
    /// Return an array of the most visited sectors sorted in ascending order.
    /// Notice that you circulate the track in ascending order of sector 
    /// numbers in the counter-clockwise direction (See the first example).
    /// 
    /// Example 1:
    /// Input: n = 4, rounds = [1,3,1,2]
    /// Output: [1,2]
    /// Explanation: The marathon starts at sector 1. The order of the visited 
    /// sectors is as follows:
    /// 1 --> 2 --> 3 (end of round 1) --> 4 --> 1 (end of round 2) --> 2 
    /// (end of round 3 and the marathon)
    /// We can see that both sectors 1 and 2 are visited twice and they are the 
    /// most visited sectors. Sectors 3 and 4 are visited only once.
    ///
    /// Example 2:
    /// Input: n = 2, rounds = [2,1,2,1,2,1,2,1,2]
    /// Output: [2]
    ///
    /// Example 3:
    /// Input: n = 7, rounds = [1,3,5,7]
    /// Output: [1,2,3,4,5,6,7]
    /// Constraints:
    /// 1. 2 <= n <= 100
    /// 2. 1 <= m <= 100
    /// 3. rounds.length == m + 1
    /// 4. 1 <= rounds[i] <= n
    /// 5. rounds[i] != rounds[i + 1] for 0 <= i < m
    /// </summary>
    vector<int> mostVisited(int n, vector<int>& rounds);

    /// <summary>
    /// Leet code #1561. Maximum Number of Coins You Can Get
    /// 
    /// Medium
    ///
    /// There are 3n piles of coins of varying size, you and your friends 
    /// will take piles of coins as follows:
    ///
    /// In each step, you will choose any 3 piles of coins (not necessarily 
    /// consecutive).
    /// Of your choice, Alice will pick the pile with the maximum number of 
    /// coins.
    /// You will pick the next pile with maximum number of coins.
    /// Your friend Bob will pick the last pile.
    /// Repeat until there are no more piles of coins.
    /// Given an array of integers piles where piles[i] is the number of coins 
    /// in the ith pile.
    ///
    /// Return the maximum number of coins which you can have.
    /// 
    /// Example 1:
    /// Input: piles = [2,4,1,2,7,8]
    /// Output: 9
    /// Explanation: Choose the triplet (2, 7, 8), Alice Pick the pile with 
    /// 8 coins, you the pile with 7 coins and Bob the last one.
    /// Choose the triplet (1, 2, 4), Alice Pick the pile with 4 coins, you 
    /// the pile with 2 coins and Bob the last one.
    /// The maximum number of coins which you can have are: 7 + 2 = 9.
    /// On the other hand if we choose this arrangement (1, 2, 8), (2, 4, 7) you 
    /// only get 2 + 4 = 6 coins which is not optimal.
    ///
    /// Example 2:
    /// Input: piles = [2,4,5]
    /// Output: 4
    ///
    /// Example 3:   
    /// Input: piles = [9,8,7,6,5,1,2,3,4]
    /// Output: 18
    ///
    /// Constraints:
    /// 1. 3 <= piles.length <= 10^5
    /// 2. piles.length % 3 == 0
    /// 3. 1 <= piles[i] <= 10^4
    /// </summary>
    int maxCoins(vector<int>& piles);

    /// <summary>
    /// Leet code #1610. Maximum Number of Visible Points
    /// 
    /// Hard
    ///
    /// You are given an array points, an integer angle, and your location, 
    /// where location = [pos[x], pos[y]] and points[i] = [x[i], y[i]] both 
    /// denote integral coordinates on the X-Y plane.
    ///
    /// Initially, you are facing directly east from your position. You cannot 
    /// move from your position, but you can rotate. In other words, pos[x] 
    /// and pos[y] cannot be changed. Your field of view in degrees is 
    /// represented by angle, determining how wide you can see from any given 
    /// view direction. Let d be the amount in degrees that you rotate 
    /// counterclockwise. Then, your field of view is the inclusive range of 
    /// angles [d - angle/2, d + angle/2].
    /// 
    /// You can see some set of points if, for each point, the angle formed by 
    /// the point, your position, and the immediate east direction from your 
    /// position is in your field of view.
    ///
    /// There can be multiple points at one coordinate. There may be points at 
    /// your location, and you can always see these points regardless of your 
    /// rotation. Points do not obstruct your vision to other points.
    ///
    /// Return the maximum number of points you can see.
    /// 
    /// Example 1:
    /// Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
    /// Output: 3
    /// Explanation: The shaded region represents your field of view. All 
    /// points can be made visible in your field of view, including [3,3] 
    /// even though [2,2] is in front and in the same line of sight.
    ///
    /// Example 2:
    /// Input: points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
    /// Output: 4
    /// Explanation: All points can be made visible in your field of view, 
    /// including the one at your location.
    ///
    /// Example 3:
    /// Input: points = [[1,0],[2,1]], angle = 13, location = [1,1]
    /// Output: 1
    /// Explanation: You can only see one of the two points, as shown above.
    ///
    /// Constraints:
    /// 1. 1 <= points.length <= 10^5
    /// 2. points[i].length == 2
    /// 3. location.length == 2
    /// 4. 0 <= angle < 360
    /// 5. 0 <= pos[x], pos[y], x[i], y[i] <= 10^9
    /// </summary>
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location);

    /// <summary>
    /// Leet code #1611. Minimum One Bit Operations to Make Integers Zero
    /// 
    /// Hard
    ///
    /// Given an integer n, you must transform it into 0 using the following 
    /// operations any number of times:
    ///
    /// Change the rightmost (0th) bit in the binary representation of n.
    /// Change the ith bit in the binary representation of n if the (i-1)th 
    /// bit is set to 1 and the (i-2)th through 0th bits are set to 0.
    /// Return the minimum number of operations to transform n into 0.
    /// 
    /// Example 1:
    /// Input: n = 0
    /// Output: 0
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: 2
    /// Explanation: The binary representation of 3 is "11".
    /// "11" -> "01" with the 2nd operation since the 0th bit is 1.
    /// "01" -> "00" with the 1st operation.
    /// Example 3:
    ///
    /// Input: n = 6
    /// Output: 4
    /// Explanation: The binary representation of 6 is "110".
    /// "110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th 
    /// through 0th bits are 0.
    /// "010" -> "011" with the 1st operation.
    /// "011" -> "001" with the 2nd operation since the 0th bit is 1.
    /// "001" -> "000" with the 1st operation.
    ///
    /// Example 4:
    /// Input: n = 9
    /// Output: 14
    ///
    /// Example 5:
    /// Input: n = 333
    /// Output: 393
    /// 
    /// Constraints:
    /// 1. 0 <= n <= 10^9
    /// </summary>
    int minimumOneBitOperations(int n);

    /// <summary>
    /// Leet code #1619. Mean of Array After Removing Some Elements
    /// 
    /// Easy
    ///
    /// Given an integer array arr, return the mean of the remaining integers 
    /// after removing the smallest 5% and the largest 5% of the elements.
    ///
    /// Answers within 10-5 of the actual answer will be considered accepted.
    /// 
    /// Example 1:
    /// Input: arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
    /// Output: 2.00000
    /// Explanation: After erasing the minimum and the maximum values of this 
    /// array, all elements are equal to 2, so the mean is 2.
    ///
    /// Example 2:
    /// Input: arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
    /// Output: 4.00000
    ///
    /// Example 3:
    ///
    /// Input: arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,
    /// 8,5,10,8,6,6,1,0,6,10,8,2,3,4]
    /// Output: 4.77778
    ///
    /// Example 4:
    /// Input: arr = [9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,8,6,3,3,5,
    /// 1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3]
    /// Output: 5.27778
    ///
    /// Example 5:
    /// Input: arr = [4,8,4,10,0,7,1,3,7,8,8,3,4,1,6,2,1,1,8,0,9,8,0,3,9,10,
    /// 3,10,1,10,7,3,2,1,4,9,10,7,6,4,0,8,5,1,2,1,6,2,5,0,7,10,9,10,3,7,10,5,
    /// 8,5,7,6,7,6,10,9,5,10,5,5,7,2,10,7,7,8,2,0,1,1]
    /// Output: 5.29167
    ///
    /// Constraints:
    /// 1. 20 <= arr.length <= 1000
    /// 2. arr.length is a multiple of 20.
    /// 3. 0 <= arr[i] <= 10^5
    /// </summary>
    double trimMean(vector<int>& arr);

    /// <summary>
    /// Leet code #1620. Coordinate With Maximum Network Quality
    /// 
    /// Medium
    ///
    /// You are given an array of network towers towers and an integer radius, 
    /// where towers[i] = [xi, yi, qi] denotes the ith network tower with 
    /// location (xi, yi) and quality factor qi. All the coordinates are 
    /// integral coordinates on the X-Y plane, and the distance between two 
    /// coordinates is the Euclidean distance.
    ///
    /// The integer radius denotes the maximum distance in which the tower is 
    /// reachable. The tower is reachable if the distance is less than or equal 
    /// to radius. Outside that distance, the signal becomes garbled, and the 
    /// tower is not reachable.
    ///
    /// The signal quality of the ith tower at a coordinate (x, y) is 
    /// calculated with the formula (qi / (1 + d)), where d is the distance 
    /// between the tower and the coordinate. The network quality at a 
    /// coordinate is the sum of the signal qualities from all the reachable 
    /// towers.
    /// 
    /// Return the integral coordinate where the network quality is maximum. If 
    /// there are multiple coordinates with the same network quality, return 
    /// the lexicographically minimum coordinate.
    ///
    /// Note:
    /// 1. A coordinate (x1, y1) is lexicographically smaller than (x2, y2) if 
    ///    either x1 < x2 or x1 == x2 and y1 < y2.
    /// 2. (val) is the greatest integer less than or equal to val (the floor 
    ///    function).
    ///
    /// Example 1:
    /// Input: towers = [[1,2,5],[2,1,7],[3,1,9]], radius = 2
    /// Output: [2,1]
    /// Explanation: 
    /// At coordinate (2, 1) the total quality is 13
    /// - Quality of 7 from (2, 1) results in (7 / (1 + sqrt(0)) = 7
    /// - Quality of 5 from (1, 2) results in (5 / (1 + sqrt(2)) = 2.07 = 2
    /// - Quality of 9 from (3, 1) results in (9 / (1 + sqrt(1)) = 4.5 = 4
    /// No other coordinate has higher quality.
    ///
    /// Example 2:
    /// Input: towers = [[23,11,21]], radius = 9
    /// Output: [23,11]
    ///
    /// Example 3:
    /// Input: towers = [[1,2,13],[2,1,7],[0,1,9]], radius = 2
    /// Output: [1,2]
    ///
    /// Example 4:
    /// Input: towers = [[2,1,9],[0,1,9]], radius = 2
    /// Output: [0,1]
    /// Explanation: Both (0, 1) and (2, 1) are optimal in terms of quality 
    /// but (0, 1) is lexicograpically minimal.
    ///
    /// Constraints:
    /// 1. 1 <= towers.length <= 50
    /// 2. towers[i].length == 3
    /// 3. 0 <= xi, yi, qi <= 50
    /// 4. 1 <= radius <= 50
    /// </summary>
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius);

    /// <summary>
    /// Leet code #1643. Kth Smallest Instructions
    /// 
    /// Hard
    ///
    /// Bob is standing at cell (0, 0), and he wants to reach destination: 
    /// (row, column). He can only travel right and down. You are going to 
    /// help Bob by providing instructions for him to reach destination.
    ///
    /// The instructions are represented as a string, where each character 
    /// is either:
    ///
    /// 'H', meaning move horizontally (go right), or
    /// 'V', meaning move vertically (go down).
    /// Multiple instructions will lead Bob to destination. For example, if 
    /// destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.
    ///
    /// However, Bob is very picky. Bob has a lucky number k, and he wants the 
    /// kth lexicographically smallest instructions that will lead him to 
    /// destination. k is 1-indexed.
    ///
    /// Given an integer array destination and an integer k, return the kth 
    /// lexicographically smallest instructions that will take Bob to 
    /// destination.
    /// 
    /// Example 1:
    /// Input: destination = [2,3], k = 1
    /// Output: "HHHVV"
    /// Explanation: All the instructions that reach (2, 3) in lexicographic 
    /// order are as follows:
    /// ["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", 
    /// "VHVHH", "VVHHH"].
    ///
    /// Example 2: 
    /// Input: destination = [2,3], k = 2
    /// Output: "HHVHV"
    ///
    /// Example 3:
    /// Input: destination = [2,3], k = 3
    /// Output: "HHVVH"
    /// Constraints:
    /// 1. destination.length == 2
    /// 2. 1 <= row, column <= 15
    /// 3. 1 <= k <= nCr(row + column, row), where nCr(a, b) denotes a choose b​​​​​.
    /// </summary>
    string kthSmallestPath(vector<int>& destination, int k);

    /// <summary>
    /// Leet code #1648. Sell Diminishing-Valued Colored Balls
    /// 
    /// Medium
    ///
    /// You have an inventory of different colored balls, and there is a customer 
    /// that wants orders balls of any color.
    ///
    /// The customer weirdly values the colored balls. Each colored ball's value 
    /// is the number of balls of that color you currently have in your inventory. 
    /// For example, if you own 6 yellow balls, the customer would pay 6 for the 
    /// first yellow ball. After the transaction, there are only 5 yellow balls 
    /// left, so the next yellow ball is then valued at 5 (i.e., the value of the 
    /// balls decreases as you sell more to the customer).
    ///
    /// You are given an integer array, inventory, where inventory[i] represents 
    /// the number of balls of the ith color that you initially own. You are also 
    /// given an integer orders, which represents the total number of balls that 
    /// the customer wants. You can sell the balls in any order.
    ///
    /// Return the maximum total value that you can attain after selling orders 
    /// colored balls. As the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: inventory = [2,5], orders = 4
    /// Output: 14
    /// Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 
    /// times (5 + 4 + 3).
    /// The maximum total value is 2 + 5 + 4 + 3 = 14.
    ///
    /// Example 2:
    /// Input: inventory = [3,5], orders = 6
    /// Output: 19
    /// Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 
    /// times (5 + 4 + 3 + 2).
    /// The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.
    ///
    /// Example 3:
    /// Input: inventory = [2,8,4,10,6], orders = 20
    /// Output: 110
    ///
    /// Example 4:
    /// Input: inventory = [1000000000], orders = 1000000000
    /// Output: 21
    /// Explanation: Sell the 1st color 1000000000 times for a total value of 
    /// 500000000500000000. 500000000500000000 modulo 109 + 7 = 21.
    /// 
    /// Constraints:
    /// 1. 1 <= inventory.length <= 10^5
    /// 2. 1 <= inventory[i] <= 10^9
    /// 3. 1 <= orders <= min(sum(inventory[i]), 10^9)
    /// </summary>
    int maxProfit(vector<int>& inventory, int orders);

    /// <summary>
    /// Leet code #1663. Smallest String With A Given Numeric Value
    /// 
    /// Medium
    ///
    /// The numeric value of a lowercase character is defined as its position 
    /// (1-indexed) in the alphabet, so the numeric value of a is 1, the 
    /// numeric value of b is 2, the numeric value of c is 3, and so on.
    ///
    /// The numeric value of a string consisting of lowercase characters is 
    /// defined as the sum of its characters' numeric values. For example, 
    /// the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.
    ///
    /// You are given two integers n and k. Return the lexicographically 
    /// smallest string with length equal to n and numeric value equal to k.
    ///
    /// Note that a string x is lexicographically smaller than string y if x 
    /// comes before y in dictionary order, that is, either x is a prefix of y, 
    /// or if i is the first position such that x[i] != y[i], then x[i] comes 
    /// before y[i] in alphabetic order.
    ///
    /// Example 1:
    /// Input: n = 3, k = 27
    /// Output: "aay"
    /// Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it 
    /// is the smallest string with such a value and length equal to 3.
    ///
    /// Example 2:
    /// Input: n = 5, k = 73
    /// Output: "aaszz"
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. n <= k <= 26 * n
    /// </summary>
    string getSmallestString(int n, int k);

    /// <summary>
    /// Leet code #1680. Concatenation of Consecutive Binary Numbers
    /// 
    /// Medium
    /// 
    /// Given an integer n, return the decimal value of the binary string 
    /// formed by concatenating the binary representations of 1 to n in order, 
    /// modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: n = 1
    /// Output: 1
    /// Explanation: "1" in binary corresponds to the decimal value 1. 
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: 27
    /// Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
    /// After concatenating them, we have "11011", which corresponds to the 
    /// decimal value 27.
    ///
    /// Example 3:
    /// Input: n = 12
    /// Output: 505379714
    /// Explanation: The concatenation results in 
    /// "1101110010111011110001001101010111100".
    /// The decimal value of that is 118505380540.
    /// After modulo 10^9 + 7, the result is 505379714.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// </summary>
    int concatenatedBinary(int n);

    /// <summary>
    /// Leet code #1688. Count of Matches in Tournament
    /// 
    /// Easy
    /// 
    /// You are given an integer n, the number of teams in a tournament that has 
    /// strange rules:
    ///
    /// If the current number of teams is even, each team gets paired with another 
    /// team. A total of n / 2 matches are played, and n / 2 teams advance to the 
    /// next round.
    /// If the current number of teams is odd, one team randomly advances in the 
    /// tournament, and the rest gets paired. A total of (n - 1) / 2 matches are 
    /// played, and (n - 1) / 2 + 1 teams advance to the next round.
    /// Return the number of matches played in the tournament until a winner is 
    /// decided.
    ///
    /// Example 1:
    /// Input: n = 7
    /// Output: 6
    /// Explanation: Details of the tournament: 
    /// - 1st Round: Teams = 7, Matches = 3, and 4 teams advance.
    /// - 2nd Round: Teams = 4, Matches = 2, and 2 teams advance.
    /// - 3rd Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
    /// Total number of matches = 3 + 2 + 1 = 6.
    ///
    /// Example 2:
    /// Input: n = 14
    /// Output: 13
    /// Explanation: Details of the tournament:
    /// - 1st Round: Teams = 14, Matches = 7, and 7 teams advance.
    /// - 2nd Round: Teams = 7, Matches = 3, and 4 teams advance.
    /// - 3rd Round: Teams = 4, Matches = 2, and 2 teams advance.
    /// - 4th Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
    /// Total number of matches = 7 + 3 + 2 + 1 = 13.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 200
    /// </summary>
    int numberOfMatches(int n);

    /// <summary>
    /// Leet code #1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
    /// 
    /// Medium
    /// 
    /// A decimal number is called deci-binary if each of its digits is either 0 
    /// or 1 without any leading zeros. For example, 101 and 1100 are deci-binary,
    /// while 112 and 3001 are not.
    ///
    /// Given a string n that represents a positive decimal integer, return the 
    /// minimum number of positive deci-binary numbers needed so that they sum 
    /// up to n.
    ///
    /// Example 1:
    /// Input: n = "32"
    /// Output: 3
    /// Explanation: 10 + 11 + 11 = 32
    ///
    /// Example 2:
    /// Input: n = "82734"
    /// Output: 8
    ///
    /// Example 3:
    /// Input: n = "27346209830709182346"
    /// Output: 9
    /// 
    /// Constraints:
    /// 1. 1 <= n.length <= 105
    /// 2. n consists of only digits.
    /// 3. n does not contain any leading zeros and represents a positive 
    ///    integer.
    /// </summary>
    int minPartitions(string n);

    /// <summary>
    /// Leet code #1716. Calculate Money in Leetcode Bank
    /// 
    /// Easy
    /// 
    /// Hercy wants to save money for his first car. He puts money in the 
    /// Leetcode bank every day.
    ///
    /// He starts by putting in $1 on Monday, the first day. Every day from 
    /// Tuesday to Sunday, he will put in $1 more than the day before. On 
    /// every subsequent Monday, he will put in $1 more than the previous 
    /// Monday.
    /// Given n, return the total amount of money he will have in the Leetcode 
    /// bank at the end of the nth day.
    /// 
    /// Example 1:
    /// Input: n = 4
    /// Output: 10
    /// Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
    ///
    /// Example 2:
    /// Input: n = 10
    /// Output: 37
    /// Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 
    /// 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy 
    /// only puts in $2.
    ///
    /// Example 3:
    /// Input: n = 20
    /// Output: 96
    /// Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 
    /// 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// </summary>
    int totalMoney(int n);

    /// <summary>
    /// Leet code 1742. Maximum Number of Balls in a Box
    /// 
    /// Easy
    /// 
    /// You are working in a ball factory where you have n balls numbered from
    /// lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), 
    /// and an infinite number of boxes numbered from 1 to infinity.
    /// 
    /// Your job at this factory is to put each ball in the box with a number 
    /// equal to the sum of digits of the ball's number. For example, the ball 
    /// number 321 will be put in the box number 3 + 2 + 1 = 6 and the ball 
    /// number 10 will be put in the box number 1 + 0 = 1.
    ///
    /// Given two integers lowLimit and highLimit, return the number of balls 
    /// in the box with the most balls.
    ///
    /// Example 1:
    /// 
    /// Input: lowLimit = 1, highLimit = 10
    /// Output: 2
    /// Explanation:
    /// Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
    /// Ball Count:  2 1 1 1 1 1 1 1 1 0  0  ...
    /// Box 1 has the most number of balls with 2 balls.
    ///
    /// Example 2:
    ///
    /// Input: lowLimit = 5, highLimit = 15
    /// Output: 2
    /// Explanation:
    /// Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
    /// Ball Count:  1 1 1 1 2 2 1 1 1 0  0  ...
    /// Boxes 5 and 6 have the most number of balls with 2 balls in each.
    ///
    /// Example 3:
    /// Input: lowLimit = 19, highLimit = 28
    /// Output: 2
    /// Explanation:
    /// Box Number:  1 2 3 4 5 6 7 8 9 10 11 12 ...
    /// Ball Count:  0 1 1 1 1 1 1 1 1 2  0  0  ...
    /// Box 10 has the most number of balls with 2 balls.
    ///
    /// Constraints:
    /// 1. 1 <= lowLimit <= highLimit <= 10^5
    /// </summary>
    int countBalls(int lowLimit, int highLimit);

    /// <summary>
    /// Leet code 1758. Minimum Changes To Make Alternating Binary String
    /// 
    /// Easy
    /// 
    /// You are given a string s consisting only of the characters '0' 
    /// and '1'. In one operation, you can change any '0' to '1' or vice 
    /// versa.
    ///
    /// The string is called alternating if no two adjacent characters are 
    /// equal. For example, the string "010" is alternating, while the 
    /// string "0100" is not.
    ///
    /// Return the minimum number of operations needed to make s alternating.
    /// 
    /// Example 1:
    /// Input: s = "0100"
    /// Output: 1
    /// Explanation: If you change the last character to '1', s will 
    /// be "0101", which is alternating.
    ///
    /// Example 2:
    /// Input: s = "10"
    /// Output: 0
    /// Explanation: s is already alternating.
    ///
    /// Example 3:
    /// Input: s = "1111"
    /// Output: 2
    /// Explanation: You need two operations to reach "0101" or "1010".
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 10^4
    /// 2. s[i] is either '0' or '1'.
    /// </summary>
    int minOperations(string s);

    /// <summary>
    /// Leet code 1735. Count Ways to Make Array With Product
    /// 
    /// Hard
    /// 
    /// You are given a 2D integer array, queries. For each queries[i], 
    /// where queries[i] = [ni, ki], find the number of different ways 
    /// you can place positive integers into an array of size ni such 
    /// that the product of the integers is ki. As the number of ways 
    /// may be too large, the answer to the ith query is the number of 
    /// ways modulo 109 + 7.
    ///
    /// Return an integer array answer where answer.length == 
    /// queries.length, and answer[i] is the answer to the ith query.
    ///
    /// Example 1:
    /// Input: queries = [[2,6],[5,1],[73,660]]
    /// Output: [4,1,50734910]
    /// Explanation: Each query is independent.
    /// [2,6]: There are 4 ways to fill an array of size 2 that 
    /// multiply to 6: [1,6], [2,3], [3,2], [6,1].
    /// [5,1]: There is 1 way to fill an array of size 5 that multiply 
    /// to 1: [1,1,1,1,1].
    /// [73,660]: There are 1050734917 ways to fill an array of size 73 
    /// that multiply to 660. 1050734917 modulo 109 + 7 = 50734910.
    /// Example 2:
    ///
    /// Input: queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
    /// Output: [1,2,3,10,5]
    /// 
    /// Constraints:
    /// 1. 1 <= queries.length <= 10^4
    /// 2. 1 <= ni, ki <= 10^4
    /// </summary>
    vector<int> waysToFillArray(vector<vector<int>>& queries);

    /// <summary>
    /// Leet code 1739. Building Boxes
    /// 
    /// Hard
    /// 
    /// You have a cubic storeroom where the width, length, and height of the 
    /// room are all equal to n units. You are asked to place n boxes in this 
    /// room where each box is a cube of unit side length. There are however 
    /// some rules to placing the boxes:
    ///
    /// You can place the boxes anywhere on the floor.
    /// If box x is placed on top of the box y, then each side of the four 
    /// vertical sides of the box y must either be adjacent to another box or 
    /// to a wall.
    /// Given an integer n, return the minimum possible number of boxes 
    /// touching the floor.
    /// 
    /// Example 1:
    /// Input: n = 3
    /// Output: 3
    /// Explanation: The figure above is for the placement of the three boxes.
    /// These boxes are placed in the corner of the room, where the corner is 
    /// on the left side.
    ///
    /// Example 2:
    /// Input: n = 4
    /// Output: 3
    /// Explanation: The figure above is for the placement of the four boxes.
    /// These boxes are placed in the corner of the room, where the corner is 
    /// on the left side.
    ///
    /// Example 3:
    /// Input: n = 10
    /// Output: 6
    /// Explanation: The figure above is for the placement of the ten boxes.
    /// These boxes are placed in the corner of the room, where the corner is 
    /// on the back side.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^9
    /// </summary>
    int minimumBoxes(int n);

    /// <summary>
    /// Leet code 1753. Maximum Score From Removing Stones
    /// 
    /// Medium
    /// 
    /// You are playing a solitaire game with three piles of stones of sizes 
    /// a, b and c respectively. Each turn you choose two different non-empty
    /// piles, take one stone from each, and add 1 point to your score. The 
    /// game stops when there are fewer than two non-empty piles (meaning 
    /// there are no more available moves).
    ///
    /// Given three integers a, b and c, return the maximum score you can get.
    ///
    /// Example 1:
    /// Input: a = 2, b = 4, c = 6
    /// Output: 6
    /// Explanation: The starting state is (2, 4, 6). One optimal set of 
    /// moves is:
    /// - Take from 1st and 3rd piles, state is now (1, 4, 5)
    /// - Take from 1st and 3rd piles, state is now (0, 4, 4)
    /// - Take from 2nd and 3rd piles, state is now (0, 3, 3)
    /// - Take from 2nd and 3rd piles, state is now (0, 2, 2)
    /// - Take from 2nd and 3rd piles, state is now (0, 1, 1)
    /// - Take from 2nd and 3rd piles, state is now (0, 0, 0)
    /// There are fewer than two non-empty piles, so the game ends. 
    /// Total: 6 points.
    ///
    /// Example 2:
    /// Input: a = 4, b = 4, c = 6
    /// Output: 7
    /// Explanation: The starting state is (4, 4, 6). One optimal set of 
    /// moves is:
    /// - Take from 1st and 2nd piles, state is now (3, 3, 6)
    /// - Take from 1st and 3rd piles, state is now (2, 3, 5)
    /// - Take from 1st and 3rd piles, state is now (1, 3, 4)
    /// - Take from 1st and 3rd piles, state is now (0, 3, 3)
    /// - Take from 2nd and 3rd piles, state is now (0, 2, 2)
    /// - Take from 2nd and 3rd piles, state is now (0, 1, 1)
    /// - Take from 2nd and 3rd piles, state is now (0, 0, 0)
    /// There are fewer than two non-empty piles, so the game ends. 
    /// Total: 7 points.
    ///
    /// Example 3:
    /// Input: a = 1, b = 8, c = 8
    /// Output: 8
    /// Explanation: One optimal set of moves is to take from the 2nd and 
    /// 3rd piles for 8 turns until they are empty.
    /// After that, there are fewer than two non-empty piles, so the game ends.
    /// 
    /// Constraints:
    /// 1. 1 <= a, b, c <= 10^5
    /// </summary>
    int maximumScore(int a, int b, int c);

    /// <summary>
    /// Leet code 1780. Check if Number is a Sum of Powers of Three
    /// 
    /// Medium
    /// 
    /// Given an integer n, return true if it is possible to represent n 
    /// as the sum of distinct powers of three. Otherwise, return false.
    ///  
    /// An integer y is a power of three if there exists an integer x such 
    /// that y == 3x.
    /// 
    /// Example 1:
    /// Input: n = 12
    /// Output: true
    /// Explanation: 12 = 31 + 32
    ///
    /// Example 2:
    /// Input: n = 91
    /// Output: true
    /// Explanation: 91 = 30 + 32 + 34
    ///
    /// Example 3:
    /// Input: n = 21
    /// Output: false
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^7
    /// </summary>
    bool checkPowersOfThree(int n);

    /// <summary>
    /// Leet code 1785. Minimum Elements to Add to Form a Given Sum
    /// 
    /// Medium
    /// 
    /// You are given an integer array nums and two integers limit and goal. 
    /// The array nums has an interesting property that abs(nums[i]) <= limit 
    /// 
    /// You are given an integer array nums and two integers limit and goal. 
    /// The array nums has an interesting property that abs(nums[i]) <= limit.
    ///
    /// Return the minimum number of elements you need to add to make the 
    /// sum of the array equal to goal. The array must maintain its property 
    /// that abs(nums[i]) <= limit.
    ///
    /// Note that abs(x) equals x if x >= 0, and -x otherwise.
    /// 
    /// Example 1:
    /// Input: nums = [1,-1,1], limit = 3, goal = -4
    /// Output: 2
    /// Explanation: You can add -2 and -3, then the sum of the array will 
    /// be 1 - 1 + 1 - 2 - 3 = -4.
    ///
    /// Example 2:
    /// Input: nums = [1,-10,9,1], limit = 100, goal = 0
    /// Output: 1
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= limit <= 10^6
    /// 3. -limit <= nums[i] <= limit
    /// 4. -10^9 <= goal <= 10^9
    /// </summary>
    int minElements(vector<int>& nums, int limit, int goal);

    /// <summary>
    /// Leet code 1798. Maximum Number of Consecutive Values You Can Make
    /// 
    /// Medium
    /// 
    /// You are given an integer array coins of length n which represents the
    /// n coins that you own. The value of the ith coin is coins[i]. You can 
    /// make some value x if you can choose some of your n coins such that 
    /// their values sum up to x.
    ///
    /// Return the maximum number of consecutive integer values that you can 
    /// make with your coins starting from and including 0.
    ///
    /// Note that you may have multiple coins of the same value.
    /// 
    /// Example 1:
    /// Input: coins = [1,3]
    /// Output: 2
    /// Explanation: You can make the following values:
    /// - 0: take []
    /// - 1: take [1]
    /// You can make 2 consecutive integer values starting from 0.
    ///
    /// Example 2:
    /// Input: coins = [1,1,1,4]
    /// Output: 8
    /// Explanation: You can make the following values:
    /// - 0: take []
    /// - 1: take [1]
    /// - 2: take [1,1]
    /// - 3: take [1,1,1]
    /// - 4: take [4]
    /// - 5: take [4,1]
    /// - 6: take [4,1,1]
    /// - 7: take [4,1,1,1]
    /// You can make 8 consecutive integer values starting from 0.
    ///
    /// Example 3:
    /// Input: nums = [1,4,10,3,1]
    /// Output: 20
    /// 
    /// Constraints:
    /// 1. coins.length == n
    /// 2. 1 <= n <= 4 * 10^4
    /// 3. 1 <= coins[i] <= 4 * 10^4
    /// </summary>
    int getMaximumConsecutive(vector<int>& coins);

    /// <summary>
    /// Leet code 1808. Maximize Number of Nice Divisors 
    /// 
    /// Hard
    /// 
    /// You are given a positive integer primeFactors. You are asked to 
    /// construct a positive integer n that satisfies the following 
    /// conditions:
    ///
    /// The number of prime factors of n (not necessarily distinct) is at 
    /// most primeFactors.
    /// The number of nice divisors of n is maximized. Note that a divisor 
    /// of n is nice if it is divisible by every prime factor of n. For 
    /// example, if n = 12, then its prime factors are [2,2,3], then 6 and 12 
    /// are nice divisors, while 3 and 4 are not.
    /// Return the number of nice divisors of n. Since that number can be too 
    /// large, return it modulo 10^9 + 7.
    /// 
    /// Note that a prime number is a natural number greater than 1 that is 
    /// not a product of two smaller natural numbers. The prime factors of a 
    /// number n is a list of prime numbers such that their product equals n.
    ///
    /// Example 1:
    /// Input: primeFactors = 5
    /// Output: 6
    /// Explanation: 200 is a valid value of n.
    /// It has 5 prime factors: [2,2,2,5,5], and it has 6 nice divisors: 
    /// [10,20,40,50,100,200].
    /// There is not other value of n that has at most 5 prime factors and more 
    /// nice divisors.
    ///
    /// Example 2:
    /// Input: primeFactors = 8
    /// Output: 18
    /// 
    /// Constraints:
    /// 1. 1 <= primeFactors <= 10^9
    /// </summary>
    int maxNiceDivisors(int primeFactors);

    /// <summary>
    /// Leet code 1812. Determine Color of a Chessboard Square 
    /// 
    /// Easy
    /// 
    /// You are given coordinates, a string that represents the coordinates 
    /// of a square of the chessboard. Below is a chessboard for your 
    /// reference.
    /// 
    /// Return true if the square is white, and false if the square is black.
    ///
    /// The coordinate will always represent a valid chessboard square. The 
    /// coordinate will always have the letter first, and the number second.
    /// 
    /// Example 1:
    /// Input: coordinates = "a1"
    /// Output: false
    /// Explanation: From the chessboard above, the square with coordinates 
    /// "a1" is black, so return false.
    ///
    /// Example 2:
    /// Input: coordinates = "h3"
    /// Output: true
    /// Explanation: From the chessboard above, the square with coordinates 
    /// "h3" is white, so return true.
    ///
    /// Example 3:
    /// Input: coordinates = "c7"
    /// Output: false
    /// 
    /// Constraints:
    /// 1. coordinates.length == 2
    /// 2. 'a' <= coordinates[0] <= 'h'
    /// 3. '1' <= coordinates[1] <= '8'
    /// </summary>
    bool squareIsWhite(string coordinates);

    /// <summary>
    /// Leet code 1819. Number of Different Subsequences GCDs
    /// 
    /// Hard
    /// 
    /// You are given an array nums that consists of positive integers.
    ///
    /// The GCD of a sequence of numbers is defined as the greatest integer 
    /// that divides all the numbers in the sequence evenly.
    ///
    /// For example, the GCD of the sequence [4,6,16] is 2.
    /// A subsequence of an array is a sequence that can be formed by removing 
    /// some elements (possibly none) of the array.
    ///
    /// For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
    /// Return the number of different GCDs among all non-empty subsequences 
    /// of nums.
    /// 
    /// Example 1:
    /// Input: nums = [6,10,3]
    /// Output: 5
    /// Explanation: The figure shows all the non-empty subsequences and their 
    /// GCDs.
    /// The different GCDs are 6, 10, 3, 2, and 1. 
    ///
    /// Example 2:
    /// Input: nums = [5,15,40,5,6]
    /// Output: 7
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 2 * 10^5
    /// </summary>
    int countDifferentSubsequenceGCDs(vector<int>& nums);

    /// <summary>
    /// Leet code 1828. Queries on Number of Points Inside a Circle
    /// 
    /// Medium
    /// 
    /// You are given an array points where points[i] = [xi, yi] is the 
    /// coordinates of the ith point on a 2D plane. Multiple points can 
    /// have the same coordinates.
    ///
    /// You are also given an array queries where queries[j] = [xj, yj, rj] 
    /// describes a circle centered at (xj, yj) with a radius of rj.
    ///
    /// For each query queries[j], compute the number of points inside the 
    /// jth circle. Points on the border of the circle are considered inside.
    ///
    /// Return an array answer, where answer[j] is the answer to the jth query.
    ///
    /// Example 1:
    /// Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = 
    /// [[2,3,1],[4,3,1],[1,1,2]]
    /// Output: [3,2,2]
    /// Explanation: The points and circles are shown above.
    /// queries[0] is the green circle, queries[1] is the red circle, and 
    /// queries[2] is the blue circle.
    ///
    /// Example 2:
    /// Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = 
    /// [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
    /// Output: [2,3,2,4]
    /// Explanation: The points and circles are shown above.
    /// queries[0] is green, queries[1] is red, queries[2] is blue, and 
    /// queries[3] is purple.
    /// 
    /// Constraints:
    /// 1. 1 <= points.length <= 500
    /// 2. points[i].length == 2
    /// 3. 0 <= x​​​​​​i, y​​​​​​i <= 500
    /// 4. 1 <= queries.length <= 500
    /// 5. queries[j].length == 3
    /// 6. 0 <= xj, yj <= 500
    /// 7. 1 <= rj <= 500
    /// 8. All coordinates are integers.
    /// </summary>
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries);
    
    /// <summary>
    /// Leet code 1830. Minimum Number of Operations to Make String Sorted
    /// </summary>
    long long modPow(long long x, long long y, long long m);
    
    /// <summary>
    /// Leet code 1830. Minimum Number of Operations to Make String Sorted
    /// 
    /// Hard
    /// 
    /// You are given a string s (0-indexed). You are asked to perform the 
    /// following operation on s until you get a sorted string:
    /// 
    /// Find the largest index i such that 1 <= i < s.length and 
    /// s[i] < s[i - 1].
    /// Find the largest index j such that i <= j < s.length and 
    /// s[k] < s[i - 1] for all the possible values of k in the range 
    /// [i, j] inclusive.
    /// Swap the two characters at indices i - 1 and j.
    /// Reverse the suffix starting at index i.
    /// Return the number of operations needed to make the string sorted. 
    /// Since the answer can be too large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: s = "cba"
    /// Output: 5
    /// Explanation: The simulation goes as follows:
    /// Operation 1: i=2, j=2. Swap s[1] and s[2] to get s="cab", then reverse 
    /// the suffix starting at 2. Now, s="cab".
    /// Operation 2: i=1, j=2. Swap s[0] and s[2] to get s="bac", then reverse 
    /// the suffix starting at 1. Now, s="bca".
    /// Operation 3: i=2, j=2. Swap s[1] and s[2] to get s="bac", then reverse 
    /// the suffix starting at 2. Now, s="bac".
    /// Operation 4: i=1, j=1. Swap s[0] and s[1] to get s="abc", then reverse 
    /// the suffix starting at 1. Now, s="acb".
    /// Operation 5: i=2, j=2. Swap s[1] and s[2] to get s="abc", then reverse 
    /// the suffix starting at 2. Now, s="abc".
    ///
    /// Example 2:
    /// Input: s = "aabaa"
    /// Output: 2
    /// Explanation: The simulation goes as follows:
    /// Operation 1: i=3, j=4. Swap s[2] and s[4] to get s="aaaab", then reverse 
    /// the substring starting at 3. Now, s="aaaba".
    /// Operation 2: i=4, j=4. Swap s[3] and s[4] to get s="aaaab", then reverse 
    /// the substring starting at 4. Now, s="aaaab".
    ///
    /// Example 3:
    /// Input: s = "cdbea"
    /// Output: 63
    ///
    /// Example 4:
    /// Input: s = "leetcodeleetcodeleetcode"
    /// Output: 982157772
    /// 
    /// Constraints:
    /// 1. 1 <= s.length <= 3000
    /// 2. s consists only of lowercase English letters.
    /// </summary>
    int makeStringSorted(string s);

    /// <summary>
    /// Leet code 1837. Sum of Digits in Base K
    /// 
    /// Easy
    /// 
    /// Given an integer n (in base 10) and a base k, return the sum of the 
    /// digits of n after converting n from base 10 to base k.
    ///
    /// After converting, each digit should be interpreted as a base 10 
    /// number, and the sum should be returned in base 10.
    ///
    /// Example 1:
    /// Input: n = 34, k = 6
    /// Output: 9
    /// Explanation: 34 (base 10) expressed in base 6 is 54. 5 + 4 = 9.
    ///
    /// Example 2:
    /// Input: n = 10, k = 10
    /// Output: 1
    /// Explanation: n is already in base 10. 1 + 0 = 1.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// 2. 2 <= k <= 10
    /// </summary>
    int sumBase(int n, int k);

    /// <summary>
    /// Leet code 1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number
    /// 
    /// Medium
    /// 
    /// You are given a string num, representing a large integer, and an 
    /// integer k.
    ///
    /// We call some integer wonderful if it is a permutation of the digits 
    /// in num and is greater in value than num. There can be many wonderful 
    /// integers. However, we only care about the smallest-valued ones.
    ///
    /// For example, when num = "5489355142":
    /// The 1st smallest wonderful integer is "5489355214".
    /// The 2nd smallest wonderful integer is "5489355241".
    /// The 3rd smallest wonderful integer is "5489355412".
    /// The 4th smallest wonderful integer is "5489355421".
    /// Return the minimum number of adjacent digit swaps that needs to be 
    /// applied to num to reach the kth smallest wonderful integer.
    ///
    /// The tests are generated in such a way that kth smallest wonderful 
    /// integer exists.
    /// 
    /// Example 1:
    /// Input: num = "5489355142", k = 4
    /// Output: 2
    /// Explanation: The 4th smallest wonderful number is "5489355421". To 
    /// get this number:
    /// - Swap index 7 with index 8: "5489355142" -> "5489355412"
    /// - Swap index 8 with index 9: "5489355412" -> "5489355421"
    ///
    /// Example 2:
    /// Input: num = "11112", k = 4
    /// Output: 4
    /// Explanation: The 4th smallest wonderful number is "21111". To get 
    /// this number:
    /// - Swap index 3 with index 4: "11112" -> "11121"
    /// - Swap index 2 with index 3: "11121" -> "11211"
    /// - Swap index 1 with index 2: "11211" -> "12111"
    /// - Swap index 0 with index 1: "12111" -> "21111"
    ///
    /// Example 3:
    /// Input: num = "00123", k = 1
    /// Output: 1
    /// Explanation: The 1st smallest wonderful number is "00132". To get 
    /// this number:
    /// - Swap index 3 with index 4: "00123" -> "00132"
    ///
    /// Constraints:
    /// 1. 2 <= num.length <= 1000
    /// 2. 1 <= k <= 1000
    /// 3. num only consists of digits.
    /// </summary>
    int getMinSwaps(string num, int k);


    /// <summary>
    /// Leet code 1862. Sum of Floored Pairs
    /// 
    /// Hard
    /// 
    /// Given an integer array nums, return the sum of floor(nums[i] / nums[j])
    /// for all pairs of indices 0 <= i, j < nums.length in the array. Since 
    /// the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// The floor() function returns the integer part of the division.
    /// 
    /// Example 1:
    /// Input: nums = [2,5,9]
    /// Output: 10
    /// Explanation:
    /// floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
    /// floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
    /// floor(5 / 2) = 2
    /// floor(9 / 2) = 4
    /// floor(9 / 5) = 1
    /// We calculate the floor of the division for every pair of indices in the array then sum them up.
    ///
    /// Example 2:
    /// Input: nums = [7,7,7,7,7,7,7]
    /// Output: 49
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int sumOfFlooredPairs(vector<int>& nums);

    /// <summary>
    /// Leet code 1860. Incremental Memory Leak
    /// 
    /// Medium
    /// 
    /// You are given two integers memory1 and memory2 representing the 
    /// available memory in bits on two memory sticks. There is currently 
    /// a faulty program running that consumes an increasing amount of memory 
    /// every second.
    ///
    /// At the ith second (starting from 1), i bits of memory are allocated 
    /// to the stick with more available memory (or from the first memory 
    /// stick if both have the same available memory). If neither stick has 
    /// at least i bits of available memory, the program crashes.
    ///
    /// Return an array containing [crashTime, memory1crash, memory2crash], 
    /// where crashTime is the time (in seconds) when the program crashed and 
    /// memory1crash and memory2crash are the available bits of memory in the 
    /// first and second sticks respectively.
    /// 
    /// Example 1:
    /// Input: memory1 = 2, memory2 = 2
    /// Output: [3,1,0]
    /// Explanation: The memory is allocated as follows:
    /// - At the 1st second, 1 bit of memory is allocated to stick 1. The 
    ///   first stick now has 1 bit of available memory.
    /// - At the 2nd second, 2 bits of memory are allocated to stick 2. 
    ///   The second stick now has 0 bits of available memory.
    /// - At the 3rd second, the program crashes. The sticks have 1 and 0 
    ///   bits available respectively.
    ///
    /// Example 2:
    /// Input: memory1 = 8, memory2 = 11
    /// Output: [6,0,4]
    /// Explanation: The memory is allocated as follows:
    /// - At the 1st second, 1 bit of memory is allocated to stick 2. The 
    ///   second stick now has 10 bit of available memory.
    /// - At the 2nd second, 2 bits of memory are allocated to stick 2. The 
    ///   second stick now has 8 bits of available memory.
    /// - At the 3rd second, 3 bits of memory are allocated to stick 1. The 
    ///   first stick now has 5 bits of available memory.
    /// - At the 4th second, 4 bits of memory are allocated to stick 2. The 
    ///   second stick now has 4 bits of available memory.
    /// - At the 5th second, 5 bits of memory are allocated to stick 1. The 
    ///   first stick now has 0 bits of available memory.
    /// - At the 6th second, the program crashes. The sticks have 0 and 4 bits 
    ///   available respectively.
    /// 
    /// Constraints:
    /// 1. 0 <= memory1, memory2 <= 2^31 - 1
    /// 2. You are given an array of strings words (0-indexed).
    /// </summary>
    vector<int> memLeak(int memory1, int memory2);

    /// <summary>
    /// Leet code 1916. Count Ways to Build Rooms in an Ant Colony
    /// </summary>
    int waysToBuildRooms(vector<vector<int>>& tree, int root, long long& product);

    /// <summary>
    /// Leet code 1916. Count Ways to Build Rooms in an Ant Colony
    /// 
    /// Hard
    /// 
    /// You are an ant tasked with adding n new rooms numbered 0 to n-1 to 
    /// your colony. You are given the expansion plan as a 0-indexed integer 
    /// array of length n, prevRoom, where prevRoom[i] indicates that you 
    /// must build room prevRoom[i] before building room i, and these two 
    /// rooms must be connected directly. Room 0 is already built, so 
    /// prevRoom[0] = -1. The expansion plan is given such that once all 
    /// the rooms are built, every room will be reachable from room 0.
    ///
    /// You can only build one room at a time, and you can travel freely 
    /// between rooms you have already built only if they are connected. 
    /// You can choose to build any room as long as its previous room is 
    /// already built.
    ///
    /// Return the number of different orders you can build all the rooms in. 
    /// Since the answer may be large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: prevRoom = [-1,0,1]
    /// Output: 1
    /// Explanation: There is only one way to build the additional 
    /// rooms: 0 -> 1 -> 2
    ///
    /// Example 2:
    ///Input: prevRoom = [-1,0,0,1,2]
    /// Output: 6
    /// Explanation:
    /// The 6 ways are:
    /// 0 -> 1 -> 3 -> 2 -> 4
    /// 0 -> 2 -> 4 -> 1 -> 3
    /// 0 -> 1 -> 2 -> 3 -> 4
    /// 0 -> 1 -> 2 -> 4 -> 3
    /// 0 -> 2 -> 1 -> 3 -> 4
    /// 0 -> 2 -> 1 -> 4 -> 3
    ///
    /// Constraints:
    /// 1. n == prevRoom.length
    /// 2. 2 <= n <= 10^5
    /// 3. prevRoom[0] == -1
    /// 3. 0 <= prevRoom[i] < n for all 1 <= i < n
    /// 4. Every room is reachable from room 0 once all the rooms are built.
    /// </summary>
    int waysToBuildRooms(vector<int>& prevRoom);

    /// <summary>
    /// Leet code 1906. Minimum Absolute Difference Queries
    /// 
    /// Hard
    /// 
    /// The minimum absolute difference of an array a is defined as the 
    /// minimum value of |a[i] - a[j]|, where 0 <= i < j < a.length and 
    /// a[i] != a[j]. If all elements of a are the same, the minimum 
    /// absolute difference is -1.
    ///
    /// For example, the minimum absolute difference of the array 
    /// [5,2,3,7,2] is |2 - 3| = 1. Note that it is not 0 because 
    /// a[i] and a[j] must be different.
    /// You are given an integer array nums and the array queries where 
    /// queries[i] = [li, ri]. For each query i, compute the minimum 
    /// absolute difference of the subarray nums[li...ri] containing the 
    /// elements of nums between the 0-based indices li and ri (inclusive).
    ///
    /// Return an array ans where ans[i] is the answer to the ith query.
    /// 
    /// A subarray is a contiguous sequence of elements in an array.
    ///
    /// The value of |x| is defined as:
    /// 1. x if x >= 0.
    /// 2. -x if x < 0.
    ///
    /// Example 1:
    /// Input: nums = [1,3,4,8], queries = [[0,1],[1,2],[2,3],[0,3]]
    /// Output: [2,1,4,1]
    /// Explanation: The queries are processed as follows:
    /// - queries[0] = [0,1]: The subarray is [1,3] and the minimum absolute 
    ///   difference is |1-3| = 2.
    /// - queries[1] = [1,2]: The subarray is [3,4] and the minimum absolute 
    ///   difference is |3-4| = 1.
    /// - queries[2] = [2,3]: The subarray is [4,8] and the minimum absolute 
    ///   difference is |4-8| = 4.
    /// - queries[3] = [0,3]: The subarray is [1,3,4,8] and the minimum 
    ///   absolute difference is |3-4| = 1.
    ///
    /// Example 2:
    /// Input: nums = [4,5,2,2,7,10], queries = [[2,3],[0,2],[0,5],[3,5]]
    /// Output: [-1,1,1,3]
    /// Explanation: The queries are processed as follows:
    /// - queries[0] = [2,3]: The subarray is [2,2] and the minimum absolute 
    ///   difference is -1 because all the elements are the same.
    /// - queries[1] = [0,2]: The subarray is [4,5,2] and the minimum absolute 
    ///   difference is |4-5| = 1.
    /// - queries[2] = [0,5]: The subarray is [4,5,2,2,7,10] and the minimum 
    ///   absolute difference is |4-5| = 1.
    /// - queries[3] = [3,5]: The subarray is [2,7,10] and the minimum absolute
    ///    difference is |7-10| = 3.
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 100
    /// 3. 1 <= queries.length <= 2 * 10^4
    /// 4. 0 <= li < ri < nums.length
    /// </summary>
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries);

    /// <summary>
    /// Leet code 1884. Egg Drop With 2 Eggs and N Floors
    ///                  
    /// Medium
    /// 
    /// You are given two identical eggs and you have access to a building 
    /// with n floors labeled from 1 to n.
    ///
    /// You know that there exists a floor f where 0 <= f <= n such that any 
    /// egg dropped at a floor higher than f will break, and any egg dropped 
    /// at or below floor f will not break.
    ///
    /// In each move, you may take an unbroken egg and drop it from any 
    /// floor x (where 1 <= x <= n). If the egg breaks, you can no longer use 
    /// it. However, if the egg does not break, you may reuse it in future 
    /// moves.
    ///
    /// Return the minimum number of moves that you need to determine with 
    /// certainty what the value of f is.
    /// 
    /// Example 1:
    /// Input: n = 2
    /// Output: 2
    /// Explanation: We can drop the first egg from floor 1 and the second 
    /// egg from floor 2.
    /// If the first egg breaks, we know that f = 0.
    /// If the second egg breaks but the first egg didn't, we know that f = 1.
    /// Otherwise, if both eggs survive, we know that f = 2.
    ///
    /// Example 2:
    /// Input: n = 100
    /// Output: 14
    /// Explanation: One optimal strategy is:
    /// - Drop the 1st egg at floor 9. If it breaks, we know f is between 0 
    /// and 8. Drop the 2nd egg starting from floor 1 and going up one at a 
    /// time to find f within 7 more drops. Total drops is 1 + 7 = 8.
    /// - If the 1st egg does not break, drop the 1st egg again at floor 22. 
    /// If it breaks, we know f is between 9 and 21. Drop the 2nd egg starting 
    /// from floor 10 and going up one at a time to find f within 12 more
    /// drops. Total drops is 2 + 12 = 14.
    /// - If the 1st egg does not break again, follow a similar process 
    /// dropping the 1st egg from floors 34, 45,
    /// 55, 64, 72, 79, 85, 90, 94, 97, 99, and 100.
    /// Regardless of the outcome, it takes at most 14 drops to determine f.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// </summary>
    int twoEggDrop(int n);

    /// <summary>
    /// Leet code 1899. Merge Triplets to Form Target Triplet
    ///                                  
    /// Medium
    /// 
    /// 
    /// A triplet is an array of three integers. You are given a 2D integer 
    /// array triplets, where triplets[i] = [ai, bi, ci] describes the ith 
    /// triplet. You are also given an integer array target = [x, y, z] that 
    /// describes the triplet you want to obtain.
    ///
    /// To obtain target, you may apply the following operation on triplets 
    /// any number of times (possibly zero):
    ///
    /// Choose two indices (0-indexed) i and j (i != j) and update triplets[j] 
    /// to become [max(ai, aj), max(bi, bj), max(ci, cj)].
    /// For example, if triplets[i] = [2, 5, 3] and triplets[j] = [1, 7, 5], 
    /// triplets[j] will be updated to [max(2, 1), max(5, 7), 
    /// max(3, 5)] = [2, 7, 5].
    /// Return true if it is possible to obtain the target triplet [x, y, z] 
    /// as an element of triplets, or false otherwise.
    /// 
    /// Example 1:
    /// Input: triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
    /// Output: true
    /// Explanation: Perform the following operations:
    /// - Choose the first and last triplets [[2,5,3],[1,8,4],[1,7,5]]. Update 
    ///  the last triplet to be [max(2,1), max(5,7), max(3,5)] = [2,7,5]. 
    ///  triplets = [[2,5,3],[1,8,4],[2,7,5]]
    /// The target triplet [2,7,5] is now an element of triplets.
    ///
    /// Example 2:
    /// Input: triplets = [[1,3,4],[2,5,8]], target = [2,5,8]
    /// Output: true
    /// Explanation: The target triplet [2,5,8] is already an element of 
    /// triplets.
    ///
    /// Example 3:
    /// Input: triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]
    /// Output: true
    /// Explanation: Perform the following operations:
    /// - Choose the first and third triplets [[2,5,3],[2,3,4],[1,2,5],
    /// [5,2,3]]. Update the third triplet to be [max(2,1), max(5,2), max(3,5)]
    /// = [2,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,2,3]].
    /// - Choose the third and fourth triplets [[2,5,3],[2,3,4],[2,5,5],
    /// [5,2,3]]. Update the fourth triplet to be [max(2,5), max(5,2), 
    ///  max(5,3)] = [5,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,5,5]].
    /// The target triplet [5,5,5] is now an element of triplets.
    ///
    /// Example 4:
    /// Input: triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
    /// Output: false
    /// Explanation: It is impossible to have [3,2,5] as an element because 
    /// there is no 2 in any of the triplets.
    /// 
    /// Constraints:
    /// 1. 1 <= triplets.length <= 10^5
    /// 2. triplets[i].length == target.length == 3
    /// 3. 1 <= ai, bi, ci, x, y, z <= 1000
    /// </summary>
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target);

    /// <summary>
    /// Leet code 1952. Three Divisors
    ///                                                
    /// Easy
    /// 
    /// Given an integer n, return true if n has exactly three positive 
    /// divisors. Otherwise, return false.
    ///
    /// An integer m is a divisor of n if there exists an integer k such 
    /// that n = k * m.
    /// 
    /// Example 1:
    /// Input: n = 2
    /// Output: false
    /// Explantion: 2 has only two divisors: 1 and 2.
    ///
    /// Example 2:
    /// Input: n = 4
    /// Output: true
    /// Explantion: 4 has three divisors: 1, 2, and 4.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// </summary>
    bool isThree(int n);

    /// <summary>
    /// Leet code 1925. Count Square Sum Triples
    ///                                                
    /// Easy
    /// 
    /// A square triple (a,b,c) is a triple where a, b, and c are integers 
    /// and a2 + b2 = c2.
    ///
    /// Given an integer n, return the number of square triples such 
    /// that 1 <= a, b, c <= n.
    ///
    /// 
    /// Example 1:
    /// Input: n = 5
    /// Output: 2
    /// Explanation: The square triples are (3,4,5) and (4,3,5).
    ///
    /// Example 2:
    /// Input: n = 10
    /// Output: 4
    /// Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), 
    /// and (8,6,10).
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 250
    /// </summary>
    int countTriples(int n);

    /// <summary>
    /// Leet code 1904. The Number of Full Rounds You Have Played
    ///                                                
    /// Medium
    /// 
    /// A new online video game has been released, and in this video game, 
    /// there are 15-minute rounds scheduled every quarter-hour period. 
    /// This means that at HH:00, HH:15, HH:30 and HH:45, a new round 
    /// starts, where HH represents an integer number from 00 to 23. A 
    /// 24-hour clock is used, so the earliest time in the day is 00:00 
    /// and the latest is 23:59.
    /// Given two strings startTime and finishTime in the format "HH:MM" 
    /// representing the exact time you started and finished playing the 
    /// game, respectively, calculate the number of full rounds that you 
    /// played during your game session.
    ///  
    /// For example, if startTime = "05:20" and finishTime = "05:59" this 
    /// means you played only one full round from 05:30 to 05:45. You did 
    /// not play the full round from 05:15 to 05:30 because you started 
    /// after the round began, and you did not play the full round from 
    /// 05:45 to 06:00 because you stopped before the round ended.
    /// If finishTime is earlier than startTime, this means you have 
    /// played overnight (from startTime to the midnight and from midnight 
    /// to finishTime).
    ///
    /// Return the number of full rounds that you have played if you had 
    /// started playing at startTime and finished at finishTime.
    ///
    /// Example 1:
    /// Input: startTime = "12:01", finishTime = "12:44"
    /// Output: 1
    /// Explanation: You played one full round from 12:15 to 12:30.
    /// You did not play the full round from 12:00 to 12:15 because you 
    /// started playing at 12:01 after it began.
    /// You did not play the full round from 12:30 to 12:45 because you 
    /// stopped playing at 12:44 before it ended.
    ///
    /// Example 2:
    /// Input: startTime = "20:00", finishTime = "06:00"
    /// Output: 40
    /// Explanation: You played 16 full rounds from 20:00 to 00:00 and 24 full 
    /// rounds from 00:00 to 06:00.
    /// 16 + 24 = 40.
    ///
    /// Example 3:
    /// Input: startTime = "00:00", finishTime = "23:59"
    /// Output: 95
    /// Explanation: You played 4 full rounds each hour except for the last 
    /// hour where you played 3 full rounds.
    /// 
    /// Constraints:
    /// 1. startTime and finishTime are in the format HH:MM.
    /// 2. 00 <= HH <= 23
    /// 3. 00 <= MM <= 59
    /// startTime and finishTime are not equal.
    /// </summary>
    int numberOfRounds(string startTime, string finishTime);

    /// <summary>
    /// Leet code 1979. Find Greatest Common Divisor of Array
    ///                                                
    /// Easy
    /// 
    /// Given an integer array nums, return the greatest common divisor of 
    /// the smallest number and largest number in nums.
    ///
    /// The greatest common divisor of two numbers is the largest positive 
    /// integer that evenly divides both numbers.
    ///
    /// Example 1:
    /// Input: nums = [2,5,6,9,10]
    /// Output: 2
    /// Explanation:
    /// The smallest number in nums is 2.
    /// The largest number in nums is 10.
    /// The greatest common divisor of 2 and 10 is 2.
    ///
    /// Example 2:
    /// Input: nums = [7,5,6,8,3]
    /// Output: 1
    /// Explanation:
    /// The smallest number in nums is 3.
    /// The largest number in nums is 8.
    /// The greatest common divisor of 3 and 8 is 1.
    ///
    /// Example 3:
    /// Input: nums = [3,3]
    /// Output: 3
    /// Explanation:
    /// The smallest number in nums is 3.
    /// The largest number in nums is 3.
    /// The greatest common divisor of 3 and 3 is 3.
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 1000
    /// </summary>
    int findGCD(vector<int>& nums);

    /// <summary>
    /// Leet code 2035. Partition Array Into Two Arrays to Minimize Sum 
    ///                 Difference
    ///                                                
    /// Hard
    /// 
    /// You are given an integer array nums of 2 * n integers. You need to 
    /// partition nums into two arrays of length n to minimize the absolute 
    /// difference of the sums of the arrays. To partition nums, put each 
    /// element of nums into one of the two arrays.
    ///
    /// Return the minimum possible absolute difference.
    /// 
    /// Example 1:
    /// Input: nums = [3,9,7,3]
    /// Output: 2
    /// Explanation: One optimal partition is: [3,9] and [7,3].
    /// The absolute difference between the sums of the arrays is 
    /// abs((3 + 9) - (7 + 3)) = 2.
    ///
    /// Example 2:
    /// Input: nums = [-36,36]
    /// Output: 72
    /// Explanation: One optimal partition is: [-36] and [36].
    /// The absolute difference between the sums of the arrays is 
    /// abs((-36) - (36)) = 72.
    ///
    /// Example 3:
    /// Input: nums = [2,-1,0,4,-2,-9]
    /// Output: 0
    /// Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
    /// The absolute difference between the sums of the arrays is 
    /// abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
    /// 
    /// Constraints:
    /// 1 <= n <= 15
    /// nums.length == 2 * n
    /// -10^7 <= nums[i] <= 10^7
    /// </summary>
    int minimumDifference(vector<int>& nums); 

    /// <summary>
    /// Leet code 1922. Count Good Numbers
    ///                                                
    /// Medium
    /// 
    /// A digit string is good if the digits (0-indexed) at even indices 
    /// are even and the digits at odd indices are prime (2, 3, 5, or 7).
    ///
    /// For example, "2582" is good because the digits (2 and 8) at even 
    /// positions are even and the digits (5 and 2) at odd positions are prime.
    /// However, "3245" is not good because 3 is at an even index but is not 
    /// even.
    /// Given an integer n, return the total number of good digit strings of 
    /// length n. Since the answer may be large, return it modulo 10^9 + 7.
    ///
    /// A digit string is a string consisting of digits 0 through 9 that 
    /// may contain leading zeros.
    ///
    /// Example 1:
    /// Input: n = 1
    /// Output: 5
    /// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
    /// Example 2:
    /// Input: n = 4
    /// Output: 400
    ///
    /// Example 3:
    /// Input: n = 50
    /// Output: 564908303
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^15
    /// </summary>
    int countGoodNumbers(long long n);

    /// <summary>
    /// Leet code 1927. Sum Game
    ///                                                                 
    /// Medium
    /// 
    /// Alice and Bob take turns playing a game, with Alice starting first.
    ///
    /// You are given a string num of even length consisting of digits and '?' 
    /// characters. On each turn, a player will do the following if there is 
    /// still at least one '?' in num:
    /// Choose an index i where num[i] == '?'.
    /// Replace num[i] with any digit between '0' and '9'.
    /// The game ends when there are no more '?' characters in num.
    /// For Bob to win, the sum of the digits in the first half of num must 
    /// be equal to the sum of the digits in the second half. For Alice to 
    /// win, the sums must not be equal.
    ///
    /// For example, if the game ended with num = "243801", then Bob wins 
    /// because 2+4+3 = 8+0+1. If the game ended with num = "243803", then 
    /// Alice wins because 2+4+3 != 8+0+3.
    /// Assuming Alice and Bob play optimally, return true if Alice will win 
    /// and false if Bob will win.
    /// 
    /// Example 1:
    /// Input: num = "5023"
    /// Output: false
    /// Explanation: There are no moves to be made.
    /// The sum of the first half is equal to the sum of the second 
    /// half: 5 + 0 = 2 + 3.
    ///
    /// Example 2:
    /// Input: num = "25??"
    /// Output: true
    /// Explanation: Alice can replace one of the '?'s with '9' and it will 
    /// be impossible for Bob to make the sums equal.
    ///
    /// Example 3:
    /// Input: num = "?3295???"
    /// Output: false
    /// Explanation: It can be proven that Bob will always win. One 
    /// possible outcome is:
    /// - Alice replaces the first '?' with '9'. num = "93295???".
    /// - Bob replaces one of the '?' in the right half with '9'. 
    ///   num = "932959??".
    /// - Alice replaces one of the '?' in the right half with '2'. 
    ///   num = "9329592?".
    /// - Bob replaces the last '?' in the right half with '7'. 
    ///   num = "93295927".
    /// Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.
    /// 
    /// Constraints:
    /// 1. 2 <= num.length <= 10^5
    /// 2. num.length is even.
    /// 3. num consists of only digits and '?'.
    /// </summary>
    bool sumGame(string num);

    /// <summary>
    /// Leet code 1982. Find Array Given Subset Sums
    ///                                                                 
    /// Hard
    /// 
    /// You are given an integer n representing the length of an unknown array 
    /// that you are trying to recover. You are also given an array sums 
    /// containing the values of all 2n subset sums of the unknown array (in 
    /// no particular order).
    ///
    /// Return the array ans of length n representing the unknown array. If 
    /// multiple answers exist, return any of them.
    ///
    /// An array sub is a subset of an array arr if sub can be obtained from 
    /// arr by deleting some (possibly zero or all) elements of arr. The sum 
    /// of the elements in sub is one possible subset sum of arr. The sum of 
    /// an empty array is considered to be 0.
    ///
    /// Note: Test cases are generated such that there will always be at least
    /// one correct answer.
    /// 
    /// Example 1:
    /// Input: n = 3, sums = [-3,-2,-1,0,0,1,2,3]
    /// Output: [1,2,-3]
    /// Explanation: [1,2,-3] is able to achieve the given subset sums:
    /// - []: sum is 0
    /// - [1]: sum is 1
    /// - [2]: sum is 2
    /// - [1,2]: sum is 3
    /// - [-3]: sum is -3
    /// - [1,-3]: sum is -2
    /// - [2,-3]: sum is -1
    /// - [1,2,-3]: sum is 0
    /// Note that any permutation of [1,2,-3] and also any permutation of 
    /// [-1,-2,3] will also be accepted.
    ///
    /// Example 2:
    /// Input: n = 2, sums = [0,0,0,0]
    /// Output: [0,0]
    /// Explanation: The only correct answer is [0,0].
    ///
    /// Example 3:
    /// Input: n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
    /// Output: [0,-1,4,5]
    /// Explanation: [0,-1,4,5] is able to achieve the given subset sums.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 15
    /// 2. sums.length == 2n
    /// 3. -10^4 <= sums[i] <= 10^4
    /// </summary>
    vector<int> recoverArray(int n, vector<int>& sums);

    /// <summary>
    /// Leet Code 1954. Minimum Garden Perimeter to Collect 
    ///                 Enough Apples
    ///                                                                 
    /// Medium
    /// 
    /// In a garden represented as an infinite 2D grid, there is an apple tree 
    /// planted at every integer coordinate. The apple tree planted at an 
    /// integer coordinate (i, j) has |i| + |j| apples growing on it.
    ///
    /// You will buy an axis-aligned square plot of land that is centered 
    /// at (0, 0).
    ///
    /// Given an integer neededApples, return the minimum perimeter of a plot 
    /// such that at least neededApples apples are inside or on the perimeter 
    /// of that plot.
    ///
    /// The value of |x| is defined as:
    ///
    /// x if x >= 0
    /// -x if x < 0
    /// 
    /// Example 1:
    /// Input: neededApples = 1
    /// Output: 8
    /// Explanation: A square plot of side length 1 does not contain any 
    /// apples.
    /// However, a square plot of side length 2 has 12 apples inside (as 
    /// depicted in the image above).
    /// The perimeter is 2 * 4 = 8.
    ///
    /// Example 2:
    /// Input: neededApples = 13
    /// Output: 16
    ///
    /// Example 3:
    /// Input: neededApples = 1000000000
    /// Output: 5040
    ///
    /// Constraints:
    /// 1. 1 <= neededApples <= 10^15
    /// </summary>
    long long minimumPerimeter(long long neededApples); 

    /// <summary>
    /// Leet Code 1975. Maximum Matrix Sum
    ///                                                                 
    /// Medium
    /// 
    /// You are given an n x n integer matrix. You can do the following 
    /// operation any number of times:
    ///
    /// Choose any two adjacent elements of matrix and multiply each of them 
    /// by -1.
    /// Two elements are considered adjacent if and only if they share a 
    /// border.
    ///
    /// Your goal is to maximize the summation of the matrix's elements. 
    /// Return the maximum sum of the matrix's elements using the operation 
    /// mentioned above.
    ///
    /// Example 1:
    /// Input: matrix = [[1,-1],[-1,1]]
    /// Output: 4
    /// Explanation: We can follow the following steps to reach sum equals 4:
    /// - Multiply the 2 elements in the first row by -1.
    /// - Multiply the 2 elements in the first column by -1.
    ///
    /// Example 2:
    /// Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
    /// Output: 16
    /// Explanation: We can follow the following step to reach sum equals 16:
    /// - Multiply the 2 last elements in the second row by -1.
    /// 
    /// Constraints:
    /// 1. n == matrix.length == matrix[i].length
    /// 2. 2 <= n <= 250
    /// -10^5 <= matrix[i][j] <= 10^5
    /// </summary>
    long long maxMatrixSum(vector<vector<int>>& matrix);

    /// <summary>
    /// Leet Code 2029. Stone Game IX
    ///                                                                 
    /// Medium
    /// 
    /// Alice and Bob continue their games with stones. There is a row of n 
    /// stones, and each stone has an associated value. You are given an 
    /// integer array stones, where stones[i] is the value of the ith stone.
    ///
    /// Alice and Bob take turns, with Alice starting first. On each turn, 
    /// the player may remove any stone from stones. The player who removes 
    /// a stone loses if the sum of the values of all removed stones is 
    /// divisible by 3. Bob will win automatically if there are no remaining 
    /// stones (even if it is Alice's turn).
    ///
    /// Assuming both players play optimally, return true if Alice wins and 
    /// false if Bob wins.
    /// 
    /// Example 1:
    /// Input: stones = [2,1]
    /// Output: true
    /// Explanation: The game will be played as follows:
    /// - Turn 1: Alice can remove either stone.
    /// - Turn 2: Bob removes the remaining stone. 
    /// The sum of the removed stones is 1 + 2 = 3 and is divisible by 3. 
    /// Therefore, Bob loses and Alice wins the game.
    ///
    /// Example 2:
    /// Input: stones = [2]
    /// Output: false
    /// Explanation: Alice will remove the only stone, and the sum of the 
    /// values on the removed stones is 2. 
    /// Since all the stones are removed and the sum of values is not 
    /// divisible by 3, Bob wins the game.
    ///
    /// Example 3:
    /// Input: stones = [5,1,2,4,3]
    /// Output: false
    /// Explanation: Bob will always win. One possible way for Bob to 
    /// win is shown below:
    /// - Turn 1: Alice can remove the second stone with value 1. Sum of 
    ///   removed stones = 1.
    /// - Turn 2: Bob removes the fifth stone with value 3. Sum of removed 
    ///   stones = 1 + 3 = 4.
    /// - Turn 3: Alices removes the fourth stone with value 4. Sum of removed 
    ///   stones = 1 + 3 + 4 = 8.
    /// - Turn 4: Bob removes the third stone with value 2. Sum of removed 
    ///   stones = 1 + 3 + 4 + 2 = 10.
    /// - Turn 5: Alice removes the first stone with value 5. Sum of removed 
    ///  stones = 1 + 3 + 4 + 2 + 5 = 15.
    /// Alice loses the game because the sum of the removed stones (15) is 
    /// divisible by 3. Bob wins the game.
    ///
    /// Constraints:
    /// 1. 1 <= stones.length <= 10^5
    /// 2. 1 <= stones[i] <= 10^4
    /// </summary>
    bool stoneGameIX(vector<int>& stones);

    /// <summary>
    /// Leet Code 2005. Subtree Removal Game with Fibonacci Tree
    ///
    /// Hard                                                    
    ///                                                                 
    /// A Fibonacci tree is a binary tree created using the order function 
    /// order(n):
    ///
    /// order(0) is the empty tree.
    /// order(1) is a binary tree with only one node.
    /// order(n) is a binary tree that consists of a root node with the left 
    /// subtree as order(n - 2) and the right subtree as order(n - 1).
    /// Alice and Bob are playing a game with a Fibonacci tree with Alice 
    /// staring first. On each turn, a player selects a node and removes that 
    /// node and its subtree. The player that is forced to delete root loses.
    ///
    /// Given the integer n, return true if Alice wins the game or false if 
    /// Bob wins, assuming both players play optimally.
    ///
    /// A subtree of a binary tree tree is a tree that consists of a node in 
    /// tree and all of this node's descendants. The tree tree could also be 
    /// considered as a subtree of itself.
    /// 
    /// Example 1: 
    /// Input: n = 3
    /// Output: true
    /// Explanation:
    /// Alice takes the node 1 in the right subtree.
    /// Bob takes either the 1 in the left subtree or the 2 in the right 
    /// subtree.
    /// Alice takes whichever node Bob doesn't take.
    /// Bob is forced to take the root node 3, so Bob will lose.
    /// Return true because Alice wins.
    ///
    /// Example 2:
    /// Input: n = 1
    /// Output: false
    /// Explanation:
    /// Alice is forced to take the root node 1, so Alice will lose.
    /// Return false because Alice loses.
    ///
    /// Example 3:
    /// Input: n = 2
    /// Output: true
    /// Explanation:
    /// Alice takes the node 1.
    /// Bob is forced to take the root node 2, so Bob will lose.
    /// Return true because Alice wins.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// </summary>
    bool findGameWinner(int n);

    /// <summary>
    /// Leet Code 1908. Game of Nim
    ///
    /// Medium                                                    
    /// 
    /// Alice and Bob take turns playing a game with Alice starting first.
    ///
    /// In this game, there are n piles of stones. On each player's turn, the 
    /// player should remove any positive number of stones from a non-empty 
    /// pile of his or her choice. The first player who cannot make a move 
    /// loses, and the other player wins.
    ///
    /// Given an integer array piles, where piles[i] is the number of stones 
    /// in the ith pile, return true if Alice wins, or false if Bob wins.
    ///
    /// Both Alice and Bob play optimally.
    /// 
    /// Example 1:
    /// Input: piles = [1]
    /// Output: true
    /// Explanation: There is only one possible scenario:
    /// - On the first turn, Alice removes one stone from the first pile. 
    ///   piles = [0].
    /// - On the second turn, there are no stones left for Bob to remove. 
    ///   Alice wins.
    ///
    /// Example 2:
    /// Input: piles = [1,1]
    /// Output: false
    /// Explanation: It can be proven that Bob will always win. One 
    /// possible scenario is:
    /// - On the first turn, Alice removes one stone from the first pile. 
    ///   piles = [0,1].
    /// - On the second turn, Bob removes one stone from the second pile. 
    ///   piles = [0,0].
    /// - On the third turn, there are no stones left for Alice to remove. 
    ///   Bob wins.
    ///
    /// Example 3:
    /// Input: piles = [1,2,3]
    /// Output: false
    /// Explanation: It can be proven that Bob will always win. One possible 
    /// scenario is:
    /// - On the first turn, Alice removes three stones from the third pile. 
    ///   piles = [1,2,0].
    /// - On the second turn, Bob removes one stone from the second pile. 
    ///   piles = [1,1,0].
    /// - On the third turn, Alice removes one stone from the first pile. 
    ///   piles = [0,1,0].
    /// - On the fourth turn, Bob removes one stone from the second pile. 
    ///   piles = [0,0,0].
    /// - On the fifth turn, there are no stones left for Alice to remove. 
    ///   Bob wins.
    ///
    /// Constraints:
    /// 1. n == piles.length
    /// 2. 1 <= n <= 7
    /// 3. 1 <= piles[i] <= 7
    /// 
    /// Follow-up: Could you find a linear time solution? Although the linear 
    /// time solution may be beyond the scope of an interview, it could be 
    /// interesting to know.
    /// </summary>
    bool nimGame(vector<int>& piles); 

    /// <summary>
    /// Leet Code 1924. Erect the Fence II
    /// </summary>
    vector<double> circleFrom(const pair<double, double>& A, const pair<double, double>& B, const pair<double, double>& C);

    /// <summary>
    /// Leet Code 1924. Erect the Fence II
    /// </summary>
    vector<double> centerAndRadius(const vector<pair<double, double>>& b);

    /// <summary>
    /// Leet Code 1924. Erect the Fence II
    /// </summary>
    vector<double> outerTrees(vector<vector<int>>& trees, int i, vector<pair<double, double>> b);

    /// <summary>
    /// Leet Code 1924. Erect the Fence II
    ///                                                                 
    /// Hard
    ///
    /// You are given a 2D integer array trees where trees[i] = [xi, yi] 
    /// represents the location of the ith tree in the garden.
    ///
    /// You are asked to fence the entire garden using the minimum length 
    /// of rope possible. The garden is well-fenced only if all the trees 
    /// are enclosed and the rope used forms a perfect circle. A tree is 
    /// considered enclosed if it is inside or on the border of the circle.
    ///
    /// More formally, you must form a circle using the rope with a 
    /// center (x, y) and radius r where all trees lie inside or on the 
    /// circle and r is minimum.
    ///
    /// Return the center and radius of the circle as a length 3 
    /// array [x, y, r]. Answers within 10-5 of the actual answer will be 
    /// accepted.
    ///
    /// Example 1:
    /// Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
    /// Output: [2.00000,2.00000,2.00000]
    /// Explanation: The fence will have center = (2, 2) and radius = 2
    ///
    /// Example 2:
    /// Input: trees = [[1,2],[2,2],[4,2]]
    /// Output: [2.50000,2.00000,1.50000]
    /// Explanation: The fence will have center = (2.5, 2) and radius = 1.5
    ///
    /// Constraints:
    /// 1. 1 <= trees.length <= 3000
    /// 2. trees[i].length == 2
    /// 3. 0 <= xi, yi <= 3000
    /// </summary>
    vector<double> outerTrees(vector<vector<int>>& trees);

    /// <summary>
    /// Leet Code 1842. Next Palindrome Using Same Digits
    ///                                                                 
    /// Hard
    /// 
    /// You are given a numeric string num, representing a very large 
    /// palindrome.
    ///
    /// Return the smallest palindrome larger than num that can be created 
    /// by rearranging its digits. If no such palindrome exists, return an 
    /// empty string "".
    ///
    /// A palindrome is a number that reads the same backward as forward.
    /// 
    /// Example 1:
    /// Input: num = "1221"
    /// Output: "2112"
    /// Explanation: The next palindrome larger than "1221" is "2112".
    ///
    /// Example 2:
    /// Input: num = "32123"
    /// Output: ""
    /// Explanation: No palindromes larger than "32123" can be made by 
    /// rearranging the digits.
    ///
    /// Example 3:
    /// Input: num = "45544554"
    /// Output: "54455445"
    /// Explanation: The next palindrome larger than "45544554" is "54455445".
    ///
    /// Constraints:
    /// 1. 1 <= num.length <= 10^5
    /// 2. num is a palindrome.
    /// </summary>
    string nextPalindrome(string num);

    /// <summary>
    /// Leet Code 1969. Minimum Non-Zero Product of the Array Elements
    ///                                                                 
    /// Medium
    /// 
    /// You are given a positive integer p. Consider an array nums (1-indexed) 
    /// that consists of the integers in the inclusive range [1, 2p - 1] in 
    /// their binary representations. You are allowed to do the following 
    /// operation any number of times:
    ///
    /// Choose two elements x and y from nums.
    /// Choose a bit in x and swap it with its corresponding bit in y. 
    /// Corresponding bit refers to the bit that is in the same position in 
    /// the other integer.
    /// For example, if x = 1101 and y = 0011, after swapping the 2nd bit from 
    /// the right, we have x = 1111 and y = 0001.
    ///
    /// Find the minimum non-zero product of nums after performing the above 
    /// operation any number of times. Return this product modulo 10^9 + 7.
    ///
    /// Note: The answer should be the minimum product before the modulo 
    /// operation is done.
    /// 
    /// Example 1:
    /// Input: p = 1
    /// Output: 1
    /// Explanation: nums = [1].
    /// There is only one element, so the product equals that element.
    ///
    /// Example 2:
    /// Input: p = 2
    /// Output: 6
    /// Explanation: nums = [01, 10, 11].
    /// Any swap would either make the product 0 or stay the same.
    /// Thus, the array product of 1 * 2 * 3 = 6 is already minimized.
    ///
    /// Example 3:
    /// Input: p = 3
    /// Output: 1512
    /// Explanation: nums = [001, 010, 011, 100, 101, 110, 111]
    /// - In the first operation we can swap the leftmost bit of the 
    ///   second and fifth elements.
    /// - The resulting array is [001, 110, 011, 100, 001, 110, 111].
    /// - In the second operation we can swap the middle bit of the 
    ///   third and fourth elements.
    /// - The resulting array is [001, 110, 001, 110, 001, 110, 111].
    /// The array product is 1 * 6 * 1 * 6 * 1 * 6 * 7 = 1512, which 
    /// is the minimum possible product.
    ///
    /// Constraints:
    /// 1. 1 <= p <= 60
    /// </summary>
    int minNonZeroProduct(int p);

    /// <summary>
    /// Leet Code 2001. Number of Pairs of Interchangeable Rectangles
    ///                                                                 
    /// Medium
    /// 
    /// You are given n rectangles represented by a 0-indexed 2D integer 
    /// array rectangles, where rectangles[i] = [widthi, heighti] denotes 
    /// the width and height of the ith rectangle.
    ///
    /// Two rectangles i and j (i < j) are considered interchangeable if 
    /// they have the same width-to-height ratio. More formally, two 
    /// rectangles are interchangeable if widthi/heighti == widthj/heightj 
    /// (using decimal division, not integer division).
    ///
    /// Return the number of pairs of interchangeable rectangles in rectangles.
    /// 
    /// Example 1:
    /// Input: rectangles = [[4,8],[3,6],[10,20],[15,30]]
    /// Output: 6
    /// Explanation: The following are the interchangeable pairs of rectangles 
    /// by index (0-indexed):
    /// - Rectangle 0 with rectangle 1: 4/8 == 3/6.
    /// - Rectangle 0 with rectangle 2: 4/8 == 10/20.
    /// - Rectangle 0 with rectangle 3: 4/8 == 15/30.
    /// - Rectangle 1 with rectangle 2: 3/6 == 10/20.
    /// - Rectangle 1 with rectangle 3: 3/6 == 15/30.
    /// - Rectangle 2 with rectangle 3: 10/20 == 15/30.
    ///
    /// Example 2:
    /// Input: rectangles = [[4,5],[7,8]]
    /// Output: 0
    /// Explanation: There are no interchangeable pairs of rectangles.
    /// 
    /// Constraints:
    /// 1. n == rectangles.length
    /// 2. 1 <= n <= 10^5
    /// 3. rectangles[i].length == 2
    /// 4. 1 <= widthi, heighti <= 10^5
    /// </summary>
    long long interchangeableRectangles(vector<vector<int>>& rectangles); 

    /// <summary>
    /// Leet Code 1953. Maximum Number of Weeks for Which You Can Work 
    ///                                                                 
    /// Medium
    ///
    /// There are n projects numbered from 0 to n - 1. You are given an integer
    /// array milestones where each milestones[i] denotes the number of 
    /// milestones the ith project has.
    /// You can work on the projects following these two rules:
    /// Every week, you will finish exactly one milestone of one project. You 
    /// must work every week.
    /// You cannot work on two milestones from the same project for two 
    /// consecutive weeks.
    /// Once all the milestones of all the projects are finished, or if the 
    /// only milestones that you can work on will cause you to violate the 
    /// above rules, you will stop working. Note that you may not be able to 
    /// finish every project's milestones due to these constraints.
    ///
    /// Return the maximum number of weeks you would be able to work on the 
    /// projects without violating the rules mentioned above.
    /// 
    /// Example 1:
    /// Input: milestones = [1,2,3]
    /// Output: 6
    /// Explanation: One possible scenario is:
    /// - During the 1st week, you will work on a milestone of project 0.
    /// - During the 2nd week, you will work on a milestone of project 2.
    /// - During the 3rd week, you will work on a milestone of project 1.
    /// - During the 4th week, you will work on a milestone of project 2.
    /// - During the 5th week, you will work on a milestone of project 1.
    /// - During the 6th week, you will work on a milestone of project 2.
    /// The total number of weeks is 6.
    ///
    /// Example 2:
    /// Input: milestones = [5,2,1]
    /// Output: 7
    /// Explanation: One possible scenario is:
    /// - During the 1st week, you will work on a milestone of project 0.
    /// - During the 2nd week, you will work on a milestone of project 1.
    /// - During the 3rd week, you will work on a milestone of project 0.
    /// - During the 4th week, you will work on a milestone of project 1.
    /// - During the 5th week, you will work on a milestone of project 0.
    /// - During the 6th week, you will work on a milestone of project 2.
    /// - During the 7th week, you will work on a milestone of project 0.
    /// The total number of weeks is 7.
    /// Note that you cannot work on the last milestone of project 0 on 
    /// 8th week because it would violate the rules.
    /// Thus, one milestone in project 0 will remain unfinished.
    ///
    /// Constraints:
    /// 1. n == milestones.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= milestones[i] <= 10^9
    /// </summary>
    long long numberOfWeeks(vector<int>& milestones);

    /// <summary>
    /// Leet Code 1999. Smallest Greater Multiple Made of Two Digits
    ///                                                                 
    /// Medium
    ///
    /// Given three integers, k, digit1, and digit2, you want to find the 
    /// smallest integer that is:
    ///
    /// Larger than k,
    /// A multiple of k, and
    /// Comprised of only the digits digit1 and/or digit2.
    /// Return the smallest such integer. If no such integer exists or the 
    /// integer exceeds the limit of a signed 32-bit integer (231 - 1), 
    /// return -1.
    /// 
    /// Example 1:
    /// Input: k = 2, digit1 = 0, digit2 = 2
    /// Output: 20
    /// Explanation:
    /// 20 is the first integer larger than 2, a multiple of 2, and comprised 
    /// of only the digits 0 and/or 2.
    ///
    /// Example 2:
    /// Input: k = 3, digit1 = 4, digit2 = 2
    /// Output: 24
    /// Explanation:
    /// 24 is the first integer larger than 3, a multiple of 3, and comprised 
    /// of only the digits 4 and/or 2.
    ///
    /// Example 3:
    /// Input: k = 2, digit1 = 0, digit2 = 0
    /// Output: -1
    /// Explanation:
    /// No integer meets the requirements so return -1.
    ///
    /// Constraints:
    /// 1. 1 <= k <= 1000
    /// 2. 0 <= digit1 <= 9
    /// 3. 0 <= digit2 <= 9
    /// </summary>
    int findInteger(int k, int digit1, int digit2);

    /// <summary>
    /// Leet Code 2048. Next Greater Numerically Balanced Number
    ///                                                                 
    /// Medium
    ///
    /// An integer x is numerically balanced if for every digit d in 
    /// the number x, there are exactly d occurrences of that digit in x.
    ///
    /// Given an integer n, return the smallest numerically balanced 
    /// number strictly greater than n.
    /// 
    /// Example 1:
    /// Input: n = 1
    /// Output: 22
    /// Explanation: 
    /// 22 is numerically balanced since:
    /// - The digit 2 occurs 2 times. 
    /// It is also the smallest numerically balanced number strictly greater 
    /// than 1.
    ///
    /// Example 2:
    /// Input: n = 1000
    /// Output: 1333
    /// Explanation: 
    /// 1333 is numerically balanced since:
    /// - The digit 1 occurs 1 time.
    /// - The digit 3 occurs 3 times. 
    /// It is also the smallest numerically balanced number strictly greater 
    /// than 1000.
    /// Note that 1022 cannot be the answer because 0 appeared more 
    /// than 0 times.
    ///
    /// Example 3:
    /// Input: n = 3000
    /// Output: 3133
    /// Explanation: 
    /// 3133 is numerically balanced since:
    /// - The digit 1 occurs 1 time.
    /// - The digit 3 occurs 3 times.
    /// It is also the smallest numerically balanced number strictly 
    /// greater than 3000.
    /// 
    /// Constraints:
    /// 1. 0 <= n <= 10^6
    /// </summary>
    int nextBeautifulNumber(int n);
    /// <summary>
    /// Leet Code 2117. Abbreviating the Product of a Range 
    ///                                                                 
    /// Medium
    ///
    /// You are given two positive integers left and right with left <= right. 
    /// Calculate the product of all integers in the inclusive range 
    /// [left, right].
    ///
    /// Since the product may be very large, you will abbreviate it following 
    /// these steps:
    ///
    /// Count all trailing zeros in the product and remove them. Let us 
    /// denote this count as C.
    /// For example, there are 3 trailing zeros in 1000, and there are 0 
    /// trailing zeros in 546.
    /// Denote the remaining number of digits in the product as d. If d > 10, 
    /// then express the product as <pre>...<suf> where <pre> denotes the 
    /// first 5 digits of the product, and <suf> denotes the last 5 digits 
    /// of the product after removing all trailing zeros. If d <= 10, we 
    /// keep it unchanged.
    /// For example, we express 1234567654321 as 12345...54321, but 1234567 
    /// is represented as 1234567.
    /// Finally, represent the product as a string "<pre>...<suf>eC".
    /// For example, 12345678987600000 will be represented 
    /// as "12345...89876e5".
    /// Return a string denoting the abbreviated product of all integers in 
    /// the inclusive range [left, right].
    /// 
    /// Example 1:
    /// Input: left = 1, right = 4
    /// Output: "24e0"
    /// Explanation:
    /// The product is 1 × 2 × 3 × 4 = 24.
    /// There are no trailing zeros, so 24 remains the same. The abbreviation 
    /// will end with "e0".
    /// Since the number of digits is 2, which is less than 10, we do not 
    /// have to abbreviate it further.
    /// Thus, the final representation is "24e0". 
    ///
    /// Example 2:
    /// Input: left = 2, right = 11
    /// Output: "399168e2"
    /// Explanation:
    /// The product is 39916800.
    /// There are 2 trailing zeros, which we remove to get 399168. The 
    /// abbreviation will end with "e2".
    /// The number of digits after removing the trailing zeros is 6, so we 
    /// do not abbreviate it further.
    /// Hence, the abbreviated product is "399168e2".  
    ///
    /// Example 3:
    /// Input: left = 999998, right = 1000000
    /// Output: "99999...00002e6"
    /// Explanation:
    /// The above diagram shows how we abbreviate the product 
    /// to "99999...00002e6".
    /// - It has 6 trailing zeros. The abbreviation will end with "e6".
    /// - The first 5 digits are 99999.
    /// - The last 5 digits after removing trailing zeros is 00002.
    /// 
    /// Constraints:
    /// 1. 1 <= left <= right <= 10^6
    /// </summary>
    string abbreviateProduct(int left, int right);

    /// <summary>
    /// Leet Code 2119. A Number After a Double Reversal
    ///                                                                 
    /// Easy
    ///
    /// Reversing an integer means to reverse all its digits.
    ///
    /// For example, reversing 2021 gives 1202. Reversing 12300 
    /// gives 321 as the leading zeros are not retained.
    /// Given an integer num, reverse num to get reversed1, then reverse 
    /// reversed1 to get reversed2. Return true if reversed2 equals num. 
    /// Otherwise return false.
    /// 
    /// Example 1:
    /// Input: num = 526
    /// Output: true
    /// Explanation: Reverse num to get 625, then reverse 625 to get 
    /// 526, which equals num.
    ///
    /// Example 2:
    /// Input: num = 1800
    /// Output: false
    /// Explanation: Reverse num to get 81, then reverse 81 to get 18, 
    /// which does not equal num.
    ///
    /// Example 3:
    /// Input: num = 0
    /// Output: true
    /// Explanation: Reverse num to get 0, then reverse 0 to get 0, 
    /// which equals num.
    /// 
    /// Constraints:
    /// 1. 0 <= num <= 10^6
    /// </summary>
    bool isSameAfterReversals(int num);

    /// <summary>
    /// Leet Code 2139. Minimum Moves to Reach Target Score
    ///                                                                 
    /// Medium
    ///
    /// You are playing a game with integers. You start with the integer 1 and 
    /// you want to reach the integer target.
    ///
    /// In one move, you can either:
    /// Increment the current integer by one (i.e., x = x + 1).
    /// Double the current integer (i.e., x = 2 * x).
    /// You can use the increment operation any number of times, however, you 
    /// can only use the double operation at most maxDoubles times.
    ///
    /// Given the two integers target and maxDoubles, return the minimum 
    /// number of moves needed to reach target starting with 1.
    /// 
    /// Example 1:
    /// Input: target = 5, maxDoubles = 0
    /// Output: 4
    /// Explanation: Keep incrementing by 1 until you reach target.
    ///
    /// Example 2:
    /// Input: target = 19, maxDoubles = 2
    /// Output: 7
    /// Explanation: Initially, x = 1
    /// Increment 3 times so x = 4
    /// Double once so x = 8
    /// Increment once so x = 9
    /// Double again so x = 18
    /// Increment once so x = 19
    ///
    /// Example 3:
    /// Input: target = 10, maxDoubles = 4
    /// Output: 4
    /// Explanation: Initially, x = 1
    /// Increment once so x = 2
    /// Double once so x = 4
    /// Increment once so x = 5
    /// Double again so x = 10
    ///
    /// Constraints:
    /// 1. 1 <= target <= 10^9
    /// 2. 0 <= maxDoubles <= 100
    /// </summary>
    int minMoves(int target, int maxDoubles);

    /// <summary>
    /// Leet Code 2152. Minimum Number of Lines to Cover Points
    ///                                                                 
    /// Medium
    ///
    /// You are given an array points where points[i] = [xi, yi] represents 
    /// a point on an X-Y plane.
    ///
    /// Straight lines are going to be added to the X-Y plane, such that every 
    /// point is covered by at least one line.
    ///
    /// Return the minimum number of straight lines needed to cover all the 
    /// points.
    /// 
    /// Example 1:
    /// Input: points = [[0,1],[2,3],[4,5],[4,3]]
    /// Output: 2
    /// Explanation: The minimum number of straight lines needed is two. One 
    /// possible solution is to add:
    /// - One line connecting the point at (0, 1) to the point at (4, 5).
    /// - Another line connecting the point at (2, 3) to the point at (4, 3).
    ///
    /// Example 2:
    /// Input: points = [[0,2],[-2,-2],[1,4]]
    /// Output: 1
    /// Explanation: The minimum number of straight lines needed is one. The 
    /// only solution is to add:
    /// - One line connecting the point at (-2, -2) to the point at (1, 4).
    /// 
    /// Constraints:
    /// 1. 1 <= points.length <= 10
    /// 2. points[i].length == 2
    /// 3. -100 <= xi, yi <= 100
    /// 4. All the points are unique.
    /// </summary>
    int minimumLines(vector<vector<int>>& points);

    /// <summary>
    /// Leet Code 2145. Count the Hidden Sequences
    ///                                                                 
    /// Medium
    ///
    /// You are given a 0-indexed array of n integers differences, which 
    /// describes the differences between each pair of consecutive integers 
    /// of a hidden sequence of length (n + 1). More formally, call the 
    /// hidden sequence hidden, then we have that differences[i] = 
    /// hidden[i + 1] - hidden[i].
    ///
    /// You are further given two integers lower and upper that describe the 
    /// inclusive range of values [lower, upper] that the hidden sequence can 
    /// contain.
    ///
    /// For example, given differences = [1, -3, 4], lower = 1, upper = 6, the 
    /// hidden sequence is a sequence of length 4 whose elements are in 
    /// between 1 and 6 (inclusive).
    /// [3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
    /// [5, 6, 3, 7] is not possible since it contains an element greater 
    /// than 6.
    /// [1, 2, 3, 4] is not possible since the differences are not correct.
    /// Return the number of possible hidden sequences there are. If there 
    /// are no possible sequences, return 0.
    /// 
    /// Example 1:
    /// Input: differences = [1,-3,4], lower = 1, upper = 6
    /// Output: 2
    /// Explanation: The possible hidden sequences are:
    /// - [3, 4, 1, 5]
    /// - [4, 5, 2, 6]
    /// Thus, we return 2.
    ///
    /// Example 2:
    /// Input: differences = [3,-4,5,1,-2], lower = -4, upper = 5
    /// Output: 4
    /// Explanation: The possible hidden sequences are:
    /// - [-3, 0, -4, 1, 2, 0]
    /// - [-2, 1, -3, 2, 3, 1]
    /// - [-1, 2, -2, 3, 4, 2]
    /// - [0, 3, -1, 4, 5, 3]
    /// Thus, we return 4.
    ///
    /// Example 3:
    /// Input: differences = [4,-7,2], lower = 3, upper = 6
    /// Output: 0
    /// Explanation: There are no possible hidden sequences. Thus, we return 0.
    ///
    /// Constraints:
    /// 1. n == differences.length
    /// 2. 1 <= n <= 10^5
    /// 3. -10^5 <= differences[i] <= 10^5
    /// 4. -10^5 <= lower <= upper <= 10^5
    /// </summary>
    int numberOfArrays(vector<int>& differences, int lower, int upper);

    /// <summary>
    /// Leet Code 2160. Minimum Sum of Four Digit Number After Splitting 
    ///                 Digits
    ///                                                                 
    /// Easy
    ///
    /// You are given a positive integer num consisting of exactly four 
    /// digits. Split num into two new integers new1 and new2 by using 
    /// the digits found in num. Leading zeros are allowed in new1 and 
    /// new2, and all the digits found in num must be used.
    /// 
    /// For example, given num = 2932, you have the following digits: 
    /// two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] 
    /// are [22, 93], [23, 92], [223, 9] and [2, 329].
    /// Return the minimum possible sum of new1 and new2.
    ///
    /// Example 1:
    /// Input: num = 2932
    /// Output: 52
    /// Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], 
    /// etc.
    /// The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52. 
    ///
    /// Example 2:
    /// Input: num = 4009
    /// Output: 13
    /// Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], 
    /// etc. 
    /// The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
    ///
    /// Constraints:
    /// 1. 1000 <= num <= 9999
    /// </summary>
    int minimumSum(int num);

    /// <summary>
    /// Leet Code 2162. Minimum Cost to Set Cooking Time
    ///                                                                 
    /// Medium
    ///
    /// A generic microwave supports cooking times for:
    ///
    /// at least 1 second.
    /// at most 99 minutes and 99 seconds.
    /// To set the cooking time, you push at most four digits. The microwave 
    /// normalizes what you push as four digits by prepending zeroes. It 
    /// interprets the first two digits as the minutes and the last two digits 
    /// as the seconds. It then adds them up as the cooking time. For example,
    ///
    /// You push 9 5 4 (three digits). It is normalized as 0954 and interpreted
    /// as 9 minutes and 54 seconds.
    /// You push 0 0 0 8 (four digits). It is interpreted as 0 minutes and 8 
    /// seconds.
    /// You push 8 0 9 0. It is interpreted as 80 minutes and 90 seconds.
    /// You push 8 1 3 0. It is interpreted as 81 minutes and 30 seconds.
    /// You are given integers startAt, moveCost, pushCost, and targetSeconds. 
    /// Initially, your finger is on the digit startAt. Moving the finger 
    /// above any specific digit costs moveCost units of fatigue. Pushing the 
    /// digit below the finger once costs pushCost units of fatigue.
    ///
    /// There can be multiple ways to set the microwave to cook for 
    /// targetSeconds seconds but you are interested in the way with the 
    /// minimum cost.
    ///
    /// Return the minimum cost to set targetSeconds seconds of cooking time.
    /// Remember that one minute consists of 60 seconds.
    ///
    /// Example 1:
    /// Input: startAt = 1, moveCost = 2, pushCost = 1, targetSeconds = 600
    /// Output: 6
    /// Explanation: The following are the possible ways to set the cooking 
    /// time.
    /// - 1 0 0 0, interpreted as 10 minutes and 0 seconds.
    /// The finger is already on digit 1, pushes 1 (with cost 1), moves 
    /// to 0 (with cost 2), pushes 0 (with cost 1), pushes 0 (with cost 1), 
    /// and pushes 0 (with cost 1).
    /// The cost is: 1 + 2 + 1 + 1 + 1 = 6. This is the minimum cost.
    /// - 0 9 6 0, interpreted as 9 minutes and 60 seconds. That is also 600 
    /// seconds.
    /// The finger moves to 0 (with cost 2), pushes 0 (with cost 1), moves 
    /// to 9 (with cost 2), pushes 9 (with cost 1), moves to 6 (with cost 2), 
    /// pushes 6 (with cost 1), moves to 0 (with cost 2), and pushes 0 
    /// (with cost 1). 
    /// The cost is: 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 = 12.
    /// - 9 6 0, normalized as 0960 and interpreted as 9 minutes and 60 
    /// seconds.
    /// The finger moves to 9 (with cost 2), pushes 9 (with cost 1), moves 
    /// to 6 (with cost 2), pushes 6 (with cost 1), moves to 0 (with cost 2), 
    /// and pushes 0 (with cost 1).
    /// The cost is: 2 + 1 + 2 + 1 + 2 + 1 = 9.
    ///
    /// Example 2:
    /// Input: startAt = 0, moveCost = 1, pushCost = 2, targetSeconds = 76
    /// Output: 6
    /// Explanation: The optimal way is to push two digits: 7 6, interpreted 
    /// as 76 seconds.
    /// The finger moves to 7 (with cost 1), pushes 7 (with cost 2), moves 
    /// to 6 (with cost 1), and pushes 6 (with cost 2). The total cost is: 
    /// 1 + 2 + 1 + 2 = 6
    /// Note other possible ways are 0076, 076, 0116, and 116, but none of 
    /// them produces the minimum cost.
    ///
    /// Constraints:
    /// 1. 0 <= startAt <= 9
    /// 2. 1 <= moveCost, pushCost <= 10^5
    /// 3. 1 <= targetSeconds <= 6039
    /// </summary>
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds);

    /// <summary>
    /// Leet Code 2169. Count Operations to Obtain Zero
    ///                                                                                  
    /// Easy
    ///
    /// You are given two non-negative integers num1 and num2.
    ///
    /// In one operation, if num1 >= num2, you must subtract num2 from num1, 
    /// otherwise subtract num1 from num2.
    ///
    /// For example, if num1 = 5 and num2 = 4, subtract num2 from num1, thus 
    /// obtaining num1 = 1 and num2 = 4. However, if num1 = 4 and num2 = 5, 
    /// after one operation, num1 = 4 and num2 = 1.
    /// Return the number of operations required to make either num1 = 0 or 
    /// num2 = 0.
    ///
    /// Example 1:
    /// Input: num1 = 2, num2 = 3
    /// Output: 3
    /// Explanation: 
    /// - Operation 1: num1 = 2, num2 = 3. Since num1 < num2, we subtract num1 
    /// from num2 and get num1 = 2, num2 = 3 - 2 = 1.
    /// - Operation 2: num1 = 2, num2 = 1. Since num1 > num2, we subtract num2 
    /// from num1.
    /// - Operation 3: num1 = 1, num2 = 1. Since num1 == num2, we subtract num2 
    /// from num1.
    /// Now num1 = 0 and num2 = 1. Since num1 == 0, we do not need to perform 
    /// any further operations.
    /// So the total number of operations required is 3.
    ///
    /// Example 2:
    /// Input: num1 = 10, num2 = 10
    /// Output: 1
    /// Explanation: 
    /// - Operation 1: num1 = 10, num2 = 10. Since num1 == num2, we subtract 
    /// num2 from num1 and get num1 = 10 - 10 = 0.
    /// Now num1 = 0 and num2 = 10. Since num1 == 0, we are done.
    /// So the total number of operations required is 1.
    /// 
    /// Constraints:
    /// 1. 0 <= num1, num2 <= 10^5
    /// </summary>
    int countOperations(int num1, int num2);

    /// <summary>
    /// Leet Code 2180. Count Integers With Even Digit Sum
    ///                                                                                  
    /// Easy
    ///
    /// Given a positive integer num, return the number of positive integers 
    /// less than or equal to num whose digit sums are even.
    /// The digit sum of a positive integer is the sum of all its digits.
    ///
    /// Example 1:
    /// Input: num = 4
    /// Output: 2
    /// Explanation:
    /// The only integers less than or equal to 4 whose digit sums are even 
    /// are 2 and 4.    
    ///
    /// Example 2:
    /// Input: num = 30
    /// Output: 14
    /// Explanation:
    /// The 14 integers less than or equal to 30 whose digit sums are even are
    /// 2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, and 28.
    ///	
    /// Constraints:
    /// 1. 1 <= num <= 1000
    /// </summary>
    int countEven(int num);

    /// <summary>
    /// Leet Code 2177. Find Three Consecutive Integers That Sum to a Given 
    ///                 Number
    ///                                                                                  
    /// Medium
    ///
    /// Given an integer num, return three consecutive integers (as a sorted 
    /// array) that sum to num. If num cannot be expressed as the sum of three 
    /// consecutive integers, return an empty array.
    /// 
    /// Example 1:
    /// Input: num = 33
    /// Output: [10,11,12]
    /// Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
    /// 10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].
    ///
    /// Example 2:
    /// Input: num = 4
    /// Output: []
    /// Explanation: There is no way to express 4 as the sum of 3 consecutive 
    /// integers.
    ///
    /// Constraints:
    /// 1. 0 <= num <= 10^15
    /// </summary>
    vector<long long> sumOfThree(long long num);

    /// <summary>
    /// Leet Code 2178. Maximum Split of Positive Even Integers 
    ///                                                                                  
    /// Medium
    ///
    /// You are given an integer finalSum. Split it into a sum of a maximum 
    /// number of unique positive even integers.
    ///
    /// For example, given finalSum = 12, the following splits are valid 
    /// (unique positive even integers summing up to finalSum): (2 + 10), 
    /// (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the 
    /// maximum number of integers. Note that finalSum cannot be split into 
    /// (2 + 2 + 4 + 4) as all the numbers should be unique.
    /// Return a list of integers that represent a valid split containing a 
    /// maximum number of integers. If no valid split exists for finalSum, 
    /// return an empty list. You may return the integers in any order.
    ///
    /// Example 1:
    /// Input: finalSum = 12
    /// Output: [2,4,6]
    /// Explanation: The following are some valid splits: (2 + 10), 
    /// (2 + 4 + 6), and (4 + 8).
    /// (2 + 4 + 6) has the maximum number of integers, which is 3. Thus, we 
    /// return [2,4,6].
    /// Note that [2,6,4], [6,2,4], etc. are also accepted.
    ///
    /// Example 2:
    /// Input: finalSum = 7
    /// Output: []
    /// Explanation: There are no valid splits for the given finalSum.
    /// Thus, we return an empty array.
    ///
    /// Example 3:
    /// Input: finalSum = 28
    /// Output: [6,8,2,12]
    /// Explanation: The following are some valid splits: (2 + 26), 
    /// (6 + 8 + 2 + 12), and (4 + 24). 
    /// (6 + 8 + 2 + 12) has the maximum number of integers, which is 4. 
    /// Thus, we return [6,8,2,12].
    /// Note that [10,2,4,12], [6,2,4,16], etc. are also accepted.
    /// 
    /// Constraints:
    /// 1. 1 <= finalSum <= 10^10
    /// </summary>
    vector<long long> maximumEvenSplit(long long finalSum);

    /// <summary>
    /// Leet Code 2183. Count Array Pairs Divisible by K
    ///                                                                                  
    /// Hard
    ///
    /// Given a 0-indexed integer array nums of length n and an integer k, 
    /// return the number of pairs (i, j) such that:
    ///
    /// 0 <= i < j <= n - 1 and
    /// nums[i] * nums[j] is divisible by k.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3,4,5], k = 2
    /// Output: 7
    /// Explanation: 
    /// The 7 pairs of indices whose corresponding products are divisible 
    /// by 2 are
    /// (0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4).
    /// Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.
    /// Other pairs such as (0, 2) and (2, 4) have products 3 and 15 
    /// respectively, which are not divisible by 2.    
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4], k = 5
    /// Output: 0
    /// Explanation: There does not exist any pair of indices whose 
    /// corresponding product is divisible by 5.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i], k <= 10^5
    /// </summary>
    long long countPairs(vector<int>& nums, int k);


    /// <summary>
    /// Leet Code 2197. Replace Non-Coprime Numbers in Array
    ///                                                                                   
    /// Hard
    ///
    /// You are given an array of integers nums. Perform the following steps:
    ///
    /// Find any two adjacent numbers in nums that are non-coprime.
    /// If no such numbers are found, stop the process.
    /// Otherwise, delete the two numbers and replace them with their LCM 
    /// (Least Common Multiple).
    /// Repeat this process as long as you keep finding two adjacent 
    /// non-coprime numbers.
    /// Return the final modified array. It can be shown that replacing 
    /// adjacent non-coprime numbers in any arbitrary order will lead to the 
    /// same result.
    ///
    /// The test cases are generated such that the values in the final array 
    /// are less than or equal to 108.
    ///
    /// Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) 
    /// is the Greatest Common Divisor of x and y.
    /// 
    /// Example 1:
    /// Input: nums = [6,4,3,2,7,6,2]
    /// Output: [12,7,6]
    /// Explanation: 
    /// - (6, 4) are non-coprime with LCM(6, 4) = 12. Now, 
    /// nums = [12,3,2,7,6,2].
    /// - (12, 3) are non-coprime with LCM(12, 3) = 12. Now, 
    /// nums = [12,2,7,6,2].
    /// - (12, 2) are non-coprime with LCM(12, 2) = 12. Now, 
    /// nums = [12,7,6,2].
    /// - (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
    /// There are no more adjacent non-coprime numbers in nums.
    /// Thus, the final modified array is [12,7,6].
    /// Note that there are other ways to obtain the same resultant array.
    ///
    /// Example 2:
    /// Input: nums = [2,2,1,1,3,3,3]
    /// Output: [2,1,1,3]
    /// Explanation: 
    /// - (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3,3].
    /// - (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3].
    /// - (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [2,1,1,3].
    /// There are no more adjacent non-coprime numbers in nums.
    /// Thus, the final modified array is [2,1,1,3].
    /// Note that there are other ways to obtain the same resultant array.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 105
    /// 3. The test cases are generated such that the values in the final 
    ///    array are less than or equal to 10^8.
    /// </summary>
    vector<int> replaceNonCoprimes(vector<int>& nums);

    /// <summary>
    /// Leet Code 2198. Number of Single Divisor Triplets
    ///                                                                                   
    /// Medium
    ///
    /// You are given a 0-indexed array of positive integers nums. A triplet 
    /// of three distinct indices (i, j, k) is called a single divisor triplet 
    /// of nums if nums[i] + nums[j] + nums[k] is divisible by exactly one 
    /// of nums[i], nums[j], or nums[k].
    ///
    /// Return the number of single divisor triplets of nums.
    ///
    /// Example 1:
    /// Input: nums = [4,6,7,3,2]
    /// Output: 12
    /// Explanation:
    /// The triplets (0, 3, 4), (0, 4, 3), (3, 0, 4), (3, 4, 0), (4, 0, 3), 
    /// and (4, 3, 0) have the values of [4, 3, 2] (or a permutation of 
    /// [4, 3, 2]).
    /// 4 + 3 + 2 = 9 which is only divisible by 3, so all such triplets 
    /// are single divisor triplets.
    /// The triplets (0, 2, 3), (0, 3, 2), (2, 0, 3), (2, 3, 0), (3, 0, 2), 
    /// and (3, 2, 0) have the values of [4, 7, 3] (or a permutation of 
    /// [4, 7, 3]).
    /// 4 + 7 + 3 = 14 which is only divisible by 7, so all such triplets 
    /// are single divisor triplets.
    /// There are 12 single divisor triplets in total.
    ///
    /// Example 2:
    /// Input: nums = [1,2,2]
    /// Output: 6
    /// Explanation:
    /// The triplets (0, 1, 2), (0, 2, 1), (1, 0, 2), (1, 2, 0), (2, 0, 1), 
    /// and (2, 1, 0) have the values of [1, 2, 2] (or a permutation of 
    /// [1, 2, 2]).
    /// 1 + 2 + 2 = 5 which is only divisible by 1, so all such triplets 
    /// are single divisor triplets.
    /// There are 6 single divisor triplets in total.
    ///
    /// Example 3:
    /// Input: nums = [1,1,1]
    /// Output: 0
    /// Explanation:
    /// There are no single divisor triplets.
    /// Note that (0, 1, 2) is not a single divisor triplet because nums[0] + 
    /// nums[1] + nums[2] = 3 and 3 is divisible by nums[0], nums[1], and 
    /// nums[2].
    ///
    /// Constraints:
    /// 1. 3 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 100
    /// </summary>
    long long singleDivisorTriplet(vector<int>& nums);

    /// <summary>
    /// Leet Code 2195. Append K Integers With Minimal Sum
    ///                                                                                   
    /// Medium
    ///
    /// You are given an integer array nums and an integer k. Append k unique 
    /// positive integers that do not appear in nums to nums such that the 
    /// resulting total sum is minimum.
    ///
    /// Return the sum of the k integers appended to nums.
    ///
    /// Example 1:
    /// Input: nums = [1,4,25,10,25], k = 2
    /// Output: 5
    /// Explanation: The two unique positive integers that do not appear in 
    /// nums which we append are 2 and 3.
    /// The resulting sum of nums is 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70, which 
    /// is the minimum.
    /// The sum of the two integers appended is 2 + 3 = 5, so we return 5.
    ///
    /// Example 2:
    /// Input: nums = [5,6], k = 6
    /// Output: 25
    /// Explanation: The six unique positive integers that do not appear in 
    /// nums which we append are 1, 2, 3, 4, 7, and 8.
    /// The resulting sum of nums is 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36, which 
    /// is the minimum. 
    /// The sum of the six integers appended is 1 + 2 + 3 + 4 + 7 + 8 = 25, so 
    /// we return 25.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= k <= 10^8
    /// </summary>
    long long minimalKSum(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2202. Maximize the Topmost Element After K Moves
    ///                                                                                   
    /// Medium
    ///
    /// You are given a 0-indexed integer array nums representing the contents 
    /// of a pile, where nums[0] is the topmost element of the pile.
    ///
    /// In one move, you can perform either of the following:
    ///
    /// If the pile is not empty, remove the topmost element of the pile.
    /// If there are one or more removed elements, add any one of them back 
    /// onto the pile. This element becomes the new topmost element.
    /// You are also given an integer k, which denotes the total number of 
    /// moves to be made.  
    /// Return the maximum value of the topmost element of the pile possible 
    /// after exactly k moves. In case it is not possible to obtain a 
    /// non-empty pile after k moves, return -1.
    /// 
    /// Example 1:
    /// Input: nums = [5,2,2,4,0,6], k = 4
    /// Output: 5
    /// Explanation:
    /// One of the ways we can end with 5 at the top of the pile after 4 moves 
    /// is as follows:
    /// - Step 1: Remove the topmost element = 5. The pile becomes [2,2,4,0,6].
    /// - Step 2: Remove the topmost element = 2. The pile becomes [2,4,0,6].
    /// - Step 3: Remove the topmost element = 2. The pile becomes [4,0,6].
    /// - Step 4: Add 5 back onto the pile. The pile becomes [5,4,0,6].
    /// Note that this is not the only way to end with 5 at the top of the 
    /// pile. It can be shown that 5 is the largest answer possible after 4 
    /// moves.
    ///
    /// Example 2:
    /// 
    /// Input: nums = [2], k = 1
    /// Output: -1
    /// Explanation: 
    /// In the first move, our only option is to pop the topmost element of 
    /// the pile.
    /// Since it is not possible to obtain a non-empty pile after one move, 
    /// we return -1.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 0 <= nums[i], k <= 10^9
    /// </summary>
    int maximumTop(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2217. Find Palindrome With Fixed Length
    ///                                                                                   
    /// Medium
    ///
    /// Given an integer array queries and a positive integer intLength, 
    /// return an array answer where answer[i] is either the queries[i]th 
    /// smallest positive palindrome of length intLength or -1 if no such 
    /// palindrome exists.
    ///
    /// A palindrome is a number that reads the same backwards and forwards. 
    /// Palindromes cannot have leading zeros.
    ///
    /// Example 1:
    /// Input: queries = [1,2,3,4,5,90], intLength = 3
    /// Output: [101,111,121,131,141,999]
    /// Explanation:
    /// The first few palindromes of length 3 are:
    /// 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
    /// The 90th palindrome of length 3 is 999.
    ///
    /// Example 2:
    /// Input: queries = [2,4,6], intLength = 4
    /// Output: [1111,1331,1551]
    /// Explanation:
    /// The first six palindromes of length 4 are:
    /// 1001, 1111, 1221, 1331, 1441, and 1551.
    /// 
    /// Constraints:
    /// 1. 1 <= queries.length <= 5 * 10^4
    /// 2. 1 <= queries[i] <= 10^9
    /// 3. 1 <= intLength <= 15
    /// </summary>
    vector<long long> kthPalindrome(vector<int>& queries, int intLength);

    /// <summary>
    /// Leet Code 2231. Largest Number After Digit Swaps by Parity
    ///                                                                                   
    /// Easy
    ///
    /// You are given a positive integer num. You may swap any two digits of 
    /// num that have the same parity (i.e. both odd digits or both even 
    /// digits).
    ///
    /// Return the largest possible value of num after any number of swaps.
    /// 
    /// Example 1:
    /// Input: num = 1234
    /// Output: 3412
    /// Explanation: Swap the digit 3 with the digit 1, this results in the 
    /// number 3214.
    /// Swap the digit 2 with the digit 4, this results in the number 3412.
    /// Note that there may be other sequences of swaps but it can be shown 
    /// that 3412 is the largest possible number.
    /// Also note that we may not swap the digit 4 with the digit 1 since 
    ///  they are of different parities.
    ///
    /// Example 2:
    /// Input: num = 65875
    /// Output: 87655
    /// Explanation: Swap the digit 8 with the digit 6, this results in the 
    /// number 85675.
    /// Swap the first digit 5 with the digit 7, this results in the 
    /// number 87655.
    /// Note that there may be other sequences of swaps but it can be shown 
    /// that 87655 is the largest possible number.
    ///  
    /// Constraints:
    /// 1. 1 <= num <= 10^9
    /// </summary>
    int largestInteger(int num);

    /// <summary>
    /// Leet Code 2233. Maximum Product After K Increments
    ///                                                                                   
    /// Medium
    ///
    /// You are given an array of non-negative integers nums and an integer k. 
    /// In one operation, you may choose any element from nums and increment 
    /// it by 1.
    ///
    /// Return the maximum product of nums after at most k operations. Since 
    /// the answer may be very large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: nums = [0,4], k = 5
    /// Output: 20
    /// Explanation: Increment the first number 5 times.
    /// Now nums = [5, 4], with a product of 5 * 4 = 20.
    /// It can be shown that 20 is maximum product possible, so we return 20.
    /// Note that there may be other ways to increment nums to have the 
    /// maximum product.
    ///
    /// Example 2:
    /// Input: nums = [6,3,3,2], k = 2
    /// Output: 216
    /// Explanation: Increment the second number 1 time and increment the 
    /// fourth number 1 time.
    /// Now nums = [6, 4, 3, 3], with a product of 6 * 4 * 3 * 3 = 216.
    /// It can be shown that 216 is maximum product possible, so we return 216.
    /// Note that there may be other ways to increment nums to have the maximum 
    /// product.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length, k <= 10^5
    /// 2. 0 <= nums[i] <= 10^6
    /// </summary>
    int maximumProduct(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2235. Add Two Integers
    ///                                                                                   
    /// Easy
    /// 
    /// Given two integers num1 and num2, return the sum of the two integers.
    ///  
    /// Example 1:
    /// Input: num1 = 12, num2 = 5
    /// Output: 17
    /// Explanation: num1 is 12, num2 is 5, and their sum is 12 + 5 = 17, 
    /// so 17 is returned.
    ///
    /// Example 2:
    /// Input: num1 = -10, num2 = 4
    /// Output: -6
    /// Explanation: num1 + num2 = -6, so -6 is returned.
    /// 
    /// Constraints:
    /// 1. -100 <= num1, num2 <= 100
    /// </summary>
    int sum(int num1, int num2);

    /// <summary>
    /// Leet Code 2239. Find Closest Number to Zero
    ///                                                                                   
    /// Easy
    /// 
    /// Given an integer array nums of size n, return the number with the 
    /// value closest to 0 in nums. If there are multiple answers, return 
    /// the number with the largest value.
    ///
    /// Example 1:
    /// Input: nums = [-4,-2,1,4,8]
    /// Output: 1
    /// Explanation:
    /// The distance from -4 to 0 is |-4| = 4.
    /// The distance from -2 to 0 is |-2| = 2.
    /// The distance from 1 to 0 is |1| = 1.
    /// The distance from 4 to 0 is |4| = 4.
    /// The distance from 8 to 0 is |8| = 8.
    /// Thus, the closest number to 0 in the array is 1.
    ///
    /// Example 2:
    /// Input: nums = [2,-1,1]
    /// Output: 1
    /// Explanation: 1 and -1 are both the closest numbers to 0, so 
    /// 1 being larger is returned.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// 2. -10^5 <= nums[i] <= 10^5
    /// </summary>
    int findClosestNumber(vector<int>& nums);

    /// <summary>
    /// Leet Code 2240. Number of Ways to Buy Pens and Pencils
    ///                                                                                   
    /// Medium
    /// 
    /// You are given an integer total indicating the amount of money you 
    /// have. You are also given two integers cost1 and cost2 indicating 
    /// the price of a pen and pencil respectively. You can spend part or 
    /// all of your money to buy multiple quantities (or none) of each 
    /// kind of writing utensil.
    ///
    /// Return the number of distinct ways you can buy some number of 
    /// pens and pencils.
    ///
    /// Example 1:
    /// Input: total = 20, cost1 = 10, cost2 = 5
    /// Output: 9
    /// Explanation: The price of a pen is 10 and the price of a pencil is 5.
    /// - If you buy 0 pens, you can buy 0, 1, 2, 3, or 4 pencils.
    /// - If you buy 1 pen, you can buy 0, 1, or 2 pencils.
    /// - If you buy 2 pens, you cannot buy any pencils.
    /// The total number of ways to buy pens and pencils is 5 + 3 + 1 = 9.
    ///
    /// Example 2:
    /// Input: total = 5, cost1 = 10, cost2 = 10
    /// Output: 1
    /// Explanation: The price of both pens and pencils are 10, which cost 
    /// more than total, so you cannot buy any writing utensils. Therefore, 
    /// there is only 1 way: buy 0 pens and 0 pencils.
    /// 
    /// Constraints:
    /// 1. 1 <= total, cost1, cost2 <= 10^6
    /// </summary>
    long long waysToBuyPensPencils(int total, int cost1, int cost2);

    /// <summary>
    /// Leet Code 2249. Count Lattice Points Inside a Circle
    ///                                                                                      
    /// Medium
    /// 
    /// Given a 2D integer array circles where circles[i] = [xi, yi, ri] 
    /// represents the center (xi, yi) and radius ri of the ith circle 
    /// drawn on a grid, return the number of lattice points that are 
    /// present inside at least one circle.
    ///
    /// Note:
    ///
    /// A lattice point is a point with integer coordinates.
    /// Points that lie on the circumference of a circle are also 
    /// considered to be inside it.
    /// 
    /// Example 1:
    /// Input: circles = [[2,2,1]]
    /// Output: 5
    /// Explanation:
    /// The figure above shows the given circle.
    /// The lattice points present inside the circle are (1, 2), (2, 1), 
    /// (2, 2), (2, 3), and (3, 2) and are shown in green.
    /// Other points such as (1, 1) and (1, 3), which are shown in red, 
    /// are not considered inside the circle.
    /// Hence, the number of lattice points present inside at least one 
    /// circle is 5.
    ///
    /// Example 2:
    /// Input: circles = [[2,2,2],[3,4,1]]
    /// Output: 16
    /// Explanation:
    /// The figure above shows the given circles.
    /// There are exactly 16 lattice points which are present inside at least 
    /// one circle. 
    /// Some of them are (0, 2), (2, 0), (2, 4), (3, 2), and (4, 4).
    /// 
    /// Constraints:
    /// 1. 1 <= circles.length <= 200
    /// 2. circles[i].length == 3
    /// 3. 1 <= xi, yi <= 100
    /// 4. 1 <= ri <= min(xi, yi)
    /// </summary>
    int countLatticePoints(vector<vector<int>>& circles);

    /// <summary>
    /// Leet Code 2280. Minimum Lines to Represent a Line Chart
    ///                                                           
    /// Medium
    /// 
    /// You are given a 2D integer array stockPrices where stockPrices[i] = 
    /// [dayi, pricei] indicates the price of the stock on day dayi is pricei. 
    /// A line chart is created from the array by plotting the points on an 
    /// XY plane with the X-axis representing the day and the Y-axis 
    /// representing the price and connecting adjacent points. One such 
    /// example is shown below:
    /// 
    /// Return the minimum number of lines needed to represent the line chart.
    /// 
    /// Example 1:
    /// Input: stockPrices = [[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]
    /// Output: 3
    /// Explanation:
    /// The diagram above represents the input, with the X-axis representing 
    /// the day and Y-axis representing the price.
    /// The following 3 lines can be drawn to represent the line chart:
    /// - Line 1 (in red) from (1,7) to (4,4) passing through (1,7), (2,6), 
    ///  (3,5), and (4,4).
    /// - Line 2 (in blue) from (4,4) to (5,4).
    /// - Line 3 (in green) from (5,4) to (8,1) passing through (5,4), (6,3), 
    ///   (7,2), and (8,1).
    /// It can be shown that it is not possible to represent the line chart 
    /// using less than 3 lines.
    ///
    /// Example 2:
    /// Input: stockPrices = [[3,4],[1,2],[7,8],[2,3]]
    /// Output: 1
    /// Explanation:
    /// As shown in the diagram above, the line chart can be represented with 
    /// a single line.
    ///
    /// Constraints:
    /// 1. 1 <= stockPrices.length <= 10^5
    /// 2. stockPrices[i].length == 2
    /// 3. 1 <= dayi, pricei <= 109
    /// 4. All dayi are distinct.
    /// </summary>
    int minimumLinesII(vector<vector<int>>& stockPrices);

    /// <summary>
    /// Leet Code 2303. Calculate Amount Paid in Taxes
    ///                                                           
    /// Easy
    /// 
    /// You are given a 0-indexed 2D integer array brackets where 
    /// brackets[i] = [upperi, percenti] means that the ith tax bracket 
    /// has an upper bound of upperi and is taxed at a rate of percenti. 
    /// The brackets are sorted by upper bound (i.e. upperi-1 < upperi 
    /// for 0 < i < brackets.length).
    ///
    /// Tax is calculated as follows:
    /// The first upper0 dollars earned are taxed at a rate of percent0.
    /// The next upper1 - upper0 dollars earned are taxed at a rate of 
    /// percent1.
    /// The next upper2 - upper1 dollars earned are taxed at a rate of 
    /// percent2.
    /// And so on.
    /// You are given an integer income representing the amount of money 
    /// you earned. Return the amount of money that you have to pay in 
    /// taxes. Answers within 10^-5 of the actual answer will be accepted.
    ///  
    /// Example 1:
    /// Input: brackets = [[3,50],[7,10],[12,25]], income = 10
    /// Output: 2.65000
    /// Explanation:
    /// The first 3 dollars you earn are taxed at 50%. You have to 
    /// pay $3 * 50% = $1.50 dollars in taxes. 
    /// The next 7 - 3 = 4 dollars you earn are taxed at 10%. You have to 
    /// pay $4 * 10% = $0.40 dollars in taxes.
    /// The final 10 - 7 = 3 dollars you earn are taxed at 25%. You have 
    /// to pay $3 * 25% = $0.75 dollars in taxes.
    /// You have to pay a total of $1.50 + $0.40 + $0.75 = $2.65 dollars in 
    /// taxes.
    ///
    /// Example 2:
    /// Input: brackets = [[1,0],[4,25],[5,50]], income = 2
    /// Output: 0.25000
    /// Explanation:
    /// The first dollar you earn is taxed at 0%. You have to 
    /// pay $1 * 0% = $0 dollars in taxes.
    /// The second dollar you earn is taxed at 25%. You have to 
    /// pay $1 * 25% = $0.25 dollars in taxes.
    /// You have to pay a total of $0 + $0.25 = $0.25 dollars in taxes.
    ///
    /// Example 3:
    /// Input: brackets = [[2,50]], income = 0
    /// Output: 0.00000
    /// Explanation:
    /// You have no income to tax, so you have to pay a total of $0 dollars 
    /// in taxes.
    ///
    /// Constraints:
    /// 1. 1 <= brackets.length <= 100
    /// 2. 1 <= upperi <= 1000
    /// 3. 0 <= percenti <= 100
    /// 4. 0 <= income <= 1000
    /// 5. upperi is sorted in ascending order.
    /// 6. All the values of upperi are unique.
    /// 7. The upper bound of the last tax bracket is greater than or equal to 
    ///    income.
    /// </summary>
    double calculateTax(vector<vector<int>>& brackets, int income);

    /// <summary>
    /// Leet Code 2310. Sum of Numbers With Units Digit K
    ///                                                           
    /// Medium
    ///
    /// Given two integers num and k, consider a set of positive integers 
    /// with the following properties:
    ///
    /// The units digit of each integer is k.
    /// The sum of the integers is num.
    /// Return the minimum possible size of such a set, or -1 if no such 
    /// set exists.
    ///
    /// Note:
    /// The set can contain multiple instances of the same integer, and the 
    /// sum of an empty set is considered 0.
    /// The units digit of a number is the rightmost digit of the number.
    /// 
    /// Example 1:
    /// Input: num = 58, k = 9
    /// Output: 2
    /// Explanation:
    /// One valid set is [9,49], as the sum is 58 and each integer has a 
    /// units digit of 9.
    /// Another valid set is [19,39].
    /// It can be shown that 2 is the minimum possible size of a valid set.
    ///
    /// Example 2:
    /// Input: num = 37, k = 2
    /// Output: -1
    /// Explanation: It is not possible to obtain a sum of 37 using only 
    /// integers that have a units digit of 2.
    ///
    /// Example 3:
    /// Input: num = 0, k = 7
    /// Output: 0
    /// Explanation: The sum of an empty set is considered 0.
    /// 
    /// Constraints:
    /// 1. 0 <= num <= 3000
    /// 2. 0 <= k <= 9
    /// </summary>
    int minimumNumbers(int num, int k);

    /// <summary>
    /// Leet Code 2335. Minimum Amount of Time to Fill Cups
    ///                                                           
    /// Easy
    ///
    /// You have a water dispenser that can dispense cold, warm, and hot 
    /// water. Every second, you can either fill up 2 cups with different 
    /// types of water, or 1 cup of any type of water.
    ///
    /// You are given a 0-indexed integer array amount of length 3 where 
    /// amount[0], amount[1], and amount[2] denote the number of cold, warm, 
    /// and hot water cups you need to fill respectively. Return the 
    /// minimum number of seconds needed to fill up all the cups.
    ///
    /// 
    /// Example 1:
    /// Input: amount = [1,4,2]
    /// Output: 4
    /// Explanation: One way to fill up the cups is:
    /// Second 1: Fill up a cold cup and a warm cup.
    /// Second 2: Fill up a warm cup and a hot cup.
    /// Second 3: Fill up a warm cup and a hot cup.
    /// Second 4: Fill up a warm cup.
    /// It can be proven that 4 is the minimum number of seconds needed.
    ///
    /// Example 2:
    /// Input: amount = [5,4,4]
    /// Output: 7
    /// Explanation: One way to fill up the cups is:
    /// Second 1: Fill up a cold cup, and a hot cup.
    /// Second 2: Fill up a cold cup, and a warm cup.
    /// Second 3: Fill up a cold cup, and a warm cup.
    /// Second 4: Fill up a warm cup, and a hot cup.
    /// Second 5: Fill up a cold cup, and a hot cup.
    /// Second 6: Fill up a cold cup, and a warm cup.
    /// Second 7: Fill up a hot cup.
    ///
    /// Example 3:
    /// Input: amount = [5,0,0]
    /// Output: 5
    /// Explanation: Every second, we fill up a cold cup.
    /// 
    /// Constraints:
    /// 1. amount.length == 3
    /// 2. 0 <= amount[i] <= 100
    /// </summary>
    int fillCups(vector<int>& amount);

    /// <summary>
    /// Leet Code 2338. Count the Number of Ideal Arrays
    ///                                                           
    /// Medium
    ///
    /// You are given two positive 0-indexed integer arrays nums1 and nums2, 
    /// both of length n.
    ///
    /// The sum of squared difference of arrays nums1 and nums2 is defined as 
    /// the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.
    ///
    /// You are also given two positive integers k1 and k2. You can modify any 
    /// of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you 
    /// can modify any of the elements of nums2 by +1 or -1 at most k2 times.
    ///
    /// Return the minimum sum of squared difference after modifying array 
    /// nums1 at most k1 times and modifying array nums2 at most k2 times.
    ///
    /// Note: You are allowed to modify the array elements to become 
    /// negative integers.
    ///
    /// Example 1:
    /// Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
    /// Output: 579
    /// Explanation: The elements in nums1 and nums2 cannot be modified 
    /// because k1 = 0 and k2 = 0. 
    /// The sum of square difference will be: 
    /// (1 - 2)^2 + (2 - 10)^2 + (3 - 20)^2 + (4 - 19)^2 = 579.
    ///
    /// Example 2:
    /// Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
    /// Output: 43
    /// Explanation: One way to obtain the minimum sum of square difference 
    /// is: 
    /// - Increase nums1[0] once.
    /// - Increase nums2[2] once.
    /// The minimum of the sum of square difference will be: 
    /// (2 - 5)^2 + (4 - 8)^2 + (10 - 7)^2 + (12 - 9)^2 = 43.
    /// Note that, there are other ways to obtain the minimum of the sum of 
    /// square difference, but there is no way to obtain a sum smaller 
    /// than 43.
    ///
    /// Constraints:
    /// 1. n == nums1.length == nums2.length
    /// 2. 1 <= n <= 10^5
    /// 3. 0 <= nums1[i], nums2[i] <= 10^5
    /// 4. 0 <= k1, k2 <= 10^9
    /// </summary>
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2);

    /// <summary>
    /// Leet Code 2344. Minimum Deletions to Make Array Divisible
    ///                                                           
    /// Hard
    ///
    /// You are given two positive integer arrays nums and numsDivide. You can 
    /// delete any number of elements from nums.
    ///
    /// Return the minimum number of deletions such that the smallest element 
    /// in nums divides all the elements of numsDivide. If this is not 
    /// possible, return -1.
    ///
    /// Note that an integer x divides y if y % x == 0.
    /// 
    /// Example 1:
    /// Input: nums = [2,3,2,4,3], numsDivide = [9,6,9,3,15]
    /// Output: 2
    /// Explanation: 
    /// The smallest element in [2,3,2,4,3] is 2, which does not divide all 
    /// the elements of numsDivide.
    /// We use 2 deletions to delete the elements in nums that are equal to 2 
    /// which makes nums = [3,4,3].
    /// The smallest element in [3,4,3] is 3, which divides all the elements 
    /// of numsDivide.
    /// It can be shown that 2 is the minimum number of deletions needed.
    ///
    /// Example 2:
    /// Input: nums = [4,3,6], numsDivide = [8,2,6,10]
    /// Output: -1
    /// Explanation: 
    /// We want the smallest element in nums to divide all the elements of 
    /// numsDivide.
    /// There is no way to delete elements from nums to allow this.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length, numsDivide.length <= 10^5
    /// 2. 1 <= nums[i], numsDivide[i] <= 10^9
    /// </summary>
    int minOperations(vector<int>& nums, vector<int>& numsDivide);

    /// <summary>
    /// Leet Code 2367. Number of Arithmetic Triplets
    ///                                                           
    /// Easy
    ///
    /// You are given a 0-indexed, strictly increasing integer array nums and 
    /// a positive integer diff. A triplet (i, j, k) is an arithmetic triplet 
    /// if the following conditions are met:
    ///
    /// i < j < k,
    /// nums[j] - nums[i] == diff, and
    /// nums[k] - nums[j] == diff.
    /// Return the number of unique arithmetic triplets.
    ///
    /// 
    /// Example 1:
    /// Input: nums = [0,1,4,6,7,10], diff = 3
    /// Output: 2
    /// Explanation:
    /// (1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 
    /// and 4 - 1 == 3.
    /// (2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 
    /// and 7 - 4 == 3. 
    /// Example 2:
    ///
    /// Input: nums = [4,5,6,7,8,9], diff = 2
    /// Output: 2
    /// Explanation:
    /// (0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 
    /// and 6 - 4 == 2.
    /// (1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 
    /// and 7 - 5 == 2.
    ///
    /// Constraints:
    /// 1. 3 <= nums.length <= 200
    /// 2. 0 <= nums[i] <= 200
    /// 3. 1 <= diff <= 50
    /// 4. nums is strictly increasing.
    /// </summary>
    int arithmeticTriplets(vector<int>& nums, int diff);

    /// <summary>
    /// Leet Code 2357. Make Array Zero by Subtracting Equal Amounts
    ///                                                           
    /// Easy
    ///
    /// You are given a non-negative integer array nums. In one operation, 
    /// you must:
    ///
    /// Choose a positive integer x such that x is less than or equal to 
    /// the smallest non-zero element in nums.
    /// Subtract x from every positive element in nums.
    /// Return the minimum number of operations to make every element 
    /// in nums equal to 0.
    ///
    /// Example 1:
    /// Input: nums = [1,5,0,3,5]
    /// Output: 3
    /// Explanation:
    /// In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
    /// In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
    /// In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].
    ///
    /// Example 2:
    /// Input: nums = [0]
    /// Output: 0
    /// Explanation: Each element in nums is already 0 so no operations 
    /// are needed.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 0 <= nums[i] <= 100
    /// </summary>
    int minimumOperations(vector<int>& nums);

    /// <summary>
    /// Leet Code 2358. Maximum Number of Groups Entering a Competition
    ///                                                           
    /// Medium
    ///
    /// You are given a positive integer array grades which represents the 
    /// grades of students in a university. You would like to enter all these 
    /// students into a competition in ordered non-empty groups, such that 
    /// the ordering meets the following conditions:
    ///
    /// The sum of the grades of students in the ith group is less than the 
    /// sum of the grades of students in the (i + 1)th group, for all groups 
    /// (except the last).
    /// The total number of students in the ith group is less than the total 
    /// number of students in the (i + 1)th group, for all groups (except the 
    /// last).
    /// Return the maximum number of groups that can be formed.
    /// 
    /// Example 1:
    ///
    /// Input: grades = [10,6,12,7,3,5]
    /// Output: 3
    /// Explanation: The following is a possible way to form 3 groups of 
    /// students:
    /// - 1st group has the students with grades = [12]. Sum of grades: 12. 
    ///   Student count: 1
    /// - 2nd group has the students with grades = [6,7]. Sum of 
    ///   grades: 6 + 7 = 13. Student count: 2
    /// - 3rd group has the students with grades = [10,3,5]. Sum of 
    ///   grades: 10 + 3 + 5 = 18. Student count: 3
    /// It can be shown that it is not possible to form more than 3 groups.
    ///
    /// Example 2:
    /// Input: grades = [8,8]
    /// Output: 1
    /// Explanation: We can only form 1 group, since forming 2 groups 
    /// would lead to an equal number of students in both groups.
    ///
    /// 
    /// Constraints:
    /// 1. 1 <= grades.length <= 10^5
    /// 2. 1 <= grades[i] <= 10^5
    /// </summary>
    int maximumGroups(vector<int>& grades);

    /// <summary>
    /// Leet Code 2350. Shortest Impossible Sequence of Rolls
    ///                                                  
    /// Hard
    ///
    /// You are given an integer array rolls of length n and an integer k. You 
    /// roll a k sided dice numbered from 1 to k, n times, where the result of 
    /// the ith roll is rolls[i].
    ///
    /// Return the length of the shortest sequence of rolls that cannot be 
    /// taken from rolls.
    ///
    /// A sequence of rolls of length len is the result of rolling a k sided 
    /// dice len times.
    ///
    /// Note that the sequence taken does not have to be consecutive as long 
    /// as it is in order.
    ///  
    /// 
    /// Example 1:
    ///
    /// Input: rolls = [4,2,1,2,3,3,2,4,1], k = 4
    /// Output: 3
    /// Explanation: Every sequence of rolls of length 1, [1], [2], [3], [4], 
    /// can be taken from rolls.
    /// Every sequence of rolls of length 2, [1, 1], [1, 2], ..., [4, 4], can 
    /// be taken from rolls.
    /// The sequence [1, 4, 2] cannot be taken from rolls, so we return 3.
    /// Note that there are other sequences that cannot be taken from rolls.
    ///
    /// Example 2:
    /// 
    /// Input: rolls = [1,1,2,2], k = 2
    /// Output: 2
    /// Explanation: Every sequence of rolls of length 1, [1], [2], can be 
    /// taken from rolls.
    /// The sequence [2, 1] cannot be taken from rolls, so we return 2.
    /// Note that there are other sequences that cannot be taken from rolls 
    /// but [2, 1] is the shortest.
    ///
    /// Example 3:
    /// 
    /// Input: rolls = [1,1,3,2,2,2,3,3], k = 4
    /// Output: 1
    /// Explanation: The sequence [4] cannot be taken from rolls, so we 
    /// return 1.
    /// Note that there are other sequences that cannot be taken from rolls 
    /// but [4] is the shortest.
    /// 
    /// Constraints:
    /// 1. n == rolls.length
    /// 2. 1 <= n <= 105
    /// 3. 1 <= rolls[i] <= k <= 105
    /// </summary>
    int shortestSequence(vector<int>& rolls, int k);

    /// <summary>
     /// Leet Code 2376. Count Special Integers
     /// </summary>
    int countSpecialNumbers(int lower, int upper, int digits, unordered_set<int>& visited);

    /// <summary>
    /// Leet Code 2376. Count Special Integers
    ///                                                  
    /// Hard
    ///
    /// We call a positive integer special if all of its digits are distinct.
    /// Given a positive integer n, return the number of special integers that 
    /// belong to the interval [1, n].
    ///
    /// Example 1:
    /// Input: n = 20
    /// Output: 19
    /// Explanation: All the integers from 1 to 20, except 11, are special. 
    /// Thus, there are 19 special integers.
    ///
    /// Example 2:
    /// Input: n = 5
    /// Output: 5
    /// Explanation: All the integers from 1 to 5 are special.
    /// Example 3:
    ///
    /// Input: n = 135
    /// Output: 110
    /// Explanation: There are 110 integers from 1 to 135 that are special.
    /// Some of the integers that are not special are: 22, 114, and 131.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 2 * 10^9
    /// </summary>
    int countSpecialNumbers(int n);

    /// <summary>
    /// Leet Code 2384. Largest Palindromic Number
    ///                                                  
    /// Medium
    ///
    /// You are given a string num consisting of digits only.
    ///
    /// Return the largest palindromic integer (in the form of a string) that 
    /// can be formed using digits taken from num. It should not contain 
    /// leading zeroes.
    ///
    /// Notes:
    /// 
    /// You do not need to use all the digits of num, but you must use at 
    /// least one digit.
    /// The digits can be reordered.
    /// 
    /// Example 1:
    /// Input: num = "444947137"
    /// Output: "7449447"
    /// Explanation: 
    /// Use the digits "4449477" from "444947137" to form the palindromic 
    /// integer "7449447".
    /// It can be shown that "7449447" is the largest palindromic integer 
    /// that can be formed.
    ///
    /// Example 2:
    /// Input: num = "00009"
    /// Output: "9"
    /// Explanation: 
    /// It can be shown that "9" is the largest palindromic integer 
    /// that can be formed.
    /// Note that the integer returned should not contain leading 
    /// zeroes.
    /// 
    /// Constraints:
    /// 1. 1 <= num.length <= 10^5
    /// 2. num consists of digits.
    /// </summary>
    string largestPalindromic(string num);

    /// <summary>
    /// Leet Code 2375. Construct Smallest Number From DI String
    ///                                                  
    /// Medium
    ///
    /// You are given a 0-indexed string pattern of length n consisting of the 
    /// characters 'I' meaning increasing and 'D' meaning decreasing.
    ///
    /// A 0-indexed string num of length n + 1 is created using the following 
    /// conditions:
    ///
    /// num consists of the digits '1' to '9', where each digit is used at 
    /// most once.
    /// If pattern[i] == 'I', then num[i] < num[i + 1].
    /// If pattern[i] == 'D', then num[i] > num[i + 1].
    /// Return the lexicographically smallest possible string num that meets 
    /// the conditions.
    ///
    /// Example 1:
    /// Input: pattern = "IIIDIDDD"
    /// Output: "123549876"
    /// Explanation:
    /// At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
    /// At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
    /// Some possible values of num are "245639871", "135749862", 
    /// and "123849765".
    /// It can be proven that "123549876" is the smallest possible num that 
    /// meets the conditions.
    /// Note that "123414321" is not possible because the digit '1' is 
    /// used more than once.
    ///
    /// Example 2:
    /// Input: pattern = "DDD"
    /// Output: "4321"
    /// Explanation:
    /// Some possible values of num are "9876", "7321", and "8742".
    /// It can be proven that "4321" is the smallest possible num that meets 
    /// the conditions.
    /// 
    /// Constraints:
    /// 1. 1 <= pattern.length <= 8
    /// 2. pattern consists of only the letters 'I' and 'D'.
    /// </summary>
    string smallestNumber(string pattern);

    /// <summary>
    /// Leet Code 2404. Most Frequent Even Element
    ///                                                  
    /// Easy
    ///
    /// Given an integer array nums, return the most frequent even element.
    /// 
    /// If there is a tie, return the smallest one. If there is no such 
    /// element, return -1.
    /// 
    /// Example 1:
    ///
    /// Input: nums = [0,1,2,2,4,4,1]
    /// Output: 2
    /// Explanation:
    /// The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
    /// We return the smallest one, which is 2.
    ///
    /// Example 2:
    ///
    /// Input: nums = [4,4,4,9,2,4]
    /// Output: 4
    /// Explanation: 4 is the even element appears the most.
    ///
    /// Example 3:
    ///
    /// Input: nums = [29,47,21,41,13,37,25,7]
    /// Output: -1
    /// Explanation: There is no even element.
    /// 
    /// Constraints:
    ///
    /// 1. 1 <= nums.length <= 2000
    /// 2. 0 <= nums[i] <= 10^5
    /// </summary>
    int mostFrequentEven(vector<int>& nums);

    /// <summary>
    /// Leet Code 2396. Strictly Palindromic Number
    ///                                                  
    /// Medium
    ///
    /// An integer n is strictly palindromic if, for every base b between 2 
    /// and n - 2 (inclusive), the string representation of the integer n 
    /// in base b is palindromic.
    ///
    /// Given an integer n, return true if n is strictly palindromic and 
    /// false otherwise.
    ///
    /// A string is palindromic if it reads the same forward and backward.
    /// Example 1:
    /// Input: n = 9
    /// Output: false
    /// Explanation: In base 2: 9 = 1001 (base 2), which is palindromic.
    /// In base 3: 9 = 100 (base 3), which is not palindromic.
    /// Therefore, 9 is not strictly palindromic so we return false.
    /// Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.
    ///
    /// Example 2:
    /// 
    /// Input: n = 4
    /// Output: false
    /// Explanation: We only consider base 2: 4 = 100 (base 2), which 
    /// is not palindromic.
    /// Therefore, we return false.
    ///
    /// Constraints:
    /// 1. 4 <= n <= 10^5
    /// </summary>
    bool isStrictlyPalindromic(int n);

    /// <summary>
    /// Leet Code 2417. Closest Fair Integer
    ///                                                  
    /// Medium
    ///
    /// You are given a positive integer n.
    ///
    /// We call an integer k fair if the number of even digits in k is equal 
    /// to the number of odd digits in it.
    ///
    /// Return the smallest fair integer that is greater than or equal to n.
    ///
    /// Example 1:
    /// Input: n = 2
    /// Output: 10
    /// Explanation: The smallest fair integer that is greater than or 
    /// equal to 2 is 10.
    /// 10 is fair because it has an equal number of even and odd digits 
    /// (one odd digit and one even digit).
    ///
    /// Example 2:
    /// Input: n = 403
    /// Output: 1001
    /// Explanation: The smallest fair integer that is greater than or 
    /// equal to 403 is 1001.
    /// 1001 is fair because it has an equal number of even and odd digits 
    /// (two odd digits and two even digits).
    /// 
    /// Constraints:
    /// 1 <= n <= 10^9
    /// </summary>
    int closestFair(int n);

    /// <summary>
    /// Leet Code 2409. Count Days Spent Together
    ///                                                  
    /// Easy
    ///
    /// Alice and Bob are traveling to Rome for separate business meetings.
    ///
    /// You are given 4 strings arriveAlice, leaveAlice, arriveBob, and 
    /// leaveBob. Alice will be in the city from the dates arriveAlice to 
    /// leaveAlice (inclusive), while Bob will be in the city from the dates 
    /// arriveBob to leaveBob (inclusive). Each will be a 5-character string 
    /// in the format "MM-DD", corresponding to the month and day of the date.
    ///
    /// Return the total number of days that Alice and Bob are in Rome 
    /// together.
    ///
    /// You can assume that all dates occur in the same calendar year, which 
    /// is not a leap year. Note that the number of days per month can be 
    /// represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].
    /// 
    /// Example 1:
    /// Input: arriveAlice = "08-15", leaveAlice = "08-18", 
    /// arriveBob = "08-16", leaveBob = "08-19"
    /// Output: 3
    /// Explanation: Alice will be in Rome from August 15 to August 18. Bob 
    /// will be in Rome from August 16 to August 19. They are both in Rome 
    /// together on August 16th, 17th, and 18th, so the answer is 3.
    ///
    /// Example 2:
    /// Input: arriveAlice = "10-01", leaveAlice = "10-31", 
    /// arriveBob = "11-01", leaveBob = "12-31"
    /// Output: 0
    /// Explanation: There is no day when Alice and Bob are in Rome together, 
    /// so we return 0.
    ///
    /// Constraints:
    /// 1. All dates are provided in the format "MM-DD".
    /// 2. Alice and Bob's arrival dates are earlier than or equal to their 
    ///    leaving dates.
    /// 3. The given dates are valid dates of a non-leap year.
    /// </summary>
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob); 

    /// <summary>
    /// Leet Code 2413. Smallest Even Multiple
    ///                                                  
    /// Easy
    ///
    /// Given a positive integer n, return the smallest positive integer 
    /// that is a multiple of both 2 and n.
    ///
    /// Example 1:
    /// Input: n = 5
    /// Output: 10
    /// Explanation: The smallest multiple of both 5 and 2 is 10.
    ///
    /// Example 2:
    /// Input: n = 6
    /// Output: 6
    /// Explanation: The smallest multiple of both 6 and 2 is 6. Note that 
    /// a number is a multiple of itself.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 150
    /// </summary>
    int smallestEvenMultiple(int n);

    /// <summary>
    /// Leet Code 2427. Number of Common Factors
    ///                                                  
    /// Easy
    ///
    /// Given two positive integers a and b, return the number of common 
    /// factors of a and b.
    ///
    /// An integer x is a common factor of a and b if x divides both a and b.
    /// 
    /// Example 1:
    /// Input: a = 12, b = 6
    /// Output: 4
    /// Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.
    ///
    /// Example 2:
    /// Input: a = 25, b = 30
    /// Output: 2
    /// Explanation: The common factors of 25 and 30 are 1, 5.
    /// 
    /// Constraints:
    /// 1. 1 <= a, b <= 1000
    /// </summary>
    int commonFactors(int a, int b);

    /// <summary>
    /// Leet Code 2436. Minimum Split Into Subarrays With GCD Greater Than One            
    ///                                                  
    /// Medium
    ///
    /// You are given an array nums consisting of positive integers.
    ///
    /// Split the array into one or more disjoint subarrays such that:
    ///
    /// Each element of the array belongs to exactly one subarray, and
    /// The GCD of the elements of each subarray is strictly greater than 1.
    /// Return the minimum number of subarrays that can be obtained after 
    /// the split.
    ///
    /// Note that:
    /// The GCD of a subarray is the largest positive integer that evenly 
    /// divides all the elements of the subarray.
    /// A subarray is a contiguous part of the array.
    /// 
    /// Example 1:
    /// Input: nums = [12,6,3,14,8]
    /// Output: 2
    /// Explanation: We can split the array into the 
    /// subarrays: [12,6,3] and [14,8].
    /// - The GCD of 12, 6 and 3 is 3, which is strictly greater than 1.
    /// - The GCD of 14 and 8 is 2, which is strictly greater than 1.
    /// It can be shown that splitting the array into one subarray will make 
    /// the GCD = 1.
    ///
    /// Example 2:
    /// Input: nums = [4,12,6,14]
    /// Output: 1
    /// Explanation: We can split the array into only one subarray, which 
    /// is the whole array.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 2000
    /// 2. 2 <= nums[i] <= 10^9
    /// </summary>
    int minimumSplits(vector<int>& nums);

    /// <summary>
    /// Leet Code 2437. Number of Valid Clock Times           
    ///                                                  
    /// Easy
    ///
    /// You are given a string of length 5 called time, representing the 
    /// current time on a digital clock in the format "hh:mm". The earliest 
    /// possible time is "00:00" and the latest possible time is "23:59".
    ///
    /// In the string time, the digits represented by the ? symbol are 
    /// unknown, and must be replaced with a digit from 0 to 9.
    ///
    /// Return an integer answer, the number of valid clock times that can 
    /// be created by replacing every ? with a digit from 0 to 9.
    ///
    /// Example 1:
    /// Input: time = "?5:00"
    /// Output: 2
    /// Explanation: We can replace the ? with either a 0 or 1, producing 
    /// "05:00" or "15:00". Note that we cannot replace it with a 2, since 
    /// the time "25:00" is invalid. In total, we have two choices.
    ///
    /// Example 2:
    /// Input: time = "0?:0?"
    /// Output: 100
    /// Explanation: Each ? can be replaced by any digit from 0 to 9, so 
    /// we have 100 total choices.
    ///
    /// Example 3:
    /// Input: time = "??:??"
    /// Output: 1440
    /// Explanation: There are 24 possible choices for the hours, and 60 
    /// possible choices for the minutes. In total, we have 24 * 60 = 1440 
    /// choices.
    ///
    ///
    /// Constraints:
    /// 1. time is a valid string of length 5 in the format "hh:mm".
    /// 2. "00" <= hh <= "23"
    /// 3. "00" <= mm <= "59"
    /// 4. Some of the digits might be replaced with '?' and need to be 
    ///    replaced with digits from 0 to 9.
    /// </summary>
    int countTime(string time);


    /// <summary>
    /// Leet Code 2438. Range Product Queries of Powers      
    ///                                                  
    /// Medium
    ///
    /// Given a positive integer n, there exists a 0-indexed array called 
    /// powers, composed of the minimum number of powers of 2 that sum to n. 
    /// The array is sorted in non-decreasing order, and there is only one 
    /// way to form the array.
    ///
    /// You are also given a 0-indexed 2D integer array queries, where 
    /// queries[i] = [lefti, righti]. Each queries[i] represents a query 
    /// where you have to find the product of all powers[j] with 
    /// lefti <= j <= righti.
    ///
    /// Return an array answers, equal in length to queries, where answers[i] 
    /// is the answer to the ith query. Since the answer to the ith query may 
    /// be too large, each answers[i] should be returned modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: n = 15, queries = [[0,1],[2,2],[0,3]]
    /// Output: [2,4,64]
    /// Explanation:
    /// For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be 
    /// a smaller size.
    /// Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
    /// Answer to 2nd query: powers[2] = 4.
    /// Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] 
    /// = 1 * 2 * 4 * 8 = 64.
    /// Each answer modulo 109 + 7 yields the same answer, so [2,4,64] is 
    /// returned.
    ///
    /// Example 2:
    /// Input: n = 2, queries = [[0,0]]
    /// Output: [2]
    /// Explanation:
    /// For n = 2, powers = [2].
    /// The answer to the only query is powers[0] = 2. The answer 
    /// modulo 10^9 + 7 is the same, so [2] is returned.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^9
    /// 2. 1 <= queries.length <= 10^5
    /// 3. 0 <= starti <= endi < powers.length
    /// </summary>
    vector<int> productQueries(int n, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2443. Sum of Number and Its Reverse      
    ///                                                  
    /// Medium
    ///
    /// Given a non-negative integer num, return true if num can be expressed 
    /// as the sum of any non-negative integer and its reverse, or false 
    /// otherwise.
    /// 
    /// Example 1:
    /// Input: num = 443
    /// Output: true
    /// Explanation: 172 + 271 = 443 so we return true.
    ///
    /// Example 2:
    /// Input: num = 63
    /// Output: false
    /// Explanation: 63 cannot be expressed as the sum of a non-negative 
    /// integer and its reverse so we return false.
    ///
    /// Example 3:
    ///
    /// Input: num = 181
    /// Output: true
    /// Explanation: 140 + 041 = 181 so we return true. Note that when a 
    /// number is reversed, there may be leading zeros.
    /// 
    /// Constraints:
    /// 1. 0 <= num <= 10^5
    /// </summary>
    bool sumOfNumberAndReverse(int num);

    /// <summary>
    /// Leet Code 2446. Determine if Two Events Have Conflict     
    ///                                                  
    /// Easy
    ///
    /// You are given two arrays of strings that represent two inclusive 
    /// events that happened on the same day, event1 and event2, where:
    ///
    /// event1 = [startTime1, endTime1] and
    /// event2 = [startTime2, endTime2].
    /// Event times are valid 24 hours format in the form of HH:MM.
    ///
    /// A conflict happens when two events have some non-empty intersection 
    /// (i.e., some moment is common to both events).
    ///
    /// Return true if there is a conflict between two events. Otherwise, 
    /// return false.
    ///  
    /// Example 1:
    /// Input: event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
    /// Output: true
    /// Explanation: The two events intersect at time 2:00.
    ///
    /// Example 2:
    /// Input: event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
    /// Output: true
    /// Explanation: The two events intersect starting from 01:20 to 02:00.
    ///
    /// Example 3:
    /// Input: event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
    /// Output: false
    /// Explanation: The two events do not intersect.
    /// 
    /// Constraints:
    /// 1. evnet1.length == event2.length == 2.
    /// 2. event1[i].length == event2[i].length == 5
    /// 3. startTime1 <= endTime1
    /// 3. startTime2 <= endTime2
    /// 4. All the event times follow the HH:MM format.
    /// </summary>
    bool haveConflict(vector<string>& event1, vector<string>& event2);

    /// <summary>
    /// Leet Code 2447. Number of Subarrays With GCD Equal to K    
    ///                                                  
    /// Medium
    ///
    /// Given an integer array nums and an integer k, return the number of 
    /// subarrays of nums where the greatest common divisor of the subarray's 
    /// elements is k.
    ///
    /// A subarray is a contiguous non-empty sequence of elements within an 
    /// array.
    ///
    /// The greatest common divisor of an array is the largest integer that 
    /// evenly divides all the array elements.
    ///
    /// Example 1:
    /// Input: nums = [9,3,1,2,6,3], k = 3
    /// Output: 4
    /// Explanation: The subarrays of nums where 3 is the greatest common 
    /// divisor of all the subarray's elements are:
    /// - [9,3,1,2,6,3]
    /// - [9,3,1,2,6,3]
    /// - [9,3,1,2,6,3]
    /// - [9,3,1,2,6,3]
    ///
    /// Example 2:
    /// Input: nums = [4], k = 7
    /// Output: 0
    /// Explanation: There are no subarrays of nums where 7 is the greatest 
    /// common divisor of all the subarray's elements.
    ///  
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i], k <= 10^9
    /// </summary>
    int subarrayGCD(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2455. Average Value of Even Numbers That Are Divisible by 
    ///                 Three 
    ///                                                  
    /// Easy
    ///
    /// Given an integer array nums of positive integers, return the average 
    /// value of all even integers that are divisible by 3.
    ///
    /// Note that the average of n elements is the sum of the n elements 
    /// divided by n and rounded down to the nearest integer.
    ///
    /// Example 1:
    /// Input: nums = [1,3,6,10,12,15]
    /// Output: 9
    /// Explanation: 6 and 12 are even numbers that are divisible by 3. 
    /// (6 + 12) / 2 = 9.
    /// Example 2:
    ///
    /// Input: nums = [1,2,4,7,10]
    /// Output: 0
    /// Explanation: There is no single number that satisfies the 
    /// requirement, so return 0.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 1000
    /// </summary>
    int averageValue(vector<int>& nums);

    /// <summary>
    /// Leet Code 2453. Destroy Sequential Targets 
    ///                                                  
    /// Medium
    ///
    /// You are given a 0-indexed array nums consisting of positive integers, 
    /// representing targets on a number line. You are also given an integer 
    /// space.
    ///
    /// You have a machine which can destroy targets. Seeding the machine with 
    /// some nums[i] allows it to destroy all targets with values that can be 
    /// represented as nums[i] + c * space, where c is any non-negative 
    /// integer. You want to destroy the maximum number of targets in nums.
    ///
    /// Return the minimum value of nums[i] you can seed the machine with to 
    /// destroy the maximum number of targets.
    ///
    /// Example 1:
    /// Input: nums = [3,7,8,1,1,5], space = 2 
    /// Output: 1
    /// Explanation: If we seed the machine with nums[3], then we destroy all 
    /// targets equal to 1,3,5,7,9,... 
    /// In this case, we would destroy 5 total targets (all except for 
    /// nums[2]). 
    /// It is impossible to destroy more than 5 targets, so we return nums[3].
    ///
    /// Example 2:
    /// Input: nums = [1,3,5,2,4,6], space = 2
    /// Output: 1
    /// Explanation: Seeding the machine with nums[0], or nums[3] destroys 3 
    /// targets. 
    /// It is not possible to destroy more than 3 targets.
    /// Since nums[0] is the minimal integer that can destroy 3 targets, we 
    /// return 1.
    ///
    /// Example 3:
    /// Input: nums = [6,2,5], space = 100
    /// Output: 2
    /// Explanation: Whatever initial seed we select, we can only destroy 1 
    /// target. The minimal seed is nums[1].
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^9
    /// 3. 1 <= space <= 10^9
    /// </summary>
    int destroyTargets(vector<int>& nums, int space);

    /// <summary>
    /// Leet Code 2457. Minimum Addition to Make Integer Beautiful 
    ///                                                  
    /// Medium
    ///
    /// You are given two positive integers n and target.
    ///
    /// An integer is considered beautiful if the sum of its digits is 
    /// less than or equal to target.
    ///
    /// Return the minimum non-negative integer x such that n + x is 
    /// beautiful. The input will be generated such that it is always 
    /// possible to make n beautiful.
    ///
    /// Example 1:
    /// Input: n = 16, target = 6
    /// Output: 4
    /// Explanation: Initially n is 16 and its digit sum is 1 + 6 = 7. 
    /// After adding 4, n becomes 20 and digit sum becomes 2 + 0 = 2. 
    /// It can be shown that we can not make n beautiful with adding 
    /// non-negative integer less than 4.
    ///
    /// Example 2:
    /// Input: n = 467, target = 6
    /// Output: 33
    /// Explanation: Initially n is 467 and its digit sum is 4 + 6 + 7 = 17. 
    /// After adding 33, n becomes 500 and digit sum becomes 5 + 0 + 0 = 5. 
    /// It can be shown that we can not make n beautiful with adding 
    /// non-negative integer less than 33.
    ///
    /// Example 3:
    /// Input: n = 1, target = 1
    /// Output: 0
    /// Explanation: Initially n is 1 and its digit sum is 1, which is already 
    /// smaller than or equal to target.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^12
    /// 2. 1 <= target <= 150
    /// 3. The input will be generated such that it is always possible to 
    ///    make n beautiful.
    /// </summary>
    long long makeIntegerBeautiful(long long n, int target);

    /// <summary>
    /// Leet Code 2450. Number of Distinct Binary Strings After Applying 
    ///                 Operations 
    ///                                                  
    /// Medium
    ///
    /// You are given a binary string s and a positive integer k.
    ///
    /// You can apply the following operation on the string any number of 
    /// times:
    ///
    /// Choose any substring of size k from s and flip all its characters, 
    /// that is, turn all 1's into 0's, and all 0's into 1's.
    /// Return the number of distinct strings you can obtain. Since the 
    /// answer may be too large, return it modulo 10^9 + 7.
    ///
    /// Note that:
    ///
    /// A binary string is a string that consists only of the 
    /// characters 0 and 1.
    /// A substring is a contiguous part of a string.
    /// 
    /// Example 1:
    /// Input: s = "1001", k = 3
    /// Output: 4
    /// Explanation: We can obtain the following strings:
    /// - Applying no operation on the string gives s = "1001".
    /// - Applying one operation on the substring starting at index 0 
    ///   gives s = "0111".
    /// - Applying one operation on the substring starting at index 1 
    ///   gives s = "1110".
    /// - Applying one operation on both the substrings starting at indices 0 
    ///   and 1 gives s = "0000".
    /// It can be shown that we cannot obtain any other string, so the 
    /// answer is 4.
    ///
    /// Example 2:
    /// Input: s = "10110", k = 5
    /// Output: 2
    /// Explanation: We can obtain the following strings:
    /// - Applying no operation on the string gives s = "10110".
    /// - Applying one operation on the whole string gives s = "01001".
    /// It can be shown that we cannot obtain any other string, so the 
    /// answer is 2.
    ///
    /// 
    /// Constraints:
    /// 1. 1 <= k <= s.length <= 10^5
    /// 2. s[i] is either 0 or 1.
    /// </summary>
    int countDistinctStrings(string s, int k);

    /// <summary>
    /// Leet Code 2469. Convert the Temperature
    /// 
    /// Easy
    ///	
    /// You are given a non-negative floating point number rounded to two 
    /// decimal places celsius, that denotes the temperature in Celsius.
    ///
    /// You should convert Celsius into Kelvin and Fahrenheit and return 
    /// it as an array ans = [kelvin, fahrenheit].
    /// 
    /// Return the array ans. Answers within 10-5 of the actual answer will 
    /// be accepted.
    ///
    /// Note that:
    ///
    /// Kelvin = Celsius + 273.15
    /// Fahrenheit = Celsius * 1.80 + 32.00
    ///
    /// Example 1: 
    /// Input: celsius = 36.50
    /// Output: [309.65000,97.70000]
    /// Explanation: Temperature at 36.50 Celsius converted in Kelvin is 
    /// 309.65 and converted in Fahrenheit is 97.70. 
    ///
    /// Example 2:
    /// Input: celsius = 122.11
    /// Output: [395.26000,251.79800]
    /// Explanation: Temperature at 122.11 Celsius converted in Kelvin 
    /// is 395.26 and converted in Fahrenheit is 251.798.
    ///
    /// Constraints:
    /// 1. 0 <= celsius <= 1000
    /// </summary>
    vector<double> convertTemperature(double celsius);

    /// <summary>
    /// Leet Code 2481. Minimum Cuts to Divide a Circle
    /// 
    /// Easy
    ///	
    /// A valid cut in a circle can be:
    ///
    /// A cut that is represented by a straight line that touches two points 
    /// on the edge of the circle and passes through its center, or
    /// A cut that is represented by a straight line that touches one 
    /// point on the edge of the circle and its center.
    /// Some valid and invalid cuts are shown in the figures below.
    ///
    /// Given the integer n, return the minimum number of cuts needed to 
    /// divide a circle into n equal slices.
    ///
    /// Example 1:
    /// Input: n = 4
    /// Output: 2
    /// Explanation: 
    /// The above figure shows how cutting the circle twice through the 
    /// middle divides it into 4 equal slices.
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: 3
    /// Explanation:
    /// At least 3 cuts are needed to divide the circle into 3 equal slices. 
    /// It can be shown that less than 3 cuts cannot result in 3 slices of 
    /// equal size and shape.
    /// Also note that the first cut will not divide the circle into distinct 
    /// parts.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// </summary>
    int numberOfCuts(int n);

    /// <summary>
    /// Leet Code 2485. Find the Pivot Integer
    /// 
    /// Easy
    ///	
    /// Given a positive integer n, find the pivot integer x such that:
    ///  
    /// The sum of all elements between 1 and x inclusively equals the sum 
    /// of all elements between x and n inclusively.
    /// Return the pivot integer x. If no such integer exists, return -1. 
    /// It is guaranteed that there will be at most one pivot index for the 
    /// given input.
    ///
    /// Example 1:
    /// Input: n = 8
    /// Output: 6
    /// Explanation: 6 is the pivot integer since: 
    /// 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
    ///
    /// Example 2:
    /// Input: n = 1
    /// Output: 1
    /// Explanation: 1 is the pivot integer since: 1 = 1.
    ///
    /// Example 3:
    /// Input: n = 4
    /// Output: -1
    /// Explanation: It can be proved that no such integer exist.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// </summary>
    int pivotInteger(int n);

    /// <summary>
    /// Leet Code 2507. Smallest Value After Replacing With Sum of Prime 
    ///                 Factors
    /// 
    /// Medium
    ///	
    /// You are given a positive integer n.
    ///
    /// Continuously replace n with the sum of its prime factors.
    ///
    /// Note that if a prime factor divides n multiple times, it should 
    /// be included in the sum as many times as it divides n.
    /// Return the smallest value n will take on.
    ///
    /// Example 1:
    ///
    /// Input: n = 15
    /// Output: 5
    /// Explanation: Initially, n = 15.
    /// 15 = 3 * 5, so replace n with 3 + 5 = 8.
    /// 8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
    /// 6 = 2 * 3, so replace n with 2 + 3 = 5.
    /// 5 is the smallest value n will take on.
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: 3
    /// Explanation: Initially, n = 3.
    /// 3 is the smallest value n will take on.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// </summary>
    int smallestValue(int n);

    /// <summary>
    /// Leet Code 2514. Count Anagrams
    /// </summary>
    long long factorial(long long n, long long M);

    /// <summary>
    /// Leet Code 2514. Count Anagrams
    /// 
    /// Hard
    ///	
    /// You are given a string s containing one or more words. Every 
    /// consecutive pair of words is separated by a single space ' '.
    ///
    /// A string t is an anagram of string s if the ith word of t is a 
    /// permutation of the ith word of s.
    ///
    /// For example, "acb dfe" is an anagram of "abc def", but "def cab" 
    /// and "adc bef" are not.
    /// Return the number of distinct anagrams of s. Since the answer may 
    /// be very large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: s = "too hot"
    /// Output: 18
    /// Explanation: Some of the anagrams of the given string are "too hot", 
    /// "oot hot", "oto toh", "too toh", and "too oht".
    ///
    /// Example 2:
    /// Input: s = "aa"
    /// Output: 1
    /// Explanation: There is only one anagram possible for the given string.
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5
    /// 2. s consists of lowercase English letters and spaces ' '.
    /// 3. There is single space between consecutive words.
    /// </summary>
    int countAnagrams(string s);

    /// <summary>
    /// Leet Code 2338. Count the Number of Ideal Arrays
    ///                                                           
    /// Hard
    ///
    /// You are given two integers n and maxValue, which are used to describe 
    /// an ideal array.
    ///
    /// A 0-indexed integer array arr of length n is considered ideal if the 
    /// following conditions hold:
    ///
    /// Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
    /// Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
    /// Return the number of distinct ideal arrays of length n. Since the 
    /// answer may be very large, return it modulo 10^9 + 7.
    /// 
    /// Example 1:
    /// Input: n = 2, maxValue = 5
    /// Output: 10
    /// Explanation: The following are the possible ideal arrays:
    /// - Arrays starting with the value 1 (5 arrays): 
    ///   [1,1], [1,2], [1,3], [1,4], [1,5]
    /// - Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
    /// - Arrays starting with the value 3 (1 array): [3,3]
    /// - Arrays starting with the value 4 (1 array): [4,4]
    /// - Arrays starting with the value 5 (1 array): [5,5]
    /// There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
    ///
    /// Example 2:
    /// Input: n = 5, maxValue = 3
    /// Output: 11
    /// Explanation: The following are the possible ideal arrays:
    /// - Arrays starting with the value 1 (9 arrays): 
    /// - With no other distinct values (1 array): [1,1,1,1,1] 
    /// - With 2nd distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], 
    ///   [1,1,2,2,2], [1,2,2,2,2]
    /// - With 2nd distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], 
    ///   [1,1,3,3,3], [1,3,3,3,3]
    /// - Arrays starting with the value 2 (1 array): [2,2,2,2,2]
    /// - Arrays starting with the value 3 (1 array): [3,3,3,3,3]
    /// There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.
    ///
    /// Constraints:
    /// 2 <= n <= 10^4
    /// 3. 1 <= maxValue <= 10^4
    /// </summary>
    int idealArrays(int n, int maxValue);

    /// <summary>
    /// Leet Code 2523. Closest Prime Numbers in Range
    /// 
    /// Medium
    ///	
    /// Given two positive integers left and right, find the two integers num1 
    /// and num2 such that:
    ///
    /// left <= nums1 < nums2 <= right .
    /// nums1 and nums2 are both prime numbers.
    /// nums2 - nums1 is the minimum amongst all other pairs satisfying the 
    /// above conditions.
    /// Return the positive integer array ans = [nums1, nums2]. If there are 
    /// multiple pairs satisfying these conditions, return the one with the 
    /// minimum nums1 value or [-1, -1] if such numbers do not exist.
    ///
    /// A number greater than 1 is called prime if it is only divisible by 1 
    /// and itself.
    ///
    /// Example 1:
    ///
    /// Input: left = 10, right = 19
    /// Output: [11,13]
    /// Explanation: The prime numbers between 10 and 19 are 11, 13, 17, 
    /// and 19.
    /// The closest gap between any pair is 2, which can be achieved by 
    /// [11,13] or [17,19].
    /// Since 11 is smaller than 17, we return the first pair.
    ///
    /// Example 2:
    /// Input: left = 4, right = 6
    /// Output: [-1,-1]
    /// Explanation: There exists only one prime number in the given range, 
    /// so the conditions cannot be satisfied.
    /// 
    /// Constraints:
    /// 1. 1 <= left <= right <= 10^6
    /// </summary>
    vector<int> closestPrimes(int left, int right);

    /// <summary>
    /// Leet Code 2520. Count the Digits That Divide a Number
    /// 
    /// Easy
    ///	
    /// Given an integer num, return the number of digits in num that divide 
    /// num.
    ///
    /// An integer val divides nums if nums % val == 0.
    ///
    /// Example 1:
    /// Input: num = 7
    /// Output: 1
    /// Explanation: 7 divides itself, hence the answer is 1.
    ///
    /// Example 2:
    /// Input: num = 121
    /// Output: 2
    /// Explanation: 121 is divisible by 1, but not 2. Since 1 occurs twice 
    /// as a digit, we return 2.
    ///
    /// Example 3:
    /// Input: num = 1248
    /// Output: 4
    /// Explanation: 1248 is divisible by all of its digits, hence the 
    /// answer is 4.
    /// 
    /// Constraints:
    /// 1. 1 <= num <= 10^9
    /// 2. num does not contain 0 as one of its digits.
    /// </summary>
    int countDigits(int num);

    /// <summary>
    /// Leet Code 2521. Distinct Prime Factors of Product of Array
    /// 
    /// Medium
    ///	
    /// Given an array of positive integers nums, return the number of 
    /// distinct prime factors in the product of the elements of nums.
    ///
    /// Note that:
    ///
    /// A number greater than 1 is called prime if it is divisible by 
    /// only 1 and itself.
    /// An integer val1 is a factor of another integer val2 if 
    /// val2 / val1 is an integer.
    ///
    /// Example 1:
    /// Input: nums = [2,4,3,7,10,6]
    /// Output: 4
    /// Explanation:
    /// The product of all the elements in nums is: 
    /// 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
    /// There are 4 distinct prime factors so we return 4.
    ///
    /// Example 2:
    /// Input: nums = [2,4,8,16]
    /// Output: 1
    /// Explanation:
    /// The product of all the elements in nums is: 
    /// 2 * 4 * 8 * 16 = 1024 = 210.
    /// There is 1 distinct prime factor so we return 1.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^4
    /// 2. 2 <= nums[i] <= 1000
    /// </summary>
    int distinctPrimeFactors(vector<int>& nums);

    /// <summary>
    /// Leet Code 2525. Categorize Box According to Criteria
    /// 
    /// Easy
    ///	
    /// Given four integers length, width, height, and mass, representing 
    /// the dimensions and mass of a box, respectively, return a string 
    /// representing the category of the box.
    ///
    /// The box is "Bulky" if:
    /// Any of the dimensions of the box is greater or equal to 10^4.
    /// Or, the volume of the box is greater or equal to 10^9.
    /// If the mass of the box is greater or equal to 100, it is "Heavy".
    /// If the box is both "Bulky" and "Heavy", then its category is "Both".
    /// If the box is neither "Bulky" nor "Heavy", then its category is 
    /// "Neither".
    /// If the box is "Bulky" but not "Heavy", then its category is "Bulky".
    /// If the box is "Heavy" but not "Bulky", then its category is "Heavy".
    /// Note that the volume of the box is the product of its length, width 
    /// and height.
    ///
    /// Example 1:
    /// Input: length = 1000, width = 35, height = 700, mass = 300
    /// Output: "Heavy"
    /// Explanation: 
    /// None of the dimensions of the box is greater or equal to 10^4. 
    /// Its volume = 24500000 <= 10^9. So it cannot be categorized as "Bulky". 
    /// However mass >= 100, so the box is "Heavy".
    /// Since the box is not "Bulky" but "Heavy", we return "Heavy".
    ///
    /// Example 2:
    /// Input: length = 200, width = 50, height = 800, mass = 50
    /// Output: "Neither"
    /// Explanation: 
    /// None of the dimensions of the box is greater or equal to 10^4.
    /// Its volume = 8 * 106 <= 109. So it cannot be categorized as "Bulky".
    /// Its mass is also less than 100, so it cannot be categorized as 
    /// "Heavy" either. 
    /// Since its neither of the two above categories, we return "Neither".
    ///
    /// Constraints:
    /// 1 <= length, width, height <= 10^5
    /// 2. 1 <= mass <= 10^3
    /// </summary>
    string categorizeBox(int length, int width, int height, int mass);

    /// <summary>
    /// Leet Code 2529. Maximum Count of Positive Integer and Negative Integer
    /// 
    /// Easy
    ///	
    /// Given an array nums sorted in non-decreasing order, return the maximum 
    /// between the number of positive integers and the number of negative 
    /// integers. 
    ///
    /// In other words, if the number of positive integers in nums is pos and 
    /// the number of negative integers is neg, then return the maximum of pos 
    /// and neg.
    /// Note that 0 is neither positive nor negative.
    /// 
    /// Example 1:
    /// Input: nums = [-2,-1,-1,1,2,3]
    /// Output: 3
    /// Explanation: There are 3 positive integers and 3 negative integers. 
    /// The maximum count among them is 3.
    ///
    /// Example 2:
    /// Input: nums = [-3,-2,-1,0,0,1,2]
    /// Output: 3
    /// Explanation: There are 2 positive integers and 3 negative integers. 
    /// The maximum count among them is 3.
    ///
    /// Example 3:
    /// Input: nums = [5,20,66,1314]
    /// Output: 4
    /// Explanation: There are 4 positive integers and 0 negative integers. 
    /// The maximum count among them is 4.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length <= 2000
    /// 2. -2000 <= nums[i] <= 2000
    /// 3. nums is sorted in a non-decreasing order.
    /// </summary>
    int maximumCount(vector<int>& nums);

    /// <summary>
    /// Leet Code 2524. Maximum Frequency Score of a Subarray
    /// 
    /// Hard
    ///	
    /// You are given an integer array nums and a positive integer k.
    /// 
    /// The frequency score of an array is the sum of the distinct values in 
    /// the array raised to the power of their frequencies, taking the sum 
    /// modulo 10^9 + 7.
    ///
    /// For example, the frequency score of the array [5,4,5,7,4,4] is 
    /// (43 + 52 + 71) modulo (109 + 7) = 96.
    /// Return the maximum frequency score of a subarray of size k in nums. 
    /// You should maximize the value under the modulo and not the actual 
    /// value.
    ///
    /// A subarray is a contiguous part of an array.
    /// 
    /// Example 1:
    /// Input: nums = [1,1,1,2,1,2], k = 3
    /// Output: 5
    /// Explanation: The subarray [2,1,2] has a frequency score equal to 5. 
    /// It can be shown that it is the maximum frequency score we can have.
    ///
    /// Example 2:
    /// Input: nums = [1,1,1,1,1,1], k = 4
    /// Output: 1
    /// Explanation: All the subarrays of length 4 have a frequency score 
    /// equal to 1.
    /// 
    /// Constraints:
    /// 1. 1 <= k <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^6
    /// </summary>
    int maxFrequencyScore(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2543. Check if Point Is Reachable
    /// 
    /// Hard
    ///	
    /// There exists an infinitely large grid. You are currently at 
    /// point (1, 1), and you need to reach the point (targetX, targetY) 
    /// using a finite number of steps.
    ///
    /// In one step, you can move from point (x, y) to any one of the 
    /// following points:
    ///
    /// (x, y - x)
    /// (x - y, y)
    /// (2 * x, y)
    /// (x, 2 * y)
    /// Given two integers targetX and targetY representing the 
    /// X-coordinate and Y-coordinate of your final position, return 
    /// true if you can reach the point from (1, 1) using some number 
    /// of steps, and false otherwise.
    ///
    /// Example 1:
    /// Input: targetX = 6, targetY = 9
    /// Output: false
    /// Explanation: It is impossible to reach (6,9) from (1,1) using any 
    /// sequence of moves, so false is returned.
    ///
    /// Example 2:
    /// Input: targetX = 4, targetY = 7
    /// Output: true
    /// Explanation: You can follow the path (1,1) -> (1,2) -> (1,4) -> 
    /// (1,8) -> (1,7) -> (2,7) -> (4,7).
    ///
    /// Constraints:
    /// 1. 1 <= targetX, targetY <= 10^9
    /// </summary>
    bool isReachable(int targetX, int targetY);

    /// <summary>
    /// Leet Code 2544. Alternating Digit Sum
    /// 
    /// Easy
    ///	
    /// You are given a positive integer n. Each digit of n has a sign 
    /// according to the following rules:
    ///
    /// The most significant digit is assigned a positive sign.
    /// Each other digit has an opposite sign to its adjacent digits.
    /// Return the sum of all digits with their corresponding sign.
    /// 
    /// Example 1:
    /// Input: n = 521
    /// Output: 4
    /// Explanation: (+5) + (-2) + (+1) = 4.
    ///
    /// Example 2:
    /// Input: n = 111
    /// Output: 1
    /// Explanation: (+1) + (-1) + (+1) = 1.
    ///
    /// Example 3:
    /// Input: n = 886996
    /// Output: 0
    /// Explanation: (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^9
    /// </summary>
    int alternateDigitSum(int n);

    /// <summary>
    /// Leet Code 2539. Count the Number of Good Subsequences
    /// 
    /// Medium
    ///	
    /// A subsequence of a string is good if it is not empty and the frequency 
    /// of each one of its characters is the same.
    ///
    /// Given a string s, return the number of good subsequences of s. Since 
    /// the answer may be too large, return it modulo 10^9 + 7.
    ///
    /// A subsequence is a string that can be derived from another string by 
    /// deleting some or no characters without changing the order of the 
    /// remaining characters.
    ///
    /// Example 1:
    /// Input: s = "aabb"
    /// Output: 11
    /// Explanation: The total number of subsequences is 24. There are five 
    /// subsequences which are not good: "aabb", "aabb", "aabb", "aabb", and 
    /// the empty subsequence. Hence, the number of good subsequences 
    /// is 24-5 = 11.
    ///
    /// Example 2:
    /// Input: s = "leet"
    /// Output: 12
    /// Explanation: There are four subsequences which are not good: "leet", 
    /// "leet", "leet", and the empty subsequence. Hence, the number of good 
    /// subsequences is 24-4 = 12.
    ///
    /// Example 3:
    /// Input: s = "abcd"
    /// Output: 15
    /// Explanation: All of the non-empty subsequences are good subsequences. 
    /// Hence, the number of good subsequences is 2^4-1 = 15.
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 104
    /// 2. s consists of only lowercase English letters.
    /// </summary>
    int countGoodSubsequences(string s);

    /// <summary>
    /// Leet Code 2549. Count Distinct Numbers on Board
    /// 
    /// Easy
    ///	
    /// You are given a positive integer n, that is initially placed on a 
    /// board. Every day, for 109 days, you perform the following procedure:
    ///
    /// For each number x present on the board, find all numbers 1 <= i <= n 
    /// such that x % i == 1.
    /// Then, place those numbers on the board.
    /// Return the number of distinct integers present on the board after 10^9 
    /// days have elapsed.
    ///
    /// Note:
    /// Once a number is placed on the board, it will remain on it until the 
    /// end.
    /// % stands for the modulo operation. For example, 14 % 3 is 2.
    ///
    /// Example 1:
    /// Input: n = 5
    /// Output: 4
    /// Explanation: Initially, 5 is present on the board. 
    /// The next day, 2 and 4 will be added since 5 % 2 == 1 and 5 % 4 == 1. 
    /// After that day, 3 will be added to the board because 4 % 3 == 1. 
    /// At the end of a billion days, the distinct numbers on the board will 
    /// be 2, 3, 4, and 5. 
    ///
    /// Example 2:
    /// Input: n = 3
    /// Output: 2
    /// Explanation: 
    /// Since 3 % 2 == 1, 2 will be added to the board. 
    /// After a billion days, the only two distinct numbers on the board 
    /// are 2 and 3. 
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 100
    /// </summary>
    int distinctIntegers(int n);

    /// <summary>
    /// Leet Code 2550. Count Collisions of Monkeys on a Polygon
    /// 
    /// Medium
    ///	
    /// There is a regular convex polygon with n vertices. The vertices are 
    /// labeled from 0 to n - 1 in a clockwise direction, and each vertex 
    /// has exactly one monkey. The following figure shows a convex polygon 
    /// of 6 vertices.
    /// 
    /// Each monkey moves simultaneously to a neighboring vertex. A 
    /// neighboring vertex for a vertex i can be:
    ///
    /// the vertex (i + 1) % n in the clockwise direction, or
    /// the vertex (i - 1 + n) % n in the counter-clockwise direction.
    /// A collision happens if at least two monkeys reside on the same vertex 
    /// after the movement.
    ///
    /// Return the number of ways the monkeys can move so that at least one 
    /// collision happens. Since the answer may be very large, return it 
    /// modulo 10^9 + 7.
    ///
    /// Note that each monkey can only move once.
    ///
    /// Example 1:
    /// Input: n = 3
    /// Output: 6
    /// Explanation: There are 8 total possible movements.
    /// Two ways such that they collide at some point are:
    /// - Monkey 1 moves in a clockwise direction; monkey 2 moves in an 
    ///   anticlockwise direction; monkey 3 moves in a clockwise direction. 
    ///   Monkeys 1 and 2 collide.
    /// - Monkey 1 moves in an anticlockwise direction; monkey 2 moves in 
    ///   an anticlockwise direction; monkey 3 moves in a clockwise direction. 
    ///   Monkeys 1 and 3 collide.
    /// It can be shown 6 total movements result in a collision.
    ///
    /// Example 2:
    /// Input: n = 4
    /// Output: 14 
    /// Explanation: It can be shown that there are 14 ways for the monkeys 
    /// to collide.
    /// 
    /// Constraints:
    /// 1. 3 <= n <= 10^9
    /// </summary>
    int monkeyMove(int n);

    /// <summary>
    /// Leet Code 2553. Separate the Digits in an Array
    /// 
    /// Easy
    ///	
    /// Given an array of positive integers nums, return an array answer that 
    /// consists of the digits of each integer in nums after separating them 
    /// in the same order they appear in nums.
    ///
    /// To separate the digits of an integer is to get all the digits it has 
    /// in the same order.
    ///
    /// For example, for the integer 10921, the separation of its digits 
    /// is [1,0,9,2,1].
    /// 
    /// Example 1:
    /// Input: nums = [13,25,83,77]
    /// Output: [1,3,2,5,8,3,7,7]
    /// Explanation: 
    /// - The separation of 13 is [1,3].
    /// - The separation of 25 is [2,5].
    /// - The separation of 83 is [8,3].
    /// - The separation of 77 is [7,7].
    /// answer = [1,3,2,5,8,3,7,7]. Note that answer contains the separations 
    /// in the same order.
    ///
    /// Example 2:
    /// Input: nums = [7,1,3,9]
    /// Output: [7,1,3,9]
    /// Explanation: The separation of each integer in nums is itself.
    /// answer = [7,1,3,9].
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    vector<int> separateDigits(vector<int>& nums);


    /// <summary>
    /// Leet Code 2554. Maximum Number of Integers to Choose From a Range I
    /// 
    /// Medium
    ///	
    /// You are given an integer array banned and two integers n and maxSum. 
    /// You are choosing some number of integers following the below rules:
    ///
    /// The chosen integers have to be in the range [1, n].
    /// Each integer can be chosen at most once.
    /// The chosen integers should not be in the array banned.
    /// The sum of the chosen integers should not exceed maxSum.
    /// Return the maximum number of integers you can choose following the 
    /// mentioned rules.
    ///
    /// Example 1:
    /// Input: banned = [1,6,5], n = 5, maxSum = 6
    /// Output: 2
    /// Explanation: You can choose the integers 2 and 4.
    /// 2 and 4 are from the range [1, 5], both did not appear in banned, 
    /// and their sum is 6, which did not exceed maxSum.
    ///
    /// Example 2:
    /// Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
    /// Output: 0
    /// Explanation: You cannot choose any integer while following the 
    /// mentioned conditions.
    ///
    /// Example 3:
    /// Input: banned = [11], n = 7, maxSum = 50
    /// Output: 7
    /// Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
    /// They are from the range [1, 7], all did not appear in banned, and 
    /// their sum is 28, which did not exceed maxSum.
    ///    
    /// Constraints:
    /// 1. 1 <= banned.length <= 10^4
    /// 2. 1 <= banned[i], n <= 10^4
    /// 3. 1 <= maxSum <= 10^9
    /// </summary>
    int maxCount(vector<int>& banned, int n, int maxSum);

    /// <summary>
    /// Leet Code 2557. Maximum Number of Integers to Choose From a Range II
    /// 
    /// Medium
    ///	
    /// You are given an integer array banned and two integers n and maxSum. 
    /// You are choosing some number of integers following the below rules:
    ///
    /// The chosen integers have to be in the range [1, n].
    /// Each integer can be chosen at most once.
    /// The chosen integers should not be in the array banned.
    /// The sum of the chosen integers should not exceed maxSum.
    /// Return the maximum number of integers you can choose following the 
    /// mentioned rules.
    /// 
    /// Example 1:
    /// Input: banned = [1,4,6], n = 6, maxSum = 4
    /// Output: 1
    /// Explanation: You can choose the integer 3.
    /// 3 is in the range [1, 6], and do not appear in banned. The sum of the 
    /// choosen integers is 3, which does not ecxeed maxSum.
    ///
    /// Example 2:
    /// Input: banned = [4,3,5,6], n = 7, maxSum = 18
    /// Output: 3
    /// Explanation: You can choose the integers 1, 2, and 7.
    /// All these integers are in the range [1, 7], all do not appear in banned, 
    /// and their sum is 18, which does not exceed maxSum.
    /// 
    /// Constraints:
    /// 1. 1 <= banned.length <= 10^5
    /// 2. 1 <= banned[i] <= n <= 10^9
    /// 3. 1 <= maxSum <= 10^15
    /// </summary>
    int maxCount(vector<int>& banned, int n, long long maxSum);

    /// <summary>
    /// Leet Code 2566. Maximum Difference by Remapping a Digit
    /// 
    /// Easy
    ///	
    /// You are given an integer num. You know that Danny Mittal will sneakily 
    /// remap one of the 10 possible digits (0 to 9) to another digit.
    ///
    /// Return the difference between the maximum and minimum values Danny 
    /// can make by remapping exactly one digit in num.
    ///
    /// Notes:
    /// When Danny remaps a digit d1 to another digit d2, Danny replaces all 
    /// occurrences of d1 in num with d2.
    /// Danny can remap a digit to itself, in which case num does not change.
    /// Danny can remap different digits for obtaining minimum and maximum 
    /// values respectively.
    /// The resulting number after remapping can contain leading zeroes.
    /// We mentioned "Danny Mittal" to congratulate him on being in the top 
    /// 10 in Weekly Contest 326.
    /// 
    /// Example 1:
    /// Input: num = 11891
    /// Output: 99009
    /// Explanation: 
    /// To achieve the maximum value, Danny can remap the digit 1 to the 
    /// digit 9 to yield 99899.
    /// To achieve the minimum value, Danny can remap the digit 1 to the 
    /// digit 0, yielding 890.
    /// The difference between these two numbers is 99009.
    ///
    /// Example 2:
    /// Input: num = 90
    /// Output: 99
    /// Explanation:
    /// The maximum value that can be returned by the function is 99 (if 0 
    /// is replaced by 9) and the minimum value that can be returned by the 
    /// function is 0 (if 9 is replaced by 0).
    /// Thus, we return 99.
    /// 
    /// Constraints:
    /// 1. 1 <= num <= 10^8
    /// </summary>
    int minMaxDifference(int num);

    /// <summary>
    /// Leet Code 2575. Find the Divisibility Array of a String
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed string word of length n consisting of 
    /// digits, and a positive integer m.
    ///
    /// The divisibility array div of word is an integer array of length n 
    /// such that:
    ///
    /// div[i] = 1 if the numeric value of word[0,...,i] is divisible by m, or
    /// div[i] = 0 otherwise.
    /// Return the divisibility array of word.
    /// 
    /// Example 1:
    /// Input: word = "998244353", m = 3
    /// Output: [1,1,0,0,0,1,1,0,0]
    /// Explanation: There are only 4 prefixes that are divisible 
    /// by 3: "9", "99", "998244", and "9982443".
    ///
    /// Example 2:
    /// Input: word = "1010", m = 10
    /// Output: [0,1,0,1]
    /// Explanation: There are only 2 prefixes that are divisible 
    /// by 10: "10", and "1010".
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. word.length == n
    /// 3. word consists of digits from 0 to 9
    /// 4. 1 <= m <= 10^9
    /// </summary>
    vector<int> divisibilityArray(string word, int m);

    /// <summary>
    /// Leet Code 2578. Split With Minimum Sum
    /// 
    /// Easy
    ///	
    /// Given a positive integer num, split it into two non-negative integers 
    /// num1 and num2 such that:
    ///
    /// The concatenation of num1 and num2 is a permutation of num.
    /// In other words, the sum of the number of occurrences of each digit in 
    /// num1 and num2 is equal to the number of occurrences of that digit in 
    /// num.
    /// num1 and num2 can contain leading zeros.
    /// Return the minimum possible sum of num1 and num2.
    ///
    /// Notes:
    /// It is guaranteed that num does not contain any leading zeros.
    /// The order of occurrence of the digits in num1 and num2 may differ from 
    /// the order of occurrence of num.
    ///
    /// Example 1:
    /// Input: num = 4325
    /// Output: 59
    /// Explanation: We can split 4325 so that num1 is 24 and num2 is 35, 
    /// giving a sum of 59. We can prove that 59 is indeed the minimal 
    /// possible sum.
    ///
    /// Example 2:
    /// Input: num = 687
    /// Output: 75
    /// Explanation: We can split 687 so that num1 is 68 and num2 is 7, which 
    /// would give an optimal sum of 75.
    ///
    /// Constraints:
    /// 1. 10 <= num <= 10^9
    /// </summary>
    int splitNum(int num);

    /// <summary>
    /// Leet Code 2582. Pass the Pillow
    /// 
    /// Easy
    ///	
    /// There are n people standing in a line labeled from 1 to n. The first 
    /// person in the line is holding a pillow initially. Every second, the 
    /// person holding the pillow passes it to the next person standing in 
    /// the line. Once the pillow reaches the end of the line, the direction 
    /// changes, and people continue passing the pillow in the opposite 
    /// direction.
    /// 
    /// For example, once the pillow reaches the nth person they pass it to 
    /// the n - 1th person, then to the n - 2th person and so on.
    /// Given the two positive integers n and time, return the index of the 
    /// person holding the pillow after time seconds.
    ///
    /// Example 1:
    /// Input: n = 4, time = 5
    /// Output: 2
    /// Explanation: People pass the pillow in the following 
    /// way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
    /// Afer five seconds, the pillow is given to the 2nd person.
    ///
    /// Example 2:
    /// Input: n = 3, time = 2
    /// Output: 3
    /// Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
    /// Afer two seconds, the pillow is given to the 3rd person.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 1000
    /// 2. 1 <= time <= 1000
    /// </summary>
    int passThePillow(int n, int time);

    /// <summary>
    /// Leet Code 2579. Count Total Number of Colored Cells
    /// 
    /// Medium
    ///	
    /// There exists an infinitely large two-dimensional grid of uncolored 
    /// unit cells. You are given a positive integer n, indicating that you 
    /// must do the following routine for n minutes:
    ///
    /// At the first minute, color any arbitrary unit cell blue.
    /// Every minute thereafter, color blue every uncolored cell that 
    /// touches a blue cell.
    /// Below is a pictorial representation of the state of the grid 
    /// after minutes 1, 2, and 3.
    ///
    /// Return the number of colored cells at the end of n minutes.
    /// 
    /// Example 1:
    /// Input: n = 1
    /// Output: 1
    /// Explanation: After 1 minute, there is only 1 blue cell, so we return 1.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: 5
    /// Explanation: After 2 minutes, there are 4 colored cells on the boundary
    /// and 1 in the center, so we return 5. 
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// </summary>
    long long coloredCells(int n);

    /// <summary>
    /// Leet Code 2584. Split the Array to Make Coprime Products
    /// 
    /// Hard
    ///	
    /// You are given a 0-indexed integer array nums of length n.
    ///
    /// A split at an index i where 0 <= i <= n - 2 is called valid if the 
    /// product of the first i + 1 elements and the product of the remaining 
    /// elements are coprime.
    ///
    /// For example, if nums = [2, 3, 3], then a split at the index i = 0 is 
    /// valid because 2 and 9 are coprime, while a split at the index i = 1 
    /// is not valid because 6 and 3 are not coprime. A split at the index 
    /// i = 2 is not valid because i == n - 1.
    /// Return the smallest index i at which the array can be split validly 
    /// or -1 if there is no such split.
    ///
    /// Two values val1 and val2 are coprime if gcd(val1, val2) == 1 where 
    /// gcd(val1, val2) is the greatest common divisor of val1 and val2.
    ///
    /// Example 1:
    /// Input: nums = [4,7,8,15,3,5]
    /// Output: 2
    /// Explanation: The table above shows the values of the product of the 
    /// first i + 1 elements, the remaining elements, and their gcd at each 
    /// index i.
    /// The only valid split is at index 2.
    ///
    /// Example 2:
    /// Input: nums = [4,7,15,8,3,5]
    /// Output: -1
    /// Explanation: The table above shows the values of the product of the 
    /// first i + 1 elements, the remaining elements, and their gcd at each 
    /// index i.
    /// There is no valid split.
    /// 
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 10^4
    /// 3. 1 <= nums[i] <= 10^6
    /// </summary>
    int findValidSplit(vector<int>& nums);

    /// <summary>
    /// Leet Code 2591. Distribute Money to Maximum Children
    /// 
    /// Easy
    ///	
    /// You are given an integer money denoting the amount of money 
    /// (in dollars) that you have and another integer children denoting 
    /// the number of children that you must distribute the money to.
    ///
    /// You have to distribute the money according to the following rules:
    ///
    /// All money must be distributed.
    /// Everyone must receive at least 1 dollar.
    /// Nobody receives 4 dollars.
    /// Return the maximum number of children who may receive exactly 8 
    /// dollars if you distribute the money according to the aforementioned 
    /// rules. If there is no way to distribute the money, return -1.
    ///
    /// Example 1:
    /// Input: money = 20, children = 3
    /// Output: 1
    /// Explanation: 
    /// The maximum number of children with 8 dollars will be 1. One of the 
    /// ways to distribute the money is:
    /// - 8 dollars to the first child.
    /// - 9 dollars to the second child. 
    /// - 3 dollars to the third child.
    /// It can be proven that no distribution exists such that number of 
    /// children getting 8 dollars is greater than 1.
    ///
    /// Example 2:
    /// Input: money = 16, children = 2
    /// Output: 2
    /// Explanation: Each child can be given 8 dollars.
    /// 
    /// Constraints:
    /// 1. 1 <= money <= 200
    /// 2. 2 <= children <= 30
    /// </summary>
    int distMoney(int money, int children);

    /// <summary>
    /// Leet Code 2595. Number of Even and Odd Bits
    /// 
    /// Easy
    ///	
    /// You are given a positive integer n.
    /// Let even denote the number of even indices in the binary 
    /// representation of n (0-indexed) with value 1.
    ///
    /// Let odd denote the number of odd indices in the binary 
    /// representation of n (0-indexed) with value 1.
    ///
    /// Return an integer array answer where answer = [even, odd].
    ///
    /// Example 1:
    /// Input: n = 17
    /// Output: [2,0]
    /// Explanation: The binary representation of 17 is 10001. 
    /// It contains 1 on the 0th and 4th indices. 
    /// There are 2 even and 0 odd indices.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: [0,1]
    /// Explanation: The binary representation of 2 is 10.
    /// It contains 1 on the 1st index. 
    /// There are 0 even and 1 odd indices.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// </summary>
    vector<int> evenOddBit(int n);

    /// <summary>
    /// Leet Code 2598. Smallest Missing Non-negative Integer After Operations
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums and an integer value.
    ///
    /// In one operation, you can add or subtract value from any element of 
    /// nums.
    ///
    /// For example, if nums = [1,2,3] and value = 2, you can choose to 
    /// subtract value from nums[0] to make nums = [-1,2,3].
    /// The MEX (minimum excluded) of an array is the smallest missing 
    /// non-negative integer in it.
    /// For example, the MEX of [-1,2,3] is 0 while the MEX of [1,0,3] is 2. 
    /// Return the maximum MEX of nums after applying the mentioned operation 
    /// any number of times.
    ///
    /// Example 1:
    /// Input: nums = [1,-10,7,13,6,8], value = 5
    /// Output: 4
    /// Explanation: One can achieve this result by applying the following 
    /// operations:
    /// - Add value to nums[1] twice to make nums = [1,0,7,13,6,8]
    /// - Subtract value from nums[2] once to make nums = [1,0,2,13,6,8]
    /// - Subtract value from nums[3] twice to make nums = [1,0,2,3,6,8]
    /// The MEX of nums is 4. It can be shown that 4 is the maximum MEX we 
    /// can achieve.
    ///   
    /// Example 2:
    /// Input: nums = [1,-10,7,13,6,8], value = 7
    /// Output: 2
    /// Explanation: One can achieve this result by applying the following 
    /// operation:
    /// - subtract value from nums[2] once to make nums = [1,-10,0,13,6,8]
    /// The MEX of nums is 2. It can be shown that 2 is the maximum MEX we 
    /// can achieve.
    /// 
    /// Constraints:
    /// 1. 1 <= nums.length, value <= 10^5
    /// 2. -10^9 <= nums[i] <= 10^9
    /// 3. You are given a positive integer n.
    /// </summary>
    int findSmallestInteger(vector<int>& nums, int value);

    /// <summary>
    /// Leet Code 2600. K Items With the Maximum Sum
    /// 
    /// Easy
    ///	
    /// There is a bag that consists of items, each item has a number 1, 0, 
    /// or -1 written on it.
    ///
    /// You are given four non-negative integers numOnes, numZeros, 
    /// numNegOnes, and k.
    ///
    /// The bag initially contains:
    ///
    /// numOnes items with 1s written on them.
    /// numZeroes items with 0s written on them.
    /// numNegOnes items with -1s written on them.
    /// We want to pick exactly k items among the available items. Return the 
    /// maximum possible sum of numbers written on the items.
    ///
    /// Example 1:
    /// Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
    /// Output: 2
    /// Explanation: We have a bag of items with numbers written on them 
    /// {1, 1, 1, 0, 0}. We take 2 items with 1 written on them and get a sum 
    /// in a total of 2.
    /// It can be proven that 2 is the maximum possible sum.
    ///
    /// Example 2:
    /// Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
    /// Output: 3
    /// Explanation: We have a bag of items with numbers written on them 
    /// {1, 1, 1, 0, 0}. We take 3 items with 1 written on them, and 1 item 
    /// with 0 written on it, and get a sum in a total of 3.
    /// It can be proven that 3 is the maximum possible sum.
    ///
    /// Constraints:
    /// 1. 0 <= numOnes, numZeros, numNegOnes <= 50
    /// 2. 0 <= k <= numOnes + numZeros + numNegOnes
    /// </summary>
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k);

    /// <summary>
    /// Leet Code 2601. Prime Subtraction Operation
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed integer array nums of length n.
    ///
    /// You can perform the following operation as many times as you want:
    ///
    /// Pick an index i that you haven’t picked before, and pick a prime p 
    /// strictly less than nums[i], then subtract p from nums[i].
    /// Return true if you can make nums a strictly increasing array using the 
    /// above operation and false otherwise.
    ///
    /// A strictly increasing array is an array whose each element is strictly 
    /// greater than its preceding element.
    ///
    /// Example 1:
    /// Input: nums = [4,9,6,10]
    /// Output: true
    /// Explanation: In the first operation: Pick i = 0 and p = 3, and then 
    /// subtract 3 from nums[0], so that nums becomes [1,9,6,10].
    /// In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums 
    /// becomes equal to [1,2,6,10].
    /// After the second operation, nums is sorted in strictly increasing order, 
    /// so the answer is true.
    ///
    /// Example 2:
    ///
    /// Input: nums = [6,8,11,12]
    /// Output: true
    /// Explanation: Initially nums is sorted in strictly increasing order, so 
    /// we don't need to make any operations.
    ///
    /// Example 3:
    /// Input: nums = [5,8,3]
    /// Output: false
    /// Explanation: It can be proven that there is no way to perform operations 
    /// to make nums sorted in strictly increasing order, so the answer is false.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 1000
    /// 2. 1 <= nums[i] <= 1000
    /// 3. nums.length == n
    /// </summary>
    bool primeSubOperation(vector<int>& nums);

        /// <summary>
    /// Leet Code 2605. Form Smallest Number From Two Digit Arrays
    /// 
    /// Easy
    ///	
	/// Given two arrays of unique digits nums1 and nums2, return the smallest 
	/// number that contains at least one digit from each array.
    ///
    ///
    /// Example 1:
    /// Input: nums1 = [4,1,3], nums2 = [5,7]
    /// Output: 15
    /// Explanation: The number 15 contains the digit 1 from nums1 and the 
	/// digit 5 from nums2. It can be proven that 15 is the smallest number 
	/// we can have.
    ///
	/// Example 2:
    /// Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
    /// Output: 3
    /// Explanation: The number 3 contains the digit 3 which exists in 
	/// both arrays.
    ///
    /// Constraints:
    /// 1. 1 <= nums1.length, nums2.length <= 9
    /// 2. 1 <= nums1[i], nums2[i] <= 9
    /// 3. All digits in each array are unique.
    /// </summary>
    int minNumber(vector<int>& nums1, vector<int>& nums2);

    /// <summary>
    /// Leet Code 2614. Prime In Diagonal
    /// 
    /// Easy
    ///	
    /// You are given a 0-indexed two-dimensional integer array nums.
    ///
    /// Return the largest prime number that lies on at least one of the 
    /// diagonals of nums. In case, no prime is present on any of the 
    /// diagonals, return 0.
    ///
    /// Note that:
    /// An integer is prime if it is greater than 1 and has no positive 
    /// integer divisors other than 1 and itself.
    /// An integer val is on one of thediagonals of nums if there exists 
    /// an integer i for which nums[i][i] = val or an i for which 
    /// nums[i][nums.length - i - 1]= val.
    ///
    /// In the above diagram, one diagonal is [1,5,9] and another 
    /// diagonal is [3,5,7].
    /// 
    /// Example 1:
    /// Input: nums = [[1,2,3],[5,6,7],[9,10,11]]
    /// Output: 11
    /// Explanation: The numbers 1, 3, 6, 9, and 11 are the only numbers 
    /// present on at least one of the diagonals. Since 11 is the largest 
    /// prime, we return 11.
    ///
    /// Example 2:
    /// Input: nums = [[1,2,3],[5,17,7],[9,11,10]]
    /// Output: 17
    /// Explanation: The numbers 1, 3, 9, 10, and 17 are all present on at 
    /// least one of the diagonals. 17 is the largest prime, so we return 17.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 300
    /// 2. nums.length == numsi.length
    /// 3. 1 <= nums[i][j] <= 4*10^6
    /// </summary>
    int diagonalPrime(vector<vector<int>>& nums);

    /// <summary>
    /// Leet Code 2644. Find the Maximum Divisibility Score
    /// 
    /// Easy
    ///	
    /// You are given two 0-indexed integer arrays nums and divisors.
    /// 
    /// The divisibility score of divisors[i] is the number of indices j 
    /// such that nums[j] is divisible by divisors[i].
    ///
    /// Return the integer divisors[i] with the maximum divisibility score. 
    /// If there is more than one integer with the maximum score, return 
    /// the minimum of them.
    ///
    /// Example 1:
    /// Input: nums = [4,7,9,3,9], divisors = [5,2,3]
    /// Output: 3
    /// Explanation: The divisibility score for every element in divisors is:
    /// The divisibility score of divisors[0] is 0 since no number in nums is 
    /// divisible by 5.
    /// The divisibility score of divisors[1] is 1 since nums[0] is divisible 
    /// by 2.
    /// The divisibility score of divisors[2] is 3 since nums[2], nums[3], 
    /// and nums[4] are divisible by 3.
    /// Since divisors[2] has the maximum divisibility score, we return it.
    ///
    /// Example 2:
    /// Input: nums = [20,14,21,10], divisors = [5,7,5]
    /// Output: 5
    /// Explanation: The divisibility score for every element in divisors is:
    /// The divisibility score of divisors[0] is 2 since nums[0] and nums[3] 
    /// are divisible by 5.
    /// The divisibility score of divisors[1] is 2 since nums[1] and nums[2] 
    /// are divisible by 7.
    /// The divisibility score of divisors[2] is 2 since nums[0] and nums[3] 
    /// are divisible by 5.
    /// Since divisors[0], divisors[1], and divisors[2] all have the maximum 
    /// divisibility score, we return the minimum of them (i.e., divisors[2]).
    ///
    /// Example 3:
    /// Input: nums = [12], divisors = [10,16]
    /// Output: 10
    /// Explanation: The divisibility score for every element in divisors is:
    /// The divisibility score of divisors[0] is 0 since no number in nums is 
    /// divisible by 10.
    /// The divisibility score of divisors[1] is 0 since no number in nums is 
    /// divisible by 16.
    /// Since divisors[0] and divisors[1] both have the maximum divisibility 
    /// score, we return the minimum of them (i.e., divisors[0]).
    ///
    /// Constraints:
    /// 1. 1 <= nums.length, divisors.length <= 1000
    /// 2. 1 <= nums[i], divisors[i] <= 10^9
    /// </summary>
    int maxDivScore(vector<int>& nums, vector<int>& divisors);

    /// <summary>
    /// Leet Code 2647. Color the Triangle Red
    /// 
    /// Hard
    ///	
    /// You are given an integer n. Consider an equilateral triangle of side 
    /// length n, broken up into n2 unit equilateral triangles. The triangle 
    /// has n 1-indexed rows where the ith row has 2i - 1 unit equilateral 
    /// triangles.
    ///
    /// The triangles in the ith row are also 1-indexed with coordinates 
    /// from (i, 1) to (i, 2i - 1). The following image shows a triangle of 
    /// side length 4 with the indexing of its triangle.
    ///
    /// Two triangles are neighbors if they share a side. For example:
    ///
    /// Triangles (1,1) and (2,2) are neighbors
    /// Triangles (3,2) and (3,3) are neighbors.
    /// Triangles (2,2) and (3,3) are not neighbors because they do not share 
    /// any side.
    /// Initially, all the unit triangles are white. You want to choose k 
    /// triangles and color them red. We will then run the following algorithm:
    ///
    /// Choose a white triangle that has at least two red neighbors.
    /// If there is no such triangle, stop the algorithm.
    /// Color that triangle red.
    /// Go to step 1.
    /// Choose the minimum k possible and set k triangles red before running 
    /// this algorithm such that after the algorithm stops, all unit triangles 
    /// are colored red.
    ///
    /// Return a 2D list of the coordinates of the triangles that you will color 
    /// red initially. The answer has to be of the smallest size possible. If 
    /// there are multiple valid solutions, return any.
    ///
    /// Example 1:
    /// Input: n = 3
    /// Output: [[1,1],[2,1],[2,3],[3,1],[3,5]]
    /// Explanation: Initially, we choose the shown 5 triangles to be red. 
    /// Then, we run the algorithm:
    /// - Choose (2,2) that has three red neighbors and color it red.
    /// - Choose (3,2) that has two red neighbors and color it red.
    /// - Choose (3,4) that has three red neighbors and color it red.
    /// - Choose (3,3) that has three red neighbors and color it red.
    /// It can be shown that choosing any 4 triangles and running the 
    /// algorithm will not make all triangles red.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: [[1,1],[2,1],[2,3]]
    /// Explanation: Initially, we choose the shown 3 triangles to be red. 
    /// Then, we run the algorithm:
    /// - Choose (2,2) that has three red neighbors and color it red.
    /// It can be shown that choosing any 2 triangles and running the 
    /// algorithm will not make all triangles red.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// </summary>
    vector<vector<int>> colorRed(int n);

    /// <summary>
    /// Leet Code 2651. Calculate Delayed Arrival Time
    /// 
    /// Easy
    ///	
    /// You are given a positive integer arrivalTime denoting the arrival 
    /// time of a train in hours, and another positive integer delayedTime 
    /// denoting the amount of delay in hours.
    ///
    /// Return the time when the train will arrive at the station.
    /// Note that the time in this problem is in 24-hours format.
    /// 
    /// Example 1:
    /// Input: arrivalTime = 15, delayedTime = 5 
    /// Output: 20 
    /// Explanation: Arrival time of the train was 15:00 hours. It is 
    /// delayed by 5 hours. Now it will reach at 15+5 = 20 (20:00 hours).
    ///
    /// Example 2:
    /// Input: arrivalTime = 13, delayedTime = 11
    /// Output: 0
    /// Explanation: Arrival time of the train was 13:00 hours. It is 
    /// delayed by 11 hours. Now it will reach at 13+11=24 (Which is 
    /// denoted by 00:00 in 24 hours format so return 0).
    ///
    /// Constraints:
    /// 1. 1 <= arrivaltime < 24
    /// 2. 1 <= delayedTime <= 24
    /// </summary>
    int findDelayedArrivalTime(int arrivalTime, int delayedTime);

    /// <summary>
    /// Leet Code 2652. Sum Multiples
    /// 
    /// Easy
    ///	
    /// Given a positive integer n, find the sum of all integers in the range 
    /// [1, n] inclusive that are divisible by 3, 5, or 7.
    ///
    /// Return an integer denoting the sum of all numbers in the given range 
    /// satisfying the constraint.
    ///
    /// Example 1:
    /// Input: n = 7
    /// Output: 21
    /// Explanation: Numbers in the range [1, 7] that are divisible by 3, 5, 
    /// or 7 are 3, 5, 6, 7. The sum of these numbers is 21.
    ///
    /// Example 2:
    /// Input: n = 10
    /// Output: 40
    /// Explanation: Numbers in the range [1, 10] that are divisible by 3, 5, 
    /// or 7 are 3, 5, 6, 7, 9, 10. The sum of these numbers is 40.
    ///
    /// Example 3:
    /// Input: n = 9
    /// Output: 30
    /// Explanation: Numbers in the range [1, 9] that are divisible by 3, 5, 
    /// or 7 are 3, 5, 6, 7, 9. The sum of these numbers is 30.
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^3
    /// </summary>
    int sumOfMultiples(int n);

    /// <summary>
    /// Leet Code 2654. Minimum Number of Operations to Make All Array 
    ///                 Elements Equal to 1
    /// 
    /// Medium
    ///	
    /// You are given a 0-indexed array nums consisiting of positive integers. 
    /// You can do the following operation on the array any number of times:
    ///
    /// Select an index i such that 0 <= i < n - 1 and replace either of 
    /// nums[i] or nums[i+1] with their gcd value.
    /// Return the minimum number of operations to make all elements of nums 
    /// equal to 1. If it is impossible, return -1.
    ///
    /// The gcd of two integers is the greatest common divisor of the two integers.
    ///
    /// Example 1:
    /// Input: nums = [2,6,3,4]
    /// Output: 4
    /// Explanation: We can do the following operations:
    /// - Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have 
    ///   nums = [2,6,1,4].
    /// - Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have 
    ///   nums = [2,1,1,4].
    /// - Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have 
    ///   nums = [1,1,1,4].
    /// - Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have 
    ///   nums = [1,1,1,1].
    //
    /// Example 2:
    /// Input: nums = [2,10,6,14]
    /// Output: -1
    /// Explanation: It can be shown that it is impossible to make all the 
    /// elements equal to 1.
    ///
    /// Constraints:
    /// 1. 2 <= nums.length <= 50
    /// 2. 1 <= nums[i] <= 10^6
    /// </summary>
    int minOperationsII(vector<int>& nums);

    /// <summary>
    /// Leet Code 2656. Maximum Sum With Exactly K Elements
    /// 
    /// Easy
    ///	
    /// You are given a 0-indexed integer array nums and an integer k. Your 
    /// task is to perform the following operation exactly k times in order 
    /// to maximize your score:
    ///
    /// Select an element m from nums.
    /// Remove the selected element m from the array.
    /// Add a new element with a value of m + 1 to the array.
    /// Increase your score by m.
    /// Return the maximum score you can achieve after performing the 
    /// operation exactly k times.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3,4,5], k = 3
    /// Output: 18
    /// Explanation: We need to choose exactly 3 elements from nums to 
    /// maximize the sum.
    /// For the first iteration, we choose 5. Then sum is 5 and 
    /// nums = [1,2,3,4,6]
    /// For the second iteration, we choose 6. Then sum is 5 + 6 and 
    /// nums = [1,2,3,4,7]
    /// For the third iteration, we choose 7. Then sum is 5 + 6 + 7 = 18 
    /// and nums = [1,2,3,4,8]
    /// So, we will return 18.
    /// It can be proven, that 18 is the maximum answer that we can achieve.
    ///
    /// Example 2:
    /// Input: nums = [5,5,5], k = 2
    /// Output: 11
    /// Explanation: We need to choose exactly 2 elements from nums to 
    /// maximize the sum.
    /// For the first iteration, we choose 5. Then sum is 5 and nums = [5,5,6]
    /// For the second iteration, we choose 6. Then sum is 5 + 6 = 11 and 
    /// nums = [5,5,7]
    /// So, we will return 11.
    /// It can be proven, that 11 is the maximum answer that we can achieve.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 100
    /// 3. 1 <= k <= 100
    /// </summary>
    int maximizeSum(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2682. Find the Losers of the Circular Game
    /// 
    /// Easy
    ///	
    /// There are n friends that are playing a game. The friends are sitting 
    /// in a circle and are numbered from 1 to n in clockwise order. More 
    /// formally, moving clockwise from the ith friend brings you to the 
    /// (i+1)th friend for 1 <= i < n, and moving clockwise from the nth 
    /// friend brings you to the 1st friend.
    ///
    /// The rules of the game are as follows:
    ///
    /// 1st friend receives the ball.
    /// After that, 1st friend passes it to the friend who is k steps away 
    /// from them in the clockwise direction.
    /// After that, the friend who receives the ball should pass it to the 
    /// friend who is 2 * k steps away from them in the clockwise direction.
    /// After that, the friend who receives the ball should pass it to the 
    /// friend who is 3 * k steps away from them in the clockwise direction, 
    /// and so on and so forth.
    /// In other words, on the ith turn, the friend holding the ball should 
    /// pass it to the friend who is i * k steps away from them in the 
    /// clockwise direction.
    ///
    /// The game is finished when some friend receives the ball for the 
    /// second time.
    ///
    /// The losers of the game are friends who did not receive the ball in 
    /// the entire game.
    ///
    /// Given the number of friends, n, and an integer k, return the array 
    /// answer, which contains the losers of the game in the ascending order.
    ///
    /// 
    /// Example 1:
    /// Input: n = 5, k = 2
    /// Output: [4,5]
    /// Explanation: The game goes as follows:
    /// 1) Start at 1st friend and pass the ball to the friend who is 2 steps 
    ///    away from them - 3rd friend.
    /// 2) 3rd friend passes the ball to the friend who is 4 steps away from 
    ///    them - 2nd friend.
    /// 3) 2nd friend passes the ball to the friend who is 6 steps away from 
    ///    them  - 3rd friend.
    /// 4) The game ends as 3rd friend receives the ball for the second time.
    ///
    /// Example 2:
    /// Input: n = 4, k = 4
    /// Output: [2,3,4]
    /// Explanation: The game goes as follows:
    /// 1) Start at the 1st friend and pass the ball to the friend who is 4 
    ///    steps away from them - 1st friend.
    /// 2) The game ends as 1st friend receives the ball for the second time.
    /// 
    /// Constraints:
    /// 1. 1 <= k <= n <= 50
    /// </summary>
    vector<int> circularGameLosers(int n, int k);

    /// <summary>
    /// Leet Code 2698. Find the Punishment Number of an Integer
    /// </summary>
    bool punishmentNumber(string str, int sum, int pos, int target);

    /// <summary>
    /// Leet Code 2698. Find the Punishment Number of an Integer
    /// 
    /// Medium
    ///	
    /// Given a positive integer n, return the punishment number of n.
    ///
    /// The punishment number of n is defined as the sum of the squares of all 
    /// integers i such that:
    ///
    /// 1 <= i <= n
    /// The decimal representation of i * i can be partitioned into contiguous 
    /// substrings such that the sum of the integer values of these substrings 
    /// equals i.
    /// 
    /// Example 1:
    /// Input: n = 10
    /// Output: 182
    /// Explanation: There are exactly 3 integers i that satisfy the 
    /// conditions in the statement:
    /// - 1 since 1 * 1 = 1
    /// - 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1.
    /// - 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0.
    /// Hence, the punishment number of 10 is 1 + 81 + 100 = 182
    ///
    /// Example 2:
    /// Input: n = 37
    /// Output: 1478
    /// Explanation: There are exactly 4 integers i that satisfy the 
    /// conditions in the statement:
    /// - 1 since 1 * 1 = 1. 
    /// - 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1. 
    /// - 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0. 
    /// - 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
    /// Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478
    ///
    /// Constraints:
    /// 1. 1 <= n <= 1000
    /// </summary>
    int punishmentNumber(int n);

    /// <summary>
    /// Leet Code 2706. Buy Two Chocolates
    /// 
    /// Easy
    ///	
    /// You are given an integer array prices representing the prices of 
    /// various chocolates in a store. You are also given a single integer 
    /// money, which represents your initial amount of money.
    ///
    /// You must buy exactly two chocolates in such a way that you still 
    /// have some non-negative leftover money. You would like to minimize 
    /// the sum of the prices of the two chocolates you buy.
    ///
    /// Return the amount of money you will have leftover after buying 
    /// the two chocolates. If there is no way for you to buy two 
    /// chocolates without ending up in debt, return money. Note that the 
    /// leftover must be non-negative.
    ///
    /// Example 1:
    /// Input: prices = [1,2,2], money = 3
    /// Output: 0
    /// Explanation: Purchase the chocolates priced at 1 and 2 units 
    /// respectively. You will have 3 - 3 = 0 units of money afterwards. 
    /// Thus, we return 0.
    ///
    /// Example 2:
    /// Input: prices = [3,2,3], money = 3
    /// Output: 3
    /// Explanation: You cannot buy 2 chocolates without going in debt, so 
    /// we return 3.
    ///
    /// Constraints:
    /// 1. 2 <= prices.length <= 50
    /// 2. 1 <= prices[i] <= 100
    /// 3. 1 <= money <= 100
    /// </summary>
    int buyChoco(vector<int>& prices, int money);

    /// <summary>
    /// Leet Code 2708. Maximum Strength of a Group
    /// 
    /// You are given a 0-indexed integer array nums representing the score of 
    /// students in an exam. The teacher would like to form one non-empty 
    /// group of students with maximal strength, where the strength of a group 
    /// of students of indices i0, i1, i2, ... , ik is defined as 
    /// nums[i0] * nums[i1] * nums[i2] * ... * nums[ik?].
    ///
    /// Return the maximum strength of a group the teacher can create.
    /// 
    /// Example 1:
    /// Input: nums = [3,-1,-5,2,5,-9]
    /// Output: 1350
    /// Explanation: One way to form a group of maximal strength is to group 
    /// the students at indices [0,2,3,4,5]. Their strength 
    /// is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.
    ///
    /// Example 2:
    /// Input: nums = [-4,-5,-4]
    /// Output: 20
    /// Explanation: Group the students at indices [0, 1] . Then, we’ll have 
    /// a resulting strength of 20. We cannot achieve greater strength.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 13
    /// 2. -9 <= nums[i] <= 9
    /// </summary>
    long long maxStrength(vector<int>& nums);

    /// <summary>
    /// Leet Code 2719. Count of Integers
    /// </summary>
    int count(string num, int min_sum, int max_sum, vector<vector<int>>& dp);

    /// <summary>
    /// Leet Code 2719. Count of Integers
    /// 
    /// Hard
    ///
    /// You are given two numeric strings num1 and num2 and two integers 
    /// max_sum and min_sum. We denote an integer x to be good if:
    ///
    /// num1 <= x <= num2
    /// min_sum <= digit_sum(x) <= max_sum.
    /// Return the number of good integers. Since the answer may be 
    /// large, return it modulo 10^9 + 7.
    ///
    /// Note that digit_sum(x) denotes the sum of the digits of x.
    /// Example 1:
    /// Input: num1 = "1", num2 = "12", min_num = 1, max_num = 8
    /// Output: 11
    /// Explanation: There are 11 integers whose sum of digits lies 
    /// between 1 and 8 are 1,2,3,4,5,6,7,8,10,11, and 12. Thus, we 
    /// return 11.
    ///
    /// Example 2:
    /// Input: num1 = "1", num2 = "5", min_num = 1, max_num = 5
    /// Output: 5
    /// Explanation: The 5 integers whose sum of digits lies between 1 and 5 
    /// are 1,2,3,4, and 5. Thus, we return 5.
    /// 
    /// Constraints:
    /// 1. 1 <= num1 <= num2 <= 10^22
    /// 2. 1 <= min_sum <= max_sum <= 400
    /// </summary>
    int count(string num1, string num2, int min_sum, int max_sum);

    /// <summary>
    /// Leet Code 2729. Check if The Number is Fascinating
    /// 
    /// Easy
    ///
    /// You are given an integer n that consists of exactly 3 digits.
    ///
    /// We call the number n fascinating if, after the following modification, 
    /// the resulting number contains all the digits from 1 to 9 exactly once 
    /// and does not contain any 0's:
    ///
    /// Concatenate n with the numbers 2 * n and 3 * n.
    /// Return true if n is fascinating, or false otherwise.
    ///
    /// Concatenating two numbers means joining them together. For example, 
    /// the concatenation of 121 and 371 is 121371.
    ///
    /// Example 1:
    /// Input: n = 192
    /// Output: true
    /// Explanation: We concatenate the numbers n = 192 and 2 * n = 384 
    /// and 3 * n = 576. The resulting number is 192384576. This number 
    /// contains all the digits from 1 to 9 exactly once.
    ///
    /// Example 2:
    /// Input: n = 100
    /// Output: false
    /// Explanation: We concatenate the numbers n = 100 and 2 * n = 200 
    /// and 3 * n = 300. The resulting number is 100200300. This number 
    /// does not satisfy any of the conditions.
    /// 
    /// Constraints:
    /// 1. 100 <= n <= 999
    /// </summary>
    bool isFascinating(int n);

    /// <summary>
    /// Leet Code 2739. Total Distance Traveled
    /// 
    /// Easy
    ///
    /// A truck has two fuel tanks. You are given two integers, mainTank 
    /// representing the fuel present in the main tank in liters and 
    /// additionalTank representing the fuel present in the additional tank 
    /// in liters.
    ///
    /// The truck has a mileage of 10 km per liter. Whenever 5 liters of fuel 
    /// get used up in the main tank, if the additional tank has at least 1 
    /// liters of fuel, 1 liters of fuel will be transferred from the 
    /// additional tank to the main tank.
    ///
    /// Return the maximum distance which can be traveled.
    ///
    /// Note: Injection from the additional tank is not continuous. It happens 
    /// suddenly and immediately for every 5 liters consumed.
    /// 
    /// Example 1:
    /// Input: mainTank = 5, additionalTank = 10
    /// Output: 60
    /// Explanation: 
    /// After spending 5 litre of fuel, fuel remaining is (5 - 5 + 1) = 1 litre 
    /// and distance traveled is 50km.
    /// After spending another 1 litre of fuel, no fuel gets injected in the main 
    /// tank and the main tank becomes empty.
    /// Total distance traveled is 60km.
    ///
    /// Example 2:
    /// Input: mainTank = 1, additionalTank = 2
    /// Output: 10
    /// Explanation: 
    /// After spending 1 litre of fuel, the main tank becomes empty.
    /// Total distance traveled is 10km.
    /// 
    /// Constraints:
    /// 1. 1 <= mainTank, additionalTank <= 100
    /// </summary>
    int distanceTraveled(int mainTank, int additionalTank);

    /// <summary>
    /// Leet Code 2748. Number of Beautiful Pairs
    /// 
    /// Easy
    ///
    /// You are given a 0-indexed integer array nums. A pair of indices i, j 
    /// where 0 <= i < j < nums.length is called beautiful if the first digit 
    /// of nums[i] and the last digit of nums[j] are coprime.
    ///
    /// Return the total number of beautiful pairs in nums.
    /// Two integers x and y are coprime if there is no integer greater than 1 
    /// that divides both of them. In other words, x and y are coprime if 
    /// gcd(x, y) == 1, where gcd(x, y) is the greatest common divisor of x 
    /// and y.
    /// 
    /// Example 1:
    /// Input: nums = [2,5,1,4]
    /// Output: 5
    /// Explanation: There are 5 beautiful pairs in nums:
    /// When i = 0 and j = 1: the first digit of nums[0] is 2, and the last 
    /// digit of nums[1] is 5. We can confirm that 2 and 5 are coprime, 
    /// since gcd(2,5) == 1.
    /// When i = 0 and j = 2: the first digit of nums[0] is 2, and the last 
    /// digit of nums[2] is 1. Indeed, gcd(2,1) == 1.
    /// When i = 1 and j = 2: the first digit of nums[1] is 5, and the last 
    /// digit of nums[2] is 1. Indeed, gcd(5,1) == 1.
    /// When i = 1 and j = 3: the first digit of nums[1] is 5, and the last 
    /// digit of nums[3] is 4. Indeed, gcd(5,4) == 1.
    /// When i = 2 and j = 3: the first digit of nums[2] is 1, and the last 
    /// digit of nums[3] is 4. Indeed, gcd(1,4) == 1.
    /// Thus, we return 5.
    ///
    /// Example 2:
    /// Input: nums = [11,21,12]
    /// Output: 2
    /// Explanation: There are 2 beautiful pairs:
    /// When i = 0 and j = 1: the first digit of nums[0] is 1, and the last 
    /// digit of nums[1] is 1. Indeed, gcd(1,1) == 1.
    /// When i = 0 and j = 2: the first digit of nums[0] is 1, and the last 
    /// digit of nums[2] is 2. Indeed, gcd(1,2) == 1.
    /// Thus, we return 2.
    /// 
    /// Constraints:
    /// 1. 2 <= nums.length <= 100
    /// 2. 1 <= nums[i] <= 9999
    /// 3. nums[i] % 10 != 0
    /// </summary>
    int countBeautifulPairs(vector<int>& nums);

    /// <summary>
    /// Leet Code 2745. Construct the Longest New String
    /// 
    /// Medium
    ///
    /// You are given three integers x, y, and z.
    ///
    /// You have x strings equal to "AA", y strings equal to "BB", and z 
    /// strings equal to "AB". You want to choose some (possibly all or 
    /// none) of these strings and concactenate them in some order to 
    /// form a new string. This new string must not contain "AAA" or "BBB" 
    /// as a substring.
    ///
    /// Return the maximum possible length of the new string.
    /// A substring is a contiguous non-empty sequence of characters within 
    /// a string.
    /// 
    /// Example 1:
    /// Input: x = 2, y = 5, z = 1
    /// Output: 12
    /// Explanation: We can concactenate the strings "BB", "AA", "BB", "AA", 
    /// "BB", and "AB" in that order. Then, our new string is "BBAABBAABBAB". 
    /// That string has length 12, and we can show that it is impossible to 
    /// construct a string of longer length.
    ///
    /// Example 2:
    /// Input: x = 3, y = 2, z = 2
    /// Output: 14
    /// Explanation: We can concactenate the strings "AB", "AB", "AA", "BB", 
    /// "AA", "BB", and "AA" in that order. Then, our new string is 
    /// "ABABAABBAABBAA". 
    /// That string has length 14, and we can show that it is impossible to 
    /// construct a string of longer length.
    ///
    /// Constraints:
    /// 1. 1 <= x, y, z <= 50
    /// </summary>
    int longestString(int x, int y, int z);

    /// <summary>
    /// Leet Code 2749. Minimum Operations to Make the Integer Zero
    /// 
    /// Medium
    ///
    /// You are given two integers num1 and num2.
    ///
    /// In one operation, you can choose integer i in the range [0, 60] and 
    /// subtract 2i + num2 from num1.
    ///
    /// Return the integer denoting the minimum number of operations needed 
    /// to make num1 equal to 0.
    ///
    /// If it is impossible to make num1 equal to 0, return -1.
    /// 
    /// Example 1:
    /// Input: num1 = 3, num2 = -2
    /// Output: 3
    /// Explanation: We can make 3 equal to 0 with the following operations:
    /// - We choose i = 2 and substract 22 + (-2) from 3, 3 - (4 + (-2)) = 1.
    /// - We choose i = 2 and substract 22 + (-2) from 1, 1 - (4 + (-2)) = -1.
    /// - We choose i = 0 and substract 20 + (-2) from 
    ///   -1, (-1) - (1 + (-2)) = 0.
    /// It can be proven, that 3 is the minimum number of operations that we 
    /// need to perform.
    /// Example 2:
    ///
    /// Input: num1 = 5, num2 = 7
    /// Output: -1
    /// Explanation: It can be proven, that it is impossible to make 5 equal 
    /// to 0 with the given operation.
    /// 
    /// Constraints:
    /// 1. 1 <= num1 <= 10^9
    /// 2. -10^9 <= num2 <= 10^9
    /// </summary>
    int makeTheIntegerZero(int num1, int num2);

    /// <summary>
    /// Leet Code 2761. Prime Pairs With Target Sum
    /// 
    /// Medium
    ///
    /// You are given an integer n. We say that two integers x and y form a 
    /// prime number pair if:
    ///
    /// 1 <= x <= y <= n
    /// x + y == n
    /// x and y are prime numbers
    /// Return the 2D sorted list of prime number pairs [xi, yi]. The list 
    /// should be sorted in increasing order of xi. If there are no prime 
    /// number pairs at all, return an empty array.
    ///
    /// Note: A prime number is a natural number greater than 1 with 
    /// only two factors, itself and 1.
    ///
    /// Example 1:
    /// Input: n = 10
    ///
    /// Output: [[3,7],[5,5]]
    /// Explanation: In this example, there are two prime pairs that satisfy 
    /// the criteria. 
    /// These pairs are [3,7] and [5,5], and we return them in the sorted 
    /// order as described in the problem statement.
    ///
    /// Example 2:
    /// Input: n = 2
    /// Output: []
    /// Explanation: We can show that there is no prime number pair that 
    /// gives a sum of 2, so we return an empty array. 
    /// 
    /// Constraints:
    /// 1 <= n <= 10^6
    /// </summary>
    vector<vector<int>> findPrimePairs(int n);

    /// <summary>
    /// Leet Code 2769. Find the Maximum Achievable Number
    /// 
    /// Easy
    ///
    /// You are given two integers, num and t.
    ///
    /// An integer x is called achievable if it can become equal to num after 
    /// applying the following operation no more than t times:
    ///
    /// Increase or decrease x by 1, and simultaneously increase or decrease 
    /// num by 1.
    /// Return the maximum possible achievable number. It can be proven that 
    /// there exists at least one achievable number.
    ///
    /// Example 1:
    /// Input: num = 4, t = 1
    /// Output: 6
    /// Explanation: The maximum achievable number is x = 6; it can become 
    /// equal to num after performing this operation:
    /// 1- Decrease x by 1, and increase num by 1. Now, x = 5 and num = 5. 
    /// It can be proven that there is no achievable number larger than 6.
    ///
    /// Example 2:
    /// Input: num = 3, t = 2
    /// Output: 7
    /// Explanation: The maximum achievable number is x = 7; after performing 
    /// these operations, x will equal num: 
    /// 1- Decrease x by 1, and increase num by 1. Now, x = 6 and num = 4.
    /// 2- Decrease x by 1, and increase num by 1. Now, x = 5 and num = 5.
    /// It can be proven that there is no achievable number larger than 7.
    /// 
    /// Constraints:
    /// 1. 1 <= num, t <= 50
    /// </summary>
    int theMaximumAchievableX(int num, int t);

    /// <summary>
    /// Leet Code 2778. Sum of Squares of Special Elements
    /// 
    /// Easy
    ///
    /// You are given a 1-indexed integer array nums of length n.
    /// An element nums[i] of nums is called special if i divides n, i.e. 
    /// n % i == 0.
    ///
    /// Return the sum of the squares of all special elements of nums.
    /// 
    /// Example 1:
    /// Input: nums = [1,2,3,4]
    /// Output: 21
    /// Explanation: There are exactly 3 special elements in nums: nums[1] 
    /// since 1 divides 4, nums[2] since 2 divides 4, and nums[4] since 4 
    /// divides 4. 
    /// Hence, the sum of the squares of all special elements of nums is 
    /// nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 
    /// 2 * 2 + 4 * 4 = 21.  
    ///
    /// Example 2:
    /// Input: nums = [2,7,1,19,18,3]
    /// Output: 63
    /// Explanation: There are exactly 4 special elements in nums: nums[1] 
    /// since 1 divides 6, nums[2] since 2 divides 6, nums[3] since 3 
    /// divides 6, and nums[6] since 6 divides 6. 
    /// Hence, the sum of the squares of all special elements of nums is 
    /// nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + 
    /// nums[6] * nums[6] = 2 * 2 + 7 * 7 + 1 * 1 + 3 * 3 = 63. 
    ///
    /// Constraints:
    /// 1. 1 <= nums.length == n <= 50
    /// 2. 1 <= nums[i] <= 50
    /// </summary>
    int sumOfSquares(vector<int>& nums);

    /// <summary>
    /// Leet Code 2790. Maximum Number of Groups With Increasing Length
    /// 
    /// Hard
    ///
    /// You are given a 0-indexed array usageLimits of length n.
    ///
    /// Your task is to create groups using numbers from 0 to n - 1, ensuring 
    /// that each number, i, is used no more than usageLimits[i] times in 
    /// total across all groups. You must also satisfy the following 
    /// conditions:
    ///
    /// Each group must consist of distinct numbers, meaning that no duplicate 
    /// numbers are allowed within a single group.
    /// Each group (except the first one) must have a length strictly greater 
    /// than the previous group.
    /// Return an integer denoting the maximum number of groups you can create 
    /// while satisfying these conditions.
    /// 
    /// Example 1:
    /// Input: usageLimits = [1,2,5]
    /// Output: 3
    /// Explanation: In this example, we can use 0 at most once, 1 at most 
    /// twice, and 2 at most five times.
    /// One way of creating the maximum number of groups while satisfying the 
    /// conditions is: 
    /// Group 1 contains the number [2].
    /// Group 2 contains the numbers [1,2].
    /// Group 3 contains the numbers [0,1,2]. 
    /// It can be shown that the maximum number of groups is 3. 
    /// So, the output is 3. 
    ///
    /// Example 2:
    /// Input: usageLimits = [2,1,2]
    /// Output: 2
    /// Explanation: In this example, we can use 0 at most twice, 1 at most 
    /// once, and 2 at most twice.
    /// One way of creating the maximum number of groups while satisfying the 
    /// conditions is:
    /// Group 1 contains the number [0].
    /// Group 2 contains the numbers [1,2].
    /// It can be shown that the maximum number of groups is 2.
    /// So, the output is 2. 
    ///
    /// Example 3:
    /// Input: usageLimits = [1,1]
    /// Output: 1
    /// Explanation: In this example, we can use both 0 and 1 at most once.
    /// One way of creating the maximum number of groups while satisfying the 
    /// conditions is:
    /// Group 1 contains the number [0].
    /// It can be shown that the maximum number of groups is 1.
    /// So, the output is 1. 
    ///
    /// Constraints:
    /// 1. 1 <= usageLimits.length <= 10^5
    /// 2. 1 <= usageLimits[i] <= 10^9
    /// </summary>
    int maxIncreasingGroups(vector<int>& usageLimits);

    /// <summary>
    /// Leet Code 2802. Find The K-th Lucky Number
    /// 
    /// Medium
    ///
    /// We know that 4 and 7 are lucky digits. Also, a number is called lucky 
    /// if it contains only lucky digits.
    ///
    /// You are given an integer k, return the kth lucky number represented 
    /// as a string.
    /// 
    /// Example 1:
    /// Input: k = 4
    /// Output: "47"
    /// Explanation: The first lucky number is 4, the second one is 7, the 
    /// third one is 44 and the fourth one is 47.
    ///
    /// Example 2:
    /// Input: k = 10
    /// Output: "477"
    /// Explanation: Here are lucky numbers sorted in increasing order:
    /// 4, 7, 44, 47, 74, 77, 444, 447, 474, 477. So the 10th lucky number 
    /// is 477.
    ///
    /// Example 3:
    /// Input: k = 1000
    /// Output: "777747447"
    /// Explanation: It can be shown that the 1000th lucky number is 777747447.
    ///
    /// Constraints:
    /// 1. 1 <= k <= 10^9
    /// </summary>
    string kthLuckyNumber(int k);

    /// <summary>
    /// Leet Code 2806. Account Balance After Rounded Purchase
    /// 
    /// Easy
    ///
    /// Initially, you have a bank account balance of 100 dollars.
    ///
    /// You are given an integer purchaseAmount representing the amount you 
    /// will spend on a purchase in dollars.
    ///
    /// At the store where you will make the purchase, the purchase amount 
    /// is rounded to the nearest multiple of 10. In other words, you pay a 
    /// non-negative amount, roundedAmount, such that roundedAmount is a 
    /// multiple of 10 and abs(roundedAmount - purchaseAmount) is minimized.
    ///
    /// If there is more than one nearest multiple of 10, the largest multiple 
    /// is chosen.
    ///
    /// Return an integer denoting your account balance after making a 
    /// purchase worth purchaseAmount dollars from the store.
    ///
    /// Note: 0 is considered to be a multiple of 10 in this problem.
    /// 
    /// Example 1:
    /// 
    /// Input: purchaseAmount = 9
    /// Output: 90
    /// Explanation: In this example, the nearest multiple of 10 to 9 is 10. 
    /// Hence, your account balance becomes 100 - 10 = 90.
    ///
    /// Example 2:
    /// Input: purchaseAmount = 15
    /// Output: 80
    /// Explanation: In this example, there are two nearest multiples of 10 
    /// to 15: 10 and 20. So, the larger multiple, 20, is chosen.
    /// Hence, your account balance becomes 100 - 20 = 80.
    ///
    /// Constraints:
    /// 1. 0 <= purchaseAmount <= 100
    /// </summary>
    int accountBalanceAfterPurchase(int purchaseAmount);

    /// <summary>
    /// Leet 2818. Apply Operations to Maximize Score
    /// 
    /// Hard
    ///
    /// You are given an array nums of n positive integers and an integer k.
    ///
    /// Initially, you start with a score of 1. You have to maximize your 
    /// score by applying the following operation at most k times:
    ///
    /// Choose any non-empty subarray nums[l, ..., r] that you haven't chosen 
    /// previously.
    /// Choose an element x of nums[l, ..., r] with the highest prime score. 
    /// If multiple such elements exist, choose the one with the smallest 
    /// index.
    /// Multiply your score by x.
    /// Here, nums[l, ..., r] denotes the subarray of nums starting at index l 
    /// and ending at the index r, both ends being inclusive.
    ///
    /// The prime score of an integer x is equal to the number of distinct 
    /// prime factors of x. For example, the prime score of 300 is 3 since 
    /// 300 = 2 * 2 * 3 * 5 * 5.
    /// 
    /// Return the maximum possible score after applying at most k operations.
    ///
    /// Since the answer may be large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: nums = [8,3,9,3,8], k = 2
    /// Output: 81
    /// Explanation: To get a score of 81, we can apply the following 
    /// operations:
    /// - Choose subarray nums[2, ..., 2]. nums[2] is the only element in 
    ///   this subarray. Hence, we multiply the score by nums[2]. The score 
    ///   becomes 1 * 9 = 9.
    /// - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have 
    ///   a prime score of 1, but nums[2] has the smaller index. Hence, we 
    //    multiply the score by nums[2]. The score becomes 9 * 9 = 81.
    /// It can be proven that 81 is the highest score one can obtain.
    ///
    /// Example 2:
    /// Input: nums = [19,12,14,6,10,18], k = 3
    /// Output: 4788
    /// Explanation: To get a score of 4788, we can apply the following 
    /// operations: 
    /// - Choose subarray nums[0, ..., 0]. nums[0] is the only element in this 
    ///   subarray. Hence, we multiply the score by nums[0]. The score 
    ///   becomes 1 * 19 = 19.
    /// - Choose subarray nums[5, ..., 5]. nums[5] is the only element in this 
    ///   subarray. Hence, we multiply the score by nums[5]. The score 
    ///   becomes 19 * 18 = 342.
    /// - Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a 
    ///   prime score of 2, but nums[2] has the smaller index. Hence, we 
    ///   multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
    /// It can be proven that 4788 is the highest score one can obtain.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length == n <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// </summary>
    int maximumScore(vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 2833. Furthest Point From Origin
    /// 
    /// Easy
    ///
    /// You are given a string moves of length n consisting only of characters 
    /// 'L', 'R', and '_'. The string represents your movement on a number 
    /// line starting from the origin 0.
    ///
    /// In the ith move, you can choose one of the following directions:
    ///
    /// move to the left if moves[i] = 'L' or moves[i] = '_'
    /// move to the right if moves[i] = 'R' or moves[i] = '_'
    /// Return the distance from the origin of the furthest point you can get 
    /// to after n moves.
    ///
    /// Example 1:
    /// Input: moves = "L_RL__R"
    /// Output: 3
    /// Explanation: The furthest point we can reach from the origin 0 is 
    /// point -3 through the following sequence of moves "LLRLLLR".
    ///
    /// Example 2:
    /// Input: moves = "_R__LL_"
    /// Output: 5
    /// Explanation: The furthest point we can reach from the origin 0 
    /// is point -5 through the following sequence of moves "LRLLLLL".
    ///
    /// Example 3:
    /// Input: moves = "_______"
    /// Output: 7
    /// Explanation: The furthest point we can reach from the origin 0 is 
    /// point 7 through the following sequence of moves "RRRRRRR".
    ///
    /// Constraints:
    /// 1. 1 <= moves.length == n <= 50
    /// 2. moves consists only of characters 'L', 'R' and '_'.
    /// </summary>
    int furthestDistanceFromOrigin(string moves);

    /// <summary>
    /// Leet Code 2842. Count K-Subsequences of a String With Maximum Beauty
    /// 
    /// Hard
    ///
    /// You are given a string s and an integer k.
    ///
    /// A k-subsequence is a subsequence of s, having length k, and all its 
    /// characters are unique, i.e., every character occurs once.
    ///
    /// Let f(c) denote the number of times the character c occurs in s.
    ///
    /// The beauty of a k-subsequence is the sum of f(c) for every character 
    /// c in the k-subsequence.
    ///
    /// For example, consider s = "abbbdd" and k = 2:
    /// f('a') = 1, f('b') = 3, f('d') = 2
    /// Some k-subsequences of s are:
    /// "abbbdd" -> "ab" having a beauty of f('a') + f('b') = 4
    /// "abbbdd" -> "ad" having a beauty of f('a') + f('d') = 3
    /// "abbbdd" -> "bd" having a beauty of f('b') + f('d') = 5
    /// Return an integer denoting the number of k-subsequences whose beauty 
    /// is the maximum among all k-subsequences. Since the answer may be too 
    /// large, return it modulo 109 + 7.
    ///
    /// A subsequence of a string is a new string formed from the original 
    /// string by deleting some (possibly none) of the characters without 
    /// disturbing the relative positions of the remaining characters.
    ///
    /// Notes
    /// f(c) is the number of times a character c occurs in s, not a 
    /// k-subsequence.
    /// Two k-subsequences are considered different if one is formed by an 
    /// index that is not present in the other. So, two k-subsequences may 
    /// form the same string.
    ///
    /// Example 1:
    /// Input: s = "bcca", k = 2
    /// Output: 4
    /// Explanation: From s we have f('a') = 1, f('b') = 1, and f('c') = 2.
    /// The k-subsequences of s are: 
    /// bcca having a beauty of f('b') + f('c') = 3 
    /// bcca having a beauty of f('b') + f('c') = 3 
    /// bcca having a beauty of f('b') + f('a') = 2 
    /// bcca having a beauty of f('c') + f('a') = 3
    /// bcca having a beauty of f('c') + f('a') = 3 
    /// There are 4 k-subsequences that have the maximum beauty, 3. 
    /// Hence, the answer is 4. 
    ///
    /// Example 2:
    /// Input: s = "abbcd", k = 4
    /// Output: 2
    /// Explanation: From s we have f('a') = 1, f('b') = 2, f('c') = 1, 
    /// and f('d') = 1. 
    /// The k-subsequences of s are: 
    /// abbcd having a beauty of f('a') + f('b') + f('c') + f('d') = 5
    /// abbcd having a beauty of f('a') + f('b') + f('c') + f('d') = 5 
    /// There are 2 k-subsequences that have the maximum beauty, 5. 
    /// Hence, the answer is 2. 
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 2 * 10^5
    /// 2. 1 <= k <= s.length
    /// 3. s consists only of lowercase English letters.
    /// </summary>
    int countKSubsequencesWithMaxBeauty(string s, int k);

    /// <summary>
    /// Leet Code 2844. Minimum Operations to Make a Special Number
    /// 
    /// Medium
    ///
    /// You are given a 0-indexed string num representing a non-negative 
    /// integer.
    ///
    /// In one operation, you can pick any digit of num and delete it. Note 
    /// that if you delete all the digits of num, num becomes 0.
    ///
    /// Return the minimum number of operations required to make num special.
    ///
    /// An integer x is considered special if it is divisible by 25.
    ///  
    /// Example 1:
    /// Input: num = "2245047"
    /// Output: 2
    /// Explanation: Delete digits num[5] and num[6]. The resulting number 
    /// is "22450" which is special since it is divisible by 25.
    /// It can be shown that 2 is the minimum number of operations required 
    /// to get a special number.
    ///
    /// Example 2:
    /// Input: num = "2908305"
    /// Output: 3
    /// Explanation: Delete digits num[3], num[4], and num[6]. The resulting 
    /// number is "2900" which is special since it is divisible by 25.
    /// It can be shown that 3 is the minimum number of operations required 
    /// to get a special number.
    ///
    /// Example 3:
    /// Input: num = "10"
    /// Output: 1
    /// Explanation: Delete digit num[0]. The resulting number is "0" which 
    /// is special since it is divisible by 25.
    /// It can be shown that 1 is the minimum number of operations required 
    /// to get a special number.
    /// 
    /// Constraints:
    /// 1. 1 <= num.length <= 100
    /// 2. num only consists of digits '0' through '9'.
    /// 3. num does not contain any leading zeros.
    /// </summary>
    int minimumOperations(string num);

    /// <summary>
    /// Leet Code 2847. Smallest Number With Given Digit Product
    /// 
    /// Medium
    ///
    /// Given a positive integer n, return a string representing the smallest 
    /// positive integer such that the product of its digits is equal to n, 
    /// or "-1" if no such number exists.
    /// 
    /// Example 1:
    /// Input: n = 10^5
    /// Output: "357"
    /// Explanation: 3 * 5 * 7 = 105. It can be shown that 357 is the smallest 
    /// number with a product of digits equal to 105. So the answer would be 
    /// "105".
    ///
    /// Example 2:
    /// Input: n = 7
    /// Output: "7"
    /// Explanation: Since 7 has only one digit, its product of digits would 
    /// be 7. We will show that 7 is the smallest number with a product of 
    /// digits equal to 7. Since the product of numbers 1 to 6 is 1 to 6 
    /// respectively, so "7" would be the answer.
    ///
    /// Example 3:
    /// Input: n = 44
    /// Output: "-1"
    /// Explanation: It can be shown that there is no number such that its 
    /// product of digits is equal to 44. So the answer would be "-1".
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^18
    /// </summary>
    string smallestNumber(long long n);

    /// <summary>
    /// Leet Code 2849. Determine if a Cell Is Reachable at a Given Time
    /// 
    /// Medium
    ///
    /// You are given four integers sx, sy, fx, fy, and a non-negative 
    /// integer t.
    /// In an infinite 2D grid, you start at the cell (sx, sy). Each 
    /// second, you must move to any of its adjacent cells.
    ///
    /// Return true if you can reach cell (fx, fy) after exactly t seconds, 
    /// or false otherwise.
    ///
    /// A cell's adjacent cells are the 8 cells around it that share at 
    /// least one corner with it. You can visit the same cell several times.
    ///
    /// Example 1:
    /// Input: sx = 2, sy = 4, fx = 7, fy = 7, t = 6
    /// Output: true
    /// Explanation: Starting at cell (2, 4), we can reach cell (7, 7) in 
    /// exactly 6 seconds by going through the cells depicted in the 
    /// picture above. 
    ///
    /// Example 2:
    /// Input: sx = 3, sy = 1, fx = 7, fy = 3, t = 3
    /// Output: false
    /// Explanation: Starting at cell (3, 1), it takes at least 4 seconds to 
    /// reach cell (7, 3) by going through the cells depicted in the picture 
    /// above. Hence, we cannot reach cell (7, 3) at the third second.
    /// Constraints:
    /// 1. 1 <= sx, sy, fx, fy <= 10^9
    /// 2. 0 <= t <= 10^9
    /// </summary>
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t);

    /// <summary>
    /// Leet Code 2862. Maximum Element-Sum of a Complete Subset of Indices
    /// 
    /// Hard
    ///
    /// You are given a 1-indexed array nums of n integers.
    ///
    /// A set of numbers is complete if the product of every pair of its 
    /// elements is a perfect square.
    ///
    /// For a subset of the indices set {1, 2, ..., n} represented as 
    /// {i1, i2, ..., ik}, we define its element-sum as: nums[i1] + nums[i2] 
    /// + ... + nums[ik].
    ///
    /// Return the maximum element-sum of a complete subset of the indices 
    /// set {1, 2, ..., n}.
    ///
    /// A perfect square is a number that can be expressed as the product 
    /// of an integer by itself.
    ///
    /// Example 1:
    /// Input: nums = [8,7,3,5,7,2,4,9]
    /// Output: 16
    /// Explanation: Apart from the subsets consisting of a single index, 
    /// there are two other complete subsets of indices: {1,4} and {2,8}.
    /// The sum of the elements corresponding to indices 1 and 4 is equal 
    /// to nums[1] + nums[4] = 8 + 5 = 13.
    /// The sum of the elements corresponding to indices 2 and 8 is equal 
    /// to nums[2] + nums[8] = 7 + 9 = 16.
    /// Hence, the maximum element-sum of a complete subset of indices is 16.
    ///
    /// Example 2:
    /// Input: nums = [5,10,3,10,1,13,7,9,4]
    /// Output: 19
    /// Explanation: Apart from the subsets consisting of a single index, 
    /// there are four other complete subsets of indices: {1,4}, {1,9}, 
    /// {2,8}, {4,9}, and {1,4,9}.
    /// The sum of the elements conrresponding to indices 1 and 4 is equal 
    /// to nums[1] + nums[4] = 5 + 10 = 15.
    /// The sum of the elements conrresponding to indices 1 and 9 is equal 
    /// to nums[1] + nums[9] = 5 + 4 = 9.
    /// The sum of the elements conrresponding to indices 2 and 8 is equal 
    /// to nums[2] + nums[8] = 10 + 9 = 19.
    /// The sum of the elements conrresponding to indices 4 and 9 is equal 
    /// to nums[4] + nums[9] = 10 + 4 = 14.
    /// The sum of the elements conrresponding to indices 1, 4, and 9 is 
    /// equal to nums[1] + nums[4] + nums[9] = 5 + 10 + 4 = 19.
    /// Hence, the maximum element-sum of a complete subset of indices is 19.
    ///
    /// Constraints:
    /// 1. 1 <= n == nums.length <= 10^4
    /// 2. 1 <= nums[i] <= 10^9
    /// </summary>
    long long maximumSum(vector<int>& nums);
};
#endif
