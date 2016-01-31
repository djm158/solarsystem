/*
 * Daniel McGrath, University of Pittsburgh
 * Department of Electrical and Computer Engineering
 * ECE 1180 Project 4 - Planets in the solar system
 * 1/26/2016
 *
 * This program simulates the planets going around the sun
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "C:\Python32\include\Python.h"
#include "planets.h"
#include <math.h>

#define PYRUN(...) memset(cmd_str, 0, 256); sprintf(cmd_str,__VA_ARGS__); PyRun_SimpleString(cmd_str);

#define DT 100.0
#define GRAV_CONST 6.67408e-11
#define TEST 2

#if TEST == 1
#define NUMPLANETS 2
//enum PLANETS {EARTH, MOON};
#else
#define NUMPLANETS 4
enum PLANETS {SUN, MERCURY, VENUS, EARTH};
char * p_str[] = {"Sun", "Mercury", "Venus", "Earth"};
//#elseif TEST == 3
////#define NUMPLANETS 10
//enum PLANETS {SUN, MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO};
#endif // TEST

char cmd_str[256];
Planet planets[NUMPLANETS];

double dist3D(Planet A, Planet B)
{
    return sqrt(pow(A.X.x - B.X.x, 2.0) + pow(A.X.y - B.X.y, 2.0) + pow(A.X.z - B.X.z, 2.0));
}

// Simulation of just the earth and the moon
#if TEST == 1
void init_planets()
{
    planets[MOON].X.x = -1.453314099873231e8;//sqrt(2.0);
    planets[MOON].X.y = -3.448547959134183e8; //MOON_E/sqrt(2.0);
    planets[MOON].X.z = 1.511096967138130e7;
    planets[MOON].V.x = 9.317459241294277e2; //sqrt(300000.0);
    planets[MOON].V.y = -4.693570592280081e2;
    planets[MOON].V.z = -7.872259668570655e1;
    planets[MOON].mass = MOON_MASS;

    planets[EARTH].X.x = 0;
    planets[EARTH].X.y = 0;
    planets[EARTH].X.z = 0;
    planets[EARTH].V.x = 0;
    planets[EARTH].V.y = 0;
    planets[EARTH].V.z = 0;
    planets[EARTH].mass = EARTH_MASS;
}

void init_display()
{
    PYRUN("from visual import *\n");
	PYRUN("from visual.graph import *\n");
	PYRUN("scene1=display(autocenter = 0, autoscale = 1)\n");
	PYRUN("earth=sphere(pos=(%f, %f ,%f), radius=%f, material=materials.earth)\n", 0.0, 0.0, 0.0, EARTH_RAD*20);
	PYRUN("moon=sphere(pos=(%f, %f ,%f), radius=%f)\n", planets[MOON].X.x, 0.0, 0.0, MOON_RAD*20);
}
void update_display()
{
    PYRUN("moon.pos=(%f, %f, %f)\n", planets[MOON].X.x, planets[MOON].X.y, planets[MOON].X.z);
}

// simulation of the sun, mercury, venus, and earth
#else
void init_planets()
{
    planets[SUN].mass = SUN_MASS;
    planets[SUN].X.x  = 0;
    planets[SUN].X.y  = 0;
    planets[SUN].X.z  = 0;
    planets[SUN].V.x  = 0;
    planets[SUN].V.y  = 0;
    planets[SUN].V.z  = 0;

    planets[MERCURY].mass = MER_MASS;
    planets[MERCURY].X.x  = MER_START_X;
    planets[MERCURY].X.y  = MER_START_Y;
    planets[MERCURY].X.z  = MER_START_Z;
    planets[MERCURY].V.x  = MER_START_VX;
    planets[MERCURY].V.y  = MER_START_VY;
    planets[MERCURY].V.z  = MER_START_VZ;

    planets[VENUS].mass = VEN_MASS;
    planets[VENUS].X.x  = VEN_START_X;
    planets[VENUS].X.y  = VEN_START_Y;
    planets[VENUS].X.z  = VEN_START_Z;
    planets[VENUS].V.x  = VEN_START_VX;
    planets[VENUS].V.y  = VEN_START_VY;
    planets[VENUS].V.z  = VEN_START_VZ;

    planets[EARTH].mass = EARTH_MASS;
    planets[EARTH].X.x  = EARTH_START_X;
    planets[EARTH].X.y  = EARTH_START_Y;
    planets[EARTH].X.z  = EARTH_START_Z;
    planets[EARTH].V.x  = EARTH_START_VX;
    planets[EARTH].V.y  = EARTH_START_VY;
    planets[EARTH].V.z  = EARTH_START_VZ;

}

void init_display()
{
    PYRUN("from visual import *\n");
	PYRUN("from visual.graph import *\n");
	PYRUN("scene1=display(autocenter = 0, autoscale = 1)\n");
	PYRUN("sun=sphere(pos=(%f, %f ,%f), radius=%f, color=color.yellow)\n", 0.0, 0.0, 0.0, SUN_RAD*20);
	PYRUN("mercury=sphere(pos=(%f, %f ,%f), radius=%f, color=color.magenta, make_trail=True)\n", planets[MERCURY].X.x, planets[MERCURY].X.y, planets[MERCURY].X.z, MER_RAD*5000);
	PYRUN("venus=sphere(pos=(%f, %f ,%f), radius=%f, color=color.orange, make_trail=True)\n", planets[VENUS].X.x, planets[VENUS].X.y, planets[VENUS].X.z, VEN_RAD*1000);
	PYRUN("earth=sphere(pos=(%f, %f ,%f), radius=%f, material=materials.earth, make_trail=True)\n", planets[EARTH].X.x, planets[EARTH].X.y, planets[EARTH].X.z, EARTH_RAD*5000);
}

void update_display()
{
    PYRUN("mercury.pos=(%f, %f, %f)\n", planets[MERCURY].X.x, planets[MERCURY].X.y, planets[MERCURY].X.z);
    PYRUN("venus.pos=(%f, %f, %f)\n", planets[VENUS].X.x, planets[VENUS].X.y, planets[VENUS].X.z);
    PYRUN("earth.pos=(%f, %f, %f)\n", planets[EARTH].X.x, planets[EARTH].X.y, planets[EARTH].X.z);
}
#endif // TEST ==

void update_planets()
{
    double Ag;

    int i, j;
    for(i = 0; i < NUMPLANETS; i++)
    {
        planets[i].A.x = 0.0;
        planets[i].A.y = 0.0;
        planets[i].A.z = 0.0;
        for(j= 0; j < NUMPLANETS; j++)
        {
            if(i != j)
            {
                Ag = (GRAV_CONST * planets[j].mass) /(pow(dist3D(planets[i],planets[j]),3));

                /* Using direction cosines        */
                planets[i].A.x +=  -Ag * (planets[i].X.x - planets[j].X.x);
                planets[i].A.y +=  -Ag * (planets[i].X.y - planets[j].X.y);
                planets[i].A.z +=  -Ag * (planets[i].X.z - planets[j].X.z);
            }
        }
//        printf("%s: ax: %.20lf ay: %.20f az: %.20lf\n", p_strs[i], planets[i].A.x, planets[i].A.y, planets[i].A.z);
        planets[i].V.x +=  planets[i].A.x*DT; /* continuosly integrate a for v */
        planets[i].V.y +=  planets[i].A.y*DT;
        planets[i].V.z +=  planets[i].A.z*DT;

        planets[i].X.x +=  planets[i].V.x*DT; /* continuosly integrate v for x */
        planets[i].X.y +=  planets[i].V.y*DT;
        planets[i].X.z +=  planets[i].V.z*DT;
    }




}

int main()
{
    Py_Initialize();
    init_planets();
    init_display();
    while(1)
    {
        update_planets();
        update_display();
//        printf("moon x: %lf y: %lf z: %lf\n", planets[MOON].X.x, planets[MOON].X.y, planets[MOON].X.z);
//        printf("moon vx: %lf vy: %lf vz: %lf\n", planets[MOON].V.x, planets[MOON].V.y, planets[MOON].V.z);

//        PYRUN("earth.rotate(angle=pi/16, axis=(0,1,0), origin=earth.pos)\n");
        PYRUN("rate(100000)");
    }

    Py_Finalize();
    return 0;
}
