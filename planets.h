#ifndef PLANETS_H_INCLUDED
#define PLANETS_H_INCLUDED

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
