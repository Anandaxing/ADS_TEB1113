#include <iostream>
#include <vector>

void PrintMatrix(std::vector<int> the_matrix) {
  for(int i=0; i<the_matrix.size(); i++) {
    std::cout<<the_matrix[i]<<" ";
  }
}

std::vector<int> DiagonalTraversalMatrix(std::vector<std::vector<int>> the_matrix) {
  std::vector<int> result;
  int size_x = the_matrix[0].size();
  int size_y = the_matrix.size();
  int x, y;
  for(int i=0; i<size_y; i++) {
    y = i;
    x = 0;
    do {
      result.push_back(the_matrix[y][x]);
      y--;
      x++;
    } while(y>=0 && x<size_x);
  }

  for(int i=1; i<size_x; i++) {
    x = i;
    y = size_y-1;
    do {
      result.push_back(the_matrix[y][x]);
      y--;
      x++;
    } while (x<size_x);
  }

  return result;
}

int main() {
  std::vector<std::vector<int>> the_matrix = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16},
    {17,18,19,20}
  };
  std::vector<int> final_result = DiagonalTraversalMatrix(the_matrix);
  PrintMatrix(final_result);

  std::cin.get();
  return 0;
}