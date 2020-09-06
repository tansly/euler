#include <iostream>

constexpr auto log10_of_2 = 0.3010299956639812;
constexpr auto lower_bound = 0.089905111439396;
constexpr auto upper_bound = 0.093421685162234;


int main(void)
{
    auto n = 0ul;
    auto power = 0ul;
    auto fractional_part = 0.0;
    while (n < 678910) {
        ++power;

        fractional_part += log10_of_2;
        if (fractional_part > 1.0) {
            fractional_part -= 1.0;
        }

        if (fractional_part > lower_bound && fractional_part < upper_bound) {
            ++n;
        }
    }

    std::cout << power << std::endl;

    return 0;
}
