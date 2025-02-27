//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 
#include "Sensor.h"  // Including the header file for Sensor module
#include "SensorMessage_m.h"  // Including the header file for SensorMessage module
#include <string>  // Including the C++ string library

Define_Module(Sensor);  // Defining the Sensor module using OMNeT++ macros

void Sensor::initialize()
{
    int greenHouseID = getParentModule()->par("greenHouseID");
    if (greenHouseID==0){
        sensingMargin = 5;  // 5% sensing margin
        energyUsedPerCycleMin = 0.5;
        energyUsedPerCycleMax = 0.7;
        energyLevelStart = 10000;
        wirelessDelayMin = 120;
        wirelessDelayMax = 150;
    }
    else{
        sensingMargin = 1;  // 5% sensing margin
        energyUsedPerCycleMin = 0.9;
        energyUsedPerCycleMax = 1.2;
        energyLevelStart = 50000;
        wirelessDelayMin = 80;
        wirelessDelayMax = 100;

    }

    double sensorStartTime = par("sensorStartTime").doubleValue();
    scheduleAt(simTime()+sensorStartTime, new cMessage("Start"));


    double mindelay=wirelessDelayMin;
    double maxdelay=wirelessDelayMax;
    double min=energyUsedPerCycleMin;
    double max=energyUsedPerCycleMax;
    batterylevel = energyLevelStart;
    transmissionDelay=uniform(mindelay,maxdelay)*.001;
    EV<<"transmissionDelay  "<<transmissionDelay;
    energyUsedPerCycle = uniform(min, max); // Assigning a random value within the range [0.5, 0.7) to energyUsedPerCycle
//energyUsedSignal = registerSignal("batterylevel");  // Registering a signal named 'energyUsed'
    transmission_delay_=registerSignal("total_transmission_delay");
    sensingInterval = uniform(10, 11);  // Assigning a random sensing interval within the range [10, 11)
    // TODO - Generated method body (Placeholder for future implementation or code)
}

void Sensor::handleMessage(cMessage *msg)
{
    if (strcmp(msg->getName(), "Start") == 0) {// Checking if the received message is "Start"
        if (batterylevel> 0) {  // Checking if energy level is greater than zero

            if (batterylevel> energyUsedPerCycle) {  // Checking if energy level is sufficient for operation

                scheduleAt(simTime() + sensingInterval, msg);  // Scheduling the next sensing interval

                int sensorId = msg->getArrivalModule()->getIndex();  // Extracting the sensor ID
                std::string sensorIdString = std::to_string(sensorId);  // Converting sensor ID to a string
                std::string sensorName = std::string("Sensor ") + sensorIdString;  // Creating sensor name

                // Generating random values for sensor data
                double airHumidityValue = uniform(50, 52);
                EV<<airHumidityValue<<"   ";
                double airTemperatureValue = uniform(21, 23);
                double soilMoistureValue = uniform(90, 93);
                double soilTemperatureValue = uniform(23, 26);
                errorPercentage = uniform(-sensingMargin, sensingMargin);
                errorFactor = 1+ errorPercentage / 100.0;
                airHumidityValue *= errorFactor;
                airTemperatureValue *= errorFactor;
                soilMoistureValue *= errorFactor;
                soilTemperatureValue *= errorFactor;


                // Creating a SensorMessage and setting its attributes
                SensorMessage *sensorMsg = new SensorMessage("SensorData");
                sensorMsg->setSensorName(sensorName.c_str());
                double currentTime = simTime().dbl();
                sensorMsg->setSensedTime(currentTime);
                sensorMsg->setAirHumidityValue(airHumidityValue);
                sensorMsg->setAirTemperatureValue(airTemperatureValue);
                sensorMsg->setSoilDampnessValue(soilMoistureValue);
                sensorMsg->setSoilTemperatureValue(soilTemperatureValue);
                sensorMsg->setCurrentEnergyLevel(batterylevel);

                // Sending the SensorMessage to the 'gateway' module using direct communication
                cModule *gatewayModule = getParentModule()->getSubmodule("gateway");
                sendDirect(sensorMsg,0.0,transmissionDelay, gatewayModule, "my_gate");
                total_transmission_delay+=transmissionDelay;
                EV<<"total_transmission_delay"<<total_transmission_delay;
                EV<<"hi  "<<transmissionDelay<<"transmissionDelay";
                emit (transmission_delay_,total_transmission_delay);
                batterylevel -= energyUsedPerCycle;  // Updating energy level after data transmission
            }
            else {
                EV << "Remaining energy level is " << batterylevel << " which is less than energy Used Per Cycle " << energyUsedPerCycle << endl;
                EV << "Sensor out of energy. Stopping operation." << endl;
            }
        }
        else {
            EV << "Remaining energy: " << batterylevel << endl;
            EV << "Sensor out of energy. Stopping operation." << endl;
        }
    }

   // emit(energyUsedSignal, batterylevel);  // Emitting the energy level signal

}

