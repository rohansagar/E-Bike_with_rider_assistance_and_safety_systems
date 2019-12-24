# IOT_safety_equipped_smartbike
When it comes to urban cycling, safety is of utmost importance. Most modern automotive vehicles have smart features such 
as,lane departure warnings and blind spot vehicle detection that help improve their safety. On the other hand, the bicycle 
industry hasn’t seen considerable advancements in additive safety technologies. On an average, about 721 cyclists were 
killed every year from 2007 to 2016 due to traffic crashes. This project looks into the opportunities in improving bicycle
safety by using existing technologies and the challenges involved in doing so. It serves as an exploratory model for the 
application of technology to improve safety in bicycles. It adds 3 elements to bicycle safety. Those being,  
1: A smart mirror to provide a view of the vehicles behind the bike,  
2: A rear lighting module to display turn and stop signals for better visibility and finally,  
3: An electric assist module to provide additional power when required. 

<h2>Smart Mirror Module:</h2>  
This module is mounted on the back of the bike and is implemented using a Raspberry Pi 3 Model B+ and a pi camera.
It creates a Wi-Fi access point using the Wi-Fi chip on the pi. It captures the video using the pi camera and streams 
it to a pre-determined IP address on the network. The video stream can be accessed by any device connected to the network. 
Therefore, it can be accessed by any smartphone mounted on the handle of the bike, to display the video and thus act as 
a smart mirror providing the rear video feed to the rider. In addition to that, it stores the video on the SD card attached
to the raspberry pi to facilitate review in case of an accident.
This module is powered by using a battery management system connected to a 3800mAh battery. 

<img src="Smart_Mirror/Images/img_1.png" height= "250" width="400"><img src="Smart_Mirror/Images/img_2.png" height=" 250" width="400 ">



<h2>Rear Lighting Module:</h2>  
This module implements lighting features such as stop/turn indicator lights and always flashing bike light. It does so,
using an LED matrix display, buttons and a Tiva-C microcontroller. The buttons are used to trigger the turn singlals 
and Tiva-C board is used to detect button presses and drive the LED matrix display. The microcontroller controls the 
matrix display using SSI protocal. When no turn signal is triggered, the entire module flashes to provide increased
visibility.    

<img src="Lighting_Unit/Images/img_1.png" height= "250" width=" 400"><img src="Lighting_Unit/Images/img_2.png" height=" 250" width="400 ">

<h2>Electric Assist Module:</h2>  
The bike is equipped with a motorized rear wheel, throttle, brakes and required electric components to control the motor. 
The electric assist can be engaged by using a throttle lever. The brakes are fitted with switches, to detect the application
of brakes. While braking, the system cuts the power to the motor even if the throttle is engaged, so that the bike can stop
quickly. The electric assist system does not interfere with the normal operation of the pedals and the drive train. 
Therefore, the rider can modulate the amount of assist provided and when it is provided, by using a combination of 
peddling cadence, gear selection and electric assist throttle.  
