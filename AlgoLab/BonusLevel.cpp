#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inBounds(int n, int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < n;
}

int solve(int n, vector<vector<int>>& shelves) {
  vector<vector<vector<int >>> state(2 * n - 1, vector<vector<int >>(n , vector<int >(n , 0))); 
  vector<vector<vector<bool>>> in_bounds(2 * n, vector<vector<bool>>(n + 1, vector<bool>(n + 2, false)));
  for (int d = 2 * n - 2; d >= 0; --d) {
    for (int x1 = 0; x1 < n; ++x1) {
      for (int x2 = 0; x2 < n; ++x2) {
        state[d][x1][x2] = 0;
        int y1 = d - x1;
        int y2 = d - x2;
        in_bounds[d][x1][x2] = y1 >= 0 && y1 < n && y2>=0 && y2<n;
      } 
    }
  }
  for (int d = 2 * n - 2; d >= 0; --d) {
    for (int x1 = 0; x1 < n; ++x1) {
      int y1 = d - x1;
      if (! (y1 >= 0 && y1 < n)) 
        continue; 
      for (int x2 = 0; x2 < n; ++x2) {
        int y2 = d - x2;
        if (! (y2 >= 0 && y2 < n)) 
          continue; 
        int m = 0;
        if (in_bounds[d + 1][x1][x2]) 
          m = max(m, state[d + 1][x1][x2]);
        if (in_bounds[d + 1][x1 + 1][x2]); 
          m = max(m, state[d + 1][x1 + 1][x2]);
        if (in_bounds[d + 1][x1][x2 + 1]) 
          m = max(m, state[d + 1][x1][x2 + 1]);
        if (in_bounds[d + 1][x1 + 1][x2 + 1]) 
          m = max(m, state[d + 1][x1 + 1][x2 + 1]);
        state[d][x1][x2] = shelves[x1][y1] + shelves[x2][y2] + m;
        if (x1 == x2 && y1 == y2) 
          state[d][x1][x2] -= shelves[x1][y1]; 
      }
    }
  }
  return state[0][0][0];
}  

int main() {
  ios_base::sync_with_stdio(false);
  int cases;
  cin >> cases;
  for (int c = 0; c < cases; ++c) {
    int n;
    cin >> n;
    vector<vector<int>> cs(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> cs[i][j];
      } 
    }
    cout << solve(n, cs) << endl;
  }
}