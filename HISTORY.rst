=======
History
=======

1.0 (2019-07-03)
------------------
* Body of the simulation taken from Dr. Moritz Von Sivers (https://github.com/vonsivers/GeMSE_efficiency_simulation)
* New naming convention for classes.
* Upgrade to G4.10.xx versions. Compilation with G4.9.xx no longer compatible.
* New Physics list. Replacement of some outdated references.
* Change Makefile structure (include config/binmake.gmx).
* Solved some detector overlaps.
* "GeMSE_ParticleSource" and "GeMSE_ParticleSourceMessenger" classes introduced, for a more detailed definition of the particles generated, the confinement volumes (possibility of setting various confinements at once) and tracking verbose.
* Implementation of the CADMesh feature (and corresponding libraries), in order to load geometries directly from 3D files in the "GeMSE_DetectorConstruction" class.
* Updated RandomSeed definition in RunAction.
* Addition of materials and DetectorConstruction cleanup.
* Solved visualization conflicts for G4.10.xx.
