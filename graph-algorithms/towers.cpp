#include <iostream>

using namespace std;

class Towers{
   public : int attack(int my_units, int hp_t, int attack_t, int num_t)
    {
        int h = hp_t;
        int rounds = 0;
        int cur_units = my_units;
        while(cur_units > 0 && num_t > 0){
            h -= cur_units;
            if(h <= 0){
                h = hp_t;
                num_t--;
            }
            cur_units -= attack_t * num_t;
            rounds++;
        }
    if(curr_units <= 0) return -1;
    else return rounds;
    }
};

int main()
{
    return 0;
}
