# Synthesizer & Sequencer
    Authors: Minh Le, Elijah Beard

## Background


This repo contains the schematics and arduino files for our Sequencer Synthesizer. This project was made for the Ohio Universities 2024 Hackathon, and won [best hardware](https://devpost.com/software/step-sequencer-synthesizer).

The synthesizer is broken up into two separate systems. The sequencer (Blue ELEGOO UNO), and the synth engine (Black ELEGOO UNO). These two systems are connected together by 4 lines of each micro-controllers digital pins. 

## Sequencer

Simple arduino design that aims to mimic a 4-step beat sequencer. Each LED represents a quarter note. There are buttons that corresponds to each LED allowing you to turn the LEDs off and on. Different rhythm patterns can be created by toggling on and off the 4 different LEDs.

![Uploading Exquisite Albar.png…]()

## Synth Engine

The synth engine controller runs on a library called [Mozzi](https://sensorium.github.io/Mozzi/), an open source arduino library for generating complex algorithmic sounds. 

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/4g0i1PBkdRs/0.jpg)](https://www.youtube.com/watch?v=4g0i1PBkdRs)
