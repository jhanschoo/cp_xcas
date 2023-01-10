#include <bits/stdc++.h>
#include <boost/date_time.hpp>

namespace {
    using ll = long long;
    using ull = unsigned long long;
}

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    auto facet = boost::date_time::date_input_facet<boost::gregorian::date, char>{"%F"};
    std::cin.imbue(std::locale{std::locale{}, &facet});
    // note: we assume utc for today
    auto d = boost::gregorian::date{}, today = boost::gregorian::day_clock::universal_day();
    std::cin >> d;
    {
        auto dow = d.day_of_week();
        std::cout << dow.as_long_string() << std::endl;
    }
    {
        auto dd = today - d;
        std::cout << dd.days() << std::endl;
    }
}
