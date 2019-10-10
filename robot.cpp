#include "robot.h"
#include <iostream>
#include <eigen3/Eigen/Dense>

Robot::Robot(double _x, double _y, double _theta, std::string _name)
  : x(_x), y(_y), theta(_theta), name(_name)
{}

void Robot::printPosition()
{
  std::cout << name << " is at (" << x << ", " << y << ", " << theta << ")\n"          ;
}

double Robot::bigComputation(uint n, const uint dim)
{
  double r = 0;
  Eigen::MatrixXd M;
  Eigen::VectorXd v;
  M.resize(dim, dim);
  v.resize(dim);
  for(uint k = 0; k < n; ++k)
  {
    M.Random();
    v.Random();
    r += M.colPivHouseholderQr().solve(v).norm();
  }
  return r;
}
