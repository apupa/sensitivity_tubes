
# Sensitivity Tubes
Repository of the paper entitled "*On the Computation of Sensitivity Tubes*".

## Preliminaries
To work with the repository you need Matlab and Casadi.
Casadi can be installed downloading the proper version (Matlab Windows or Linux) on the [official website](https://web.casadi.org/get/).

### Mass
In the Mass folder you can find a main that shows all the steps.
**Note:** before running the main, you have to change the variable casadi_path to point your casadi folder.

### Manipulator
For the manipulator you have just two steps:
1. generate_functions.m: This generate the dynamic of the manipulator. Please note that, in order to compile all the files, it may require time. On my laptop it requires around 30 minutes.
2. optimization.m: Here is where the optimization is performed. It requires approximately 3 minutes.

## Trubleshooting
If you have any problems, please contact us at our email address or open an issue.

## Owners
- **Andrea Pupa** andrea.pupa@unimore.it
- **Tommaso Belvedere** tommaso.belvedere@irisa.fr
