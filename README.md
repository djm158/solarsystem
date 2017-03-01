# solarsystem
Solar system simulation for ECE 1180

This projet is a simulation of of our solar system. It computes all necessary calculations in C, then renders the objects using visual python. 

## Build Environment
First, you'll need to install [VPython](http://vpython.org/) and [CodeBlocks](http://www.codeblocks.org/)
Setup instructions can be found [here](http://kona.ee.pitt.edu/1180wiki/doku.php?id=how_to_mix_c_and_python)


## Running the simulation
 #define TEST 1 will give you a simulation of the moon orbiting Earth.
You'll need to set DT to something like #define DT 1.0 in order to see anything interesting. Note that the larger DT, the greater error in the actual orbit calculations. 

![Image of full earth and moon](img/earthmoon.PNG?raw=true)

 #define TEST 2 will give you a simulation of all of the planets orbiting the sun.
You'll need to set DT to something like #define DT 100.0 in order to see anything interesting.

![Image of full solar system](img/solarsystem.PNG?raw=true)
