# AI-Camera-Focus-Controller

## Project Overview

This project is a manual Arduino-based motorized camera focus controller. It uses a joystick/knob module to control a DC motor through a Cytron MD10C motor driver. The motor is designed to help rotate a camera lens focus ring more smoothly without directly touching the lens.

The current version is manual. The project is also designed to be expandable into an AI-assisted focus system in the future.

## Problem

When recording video with a DSLR camera, manually turning the focus ring can shake the camera and make the focus movement uneven. My original idea was to motorize the zoom ring, but I changed the design because the zoom ring required more force and had a higher risk of damaging the lens.

I switched to the focus ring because it was safer, more realistic with the motor I had, and still solved a real camera-control problem.

## Current Working Version

The current version uses joystick control:

* Joystick left/right controls motor direction
* Joystick up/down controls motor speed
* Joystick press works as a stop button

This version proves the core hardware system: Arduino input, motor driver output, power control, wiring, and physical mounting.

## Components Used

* Arduino Uno R4 / Arduino-compatible board
* Cytron MD10C motor driver
* DC motor
* HW-504 joystick/knob module
* External power supply
* Jumper wires
* 3D-printed motor case
* 3D-printed pocket/electronics case
* Camera and lens for testing

## Wiring

### Cytron MD10C Motor Driver to Arduino

| Cytron MD10C | Arduino |
| ------------ | ------- |
| DIR          | D4      |
| PWM          | D5      |
| GND          | GND     |

### Power and Motor Wiring

| Part                   | Connection       |
| ---------------------- | ---------------- |
| Battery/Power Supply + | Cytron POWER +   |
| Battery/Power Supply - | Cytron POWER -   |
| Motor red/black wires  | Cytron MOTOR A/B |

### HW-504 Joystick Module to Arduino

| Joystick  | Arduino |
| --------- | ------- |
| GND       | GND     |
| VCC / +5V | 3.3V    |
| VRx       | A0      |
| VRy       | A1      |
| SW        | D10     |

## AI Expansion Plan

The project is not fully AI-controlled yet, but it can be expanded into an AI-assisted focus controller.

The AI version would count as an embedded assistive control system. It would not be a chatbot or generative AI. It would be a small decision-making system that uses sensor or camera feedback to help control the motor.

Future AI features could include:

* Learning safe focus-ring limits
* Preventing the motor from forcing the lens too far
* Saving focus positions
* Moving smoothly between focus presets
* Using camera/image feedback to detect sharpness
* Adjusting motor movement based on previous testing data

In the future, the AI system could read image sharpness from a camera feed, compare focus quality, and move the motor until the image becomes sharper. This would turn the current manual controller into an automatic focus-assist system.

## Design Changes

The project changed during development. The first idea was to motorize the zoom ring, but this was too risky because the zoom ring needed more torque. It could have put too much stress on the lens.

The second design focused on the focus ring instead. This made the project safer and more realistic. I also redesigned the 3D-printed parts multiple times because some old prototypes did not fit the motor correctly.

## What I Learned

This project taught me about Arduino motor control, motor drivers, wiring, soldering, power supplies, 3D design, prototyping, and troubleshooting. The biggest lesson was that engineering projects change during testing, and redesigning is part of the process.
