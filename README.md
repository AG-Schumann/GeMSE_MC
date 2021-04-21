# GeMSE_MC_efficiency

Geant4 code to simulate the GeMSE detector efficiency

[![CodeFactor](https://www.codefactor.io/repository/github/ag-schumann/gemse_mc_efficiency/badge)](https://www.codefactor.io/repository/github/ag-schumann/gemse_mc_efficiency)

## Usage

For compilation, ensure ROOT and Geant4 (10.3 recommended) are set up and simplu run:
```
git clone https://github.com/AG-Schumann/GeMSE_MC_efficiency.git
cd GeMSE_MC_efficiency
make -j # "-j" for parallel compilation using all available CPU
```

Run the executable with:
```
$G4WORKDIR/bin/Linux-g++GeMSE_efficiency -m <macrofile.mac> -o <results_folder>
```

### macrofile.mac
* Contains the information which isotopes or gamma lines are simulated
* See example, `example_various_isotopes_G4103p3.mac`.
* For visualization only use `visualization_vrml.mac` (no need for `-o` argument in this case).

### results_folder
* Folder where result files are written.

### Output
* `simulated_efficiencies.root`
	* TTree `tree`: Tree with information about detection efficiency and branching ratio (emission probability) for every gamma line
		* TBranch "energy": energy of gamma line
		* TBranch "efficiency": detection efficiency
        * TBranch "efficiency_err": statistical uncertainty of detection efficiency
        * TBranch "eff_BR": product of detection efficiency and branching ratio
