#include <string>
#include <iostream>
#include <vector>
#include <ctime> // https://man7.org/linux/man-pages/man3/clock.3.html
#include <iterator>
#include "solution.cpp"
#include <sstream>
#include <cstdint>
#include <stdbool.h>

#define bool char

using namespace std;

const char *toString(vector <int> v) {
    stringstream ss;
    copy(v.begin(), v.end(), ostream_iterator<int>(ss, " "));
    return ss.str().c_str();
}

int main(void) {
    vector<int> nums = {2, 5};
    vector<vector<int>> expected = {{0,1,1}, {0,1,1,2,1,2}};

    for (int i = 0; i < expected.size(); i++) {
        clock_t start = clock();
        Solution s;
        vector<int> res = s(nums[i]);
        double elapsedTime = (clock() - start);

        printf("%s  \033[30m(%4.0lf cycles)\033[0m\t %s -> %s\n", (expected[i] == res) ? "\033[34mOK" : "\033[31mKO", elapsedTime, toString(res), toString(expected[i]));
    }
    return 0;
}