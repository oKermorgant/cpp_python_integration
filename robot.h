#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <iostream>

class Robot
{
public:
  Robot(double _x=0, double _y=0, double _theta=0, std::string _name="my robot");

  void printPosition();
  
  double bigComputation(uint n, const uint dim);

private:
  double x,y,theta;
  std::string name;
};

#endif // MYCLASS_H
