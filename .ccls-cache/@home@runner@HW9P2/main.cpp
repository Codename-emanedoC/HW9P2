#include <iomanip>
#include <iostream>
using namespace std;
void Grade8(double grade[5][8]);
void PrintMatrix(double grade[5][8]);
int main() {

  double grade[60][8] = {{1, 100, 100, 100, 100},
                         {2, 100, 0, 100, 0},
                         {3, 82, 94, 73, 86},
                         {4, 64, 74, 84, 94},
                         {5, 94, 84, 74, 64}};

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      grade[i][5] = (grade[i][1] + grade[i][2] + grade[i][3] + grade[i][4]) / 4;
      grade[i][6] = (grade[i][1] * .2) + (grade[i][2] * .3) +
                    (grade[i][2] * .3) + (grade[i][4] * .2);
    }
  }

  PrintMatrix(grade);
  Grade8(grade);

  return 0;
}

void Grade8(double grade[5][8]) {
  double locOfSmallest;
  for (int i = 0; i < 5; i++) {
    if (grade[i][1] <= grade[i][2] && grade[i][1] <= grade[i][3] &&
        grade[i][1] <= grade[i][4]) {
      locOfSmallest = 1;
    } else if (grade[i][2] <= grade[i][3] && grade[i][2] <= grade[i][4]) {
      locOfSmallest = 2;
    } else if (grade[i][3] <= grade[i][4]) {
      locOfSmallest = 3;
    } else {
      locOfSmallest = 4;
    }
    for (int j = 1; j < 5; j++) {
      if (j != locOfSmallest) {
        grade[i][7] += grade[i][j] / 3;
      }
    }
  }
  int row, col;
  for (row = 0; row < 5; row++) {
    for (col = 0; col < 8; col++)
      cout << setw(6) << grade[row][col] << " ";

    cout << endl;
  }
}

void PrintMatrix(double grade[5][8]) {

  for (int i = 0; i < 5; i++) {
    cout << "Regular Average GPA for student: " << (i + 1) << " = "
         << grade[i][5] << endl;
  }

  for (int i = 0; i < 5; i++) {
    cout << "Weighted GPA for student: " << (i + 1) << " = " << grade[i][6]
         << endl;
  }
}