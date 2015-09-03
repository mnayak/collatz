
#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <map>
//#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------
//int cache[851290];
int max_val = 851290;
map<int, int> cache_map;

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}


// ------------
// collatz_eval
// ------------
int recurse_val(int n){
  if (n == 1)
    return 1;
  /*
  if ((n <= max_val) && (cache[n] != 0)){
    return cache[n];
  }
  */

  if ((n <= max_val) && (cache_map.find(n) != cache_map.end())){
    return cache_map[n];
  }


  int num;
  if ((n % 2) == 0)
    num =  (n / 2);
  else
    num = (3 * n) + 1;
    
  int save_maxnum = 1 + recurse_val(num);

  if(n <= max_val)
    {
      //      cache[n] = save_maxnum;
      cache_map[n] = save_maxnum;
    }
  return save_maxnum;
}


// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
  int max_num = 0;
  for(int n=i; n<=j; n++)
    {
      assert(n > 0);
      int c;
      c = recurse_val(n);

      assert(c > 0);
      max_num = c > max_num ? c : max_num;

    }
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
        const int            v = collatz_eval(min(i, j), max(i,j));
        collatz_print(w, i, j, v);}}

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
