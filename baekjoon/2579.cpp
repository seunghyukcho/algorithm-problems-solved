// by Juyong Lee

#include <iostream>
#include <vector>


int main() {
   std::vector <int> stareScore, stareZero, stareOne;
   // An,1 = An-2,1 + score  vs. An-2,0 + score
   // An,0 = An-1,1 + score

   int numStare;
   std::cin >> numStare;

   for(int i = 0; i < numStare; i++){
      int score;
      std::cin >> score;
      stareScore.push_back(score);
   }

   stareOne.push_back(stareScore.at(0));
   stareZero.push_back(0);
   stareOne.push_back(stareScore.at(1));
   stareZero.push_back(stareOne.at(0) + stareOne.at(1));

   for (int i = 2; i < numStare; i++) {
      int score = stareScore.at(i);
      
      int tmp1 = stareOne.at(i - 2) + score;
      int tmp0 = stareZero.at(i - 2) + score;
      tmp1 > tmp0 ? stareOne.push_back(tmp1) : stareOne.push_back(tmp0);

      stareZero.push_back(stareOne.at(i - 1) + score);
   }

   int res1 = stareOne.at(numStare - 1);
   int res0 = stareZero.at(numStare - 1);
   
   res1 > res0 ? std::cout << res1 << std::endl : std::cout << res0 << std::endl;

   return 0;
}