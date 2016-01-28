#ifndef PLANETS_H_INCLUDED
#define PLANETS_H_INCLUDED

/* Define earth constants */
#define EARTH_MASS 5.97e24
#define EARTH_RAD  1737500.0
#define EARTH_S    149.6e9

/* Define moon constants */
#define MOON_E 3.78e8
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
