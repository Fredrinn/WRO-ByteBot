# WRO-Future Engineers

## ByteBots
### Robotic Solution - ByteBot  

We are Team ByteBots, consisting of Anthony Vargas, Miguelangel Moreno, and Yonathan González. We have developed an autonomous vehicle model to compete in the 2024 season of WRO Future Engineers. This repository houses a wide range of engineering resources related to our autonomous vehicle, designed to tackle challenging speed and skill tests.

## Contents

* **Team Photo**  
  In this section, we present an official photo of our talented ByteBot team. This image captures the spirit of collaboration and dedication that has led us to develop a high-performance autonomous vehicle for the WRO Future Engineers competition. Meet the faces behind the project and discover the collective effort we've invested to achieve our goals.

* **Diagram**  
  Here, we present a comprehensive diagram showing the internal workings and structure of our autonomous robot. This diagram provides a clear understanding of how we designed and assembled each essential part of our vehicle, including the sensor system, control unit, actuators, and the overall layout of the components.

* **Prototype Images**  
  In this section, you'll find various .pdf files with detailed photos of our robot. You can explore its innovative design, components, and key features up close. These images will allow you to appreciate the quality and precision with which we've built our autonomous vehicle for the WRO Future Engineers competition.

* **Programming**  
  Here you will find the C++ code we developed for the operation of our autonomous robot. This programming file provides detailed information about the navigation algorithms, obstacle detection, and decision-making capabilities of our vehicle. We will be updating the code versions as we progress in the development and optimization of the robot.

* **Robot Video**  
  In this section, we provide a link to a video located in the vehicle photo folder where you can see our robot in action.

## Introduction

To optimize the design, the solution was modeled in virtual simulations and used a minimal number of components, allowing for space savings. Significant effort was devoted to optimizing the robot's size and reducing material consumption.

The components used in our prototype are as follows:

- **Microcontroller**: Arduino UNO R3
- **Sensor**: HuskyLens
- **Motors**: DC Motor 6V
- **Servomotor**: Servomotor
- **Other components**: 18650 Batteries, LN298 Module, Jumpers, LEDs

### Operation

The journey of the robotic prototype begins with the use of HuskyLens, which provides precise data on the distance between the robot and surrounding objects. Once this data is obtained, the robot enters a second phase of conditional processing that allows it to determine its precise location on the game track.

The prototype can take two distinct approaches to act accordingly. On one hand, it can choose to follow a predefined or pre-programmed route, using sensor data to adjust its trajectory and avoid obstacles. This strategy is based on prior planning and precise execution to achieve the desired goal.

On the other hand, the prototype can also employ a more dynamic and adaptive approach. Using sensor information, the robot can continuously evaluate its surroundings and make real-time decisions to avoid obstacles and reach its goal in the most efficient way possible. This involves a greater capacity for reaction and adaptation to changing game conditions.

#### First Option

The robotic prototype extensively validates HuskyLens data to determine its exact position on the game track. It uses this information to follow a predefined and optimized path that ensures a smooth, fast, and precise journey. The robot maintains a constant and safe pace using the distance data recorded by HuskyLens, avoiding unnecessary stops to check for obstacles in its path.

#### Second Option

When the ByteBot system detects obstacles through HuskyLens, a conditional logic is activated in Program 2. This program encodes variables and actions for the prototype to make dynamic decisions and adjust its trajectory to avoid obstacles. If an obstacle is detected, the prototype efficiently turns left or right.

The prototype uses HuskyLens data to identify the location and nature of obstacles, determining the optimal direction to avoid them and encoding the necessary instructions for the corresponding turn. This real-time response and adaptation capability is crucial for the prototype's success.

### Action-Reaction

Our action-reaction principle is based on the idea that all vehicle components must work in perfect harmony to achieve optimal performance. The components and actions necessary to generate a reaction based on the received data are as follows:

1. **Sensor Activation**: Upon powering on the vehicle, the first action is to activate HuskyLens, which will provide distance data to locate the prototype at a specific point on the track. These sensors are crucial for obstacle detection and correct vehicle positioning.

2. **Obstacle Detection**: Once the prototype's location is known, the next action is to determine if obstacles are present. To achieve this, we have proposed implementing artificial intelligence (AI) capable of detecting these obstacles. Our team has decided to develop this AI using accessible and user-friendly tools like Teachable Machine. This way, we can leverage machine learning capabilities to train the system in obstacle detection.

3. **Reactions**: Once the prototype knows its location and the presence of obstacles on the track, two possible reactions are triggered:

   3.1. **Predefined Route**: The first reaction is to act as if the prototype is in Round 1, i.e., an obstacle-free track. To achieve this, we use known data such as the initial position, robot speed, track size, robot size, and turning angles. By using mathematical and physical principles, we can calculate a predefined route based on this data, thus avoiding the need to constantly read and analyze known data, saving time and improving efficiency.

   3.2. **Obstacle Detection and Response**: If the prototype detects an obstacle, indicating Round 2, a second reaction occurs. Since Round 2 presents obstacles, it is necessary to reduce the motor speed to avoid errors due to excessive speed.

      3.2.1. **Obstacle Monitoring**: The next action is to monitor the color of the obstacles. This way, we can predefine the vehicle's reaction, which consists of reducing the speed of the DC motors and turning the servomotor in the appropriate direction to provide optimal direction to the robot. This approach allows us to navigate safely and efficiently around obstacles.

<div align="center">

### Made with ❤️ by Bytebots Team

</div>
