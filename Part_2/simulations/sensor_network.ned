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

package iot.simulations;
import iot.Sensor;
import iot.Gateway;
import iot.User;


network Sensor_network
{
    parameters:
        int sensors=5;
//         @statistic[totalEnergyUsed](source=batterylevel; record=timeavg,stats,vector);
    submodules:
        sensor[sensors]:Sensor;
        gateway:Gateway;
        user:User;
    connections:

        gateway.gateway_outgate-->user.user_gate;
        
        
}
