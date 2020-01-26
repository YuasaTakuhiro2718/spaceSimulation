#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <array>
#include <random>
#include <cmath>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <gnuplot.hpp>
#include <N-Body.hpp>

int main()
{
    N_Body body;
    body.set_randomValue();
    body.Initial_calibration();
    body.VelocityVerlet_initialStep();
    
    for(int i = 0;i<300;i++)
    {
        body.VelocityVerlet_calculate();
        std::cout << i << std::endl;
    }
    
    
    return 0;
    
    Gnuplot gp3;
    gp3 << "set term png";
    gp3 << "set output \"star,dt=0.001,N=2000,3d.png\"";
    gp3 << "set view equal xyz";
    gp3 << "set ticslevel 0";
    
    Gnuplot gp2;
    gp2 << "set term png";
    gp2 << "set output \"star,dt=0.001,N=2000,2d,x_y.png\"";
    gp2 << "set view equal xyz";
    gp2 << "set ticslevel 0";
    
    Gnuplot gp1;
    gp1 << "set term png";
    gp1 << "set output \"star,dt=0.001,N=2000,2d,x_z.png\"";
    gp1 << "set view equal xyz";
    gp1 << "set ticslevel 0";
    
    Gnuplot gp5;
    gp5 << "set term gif animate";
    gp5 << "set output \"star,dt=0.001,N=2000,3d.gif\"";
    gp5 << "set view equal xyz";
    gp5 << "set ticslevel 0";
    
    Gnuplot gp4;
    gp4 << "set term gif animate";
    gp4 << "set output \"star,dt=0.001,N=2000,2d,curve_make.gif\"";
    gp4 << "set view equal xyz";
    gp4 << "set ticslevel 0";
    
    Gnuplot gp6;
       gp6 << "set term gif animate";
       gp6 << "set output \"star,dt=0.001,N=2000,2d,curve_make_difference.gif\"";
       gp6 << "set view equal xyz";
       gp6 << "set ticslevel 0";
    Dark_Matar_Halo Dark_Mater;
    
    for(int i = 0;i<300;i++)
    {
        body.VelocityVerlet_calculate();
    }
    
    double sphere_pos = 5;
    
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<1;j++)
        {
            body.position[i][j] += sphere_pos;
        }
    }
    body.position[0][0] = sphere_pos;
    body.position[0][1] = 0;
    body.position[0][2] = 0;
    body.velocity[0][0] = 0;
    body.velocity[0][1] = 0;
    body.velocity[0][2] = 0;
    
    double save[1000][3];
    
    body.VelocityVerlet_initialStep_withObject(Dark_Mater);
    for(int i = 0;i<10000;i++)
    {
        if(i%10 == 0)
        {
            double pos[3] = {body.position[0][0],body.position[0][1],body.position[0][2]};
            
            gp3 << "set title \"t = "+std::to_string(dt*i)+"\"";
            gp3 << "splot[-10:10][-10:10][-10:10] \"-\" with lines";
            gp3 << std::to_string(pos[0])+", "+std::to_string(pos[1])+", "+std::to_string(pos[2]);
            
            gp2 << "set title \"t = "+std::to_string(dt*i)+"\"";
            gp2 << "plot[-10:10][-10:10] \"-\" with lines";
            gp2 << std::to_string(pos[0])+", "+std::to_string(pos[1]);
            
            gp1 << "set title \"t = "+std::to_string(dt*i)+"\"";
            gp1 << "plot[-10:10][-10:10] \"-\" with lines";
            gp1 << std::to_string(pos[0])+", "+std::to_string(pos[2]);
            
            gp5 << "set title \"t = "+std::to_string(dt*i)+"\"";
            gp5 << "plot[-10:10][-10:10] \"-\" with lines";
            gp5 << std::to_string(pos[0])+", "+std::to_string(pos[2]);
            gp5 << "e";
            
            gp4 << "set title \"t = "+std::to_string(dt*i)+"\"";
            gp4 << "plot[-10:10][-10:10] \"-\" with lines";
            
            gp6 << "set title \"t = "+std::to_string(dt*i)+"\"";
            gp6 << "plot[-10:10][-10:10] \"-\" with lines";
            
            save[i/10][0] = body.position[0][0]; save[i/10][1] = body.position[0][2]; save[i/10][2] = body.position[0][1];
            
            
            for(int k = 0;k<i/10+1;k++)
            {
                gp4 << std::to_string(save[k][0])+", "+std::to_string(save[k][1]);
                gp6 << std::to_string(save[k][0])+", "+std::to_string(save[k][2]);
            }
            
            gp4 << "e";
            gp6 << "e";
        }
        
        body.VelocityVerlet_calculate_withObject(Dark_Mater);
        
        std::cout << i << std::endl;
    }
    gp1 << "e";
    gp2 << "e";
    gp3 << "e";
}

