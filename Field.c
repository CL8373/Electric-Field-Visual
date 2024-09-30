
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 typedef struct {
     double x;
     double y;
     double charge;
    
} ChargePoint; 

 typedef struct {
     double x;
     double y;
} Force;

 Force calculateElectricfield(ChargePoint charge, double xpos, double ypos){
     Force force;
     double dx = xpos - charge.x;
     double dy = ypos - charge.y;
     double distance = sqrt(pow(dx, 2) + pow(dy, 2));
     if(distance == 0){
         force.x = 0;
         force.y = 0;
         return force;
     }
     double dangle = atan2(dy, dx);

     const double k = 9e9;
     double E = k * charge.charge / pow(distance, 2);
     force.x = E * cos(dangle);
     force.y = E * sin(dangle);
     return force;
}

int main() {
    ChargePoint charge1 = {200.0, 200.0, 0.000000001};
     Force force;
     force = calculateElectricfield(charge1, 300.0, 300.0);
     printf("x: %f, y: %f\n", force.x, force.y);
     return 0;
 }

