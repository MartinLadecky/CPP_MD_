#include "verlet.h"
#include "Eigen/Dense"




void verlet_step1(Positions_t &positions, Velocities_t &velocities,
                  const Forces_t &forces, const Masses_t &masses,  double timestep) {

    velocities += 0.5*(forces.rowwise()/masses.transpose())* timestep;
    positions += velocities * timestep;
}

void verlet_step2(Velocities_t &velocities, const Forces_t &forces, const Masses_t &masses, double timestep){
    velocities += (forces.rowwise()/masses.transpose())* timestep/2;

}




void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz,
                  double fx, double fy, double fz, double timestep) {

    vx += 0.5 * fx * timestep; // TODO{Martin} Where is mass?
    vy += 0.5 * fy * timestep;
    vz += 0.5 * fz * timestep;

    x += vx * timestep;
    y += vy * timestep;
    z += vz * timestep;
}

void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz,
                  double timestep) {

    vx += 0.5 * fx * timestep; // TODO{Martin} Where is mass?
    vy += 0.5 * fy * timestep;
    vz += 0.5 * fz * timestep;
}

