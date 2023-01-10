#include <bits/stdc++.h>

namespace {
    using ll = long long;
    using ull = unsigned long long;
}

int main(int argc, char *argv[]) {
    auto n = ll{};
    auto ns = std::set<ll>{};
    while (std::cin >> n) {
        ns.insert(n);
    }
    for (auto const &nn : ns) {
        std::cout << nn << ' ';
    }
}
