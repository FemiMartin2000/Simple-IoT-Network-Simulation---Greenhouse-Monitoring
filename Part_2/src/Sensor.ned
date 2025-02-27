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

package iot;

//
// TODO auto-generated module
//
simple Sensor
{
    parameters:
        @display("i=device/accesspoint");
        int sensorId=default(-1);
        double energyLevelStart = 10000;
        double sensorStartTime @unit(s)= uniform(10s,15s); 
         
        @statistic[Each_sensor_energy](source=batterylevel; record=timeavg,stats,vector);
        // Declaration of a signal 'batteryx' of type double for this Sensor
        @signal[batterylevel](type=double);
    gates:
        input my_gate @directIn;
}
