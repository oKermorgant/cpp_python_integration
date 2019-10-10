#include "robot.h"

int main(int argc, char ** argv)
{
    uint n = atoi(argv[1]);
    uint dim = atoi(argv[2]);
    
    Robot robot;
    
    robot.bigComputation(n, dim);
    
}
