# Slateback
**Generate camera reports quickly and efficiently.**

This repository houses the source code for Slateback, a camera report generator built in C++.

At the moment, the code has only been tested on Windows, but does not feature any platform-specific code and should run on any operating system without issue.

This repository is governed by the MIT License, detailed in the `LICENSE` file.


###### Contributing
Slateback was created in Windows with Visual Studio 2019, but has successfully been built and ran on Linux. It is still recommended to utilize VS 2019 as other IDEs have yet to be tested.

Clone the repository with `git clone --recursive https://github.com/filmbrood/Slateback.git`.


###### Roadmap
At the moment, Slateback is command-line only, meaning it only runs in the terminal of the operation system of your choice. (Only tested on Windows and Linux!)

Eventually, Slateback will have a separate user-friendly GUI interface that any fresh-outta-film-school 2nd AC will be able to pick up in minutes. But for now, to get started with Slateback, all the user must do is copy slt.exe to a directory, launch a terminal in said directory, and type the following commands:

`slt project` Creates a new project within Slateback.
```
F:\>slt project
Project Title > Generic Film
New Project Created - Generic Film
Project Company > Generic Film Production, LLC
Project Director > Stephen Sealpug
Project DP > Ronald Dinkins
```

`slt camera` Creates a new camera within the active project.
```
F:\>slt camera
New camera created for Generic Film
Camera Model > Anri Atrexa Mini
Camera ID (A, B, C) > A
Camera Sensor Size > Super 35
Camera Codec > ProRes 422 HQ
Camera Lens Set > Zeesse Sumpremes
Camera Operator > John Man
Camera 1st AC > Hezekiah Condron
Camera 2nd AC > John Man, Jr.
```

`slt roll` Adds a new roll to the active camera.
```
F:\>slt roll
New roll created for camera A - A1
```

`slt shot` Adds a new shot to the active roll.
```
F:\>slt shot
New shot created for Roll A1
Scene > 1A
Take > 1
FPS > 23.98
Focal Length > 35mm
f/Stop > 2.8
ISO > 640
Color Temp > 5600K
Filter > Prom Mist 1/8
```

`slt take` Logs a new shot, but copies the details from the previous shot while incrementing the take number. This makes logging shots with several takes and few changes MUCH quicker.

When finished, `slt print` prints out a camera report based on the active project to `CameraReport.txt`.

For extra help, all commands with brief descriptions can be viewed in detail with `slt help` at any time.
