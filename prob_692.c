#include <iostream>

long can_win_by_taking(long total_pebbles, long max_allowed)
{
    if (total_pebbles > 0 && total_pebbles <= max_allowed) {
        return total_pebbles;
    }

    for (long i = 1; i <= max_allowed; ++i) {
        if (!can_win_by_taking(total_pebbles - i, i * 2)) {
            return i;
        }
    }

    return 0;
}


int main(void)
{
    long sum = 0;
    for (long i = 1; i <= 23416728348467685; ++i) {
        auto take = can_win_by_taking(i, i - 1);
        if (take == 0) {
            take = i;
        }
        sum += take;
    }
    std::cout << sum << std::endl;

    return 0;
}
