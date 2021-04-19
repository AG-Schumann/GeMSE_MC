#ifndef GeMSE_DetectorConstruction_h
#define GeMSE_DetectorConstruction_h 1

#include "globals.hh"

#include "G4LogicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"
#include "PMTholders.ihh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class GeMSE_DetectorConstruction : public G4VUserDetectorConstruction {
 public:
  GeMSE_DetectorConstruction(G4String GeometryFile);
  ~GeMSE_DetectorConstruction();

 public:
  G4LogicalVolume* ConstructPmtR11410();
  G4LogicalVolume* ConstructPMTholder_long();
  G4VPhysicalVolume* Construct();

 private:
  void OverlapCheck();
  G4String fGeometryFile;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif /*GeMSE_DetectorConstruction_h*/
