// Include a library file to make sure proper includes are set
#include "verlet.h"
#include <gtest/gtest.h>

//// Demonstrate some basic assertions.
//TEST(HelloTest, BasicAssertions) {
//    // Expect two strings not to be equal.
//    EXPECT_STRNE("hello", "world");
//    // Expect equality.
//    EXPECT_EQ(7 * 6, 42);
//    // Testing if we can call a function from our MD library
//    hello_eigen();
//}
//
TEST(IntegratorTest, BasicAssertions) {
    double x = 1;
    double y = 0;
    double z = 0;
    double vx = 1;
    double vy = 0;
    double vz = 0;
    double fx = 1;
    double fy = 0;
    double fz = 0;
    double timestep = 0.1;

    // Expect equality.
    EXPECT_EQ(fx, vx);
    int nb_steps = 2;

    for (int i = 0; i < nb_steps; ++i) {
        std::cout << "Step: " << i << std::endl;

        std::cout << "x : " << x << std::endl;
        std::cout << "y : " << y << std::endl;
        std::cout << "z : " << z << std::endl;

        std::cout << "vx: " << vx << std::endl;
        std::cout << "vy: " << vy << std::endl;
        std::cout << "vz: " << vz << std::endl;

        std::cout << "fx: " << fx << std::endl;
        std::cout << "fy: " << fy << std::endl;
        std::cout << "fz: " << fz << std::endl;

        verlet_step1(x, y, z, vx, vy, vz,
                     fx, fy, fz, timestep);

//    TODO[Martin]
//        compute
//        forces
//        here ...
        verlet_step2(vx, vy, vz,
                     fx, fy, fz, timestep);


    }
}
// Testing if we can call a function from our MD library
//    hello_eigen();
//}
//
//for (int i = 0; i < nb_steps; ++i) {
//std::cout << "Step: " << i << std::endl;
//verlet_step1(args...);
//... compute forces here ...
//        verlet_step2(args...);
//}