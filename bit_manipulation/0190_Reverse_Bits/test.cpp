#include <string>
#include <iostream>
#include <vector>
#include <ctime> // https://man7.org/linux/man-pages/man3/clock.3.html
#include <iterator>
#include "solution.cpp"
#include <sstream>
#include <cstdint>

using namespace std;

const char *toString(vector <int> v) {
    stringstream ss;
    copy(v.begin(), v.end(), ostream_iterator<int>(ss, " "));
    return ss.str().c_str();
}

int main(void) {
    vector<uint32_t> nums = {0b00000010100101000001111010011100, 0b11111111111111111111111111111101};
    vector<uint32_t> expected = {0b00111001011110000010100101000000, 0b10111111111111111111111111111111};

    for (int i = 0; i < expected.size(); i++) {
        clock_t start = clock();
        Solution s;
        uint32_t res = s(nums[i]);
        double elapsedTime = (clock() - start);

        printf("%s  \033[30m(%4.0lf cycles)\033[0m\t %d -> %d\n", (expected[i] == res) ? "\033[34mOK" : "\033[31mKO", elapsedTime, res, expected[i]);
    }
    return 0;
}