# Simple-IoT-Network-Simulation---Greenhouse-Monitoring
This project involves simulating a simple IoT-based greenhouse monitoring system using OMNeT++. The simulation models a network of wireless sensor nodes, a gateway, and a user interface (farmer’s computer). The goal is to evaluate the system’s performance, energy efficiency, and data transmission delay.

The project is divided into two parts:

Part 1: Models the basic greenhouse sensor network.
Part 2: Extends the system with new sensors, a second gateway, and a router.

# Simulation Details
Part 1: Basic IoT Model
Five sensors monitor air humidity, temperature, soil moisture, and temperature.
Wireless communication to a gateway, then to the farmer’s computer.
Goal: Measure system runtime before sensor shutdown.
Part 2: Extended Model
New sensors (better accuracy, higher energy use).
Additional gateway + router for scalability.
Wireless delay modeling.
Goals:
Optimize wakeup cycles for 4-week battery life.
Determine ideal battery capacity.
Analyze transmission delays.

#How to Run
Requirements 

OMNeT++ (v5.6+), Python, matplotlib.

\
Clone repo & navigate

Run simulation in OMNeT++.
Analyze results (energy trends, delays, sensor lifespan).
