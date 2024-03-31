#include <iostream>
#include <utility>
#include <time.h>

std::pair <int, int> random_walk(int n) {
    int x(0), y(0);
    std::vector<std::string> direction; 
    direction = {"N", "NW", "W", "SW", "S", "SE", "E", "NE"};
    for(int i = 0; i < n; ++i) {
        int r = rand() % 8;

        if (direction[r] == "N") {
            y += 1;
        } else if (direction[r] == "NW") {
            x -= 1;
            y += 1;
        } else if (direction[r] == "W") {
            x -= 1;
        } else if (direction[r] == "SW") {
            x -= 1;
            y -= 1;
        } else if (direction[r] == "S") {
            y -= 1;
        } else if (direction[r] == "SE") {
            x += 1;
            y -= 1;
        } else if (direction[r] == "E") {
            x += 1;
        } else if (direction[r] == "NE") {
            x += 1;
            y += 1;
        }
    }
    return {x, y};
}
int main() {
    srand (time(NULL));
    std::pair <int, int> p;
    int k(0), num_walks(100000);

    for (int i=1; i <= 30; ++i) {
        for(int j = 0; j < num_walks; ++j) {
            p = random_walk(i);

            if(p == std::make_pair(4, 4) || p == std::make_pair(-4, 4) || p == std::make_pair(-4, -4) || p == std::make_pair(4, -4)) {
                k+=1;
            }
        }
        std::cout << "Iteration #" << i << ": Panda falls for " << k << " times" << std::endl;
    }

    double total_walks = num_walks * 30;
    std::cout << "\nNumber of times that the panda ended up in holes = " << k << std::endl;
    std::cout << "\nProbability that the panda will get killed " << (k / total_walks)*100 << "%" << std::endl;

}
