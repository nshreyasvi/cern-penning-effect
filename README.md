# Astrophysics Project Report
## Supervisor: Archana Sharma

## Aim: To find out Penning effect in ionized Argon Carbon-Dioxide gas mixture.

## Introduction:
Penning effect takes place when gases that have been supplied with electric field tend to acquire uneven charge which is distributed between two different gas molecules due to the difference in their nature. 
Garfield++ uses an electric field mesh in order to create a simulated environment for ionization of the gas and using that it determines the excitation and ionization rates for each of the collisions that take place between the different gas molecules. Using these ionization and excitation rates, gain curves are found which is used in order to find the transfer probability for the collisions and therefore the Penning effect. 

## The Problem: 
In the present version of garfield++, the transfer probability is kept constant in the program.
This causes an inaccuracy in finding out penning effect since the transfer probability changes for each collision and keeping it constant does not give accurate values for penning transfer.

## Project:
Initially, I carried out simulations for Argon-Carbon Dioxide gas mixture in which I kept the transfer probability to 0.61 under a custom electric field mesh which was changes for each simulation. Using that I obtained gas tables. However, due to inaccuracy in this method, I tried to find out ways in which we can find the gain curves from the gas table which can be used in order to find transfer probability for each of the collision and hence more accurate values of Penning transfer.
Upon discussion, there tends to be already a program made at CERN by which can be used to obtain gain curves which can give the transfer probabilities for each of the collisions. Hence, integrating the same would help in getting more accurate values. 
I then tried to print out gas tables with an electric and magnetic field mesh for Argon-Carbon Dioxide gas mixture that can be later on used up by the gain curve calculation program to get more accurate values.

## Conclusion:
Therefore, I carried out the simulations and got the gas tables as well as ionization and excitation rates for the mixture under the electric and magnetic field. 
Gas tables can be found in the file ar_93_co2_7.gas and ionization and excitation rates along with other data can be found in the file printed_results.gas here.
Apart from that, I edited the gem.C file in the examples section in order to make this program and the edited program can also be found in the same repository.

![Result](https://github.com/nshreyasvi/cern-penning-effect/blob/master/result_svg.svg)

## Results:
The results of ionization and excitation states can be used by the other program in order to find transfer probabilities for each collision and fetch those values to get the final penning transfer values for each of the collision.
