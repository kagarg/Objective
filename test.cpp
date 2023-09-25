#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "Header.h"

bool equal(const double& x, const double& y) {
    if (abs(x - y) <= 0.001) {
        return true;
    }
    else return false;
}

TEST_CASE("standart distribution") {
    LaplaceDistribution distr;
    CHECK(density(distr, 0) == 0.5);
    CHECK(expected_value(distr) == 0);
    CHECK(dispersion(distr) == 2);
    CHECK(asymmetry(distr) == 0);
    CHECK(kurtosis(distr) == 3);
}

TEST_CASE("shift scale transformation") {
    LaplaceDistribution distr;
    distr.lambda = 2;
    distr.mu = 2;
    CHECK(equal(density(distr, 0), 0.091) == true);
    CHECK(expected_value(distr) == 2);
    CHECK(dispersion(distr) == 8);
    CHECK(asymmetry(distr) == 0);
    CHECK(kurtosis(distr) == 3);
}

TEST_CASE("mixture distribution") {
    MixtureDistribution distr;
    distr.LD1.lambda = 2;
    distr.LD2.lambda = 2;
    distr.LD1.mu = 2;
    distr.LD2.mu = 2;
    CHECK(equal(mixtr_density(distr, 0), 0.091) == true);
    CHECK(mixtr_expected_value(distr) == 2);
    CHECK(mixtr_dispersion(distr) == 8);
    CHECK(mixtr_asymmetry(distr) == 0);
    CHECK(equal(mixtr_kurtosis(distr), 2.953) == true);
}

TEST_CASE("mixture distribution expected") {
    MixtureDistribution distr;
    distr.LD1.lambda = 2;
    distr.LD2.lambda = 2;
    distr.LD1.mu = 1;
    distr.LD2.mu = 2;
    CHECK(mixtr_expected_value(distr) == 1.5);
}

TEST_CASE("mixture distribution dispersion") {
    MixtureDistribution distr;
    distr.LD1.lambda = 1;
    distr.LD2.lambda = 3;
    CHECK(mixtr_dispersion(distr) == 10);
}
