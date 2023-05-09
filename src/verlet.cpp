#include "verlet.h"

void verlet_step1(double &x, double &y, double &z, double &vx, double &vy, double &vz,
                  double fx, double fy, double fz, double timestep) {

    vx += 0.5 * fx * timestep; // TODO{Martin} Where is mass?
    vy += 0.5 * fy * timestep;
    vz += 0.5 * fz * timestep;

    x += vx * timestep;
    y += vy * timestep;
    z += vz * timestep;

    // ... implement Verlet step1 here ...
}

void verlet_step2(double &vx, double &vy, double &vz, double fx, double fy, double fz,
                  double timestep) {

    vx += 0.5 * fx * timestep; // TODO{Martin} Where is mass?
    vy += 0.5 * fy * timestep;
    vz += 0.5 * fz * timestep;
    //  ... implement Verlet step2 here ...
}

