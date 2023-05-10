//
// Created by martin on 10/05/23.
//

#ifndef MY_MD_CODE_TYPES_H
#define MY_MD_CODE_TYPES_H

#include <Eigen/Dense>

using Positions_t = Eigen::Array3Xd; // po (coord_xyz,nb_atoms) [dim, N]
using Velocities_t = Eigen::Array3Xd; // po (coord_xyz,nb_atoms) [dim, N]
using Forces_t = Eigen::Array3Xd; // po (coord_xyz,nb_atoms) [dim, N]
using Masses_t = Eigen::ArrayXd; // po (nb_atoms) [N, 1]




#endif //MY_MD_CODE_TYPES_H
