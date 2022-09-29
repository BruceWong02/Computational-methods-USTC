
#include "../include/CoorCal.h"

extern double P[2];
extern double Q[2];
extern double T[2];
extern double R[2];

void GetCoor()
{
    printf("Please enter the x coordinate of P and coordinates of Q.\ne.g:\tQ: x y\n");

    // Get x coordinate of P.
    while (P[0] >= -1.)
    {
        printf("(Notice: Px < -1 !!!) P: ");
        scanf("%lf", P);
    }
    
    // Get coordinates of Q.
    while (Q[0] >= 0. || Q[1] <= 0. || (Q[0]*Q[0]+Q[1]*Q[1]) <= 1.)
    {
        printf("(Notice: Qx < 0 && Qy > 0 && r(Q) > 1 !!!) Q: ");
        scanf("%lf %lf", Q, &Q[1]);
    }
}

double dL(double theta)
{
    return -((P[0]*sin(theta)) / sqrt(P[0]*P[0]+2*P[0]*cos(theta)+1) + (Q[0]*sin(theta)+Q[1]*cos(theta)) 
                / sqrt(Q[0]*Q[0]+Q[1]*Q[1]+2*Q[0]*cos(theta)-2*Q[1]*sin(theta)+1));
}

void CalTQ(double theta1, double theta2)
{
    double theta3 = (theta1+theta2)/2.;

    // iteration
    while ((theta2 - theta1) > 0.000001)
    {   
        // when dL(theta3) == 0 means theta3 is extreme point.
        if (0. == dL(theta3))
        {
            break;
        }
        
        // determine the range of extreme point.
        else if ((dL(theta3)>0. && dL(theta2)>0.) || (dL(theta3)<0. && dL(theta2)<0.))
        {
            theta2 = theta3;
        }
        else
        {
            theta1 = theta3;
        }

        theta3 = (theta1+theta2)/2.;
    }
    
    // Calculate coordinates.
    T[0] = -cos(theta3);
    T[1] = sin(theta3);
    R[0] = ((Q[1]+Q[0]*tan(theta3))*(cos(theta3)+P[0]) - P[0]*sin(theta3)) 
            / (tan(theta3)*(cos(theta3)+P[0]) - sin(theta3));
    R[1] = (sin(theta3)*(P[0]-R[0])) / (cos(theta3)+P[0]);
}
