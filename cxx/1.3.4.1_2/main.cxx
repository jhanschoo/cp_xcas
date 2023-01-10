#include <bits/stdc++.h>
#include <range/v3/all.hpp>

namespace {
    using ll = long long;
    using ull = unsigned long long;
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // note: cin precision specifications round
    auto prec = std::streamsize{};
    std::cin >> prec;

    std::cout.precision(prec);

    std::cout << std::numbers::pi << std::endl;
}