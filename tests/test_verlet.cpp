// Include a library file to make sure proper includes are set
#include "verlet.h"
#include <gtest/gtest.h>
#include "types.h"

TEST(IntegratorTest, SingleAtom) {
    double x = 1, y = 0, z = 0;
    double vx = 1, vy = 0, vz = 0;
    double fx = 1, fy = 0, fz = 0;
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


TEST(IntegratorTest, ConstantForce) {
    int nb_atoms = 4;
    // initialisation
    Positions_t positions(3, nb_atoms);
    Velocities_t velocities(3, nb_atoms);
    Forces_t forces(3, nb_atoms);
    Masses_t masses(nb_atoms);

    // setting random velocities
    positions.setRandom();
    velocities.setRandom();
    forces.setRandom();
    masses.setOnes();

    int nb_steps = 2;
    double timestep;
    timestep = 0.1;

    auto initial_positions{positions};
    auto initial_velocities{velocities};


    for (int i = 0; i < nb_steps; ++i) {

        verlet_step1(positions, velocities,
                     forces, masses, timestep);


        verlet_step2(velocities, forces, masses, timestep);

        auto analytical_velocities{initial_velocities + (forces.rowwise() / masses.transpose()) * (i + 1) * timestep};

        auto analytical_positions{initial_positions + initial_velocities * (i + 1) * timestep +
                                  0.5 * forces * ((i + 1) * timestep) *
                                  ((i + 1) * timestep)};


        for (int i{0}; i < nb_atoms; ++i) {
            for (int dim{0}; dim < 3; ++dim) {

                EXPECT_NEAR(velocities(dim, i),
                            analytical_velocities(dim, i), 1e-10);
                EXPECT_NEAR(positions(dim, i),
                            analytical_positions(dim, i), 1e-10);
            }
        }


    }
}