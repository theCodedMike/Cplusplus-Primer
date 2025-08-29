//
// Created by lixia on 2025/8/27.
//

#ifndef CHAPTER6_H
#define CHAPTER6_H

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int fact(int val);
size_t count_calls();
long double fact_for(unsigned int);
long double fact_while(unsigned int);
void print_absolute_value(int, double);
tuple<int, int, int> test_local_var(int l);
int test_ret();
void reset_with_ptr(int *ip);
void reset_with_ref(int &val);
void swap(int *ip1, int *ip2);
void swap_with_ref(int &i1, int &i2);
string::size_type find_char(const string &s, char c, string::size_type &occurs);
bool is_sentence(const string &s);
bool have_upper_letter(const string &s);
void all_to_lower(string &s);
void print_2d_array(int (*matrix)[4], int row_size);
int my_max(int i1, const int *i2);
int factorial(int val);
auto is_shorter(const string &s1, const string &s2) -> bool;


#endif //CHAPTER6_H