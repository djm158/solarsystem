#ifndef PLANETS_H_INCLUDED
#define PLANETS_H_INCLUDED

/*
 * This file defines the mass and radius
 * of each of the planets to be simulated.
 * It also defines two structs, a three dimensional
 * vector and a planet object containing mass, position,
 * velocity, and acceleration information.
 *
 * All defined constants were taken from JPL's HORIZONS
 * http://ssd.jpl.nasa.gov/horizons.cgi
 *
 * The initial position and velocities of the planets
 * occur on 03/15/2020
 */

/* define sun constants */
#define SUN_MASS 1.988544e30
#define SUN_RAD  6.963e8

/* define mercury constants */
#define MER_MASS      3.302e23
#define MER_RAD       1600000.0
#define MER_START_X  -4.890204690531221e10
#define MER_START_Y  -4.543426862243970e10
#define MER_START_Z   7.733667958471943e8
#define MER_START_VX  2.322727977229309e4
#define MER_START_VY -3.348348119939182e4
#define MER_START_VZ -4.866833510213040e3

/* define venus constants */
#define VEN_MASS      48.685e23
#define VEN_RAD       6051000.8
#define VEN_START_X   -5.870838049404506e10
#define VEN_START_Y    8.991759385480268e10
#define VEN_START_Z    4.621677192737333e09
#define VEN_START_VX  -2.944345452770062e04
#define VEN_START_VY  -1.933832561370903e04
#define VEN_START_VZ   1.433740626542120e03

/* define earth constants */
#define EARTH_MASS       5.97e24
#define EARTH_RAD        1737500.0
#define EARTH_START_X   -1.481065922576207e11
#define EARTH_START_Y    1.401854123205519e10
#define EARTH_START_Z   -4.431806373577565e05
#define EARTH_START_VX  -3.303698235596289e03
#define EARTH_START_VY  -2.976285555872579e4
#define EARTH_START_VZ   2.330959433210822e2

/* define mars constants */
#define MARS_MASS       6.4185e23
#define MARS_RAD        3389900.0
#define MARS_START_X   -7.132311648722184e10
#define MARS_START_Y   -2.123434077457961e11
#define MARS_START_Z   -2.699498644668877e9
#define MARS_START_VX   2.388311374565992e4
#define MARS_START_VY  -5.633170880466154e3
#define MARS_START_VZ  -7.039971694277738e2

/* define jupiter constants */
#define JUP_MASS       1898.13e24
#define JUP_RAD        71492000
#define JUP_START_X    1.602947613244428e11
#define JUP_START_Y   -7.612877634976143e11
#define JUP_START_Z   -4.243802877326608e8
#define JUP_START_VX   1.264029683026608e4
#define JUP_START_VY   3.311894265637413e3
#define JUP_START_VZ  -2.965951867133042e2

/* define saturn constants */
#define SAT_MASS       5.68319e26
#define SAT_RAD        60268000.0
#define SAT_START_X    6.214245109878402e11
#define SAT_START_Y   -1.365154321370484e12
#define SAT_START_Z   -1.000252085554659e9
#define SAT_START_VX   8.271189307591397e3
#define SAT_START_VY   3.977405683344818e3
#define SAT_START_VZ  -3.978456439344353e2

/* define constants for uranus */
#define URA_MASS     86.8103e24
#define URA_RAD      25559000.0
#define URA_START_X  2.401804590186682e12
#define URA_START_Y  1.735735030250998e12
#define URA_START_Z  -2.466252900986159e10
#define URA_START_VX  -4.027250324719235e3
#define URA_START_VY  5.205142926704514e3
#define URA_START_VZ  7.108708897247795e1

/* define neptune constants */
#define NEP_MASS       102.41e24
#define NEP_RAD        24766000
#define NEP_START_X    4.381776442113614e12
#define NEP_START_Y   -9.182998086709845e11
#define NEP_START_Z   -8.208486611191589e10
#define NEP_START_VX   1.092577928973806e3
#define NEP_START_VY   5.357518270098838e3
#define NEP_START_VZ  -1.353976885482078e2

/* define moon constants */
#define MOON_E 3.84e8
#define MOON_RAD 869050.0
#define MOON_MASS 7.3e22

typedef struct v
{
    double x, y, z;
} Vect;

typedef struct p
{
    Vect   X;
    Vect   V;
    Vect   A;
    char * color;
    double mass;
} Planet;
#endif // PLANETS_H_INCLUDED
