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

#include "User.h"
#include "SensorMessage_m.h"

Define_Module(User);

void User::initialize()
{

}

void User::handleMessage(cMessage *msg)
{
    if (dynamic_cast<SensorMessage *>(msg)) {

                SensorMessage *sensorMsg = check_and_cast<SensorMessage *>(msg);

                // Process or display the received SensorMessage data
                EV << "Received sensor data from: " << sensorMsg->getSensorName() << endl;
                EV << "Air Humidity: " << sensorMsg->getAirHumidityValue() << endl;
                EV << "Air Temparature: " << sensorMsg->getAirTemperatureValue() << endl;
                EV << "Soil dampness: " << sensorMsg->getSoilDampnessValue() << endl;
                EV << "Soil Temparature: " << sensorMsg->getSoilTemperatureValue() << endl;
                EV << "Energy_remaining: " << sensorMsg->getCurrentEnergyLevel() << endl;

                // Remember to delete the message after processing it
                delete sensorMsg;
            } else {
                // Handle other types of messages if required
                EV << "User received an unknown message." << endl;
                delete msg;
            }
    // TODO - Generated method body
}
