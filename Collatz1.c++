// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"
#include <map>
using namespace std;

// ------------
// collatz_read
// ------------
int cache[1000000];

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
  int max_num = 0;
  int max_compute = 0;
  for(int num=i; num<=j; num++)
    {
      int n = num;
      assert(n > 0);
      int c = 1;
      while ((n > 1) && (cache[n] == 0)) {
	if ((n % 2) == 0)
	  n = (n / 2);
	else
	  n = (3 * n) + 1;
	++c;
	max_compute ++;
      }
      assert(c > 0);
      if (cache[n] != 0 && n > 1)
	{
	  //	  cout << "c = " << c << " n = " << n << " cache ["<<num<<"] = " << cache[n] << " , " << cache[n]+c-1 <<endl;
	  c = c + cache[n] - 1;
	}
      max_num = c > max_num ? c : max_num;
            cache[num] = c;
      //      cout << "cache [ " << num << "] = " << cache[num] <<endl;

    }
  //  cout << " max_num = " << max_num << endl;
  cout << " max_compute = " << max_compute << endl;
  return max_num;
    // <your code>}
}
// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
