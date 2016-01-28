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

#define DT 0.01
#define GRAV_CONST 6.67408e-11
#define TEST 1
#if TEST == 1
#define NUMPLANETS 2
enum PLANETS {EARTH, MOON};
#else
#define NUMPLANETS 10
enum PLANETS {SUN, MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO};
#endif // TEST

char cmd_str[256];
Planet planets[NUMPLANETS];

double dist3D(Planet A, Planet B)
{
    return sqrt(pow(A.X.x - B.X.x, 2.0) + pow(A.X.y - B.X.y, 2.0) + pow(A.X.z - B.X.z, 2.0));
}
void init_planets()
{
    planets[MOON].X.x = MOON_E;
    planets[MOON].X.y = 0;
    planets[MOON].X.z = 0;
    planets[MOON].V.x = sqrt(500.0);
    planets[MOON].V.y = sqrt(500.0);
    planets[MOON].V.z = 0;
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
	PYRUN("earth=sphere(pos=(%f, %f ,%f), radius=%f, material=materials.earth)\n", 0.0, 0.0, 0.0, EARTH_RAD*30);
	PYRUN("moon=sphere(pos=(%f, %f ,%f), radius=%f, material=materials.bricks)\n", planets[MOON].X.x, 0.0, 0.0, MOON_RAD*30);
}

void update_planets()
{
    double Ag;

    int i, j;
    for(i = 0; i < NUMPLANETS; i++)
    {
        for(j= 0; j < NUMPLANETS; j++)
        {
            if(i != j)
            {
                Ag = (GRAV_CONST * planets[j].mass) /(pow(dist3D(planets[i],planets[j]),3));

                /* Using direction cosines http://en.wikipedia.org/wiki/Direction_cosines */
                planets[i].A.x +=  -Ag * (planets[i].X.x - planets[j].X.x);
                planets[i].A.y +=  -Ag * (planets[i].X.y - planets[j].X.y);
                planets[i].A.z +=  -Ag * (planets[i].X.z - planets[j].X.z);
            }
        }
        planets[i].V.x +=  planets[i].A.x*DT; /* continuosly integrate a for v */
        planets[i].V.y +=  planets[i].A.y*DT;
        planets[i].V.z +=  planets[i].A.z*DT;

        planets[i].X.x +=  planets[i].V.x*DT; /* continuosly integrate v for x */
        planets[i].X.y +=  planets[i].V.y*DT;
        planets[i].X.z +=  planets[i].V.z*DT;
    }




}

void update_display()
{
    PYRUN("moon.pos=(%f, %f, %f)\n", planets[MOON].X.x, planets[MOON].X.y, planets[MOON].X.z);
}

int main()
{
    Py_Initialize();
    init_planets();
    init_display();
    double axis = 0.0;
    while(1)
    {
        update_planets();
        update_display();
        printf("moon - x: %lf y: %lf z: %lf\n", planets[MOON].X.x, planets[MOON].X.y, planets[MOON].X.z);
        PYRUN("earth.rotate(angle=pi/16, axis=(0,1,0), origin=earth.pos)\n");
        PYRUN("rate(1000)");
    }

    Py_Finalize();
    return 0;
}
