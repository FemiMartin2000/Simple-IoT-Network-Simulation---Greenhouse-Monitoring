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
import iot.Greenhouse;
import iot.Router;
import iot.User;


network Sensor_network
{
      parameters:
       int num_house=2;

    submodules:
        greenhouse[num_house]:Greenhouse;
        router:Router;
        user:User;
    connections:
        greenhouse[0].greenhouse_gate_o-->router.router_gate[0];
        greenhouse[1].greenhouse_gate_o-->router.router_gate[1];
        router.router_gate_o-->user.user_gate;
        
        
}
