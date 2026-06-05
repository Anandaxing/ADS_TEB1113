// Rotating Matrix By Clock Wise
#include <iostream>
#include <vector>
#include <cmath>

void print(std::vector<int> layers) {
  for(int i=0;i<layers.size();i++) {
    std::cout<<layers[i]<<" ";
  }
  std::cout<<std::endl;
}

void print(std::vector<std::vector<int>> matrix) {
  for(int i=0;i<matrix.size();i++) {
    for(int j=0;j<matrix[i].size();j++) {
      std::cout<<matrix[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
}

std::vector<std::vector<int>> restructMatrix(std::vector<std::vector<int>> matrix, int row, int col) {
  std::vector<std::vector<int>> final_result;
  int result[row][col];
  int width = row;
  int height = col-2;

  for(int i=0; i<matrix.size(); i++) {
    // std::vector<int> temp;
    for(int j=0; j<width; j++) {
      result[i][j+i] = matrix[i][j];
    }

    for(int k=0; k<height; k++) {
      result[k+1][col-1-i] = matrix[i][k+width];
    }

    for(int l=width-1, z=0; l>=0; l--, z++) {
      result[row-i-1][l+i] = matrix[i][z+width+height];
    }

    for(int m=height-1, z=0; m>=0; m--, z++) {
      result[m+1][i] = matrix[i][z+width+height+width];
    }

    width -= 2;
    height -= 2;
  }

  for(int i=0;i<row;i++) {
    std::vector<int> the_row;
    for(int j=0;j<col;j++) {
      the_row.push_back(result[i][j]);
    }
    final_result.push_back(the_row);
  }

  return final_result;
}

void rotateMatrix(std::vector<std::vector<int>> matrix) {
  int row = matrix.size();
  int col = row;
  int layer_h = col-2;
  int layer_w = row;
  int x, y;
  int latest;

  // Layer that will be moving throughout the rotation
  int layer_tickness = (pow(-1, row+1)+1)*(row+1)/4 + (pow(-1, row)+1)*row/4;
  std::vector<std::vector<int>> layers;
  for(int i=0; i<layer_tickness; i++) {
    std::vector<int> temp_layer;
    for(int j=0; j<layer_w; j++) {
      temp_layer.push_back(matrix[i][j+i]);
      x = i;
      y = j+1;
    }
    
    for(int k=0; k<layer_h; k++) {
      temp_layer.push_back(matrix[k+1][col-1-i]);
    }
    
    for(int l=layer_w-1; l >= 0; l--) {
      temp_layer.push_back(matrix[row-1-i][l+i]);
      if(row-1-i==x && l+i==y) temp_layer.pop_back();
    }
    
    for(int m=layer_h-1; m >= 0; m--) {
      temp_layer.push_back(matrix[m+1][i]);
    }

    temp_layer.insert(temp_layer.begin(), temp_layer[temp_layer.size()-1]);
    temp_layer.pop_back();

    layers.push_back(temp_layer);
    layer_h -= 2;
    layer_w -= 2;
  }

  std::vector<std::vector<int>> result = restructMatrix(layers, row, col);
  print(result);
}

int main() {
  std::vector<std::vector<int>> matrix = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };

  std::vector<std::vector<int>> matrix2 = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  rotateMatrix(matrix);

  return 0;
}