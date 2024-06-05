#include <algorithm>
#include <iostream>
#include <string>

void DrawBoards(std::string play[]) {
  std::cout << play[0] << "|" << play[1] << "|" << play[2] << std::endl;
  std::cout << "-----" << "|" << "-----" << "|" << "-----" << std::endl;
  std::cout << play[3] << "|" << play[4] << "|" << play[5] << std::endl;
  std::cout << "-----" << "|" << "-----" << "|" << "-----" << std::endl;
  std::cout << play[6] << "|" << play[7] << "|"  << play[8] << std::endl;

}

void MovePlayer(std::string boards[]) {
  std::string position;
  std::cin >> position;
  position.erase(std::remove(position.begin(), position.end(), ' '), position.end());
  int positionNum = std::stoi(position);
  boards[positionNum] = "  x  ";
}

int main() {
  std::string boards[9] = {"     ", "     ", "     ", "     ", "     ", "     ", "     ", "     ", "    "};
  MovePlayer(boards);
  DrawBoards(boards);
  return 0;
}
